/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:22:45 by xli               #+#    #+#             */
/*   Updated: 2021/02/04 08:56:55 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

/*
** [flags][width][.precision]specifier
**
** flags : '-' '0'
**
** specifier : cspdiuxX%
**             012345678
*/

typedef struct	s_form
{
	int			flag[5];
	int			width;
	int			precision;
	int			specifier;
}				t_form;

int				ft_printf(const char *format, ...);
int				ft_comp(int a, int b);
int				ft_atoi(const char *str);
size_t			ft_strlen(const	char *s);
char			*ft_itoa(long n);
char			*ft_itoa_base(unsigned long n, const char *base, unsigned long base_len);
void			ft_init_form(t_form *form);
void			ft_get_flags(char **str, t_form *form);
void			ft_get_width(char **str, va_list *args, t_form *form);
void			ft_get_precision(char **str, va_list *args, t_form *form);
void			ft_get_specifier(char **str, t_form *form);
void			ft_parse(char **str, va_list *args, t_form *form);
void			ft_putchar(char c, int *counter);
void			ft_putstr(char *str, int *counter);
void			ft_handle_char(t_form form, va_list *args, int *counter);
void			ft_handle_percent(t_form form, int *counter);
void			ft_handle_string(t_form form, va_list *args, int *counter);
void			ft_handle_specifier(t_form form, va_list *args, int *counter);
void			ft_int_zero(t_form form, int *counter);
void			ft_int_int(t_form form, char *str, int len, long nb, int *counter);
void			ft_handle_int(t_form form, va_list *args, int *counter);
void			ft_unint_zero(t_form form, int *counter);
void			ft_unint_unint(t_form form, char *str, int len, int *counter);
void			ft_handle_unint(t_form form, va_list *args, int *counter);
void			ft_hex_zero(t_form form, int *counter);
void			ft_hex_hex(t_form form, char *str, int len, int *counter);
void			ft_handle_hex(t_form form, va_list *args, int *counter);
void			ft_hex_zero_upper(t_form form, int *counter);
void			ft_hex_hex_upper(t_form form, char *str, int len, int *counter);
void			ft_handle_hex_upper(t_form form, va_list *args, int *counter);
void			ft_pointer_null(t_form form, int *counter);
void			ft_pointer_pointer(t_form form, char *str, int *counter);
void			ft_handle_pointer(t_form form, va_list *args, int *counter);

#endif
