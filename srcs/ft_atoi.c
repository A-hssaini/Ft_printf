/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:52:11 by ahssaini          #+#    #+#             */
/*   Updated: 2020/02/08 18:52:20 by ahssaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		initialize(int *a, int *b)
{
	*a = 0;
	*b = 0;
}

static int		test(int negative, int nombre)
{
	if (negative)
		nombre = nombre * (-1);
	return (nombre);
}

int				ft_atoi(const char *str)
{
	int		nombre;
	int		negative;

	initialize(&nombre, &negative);
	while (*str != '\0')
	{
		if (*str == ' ' || *str == '\n'
			|| *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\r')
			str++;
		else
			break ;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			negative = 1;
	}
	while (*str >= '0' && *str <= '9' && *str != '\0')
	{
		nombre = nombre * 10 + *str - 48;
		str++;
	}
	nombre = test(negative, nombre);
	return (nombre);
}
