/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_sprites_textures.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 12:53:14 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 15:16:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	check_wall_sprites_textures2(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.sprites_names[3] =
	ft_strdup("./images/sprites/MIDSPACE.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("./images/sprites/MIDSPACE.bmp", O_RDONLY, env)) == -1)
		env->init.sprites[3] = 1;
	if (!env->init.sprites[3] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	return (0);
}

int	check_wall_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.sprites_names[0] =
	ft_strdup("./images/sprites/bullet_hole.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("./images/sprites/bullet_hole.bmp", O_RDONLY)) == -1)
		env->init.sprites[0] = 1;
	if (!env->init.sprites[0] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	if (!(env->init.sprites_names[1] =
	ft_strdup("./images/sprites/button_off.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("./images/sprites/button_off.bmp", O_RDONLY, env)) == -1)
		env->init.sprites[1] = 1;
	if (!env->init.sprites[1] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	if (!(env->init.sprites_names[2] =
	ft_strdup("./images/sprites/button_on.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("./images/sprites/button_on.bmp", O_RDONLY, env)) == -1)
		env->init.sprites[2] = 1;
	if (!env->init.sprites[2] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	return (check_wall_sprites_textures2(env));
}
