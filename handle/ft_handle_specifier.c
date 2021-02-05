/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 12:12:31 by xli               #+#    #+#             */
/*   Updated: 2021/02/02 09:55:47 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ft_printf.h"

void	ft_handle_specifier(t_form form, va_list *args, int *counter)
{
	if (form.specifier == 0 || form.specifier == 1)
		ft_handle_int(form, args, counter);
	if (form.specifier == 2)
		ft_handle_unint(form, args, counter);
	if (form.specifier == 3)
		ft_handle_hex(form, args, counter);
	if (form.specifier == 4)
		ft_handle_hex_upper(form, args, counter);
	if (form.specifier == 5)
		ft_handle_char(form, args, counter);
	if (form.specifier == 6)
		ft_handle_string(form, args, counter);
	if (form.specifier == 7)
		ft_handle_pointer(form, args, counter);
	if (form.specifier == 8)
		ft_handle_percent(form, counter);
}
