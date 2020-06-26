/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weapons_sprites2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 15:51:57 by gaerhard          #+#    #+#             */
/*   Updated: 2020/05/21 16:27:47 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		init_rocket_launcher(t_env *env)
{
	if (parse_bmp("images/HUD/rocket_launcher1.bmp", 53, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher2.bmp", 54, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher3.bmp", 55, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher4.bmp", 56, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher5.bmp", 57, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher6.bmp", 58, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher7.bmp", 59, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher8.bmp", 60, env))
		return (custom_error("Invalid bmp file\n"));
	if (parse_bmp("images/HUD/rocket_launcher9.bmp", 61, env))
		return (custom_error("Invalid bmp file\n"));
	return (0);
}
