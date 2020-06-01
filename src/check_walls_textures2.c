/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls_textures2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/20 16:15:46 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 16:28:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_wall_textures6(t_env *env)
{
	int	i;
	int	fd;

	env->init.text_name[118] = "./images/textures/woodmet3.bmp";
	env->init.text_name[119] = "./images/textures/woodmet4.bmp";
	env->init.text_name[120] = "./images/textures/woodvert.bmp";
	env->init.text_name[121] = "./images/textures/zdoorb1.bmp";
	env->init.text_name[122] = "./images/textures/zdoorf1.bmp";
	env->init.text_name[123] = "./images/textures/zzwolf11.bmp";
	env->init.text_name[124] = "./images/textures/zzwolf12.bmp";
	env->init.text_name[125] = "./images/textures/zzwolf13.bmp";
	env->init.text_name[126] = "./images/textures/magma_rock.bmp";
	env->init.text_name[127] = "./images/textures/rock5.bmp";
	i = 0;
	while (i < MAX_WALL_TEXTURE)
	{
		if ((fd = open(env->init.text_name[i], O_RDONLY)) == -1)
			env->init.textures[i] = 1;
		if (!env->init.textures[i] && close(fd))
			return (custom_error("Could not close %s after textures check\n",
				env->init.text_name[i]));
			i++;
	}
	return (0);
}
