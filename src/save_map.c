/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:39:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 11:08:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "save.h"

int		save_map(void *param)
{
	t_env			*env;
	int				fd;

	env = (t_env*)param;
	ft_printf("Saving map in \"%s\"...\n", env->save_file);
	ft_printf("{red}");
	if (valid_map(env))
	{
		if (update_confirmation_box(&env->confirmation_box, "Map is not valid",
			ERROR, env))
			return (-1);
		return (0);
	}
	if ((fd = open(env->save_file, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (custom_error("Could not open %s\n", env->save_file));
	if (write_resources(fd, env))
	{
		if (close(fd))
			return (-1);
		return(-1);
	}
	write_vertices(fd, env);
	write_sectors(fd, env);
	write_objects(fd, env);
	write_enemies(fd, env);
	write_events(fd, env);
	write_events_links(fd, env);
	write_music_choices(fd, env);
	write_player(fd, env);
	ft_printf("{reset}");
	if (env->editor.in_game && !env->editor.tab)
	{
		SDL_SetRelativeMouseMode(1);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
		SDL_GetRelativeMouseState(&env->sdl.mouse_x, &env->sdl.mouse_y);
	}
	if (close(fd))
		return (custom_error("Current map file could not be closed\n"));
	ft_printf("Map saved\n");
	return (0);
}
