/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 11:31:07 by marvin            #+#    #+#             */
/*   Updated: 2020/05/08 11:31:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "env.h"

int		check_textures(t_env *env)
{
	if (check_wall_textures(env))
		return (custom_error("Could not load Wall textures\n"));
	if (check_sprites_textures(env))
		return (custom_error("Could not load sprites textures\n"));
	if (check_skyboxes(env))
		return (custom_error("Could not load skyboxes textures\n"));
	if (check_hud_textures(env))
		return (custom_error("Could not load hud textures\n"));
	return (0);
}

int    check_resources(t_env *env)
{
	if (check_textures(env))
		return (custom_error("Error while checking resources\n"));
	if (check_fonts(env))
		return (custom_error("Error while checking resources\n"));	
	if (check_sounds(env))
		return (custom_error("Error while checking resources\n"));	
	return (0);
}