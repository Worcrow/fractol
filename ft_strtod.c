/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: worcrow <worcrow@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 08:41:18 by worcrow           #+#    #+#             */
/*   Updated: 2024/07/08 14:00:53 by worcrow          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

static void	initialize_var(int *add, double *result, double *pow, int *sign)
{
	*add = 10;
	*result = 0.0;
	*pow = 1.0;
	*sign = 1;
}

static int	is_digit(char *c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
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
		(!is_digit(*str) && *str != '.') && (send_error("Error", EINVAL));
		(is_digit(*str)) && (result = result * add + ((*str - '0') / pow));
		(pow != 1 && *str != '.') && (pow *= 10);
		str++;
	}
	return (result * sign);
}
