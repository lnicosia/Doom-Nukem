/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprites_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:50:35 by marvin            #+#    #+#             */
/*   Updated: 2020/05/21 15:12:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_enemies_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.enemy_names[0] =
	ft_strdup("./images/sprites/cyber_demon.bmp")))
		return (ft_perror("Error while parsing enemy sprite texture\n"));
	if ((fd = open("./images/sprites/cyber_demon.bmp", O_RDONLY)) == -1)
		env->init.enemies[0] = 1;
	if (!env->init.enemies[0] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	if (!(env->init.enemy_names[1] =
	ft_strdup("./images/sprites/lost_soul.bmp")))
		return (ft_perror("Error while parsing enemy sprite texture\n"));
	if ((fd = open("./images/sprites/lost_soul.bmp", O_RDONLY)) == -1)
		env->init.enemies[1] = 1;
	if (!env->init.enemies[1] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	return (0);
}

int		check_object_sprites_textures2(t_env *env)
{
	int	fd;

	fd = 0;
	if (!(env->init.objects_names[3] =
	ft_strdup("./images/sprites/raygun.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("./images/sprites/raygun.bmp", O_RDONLY)) == -1)
		env->init.objects[3] = 1;
	if (!env->init.objects[3] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	return (0);
}

int		check_object_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.objects_names[0] =
	ft_strdup("./images/sprites/objects_sprites.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("./images/sprites/objects_sprites.bmp", O_RDONLY)) == -1)
		env->init.objects[0] = 1;
	if (!env->init.objects[0] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	if (!(env->init.objects_names[1] =
	ft_strdup("./images/sprites/sprite_sheet.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("./images/sprites/sprite_sheet.bmp", O_RDONLY)) == -1)
		env->init.objects[1] = 1;
	if (!env->init.objects[1] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	if (!(env->init.objects_names[2] =
	ft_strdup("./images/sprites/projectiles_sprites.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("./images/sprites/projectiles_sprites.bmp", O_RDONLY)) == -1)
		env->init.objects[2] = 1;
	if (!env->init.objects[2] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	return (check_object_sprites_textures2(env));
}

int		check_editor_sprites_textures(t_env *env)
{
	int	fd;

	env->init.editor_names[0] = "./images/sprites/doom_guy.bmp";
	if ((fd = open("./images/sprites/doom_guy.bmp", O_RDONLY)) == -1)
		env->init.editor[0] = 1;
	if (!env->init.editor[0] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	env->init.editor_names[1] = "./images/sprites/doom_guy_face.bmp";
	if ((fd = open("./images/sprites/doom_guy_face.bmp", O_RDONLY)) == -1)
		env->init.editor[1] = 1;
	if (!env->init.editor[1] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	env->init.editor_names[2] = "./images/sprites/camera.bmp";
	if ((fd = open("./images/sprites/camera.bmp", O_RDONLY)) == -1)
		env->init.editor[2] = 1;
	if (!env->init.editor[2] && close(fd))
		return (custom_error("Could not close the file in check sprites\n"));
	return (0);
}

int		check_sprites_textures(t_env *env)
{
	if (check_enemies_sprites_textures(env))
		return (-1);
	if (check_wall_sprites_textures(env))
		return (-1);
	if (check_object_sprites_textures(env))
		return (-1);
	if (check_editor_sprites_textures(env))
		return (-1);
	return (0);
}
