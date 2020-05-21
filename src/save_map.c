/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:39:43 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/21 18:08:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "save.h"

void	write_data(int fd, t_env *env)
{
	write_vertices(fd, env);
	write_sectors(fd, env);
	write_objects(fd, env);
	write_enemies(fd, env);
	write_events(fd, env);
	write_events_links(fd, env);
	write_music_choices(fd, env);
	write_player(fd, env);
}

int		save_map(void *param)
{
	t_env			*env;
	int				fd;

	env = (t_env*)param;
	ft_printf("Saving map in \"%s\"...\n", env->save_file);
	if ((fd = open(env->save_file, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (custom_error("Could not open %s\n", env->save_file));
	if (write_resources(fd, env))
	{
		if (close(fd))
			return (-1);
		return (-1);
	}
	write_data(fd, env);
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
