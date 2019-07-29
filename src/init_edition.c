/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:12:05 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/29 17:31:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_edition(int ac, char **av)
{
	t_env	env;

	env.w = 1600;
	env.h = 900;
	env.h_w = env.w / 2;
	env.h_h = env.h / 2;
	env.running = 1;
	env.drawing = 1;
	env.edition = 1;
	init_pointers(&env);
	init_sdl(&env);
	init_editor(&env);
	init_textures(&env);
	init_ttf(&env);
	init_keys(&env);
	if (ac == 1)
		ft_printf("Creating a new map\n");
	else if (ac == 2)
		ft_printf("opening %s\n", av[1]);
	return (editor(&env));
}
