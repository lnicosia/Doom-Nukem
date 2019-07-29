/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:12:05 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/29 17:59:00 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_edition(int ac, char **av)
{
	t_env	env;

	if (ac == 1)
		ft_printf("Creating a new map\n");
	else if (ac == 2)
		ft_printf("opening %s\n", av[1]);
	env.running = 1;
	env.drawing = 1;
	env.reset = 0;
	env.i = 0;
	init_pointers(&env);
	if (init_screen_size(&env))
		return (crash("Could not initialize screen sizes\n", &env));
	init_options(&env);
	init_keys(&env);
	init_editor(&env);
	init_inputs(&env);
	init_camera(&env);
	env.player.eyesight = 6;
	env.player.speed = 0.5;
	env.player.size_2d = 0.5;
	env.flag = 0;
	if (init_sdl(&env))
		return (crash("Could not initialize SDL\n", &env));
	if (init_sound(&env))
		return (crash("Could not load sound\n", &env));
	if (init_ttf(&env))
		return (crash("Could not load fonts\n", &env));
	if (init_textures(&env))
		return (crash("Could not load textures\n", &env));
	if (init_sprites(&env))
		return (crash("Could not load sprites\n", &env));
	return (editor(&env));
}
