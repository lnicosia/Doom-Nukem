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

int		init_tpool(t_tpool *tpool, int nb_threads)
{
	int	i;
	
	ft_bzero(tpool, sizeof(*tpool));
	pthread_mutex_init(&tpool->mutex, NULL);
	pthread_cond_init(&tpool->worker_cond, NULL);
	pthread_cond_init(&tpool->main_cond, NULL);
	tpool->nb_threads = nb_threads;
	if (!(tpool->threads = (pthread_t*)ft_memalloc(nb_threads
		* sizeof(pthread_t))))
		return (custom_error("Could not init threads array\n"));
	i = 0;
	while (i < nb_threads)
	{
		if (pthread_create(&tpool->threads[i], NULL, tpool_worker, tpool))
			return (custom_error("Could not create thread %d\n", i));
		i++;
	}
	pthread_mutex_lock(&tpool->mutex);
	while (tpool->nb_alive_threads < tpool->nb_threads - 1)
		pthread_cond_wait(&tpool->main_cond, &tpool->mutex);
	pthread_mutex_unlock(&tpool->mutex);
	return (0);
}

int		free_tpool(t_tpool *tpool)
{
	t_work	*work;
	t_work	*tmp;
	int		i;

	pthread_mutex_lock(&tpool->mutex);
	work = tpool->works;
	while (work)
	{
		tmp = work->next;
		destroy_work(work);
		work = tmp;
	}
	tpool->stop = 1;
	pthread_cond_broadcast(&tpool->worker_cond);
	pthread_mutex_unlock(&tpool->mutex);
	if (!tpool->threads)
		return (0);
	i = 0;
	while (i < tpool->nb_threads)
	{
		if (pthread_join(tpool->threads[i], NULL))
			return (custom_error("Could not join thread %d\n", i));
		i++;
	}
	ft_memdel((void**)&tpool->threads);
	if (pthread_mutex_destroy(&tpool->mutex))
		return (custom_error("Could not destroy the mutex\n"));
	if (pthread_cond_destroy(&tpool->worker_cond))
		return (custom_error("Could not destroy the worker condition\n"));
	if (pthread_cond_destroy(&tpool->main_cond))
		return (custom_error("Could not destroy the main condition\n"));
	return (0);
}

void	*tpool_worker(void *param)
{
	t_tpool	*tpool;
	t_work	*work;
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
		work = get_work(tpool);
		tpool->nb_working_threads++;
		pthread_mutex_unlock(&tpool->mutex);
		if (work->func(work->param))
		{
			tpool->err = 1;
			tpool->stop = 1;
			return (NULL);
		}
		destroy_work(work);
		pthread_mutex_lock(&tpool->mutex);
		tpool->nb_working_threads--;
		if (!tpool->works && tpool->nb_working_threads == 0 && !tpool->stop)
			pthread_cond_signal(&tpool->main_cond);
		pthread_mutex_unlock(&tpool->mutex);
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

void	tpool_wait(t_tpool *tpool)
{
	if (!tpool)
		return ;
	pthread_mutex_lock(&tpool->mutex);
	while ((!tpool->stop && tpool->nb_working_threads > 0)
		|| (tpool->stop && tpool->nb_alive_threads > 0)
		|| tpool->works)
		pthread_cond_wait(&tpool->main_cond, &tpool->mutex);
	pthread_mutex_unlock(&tpool->mutex);
}
