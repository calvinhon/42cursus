/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:43:35 by chon              #+#    #+#             */
/*   Updated: 2023/12/29 16:11:23 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int num)
{
	int	digits;

	digits = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		digits++;
	}
	return (digits);
}

int	alpha(const char *format, va_list args, va_list args2, va_list args3)
{
	int	count;

	count = 0;
	if (*format == 's')
	{
		if (va_arg(args, char *) == NULL)
		{
			count += 6;
			ft_putstr_fd("(null)", 1);
		}
		else
		{
			ft_putstr_fd(va_arg(args2, char *), 1);
			count += ft_strlen(va_arg(args3, char *));
		}
	}
	else if (*format == 'c')
	{
		ft_putchar_fd(va_arg(args3, int), 1);
		count++;
	}
	return (count);
}

int	void_ptr(const char *format, va_list args, va_list args2)
{
	int	count;

	count = 0;
	if (*format == '#')
		ft_strlen(va_arg(args2, char *));
	ft_putstr_fd("0x", 1);
	if (ft_strlen(va_arg(args, char *)) == 0)
		count++;
	// if (sizeof(va_arg(args, void *)) == sizeof(char *))
	// 	ft_putstr_fd("10", 1);
	ft_putnbr_base((int)va_arg(args2, void *), "0123456789abcdef");
	return (count + count_digits((int)va_arg(args, void *)) + 2);
}

int	num(const char *format, va_list args, va_list args2)
{
	int	count;

	count = 0;
	if (*format == 'd' || *format == 'i')
		ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (*format == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	return (count_digits(va_arg(args2, int)));
}

int	*path(int *count, char *flags, const char *format, va_list args, va_list args2, va_list args3)
{
	if (*format == 's' || *format == 'c')
		*count += alpha(format, args, args2, args3);
	else if (*format == 'p')
		*count += void_ptr(format, args, args2);
	else if (ft_strchr(flags, *format))
		format++;
	else if (*format == '%')
	{
		ft_putchar_fd(*format, 1);
		(*count)++;
	}
	else
		*count += num(format, args, args2);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;
	va_list	args2;
	va_list	args3;
	char	*flags;

	count = 0;
	va_start(args, format);
	va_copy(args2, args);
	va_copy(args3, args);
	flags = "-0.'# +";
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			count++;
		}
		else
		{
			format++;
			path(&count, flags, format, args, args2, args3);
		}
		format++;
	}
	va_end(args);
	return (count);
}

// int main(void)
// {
// 	char *format = "%p";
// 	// char c = '0';
// 	// char *s1 = "hi\n";
// 	// char *s2 = "good bye\n";
// 	int i1 = 1;
// 	ft_printf(format, i1);
// 	printf("\n");
// 	printf(format, i1);
// }