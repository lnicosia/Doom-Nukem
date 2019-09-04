/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_maths_enemies.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:05:12 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/02 15:49:38 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	*get_enemy_relative_pos(void *param)
{
	t_env	*env;
	int		i;
	int		max;

	env = ((t_enemy_thread*)param)->env;
	i = ((t_enemy_thread*)param)->xstart;
	max = ((t_enemy_thread*)param)->xend;
	while (i < max)
	{
		//ft_printf("i = %d\n", i);
		get_translated_enemy_pos(env, &env->enemies[i]);
		get_rotated_enemy_pos(env, &env->enemies[i]);
		i++;
	}
	return (NULL);
}

void	get_translated_enemy_pos(t_env *env, t_enemies *enemy)
{
	/*object->translated_left_bottom.x = (object.pos.x - object.width / 2.0)
		- env->player.pos.x;
	object->translated_left_bottom.z = object.pos.y - env->player.pos.y;
	object->translated_left_bottom.y = (object.pos.z - env->player.pos.z);
	object->translated_right_bottom.x = (object.pos.x + object.width / 2.0)
		- env->player.pos.x;
	object->translated_right_bottom.z = object->translated_left_bottom.z;
	object->translated_right_bottom.y = object->translated_left_bottom.y;
	object->translated_left_top.x = object->translated_left_top.x;
	object->translated_left_top.z = object->translated_left_top.z;
	object->translated_left_top.y = (object.pos.z + object.height)
		- env->player.pos.z;
	object->translated_right_top.x = object->translated_right_top.x;
	object->translated_right_top.z = object->translated_right_top.z;
	object->translated_right_top.y = object->translated_left_top.y;*/
	enemy->translated_pos.x = enemy->pos.x - env->player.pos.x;
	enemy->translated_pos.z = enemy->pos.y - env->player.pos.y;
	enemy->translated_pos.y = enemy->pos.z - env->player.head_z;
}

void	get_rotated_enemy_pos(t_env *env, t_enemies *enemy)
{
	/*object->rotated_left_bottom.x = object->translated_left_bottom.x
		* env->player.angle_sin - object->translated_left_bottom.z
		* env->player.angle_cos;
	object->rotated_left_bottom.z = object->translated_left_bottom.x
		* env->player.angle_cos + object->translated_left_bottom.z
		* env->player.angle_sin;
	object->rotated_left_bottom.y = object->translated_left_bottom.y
		+ object->rotated_left_bottom.z * env->player.angle_z;
	object->rotated_right_bottom.x = object->translated_right_bottom.x
		* env->player.angle_sin - object->translated_right_bottom.z
		* env->player.angle_cos;
	object->rotated_right_bottom.z = object->rotated_left_bottom.z;
	object->rotated_right_bottom.y = object->rotated_left_bottom.y;
	object->rotated_left_top.x = object->rotated_left_bottom.x;
	object->rotated_left_top.z = object->rotated_left_bottom.z;
	object->rotated_left_top.y = object->translated_left_top.y
		+ object->rotated_left_bottom.z * env->player.angle_z;
	object->rotated_right_top.x = object->rotated_right_bottom.x;
	object->rotated_right_top.z = object->rotated_right_bottom.z;
	object->rotated_right_top.y = object->rotated_left_top.y;*/
	enemy->rotated_pos.x = enemy->translated_pos.x
		* env->player.angle_sin - enemy->translated_pos.z * env->player.angle_cos;
	enemy->rotated_pos.z = enemy->translated_pos.x
		* env->player.angle_cos + enemy->translated_pos.z * env->player.angle_sin;
	enemy->rotated_pos.y = enemy->translated_pos.y
		+ enemy->rotated_pos.z * env->player.angle_z;
}

void	project_enemy(t_render_enemy *erender, t_enemies enemy, t_env *env)
{
	double	scale;

	scale = env->camera.scale;
	erender->screen_pos.y = env->h_h
		+ (enemy.rotated_pos.y * scale / -enemy.rotated_pos.z);
	erender->screen_pos.x = env->h_w + (enemy.rotated_pos.x * (scale / -enemy.rotated_pos.z));
	erender->dist = sqrt(pow(enemy.pos.x - env->player.pos.x, 2)
		+ pow(enemy.pos.y - env->player.pos.y, 2));
}
