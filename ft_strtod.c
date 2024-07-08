/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: worcrow <worcrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:41:18 by worcrow           #+#    #+#             */
/*   Updated: 2024/07/08 09:21:08 by worcrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

void	initialize_var(int *add, double *result, double *pow, int *sign)
{
	*add = 10;
	*result = 0.0;
	*pow = 1.0;
	*sign = 1;
}

double	ft_strtod(char *str, int *errno)
{
	double	result;
	int		sign;
	double	pow;
	int		add;

	initialize_var(&add, &result, &pow, &sign);
	while (*str && *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str == '.')
			(1) && (pow = 10, add = 1);
		(!(*str >= '0' && *str <= '9') && *str != '.') && (*errno = 1);
		(*str >= '0' && *str <= '9') && (result = result * add + ((*str - '0') / pow));
		(pow != 1 && *str != '.') && (pow *= 10);
		str++;
	}
	return (result * sign);
}
