/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 16:57:17 by sipatry           #+#    #+#             */
/*   Updated: 2020/05/20 16:44:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "parser.h"

int		init_editor_sprites(t_env *env)
{
	int	start;

	start = env->editor_start;
	if (parse_bmp("./images/sprites/doom_guy.bmp", start + 0, env))
		return (custom_error("Failed to load doom guy sprite\n"));
	if (parse_bmp("./images/sprites/doom_guy_face.bmp", start + 1, env))
		return (custom_error("Failed to load doom guy face sprite\n"));
	if (parse_bmp("./images/sprites/camera.bmp", start + 2, env))
		return (custom_error("Failed to load camera sprite\n"));
	return (0);
}

int		init_wall_sprites_textures(t_env *env)
{
	int	start;

	start = env->wall_sprites_start;
	if (parse_bmp("./images/sprites/bullet_hole.bmp", start + 0, env))
		return (custom_error("Failed to load bullet hole sprite\n"));
	if (parse_bmp("./images/sprites/button_off.bmp", start + 1, env))
		return (custom_error("Failed to load midspace\n"));
	if (parse_bmp("./images/sprites/button_on.bmp", start + 2, env))
		return (custom_error("Failed to load midspace\n"));
	if (parse_bmp("./images/sprites/MIDSPACE.bmp", start + 3, env))
		return (custom_error("Failed to load midspace\n"));
	return (0);
}

int		init_objects_sprites_textures(t_env *env)
{
	int	start;

	start = env->objects_sprites_start;
	if (parse_bmp("./images/sprites/sprite_sheet.bmp",
	start + 0, env))
		return (custom_error("Failed to load sprite sheet\n"));
	if (parse_bmp("./images/sprites/projectiles_sprites.bmp",
	start + 1, env))
		return (custom_error("Failed to load projectiles sprite sheet\n"));
	if (parse_bmp("./images/sprites/objects_sprites.bmp",
	start + 2, env))
		return (custom_error("Failed to load object sprites\n"));
	if (parse_bmp("./images/sprites/raygun.bmp", start + 3, env))
		return (custom_error("Failed to load raygun sprite\n"));
	if (parse_bmp("./images/sprites/rocket_launcher_sprites.bmp", start + 4,
		env))
		return (custom_error("Failed to load rocket launcher sprite\n"));
	if (parse_bmp("./images/sprites/gun_sprite_sheet.bmp", start + 5,
		env))
		return (custom_error("Failed to load gun sprite sheet\n"));
	return (0);
}
