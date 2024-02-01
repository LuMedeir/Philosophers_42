/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumedeir < lumedeir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 11:03:32 by lumedeir          #+#    #+#             */
/*   Updated: 2024/01/30 15:25:13 by lumedeir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static t_bool	is_digit(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (FALSE);
	return (TRUE);
}

int	convert_to_int(const char *str)
{
	int	count;
	int	number;
	int	sign;

	number = 0;
	count = 0;
	sign = 1;
	while (str[count] == ' ' || ('\t' <= str[count] && str[count] <= '\r'))
		count++;
	if (str[count] == '-' || str[count] == '+')
	{
		if (str[count] == '-')
			sign = -1;
		count++;
	}
	while (str[count] >= '0' && str[count] <= '9')
	{
		number = (number * 10) + (str[count] - '0');
		count++;
	}
	return (number * sign);
}

t_bool	check_is_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!is_digit(argv[i][j]))
				return (FALSE);
			j++;
		}
	}
	return (TRUE);
}
