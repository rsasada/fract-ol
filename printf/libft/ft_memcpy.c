/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy .c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 15:21:23 by risasada          #+#    #+#             */
/*   Updated: 2023/05/28 15:28:07 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < len)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i ++;
	}
	return (dst);
}
// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char *str = "test";
// 	// str[0] = 'a';
// 	char test[4];
// 	test[0] = 'b';

// 	// str1 = memcpy(NULL, test, 3);
// 	char *str1 = memcpy(NULL, NULL, 3);
// 	// str1 = ft_memcpy(str, NULL, 3);
// 	// str1 = ft_memcpy(str, '\0', 3);
// 		// NULL = 0x0
// 		// 101 = 'c'
// 		// '\0'
// 	// printf("%p %p %p %s\n", NULL, str1, &str1, str1);
// 	// str1 = *str;
// 	// str1 = "\0";
// }