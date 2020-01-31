/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:04:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_weapon_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Weapon", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Weapon", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.weapon),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.weapon),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_ceiling_sprite_target(t_env *env, t_event *event, t_point pos,
int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;

	print_text(pos, new_printable_text("Sector", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Sector", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sector),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.sector),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text("ceiling sprite", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "ceiling sprite", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sprite),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.sprite),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_enemy_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Enemy", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Enemy", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.enemy),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.enemy),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_object_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Object", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Object", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.object),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.object),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_nothing_target(t_env *env, t_event *event, t_point pos, int size)
{
	(void)env;
	(void)event;
	(void)pos;
	(void)size;
	return (pos.y);
}
