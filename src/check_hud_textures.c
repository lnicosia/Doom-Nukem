/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hud_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:48:37 by marvin            #+#    #+#             */
/*   Updated: 2020/05/15 18:02:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int	check_hud_textures(t_env *env)
{
	int	fd;

	fd = 0;
	if (check_shotgun(env))
		return (custom_error("Failed to load shotgun textures\n"));
	if (check_raygun(env))
		return (custom_error("Failed to load raygun textures\n"));
	if (check_gun(env))
		return (custom_error("Failed to load gun textures\n"));
	if (check_gatling(env))
		return (custom_error("Failed to load gatling textures\n"));
	if (!(env->init.hud_names[34] = ft_strdup("images/HUD/Ammo_hud.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Ammo_hud.bmp", O_RDONLY)) == -1)
		env->init.hud[34] = 1;
	if (!env->init.hud[34] && close(fd))
		return (custom_error("Could not close the fd in check hud textures\n"));
	if (!(env->init.hud_names[35] = ft_strdup("images/HUD/Life_armor_hud.bmp")))
		return (ft_perror("Error while parsing hud textures\n"));
	if ((fd = open("images/HUD/Life_armor_hud.bmp", O_RDONLY)) == -1)
		env->init.hud[35] = 1;
	if (!env->init.hud[35] && close(fd))
		return (custom_error("Could not close the fd in check hud textures\n"));
	return (0);
}
