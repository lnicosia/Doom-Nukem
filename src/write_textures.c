/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 10:16:20 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/14 16:15:30 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "save.h"
#include "bmp_parser.h"

int		write_textures1(t_env *env, int fd)
{
	int		i;
	int		file;

	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		if ((file = open(env->init.text_name[i], O_RDONLY)) < 0)
			return (custom_error("Could not open %s to save it\n",
				env->init.text_name[i]));
			if (writing_bmp(file, fd, env->init.text_name[i]))
				return (custom_error("Could not write %s\n",
				env->init.text_name[i]));
			i++;
	}
	return (0);
}
