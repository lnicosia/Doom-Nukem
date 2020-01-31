/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_target_functions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:04:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/30 16:57:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		print_sector_target(t_env *env, t_event *event, t_point pos, int size)
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
	return (pos.y);
}

int		print_wall_target(t_env *env, t_event *event, t_point pos, int size)
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
	print_text(pos, new_printable_text("wall", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "wall", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.wall),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.wall),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_floor_sprite_target(t_env *env, t_event *event, t_point pos,
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
	print_text(pos, new_printable_text("floor sprite", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "floor sprite", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sprite),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.sprite),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_wall_sprite_target(t_env *env, t_event *event, t_point pos, int size)
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
	print_text(pos, new_printable_text("wall", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "wall", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.wall),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.wall),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text("sprite", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "sprite", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.sprite),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.sprite),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}

int		print_vertex_target(t_env *env, t_event *event, t_point pos, int size)
{
	TTF_Font	*font;
	t_point		text_size;

	if (size == 20)
		font = env->sdl.fonts.lato20;
	else
		font = env->sdl.fonts.lato15;
	print_text(pos, new_printable_text("Vertex", font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, "Vertex", &text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	print_text(pos, new_printable_text(ft_sitoa(event->update_param.vertex),
	font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(font, ft_sitoa(event->update_param.vertex),
	&text_size.x, &text_size.y);
	pos.y += text_size.x + 5;
	return (pos.y);
}
