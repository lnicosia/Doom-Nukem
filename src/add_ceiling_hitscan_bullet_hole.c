/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ceiling_hitscan_bullet_hole.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/28 15:15:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 15:21:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "wall_sprite_remover.h"

int		add_ceiling_hitscan_bullet_hole4(t_sector *sector, t_env *env)
{
	t_floor_sprite_remover	*param;

	if (!(env->ceiling_bullet_holes_events =
		(t_event*)ft_realloc(env->ceiling_bullet_holes_events,
		sizeof(t_event) * env->nb_ceiling_bullet_holes_events,
		sizeof(t_event) * (env->nb_ceiling_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
		"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	param->sector = sector->num;
	param->sprite = sector->ceiling_sprites.nb_sprites - 1;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events] =
		new_func_event(&delete_ceiling_bullet_hole, param);
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].
		max_uses = 1;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].
		delay = 5000;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].
		target_index = -1;
	env->nb_ceiling_bullet_holes_events++;
	return (0);
}

int		add_ceiling_hitscan_bullet_hole3(t_sector *sector, t_env *env)
{
	sector->ceiling_sprites.sprite[sector->ceiling_sprites.nb_sprites] =
	BULLET_HOLE;
	sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites] =
		new_v2(env->weapons[env->player.curr_weapon].hole_scale,
		env->weapons[env->player.curr_weapon].hole_scale);
	sector->ceiling_sprites.pos[sector->ceiling_sprites.nb_sprites] =
		env->new_bullet_hole_pos;
	sector->ceiling_sprites.pos[sector->ceiling_sprites.nb_sprites].x -=
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].x / 2;
	sector->ceiling_sprites.pos[sector->ceiling_sprites.nb_sprites].y -=
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].y / 2;
	sector->ceiling_sprites_scale[sector->ceiling_sprites.nb_sprites].x =
		env->object_sprites[sector->ceiling_sprites.
		sprite[sector->ceiling_sprites.nb_sprites]].size[0].x /
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].x;
	sector->ceiling_sprites_scale[sector->ceiling_sprites.nb_sprites].y =
		env->object_sprites[sector->ceiling_sprites.
		sprite[sector->ceiling_sprites.nb_sprites]].size[0].y /
		sector->ceiling_sprites.scale[sector->ceiling_sprites.nb_sprites].y;
	sector->ceiling_sprites.nb_sprites++;
	return (add_ceiling_hitscan_bullet_hole4(sector, env));
}

int		add_ceiling_hitscan_bullet_hole2(t_sector *sector, t_env *env)
{
	if (!(sector->ceiling_sprites.nb_press_events =
		(size_t*)ft_realloc(sector->ceiling_sprites.nb_press_events,
		sizeof(size_t) * sector->ceiling_sprites.nb_sprites,
		sizeof(size_t) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites nb press events"));
	if (!(sector->ceiling_sprites.nb_shoot_events =
		(size_t*)ft_realloc(sector->ceiling_sprites.nb_shoot_events,
		sizeof(size_t) * sector->ceiling_sprites.nb_sprites,
		sizeof(size_t) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites nb shoot events"));
	if (!(sector->ceiling_sprites.shoot_events =
		(t_event**)ft_realloc(sector->ceiling_sprites.shoot_events,
		sizeof(t_event*) * sector->ceiling_sprites.nb_sprites,
		sizeof(t_event*) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites shoot events"));
	if (!(sector->ceiling_sprites.press_events =
		(t_event**)ft_realloc(sector->ceiling_sprites.press_events,
		sizeof(t_event*) * sector->ceiling_sprites.nb_sprites,
		sizeof(t_event*) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites press events"));
	return (add_ceiling_hitscan_bullet_hole3(sector, env));
}

int		add_ceiling_hitscan_bullet_hole(t_sector *sector, t_env *env)
{
	if (!(sector->ceiling_sprites.sprite =
		(int*)ft_realloc(sector->ceiling_sprites.sprite,
		sizeof(int) * sector->ceiling_sprites.nb_sprites,
		sizeof(int) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites indexes"));
	if (!(sector->ceiling_sprites.pos =
		(t_v2*)ft_realloc(sector->ceiling_sprites.pos,
		sizeof(t_v2) * sector->ceiling_sprites.nb_sprites,
		sizeof(t_v2) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("Could not realloc ceiling sprites pos"));
	if (!(sector->ceiling_sprites.scale =
		(t_v2*)ft_realloc(sector->ceiling_sprites.scale,
		sizeof(t_v2) * sector->ceiling_sprites.nb_sprites,
		sizeof(t_v2) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("could not realloc ceiling sprites scale"));
	if (!(sector->ceiling_sprites_scale =
		(t_v2*)ft_realloc(sector->ceiling_sprites_scale,
		sizeof(t_v2) * sector->ceiling_sprites.nb_sprites,
		sizeof(t_v2) * (sector->ceiling_sprites.nb_sprites + 1))))
		return (ft_perror("could not realloc ceiling sprites scale"));
	return (add_ceiling_hitscan_bullet_hole2(sector, env));
}
