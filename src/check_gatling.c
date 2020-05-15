/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gatling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:17:29 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 17:58:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_gatling2(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.hud_names[31] = ft_strdup("images/HUD/Gatling_4.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Gatling_4.bmp", O_RDONLY)) == -1)
		env->init.hud[31] = 1;
	if (!env->init.hud[31] && close(fd))
		return (custom_error("Could not close the fd in check Gatling\n"));
	if (!(env->init.hud_names[32] = ft_strdup("images/HUD/Gatling_5.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Gatling_5.bmp", O_RDONLY)) == -1)
		env->init.hud[32] = 1;
	if (!env->init.hud[32] && close(fd))
		return (custom_error("Could not close the fd in check Gatling\n"));
	if (!(env->init.hud_names[33] = ft_strdup("images/HUD/Gatling_6.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Gatling_6.bmp", O_RDONLY)) == -1)
		env->init.hud[33] = 1;
	if (!env->init.hud[33] && close(fd))
		return (custom_error("Could not close the fd in check Gatling\n"));
	return (0);
}

int	check_gatling(t_env *env)
{
	int fd;

	fd = 0;
	if (!(env->init.hud_names[28] = ft_strdup("images/HUD/Gatling_1.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Gatling_1.bmp", O_RDONLY)) == -1)
		env->init.hud[28] = 1;
	if (!env->init.hud[28] && close(fd))
		return (custom_error("Could not close the fd in check Gatling\n"));
	if (!(env->init.hud_names[29] = ft_strdup("images/HUD/Gatling_2.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Gatling_2.bmp", O_RDONLY)) == -1)
		env->init.hud[29] = 1;
	if (!env->init.hud[29] && close(fd))
		return (custom_error("Could not close the fd in check Gatling\n"));
	if (!(env->init.hud_names[30] = ft_strdup("images/HUD/Gatling_3.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Gatling_3.bmp", O_RDONLY)) == -1)
		env->init.hud[30] = 1;
	if (!env->init.hud[30] && close(fd))
		return (custom_error("Could not close the fd in check Gatling\n"));
	return (check_gatling2(env));
}
