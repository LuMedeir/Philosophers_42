/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 13:45:07 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 15:24:57 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	free_philo(t_data *data)
{
	free(data->philos);
	free(data->print);
	free(data->time_meals);
	free(data->forks);
	free(data->stop);
}
