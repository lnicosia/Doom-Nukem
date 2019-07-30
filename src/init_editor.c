/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:26:04 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/30 11:02:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	init_editor_data(t_env *env)
{
	env->editor.in_game = 0;
	env->editor.select_mode = 0;
	env->editor.center.x = env->h_w;
	env->editor.center.y = env->h_h;
	env->editor.scale = 20;
	env->editor.current_vertices = NULL;
	env->editor.new_sector = 0;
	env->editor.reverted = 0;
	env->nb_vertices = 0;
	env->nb_sectors = 0;
	env->nb_objects = 0;
}

int	init_editor(int ac, char **av)
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
	init_editor_data(&env);
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
