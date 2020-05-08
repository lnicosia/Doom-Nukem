/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_textures.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:15:46 by marvin            #+#    #+#             */
/*   Updated: 2020/04/20 16:15:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int     check_wall_textures2(t_env *env)
{
	if (new_parsed_textures("./images/textures/grass1.bmp", env))
		return (custom_error("Failed to load grass1\n"));
	if (new_parsed_textures("./images/textures/grass2.bmp", env))
		return (custom_error("Failed to load grass2\n"));
	if (new_parsed_textures("./images/textures/grass3.bmp", env))
		return (custom_error("Failed to load grass3\n"));
	if (new_parsed_textures("./images/textures/tiles.bmp", env))
		return (custom_error("Failed to load tiles\n"));
	if (new_parsed_textures("./images/textures/sand.bmp", env))
		return (custom_error("Failed to load sand\n"));
	if (new_parsed_textures("./images/textures/grey.bmp", env))
		return (custom_error("Failed to load grey\n"));
    return (0);
}

int		check_wall_textures(t_env *env)
{
    if (new_parsed_textures("./images/textures/wall0.bmp", env))
	    return (custom_error("Invalid bmp file\n"));
    if (new_parsed_textures("./images/textures/wall1.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_textures("./images/textures/wall2.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_textures("./images/textures/wall3.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_textures("./images/textures/floor0.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_textures("./images/textures/floor1.bmp", env))
		return (custom_error("Invalid bmp file\n"));
	if (new_parsed_textures("./images/textures/rust.bmp", env))
		return (custom_error("Failed to load rust\n"));
	if (new_parsed_textures("./images/textures/black_tiles.bmp", env))
		return (custom_error("Failed to load black_tiles\n"));
	if (new_parsed_textures("./images/textures/rock.bmp", env))
		return (custom_error("Failed to load rock\n"));
	return (0);
}
