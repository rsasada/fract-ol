/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:16:16 by risasada          #+#    #+#             */
/*   Updated: 2023/06/03 14:16:18 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	check_word(char c, char charset);
static size_t	how_many_words(char *str, char charset);
static void		store_word(char *dest, char *start, char charset);
static int		split_word(char **splits, char *str, char charset);

char	**ft_split(char const *str, char charset)
{
	char	**splits;
	size_t	count;
	int		sign;

	count = how_many_words((char *)str, charset);
	if (count == 0)
		return (NULL);
	splits = (char **)malloc(sizeof(char *) * (count + 1));
	if (!splits)
		return (NULL);
	splits[count] = 0;
	sign = split_word(splits, (char *)str, charset);
	if (sign != -1)
	{
		count = 0;
		while (splits[count])
		{
			free(splits[count]);
			count ++;
		}
		free(splits);
	}
	return (splits);
}

static int	split_word(char **splits, char *str, char charset)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_word(str[i], charset) == 1)
			i ++;
		else
		{
			j = 0;
			while (check_word(str[i + j], charset) == 0)
				j ++;
			splits[count] = (char *)malloc(sizeof(char) * (j + 1));
			if (!splits[count])
				return (count);
			store_word(splits[count], str + i, charset);
			count ++;
			i += j;
		}
	}
	return (-1);
}

static void	store_word(char *dest, char *start, char charset)
{
	size_t	i;

	i = 0;
	while (check_word(start[i], charset) == 0)
	{
		dest[i] = start[i];
		i ++;
	}
	dest[i] = '\0';
}

static size_t	how_many_words(char *str, char charset)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_word(str[i], charset) == 0
			&& check_word(str[i + 1], charset) == 1)
			count ++;
		i ++;
	}
	return (count);
}

static size_t	check_word(char c, char charset)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return (1);
	if (charset == c)
		return (1);
	i ++;
	return (0);
}
