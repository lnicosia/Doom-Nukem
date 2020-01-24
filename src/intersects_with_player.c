/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersects_with_player.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:01:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/24 16:04:28 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events_parser.h"
#include "collision.h"

int			pos_changed_sector(t_env *env, t_sector *sector, t_point data,
		t_v3 pos)
{
	int	prec;
	int	new;

	prec = get_sector_no_z(env, pos);
	//ft_printf("prec pos sector = %d\n", prec);
	if (((new = get_sector_no_z_origin(env, pos, prec)) == -1)
			|| (new != prec
				&& new != sector->neighbors[data.y] && new != sector->neighbors[data.x]
				&& new != sector->num))
		return (1);
	return (0);
}

int			player_changed_sector(t_env *env, t_sector *sector, t_point data,
		t_v3 pos)
{
	int	prec;
	int	new;

	prec = env->player.sector;
	if (((new = get_sector_no_z_origin(env, pos, prec)) == -1)
			|| (new != prec
				&& new != sector->neighbors[data.y] && new != sector->neighbors[data.x]
				&& new != sector->num))
		return (1);
	return (0);
}

int			intersects_with_wall(t_sector *sector, t_v3 pos, int wall,
		t_env *env)
{
	int		prec;
	t_point	data;

	update_sector_slope(env, sector);
	if (hitbox_collision(
				new_v2(env->vertices[sector->vertices[wall]].x,
					env->vertices[sector->vertices[wall]].y),
				new_v2(env->vertices[sector->vertices[wall + 1]].x,
					env->vertices[sector->vertices[wall + 1]].y), new_v2(pos.x,
						pos.y), env->player.size_2d) && (!sector->portals[wall]
						|| sector->neighbors[wall] == -1))
		return (1);
	if (wall == 0)
		prec = sector->nb_vertices - 1;
	else
		prec = wall - 1;
	if (hitbox_collision(
				new_v2(env->vertices[sector->vertices[prec]].x,
					env->vertices[sector->vertices[prec]].y),
				new_v2(env->vertices[sector->vertices[wall]].x,
					env->vertices[sector->vertices[wall]].y), new_v2(pos.x,
						pos.y), env->player.size_2d) && (!sector->portals[prec]
						|| sector->neighbors[prec] == -1))
		return (1);
	data = new_point(wall, prec);
	if (player_changed_sector(env, sector, data, pos))
		return (1);
	return (0);
}

int			intersects_with_wall_no_portal_check(t_sector *sector, t_v3 pos,
int wall, t_env *env)
{
	int		prec;
	t_point	data;

	update_sector_slope(env, sector);
	if (hitbox_collision(
				new_v2(env->vertices[sector->vertices[wall]].x,
					env->vertices[sector->vertices[wall]].y),
				new_v2(env->vertices[sector->vertices[wall + 1]].x,
					env->vertices[sector->vertices[wall + 1]].y), new_v2(pos.x,
						pos.y), env->player.size_2d))
		return (1);
	if (wall == 0)
		prec = sector->nb_vertices - 1;
	else
		prec = wall - 1;
	if (hitbox_collision(
				new_v2(env->vertices[sector->vertices[prec]].x,
					env->vertices[sector->vertices[prec]].y),
				new_v2(env->vertices[sector->vertices[wall]].x,
					env->vertices[sector->vertices[wall]].y), new_v2(pos.x,
						pos.y), env->player.size_2d))
		return (1);
	data = new_point(wall, prec);
	if (player_changed_sector(env, sector, data, pos))
		return (1);
	return (0);
}

int			intersects_with_sector(t_sector *sector, t_v3 pos, t_env *env)
{
	int		prec;
	int		i;
	t_point	data;

	update_sector_slope(env, sector);
	i = 0;
	while (i <= sector->nb_vertices)
	{
		if (hitbox_collision(
					new_v2(env->vertices[sector->vertices[i]].x,
						env->vertices[sector->vertices[i]].y),
					new_v2(env->vertices[sector->vertices[i + 1]].x,
						env->vertices[sector->vertices[i + 1]].y), new_v2(pos.x,
							pos.y), env->player.size_2d) && (!sector->portals[i]
							|| sector->neighbors[i] == -1))
			return (1);
		if (i == 0)
			prec = sector->nb_vertices - 1;
		else
			prec = i - 1;
		if (hitbox_collision(
					new_v2(env->vertices[sector->vertices[prec]].x,
						env->vertices[sector->vertices[prec]].y),
					new_v2(env->vertices[sector->vertices[i]].x,
						env->vertices[sector->vertices[i]].y), new_v2(pos.x,
							pos.y), env->player.size_2d) && (!sector->portals[prec]
							|| sector->neighbors[prec] == -1))
			return (1);
		data = new_point(i, prec);
		if (pos_changed_sector(env, sector, data, pos))
			return (1);
		i++;
	}
	return (0);
}
