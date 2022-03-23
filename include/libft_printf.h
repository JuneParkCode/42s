/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungjpar <sungjpar@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:10:31 by sungjpar          #+#    #+#             */
/*   Updated: 2022/03/23 16:08:19 by sungjpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
int		ft_printf(const char *msg, ...);
int		ft_putchar(const char c);
int		ft_putstr(const char *str);
int		ft_putnbr_base(const int n, const char *base);
int		ft_putaddr(void *addr);
size_t	ft_strlen(const char *str);

#endif
