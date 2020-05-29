/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_maths_enemies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:05:12 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/21 10:32:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

int		get_enemy_relative_pos(void *param)
{
	t_env		*env;
	t_camera	*camera;
	int			i;
	int			max;

	env = ((t_enemy_thread*)param)->env;
	i = ((t_enemy_thread*)param)->xstart;
	max = ((t_enemy_thread*)param)->xend;
	camera = ((t_enemy_thread*)param)->camera;
	while (i < max)
	{
		get_translated_enemy_pos(camera, &env->enemies[i]);
		get_rotated_enemy_pos(camera, &env->enemies[i]);
		i++;
	}
	return (0);
}

void	get_translated_enemy_pos(t_camera *camera, t_enemy *enemy)
{
	enemy->translated_pos.x = enemy->pos.x - camera->pos.x;
	enemy->translated_pos.z = enemy->pos.y - camera->pos.y;
	enemy->translated_pos.y = enemy->pos.z - camera->pos.z;
}

void	get_rotated_enemy_pos(t_camera *camera, t_enemy *enemy)
{
	enemy->rotated_pos.x = enemy->translated_pos.x
		* camera->angle_sin - enemy->translated_pos.z * camera->angle_cos;
	enemy->rotated_pos.z = enemy->translated_pos.x
		* camera->angle_cos + enemy->translated_pos.z * camera->angle_sin;
	enemy->rotated_pos.y = enemy->translated_pos.y
		+ enemy->rotated_pos.z * camera->angle_z;
}

void	project_enemy(t_render_object *erender, t_enemy *enemy, t_env *env)
{
	double	scale;

	scale = erender->camera->scale;
	erender->screen_pos.y = env->h_h
		+ (enemy->rotated_pos.y * scale / -enemy->rotated_pos.z);
	erender->screen_pos.x = env->h_w
		+ (enemy->rotated_pos.x * scale / -enemy->rotated_pos.z);
}
