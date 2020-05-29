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

int	count = 0;

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

void	draw_limits(t_render *render, t_env *env)
{
	int	x;

	x = render->xstart;
	while (x <= render->xend)
	{
		env->sdl.texture_pixels[x + env->w * env->ymin[x]] = 0xFF00FF00;
		//env->sdl.texture_pixels[x + env->w * env->ymax[x]] = 0xFFFF0000;
		x++;
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
	render->xstart = ft_max(render->v1->clipped_x1, render->xmin);
	render->xend = ft_min(render->v1->clipped_x2, render->xmax);
	render->i = i;
	render->ceiling_horizon = render->v1->ceiling_horizon;
	render->floor_horizon = render->v1->floor_horizon;
	render->texture = sector->textures[i];
	set_texture_size(render, env);
	env->editor.just_selected = 0;
	just_selected = 0;
	gettimeofday(&start, NULL);
	if (threaded_wall_loop(sector, render, env) || env->fatal_error)
		return (custom_error("threads crash\n", env));
	gettimeofday(&end, NULL);
	int j = -1;
	while (++j < count - 1)
		ft_printf("----");
	ft_printf(">Rendering wall %d (from %d to %d) took %ld\n", i,
	render->xstart, render->xend, (end.tv_sec - start.tv_sec)
	* 1000000 + end.tv_usec - start.tv_usec);
	if (env->editor.just_selected)
		just_selected = 1;
	if (sector->neighbors[i] != -1)
	{
		gettimeofday(&start, NULL);
		if (render_neighbor(just_selected, sector, render, env))
			return (-1);
		gettimeofday(&end, NULL);
		j = -1;
		while (++j < count - 1)
			ft_printf("----");
		ft_printf(">Rendering wall %d neighbors took %ld\n", i,
		(end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec);
	}
	draw_limits(render, env);
	//update_screen(env);
	//getchar();
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
	i = -1;
	while (++i < count)
		ft_printf("----");
	count++;
	ft_printf("rendering sector %d\n", render.sector->num);
	render.camera->rendered_sectors[render.sector->num]++;
	sector = render.sector;
	j = -1;
	while (++j < env->w)
	{
		render.tmp_max[j] = env->ymax[j];
		render.tmp_min[j] = env->ymin[j];
	}
	i = -1;
	gettimeofday(&start, NULL);
	while (++i < sector->nb_vertices)
	{
		if (!render.camera->v[sector->num][i].draw)
			continue ;
		if (render_current_wall(i, sector, &render, env))
			return (-1);
	}
	gettimeofday(&end, NULL);
	i = -1;
	while (++i < count - 1)
		ft_printf("----");
	ft_printf("Rendering execution is %ld\n", (end.tv_sec - start.tv_sec)
	* 1000000 + end.tv_usec - start.tv_usec);
	count--;
	render.camera->rendered_sectors[render.sector->num]--;
	return (0);
}
