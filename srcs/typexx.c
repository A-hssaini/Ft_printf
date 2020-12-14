/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typexx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:57:03 by ahssaini          #+#    #+#             */
/*   Updated: 2020/02/08 18:51:59 by ahssaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	norminette14(int i, t_param *a, int *count, char *str)
{
	if (*str == '-')
	{
		write(1, "-", 1);
		*count = *count + 1;
		str++;
	}
	while (i != 0)
	{
		if (a->precesion > 0)
			write(1, " ", 1);
		else
			write(1, "0", 1);
		*count = *count + 1;
		i--;
	}
	*count = *count + ft_strlen(str);
	write(1, str, ft_strlen(str));
}

void	norminette15(int i, int *count, char *str)
{
	write(1, str, ft_strlen(str));
	*count = *count + ft_strlen(str);
	while (i > 0)
	{
		*count = *count + 1;
		write(1, " ", 1);
		i--;
	}
}

void	printf_x_with(t_param *a, char *str, int *count)
{
	int i;

	i = a->with - ft_strlen(str);
	if (a->flag == '-')
		norminette15(i, count, str);
	else if (a->flag == '0')
		norminette14(i, a, count, str);
	else
	{
		while (i > 0)
		{
			*count = *count + 1;
			write(1, " ", 1);
			i--;
		}
		write(1, str, ft_strlen(str));
		*count = *count + ft_strlen(str);
	}
}
