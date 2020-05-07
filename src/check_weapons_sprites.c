/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_weapons_sprites.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 14:46:37 by marvin            #+#    #+#             */
/*   Updated: 2020/04/24 12:15:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     check_shotgun2(t_env *env)
{
    if (new_parsed_hud_file("images/HUD/shot8.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
    if (new_parsed_hud_file("images/HUD/shot9.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot10.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot11.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot12.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot13.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot14.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot15.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
    return (0);
}

int		check_shotgun(t_env *env)
{
	if (new_parsed_hud_file("images/HUD/shot1.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
 	if (new_parsed_hud_file("images/HUD/shot2.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot3.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot4.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot5.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot6.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/shot7.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (check_shotgun2(env))
        return (ft_printf("Error while loadig shotgun sprites\n"));
	return (0);
}

int		check_raygun(t_env *env)
{
	if (new_parsed_hud_file("images/HUD/raygun1.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/raygun2.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/raygun3.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/raygun4.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/raygun5.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/raygun6.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/raygun7.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		check_gun(t_env *env)
{
	if (new_parsed_hud_file("images/HUD/gun_1.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/gun_2.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/gun_3.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/gun_4.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/gun_5.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/gun_6.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}

int		check_gatling(t_env *env)
{
	if (new_parsed_hud_file("images/HUD/Gatling/Gatling_1.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/Gatling/Gatling_2.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/Gatling/Gatling_3.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/Gatling/Gatling_4.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/Gatling/Gatling_5.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/Gatling/Gatling_6.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
    if (new_parsed_hud_file("images/HUD/Ammo_hud.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
    if (new_parsed_hud_file("images/HUD/Life_armor_hud.bmp", env))
		return (ft_printf("Invalid bmp file\n"));
	return (0);
}