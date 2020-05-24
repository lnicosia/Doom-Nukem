/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_selection_tabs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 12:07:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 12:07:47 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_selection_tabs2(t_env *env)
{
	int		textures_per_line;
	int		nb_textures_lines;
	int		nb_skyboxes_lines;

	textures_per_line = 5;
	nb_textures_lines = MAX_WALL_TEXTURE / textures_per_line;
	if (MAX_WALL_TEXTURE % textures_per_line != 0)
		nb_textures_lines++;
	nb_skyboxes_lines = MAX_SKYBOX / textures_per_line;
	if (MAX_SKYBOX % textures_per_line != 0)
		nb_skyboxes_lines++;
	env->editor.wall_sprite_selection_size = env->editor.object_selection_size;
	env->editor.texture_selection_size = new_point((66 * textures_per_line)
	+ 11, (66 * (nb_textures_lines + nb_skyboxes_lines)) + 30);
	env->editor.enemy_selection_pos = new_point(280, 380);
	env->editor.texture_selection_pos = new_point(300, 150);
	env->editor.object_selection_pos = new_point(280, 280);
	env->editor.wall_sprite_selection_pos = new_point(180, 490);
}

void	init_selection_tabs(t_env *env)
{
	int		mod;
	int		tmp;

	tmp = MAX_ENEMIES;
	if (tmp > 25)
		mod = 10;
	else
		mod = 5;
	while (tmp % mod != 0)
		tmp++;
	env->editor.enemy_selection_size = new_point((66 * mod) + 13,
	(66 * (tmp / mod)) + 13);
	tmp = MAX_OBJECTS;
	if (tmp > 25)
		mod = 10;
	else
		mod = 5;
	while (tmp % mod != 0)
		tmp++;
	env->editor.object_selection_size = new_point((66 * mod) + 13,
	(66 * (tmp / mod)) + 13);
	init_selection_tabs2(env);
}
