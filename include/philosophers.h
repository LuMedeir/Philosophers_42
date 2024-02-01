/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:02:18 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 13:48:13 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define DIE_MSG "%ld %i died 💀\n"
# define EAT_MSG "%ld %i is eating 🍽️\n"
# define THINK_MSG "%ld %i is thinking 🤔\n"
# define SLEEP_MSG "%ld %i is sleeping 😴\n"
# define FORK_MSG "%ld %i has taken a fork 🍴\n"

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

typedef struct s_philo
{
	int						id;
	_Atomic int				num_meals;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*left_fork;
	_Atomic t_bool			is_dead;
	_Atomic long			last_meal;
}	t_philo;

typedef struct s_data
{
	t_philo				*philos;
	_Atomic t_bool		stop_all;
	pthread_mutex_t		*print;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*time_meals;
	pthread_mutex_t		*stop;
	long				start_time;
	int					n_philo;
	int					time_to_eat;
	int					time_to_sleep;
	int					time_to_die;
	int					n_time_eat;
}	t_data;

t_bool		valid_argument(int argc, char **argv, t_data *data);
t_bool		check_is_digit(char **argv);
t_data		*get_data(void);
void		init_threads(void);
long		format_time(void);
long int	get_time(void);
int			convert_to_int(const char *str);
void		*routine(void *philo);
void		free_philo(t_data *data);
void		*philo_monitoring(void *philos);
void		philo_eat(t_philo *philo);
void		philo_think(t_philo *philo);
void		philo_sleep(t_philo *philo);

#endif