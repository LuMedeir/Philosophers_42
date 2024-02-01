/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:44:49 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/31 12:04:37 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static void	init_philos(void)
{
	int		i;
	t_data	*data;

	i = -1;
	data = get_data();
	while (++i < data->n_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].right_fork = &data->forks[i];
		data->philos[i].left_fork = &data->forks[(i + 1) % data->n_philo];
		data->philos[i].is_dead = FALSE;
		data->philos[i].num_meals = 0;
	}
}

static void	init_forks(void)
{
	t_data	*data;
	int		i;

	data = get_data();
	i = -1;
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	if (!data->forks)
		return ;
	while (++i < data->n_philo)
		pthread_mutex_init(&data->forks[i], NULL);
}

static void	init_struct(int argc, char **argv)
{
	t_data	*data;

	data = get_data();
	data->philos = (t_philo *)malloc((atoi(argv[1]) + 1) * sizeof(t_philo));
	if (!data->philos)
		return ;
	data->n_philo = atoi(argv[1]);
	data->time_to_die = atoi(argv[2]);
	data->time_to_eat = atoi(argv[3]);
	data->time_to_sleep = atoi(argv[4]);
	data->stop_all = FALSE;
	data->n_time_eat = -1;
	if (argc == 6)
		data->n_time_eat = atoi(argv[5]);
	data->start_time = get_time();
	data->print = malloc(sizeof(pthread_mutex_t));
	data->stop = malloc(sizeof(pthread_mutex_t));
	data->time_meals = malloc(sizeof(pthread_mutex_t));
	init_forks();
	init_philos();
	pthread_mutex_init(data->print, NULL);
	pthread_mutex_init(data->stop, NULL);
	pthread_mutex_init(data->time_meals, NULL);
}

t_bool	valid_argument(int argc, char **argv, t_data *data)
{
	int	index;

	(void)data;
	index = 1;
	if (argc > 6 || argc < 5 || convert_to_int(argv[1]) < 1
		|| !check_is_digit(argv))
		return (printf("Invalid arguments\n"), FALSE);
	while (argv[++index])
		if (convert_to_int(argv[index]) < 0)
			return (printf("Invalid arguments\n"), FALSE);
	init_struct(argc, argv);
	return (TRUE);
}

void	init_threads(void)
{
	pthread_t	*thread;
	pthread_t	*monitoring;
	t_data		*data;
	int			i;

	data = get_data();
	thread = malloc(data->n_philo * sizeof(thread));
	monitoring = malloc(1 * sizeof(monitoring));
	if (!thread)
		return ;
	i = -1;
	while (++i < data->n_philo)
	{
		data->philos[i].last_meal = get_time();
		pthread_create(&thread[i], NULL, &routine, (void *)&data->philos[i]);
	}
	if (get_data()->n_philo > 1)
		pthread_create(monitoring, NULL, &philo_monitoring, NULL);
	i = -1;
	while (++i < data->n_philo)
		pthread_join(thread[i], NULL);
	if (get_data()->n_philo > 1)
		pthread_join(*monitoring, NULL);
	free(thread);
	free(monitoring);
}
