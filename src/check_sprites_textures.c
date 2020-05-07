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
	int	start;

	start = env->enemies_start;
	if (new_parsing_sprite("images/sprites/lost_soul.bmp", start + 0, env))
		return (ft_printf("Failed to load lost soul\n"));
	if (new_parsing_sprite("images/sprites/cyber_demon.bmp", start + 1, env))
		return (ft_printf("Failed to load cyber demon sprite sheet\n"));
	return (0);
}

int		check_wall_sprites_textures(t_env *env)
{
	int	start;

	start = env->wall_sprites_start;
	if (new_parsing_sprite("images/sprites/bullet_hole.bmp", start + 0, env))
		return (ft_printf("Failed to load bullet hole sprite\n"));
	if (new_parsing_sprite("images/sprites/button_off.bmp", start + 1, env))
		return (ft_printf("Failed to load midspace\n"));
	if (new_parsing_sprite("images/sprites/button_on.bmp", start + 2, env))
		return (ft_printf("Failed to load midspace\n"));
	if (new_parsing_sprite("images/sprites/MIDSPACE.bmp", start + 3, env))
		return (ft_printf("Failed to load midspace\n"));
	return (0);
}

int		check_object_sprites_textures(t_env *env)
{
	int	start;

	start = env->objects_sprites_start;
	if (new_parsing_sprite("images/sprites/sprite_sheet.bmp", start + 0, env))
		return (ft_printf("Failed to load sprite sheet\n"));
	if (new_parsing_sprite("images/sprites/projectiles_sprites.bmp", start + 1, env))
		return (ft_printf("Failed to load projectiles sprite sheet\n"));
	if (new_parsing_sprite("images/sprites/objects_sprites.bmp", start + 2, env))
		return (ft_printf("Failed to load object sprites\n"));
	if (new_parsing_sprite("images/sprites/raygun.bmp", start + 3, env))
		return (ft_printf("Failed to load raygun sprite\n"));
	return (0);
}

int		check_editor_sprites_textures(t_env *env)
{
	int	start;

	start = env->editor_start;
	if (new_parsing_sprite("images/sprites/doom_guy.bmp", start + 0, env))
		return (ft_printf("Failed to load doom guy sprite\n"));
	if (new_parsing_sprite("images/sprites/doom_guy_face.bmp", start + 1, env))
		return (ft_printf("Failed to load doom guy face sprite\n"));
	if (new_parsing_sprite("images/sprites/camera.bmp", start + 2, env))
		return (ft_printf("Failed to load camera sprite\n"));
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