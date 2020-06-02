/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_weapons_sprites2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:03:27 by user42            #+#    #+#             */
/*   Updated: 2020/05/22 19:05:50 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_rocket_launcher(t_env *env)
{
	if (new_parsed_hud_file("images/HUD/rocket_launcher1.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher2.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher3.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher4.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher5.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher6.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher7.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher8.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_hud_file("images/HUD/rocket_launcher9.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}
