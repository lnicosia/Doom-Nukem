/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:08:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:33:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	get_current_x_sector(int x, t_camera *camera, t_env *env)
{
	double		tmp;
	t_v3		curr;

	tmp = (x / (double)(env->w - 1)) * camera->range + camera->near_left;
	curr.y = -env->player.camera.near_z;
	curr.x =
	tmp * -camera->angle_sin - curr.y * camera->angle_cos + camera->pos.x;
	curr.y =
	tmp * camera->angle_cos - curr.y * camera->angle_sin + camera->pos.y;
	curr.z = camera->pos.z;
	camera->screen_pos[x] = get_sector(env, curr, env->player.sector);
}

int		get_screen_sectors_loop(void *param)
{
	t_env		*env;
	t_camera	*camera;
	int			x;
	int			end;

	env = ((t_precompute_thread*)param)->env;
	x = ((t_precompute_thread*)param)->start;
	end = ((t_precompute_thread*)param)->end;
	camera = ((t_precompute_thread*)param)->camera;
	while (x < end)
	{
		get_current_x_sector(x, camera, env);
		x++;
	}
	return (0);
}

void	set_current_x_sectors(int *count, int x, t_camera *camera, t_env *env)
{
	int	i;
	int	sect;
	int	size;

	size = env->screen_sectors_size;
	sect = camera->screen_pos[x];
	i = 0;
	while (i < size && camera->screen_sectors[i] != -1
		&& camera->screen_sectors[i] != sect)
		i++;
	if (i < size && camera->screen_sectors[i] == -1 && sect != -1)
	{
		camera->screen_sectors[i] = sect;
		camera->xmin[i] = x;
		(*count)++;
	}
	else if (i < size && camera->screen_sectors[i] == sect)
		camera->xmax[i] = x;
}

int		set_screen_sectors(t_camera *camera, t_env *env)
{
	int	x;
	int	count;

	x = 0;
	count = 0;
	while (x < env->w)
	{
		set_current_x_sectors(&count, x, camera, env);
		x++;
	}
	return (count);
}

int		get_screen_sectors(t_camera *camera, t_env *env)
{
	t_precompute_thread	pt[MAX_PROC];
	int					i;

	i = -1;
	while (++i < env->nprocs)
	{
		pt[i].env = env;
		pt[i].camera = camera;
		pt[i].start = env->w / (double)env->nprocs * i;
		pt[i].end = env->w / (double)env->nprocs * (i + 1);
		if (tpool_work(&env->tpool, get_screen_sectors_loop, &pt[i]))
			return (-1);
	}
	if (tpool_wait(&env->tpool))
		return (-1);
	return (set_screen_sectors(camera, env));
}
