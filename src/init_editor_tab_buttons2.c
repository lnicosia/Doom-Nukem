/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_tab_buttons2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 13:33:01 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 13:33:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

int		change_var(void *target)
{
	t_button_tab	*button;
	t_env			*env;

	button = (t_button_tab *)target;
	env = button->env;
	new_input_var(&env->input_box, button->pos, button->type, button->target);
	return (0);
}

void	init_wall_buttons(t_env *env)
{
	init_wall_general_env(env);
	init_wall_sector_env(env);
	init_wall_sprite_env(env);
	init_wall_sprite_sector_env(env);
	init_wall_general_buttons(env);
	init_wall_sector_buttons(env);
	init_wall_sprite_sector_buttons(env);
	init_wall_sprite_buttons(env);
}

void	init_floor_buttons(t_env *env)
{
	init_floor_general_env(env);
	init_floor_sector_env(env);
	init_floor_sprite_env(env);
	init_floor_general_buttons(env);
	init_floor_sector_buttons(env);
	init_floor_sprite_buttons(env);
}

void	init_ceiling_buttons(t_env *env)
{
	init_ceiling_general_env(env);
	init_ceiling_sector_env(env);
	init_ceiling_sprite_env(env);
	init_ceiling_general_buttons(env);
	init_ceiling_sector_buttons(env);
	init_ceiling_sprite_buttons(env);
}

void	init_player_buttons(t_env *env)
{
	init_player_general_env(env);
	init_player_sector_env(env);
	init_player_general_buttons(env);
	init_player_sector_buttons(env);
}
