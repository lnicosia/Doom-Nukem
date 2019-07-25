/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:19:13 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 12:22:47 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_vertex(t_env *env, int num)
{
	int	i;
	t_list	*tmp;
	t_vertex	*v;

	i = 0;
	tmp = env->edit.vertices;
	while(i <= num)
	{
		v = (t_vertex*)tmp->content;
		tmp = tmp->next;
		i++;
	}
	ft_printf("vertex [%d]:\nx: %f y: %f\n\n", v->num, v->x, v->y);
}

void	print_vertices(t_env *env)
{
	t_list *tmp;
	t_vertex *v;
	t_list	*tmp2;

	tmp = env->edit.vertices;
	tmp2 = env->edit.vertices;
	while(env->edit.vertices != NULL)
	{
		v = (t_vertex *)tmp->content;
		ft_printf("vertex [%d]:\nx: %f y: %f\n", v->num, v->x, v->y);
		tmp = tmp->next;
	}
}
