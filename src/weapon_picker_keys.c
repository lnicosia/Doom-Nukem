/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_picker_keys.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:32:34 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 10:23:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		is_mouse_on_weapon_picker(t_env *env)
{
	if (!env->editor.selecting_weapon
		&& !env->editor.selecting_condition_weapon)
		return (0);
	if (is_point_in_rectangle(new_point(env->sdl.mx, env->sdl.my),
	env->editor.weapon_picker.pos, env->editor.weapon_picker.size))
		return (1);
	return (0);
}

int		weapon_picker_keys(t_env *env)
{
	if (button_keys(&env->editor.weapon_picker.next, env))
		return (-1);
	if (button_keys(&env->editor.weapon_picker.previous, env))
		return (-1);
	if (button_keys(&env->editor.weapon_picker.ok, env))
		return (-1);
	if (button_keys(&env->editor.weapon_picker.cancel, env))
		return (-1);
	return (0);
}

int		weapon_picker_keyup(t_env *env)
{
	if (button_keyup(&env->editor.weapon_picker.next, env))
		return (-1);
	if (button_keyup(&env->editor.weapon_picker.previous, env))
		return (-1);
	if (button_keyup(&env->editor.weapon_picker.ok, env))
		return (-1);
	if (button_keyup(&env->editor.weapon_picker.cancel, env))
		return (-1);
	return (0);
}
