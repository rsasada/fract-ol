/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 18:15:09 by risasada          #+#    #+#             */
/*   Updated: 2023/07/30 18:11:04 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"

ssize_t	check_format(char identifier, va_list args);

int	ft_printf(const char *s, ...)
{
	va_list	args;
	ssize_t	i;
	ssize_t	count;
	ssize_t	arg_count;

	i = 0;
	count = 0;
	va_start(args, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			arg_count = check_format(s[i + 1], args);
			if (arg_count != 0)
				count += arg_count;
			i += 2;
		}
		else
		{
			ft_putchar_fd(s[i], 1);
			count ++;
			i ++;
		}
	}
	return (count);
}

ssize_t	check_format(char identifier, va_list args)
{
	ssize_t	count;

	count = 0;
	if (identifier == 'c')
		count = ft_putchar(va_arg(args, int));
	else if (identifier == 's')
		count = ft_putstr(va_arg(args, char *));
	else if (identifier == 'p')
		count = ft_print_pointer(va_arg(args, unsigned long long));
	else if (identifier == 'd' || identifier == 'i')
		ft_putnbr(va_arg(args, int), 1, &count);
	else if (identifier == 'u')
		ft_put_uint_nbr(va_arg(args, unsigned int), 1, &count);
	else if (identifier == 'x' || identifier == 'X')
		count = ft_print_hex(va_arg(args, unsigned int), identifier);
	else if (identifier == '%')
		count = write(1, "%", 1);
	else
		return (0);
	return (count);
}
