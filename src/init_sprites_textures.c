/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:57:17 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/12 18:07:31 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		init_editor_sprites(t_env *env)
{
	int start;

	start = env->editor_start;
	if (!(env->init.sprites_names[0] =
	ft_strdup("images/sprites/camera.bmp")))
		return (ft_printf("Error while parsing editor sprite\n"));
	if (parse_bmp("images/sprites/camera.bmp", start + 0, env))
		env->init.sprites[0] = 1;
	if (!(env->init.sprites_names[1] =
	ft_strdup("images/sprites/doom_guy.bmp")))
		return (ft_printf("Error while parsing editor sprite\n"));
	if (parse_bmp("images/sprites/doom_guy.bmp", start + 1, env))
		env->init.sprites[1] = 1;
	if (!(env->init.sprites_names[2] =
	ft_strdup("images/sprites/doom_guy_face.bmp")))
		return (ft_printf("Error while parsing editor sprite\n"));
	if (parse_bmp("images/sprites/doom_guy_face.bmp", start + 2, env))
		env->init.sprites[2] = 1;
	return (0);
}

int		init_wall_sprites_textures(t_env *env)
{
	int start;

	start = env->wall_sprites_start;
	ft_printf("start: %d\n", start);
	if (!(env->init.sprites_names[0] =
	ft_strdup("images/sprites/bullet_hole.bmp")))
		return (ft_printf("Error while parsing wall sprite\n"));
	if (parse_bmp("images/sprites/bullet_hole.bmp", start + 0, env))
		env->init.sprites[0] = 1;
	if (!(env->init.sprites_names[1] =
	ft_strdup("images/sprites/button_off.bmp")))
		return (ft_printf("Error while parsing wall sprite\n"));
	if (parse_bmp("images/sprites/button_off.bmp", start + 1, env))
		env->init.sprites[1] = 1;
	if (!(env->init.sprites_names[2] =
	ft_strdup("images/sprites/button_on.bmp")))
		return (ft_printf("Error while parsing wall sprite\n"));
	if (parse_bmp("images/sprites/button_on.bmp", start + 2, env))
		env->init.sprites[2] = 1;
	if (!(env->init.sprites_names[3] =
	ft_strdup("images/sprites/MIDSPACE.bmp")))
		return (ft_printf("Error while parsing wall sprite\n"));
	if (parse_bmp("images/sprites/MIDSPACE.bmp", start + 3, env))
		env->init.sprites[3] = 1;
	return (0);
}

int		init_objects_sprites_textures(t_env *env)
{
	int start;

	start = env->objects_sprites_start;
	if (!(env->init.objects_names[0] =
	ft_strdup("images/sprites/objects_sprites.bmp")))
		return (ft_printf("Error while parsing object sprite texture\n"));
	if (parse_bmp("images/sprites/objects_sprites.bmp", start + 0, env))
		env->init.objects[0] = 1;
	if (!(env->init.objects_names[1] =
	ft_strdup("images/sprites/sprite_sheet.bmp")))
		return (ft_printf("Error while parsing object sprite texture\n"));
	if (parse_bmp("images/sprites/sprite_sheet.bmp", start + 1, env))
		env->init.objects[1] = 1;
	if (!(env->init.objects_names[2] =
	ft_strdup("images/sprites/projectiles_sprites.bmp")))
		return (ft_printf("Error while parsing object sprite texture\n"));
	if (parse_bmp("images/sprites/projectiles_sprites.bmp", start + 2, env))
		env->init.objects[2] = 1;
	if (!(env->init.objects_names[3] =
	ft_strdup("images/sprites/raygun.bmp")))
		return (ft_printf("Error while parsing object sprite texture\n"));
	if (parse_bmp("images/sprites/raygun.bmp", start + 3, env))
		env->init.objects[3] = 1;
	return (0);
}