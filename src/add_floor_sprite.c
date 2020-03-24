/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_floor_sprite.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:47:37 by sipatry           #+#    #+#             */
/*   Updated: 2020/03/06 10:57:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	update_floor_sprite_arrays3(t_env *env, t_sector *sector,
t_wall_sprites *floor)
{
	if (!(sector->floor_sprites_scale =
	 	(t_v2*)ft_realloc(sector->floor_sprites_scale,
		sizeof(t_v2) * floor->nb_sprites, sizeof(t_v2)
		* (floor->nb_sprites + 1))))
		return (-1);
	precompute_floor_sprite_scales(env->selected_floor,
		floor->nb_sprites, env);
	floor->nb_sprites++;
	return (0);
}

int	update_floor_sprite_arrays2(t_env *env, t_sector *sector,
t_wall_sprites *floor)
{
	floor->pos[floor->nb_sprites].x /= sector->nb_vertices;
	floor->pos[floor->nb_sprites].y /= sector->nb_vertices;
	if (!(floor->scale = (t_v2*)ft_realloc(floor->scale,
		sizeof(t_v2) * floor->nb_sprites, sizeof(t_v2)
		* (floor->nb_sprites + 1))))
		return (-1);
	floor->scale[floor->nb_sprites] = new_v2(2, 2);
	if (!(floor->nb_press_events = (size_t*)ft_realloc(floor->nb_press_events,
		sizeof(size_t) * floor->nb_sprites, sizeof(size_t)
		* (floor->nb_sprites + 1))))
		return (-1);
	if (!(floor->press_events = (t_event**)ft_realloc(floor->press_events,
		sizeof(t_event *) * floor->nb_sprites, sizeof(t_event*)
		* (floor->nb_sprites + 1))))
		return (-1);
	if (!(floor->nb_shoot_events = (size_t*)ft_realloc(floor->nb_shoot_events,
		sizeof(size_t) * floor->nb_sprites, sizeof(size_t)
		* (floor->nb_sprites + 1))))
		return (-1);
	if (!(floor->shoot_events = (t_event**)ft_realloc(floor->shoot_events,
		sizeof(t_event *) * floor->nb_sprites, sizeof(t_event*)
		* (floor->nb_sprites + 1))))
		return (-1);
	return (update_floor_sprite_arrays3(env, sector, floor));
}

int	update_floor_sprite_arrays(t_env *env)
{
	t_wall_sprites	*floor;
	t_sector		*sector;
	int				i;

	i = 0;
	sector = &env->sectors[env->selected_floor];
	floor = &env->sectors[env->selected_floor].floor_sprites;
	if (!(floor->sprite = (int*)ft_realloc(floor->sprite,
	sizeof(int) * floor->nb_sprites, sizeof(int)
	* (floor->nb_sprites + 1))))
		return (-1);
	floor->sprite[floor->nb_sprites] = env->editor.current_sprite;
	if (!(floor->pos = (t_v2*)ft_realloc(floor->pos,
	sizeof(t_v2) * floor->nb_sprites, sizeof(t_v2)
	* (floor->nb_sprites + 1))))
		return (-1);
	floor->pos[floor->nb_sprites] = new_v2(0, 0);
	while (i< sector->nb_vertices)
	{
		floor->pos[floor->nb_sprites].x +=
		(env->vertices[sector->vertices[i]].x);
		floor->pos[floor->nb_sprites].y +=
		(env->vertices[sector->vertices[i]].y);
		i++;
	}
	return (update_floor_sprite_arrays2(env, sector, floor));
}
