/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:29:46 by risasada          #+#    #+#             */
/*   Updated: 2023/05/28 17:48:08 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*converted_s;

	converted_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (converted_s[i] == (unsigned char)c)
			return ((void *)(&converted_s[i]));
		i ++;
	}
	return (NULL);
}
