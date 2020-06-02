/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:40:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/15 01:10:45 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <sys/time.h>

void	set_texture_size(t_render *render, t_env *env)
{
	if (render->texture == -1)
	{
		render->texture_w = env->skyboxes[0].textures[0].surface->w;
		render->texture_h = env->skyboxes[0].textures[0].surface->h;
		render->map_lvl = env->skyboxes[0].textures[0].nb_maps - 1;
	}
	else
	{
		render->texture_w = env->wall_textures[render->texture].surface->w;
		render->texture_h = env->wall_textures[render->texture].surface->h;
		render->map_lvl = env->wall_textures[render->texture].nb_maps - 1;
	}
}

int		render_neighbor(int just_selected, t_sector *sector, t_render *render,
t_env *env)
{
	t_render	new;

	new = *render;
	new.xmin = render->xstart;
	new.sector = &env->sectors[sector->neighbors[render->i]];
	new.xmax = render->xend;
	if (render_sector(new, env))
		return (-1);
	if (env->editor.selected_wall == render->i && !just_selected
		&& env->editor.selected_sector == sector->num)
	{
		if (colorize_selected_portal(sector, render, env))
			return (-1);
	}
	if (env->editor.select_portal
		&& ((env->editor.tab && env->sdl.mx >= render->xstart
		&& env->sdl.mx <= render->xend) || (!env->editor.tab
		&& env->h_w >= render->xstart && env->h_w <= render->xend)))
	{
		if (select_portal(sector, render, env))
			return (-1);
	}
	reset_screen_limits(render, env);
	return (0);
}

void	set_x_limits(t_render *render, t_env *env)
{
	int	x;

	render->xstart = ft_max(render->v1->clipped_x1, render->xmin);
	render->xend = ft_min(render->v1->clipped_x2, render->xmax);
	x = render->xstart;
	while (x <= render->xend)
	{
		if (env->ymax[x] == env->ymin[x])
			render->xstart++;
		else
			break ;
		x++;
	}
	x = render->xend;
	while (x >= render->xstart)
	{
		if (env->ymax[x] == env->ymin[x])
			render->xend--;
		else
			break ;
		x--;
	}
}

int		render_current_wall(int i, t_sector *sector, t_render *render,
t_env *env)
{
	int		just_selected;
	struct timeval	start, end;

	render->v1 = &render->camera->v[sector->num][i];
	if (render->v1->clipped_x1 >= render->v1->clipped_x2 || render->v1->
		clipped_x1 > render->xmax || render->v1->clipped_x2 < render->xmin)
		return (0);
	set_x_limits(render, env);
	if (render->xend <= render->xstart)
		return (0);
	render->ceiling_horizon = render->v1->ceiling_horizon;
	render->floor_horizon = render->v1->floor_horizon;
	render->texture = sector->textures[i];
	set_texture_size(render, env);
	env->editor.just_selected = 0;
	just_selected = 0;
	gettimeofday(&start, NULL);
	if (threaded_wall_loop(sector, render, env) || env->fatal_error)
		return (custom_error("Threads crash\n", env));
	gettimeofday(&end, NULL);
	sector->walls_time.tv_sec += end.tv_sec - start.tv_sec;
	sector->walls_time.tv_usec += end.tv_usec - start.tv_usec;
	if (env->editor.just_selected)
		just_selected = 1;
	if (sector->neighbors[i] != -1)
	{
		gettimeofday(&start, NULL);
		if (render_neighbor(just_selected, sector, render, env))
			return (-1);
		gettimeofday(&end, NULL);
		sector->neighbors_time.tv_sec += end.tv_sec - start.tv_sec;
		sector->neighbors_time.tv_usec += end.tv_usec - start.tv_usec;
	}
	return (0);
}

int		render_sector(t_render render, t_env *env)
{
	int			i;
	int			j;
	t_sector	*sector;
	struct timeval	start, end;

	if (render.camera->rendered_sectors[render.sector->num])
		return (-1);
	render.camera->rendered_sectors[render.sector->num]++;
	sector = render.sector;
	gettimeofday(&start, NULL);
	j = -1;
	while (++j < env->w)
	{
		render.tmp_max[j] = env->ymax[j];
		render.tmp_min[j] = env->ymin[j];
	}
	i = -1;
	while (++i < sector->nb_vertices)
	{
		render.i = i;
		if (!render.camera->v[sector->num][i].draw)
			continue ;
		if (render_current_wall(i, sector, &render, env))
			return (-1);
	}
	gettimeofday(&end, NULL);
	sector->time.tv_sec += end.tv_sec - start.tv_sec;
	sector->time.tv_usec += end.tv_usec - start.tv_usec;
	sector->nb_renders++;
	render.camera->rendered_sectors[render.sector->num]--;
	return (0);
}
