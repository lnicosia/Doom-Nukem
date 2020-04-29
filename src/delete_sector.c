/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_sector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:44:52 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 15:59:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "update_existing_events.h"

void	modify_sector_neighbors(t_env *env, int sector)
{
	int	i;
	int	j;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (env->sectors[i].neighbors[j] >= sector)
				env->sectors[i].neighbors[j]--;
			j++;
		}
		i++;
	}
}

int		delete_linked_events(t_env *env)
{
	t_event_trigger	*trigger;

	while (env->editor.events_to_delete)
	{
		trigger = (t_event_trigger*)env->editor.events_to_delete->content;
		if (delete_selected_event1(env, *trigger))
			return (-1);
		ft_lstpopfront(&env->editor.events_to_delete);
	}
	return (0);
}

int		delete_sector2(t_env *env)
{
	int	i;

	if (delete_linked_events(env))
		return (-1);
	if (update_entities_sectors(env))
		return (-1);
	if (delete_invalid_vertices(env))
		return (-1);
	env->editor.selected_sector = -1;
	tabs_gestion(env);
	clear_portals(env);
	i = 0;
	while (i < env->nb_sectors)
	{
		create_portals(env, env->sectors[i]);
		i++;
	}
	env->player.sector = get_sector_global(env, env->player.pos);
	return (0);
}

int		delete_sector(void *param)
{
	t_env			*env;
	int				i;

	env = (t_env*)param;
	i = 0;
	ft_printf("{red}Deleting sector{reset}\n");
	free_sector(&env->sectors[env->editor.selected_sector]);
	env->sectors = (t_sector*)ft_delindex(env->sectors,
			sizeof(t_sector) * env->nb_sectors,
			sizeof(t_sector),
			sizeof(t_sector) * env->editor.selected_sector);
	env->nb_sectors--;
	if (env->nb_sectors > 0 && !env->sectors)
		return (-1);
	free(env->sector_list);
	if (!(env->sector_list = (int*)ft_memalloc(sizeof(int) * env->nb_sectors)))
		return (ft_perror("Could not allocate sector list\n"));
	i = env->editor.selected_sector;
	while (i < env->nb_sectors)
	{
		env->sectors[i].num--;
		i++;
	}
	return (delete_sector2(env));
}

int		delete_invalid_sectors(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (env->sectors[i].nb_vertices < 3
				|| !count_sector_angles(&env->sectors[i], env))
		{
			env->editor.selected_sector = i;
			if (delete_sector(env))
				return (-1);
			i--;
		}
		i++;
	}
	return (0);
}
