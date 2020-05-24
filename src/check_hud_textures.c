/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hud_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:48:37 by marvin            #+#    #+#             */
/*   Updated: 2020/05/22 19:41:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		check_hud_weapons(t_env *env)
{
	if (check_shotgun(env))
		return (custom_error("Failed to load shotgun textures\n"));
	if (check_raygun(env))
		return (custom_error("Failed to load raygun textures\n"));
	if (check_gun(env))
		return (custom_error("Failed to load gun textures\n"));
	if (check_gatling(env))
		return (custom_error("Failed to load gatling textures\n"));
	if (check_rocket_launcher(env))
		return (custom_error("Failed to load rocket launcher textures\n"));
	return (0);
}

int     check_hud_textures(t_env *env)
{
	int	fd;

	fd = 0;
	if (check_hud_weapons(env))
		return (custom_error("Could not init some weapons texutres\n"));
	if (!(env->init.hud_names[34] = ft_strdup("./images/HUD/Ammo_hud.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/Ammo_hud.bmp", O_RDONLY)) == -1)
		env->init.hud[34] = 1;
	if (!env->init.hud[34] && close(fd))
		return (custom_error("Could not close the fd in check hud textures\n"));
	if (!(env->init.hud_names[35] =
		ft_strdup("./images/HUD/Life_armor_hud.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("./images/HUD/Life_armor_hud.bmp", O_RDONLY)) == -1)
		env->init.hud[35] = 1;
	if (!env->init.hud[35] && close(fd))
		return (custom_error("Could not close the fd in check hud textures\n"));
	return (0);
}
