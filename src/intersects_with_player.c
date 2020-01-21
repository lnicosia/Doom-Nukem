/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects_with_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:01:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/21 15:42:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "collision.h"

int			player_changed_sector(t_env *env)
{
	int	prec;

	prec = env->player.sector;
	if (get_sector_no_z_origin(env, env->player.pos, prec) != prec)
		return (1);
	return (0);
}

int			intersects_with_player(t_sector *sector, int wall, t_env *env)
{
	int	prec;

	update_sector_slope(env, sector);
	if (hitbox_collision(
		new_v2(env->vertices[sector->vertices[wall]].x,
		env->vertices[sector->vertices[wall]].y),
		new_v2(env->vertices[sector->vertices[wall + 1]].x,
		env->vertices[sector->vertices[wall + 1]].y), new_v2(env->player.pos.x,
		env->player.pos.y), env->player.size_2d) && sector->portals[wall])
		return (1);
	if (wall == 0)
		prec = sector->nb_vertices - 1;
	else
		prec = wall - 1;
	if (hitbox_collision(
		new_v2(env->vertices[sector->vertices[prec]].x,
		env->vertices[sector->vertices[prec]].y),
		new_v2(env->vertices[sector->vertices[wall]].x,
		env->vertices[sector->vertices[wall]].y), new_v2(env->player.pos.x,
		env->player.pos.y), env->player.size_2d) && sector->portals[prec])
		return (1);
	if (player_changed_sector(env))
		return (1);
	return (0);
}
