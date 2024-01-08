/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:44:03 by risasada          #+#    #+#             */
/*   Updated: 2023/06/21 14:46:31 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static void	short_cut(size_t *j, int *i, char *str);
static int	check_overflow(long n, char c, int sign);

int	ft_atoi(const char *str)
{
	long	n;
	int		i;
	size_t	j;
	int		sign;

	n = 0;
	j = 0;
	i = 1;
	sign = 0;
	if (*str == '\0')
		return (0);
	short_cut(&j, &i, (char *)str);
	while (str[j] >= '0' && str[j] <= '9')
	{
		sign = check_overflow(n, str[j], i);
		if (sign == 1)
			return ((int)LONG_MAX);
		else if (sign == -1)
			return ((int)LONG_MIN);
		n *= 10;
		n += str[j] - 48;
		j ++;
	}
	return ((int)(n * i));
}

static void	short_cut(size_t *j, int *i, char *str)
{
	while (((str[*j] <= 13 && str[*j] >= 9) || str[*j] == 32) && str[*j])
	{
		*j += 1;
	}
	if (str[*j] == '-')
	{
		*j += 1;
		*i *= -1;
	}
	else if (str[*j] == '+')
		*j += 1;
}

static int	check_overflow(long n, char c, int sign)
{
	if (n > (LONG_MAX / 10))
	{
		if (sign == 1)
			return (1);
		else if (sign == -1)
			return (-1);
	}
	else if (sign == 1 && n == (LONG_MAX / 10)
		&& (c - '0') > (LONG_MAX % 10))
	{
		return (1);
	}
	else if (sign == -1 && n == (LONG_MAX / 10)
		&& (c - '0') > (LONG_MAX % 10) + 1)
	{
		return (-1);
	}
	return (0);
}
