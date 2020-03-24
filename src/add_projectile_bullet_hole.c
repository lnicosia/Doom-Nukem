/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_projectile_bullet_hole.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:53:44 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/06 11:21:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_remover.h"

static void	init_param(t_sector *sector, int i,
t_wall_sprite_remover *param, t_env *env)
{
	param->sector = sector->num;
	param->wall = i;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events]
		= new_func_event(&delete_wall_bullet_hole, param);
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].max_uses
		= 1;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].delay
		= 5000;
	env->wall_bullet_holes_events[env->nb_wall_bullet_holes_events].
		target_index = -1;
	env->nb_wall_bullet_holes_events++;
}

int			add_wall_projectile_bullet_hole(t_sector *sector,
t_projectile *projectile, int i, t_env *env)
{
	t_list					*new;
	t_wall_sprite_remover	*param;
	t_bullet_hole			bullet_hole;

	bullet_hole.pos =
		get_wall_bullet_hole_pos(sector, projectile, i, env);
	bullet_hole.pos.x -= 0.2;
	bullet_hole.pos.y -= 0.2;
	bullet_hole.map_scale = new_v2(projectile->scale, projectile->scale);
	if (!(new = ft_lstnew(&bullet_hole, sizeof(t_bullet_hole))))
		return (ft_perror("Could not malloc new bullet hole"));
	ft_lstpushback(&sector->wall_bullet_holes[i], new);
	if (!(env->wall_bullet_holes_events
				= (t_event*)ft_realloc(env->wall_bullet_holes_events,
					sizeof(t_event) * env->nb_wall_bullet_holes_events,
					sizeof(t_event) * (env->nb_wall_bullet_holes_events + 1))))
		return (ft_perror("Could not realloc bullet_holes events"
					"to make bullet hole fade"));
	if (!(param = (t_wall_sprite_remover*)ft_memalloc(sizeof(*param))))
		return (ft_perror("Could not malloc wall sprite remover"));
	init_param(sector, i, param, env);
	if (projectile_on_wall_sprite(bullet_hole.pos, sector, i, env))
		return (-1);
	return (0);
}
