/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ui_textures2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 15:24:38 by marvin            #+#    #+#             */
/*   Updated: 2020/05/08 15:24:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		check_mini_skyboxes_selection(t_env *env)
{
	if (parse_bmp_mini_skyboxes_textures("images/ui/moonlight.bmp", 0,
		env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_mini_skyboxes_textures("images/ui/nebula.bmp", 1,
		env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_mini_skyboxes_textures("images/ui/beautifull_scenery"
		".bmp", 2, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_mini_skyboxes_textures("images/ui/moonlight_128.bmp",
		3, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_mini_skyboxes_textures("images/ui/nebula_128.bmp", 4,
		env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_mini_skyboxes_textures("images/ui/beautifull_scenery"
		"_128.bmp", 5, env))
		return (custom_error("Invalid bmp files\n"));
	return (0);
}

int init_ui_textures6(t_env *env)
{
    if (parse_bmp_ui_textures("images/ui/next_arrow_hover.bmp", 59, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/dialog_box.bmp", 60, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/previous-up2_pink.bmp", 61, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/previous-pressed2_pink.bmp", 62, env))
		return (custom_error("Invalid bmp files\n"));
	if (parse_bmp_ui_textures("images/ui/previous-hover2_pink.bmp", 63, env))
		return (custom_error("Invalid bmp files"));
    return (0);
}