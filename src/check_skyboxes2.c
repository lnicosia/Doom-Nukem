/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_skyboxes2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:57:59 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 17:40:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		check_skyboxes6(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.skyboxes_names[15] =
		ft_strdup("images/skyboxes/left.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/left.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[15] = 1;
	if (!env->init.skyboxes[15] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[16] =
		ft_strdup("images/skyboxes/front.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/front.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[16] = 1;
	if (!env->init.skyboxes[16] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	if (!(env->init.skyboxes_names[17] =
		ft_strdup("images/skyboxes/right.bmp")))
		return (ft_perror("Error while parsing skyboxe\n"));
	if ((fd = open("images/skyboxes/right.bmp", O_RDONLY)) == -1)
		env->init.skyboxes[17] = 1;
	if (!env->init.skyboxes[17] && close(fd))
		return (custom_error("Could not close the fd in check skyboxes\n"));
	return (0);
}
