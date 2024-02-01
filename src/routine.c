/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:05:32 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 15:25:07 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	*one_philo(void)
{
	printf(FORK_MSG, (get_time() - get_time()), 1);
	usleep(get_data()->time_to_die * 1000);
	printf(DIE_MSG, (unsigned long)get_data()->time_to_die, 1);
	return (NULL);
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	if (get_data()->n_philo == 1)
		return (one_philo());
	while (!get_data()->stop_all)
	{
		philo_eat(p);
		if (get_data()->stop_all)
			break ;
		philo_sleep(p);
		if (get_data()->stop_all)
			break ;
		philo_think(p);
		if (get_data()->stop_all)
			break ;
	}
	return (NULL);
}
