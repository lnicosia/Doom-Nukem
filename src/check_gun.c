/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_gun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 17:13:41 by marvin            #+#    #+#             */
/*   Updated: 2020/05/08 17:13:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int check_gun2(t_env *env)
{
    int fd = 0;
    
    fd = 0;
    if (!(env->init.hud_names[25] = ft_strdup("./images/HUD/gun_4.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/gun_4.bmp", O_RDONLY)) == -1)
		env->init.hud[25] = 1;
    if (!env->init.hud[25] && close(fd))
		return (custom_error("Could not close the fd in check gun\n"));
    if (!(env->init.hud_names[26] = ft_strdup("./images/HUD/gun_5.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/gun_5.bmp", O_RDONLY)) == -1)
		env->init.hud[26] = 1;
    if (!env->init.hud[26] && close(fd))
		return (custom_error("Could not close the fd in check gun\n"));
	if (!(env->init.hud_names[27] = ft_strdup("./images/HUD/gun_6.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/gun_6.bmp", O_RDONLY)) == -1)
		env->init.hud[27] = 1;
    if (!env->init.hud[27] && close(fd))
		return (custom_error("Could not close the fd in check gun\n"));
    return (0);
}

int     check_gun(t_env *env)
{
    int    fd;

    fd = 0;
    if (!(env->init.hud_names[22] = ft_strdup("./images/HUD/gun_1.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/gun_1.bmp", O_RDONLY)) == -1)
		env->init.hud[22] = 1;
    if (!env->init.hud[22] && close(fd))
		return (custom_error("Could not close the fd in check gun\n"));
	if (!(env->init.hud_names[23] = ft_strdup("./images/HUD/gun_2.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/gun_2.bmp", O_RDONLY)) == -1)
		env->init.hud[23] = 1;
    if (!env->init.hud[23] && close(fd))
		return (custom_error("Could not close the fd in check gun\n"));
    if (!(env->init.hud_names[24] = ft_strdup("./images/HUD/gun_3.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/gun_3.bmp", O_RDONLY)) == -1)
		env->init.hud[24] = 1;
    if (!env->init.hud[24] && close(fd))
		return (custom_error("Could not close the fd in check gun\n"));
    return (check_gun2(env));
}
