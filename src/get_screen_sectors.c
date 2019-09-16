/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_sectors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:08:25 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/16 11:57:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render2.h"

/*int		get_screen_sectors(t_env *env)
{
	int		size;
	t_v3	curr;
	double	tmp;
	int		sect;
	int		sect_count;
	int		x;
	int		i;
	double	camera_range;

	size = env->screen_sectors_size;
	x = 0;
	sect_count = 0;
	camera_range = env->camera.near_right - env->camera.near_left;
	while (x < env->w)
	{
		tmp = (x / (double)(env->w - 1)) * camera_range + env->camera.near_left;
		curr.y = -env->camera.near_z;
		curr.x = tmp * -env->player.angle_sin - curr.y * env->player.angle_cos + env->player.pos.x;
		curr.y = tmp * env->player.angle_cos - curr.y * env->player.angle_sin + env->player.pos.y;
		curr.z = env->player.head_z;
		i = 0;
		sect = get_sector(env, curr, env->player.sector);
		env->screen_pos[x] = sect;
		while (i < size && env->screen_sectors[i] != -1 && env->screen_sectors[i] != sect)
			i++;
		if (i < size && env->screen_sectors[i] == -1 && sect != -1)
		{
			env->screen_sectors[i] = sect;
			env->xmin[i] = x;
			sect_count++;
		}
		else if (i < size && env->screen_sectors[i] == sect)
			env->xmax[i] = x;
		x++;
	}
	return (sect_count);
}*/

void	*get_screen_sectors_loop(void *param)
{
	t_env	*env;
	int		x;
	int		end;
	double	tmp;
	t_v3	curr;

	env = ((t_precompute_thread*)param)->env;
	x = ((t_precompute_thread*)param)->start;
	end = ((t_precompute_thread*)param)->end;
	while (x < end)
	{
		tmp = (x / (double)(env->w - 1)) * env->camera.range + env->camera.near_left;
		curr.y = -env->camera.near_z;
		curr.x = tmp * -env->player.angle_sin - curr.y * env->player.angle_cos + env->player.pos.x;
		curr.y = tmp * env->player.angle_cos - curr.y * env->player.angle_sin + env->player.pos.y;
		curr.z = env->player.head_z;
		env->screen_pos[x] = get_sector(env, curr, env->player.sector);
		x++;
	}
	return (NULL);
}

int		set_screen_sectors(t_env *env)
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
		sect = env->screen_pos[x];
		i = 0;
		while (i < size && env->screen_sectors[i] != -1 && env->screen_sectors[i] != sect)
			i++;
		if (i < size && env->screen_sectors[i] == -1 && sect != -1)
		{
			env->screen_sectors[i] = sect;
			env->xmin[i] = x;
			count++;
		}
		else if (i < size && env->screen_sectors[i] == sect)
			env->xmax[i] = x;
		x++;
	}
	return (count);
}

int		get_screen_sectors(t_env *env)
{
	t_precompute_thread	pt[THREADS];
	pthread_t			threads[THREADS];
	int					i;

	i = -1;
	while (++i < THREADS)
	{
		pt[i].env = env;
		pt[i].start = env->w / (double)THREADS * i;
		pt[i].end = env->w / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, get_screen_sectors_loop, &pt[i]);
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
	return (set_screen_sectors(env));
}
