/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rocket_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:17:49 by user42            #+#    #+#             */
/*   Updated: 2020/05/22 19:33:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     check_rocket_launcher3(t_env *env)
{
    int fd;

    fd = 0;
    if (!(env->init.hud_names[42] =
        ft_strdup("./images/HUD/rocket_launcher7.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher7.bmp", O_RDONLY)) == -1)
		env->init.hud[42] = 1;
    if (!env->init.hud[42] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    if (!(env->init.hud_names[43] =
        ft_strdup("./images/HUD/rocket_launcher8.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher8.bmp", O_RDONLY)) == -1)
		env->init.hud[43] = 1;
    if (!env->init.hud[43] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    if (!(env->init.hud_names[44] =
        ft_strdup("./images/HUD/rocket_launcher9.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher9.bmp", O_RDONLY)) == -1)
		env->init.hud[44] = 1;
    if (!env->init.hud[44] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    return (0);
}

int     check_rocket_launcher2(t_env *env)
{
    int fd;

    fd = 0;
    if (!(env->init.hud_names[39] =
        ft_strdup("./images/HUD/rocket_launcher4.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher4.bmp", O_RDONLY)) == -1)
		env->init.hud[39] = 1;
    if (!env->init.hud[39] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    if (!(env->init.hud_names[40] =
        ft_strdup("./images/HUD/rocket_launcher5.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher5.bmp", O_RDONLY)) == -1)
		env->init.hud[40] = 1;
    if (!env->init.hud[40] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    if (!(env->init.hud_names[41] =
        ft_strdup("./images/HUD/rocket_launcher6.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher6.bmp", O_RDONLY)) == -1)
		env->init.hud[41] = 1;
    if (!env->init.hud[41] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    return (check_rocket_launcher3(env));
}

int		check_rocket_launcher(t_env *env)
{
    int fd;

    fd = 0;
    if (!(env->init.hud_names[36] =
        ft_strdup("./images/HUD/rocket_launcher1.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher1.bmp", O_RDONLY)) == -1)
		env->init.hud[36] = 1;
    if (!env->init.hud[36] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    if (!(env->init.hud_names[37] =
        ft_strdup("./images/HUD/rocket_launcher2.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher2.bmp", O_RDONLY)) == -1)
		env->init.hud[37] = 1;
    if (!env->init.hud[37] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    if (!(env->init.hud_names[38] =
        ft_strdup("./images/HUD/rocket_launcher3.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/rocket_launcher3.bmp", O_RDONLY)) == -1)
		env->init.hud[38] = 1;
    if (!env->init.hud[38] && close(fd))
		return (custom_error("Could not close the fd in check rocket\n"));
    return (check_rocket_launcher2(env));
}
