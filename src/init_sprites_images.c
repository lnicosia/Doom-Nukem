/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_images.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 11:59:31 by marvin            #+#    #+#             */
/*   Updated: 2020/03/25 11:59:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     init_hud_sprites(t_env *env)
{
  	if (init_shotgun(env))
		return (custom_error("Failed to load shotgun textures\n"));
	if (init_raygun(env))
		return (custom_error("Failed to load raygun textures\n"));
	if (init_gun(env))
		return (custom_error("Failed to load gun textures\n"));  
    if (init_gatling(env))
		return (custom_error("Failed to load gatling textures\n"));
    if (parse_bmp("images/HUD/Ammo_hud.bmp", 26, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/Life_armor_hud.bmp", 27, env))
		return (custom_error("Invalid bmp file\n"));
    return (0);
}
