/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_condition_functions2.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/14 19:27:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;

	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Weapon %d %s %s %.*f",
	condition->weapon, env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0x333333FF, 0), env);*/
	return (0);
}

int		print_ceiling_sprite_condition_target(t_env *env,
t_condition *condition, t_point pos, int size)
{
	TTF_Font	*font;

	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Sector %d ceiling sprite %d %s"
	"%s %.*f",
	condition->sector, condition->sprite,
	env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0x333333FF, 0), env);*/
	return (0);
}

int		print_enemy_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;

	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Enemy %d %s %s %.*f",
	condition->enemy, env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0x333333FF, 0), env);*/
	return (0);
}

int		print_object_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;

	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Object %d %s %s %.*f",
	condition->object, env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0x333333FF, 0), env);*/
	return (0);
}

int		print_nothing_condition_target(t_env *env, t_condition *condition,
t_point pos, int size)
{
	TTF_Font	*font;

	(void)pos;
	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%s %s %.*f",
	env->event_types[condition->target_index],
	get_condition_type_str(condition), get_decimal_len(condition->value),
	condition->value);
	/*print_text(pos, new_printable_text(env->snprintf,
	font, 0x333333FF, 0), env);*/
	return (0);
}
