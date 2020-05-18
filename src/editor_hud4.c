/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 12:40:19 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 12:53:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		editor_options_buttons2(t_env *env)
{
    if (draw_button(env, env->editor.zbuffer, env->editor.zbuffer.str))
		return (-1);
	if (draw_button(env, env->editor.light, env->editor.light.str))
		return (-1);
	if (draw_button(env, env->editor.fps, env->editor.fps.str))
		return (-1);
	if (print_on_off(env, env->options.mipmapping, new_point(64, 265)))
		return (-1);
	if (print_on_off(env, env->options.zbuffer, new_point(114, 265)))
		return (-1);
	if (print_on_off(env, env->options.lighting, new_point(164, 265)))
		return (-1);
	if (print_on_off(env, env->options.show_fps, new_point(214, 265)))
		return (-1);
    return (0);
}

int		editor_options_buttons(t_env *env)
{
	if (draw_button(env, env->editor.quit_options,
		env->editor.quit_options.str))
		return (-1);
	if (print_text(new_point(5, 155), new_printable_text("OPTIONS",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env))
		return (-1);
	if (print_text(new_point(275, 167), new_printable_text("HELP",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env))
		return (-1);
	if (draw_button(env, env->editor.mipmapping,
		env->editor.mipmapping.str))
		return (-1);
	return (editor_options_buttons2(env));
}

int		editor_options_sprites_portals2(t_env *env)
{
    ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select %*s", 57,
		"ctrl left-click");
	if (print_text(new_point(695, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
    return (0);
}

int		editor_options_sprites_portals(t_env *env)
{
	if (print_text(new_point(565, 50), new_printable_text("Sprites",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	if (print_text(new_point(590, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	if (print_text(new_point(610, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Pos   %*s", 58,
		"ctrl shift </>");
	if (print_text(new_point(630, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env))
		return (-1);
	if (print_text(new_point(670, 50), new_printable_text("Portals",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env))
		return (-1);
	return (editor_options_sprites_portals2(env));
}