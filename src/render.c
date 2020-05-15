/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:10:53 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/11 17:54:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	*precompute_sectors_loop(void *param)
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
	return (NULL);
}

int		precompute_sectors(t_camera *camera, t_env *env)
{
	t_precompute_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = 0;
	while (i < THREADS)
	{
		pt[i].env = env;
		pt[i].camera = camera;
		pt[i].start = env->nb_sectors / (double)THREADS * i;
		pt[i].end = env->nb_sectors / (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, precompute_sectors_loop, &pt[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

int		render_walls(t_camera *camera, t_env *env)
{
	int			i;
	int			screen_sectors;
	t_render	render;

	camera->computed = 1;
	env->visible_sectors = 0;
	reset_render_utils(camera, env);
	if ((screen_sectors = get_screen_sectors(camera, env)) < 0)
		return (-1);
	get_rendered_sectors_list(screen_sectors, camera, env);
	if (precompute_sectors(camera, env))
		return (-1);
	i = 0;
	while (i < screen_sectors)
	{
		render.xmin = camera->xmin[i];
		render.xmax = camera->xmax[i];
		render.sector = &env->sectors[camera->screen_sectors[i]];
		render.camera = camera;
		render.ystart = 0;
		render.yend = env->h - 1;
		if (render_sector(render, env))
			return (-1);
		i++;
	}
	return (0);
}

int		draw_walls(t_camera *camera, t_env *env)
{
	return (render_walls(camera, env));
}
