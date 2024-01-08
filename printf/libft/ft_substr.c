/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 17:40:10 by risasada          #+#    #+#             */
/*   Updated: 2023/06/03 17:40:34 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;
	size_t	s_len;

	s_len = ft_strlen(s);
	index = 0;
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len < len + start)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (s[start] != '\0' && index < len)
	{
		sub[index] = s[start + index];
		index ++;
	}
	sub[index] = '\0';
	return (sub);
}
