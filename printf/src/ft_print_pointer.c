/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 16:40:15 by risasada          #+#    #+#             */
/*   Updated: 2023/09/12 16:40:16 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

#include	"ft_printf.h"

void	ft_put_pointer(unsigned long long nb, const char format)
{
	if (nb >= 16)
	{
		ft_put_pointer(nb / 16, format);
		ft_put_pointer(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

ssize_t	how_many_pointer_len(unsigned long long num)
{
	ssize_t	len;

	len = 0;
	while (num)
	{
		num = num / 16;
		len ++;
	}
	return (len);
}

ssize_t	ft_print_pointer(unsigned long long address)
{
	ssize_t	count;

	count = ft_putstr("0x");
	if (address == 0)
		count += write(1, "0", 1);
	else
	{
		ft_put_pointer(address, 'x');
		count += how_many_pointer_len(address);
	}
	return (count);
}
