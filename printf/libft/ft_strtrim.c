/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:59:40 by risasada          #+#    #+#             */
/*   Updated: 2023/06/01 13:59:52 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static size_t	check_char(char s1, char const *set);
static size_t	check_front(const char *s, char const *set);
static size_t	check_back(const char *s, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_idx;
	size_t	back_idx;
	char	*t_s;

	front_idx = check_front(s1, set);
	back_idx = check_back(s1, set);
	if (front_idx > back_idx)
		t_s = ft_strdup("");
	else
		t_s = ft_substr(s1, front_idx, (back_idx - front_idx) + 1);
	return (t_s);
}

static size_t	check_front(const char *s, char const *set)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && check_char(s[i], set) == 1)
	{
		i ++;
	}
	return (i);
}

static size_t	check_back(const char *s, char const *set)
{
	size_t	len;

	len = ft_strlen(s);
	if (len > 0)
		len --;
	while (s[len] != '\0' && check_char(s[len], set) == 1)
		len --;
	return (len);
}

static size_t	check_char(char s1, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == s1)
			return (1);
		i ++;
	}
	return (0);
}
