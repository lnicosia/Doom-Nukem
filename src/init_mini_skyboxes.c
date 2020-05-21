/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mini_skyboxes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 10:58:23 by marvin            #+#    #+#             */
/*   Updated: 2020/04/20 10:58:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int	init_mini_skyboxes_selection(t_env *env)
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
