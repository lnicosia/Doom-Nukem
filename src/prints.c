/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:19:13 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/26 10:04:38 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	print_vertex(t_env *env, int num)
{
	int	i;
	t_list	*tmp;
	t_vertex	*v;

	i = 0;
	tmp = env->editor.vertices;
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

	tmp = env->editor.vertices;
	while(tmp)
	{
		v = (t_vertex *)tmp->content;
		ft_printf("vertex [%d]:\nx: %f y: %f\n", v->num, v->x, v->y);
		tmp = tmp->next;
	}
}
