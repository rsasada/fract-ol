/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:57:32 by risasada          #+#    #+#             */
/*   Updated: 2023/08/03 17:57:33 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"
#include	"libft.h"

void	ft_putnbr(int n, int fd, ssize_t *count)
{
	if (n < 10 && n >= 0)
	{
		ft_putchar(n + 48);
		*count += 1;
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, fd, count);
		ft_putnbr(n % 10, fd, count);
	}
	else if (n < 0 && n > INT_MIN)
	{
		n = n * -1;
		ft_putchar('-');
		*count += 1;
		ft_putnbr(n, fd, count);
	}
	else
	{
		write(fd, "-2147483648", 11);
		*count = 11;
	}
}

void	ft_put_uint_nbr(unsigned int n, int fd, ssize_t *count)
{
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd(n + 48, fd);
		*count += 1;
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10, fd, count);
		ft_putnbr(n % 10, fd, count);
	}
	else if (n > UINT_MAX)
	{
		write(fd, "4294967295", 11);
		*count += 10;
	}
}
