/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 11:38:33 by sipatry           #+#    #+#             */
/*   Updated: 2020/01/14 12:08:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_button_target	*new_button_target(t_env *env, int i)
{
	t_button_target	*new;

	new = (t_button_target*)ft_memalloc(sizeof(t_button_target));
	new->env = env;
	new->i = i;
	return (new);
}

int	init_array_texture_buttons(t_env *env)
{
	int	i;
	int	mod;

	if (MAX_WALL_TEXTURE > 25)
		mod = 10;
	else
		mod = 5;
	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		// NE PAS OUBLIER DE FREE LES NEW_BUTTON_TARGET
		env->editor.textures[i] = new_image_button(WHEN_DOWN, &save_texture, new_button_target(env, i), env);
		env->editor.textures[i].img_up = env->wall_textures[i].maps[6];
		env->editor.textures[i].img_pressed = env->wall_textures[i].maps[6];
		env->editor.textures[i].img_down = env->wall_textures[i].maps[6];
		env->editor.textures[i].img_hover = env->wall_textures[i].maps[6];
		env->editor.textures[i].size_up = new_point(64, 64);
		env->editor.textures[i].size_down = new_point(64, 64);
		env->editor.textures[i].size_hover = new_point(64, 64);
		env->editor.textures[i].size_pressed = new_point(64, 64);
		env->editor.textures[i].pos = new_point(60 + (64 * (i % mod)) + 5, 370 + 5 + (64 * (i / mod)));
		i++;
	}
     	env->editor.current_texture_selection = new_image_button(WHEN_DOWN, &save_texture, &env->editor.current_texture_selection, env);
		env->editor.current_texture_selection.img_up = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_texture_selection.img_pressed = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_texture_selection.img_down = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_texture_selection.img_hover = env->wall_textures[env->editor.current_texture].maps[6];
		env->editor.current_texture_selection.size_up = new_point(64, 64);
		env->editor.current_texture_selection.size_down = new_point(64, 64);
		env->editor.current_texture_selection.size_hover = new_point(64, 64);
		env->editor.current_texture_selection.size_pressed = new_point(64, 64);
        env->editor.current_texture_selection.pos = new_point(13, 353);
		env->editor.texture_background = new_background_button(WHEN_DOWN, &nothing, &env->editor.texture_background, env);
		env->editor.texture_background.pos = new_point(10, 350);
	return (1);
}

int		init_enemy_selection_button(t_env *env)
{
	int	i;
	int	mod;

	if (MAX_ENEMIES > 20)
		mod = 10;
	else
		mod = 5;
	i = 0;
	ft_printf("current_enemy: %d\n", env->editor.current_enemy);
	ft_printf("current_selection: %d\n", env->editor.current_texture);
 	while (i < MAX_ENEMIES)
	{
		ft_printf("%d | %f\n", i, env->mini_enemies_textures[i].scale);
		env->editor.enemy_tab[i].img_up = env->wall_textures[i].maps[6];
		env->editor.enemy_tab[i] = new_image_button(WHEN_DOWN, &save_enemy, new_button_target(env, i), env);
		env->editor.enemy_tab[i].img_up = env->mini_enemies_textures[i].surface;
		env->editor.enemy_tab[i].img_pressed = env->mini_enemies_textures[i].surface;
		env->editor.enemy_tab[i].img_down = env->mini_enemies_textures[i].surface;
		env->editor.enemy_tab[i].img_hover = env->mini_enemies_textures[i].surface;
		env->editor.enemy_tab[i].size_up = new_point(64, 64);
		env->editor.enemy_tab[i].size_down = new_point(64, 64);
        env->editor.enemy_tab[i].size_hover = new_point(64, 64);
        env->editor.enemy_tab[i].size_pressed = new_point(64, 64);
		env->editor.enemy_tab[i].pos = new_point(140 + (64 * (i % mod)) + 5, 370 + 5 + (64 * (i / mod)));
		i++;
	}
	env->editor.current_enemy_selection = new_image_button(WHEN_DOWN, &save_enemy, &env->editor.current_enemy_selection, env);
	env->editor.current_enemy_selection.img_up = env->mini_enemies_textures[env->editor.current_enemy].surface;
	env->editor.current_enemy_selection.img_pressed = env->mini_enemies_textures[env->editor.current_enemy].surface;
	env->editor.current_enemy_selection.img_down = env->mini_enemies_textures[env->editor.current_enemy].surface;
	env->editor.current_enemy_selection.img_hover = env->mini_enemies_textures[env->editor.current_enemy].surface;
	env->editor.current_enemy_selection.size_up = new_point(64, 64);
	env->editor.current_enemy_selection.size_down = new_point(64, 64);
    env->editor.current_enemy_selection.size_hover = new_point(64, 64);
    env->editor.current_enemy_selection.size_pressed = new_point(64, 64);	
    env->editor.current_enemy_selection.pos = new_point(103, 353);
	env->editor.enemy_background = new_background_button(WHEN_DOWN, &nothing, &env->editor.enemy_background, env);
	env->editor.enemy_background.pos = new_point(100, 350);
	return (1);
}

void	init_options_buttons(t_env *env)
{
	(void)env;
	editor_mode_button(env);
	editor_save_button(env);
	editor_launch_game(env);
}

void	init_informations_tab(t_env *env)
{
	env->editor.sector_tab = new_tab_button(WHEN_DOWN, &sector_tab, env, env);
    env->editor.sector_tab.str = "Sector";
    env->editor.sector_tab.pos = new_point(238,425);
	env->editor.general_tab = new_tab_button(WHEN_DOWN, &general_tab, env, env);
	env->editor.general_tab.str = "General";
    env->editor.general_tab.pos = new_point(0,425);
	env->editor.sprite_tab = new_tab_button(WHEN_DOWN, &sprite_tab, env, env);
    env->editor.sprite_tab.str = "Sprites";
    env->editor.sprite_tab.pos = new_point(119,425);
}

int		init_editor_hud(t_env *env)
{
	if (!init_array_texture_buttons(env))
		return (0);
	init_enemy_selection_button(env);
	init_informations_tab(env);
	init_options_buttons(env);
	init_editor_tab_buttons(env);
	return (1);
}
