/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:57:30 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/26 11:39:36 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_sector	default_sector(t_env *env)
{
	t_sector	sector;

	sector.num = env->editor.sectors_count;
	sector.floor = 0;
	sector.floor_slope = 0;
	sector.floor_texture = 4;
	sector.ceiling = 12;
	sector.ceiling_slope = 0;
	sector.ceiling_texture = 4;
	sector.closed = 0;
	return (sector);
}

int		add_vertex_to_current_sector(t_env *env, int num)
{
	t_list		*tmp;
	t_list		*new;
	t_vertex	*vertex;
	int			i;

	i= 0;
	tmp = env->editor.vertices;
	while (i < num && tmp)
	{
		tmp = tmp->next;
		i++;
	}
	if (!tmp)
		return (ft_printf("Vertex %d not found\n", num));
	vertex = (t_vertex*)tmp->content;
	if (!(new = ft_lstnew(vertex, sizeof(t_vertex))))
		return (ft_printf("Error when creating new vertex\n"));
	ft_lstpushback(&env->editor.current_vertices, new);
	return (0);
}

int		add_vertex(t_env *env)
{
	t_list		*new;
	t_vertex	vertex;

	vertex.num = env->editor.vertices_count;
	vertex.x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	vertex.y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	if (!(new = ft_lstnew(&vertex, sizeof(t_vertex))))
		return (ft_printf("Error when creating new vertex\n"));
	ft_lstpushback(&env->editor.vertices, new);
	env->editor.vertices_count++;
	return (0);
}

int		add_sector(t_env *env)
{
	t_list		*new;
	t_sector	sector;

	sector = default_sector(env);
	env->editor.sectors_count++;
	(void)new;
	return (0);
}
