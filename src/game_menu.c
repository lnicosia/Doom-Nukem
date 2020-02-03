/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:53:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/21 15:53:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	start_game_menu(t_env *env)
{
	ft_printf("coucou\n");
	clear_image(env);
	SDL_SetRelativeMouseMode(0);
	apply_surface(env->sprite_textures[0].surface, new_point(0, 0), new_point(50, 50), env);
	update_screen(env);
}
