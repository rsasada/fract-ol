/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:24:22 by risasada          #+#    #+#             */
/*   Updated: 2023/06/17 17:24:27 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (dstsize != 0)
	{
		while (i < dstsize - 1)
		{
			if (src[i] == '\0')
				break ;
			dst[i] = src[i];
			i ++;
		}
		dst[i] = '\0';
	}
	len = ft_strlen((char *)src);
	return (len);
}
