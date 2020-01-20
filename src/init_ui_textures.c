/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:42:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/20 15:44:01 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_mini_ui_textures(t_env *env)
{
	ft_printf("erlaigfla\n");
	if (parse_bmp_mini_enemies_textures("images/ui/mini/lost_soul_mini.bmp", 0, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_mini_enemies_textures("images/ui/mini/cyber_demon_mini.bmp", 1, env))
		return (custom_error("Invalid bmp files"));
	return (0);
}

int		init_ui_textures(t_env *env)
{
	if (parse_bmp_ui_textures("images/ui/button-default-up.bmp", 0, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/button-default-pressed.bmp", 1, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/button-default-hover.bmp", 2, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/background-up-64.bmp", 3, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/background-pressed-64.bmp", 4, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/background-hover-64.bmp", 5, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/onglet-up.bmp", 6, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/onglet-pressed.bmp", 7, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/onglet-hover.bmp", 8, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/tab-button-up.bmp", 9, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/tab-button-pressed.bmp", 10, env))
		return (custom_error("Invalid bmp files"));
	if (parse_bmp_ui_textures("images/ui/tab-button-hover.bmp", 11, env))
		return (custom_error("Invalid bmp files"));
	if (init_mini_ui_textures(env))
		return (custom_error("error while parsing the miniatures of the enemies"));
	return (0);
}
