/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:08:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/21 18:17:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	*get_screen_sectors_loop(void *param)
{
	t_env		*env;
	t_camera	*camera;
	int			x;
	int			end;
	double		tmp;
	t_v3		curr;

	env = ((t_precompute_thread*)param)->env;
	x = ((t_precompute_thread*)param)->start;
	end = ((t_precompute_thread*)param)->end;
	camera = ((t_precompute_thread*)param)->camera;
	while (x < end)
	{
		tmp = (x / (double)(env->w - 1)) * camera->range + camera->near_left;
		curr.y = -env->player.camera.near_z;
		curr.x = tmp * -camera->angle_sin - curr.y * camera->angle_cos + camera->pos.x;
		curr.y = tmp * camera->angle_cos - curr.y * camera->angle_sin + camera->pos.y;
		curr.z = camera->pos.z;
		camera->screen_pos[x] = get_sector(env, curr, env->player.sector);
		x++;
	}
	return (NULL);
}

int		set_screen_sectors(t_camera *camera, t_env *env)
{
	int	x;
	int	i;
	int	count;
	int	size;
	int	sect;

	x = 0;
	count = 0;
	size = env->screen_sectors_size;
	while (x < env->w)
	{
		sect = camera->screen_pos[x];
		i = 0;
		while (i < size && camera->screen_sectors[i] != -1 && camera->screen_sectors[i] != sect)
			i++;
		if (i < size && camera->screen_sectors[i] == -1 && sect != -1)
		{
			camera->screen_sectors[i] = sect;
			camera->xmin[i] = x;
			count++;
		}
		else if (i < size && camera->screen_sectors[i] == sect)
			camera->xmax[i] = x;
		x++;
	}
	return (count);
}

int		get_screen_sectors(t_camera *camera, t_env *env)
{
	t_precompute_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = -1;
	while (++i < THREADS)
	{
		pt[i].env = env;
		pt[i].camera = camera;
		pt[i].start = env->w / (double)THREADS * i;
		pt[i].end = env->w / (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, get_screen_sectors_loop, &pt[i]))
			return (-1);
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (set_screen_sectors(camera, env));
}
