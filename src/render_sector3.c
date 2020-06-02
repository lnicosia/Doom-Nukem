/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sector3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:35:35 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/15 01:11:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_current_wall_vline(t_sector *sector, t_render *render,
t_env *env)
{
	compute_vline_data(sector, render, env);
	if (render->current_ceiling > env->ymin[render->x]
		|| render->current_floor < env->ymax[render->x])
		precompute_texels(render);
	draw_wall_bullet_holes(sector, render, env);
	if (draw_wall_sprites(sector, render, env))
		return ;
	draw_floor_and_ceiling(sector, render, env);
	if (sector->neighbors[render->i] != -1)
		draw_bottom_and_upper_walls(sector, render, env);
	else
	{
		if (sector->textures[render->i] < 0)
			draw_skybox(render, WALL, env);
		else
			draw_wall(sector, render, env);
	}
}

int		wall_loop(void *param)
{
	t_sector		*sector;
	t_render		render;
	t_env			*env;
	int				x;
	int				xend;
	struct timeval	start, end;

	sector = ((t_render_thread*)param)->sector;
	render = ((t_render_thread*)param)->render;
	env = ((t_render_thread*)param)->env;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	gettimeofday(&start, NULL);
	while (x <= xend)
	{
		render.x = x;
		render_current_wall_vline(sector, &render, env);
		if (env->options.clipping)
			update_screen(env);
		x++;
	}
	gettimeofday(&end, NULL);
	sector->real_walls_time.tv_sec += end.tv_sec - start.tv_sec;
	sector->real_walls_time.tv_usec += end.tv_usec - start.tv_usec;
	return (0);
}

int		threaded_wall_loop(t_sector *sector, t_render *render, t_env *env)
{
	t_render_thread	rt[env->nprocs];
	struct timeval	start, end;
	int				i;

	i = 0;
	while (i < env->nprocs)
	{
		render->thread = i;
		rt[i].sector = sector;
		rt[i].render = *render;
		rt[i].env = env;
		rt[i].xstart = render->xstart + (render->xend - render->xstart)
			/ (double)env->nprocs * i;
		rt[i].xend = render->xstart + (render->xend - render->xstart)
			/ (double)env->nprocs * (i + 1);
		sector->nb_threads++;
		env->nb_threads++;
		gettimeofday(&start, NULL);
		tpool_work(&env->tpool, wall_loop, &rt[i]);
		gettimeofday(&end, NULL);
		sector->threads_time.tv_sec += end.tv_sec - start.tv_sec;
		sector->threads_time.tv_usec += end.tv_usec - start.tv_usec;
		env->threads_time.tv_sec += end.tv_sec - start.tv_sec;
		env->threads_time.tv_usec += end.tv_usec - start.tv_usec;
		i++;
	}
	if (tpool_wait(&env->tpool))
		return (-1);
	return (0);
}

int		colorize_selected_portal(t_sector *sector, t_render *render, t_env *env)
{
	t_render_thread	rt[env->nprocs];
	int				i;

	i = 0;
	while (i < env->nprocs)
	{
		render->thread = i;
		rt[i].sector = sector;
		rt[i].render = *render;
		rt[i].env = env;
		rt[i].xstart = render->xstart + (render->xend - render->xstart)
			/ (double)env->nprocs * i;
		rt[i].xend = render->xstart + (render->xend - render->xstart)
			/ (double)env->nprocs * (i + 1) - 1;
		tpool_work(&env->tpool, portal_loop, &rt[i]);
		i++;
	}
	if (tpool_wait(&env->tpool))
		return (-1);
	return (0);
}

int		select_portal(t_sector *sector, t_render *render, t_env *env)
{
	t_render_thread	rt[env->nprocs];
	int				i;

	i = 0;
	while (i < env->nprocs)
	{
		render->thread = i;
		rt[i].sector = sector;
		rt[i].render = *render;
		rt[i].env = env;
		rt[i].xstart = render->xstart + (render->xend - render->xstart)
			/ (double)env->nprocs * i;
		rt[i].xend = render->xstart + (render->xend - render->xstart)
			/ (double)env->nprocs * (i + 1);
		tpool_work(&env->tpool, select_portal_loop, &rt[i]);
		i++;
	}
	if (tpool_wait(&env->tpool))
		return (-1);
	return (0);
}
