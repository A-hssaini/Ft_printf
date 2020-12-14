/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahssaini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:52:48 by ahssaini          #+#    #+#             */
/*   Updated: 2020/02/08 18:50:21 by ahssaini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		much(unsigned long i, int base)
{
	int j;

	j = 1;
	while (i / base != 0 && (base >= 2 && base <= 16))
	{
		j++;
		i = i / base;
	}
	return (j);
}

int		ft_str(char *a)
{
	int i;

	i = 0;
	while (*a != '\0')
	{
		i++;
		a++;
	}
	return (i);
}

void	norminette1(int *j, int *n, unsigned long *t, char **tab)
{
	*j = 0;
	*n = 0;
	*tab = (char*)malloc(sizeof(char) * (much(*t, 16) + 1));
}

void	norminette1c(int *j, int *n, unsigned int *t, char **tab)
{
	*j = 0;
	*n = 0;
	*tab = (char*)malloc(sizeof(char) * (muchc(*t, 16) + 1));
}

void	norminette2(unsigned long *t, int *i, char *tab, int *n)
{
	while (*t != 0)
	{
		if (*t % 16 > 9)
			tab[*i] = 'a' + *t % 16 - 10;
		else
			tab[*i] = '0' + *t % 16;
		*i = *i + 1;
		*t = *t / 16;
	}
	tab[*i] = '\0';
	*n = ft_str(tab);
}
