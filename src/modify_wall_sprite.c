/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_wall_sprite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:56:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/04 18:49:12 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_modifier.h"

int		modify_ceiling_sprite(void *p, void *penv)
{
	t_env					*env;
	t_floor_sprite_modifier	*param;

	env = (t_env*)penv;
	param = (t_floor_sprite_modifier*)p;
	if (param->type == SPRITE)
		env->sectors[param->sector].ceiling_sprites.sprite[param->sprite]
		= param->value;
	else if (param->type == POSX)
		env->sectors[param->sector].ceiling_sprites.pos[param->sprite].x
		= param->value;
	else if (param->type == POSY)
		env->sectors[param->sector].ceiling_sprites.pos[param->sprite].y
		= param->value;
	else if (param->type == SCALEX)
		env->sectors[param->sector].ceiling_sprites.scale[param->sprite].x
		= param->value;
	else if (param->type == SCALEY)
		env->sectors[param->sector].ceiling_sprites.scale[param->sprite].y
		= param->value;
	ft_memdel(&p);
	return (0);
}

int		modify_floor_sprite(void *p, void *penv)
{
	t_env					*env;
	t_floor_sprite_modifier	*param;

	env = (t_env*)penv;
	param = (t_floor_sprite_modifier*)p;
	if (param->type == SPRITE)
		env->sectors[param->sector].floor_sprites.sprite[param->sprite]
		= param->value;
	else if (param->type == POSX)
		env->sectors[param->sector].floor_sprites.pos[param->sprite].x
		= param->value;
	else if (param->type == POSY)
		env->sectors[param->sector].floor_sprites.pos[param->sprite].y
		= param->value;
	else if (param->type == SCALEX)
		env->sectors[param->sector].floor_sprites.scale[param->sprite].x
		= param->value;
	else if (param->type == SCALEY)
		env->sectors[param->sector].floor_sprites.scale[param->sprite].y
		= param->value;
	ft_memdel(&p);
	return (0);
}

int		modify_wall_sprite(void *p, void *penv)
{
	t_env					*env;
	t_wall_sprite_modifier	*param;

	env = (t_env*)penv;
	param = (t_wall_sprite_modifier*)p;
	if (param->type == SPRITE)
		env->sectors[param->sector].wall_sprites[param->wall]
		.sprite[param->sprite] = param->value;
	else if (param->type == POSX)
		env->sectors[param->sector].wall_sprites[param->wall]
		.pos[param->sprite].x = param->value;
	else if (param->type == POSY)
		env->sectors[param->sector].wall_sprites[param->wall]
		.pos[param->sprite].y = param->value;
	else if (param->type == SCALEX)
		env->sectors[param->sector].wall_sprites[param->wall]
		.scale[param->sprite].x = param->value;
	else if (param->type == SCALEY)
		env->sectors[param->sector].wall_sprites[param->wall]
		.scale[param->sprite].y = param->value;
	return (1);
}
