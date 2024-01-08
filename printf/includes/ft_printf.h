/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risasada <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:11:19 by risasada          #+#    #+#             */
/*   Updated: 2023/07/30 18:11:23 by risasada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include	<stdlib.h>
# include	<stdio.h>
# include	<stdint.h>
# include	<limits.h>
# include	<unistd.h>
# include	<string.h>
# include	<stdarg.h>
# include	<stdlib.h>

ssize_t	ft_putstr(char *s);
ssize_t	ft_putchar(int c);
ssize_t	ft_print_hex(unsigned int nb, const char format);
ssize_t	ft_print_pointer(unsigned long long address);
void	ft_putnbr(int n, int fd, ssize_t *count);
void	ft_put_uint_nbr(unsigned int n, int fd, ssize_t *count);
int		ft_printf(const char *s, ...);

#endif
