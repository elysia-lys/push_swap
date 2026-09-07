/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zetan <zetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 18:20:05 by zetan             #+#    #+#             */
/*   Updated: 2026/08/26 15:18:25 by zetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

int	print_char(int c);
int	print_string(const char *str);
int	print_num(int n);
int	print_address(void *ptr);
int	print_hex(unsigned int n, char c);
int	print_unsigned_num(unsigned int n);
int	ft_printf(const char *s, ...);

#endif