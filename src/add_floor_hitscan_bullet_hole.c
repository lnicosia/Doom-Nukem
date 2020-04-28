/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_floor_hitscan_bullet_hole.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:35:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:10:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_remover.h"

int		add_floor_hitscan_bullet_hole3(t_sector *sector, t_env *env)
{
	t_floor_sprite_remover	*param;

	if (!(env->floor_bullet_holes_events =
		(t_event*)ft_realloc(env->floor_bullet_holes_events,
		sizeof(t_event) * env->nb_floor_bullet_holes_events,
		sizeof(t_event) * (env->nb_floor_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
		"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->sprite = sector->floor_sprites.nb_sprites - 1;
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events] =
		new_func_event(&delete_floor_bullet_hole, param);
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events].
		max_uses = 1;
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events].
		delay = 5000;
	env->floor_bullet_holes_events[env->nb_floor_bullet_holes_events].
		target_index = -1;
	env->nb_floor_bullet_holes_events++;
	return (0);
}

int		add_floor_hitscan_bullet_hole2(t_sector *sector, t_env *env)
{
	sector->floor_sprites.sprite[sector->floor_sprites.nb_sprites] =
	BULLET_HOLE;
	sector->floor_sprites.scale[sector->floor_sprites.nb_sprites] =
		new_v2(env->weapons[env->player.curr_weapon].hole_scale,
		env->weapons[env->player.curr_weapon].hole_scale);
	sector->floor_sprites.pos[sector->floor_sprites.nb_sprites] =
		env->new_bullet_hole_pos;
	sector->floor_sprites.pos[sector->floor_sprites.nb_sprites].x -=
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].x / 2;
	sector->floor_sprites.pos[sector->floor_sprites.nb_sprites].y -=
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].y / 2;
	sector->floor_sprites_scale[sector->floor_sprites.nb_sprites].x =
		env->object_sprites[sector->floor_sprites.
		sprite[sector->floor_sprites.nb_sprites]].size[0].x /
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].x;
	sector->floor_sprites_scale[sector->floor_sprites.nb_sprites].y =
		env->object_sprites[sector->floor_sprites.
		sprite[sector->floor_sprites.nb_sprites]].size[0].y /
		sector->floor_sprites.scale[sector->floor_sprites.nb_sprites].y;
	sector->floor_sprites.nb_sprites++;
	return (add_floor_hitscan_bullet_hole3(sector, env));
}

int		add_floor_hitscan_bullet_hole(t_sector *sector, t_env *env)
{
	if (!(sector->floor_sprites.sprite =
		(int*)ft_realloc(sector->floor_sprites.sprite,
		sizeof(int) * sector->floor_sprites.nb_sprites,
		sizeof(int) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites indexes"));
	if (!(sector->floor_sprites.pos =
		(t_v2*)ft_realloc(sector->floor_sprites.pos,
		sizeof(t_v2) * sector->floor_sprites.nb_sprites,
		sizeof(t_v2) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites pos"));
	if (!(sector->floor_sprites.scale =
		(t_v2*)ft_realloc(sector->floor_sprites.scale,
		sizeof(t_v2) * sector->floor_sprites.nb_sprites,
		sizeof(t_v2) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc floor sprites scale"));
	if (!(sector->floor_sprites_scale =
		(t_v2*)ft_realloc(sector->floor_sprites_scale,
		sizeof(t_v2) * sector->floor_sprites.nb_sprites,
		sizeof(t_v2) * (sector->floor_sprites.nb_sprites + 1))))
		return (ft_perror("could not realloc floor sprites scale"));
	return (add_floor_hitscan_bullet_hole2(sector, env));
}
