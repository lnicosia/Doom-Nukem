/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:56:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/20 11:22:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_game(int ac, char **av)
{
	t_env	env;
	int		i;

	i = 0;
	if (ac != 2)
		return (ft_printf("No map file.\n"));
	ft_bzero(&env, sizeof(t_env));
	env.menu_select = 1;
	env.running = 1;
	init_player(&env);
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	init_camera(&env);
	if (init_sdl(&env))
		return (crash("Coulnt not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not load fonts\n", &env));
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parse_map(av[1], &env))
		return (crash("Error while parsing the map\n", &env));
	/*if (init_screen_pos(&env))
		return (crash("Could not init screen pos\n", &env));
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (init_sprites(&env))
		return (crash("Could not load sprites\n", &env));
	if (!(env.sector_list = (int *)malloc(sizeof(int) * env.nb_sectors)))
		return (crash("Could not allocate sector list\n", &env));
	while (i < env.nb_objects)
	{
		env.objects[i].exists = 1;
		i++;
	}
	update_camera_position(&env);
	SDL_SetRelativeMouseMode(1);
	init_animations(&env);
	init_weapons(&env);
	ft_printf("Starting music..\n");
	Mix_PlayMusic(env.sound.background, -1);
	ft_printf("Launching game loop..\n");
	return (doom(&env));*/
	return (0);
}
