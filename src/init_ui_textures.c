/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:42:47 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/13 17:06:46 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
	return (0);
}
