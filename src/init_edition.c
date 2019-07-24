/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_edition.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 20:12:05 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/23 18:37:44 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	init_edition(int ac, char **av)
{
	t_env	env;

	env.w = 1600;
	env.h = 900;
	env.running = 1;
	env.drawing = 0;
	env.edition = 1;
	init_edit(&env);
	init_textures(&env);
	init_ttf(&env);
	if (ac == 1)
		ft_printf("Creating a new map\n");
	else if (ac == 2)
		ft_printf("opening %s\n", av[1]);
	init_sdl(&env);
	editor(&env);
	return (0);
}
