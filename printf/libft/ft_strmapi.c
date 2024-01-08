/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:55:22 by risasada          #+#    #+#             */
/*   Updated: 2023/06/01 18:55:24 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size_s;
	char			*s2;

	i = 0;
	size_s = ft_strlen((char *)s);
	s2 = (char *)malloc(sizeof(char) * (size_s + 1));
	if (!s2)
		return (NULL);
	while (s[i] != '\0')
	{
		s2[i] = f(i, s[i]);
		i ++;
	}
	s2[i] = '\0';
	return (s2);
}
