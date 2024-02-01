/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:05:22 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 15:25:03 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*philo_died(t_philo philo)
{
	t_data	*data;

	(void)philo;
	data = get_data();
	pthread_mutex_lock(data->stop);
	data->stop_all = TRUE;
	pthread_mutex_unlock(data->stop);
	pthread_mutex_lock(data->print);
	printf(DIE_MSG, format_time(), philo.id);
	pthread_mutex_unlock(data->print);
	return (NULL);
}

static void	philos_eat_enough(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = -1;
	while (++i < data->n_philo)
	{
		if (data->philos[i].num_meals < data->n_time_eat)
			return ;
	}
	pthread_mutex_lock(data->stop);
	get_data()->stop_all = TRUE;
	pthread_mutex_unlock(data->stop);
}

void	*philo_monitoring(void *null)
{
	t_data	*data;
	t_philo	*philo;
	long	limit_time;
	int		i;

	(void)null;
	data = get_data();
	philo = data->philos;
	while (!data->stop_all)
	{
		i = -1;
		while (++i < data->n_philo)
		{
			pthread_mutex_lock(data->time_meals);
			limit_time = get_time() - philo[i].last_meal;
			pthread_mutex_unlock(data->time_meals);
			if (limit_time > data->time_to_die + 1)
				return (philo_died(philo[i]));
			else if (data->n_time_eat > 0)
				philos_eat_enough();
		}
	}
	return (NULL);
}
