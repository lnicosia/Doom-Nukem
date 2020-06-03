/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/15 01:10:14 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		precompute_sectors_loop(void *param)
{
	int			i;
	int			end;
	t_env		*env;
	t_camera	*camera;

	i = ((t_precompute_thread*)param)->start - 1;
	end = ((t_precompute_thread*)param)->end;
	env = ((t_precompute_thread*)param)->env;
	camera = ((t_precompute_thread*)param)->camera;
	while (++i < end)
		precompute_sector(camera, &env->sectors[i], env);
	return (0);
}

int		precompute_sectors(t_camera *camera, t_env *env)
{
	int					i;
	t_precompute_thread	pt[env->nprocs];

	i = 0;
	while (i < env->nprocs)
	{
		pt[i].env = env;
		pt[i].camera = camera;
		pt[i].start = env->nb_sectors / (double)env->nprocs * i;
		pt[i].end = env->nb_sectors / (double)env->nprocs * (i + 1);
		tpool_work(&env->tpool, precompute_sectors_loop, &pt[i]);
		i++;
	}
	if (tpool_wait(&env->tpool))
		return (-1);
	return (0);
}

void	set_render(t_camera *camera, t_env *env, int i, t_render *render)
{
	render->xmin = ft_max(camera->xmin[i], render->threadmin);
	render->xmax = ft_min(camera->xmax[i], render->threadmax);
	render->sector = &env->sectors[camera->screen_sectors[i]];
	render->camera = camera;
	render->ystart = 0;
	render->yend = env->h - 1;
}

int		render_walls(void *param)
{
	int			i;
	int			screen_sectors;
	t_render	render;
	t_camera	*camera;
	t_env		*env;

	screen_sectors = ((t_render_thread*)param)->screen_sectors;
	env = ((t_render_thread*)param)->env;
	camera = ((t_render_thread*)param)->camera;
	render.threadmin = ((t_render_thread*)param)->xstart;
	render.threadmax = ((t_render_thread*)param)->xend;
	render.thread = ((t_render_thread*)param)->id;
	i = 0;
	while (i < screen_sectors)
	{
		set_render(camera, env, i, &render);
		if (render_sector(render, env))
			return (-1);
		i++;
	}
	return (0);
}

int		draw_walls(t_camera *camera, t_env *env)
{
	int				i;
	int				screen_sectors;
	t_render_thread	rt[env->nprocs];

	camera->computed = 1;
	env->visible_sectors = 0;
	reset_render_utils(camera, env);
	if ((screen_sectors = get_screen_sectors(camera, env)) < 0)
		return (-1);
	get_rendered_sectors_list(screen_sectors, camera, env);
	if (precompute_sectors(camera, env))
		return (-1);
	i = 0;
	while (i < env->nprocs)
	{
		rt[i].xstart = env->w / (double)env->nprocs * i;
		rt[i].xend = env->w / (double)env->nprocs * (i + 1);
		rt[i].env = env;
		rt[i].screen_sectors = screen_sectors;
		rt[i].camera = camera;
		rt[i].id = i;
		if (tpool_work(&env->tpool, &render_walls, &rt[i]))
			return (custom_error("Threads crash\n"));
		i++;
	}
	if (tpool_wait(&env->tpool))
		return (custom_error("Error in threads\n"));
	return (0);
}
