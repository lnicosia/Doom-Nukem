/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_skyboxes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 09:15:55 by marvin            #+#    #+#             */
/*   Updated: 2020/04/21 09:15:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "parser.h"

int     new_parsed_skyboxe(char *name, t_env *env)
{
    int i;
    int j;

    j = 0;
    i = 0;
    while (i < MAX_WALL_TEXTURE)
    {
        if (i % 3 == 0)
            j++;
        if (ft_strcmp(name, env->init.skyboxes_names[i])
        && env->init.skyboxes[i])
        {
            if (parse_bmp_skybox_textures(name, i, j, env))
		        return (-1);
        }
        i++;
    }
    return (0);
}

int		check_skyboxes2(t_env *env)
{
    if (new_parsed_skyboxe("images/skyboxes/nebula_left.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/nebula_front.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/nebula_right.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/bottom.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/top.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/back.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/left.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/front.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/right.bmp", env))
		return (custom_error("Failed to load skybox\n"));
    return (0);
}

int		check_skyboxes(t_env *env)
{
	if (new_parsed_skyboxe("images/skyboxes/night_bottom.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/night_top.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/night_back.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/night_left.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/night_front.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/night_right.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/nebula_bottom.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/nebula_top.bmp", env))
		return (custom_error("Failed to load skybox\n"));
	if (new_parsed_skyboxe("images/skyboxes/nebula_back.bmp", env))
		return (custom_error("Failed to load skybox\n"));	
    if (check_skyboxes2(env))
        return (-1);
	return (0);
}
