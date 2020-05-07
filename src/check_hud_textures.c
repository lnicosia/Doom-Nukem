/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hud_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:48:37 by marvin            #+#    #+#             */
/*   Updated: 2020/04/21 09:48:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int		new_parsing_sprite(char *name, int index, t_env *env)
{
	if (check_existing_files(env, name))
	{
		if (parse_bmp(name, index, env))
			return (ft_printf("Failed to load lost soul\n"));
	}
	return (0);
}

int     check_hud_textures(t_env *env)
{
	int start;

	start = env->hud_start;
	if (check_shotgun(env))
		return (ft_printf("Failed to load shotgun textures\n"));
	if (check_raygun(env))
		return (ft_printf("Failed to load raygun textures\n"));
	if (check_gun(env))
		return (ft_printf("Failed to load gun textures\n"));  
    if (check_gatling(env))
		return (ft_printf("Failed to load gatling textures\n"));
	if (new_parsing_sprite("images/HUD/Ammo_hud.bmp", start + 34, env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsing_sprite("images/HUD/Life_armor_hud.bmp", start + 35, env))
		return (ft_printf("Invalid bmp file\n"));
    return (0);
}