/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:10:19 by sipatry           #+#    #+#             */
/*   Updated: 2019/12/04 18:37:04 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	init_array_buttons(t_env *env)
{
	int	i;

	i = 0;
	t_button	*textures;
	if (!(textures = (t_button*)malloc(sizeof(t_button) * MAX_WALL_TEXTURE)))
		return (perror("Could not maloc the texture buttons array"));
	while (i < MAX_WALL_TEXTURE)
	{
		textures[i] = new_image_button()
	}
	return (1);
}

int	init_hud(t_env *env)
{
	if (!init_array_buttons(env));
		return (0);
	return (1);
}