/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:15:20 by xli               #+#    #+#             */
/*   Updated: 2021/01/31 18:18:43 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_string(t_form form, va_list *args, int *counter)
{
	char *str;

	str = va_arg(*args, char*);
	if (!str)
		str = "(null)";
	if (form.precision == -1 || form.precision > (int)ft_strlen(str))
		form.precision = (int)ft_strlen(str);
	form.width -= form.precision;
	if (!form.flag[0])
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	while (form.precision-- > 0)
		ft_putchar(*(str++), counter);
	while (form.width-- > 0)
		ft_putchar(' ', counter);
}
