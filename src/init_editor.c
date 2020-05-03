/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/04 18:12:24 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		init_editor4(t_env *env)
{
	if (init_camera(&env->player.camera, env))
		return (crash("Could not init camera\n", env));
	if (init_skybox(env))
		return (crash("Could not init skybox\n", env));
	init_selection_tabs(env);
	init_weapons(env);
	env->confirmation_box.font = env->sdl.fonts.lato20;
	env->player.health = 100;
	env->editor.center.x = -env->player.pos.x * env->editor.scale +
	env->h_w + 200;
	env->editor.center.y = -env->player.pos.y * env->editor.scale + env->h_h;
	new_tabs_position(env);
	return (editor(env));
}

int		init_editor3(int ac, char **av, t_env *env)
{
	if (ac == 1)
	{
		ft_printf("Creating a new map\n");
		env->save_file = ft_strdup("test.map");
	}
	else if (ac == 2)
	{
		ft_printf("Opening \"%s\"\n", av[1]);
		if (parse_map(av[1], env))
			return (crash("Error while parsing the map\n", env));
		if (valid_map(env))
			return (crash("Invalid map!\n", env));
		env->save_file = ft_strdup(av[1]);
		precompute_slopes(env);
		ft_printf("{reset}");
	}
	if (!(env->sector_list = (int *)ft_memalloc(sizeof(int) * env->nb_sectors)))
		return (crash("Could not malloc sector list\n", env));
	view(env);
	update_camera_position(&env->player.camera);
	return (init_editor4(env));
}

int		init_editor2(int ac, char **av, t_env *env)
{
	if (init_audio(env))
		return (crash("Could not load sound\n", env));
	if (init_ttf(env))
		return (crash("Could not load fonts\n", env));
	if (init_input_box(&env->input_box, env))
		return (crash("Could not init input box\n", env));
	if (init_textures(env))
		return (crash("Could not load textures\n", env));
	if (generate_mipmaps(env))
		return (crash("Could not generate mipmaps\n", env));
	if (init_object_sprites(env))
		return (crash("Could not load object sprites\n", env));
	if (init_enemy_sprites(env))
		return (crash("Could not load enemy sprites\n", env));
	if (!(init_editor_hud(env)))
		return (crash("Could not init hud\n", env));
	return (init_editor3(ac, av, env));
}

int		init_editor(int ac, char **av)
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
	if (!(env.snprintf = ft_strnew(SNPRINTF_SIZE)))
		return (crash("Could not malloc snprintf char *\n", &env));
	if (init_sdl(&env))
		return (crash("Could not initialize SDL\n", &env));
	return (init_editor2(ac, av, &env));
}
