/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor_tab_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 13:41:32 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/11 11:41:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_enemy_buttons(t_env *env)
{
	init_enemy_general_env(env);
	init_enemy_sector_env(env);
	init_enemy_general_buttons(env);
	init_enemy_sector_buttons(env);
}

void	init_object_buttons(t_env *env)
{
	init_object_general_env(env);
	init_object_sector_env(env);
	init_object_general_buttons(env);
	init_object_sector_buttons(env);
}

void	init_sector_buttons(t_env *env)
{
	init_sector_general_env(env);
	init_sector_general_buttons(env);
}

void	init_vertices_buttons(t_env *env)
{
	init_vertices_general_env(env);
	init_vertices_general_buttons(env);
}

void	init_editor_tab_buttons(t_env *env)
{
	init_wall_buttons(env);
	init_floor_buttons(env);
	init_ceiling_buttons(env);
	init_sector_buttons(env);
	init_player_buttons(env);
	init_enemy_buttons(env);
	init_object_buttons(env);
	init_vertices_buttons(env);
}
