/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:39:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/11 14:43:58 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "save.h"

int		save_map(char *file, t_env *env)
{
	int		fd;

	ft_printf("Saving map in \"%s\"...\n", file);
	ft_printf("{red}");
	if ((fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0000700)) < 0)
		return (ft_printf("Could not open %s\n", file));
	write_vertices(fd, env);
	write_sectors(fd, env);
	write_objects(fd, env);
	write_enemies(fd, env);
	write_player(fd, env);
	if (close(fd))
		return (ft_printf("Could not close the file\n"));
	ft_printf("{reset}");
	return (0);
}
