/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:05:29 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 15:24:55 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_right_handed(t_philo *philo)
{
	t_data	*data;

	(void)philo;
	data = get_data();
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(data->print);
	if (!data->stop_all)
		printf(FORK_MSG, format_time(), philo->id);
	pthread_mutex_unlock(data->print);
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(data->time_meals);
	philo->last_meal = get_time();
	pthread_mutex_unlock(data->time_meals);
	pthread_mutex_lock(data->print);
	if (!data->stop_all)
	{
		printf(FORK_MSG, format_time(), philo->id);
		printf(EAT_MSG, format_time(), philo->id);
	}
	pthread_mutex_unlock(data->print);
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->num_meals++;
}

void	philo_left_handed(t_philo *philo)
{
	t_data	*data;

	(void)philo;
	data = get_data();
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(data->print);
	if (!data->stop_all)
		printf(FORK_MSG, format_time(), philo->id);
	pthread_mutex_unlock(data->print);
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(data->time_meals);
	philo->last_meal = get_time();
	pthread_mutex_unlock(data->time_meals);
	pthread_mutex_lock(data->print);
	if (!data->stop_all)
	{
		printf(FORK_MSG, format_time(), philo->id);
		printf(EAT_MSG, format_time(), philo->id);
	}
	pthread_mutex_unlock(data->print);
	usleep(data->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->num_meals++;
}

void	philo_eat(t_philo *philo)
{
	if (philo->id % 2 == 0 && !get_data()->stop_all)
		return (philo_right_handed(philo));
	else if (!get_data()->stop_all)
		return (philo_left_handed(philo));
}

void	philo_think(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(data->print);
	if (!data->stop_all)
		printf(THINK_MSG, format_time(), philo->id);
	pthread_mutex_unlock(data->print);
}

void	philo_sleep(t_philo *philo)
{
	t_data	*data;

	data = get_data();
	pthread_mutex_lock(data->print);
	if (!data->stop_all)
		printf(SLEEP_MSG, format_time(), philo->id);
	pthread_mutex_unlock(data->print);
	usleep(data->time_to_sleep * 1000);
}
