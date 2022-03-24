/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:10:31 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/24 10:46:55 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H
# include <stddef.h>
# include <stdarg.h>
int		ft_printf(const char *msg, ...);
int		ft_putchar(const char c);
int		ft_putstr(const char *str);
int		ft_putnbr(const long long n);
int		ft_putaddr(void *addr);
int		ft_puthex(unsigned long long n, int flag);
size_t	ft_strlen(const char *str);

#endif
