/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:54:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/23 20:33:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "thread_pool.h"
#include "libft.h"

void	perform_work(t_tpool *tpool)
{
	t_work	*work;

	work = get_work(tpool);
	tpool->nb_working_threads++;
	pthread_mutex_unlock(&tpool->mutex);
	if (work->func(work->param))
		tpool->err = 1;
	destroy_work(work);
	pthread_mutex_lock(&tpool->mutex);
	tpool->nb_working_threads--;
	if (!tpool->works && tpool->nb_working_threads == 0 && !tpool->stop)
		pthread_cond_signal(&tpool->main_cond);
	pthread_mutex_unlock(&tpool->mutex);
}

void	*tpool_worker(void *param)
{
	t_tpool	*tpool;
	int		id;

	tpool = (t_tpool*)param;
	pthread_mutex_lock(&tpool->mutex);
	id = tpool->nb_alive_threads;
	tpool->nb_alive_threads++;
	if (id == tpool->nb_threads - 1)
		pthread_cond_signal(&tpool->main_cond);
	pthread_mutex_unlock(&tpool->mutex);
	while (1)
	{
		pthread_mutex_lock(&tpool->mutex);
		while (!tpool->works && !tpool->stop)
			pthread_cond_wait(&tpool->worker_cond, &tpool->mutex);
		if (tpool->stop)
			break ;
		perform_work(tpool);
	}
	tpool->nb_alive_threads--;
	if (!tpool->works && tpool->nb_alive_threads == 0 && tpool->stop)
		pthread_cond_signal(&tpool->main_cond);
	pthread_mutex_unlock(&tpool->mutex);
	return (0);
}

void	*tpool_work(t_tpool *tpool, int (*func)(void *), void *param)
{
	t_work	*work;

	if (!func)
		return (NULL);
	if (!(work = create_work(func, param)))
		return (NULL);
	pthread_mutex_lock(&tpool->mutex);
	if (tpool->works)
		work->next = tpool->works;
	tpool->works = work;
	pthread_cond_broadcast(&tpool->worker_cond);
	pthread_mutex_unlock(&tpool->mutex);
	return (0);
}

int		tpool_wait(t_tpool *tpool)
{
	if (!tpool)
		return (0);
	pthread_mutex_lock(&tpool->mutex);
	while ((!tpool->stop && tpool->nb_working_threads > 0)
		|| (tpool->stop && tpool->nb_alive_threads > 0)
		|| tpool->works)
		pthread_cond_wait(&tpool->main_cond, &tpool->mutex);
	pthread_mutex_unlock(&tpool->mutex);
	if (tpool->err)
		return (-1);
	return (0);
}
