/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_panel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:05:33 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/06 19:26:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		draw_event_panel(t_env *env)
{
	t_point		text_size;

	// Ecran de debbug/placement
	draw_rectangle_alpha(env, new_rectangle(0xdcdde1, 0xdcdde1, 1, 0),
	env->editor.event_panel.pos, env->editor.event_panel.size);

	// Bande du haut
	draw_rectangle_alpha(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	env->editor.event_panel.pos, new_point(env->editor.event_panel.size.x,
	env->editor.event_panel.size.y / 5 - 2));

	// Premier onglet
	/*draw_rectangle_alpha(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + 100),
	new_point(env->editor.event_panel.size.y / 5 - 2,
	env->editor.event_panel.size.y / 5 - 2));*/
	draw_button(env, env->editor.event_panel.target_tab, NULL);

	// Deuxieme onglet
	/*draw_rectangle_alpha(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + 200),
	new_point(env->editor.event_panel.size.y / 5 - 2,
	env->editor.event_panel.size.y / 5 - 2));*/
	draw_button(env, env->editor.event_panel.action_tab, NULL);

	// Troisieme onglet
	/*draw_rectangle_alpha(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + 300),
	new_point(env->editor.event_panel.size.y / 5 - 2,
	env->editor.event_panel.size.y / 5 - 2));*/
	draw_button(env, env->editor.event_panel.launch_conditions_tab, NULL);

	// Quatrieme onglet
	/*draw_rectangle_alpha(env, new_rectangle(0xFFf1f2f3, 0xFFf1f2f3, 1, 0),
	new_point(env->editor.event_panel.pos.x,
	env->editor.event_panel.pos.y + 400),
	new_point(env->editor.event_panel.size.y / 5 - 2,
	env->editor.event_panel.size.y / 5 - 2));*/
	draw_button(env, env->editor.event_panel.exec_conditions_tab, NULL);

	// Background
	draw_rectangle_alpha(env, new_rectangle(0xe3e4e8, 0xe3e4e8 + 100, 1, 0),
	new_point(env->editor.event_panel.pos.x + 100,
	env->editor.event_panel.pos.y + 100),
	new_point(env->editor.event_panel.size.x -
	env->editor.event_panel.size.y / 5,
	env->editor.event_panel.size.y - env->editor.event_panel.size.y / 5));

	// Text
	//ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Events");
	TTF_SizeText(env->sdl.fonts.lato_black50, "Events", &text_size.x, &text_size.y);
	print_text(new_point(env->editor.event_panel.pos.y + 17,
	env->editor.event_panel.pos.x + 110),
	new_printable_text("Events", env->sdl.fonts.lato_black50, 0x333333FF, 0), env);
	
	// Event icon
	apply_surface(env->ui_textures[EVENT_ICON].surface,
	new_point(env->editor.event_panel.pos.y +
	(50 - env->ui_textures[EVENT_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(50 - env->ui_textures[EVENT_ICON].surface->h / 2)),
	new_point(env->ui_textures[EVENT_ICON].surface->w,
	env->ui_textures[EVENT_ICON].surface->h), env);
	
	// Target icon
	apply_surface(env->ui_textures[TARGET_ICON].surface,
	new_point(env->editor.event_panel.pos.y + 100 +
	(50 - env->ui_textures[TARGET_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(50 - env->ui_textures[TARGET_ICON].surface->h / 2)),
	new_point(env->ui_textures[TARGET_ICON].surface->w,
	env->ui_textures[TARGET_ICON].surface->h), env);

	// Action icon
	apply_surface(env->ui_textures[ACTION_ICON].surface,
	new_point(env->editor.event_panel.pos.y + 200 +
	(50 - env->ui_textures[ACTION_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(50 - env->ui_textures[ACTION_ICON].surface->h / 2)),
	new_point(env->ui_textures[ACTION_ICON].surface->w,
	env->ui_textures[ACTION_ICON].surface->h), env);

	// Launch condition icon
	apply_surface(env->ui_textures[CONDITION_ICON].surface,
	new_point(env->editor.event_panel.pos.y + 300 +
	(50 - env->ui_textures[CONDITION_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(50 - env->ui_textures[CONDITION_ICON].surface->h / 2)),
	new_point(env->ui_textures[CONDITION_ICON].surface->w,
	env->ui_textures[CONDITION_ICON].surface->h), env);

	// Exec condition icon
	apply_surface(env->ui_textures[CONDITION_ICON].surface,
	new_point(env->editor.event_panel.pos.y + 400 +
	(50 - env->ui_textures[CONDITION_ICON].surface->h / 2),
	env->editor.event_panel.pos.x +
	(50 - env->ui_textures[CONDITION_ICON].surface->h / 2)),
	new_point(env->ui_textures[CONDITION_ICON].surface->w,
	env->ui_textures[CONDITION_ICON].surface->h), env);
	return (0);
}
