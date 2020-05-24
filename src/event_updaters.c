/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_updaters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:05:50 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/25 14:28:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"

int			update_object_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->objects[event->update_param.object].sprite =
	env->objects_main_sprites[env->objects[event->update_param.object].sprite];
	return (0);
}

int			update_enemy_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->enemies[event->update_param.enemy].sprite =
	env->enemies_main_sprites[env->objects[event->update_param.enemy].sprite];
	return (0);
}

int			update_wall_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[event->update_param.sector].wall_sprites[event->
	update_param.wall].sprite[event->update_param.sprite] =
	env->objects_main_sprites[env->sectors[event->update_param.sector]
	.wall_sprites[event->update_param.wall].sprite[event->update_param.sprite]];
	return (0);
}

int			update_floor_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[event->update_param.sector].floor_sprites.sprite[event->
	update_param.sprite] =
	env->objects_main_sprites[env->sectors[event->update_param.sector]
	.floor_sprites.sprite[event->update_param.sprite]];
	precompute_floor_sprite_scales(event->update_param.sector,
	event->update_param.sprite, env);
	return (0);
}

int			update_ceiling_sprite_event(t_event *event, void *penv)
{
	t_env	*env;

	env = (t_env *)penv;
	env->sectors[event->update_param.sector].ceiling_sprites.sprite[event->
	update_param.sprite] =
	env->objects_main_sprites[env->sectors[event->update_param.sector]
	.ceiling_sprites.sprite[event->update_param.sprite]];
	precompute_ceiling_sprite_scales(event->update_param.sector,
	event->update_param.sprite, env);
	return (0);
}
