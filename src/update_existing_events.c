/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_existing_events.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:29:41 by sipatry           #+#    #+#             */
/*   Updated: 2020/02/25 12:08:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "update_existing_events.h"
#include "events_parser.h"

int		events_to_delete_contains(t_env *env, t_event_trigger *trigger)
{
	t_event_trigger	*tmp;

	while (env->editor.events_to_delete)
	{
		tmp = (t_event_trigger*)env->editor.events_to_delete->content;
		if (tmp->type == trigger->type
			&& tmp->index == trigger->index
			&& tmp->sector == trigger->sector
			&& tmp->wall == trigger->wall
			&& tmp->enemy == trigger->enemy
			&& tmp->object == trigger->object
			&& tmp->sprite == trigger->sprite)
			return (1);
		env->editor.events_to_delete = env->editor.events_to_delete->next;
	}
	return (0);
}

int		delete_events_to_delete_list(void *param)
{
	t_env	*env;

	env = (t_env*)param;
	ft_lstdelfront(&env->editor.events_to_delete);
	return (0);
}

int		check_condition_targets(t_env *env, t_condition *condition,
t_event_target target, t_event_trigger *trigger)
{
	t_list			*new;
	t_event_target	new_target;

	init_target(&new_target);
	if (events_to_delete_contains(env, trigger))
		return (0);
	if (target.type == SECTOR_DELETED && target.sector >= 0
		&& (condition->sector == target.sector
		|| condition->target_trigger.sector == target.sector))
	{
		ft_printf("{green}Condition sector link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
		/*env->confirmation_box.yes_action = &delete_sector;
		env->confirmation_box.yes_target = env;
		env->confirmation_box.no_action = &delete_events_to_delete_list;
		env->confirmation_box.no_target = env;*/
	}
	else if (target.type == VERTEX_DELETED && target.vertex >= 0
		&& condition->vertex == target.vertex)
	{
		ft_printf("{green}Condition vertex link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
		/*env->confirmation_box.yes_target = env;
		env->confirmation_box.yes_action = &delete_vertex;
		env->confirmation_box.no_action = &delete_events_to_delete_list;
		env->confirmation_box.no_target = env;*/
	}
	else if (target.type == ENEMY_DELETED && target.enemy >= 0
		&& condition->enemy == target.enemy)
	{
		ft_printf("{green}Condition enemy link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
		/*env->confirmation_box.yes_target = env;
		env->confirmation_box.no_action = &delete_events_to_delete_list;
		env->confirmation_box.no_target = env;*/
	}
	else if (target.type == OBJECT_DELETED && target.object >= 0
		&& condition->object == target.object)
	{
		ft_printf("{green}Condition object link found{reset}\n");
		if (update_confirmation_box(&env->confirmation_box, "Deleting this"
			" sector will also delete its related events. Are you sure?",
			YESNO, env))
			return (-1);
		if (!(new = ft_lstnew(trigger, sizeof(*trigger))))
			return (ft_perror("Could not malloc new trigger node"));
		ft_lstpushback(&env->editor.events_to_delete, new);
		/*env->confirmation_box.yes_target = env;
		env->confirmation_box.no_action = &delete_events_to_delete_list;
		env->confirmation_box.no_target = env;*/
	}
	return (0);
}

int		check_event_conditions_targets(t_env *env, t_event *event,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	while (i < event->nb_launch_conditions)
	{
		if (check_condition_targets(env, &event->launch_conditions[i],
			target, trigger))
			return (-1);
		i++;
	}
	i = 0;
	while (i < event->nb_exec_conditions)
	{
		if (check_condition_targets(env, &event->exec_conditions[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_event_targets(t_env *env, t_event *event,
t_event_target target, t_event_trigger *trigger)
{
	if (event->nb_launch_conditions > 0 || event->nb_exec_conditions > 0)
	{
		if (check_event_conditions_targets(env, event, target, trigger))
			return (-1);
	}
	return (0);
}

int		check_stand_events_targets(t_env *env, t_sector *sector,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = STAND;
	trigger->sector = sector->num;
	while (i < sector->nb_stand_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &sector->stand_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_walk_in_events_targets(t_env *env, t_sector *sector,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = WALK_IN;
	trigger->sector = sector->num;
	while (i < sector->nb_walk_in_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &sector->walk_in_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_walk_out_events_targets(t_env *env, t_sector *sector,
t_event_target target, t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = WALK_OUT;
	trigger->sector = sector->num;
	while (i < sector->nb_walk_out_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &sector->walk_out_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_sectors_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;

	i = -1;
	while (++i < env->nb_sectors)
	{
		if (i == target.sector)
			continue;
		if (env->sectors[i].nb_stand_events > 0
			&& check_stand_events_targets(env, &env->sectors[i],
			target, trigger))
			return (-1);
		if (env->sectors[i].nb_walk_in_events > 0
			&& check_walk_in_events_targets(env, &env->sectors[i],
			target, trigger))
			return (-1);
		if (env->sectors[i].nb_walk_out_events > 0
			&& check_walk_out_events_targets(env, &env->sectors[i],
				target, trigger))
			return (-1);
	}
	return (0);
}

int		check_global_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	size_t	i;

	i = 0;
	trigger->type = GLOBAL;
	while (i < env->nb_global_events)
	{
		trigger->index = i;
		if (check_event_targets(env, &env->global_events[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_enemy_collision_events_targets(t_env *env, t_enemy *enemy,
t_event_target target, t_event_trigger *trigger)
{
	size_t	j;

	j = 0;
	trigger->type = ENEMY_COLLISION;
	while (j < enemy->nb_collision_events)
	{
		trigger->index = j;
		if (check_event_targets(env, &enemy->collision_events[j],
			target, trigger))
			return (-1);
		j++;
	}
	return (0);
}

int		check_enemy_death_events_targets(t_env *env, t_enemy *enemy,
t_event_target target, t_event_trigger *trigger)
{
	size_t	j;

	j = 0;
	trigger->type = DEATH;
	while (j < enemy->nb_death_events)
	{
		trigger->index = j;
		if (check_event_targets(env, &enemy->death_events[j],
			target, trigger))
			return (-1);
		j++;
	}
	return (0);
}

int		check_enemies_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;

	i = 0;
	while (i < env->nb_enemies)
	{
		trigger->enemy = i;
		if (check_enemy_collision_events_targets(env, &env->enemies[i],
			target, trigger))
			return (-1);
		if (check_enemy_death_events_targets(env, &env->enemies[i],
			target, trigger))
			return (-1);
		i++;
	}
	return (0);
}

int		check_objects_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;
	size_t	j;

	i = 0;
	trigger->type = OBJECT_COLLISION;
	while (i < env->nb_objects)
	{
		trigger->object = i;
		j = 0;
		while (j < env->objects[i].nb_collision_events)
		{
			trigger->index = j;
			if (check_event_targets(env, &env->objects[i].collision_events[j],
				target, trigger))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_wall_sprite_shoot_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger, t_wall_sprites *wall_sprites)
{
	int		i;
	size_t	j;

	i = 0;
	trigger->type = SHOOT;
	while (i < wall_sprites->nb_sprites)
	{
		j = 0;
		trigger->sprite = i;
		while (j < wall_sprites->nb_shoot_events[i])
		{
			trigger->index = j;
			if (check_event_targets(env, &wall_sprites->shoot_events[i][j],
				target, trigger))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_wall_sprite_press_events_targets(t_env *env,
t_event_target target, t_event_trigger *trigger, t_wall_sprites *wall_sprites)
{
	int		i;
	size_t	j;

	i = 0;
	trigger->type = PRESS;
	while (i < wall_sprites->nb_sprites)
	{
		j = 0;
		trigger->sprite = i;
		while (j < wall_sprites->nb_press_events[i])
		{
			trigger->index = j;
			if (check_event_targets(env, &wall_sprites->press_events[i][j],
				target, trigger))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int		check_wall_sprites_events_targets(t_env *env, t_event_target target,
t_event_trigger *trigger)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		trigger->sector = i;
		while (j < env->sectors[i].nb_vertices)
		{
			trigger->wall = j;
			if (env->sectors[i].wall_sprites[j].nb_sprites > 0)
			{
				if (check_wall_sprite_shoot_events_targets(env, target, trigger,
					&env->sectors[i].wall_sprites[j]))
					return (-1);
				if (check_wall_sprite_press_events_targets(env, target, trigger,
					&env->sectors[i].wall_sprites[j]))
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
**	Check if any existing events had the deleted sector as a target
**	Things to check:
**	Every trigger (enemies, objects, wall sprites, global, sector)
*/

int		update_sector_existing_events(t_env *env, t_event_target target)
{
	t_event_trigger		trigger;

	init_trigger(&trigger);
	//ft_printf("checking sectors events\n");
	if (check_sectors_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	//ft_printf("checking enemies events\n");
	if (check_enemies_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	//ft_printf("checking objects events\n");
	if (check_objects_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	//ft_printf("checking wall sprites events\n");
	if (check_wall_sprites_events_targets(env, target, &trigger))
		return (-1);
	init_trigger(&trigger);
	//ft_printf("checking global events\n");
	if (env->nb_global_events > 0 && check_global_events_targets(env, target,
		&trigger))
		return (-1);
	return (0);
}

/*int		update_existing_events(t_env *env, int mode)
{
	if (mode == SECTOR_DELETED)
		return (update_sector_existing_events(env));
	return (0);
}*/
