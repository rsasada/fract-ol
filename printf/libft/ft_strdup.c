/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 20:08:08 by risasada          #+#    #+#             */
/*   Updated: 2023/06/21 14:47:43 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static char	*ft_strcpy(char *dest, const char *src);

char	*ft_strdup(const char *src)
{
	char	*c;
	size_t	len;

	len = ft_strlen(src);
	c = (char *)malloc(sizeof(char) * (len + 1));
	if (!c)
		return (NULL);
	ft_strcpy(c, src);
	return (c);
}

static char	*ft_strcpy(char *dest, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}
