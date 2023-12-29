/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:43:42 by chon              #+#    #+#             */
/*   Updated: 2023/12/27 12:21:35 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convert(int nbr, char *base, int len)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			convert(-2147483648 / len * -1, base, len);
			convert(-2147483648 % len * -1, base, len);
		}
		else
			convert(-nbr, base, len);
	}
	else if (nbr > len - 1)
	{
		convert(nbr / len, base, len);
		convert(nbr % len, base, len);
	}
	else if (nbr < len)
		write(1, &base[nbr], 1);
}

int	check_arg(char *base, int *len)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (base[*len])
	{
		if (base[*len] == '+' || base[*len] == '-')
			return (0);
		*len += 1;
	}
	if (*len < 2)
		return (0);
	while (base[i + 1])
	{
		while (base[j + i])
		{
			if (base[i] == base[j + i])
				return (0);
			j++;
		}
		j = 1;
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	if (check_arg(base, &len) == 0)
		return ;
	convert(nbr, base, len);
}
