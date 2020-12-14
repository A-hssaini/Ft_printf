/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typexx1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:57:14 by ahssaini          #+#    #+#             */
/*   Updated: 2020/02/08 18:52:41 by ahssaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_space_number_x_x(t_param *a, int *count, unsigned int nbr)
{
	char	*str;

	if (a->type == 'x')
		str = ft_itoa_base_x(nbr, 16);
	else
		str = ft_itoa_base_x_x(nbr, 16);
	a->with = a->with - (int)ft_strlen(str);
	while (a->with > 0)
	{
		write(1, " ", 1);
		*count = *count + 1;
		a->with--;
	}
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
	free(str);
}

void	printf_x_prec(t_param *a, char *str, int *count)
{
	int i;

	i = a->precesion - ft_strlen(str);
	if (*str == '-')
	{
		write(1, str, 1);
		*count = *count + 1;
		str++;
		i++;
	}
	while (i > 0)
	{
		write(1, "0", 1);
		*count = *count + 1;
		i--;
	}
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
}

void	printf_x_with_prec(t_param *a, char *str, int *count)
{
	int i;

	i = a->with - a->precesion;
	if (*str == '-')
		i--;
	if (a->flag == '-')
	{
		printf_d_prec(a, str, count);
		while (i > 0)
		{
			*count = *count + 1;
			write(1, " ", 1);
			i--;
		}
	}
	else
	{
		while (i > 0)
		{
			write(1, " ", 1);
			*count = *count + 1;
			i--;
		}
		printf_d_prec(a, str, count);
	}
}

void	printf_x_x(t_param *a, int *count, unsigned int nbr)
{
	char	*str;
	int		lenght;

	if (a->type == 'x')
		str = ft_itoa_base_x(nbr, 16);
	else
		str = ft_itoa_base_x_x(nbr, 16);
	lenght = (int)ft_strlen(str);
	if (lenght >= a->with && lenght >= a->precesion)
	{
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
	}
	else
	{
		if (lenght >= a->with)
			printf_x_prec(a, str, count);
		else if (lenght >= a->precesion)
			printf_x_with(a, str, count);
		else
			printf_x_with_prec(a, str, count);
	}
	free(str);
}
