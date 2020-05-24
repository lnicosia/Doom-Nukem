/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_object_tabs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:50:14 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/18 11:07:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		print_object_general_tab4(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->objects[env->selected_object].angle),
	env->objects[env->selected_object].angle);
	env->editor.hud.g_object.t_angle.target =
	&env->objects[env->selected_object].angle;
	if (draw_button(env, env->editor.hud.g_object.angle, env->snprintf))
		return (-1);
	return (0);
}

int		print_object_general_tab3(t_env *env)
{
	if (draw_button(env, env->editor.hud.g_object.health, env->snprintf))
		return (-1);
	if (print_text(new_point(680, 60), new_printable_text("Scale ",
		env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	get_decimal_len(env->objects[env->selected_object].scale),
	env->objects[env->selected_object].scale);
	env->editor.hud.g_object.t_scale.target =
	&env->objects[env->selected_object].scale;
	if (draw_button(env, env->editor.hud.g_object.scale, env->snprintf))
		return (-1);
	if (print_text(new_point(720, 60), new_printable_text("Damage",
		env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->objects[env->selected_object].damage);
	env->editor.hud.g_object.t_damage.target =
	&env->objects[env->selected_object].damage;
	if (draw_button(env, env->editor.hud.g_object.damage, env->snprintf))
		return (-1);
	if (print_text(new_point(760, 60), new_printable_text("Angle",
		env->sdl.fonts.lato20, 0x333333FF, 30), env))
		return (-1);
	return (print_object_general_tab4(env));
}

int		print_object_general_tab2(t_env *env)
{
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->objects[env->selected_object].pos.y)),
	env->objects[env->selected_object].pos.y);
	env->editor.hud.g_object.t_pos_y.target =
	&env->objects[env->selected_object].pos.y;
	if (draw_button(env, env->editor.hud.g_object.pos_y, env->snprintf))
		return (-1);
	if (print_text(new_point(600, 60), new_printable_text("Z",
		env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->objects[env->selected_object].pos.z)),
	env->objects[env->selected_object].pos.z);
	env->editor.hud.g_object.t_pos_z.target =
	&env->objects[env->selected_object].pos.z;
	if (draw_button(env, env->editor.hud.g_object.pos_z, env->snprintf))
		return (-1);
	if (print_text(new_point(640, 60), new_printable_text("Health",
		env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->objects[env->selected_object].health);
	env->editor.hud.g_object.t_health.target =
	&env->objects[env->selected_object].health;
	return (print_object_general_tab3(env));
}

int		print_object_general_tab(t_env *env)
{
	t_point		size;

	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Object %d",
	env->selected_object);
	if (TTF_SizeText(env->sdl.fonts.lato_black30,
		env->snprintf, &size.x, &size.y))
		return (-1);
	if (print_text(new_point(465, 200 - size.x / 2),
		new_printable_text(env->snprintf,
		env->sdl.fonts.lato_black30, 0x333333FF, 30), env))
		return (-1);
	if (print_text(new_point(520, 60), new_printable_text("X",
		env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%.*f",
	ft_min(1, get_decimal_len(env->objects[env->selected_object].pos.x)),
	env->objects[env->selected_object].pos.x);
	env->editor.hud.g_object.t_pos_x.target =
	&env->objects[env->selected_object].pos.x;
	if (draw_button(env, env->editor.hud.g_object.pos_x, env->snprintf))
		return (-1);
	if (print_text(new_point(560, 60), new_printable_text("Y",
		env->sdl.fonts.lato20, 0x00000000, 30), env))
		return (-1);
	return (print_object_general_tab2(env));
}
