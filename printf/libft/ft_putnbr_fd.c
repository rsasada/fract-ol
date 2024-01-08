/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 20:31:03 by risasada          #+#    #+#             */
/*   Updated: 2023/06/03 20:31:52 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd(n + 48, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	else if (n < 0 && n >= -2147483647)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n, fd);
	}
	else
	{
		write(fd, "-2147483648", 11);
	}
}
