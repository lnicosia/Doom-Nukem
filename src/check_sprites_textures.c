/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sprites_textures.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 14:50:35 by marvin            #+#    #+#             */
/*   Updated: 2020/04/22 14:50:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_enemies_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.enemy_names[0] =
	ft_strdup("images/sprites/cyber_demon.bmp")))
		return (ft_perror("Error while parsing enemy sprite texture\n"));
	if ((fd = open("images/sprites/cyber_demon.bmp", O_RDONLY)) == -1)
		env->init.enemies[0] = 1;
	if (!(env->init.enemy_names[1] =
	ft_strdup("images/sprites/lost_soul.bmp")))
		return (ft_perror("Error while parsing enemy sprite texture\n"));
	if ((fd = open("images/sprites/lost_soul.bmp", O_RDONLY)) == -1)
		env->init.enemies[1] = 1;
	return (0);
}

int		check_wall_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.sprites_names[0] =
	ft_strdup("images/sprites/bullet_hole.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("images/sprites/bullet_hole.bmp", O_RDONLY)) == -1)
		env->init.sprites[0] = 1;
	if (!(env->init.sprites_names[1] =
	ft_strdup("images/sprites/button_off.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("images/sprites/button_off.bmp", O_RDONLY, env)) == -1)
		env->init.sprites[1] = 1;
	if (!(env->init.sprites_names[2] =
	ft_strdup("images/sprites/button_on.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("images/sprites/button_on.bmp", O_RDONLY, env)) == -1)
		env->init.sprites[2] = 1;
	if (!(env->init.sprites_names[3] =
	ft_strdup("images/sprites/MIDSPACE.bmp")))
		return (ft_perror("Error while parsing wall sprite\n"));
	if ((fd = open("images/sprites/MIDSPACE.bmp", O_RDONLY, env)) == -1)
		env->init.sprites[3] = 1;
	return (0);
}

int		check_object_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.objects_names[0] =
	ft_strdup("images/sprites/objects_sprites.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("images/sprites/objects_sprites.bmp", O_RDONLY)) == -1)
		env->init.objects[0] = 1;
	if (!(env->init.objects_names[1] =
	ft_strdup("images/sprites/sprite_sheet.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("images/sprites/sprite_sheet.bmp", O_RDONLY)) == -1)
		env->init.objects[1] = 1;
	if (!(env->init.objects_names[2] =
	ft_strdup("images/sprites/projectiles_sprites.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("images/sprites/projectiles_sprites.bmp", O_RDONLY)) == -1)
		env->init.objects[2] = 1;
	if (!(env->init.objects_names[3] =
	ft_strdup("images/sprites/raygun.bmp")))
		return (ft_perror("Error while parsing object sprite texture\n"));
	if ((fd = open("images/sprites/raygun.bmp", O_RDONLY)) == -1)
		env->init.objects[3] = 1;
	return (0);
}

int		check_editor_sprites_textures(t_env *env)
{
	int	fd;

	if (!(env->init.sprites_names[0] =
	ft_strdup("images/sprites/camera.bmp")))
		return (ft_perror("Error while parsing editor sprite\n"));
	if ((fd = open("images/sprites/camera.bmp", O_RDONLY)) == -1)
		env->init.sprites[0] = 1;
	if (!(env->init.sprites_names[1] =
	ft_strdup("images/sprites/doom_guy.bmp")))
		return (ft_perror("Error while parsing editor sprite\n"));
	if ((fd = open("images/sprites/doom_guy.bmp", O_RDONLY)) == -1)
		env->init.sprites[1] = 1;
	if (!(env->init.sprites_names[2] =
	ft_strdup("images/sprites/doom_guy_face.bmp")))
		return (ft_perror("Error while parsing editor sprite\n"));
	if ((fd = open("images/sprites/doom_guy_face.bmp", O_RDONLY)) == -1)
		env->init.sprites[2] = 1;
	return (0);
}

int		check_sprites_textures(t_env *env)
{
	check_enemies_sprites_textures(env);
	check_wall_sprites_textures(env);
	check_object_sprites_textures(env);
	check_editor_sprites_textures(env);
	return (0);
}