/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_bullet_hole.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:12:36 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 15:58:23 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_remover.h"

int		delete_ceiling_bullet_hole2(t_floor_sprite_remover *param,
t_env *env)
{
	shift_ceiling_bullet_hole_events(param->sector, param->sprite, env);
	return (1);
}

int		delete_ceiling_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_floor_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_floor_sprite_remover*)p;
	env->sectors[param->sector].ceiling_sprites.sprite = (int*)ft_delindex(
	env->sectors[param->sector].ceiling_sprites.sprite, sizeof(int)
	* env->sectors[param->sector].ceiling_sprites.nb_sprites,
	sizeof(int), sizeof(int) * param->sprite);
	env->sectors[param->sector].ceiling_sprites.scale = (t_v2*)ft_delindex(
	env->sectors[param->sector].ceiling_sprites.scale, sizeof(t_v2)
	* env->sectors[param->sector].ceiling_sprites.nb_sprites,
	sizeof(t_v2), sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].ceiling_sprites.pos = (t_v2*)ft_delindex(
	env->sectors[param->sector].ceiling_sprites.pos, sizeof(t_v2)
	* env->sectors[param->sector].ceiling_sprites.nb_sprites,
	sizeof(t_v2), sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].ceiling_sprites.nb_sprites--;
	if (env->sectors[param->sector].ceiling_sprites.nb_sprites > 0
		&& (!env->sectors[param->sector].ceiling_sprites.sprite
		|| !env->sectors[param->sector].ceiling_sprites.scale
		|| !env->sectors[param->sector].ceiling_sprites.pos))
		return (-1);
	return (delete_ceiling_bullet_hole2(param, env));
}

int		delete_floor_bullet_hole2(t_floor_sprite_remover *param,
t_env *env)
{
	shift_floor_bullet_hole_events(param->sector, param->sprite, env);
	return (1);
}

int		delete_floor_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_floor_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_floor_sprite_remover*)p;
	env->sectors[param->sector].floor_sprites.sprite = (int*)ft_delindex(
	env->sectors[param->sector].floor_sprites.sprite, sizeof(int)
	* env->sectors[param->sector].floor_sprites.nb_sprites,
	sizeof(int), sizeof(int) * param->sprite);
	env->sectors[param->sector].floor_sprites.scale = (t_v2*)ft_delindex(
	env->sectors[param->sector].floor_sprites.scale, sizeof(t_v2)
	* env->sectors[param->sector].floor_sprites.nb_sprites,
	sizeof(t_v2), sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].floor_sprites.pos = (t_v2*)ft_delindex(
	env->sectors[param->sector].floor_sprites.pos, sizeof(t_v2)
	* env->sectors[param->sector].floor_sprites.nb_sprites,
	sizeof(t_v2), sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].floor_sprites.nb_sprites--;
	if (env->sectors[param->sector].floor_sprites.nb_sprites > 0
		&& (!env->sectors[param->sector].floor_sprites.sprite
		|| !env->sectors[param->sector].floor_sprites.scale
		|| !env->sectors[param->sector].floor_sprites.pos))
		return (-1);
	return (delete_floor_bullet_hole2(param, env));
}

int		delete_wall_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_wall_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_wall_sprite_remover*)p;
	ft_lstpopfront(&env->sectors[param->sector].wall_bullet_holes[param->wall]);
	return (1);
}
