/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:37:50 by risasada          #+#    #+#             */
/*   Updated: 2023/06/21 14:48:22 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	char	*n_s;

	i = 0;
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	n_s = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!n_s)
		return (NULL);
	while (i < len_s1)
	{
		n_s[i] = s1[i];
		i ++;
	}
	i = 0;
	while (i < len_s2)
	{
		n_s[len_s1 + i] = s2[i];
		i ++;
	}
	n_s[len_s1 + i] = '\0';
	return (n_s);
}
