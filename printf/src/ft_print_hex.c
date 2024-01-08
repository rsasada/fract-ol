/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:07:28 by risasada          #+#    #+#             */
/*   Updated: 2023/08/03 16:07:31 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"
#include	"ft_printf.h"

void	ft_put_hex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		ft_put_hex(nb / 16, format);
		ft_put_hex(nb % 16, format);
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

ssize_t	how_many_hex_len(unsigned int num)
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

ssize_t	ft_print_hex(unsigned int nb, const char format)
{
	if (nb == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(nb, format);
	return (how_many_hex_len(nb));
}
