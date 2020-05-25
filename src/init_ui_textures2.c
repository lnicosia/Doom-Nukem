/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:24:38 by marvin            #+#    #+#             */
/*   Updated: 2020/05/22 15:46:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "init.h"

int	init_ui_textures6(t_env *env)
{
	if (parse_bmp_ui_textures("images/ui/next_arrow_hover.bmp", 59, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/previous-up2_pink.bmp", 61, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/previous-pressed2_pink.bmp", 62, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/previous-hover2_pink.bmp", 63, env))
		return (custom_error("Invalid bmp files"));
	if (init_mini_skyboxes_selection(env))
		return (custom_error("Could not init hud textures\n"));
	return (0);
}
