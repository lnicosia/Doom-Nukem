/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:00:29 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/21 11:19:28 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	modify_sectors(t_env *env, int	*sectors)
{
	int			i;
	int			j;
	t_sector	tmp;

	i = 0;
	j = 0;
	while (sectors[i])
	{
		if (env->sectors[sectors[i]].nb_vertices - 1 > 3)
			delete_sector(env);
		else
		{
			tmp = env->sectors[sectors[i]];
			env->sectors[sectors[i]].vertices = ft_delindex(env->sectors[sectors[i]].vertices,
					env->sectors[sectors[i]].nb_vertices * sizeof(t_vertex),
					sizeof(t_vertex),
					env->editor.select_vertex * sizeof(t_vertex));
			env->sectors[sectors[i]].nb_vertices--;
		}
		i++;
	}
}

void	calc_sectors(t_env *env)
{
	int	i;
	int	j;
	int	k;
	int	*sectors;
	int	count;

	i = 0;
	count = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		k = 0;
		while (j < env->sectors[i].nb_vertices)
		{	
			if (env->sectors[i].vertices[j] == env->editor.select_vertex)
			{
				if(!(sectors = (int*)ft_realloc(sectors, sizeof(int) * count, sizeof(int) * (count + 1))))
					return ;
				sectors[k] = i;
				count++;
				k++;
			}
			j++;
		}
	}
	i = 0;
	while (sectors[i])
	{
		ft_printf("sector: %d\n", sectors[i]);
		i++;
	}
	modify_sectors(env, sectors);
}

int	delete_vertex(t_env *env)
{
	t_vertex	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	(void)env;
	if (!(tmp = (t_vertex*)malloc(sizeof(t_vertex) * env->nb_vertices)))
		return (ft_printf("Deleting: failed copying vertices\n"));
	if (env->editor.drag_vertex && !env->inputs.left_click
			&& env->sdl.mx <= 200 && env->flag)
	{
		env->flag = 0;
		tmp = env->vertices;
		env->vertices = ft_delindex(env->vertices,
									sizeof(t_vertex) * env->nb_vertices,
									sizeof(t_vertex),
									env->editor.select_vertex * sizeof(t_vertex));
		env->nb_vertices--;
		env->editor.select_vertex = -1;
		calc_sectors(env);
	}
	i = 0;
	return (0);
}

int	delete_object(t_env *env)
{
	t_object	*tmp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	if (!(tmp = (t_object*)malloc(sizeof(t_object) * env->nb_objects)))
		return (ft_printf("Deleting: failed copying objects\n"));
	if (!env->editor.drag_object && !env->inputs.left_click
			&& env->sdl.mx <= 200 && env->flag)
	{
		env->flag = 0;
		tmp = env->objects;
		env->objects = ft_delindex(env->objects,
									env->nb_objects * sizeof(t_object),
									sizeof(t_object),
									env->editor.select_object * sizeof(t_object));
		env->nb_objects--;
		if (!env->nb_objects && env->editor.objects == 1)
			env->editor.objects = 0;
		env->editor.select_object = -1;
	}
	return (0);
}
