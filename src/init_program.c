/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:56:46 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/19 16:04:57 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	init_program(int ac, char **av)
{
	t_env env;

	if (ac != 2)
		return (ft_printf("No map file.\n"));
	env.menu_start = 0;
	env.aplicate_changes = 0;
	env.reset = 0;
	env.running = 1;
	env.i = 0;
	env.horizon = 3;
	env.sector_list = NULL;
	init_pointers(&env);
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_inputs(&env);
	init_camera(&env);
	env.player.eyesight = 6.00;
	env.player.curr_weapon = 0;
	if (init_sdl(&env))
		return (crash("Coulnt not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not initialize fonts\n", &env));
	ft_printf("Parsing map \"%s\"..\n", av[1]);
	if (parse_map(av[1], &env))
		return (crash("Error while parsing the map\n", &env));
	if (init_screen_pos(&env))
		return (crash("Could not init screen pos\n", &env));
	precompute_slopes(&env);
	if (valid_map(&env))
		return (crash("Invalid map!\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (init_sprites(&env))
		return (crash("Could not load sprites\n", &env));
	if (init_wallpapers_and_buttons(&env))
		return (crash("Could not load menu tools\n", &env));
	if (!(env.sector_list = (int *)malloc(sizeof(int) * env.nb_sectors)))
	{
		/* ft_printf("crash\n"); */
		return (crash("Could not allocate sector list\n", &env));}
	update_camera_position(&env);
	SDL_SetRelativeMouseMode(1);
	return (doom(&env));
}
