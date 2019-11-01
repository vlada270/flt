/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thalfemp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:24:55 by thalfemp          #+#    #+#             */
/*   Updated: 2019/09/16 08:42:38 by thalfemp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		minus(char c)
{
	if (c == '-')
		return (-1);
	else
		return (1);
}

int				ft_atoi(const char *str)
{
	long long int	num;
	int				rev;
	long long int	x;

	num = 0;
	rev = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		rev = minus(*str);
		str++;
	}
	while (*str >= '0' && *str <= '9' && *str)
	{
		x = num * 10 + *str - 48;
		if (x / 10 != num && rev == 1)
			return (-1);
		if (x / 10 != num && rev == -1)
			return (0);
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * rev);
}
