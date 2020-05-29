/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool_work.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:54:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/23 20:33:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_pool.h"
#include "libft.h"

/*
**	Creates a new work and adds it to the list
*/

t_work	*create_work(int (*func)(void*), void *param)
{
	t_work	*new;

	if (!func)
		return (0);
	if (!(new = (t_work*)ft_memalloc(sizeof(t_work))))
		return (0);
	new->func = func;
	new->param = param;
	new->next = NULL;
	return (new);
}

/*
**	Free a given work
*/

void	destroy_work(t_work *work)
{
	if (!work)
		return ;
	free(work);
	work = NULL;
}

/*
**	Returns the first work from the list to execute it in an avaible thread
**	When the works list is emply, signals the main thread that every work
**	was recovered by the threads
*/

t_work	*get_work(t_tpool *tpool)
{
	t_work	*work;

	if (!tpool || !tpool->works)
		return (0);
	work = tpool->works;
	tpool->works = tpool->works->next;
	if (!tpool->works)
		pthread_cond_signal(&tpool->main_cond);
	return (work);
}
