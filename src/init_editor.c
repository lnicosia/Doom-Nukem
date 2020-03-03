/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/03 16:22:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Interaction test function
*/

int	hola2(void *param)
{
	(void)param;
	ft_printf("Hola\n");
	return (1);
}

int	hola(void *param, void *env)
{
	(void)param;
	(void)env;
	ft_printf("Hola\n");
	return (1);
}

int	hit_player(void *param, void *env)
{
	(void)param;
	(void)env;
	ft_printf("Aie\n");
	return (1);
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
	env->editor.wall_sprite_selection_size = env->editor.object_selection_size;
	tmp = MAX_WALL_TEXTURE + MAX_SKYBOX;
	if (tmp > 25)
		mod = 10;
	else
		mod = 5;
	while (tmp % mod != 0)
		tmp++;
	env->editor.texture_selection_size = new_point((66 * mod) + 11,
	(66 * (tmp / mod)) + 30);
	env->editor.enemy_selection_pos = new_point(280, 380);
	env->editor.texture_selection_pos = new_point(300, 150);
	env->editor.object_selection_pos = new_point(280, 280);
	env->editor.wall_sprite_selection_pos = new_point(180, 490);
}

int	init_editor(int ac, char **av)
{
	t_env	env;

	ft_bzero(&env, sizeof(t_env));
	env.running = 1;
	env.drawing = 1;
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_editor_data(&env);
	init_inputs(&env);
	init_player(&env);
	init_animations(&env);
	init_event_types(&env);
	init_print_target_data(&env);
	init_print_condition_target_data(&env);
	init_event_links_types(&env);
	init_print_link_target_data(&env);
	init_objects_data(&env);
	init_enemies_data(&env);
	if (!(env.snprintf = ft_strnew(SNPRINTF_SIZE)))
		return (crash("Could not malloc snprintf char *\n", &env));
	if (init_sdl(&env))
		return (crash("Could not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not load fonts\n", &env));
	if (init_input_box(&env.input_box, &env))
		return (crash("Could not init input box\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (generate_mipmaps(&env))
		return (crash("Could not generate mipmaps\n", &env));
	if (init_object_sprites(&env))
		return (crash("Could not load object sprites\n", &env));
	if (init_enemy_sprites(&env))
		return (crash("Could not load enemy sprites\n", &env));
	if (!(init_editor_hud(&env)))
		return (crash("Could not init hud\n", &env));
	if (ac == 1)
	{
		ft_printf("Creating a new map\n");
		env.save_file = ft_strdup("maps/test.map");
	}
	else if (ac == 2)
	{
		ft_printf("Opening \"%s\"\n", av[1]);
		if (parse_map(av[1], &env))
			return (crash("Error while parsing the map\n", &env));
		if (valid_map(&env))
			return (crash("Invalid map!\n", &env));
		env.save_file = ft_strdup(av[1]);
		precompute_slopes(&env);
		ft_printf("{reset}");
	}
	if (!(env.sector_list = (int *)ft_memalloc(sizeof(int) * env.nb_sectors)))
		return (crash("Could not malloc sector list\n", &env));
	view(&env);
	update_camera_position(&env.player.camera);
	if (init_camera(&env.player.camera, &env))
		return (crash("Could not init camera\n", &env));
	if (init_skybox(&env))
		return (crash("Could not init skybox\n", &env));
	init_selection_tabs(&env);
	init_weapons(&env);
	env.confirmation_box.font = env.sdl.fonts.lato20;
	env.player.health = 100;
	env.editor.center.x = -env.player.pos.x * env.editor.scale + env.h_w + 200;
	env.editor.center.y = -env.player.pos.y * env.editor.scale + env.h_h;
	new_tabs_position(&env);
	return (editor(&env));
}
