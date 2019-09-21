/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_clockwise_order.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:35:45 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/15 14:12:19 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"


int		get_clockwise_order_sector(t_env *env, int index)	
{
	int			res;
	int			i;
	int			num;
	t_vertex	vertex1;
	t_vertex	vertex2;
	
	res = 0;
	i = 0;
	vertex2 = env->vertices[0];
	while (i < env->sectors[index].nb_vertices - 1)
	{
		num = env->sectors[index].vertices[i];
		vertex1 = env->vertices[num];
		num = env->sectors[index].vertices[i + 1];
		vertex2 = env->vertices[num];
		res += (vertex2.x - vertex1.x) * (vertex2.y + vertex1.y);
		i++;
	}
	vertex1 = vertex2;;
	num = env->sectors[index].vertices[0];
	vertex2 = env->vertices[num];
	res += (vertex2.x - vertex1.x) * (vertex2.y + vertex1.y);
	return (res > 0 ? 0 : 1);
}

int		get_clockwise_order(t_env *env)
{
	int			res;
	int			i;
	t_list		*tmp;
	t_vertex	*vertex1;
	t_vertex	*vertex2;
	
	tmp = env->editor.current_vertices;
	res = 0;
	i = 0;
	while (tmp && tmp->next)
	{
		vertex1 = (t_vertex*)tmp->content;
		vertex2 = (t_vertex*)tmp->next->content;
		res += (vertex2->x - vertex1->x) * (vertex2->y + vertex1->y);
		/*ft_printf("[%d]: (%.f - %.f)(%.f + %.f) = %d\n",
				i, vertex2->x, vertex1->x,
				vertex2->y, vertex1->y,
				(int)((vertex2->x - vertex1->x) * (vertex2->y + vertex1->y)));*/
		i++;
		tmp = tmp->next;
	}
	vertex1 = (t_vertex*)tmp->content;
	vertex2 = (t_vertex*)env->editor.current_vertices->content;
	res += (vertex2->x - vertex1->x) * (vertex2->y + vertex1->y);
	/*ft_printf("[%d]: (%.f - %.f)(%.f + %.f) = %d\n",
			i, vertex2->x, vertex1->x,
			vertex2->y, vertex1->y,
			(int)((vertex2->x - vertex1->x) * (vertex2->y + vertex1->y)));
	ft_printf("res = %d\n", res);*/
	return (res > 0 ? 0 : 1);
}
