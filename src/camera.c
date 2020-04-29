/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:47:23 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 14:57:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_camera_arrays3(t_camera *camera, t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (!(camera->v[i] = (t_render_vertex*)ft_memalloc(
			sizeof(t_render_vertex) * (env->sectors[i].nb_vertices + 1))))
			return (ft_perror("Could not malloc camera sectors"));
		camera->sectors_size[i] = env->sectors[i].nb_vertices;
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			camera->v[i][j].sprite_scale = 0;
			if (set_camera_sprites_array(camera, i, j, env))
				return (-1);
			camera->v[i][j].texture_scale = 0;
			camera->v[i][j].texture_align = 0;
			if (set_camera_map_array(camera, i, j, env))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		init_camera_arrays2(t_camera *camera, t_env *env)
{
	if (!(camera->rendered_sectors = (int*)ft_memalloc(sizeof(int)
		* (env->screen_sectors_size))))
		return (ft_printf("Could not malloc rendered sectors!\n", env));
	if (!(camera->v = (t_render_vertex**)
				malloc(sizeof(t_render_vertex*) * env->nb_sectors)))
		return (ft_perror("Could not malloc camera sectors"));
	return (init_camera_arrays3(camera, env));
}

int		init_camera_arrays(t_camera *camera, t_env *env)
{
	camera->size = env->nb_sectors;
	if (!(camera->screen_pos = (int*)ft_memalloc(sizeof(int) * (env->w))))
		return (ft_printf("Could not malloc screen pos!\n", env));
	if (!(camera->sector_computed = (int*)ft_memalloc(sizeof(int)
		* (env->nb_sectors))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(camera->sectors_size = (int*)ft_memalloc(sizeof(int)
		* (env->nb_sectors))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(camera->feet_y = (double*)ft_memalloc(sizeof(double)
		* (env->nb_sectors))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(camera->head_y = (double*)ft_memalloc(sizeof(double)
		* (env->nb_sectors))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(camera->xmin = (int*)ft_memalloc(sizeof(int)
		* (env->screen_sectors_size))))
		return (ft_printf("Could not malloc xmins!\n", env));
	if (!(camera->xmax = (int*)ft_memalloc(sizeof(int)
		* (env->screen_sectors_size))))
		return (ft_printf("Could not malloc xmaxs!\n", env));
	if (!(camera->screen_sectors = (int*)ft_memalloc(sizeof(int)
		* (env->screen_sectors_size))))
		return (ft_printf("Could not malloc screen sectors!\n", env));
	return (init_camera_arrays2(camera, env));
}

int		init_camera(t_camera *camera, t_env *env)
{
	camera->hfov = 90;
	camera->near_z = 0.1;
	camera->far_z = 1000;
	camera->ratio_w = 16;
	camera->ratio_h = 9;
	camera->ratio = camera->ratio_w / camera->ratio_h;
	set_camera(camera, env);
	if (init_camera_arrays(camera, env))
		return (ft_printf("Could not init camera arrays\n"));
	return (0);
}
