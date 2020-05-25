/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ceiling_hitscan_bullet_hole.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:53:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/28 16:11:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "wall_sprite_remover.h"

static void		init_param(t_sector *sector, t_floor_sprite_remover *param,
t_env *env)
{
	param->sector = sector->num;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events] =
		new_func_event(&delete_ceiling_bullet_hole, param);
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].
		max_uses = 1;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].
		delay = 5000;
	env->ceiling_bullet_holes_events[env->nb_ceiling_bullet_holes_events].
		target_index = -1;
	env->nb_ceiling_bullet_holes_events++;
}

t_bullet_hole	init_ceiling_hitscan_bullet_hole(t_env *env)
{
	t_bullet_hole	bullet_hole;

	bullet_hole.pos = env->new_bullet_hole_pos;
	bullet_hole.map_scale =
		new_v2(env->weapons[env->player.curr_weapon].hole_scale,
		env->weapons[env->player.curr_weapon].hole_scale);
	bullet_hole.pos.x -= bullet_hole.map_scale.x / 2;
	bullet_hole.pos.y -= bullet_hole.map_scale.y / 2;
	bullet_hole.scale.x = env->object_sprites[BULLET_HOLE].size[0].x /
	bullet_hole.map_scale.x;
	bullet_hole.scale.y = env->object_sprites[BULLET_HOLE].size[0].y /
	bullet_hole.map_scale.y;
	return (bullet_hole);
}

int				add_ceiling_hitscan_bullet_hole(t_sector *sector, t_env *env)
{
	t_list					*new;
	t_floor_sprite_remover	*param;
	t_bullet_hole			bullet_hole;

	bullet_hole = init_ceiling_hitscan_bullet_hole(env);
	if (!(new = ft_lstnew(&bullet_hole, sizeof(t_bullet_hole))))
		return (ft_perror("Could not malloc new bullet hole"));
	ft_lstpushback(&sector->ceiling_bullet_holes, new);
	if (!(env->ceiling_bullet_holes_events =
		(t_event*)ft_realloc(env->ceiling_bullet_holes_events,
		sizeof(t_event) * env->nb_ceiling_bullet_holes_events,
		sizeof(t_event) * (env->nb_ceiling_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc ceiling bullet_holes events"
		"to make bullet hole fade"));
	if (!(param = (t_floor_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc ceiling sprite remover"));
	init_param(sector, param, env);
	return (0);
}
