/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:17:30 by risasada          #+#    #+#             */
/*   Updated: 2023/06/01 16:17:45 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	how_many_digit(int n);

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		len;
	char		*s;

	len = how_many_digit(n) + 1;
	nb = n;
	if (n < 0)
	{
		nb *= -1;
		len ++;
	}
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	*(s + len) = '\0';
	while (len --)
	{
		*(s + len) = (nb % 10) + '0';
		nb /= 10;
	}
	if (n < 0)
		*(s + 0) = '-';
	return (s);
}

static int	how_many_digit(int n)
{
	int	i;

	i = 0;
	n /= 10;
	while (n != 0)
	{
		n /= 10;
		i ++;
	}
	return (i);
}
