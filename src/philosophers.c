/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:27:38 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 15:24:49 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

t_data	*get_data(void)
{
	static t_data	data;

	return (&data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	if (!valid_argument(argc, argv, data))
		return (1);
	init_threads();
	free_philo(data);
}
