/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:39:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/08 10:20:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "save.h"

int		save_map(t_env *env)
{
	int		fd;

	env->saving = 0;
	ft_printf("Saving map in \"%s\"...\n", env->save_file);
	ft_printf("{red}");
	if ((fd = open(env->save_file, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (ft_printf("Could not open %s\n", env->save_file));
	write_vertices(fd, env);
	write_sectors(fd, env);
	write_objects(fd, env);
	write_enemies(fd, env);
	write_player(fd, env);
	if (close(fd))
		return (ft_printf("Could not close the file\n"));
	ft_printf("{reset}");
	if (env->editor.in_game)
		SDL_SetRelativeMouseMode(1);
	SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	return (0);
}
