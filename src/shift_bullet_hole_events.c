/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_bullet_hole_events.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 10:46:55 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 10:46:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "wall_sprite_remover.h"

void	shift_ceiling_bullet_hole_events(int sector, int sprite, t_env *env)
{
	size_t					i;
	t_floor_sprite_remover	*curr;

	i = 0;
	while (i < env->nb_ceiling_bullet_holes_events)
	{
		curr = (t_floor_sprite_remover*)env->ceiling_bullet_holes_events[i].
			exec_param;
		if (sector == curr->sector && curr->sprite > sprite)
			curr->sprite--;
		i++;
	}
}

void	shift_floor_bullet_hole_events(int sector, int sprite, t_env *env)
{
	size_t					i;
	t_floor_sprite_remover	*curr;

	i = 0;
	while (i < env->nb_floor_bullet_holes_events)
	{
		curr = (t_floor_sprite_remover*)env->floor_bullet_holes_events[i].
			exec_param;
		if (sector == curr->sector && curr->sprite > sprite)
			curr->sprite--;
		i++;
	}
}

void	shift_wall_bullet_hole_events(int sector, int wall, int sprite,
t_env *env)
{
	size_t					i;
	t_wall_sprite_remover	*curr;

	i = 0;
	while (i < env->nb_wall_bullet_holes_events)
	{
		curr = (t_wall_sprite_remover*)env->wall_bullet_holes_events[i].
			exec_param;
		if (sector == curr->sector && wall == curr->wall
			&& curr->sprite > sprite)
			curr->sprite--;
		i++;
	}
}
