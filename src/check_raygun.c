/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_raygun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:03:23 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 21:16:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_raygun3(t_env *env)
{
	int fd;

	fd = 0;
	if (!(env->init.hud_names[21] = ft_strdup("images/HUD/raygun7.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun7.bmp", O_RDONLY)) == -1)
		env->init.hud[21] = 1;
	if (!env->init.hud[21] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	return (0);
}

int	check_raygun2(t_env *env)
{
	int fd;

	fd = 0;
	if (!(env->init.hud_names[18] = ft_strdup("images/HUD/raygun4.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun4.bmp", O_RDONLY)) == -1)
		env->init.hud[18] = 1;
	if (!env->init.hud[18] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	if (!(env->init.hud_names[19] = ft_strdup("images/HUD/raygun5.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun5.bmp", O_RDONLY)) == -1)
		env->init.hud[19] = 1;
	if (!env->init.hud[19] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	if (!(env->init.hud_names[20] = ft_strdup("images/HUD/raygun6.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun6.bmp", O_RDONLY)) == -1)
		env->init.hud[20] = 1;
	if (!env->init.hud[20] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	return (check_raygun3(env));
}

int	check_raygun(t_env *env)
{
	int fd;

	fd = 0;
	if (!(env->init.hud_names[15] = ft_strdup("images/HUD/raygun1.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun1.bmp", O_RDONLY)) == -1)
		env->init.hud[15] = 1;
	if (!env->init.hud[15] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	if (!(env->init.hud_names[16] = ft_strdup("images/HUD/raygun2.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun2.bmp", O_RDONLY)) == -1)
		env->init.hud[16] = 1;
	if (!env->init.hud[16] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	if (!(env->init.hud_names[17] = ft_strdup("images/HUD/raygun3.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/raygun3.bmp", O_RDONLY)) == -1)
		env->init.hud[17] = 1;
	if (!env->init.hud[17] && close(fd))
		return (custom_error("Could not close the fd in check raygun\n"));
	return (check_raygun2(env));
}
