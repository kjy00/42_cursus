/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyokim <jiyokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:54:22 by jiyokim           #+#    #+#             */
/*   Updated: 2022/04/29 17:44:27 by jiyokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_print_c(char c);
int	ft_checkformat(char c, va_list ap);
int	ft_print_p(unsigned long long p);
int	ft_print_x(unsigned int hex);
int	ft_print_upperx(unsigned int hex);
int	ft_print_s(char *str);
int	ft_print_di(int num);
int	ft_print_u(unsigned int num);
int	ft_strlen(const char *s);

#endif
