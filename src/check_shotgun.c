/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shotgun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:42:01 by marvin            #+#    #+#             */
/*   Updated: 2020/05/20 16:52:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_shotgun5(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.hud_names[12] = ft_strdup("./images/HUD/shot13.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot13.bmp", O_RDONLY)) == -1)
		env->init.hud[12] = 1;
	if (!env->init.hud[12] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[13] = ft_strdup("./images/HUD/shot14.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot14.bmp", O_RDONLY)) == -1)
		env->init.hud[13] = 1;
	if (!env->init.hud[13] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[14] = ft_strdup("./images/HUD/shot15.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot15.bmp", O_RDONLY)) == -1)
		env->init.hud[14] = 1;
	if (!env->init.hud[14] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	return (0);
}

int	check_shotgun4(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.hud_names[9] = ft_strdup("./images/HUD/shot10.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot10.bmp", O_RDONLY)) == -1)
		env->init.hud[9] = 1;
	if (!env->init.hud[9] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[10] = ft_strdup("./images/HUD/shot11.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot11.bmp", O_RDONLY)) == -1)
		env->init.hud[10] = 1;
	if (!env->init.hud[10] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[11] = ft_strdup("./images/HUD/shot12.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot12.bmp", O_RDONLY)) == -1)
		env->init.hud[11] = 1;
	if (!env->init.hud[11] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	return (check_shotgun5(env));
}

int	check_shotgun3(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.hud_names[6] = ft_strdup("./images/HUD/shot7.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot7.bmp", O_RDONLY)) == -1)
		env->init.hud[6] = 1;
	if (!env->init.hud[6] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[7] = ft_strdup("./images/HUD/shot8.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot8.bmp", O_RDONLY)) == -1)
		env->init.hud[7] = 1;
	if (!env->init.hud[7] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[8] = ft_strdup("./images/HUD/shot9.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot9.bmp", O_RDONLY)) == -1)
		env->init.hud[8] = 1;
	if (!env->init.hud[8] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	return (check_shotgun4(env));
}

int	check_shotgun2(t_env *env)
{
	int	fd;

	fd = 0;
    if (!(env->init.hud_names[3] = ft_strdup("./images/HUD/shot4.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot4.bmp", O_RDONLY)) == -1)
		env->init.hud[3] = 1;
	if (!env->init.hud[3] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[4] = ft_strdup("./images/HUD/shot5.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot5.bmp", O_RDONLY)) == -1)
		env->init.hud[4] = 1;
	if (!env->init.hud[4] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[5] = ft_strdup("./images/HUD/shot6.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot6.bmp", O_RDONLY)) == -1)
		env->init.hud[5] = 1;
	if (!env->init.hud[5] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	return (check_shotgun3(env));
}

int	check_shotgun(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.hud_names[0] = ft_strdup("./images/HUD/shot1.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot1.bmp", O_RDONLY)) == -1)
		env->init.hud[0] = 1;
	if (!env->init.hud[0] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[1] = ft_strdup("./images/HUD/shot2.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
 	if ((fd = open("./images/HUD/shot2.bmp", O_RDONLY)) == -1)
		env->init.hud[1] = 1;
	if (!env->init.hud[1] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	if (!(env->init.hud_names[2] = ft_strdup("./images/HUD/shot3.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/shot3.bmp", O_RDONLY)) == -1)
		env->init.hud[2] = 1;
	if (!env->init.hud[2] && close(fd))
		return (custom_error("Could not close the fd in check shotgun\n"));
	return (check_shotgun2(env));
}
