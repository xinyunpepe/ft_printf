/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 11:02:33 by xli               #+#    #+#             */
/*   Updated: 2021/01/31 18:19:05 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_char(t_form form, va_list *args, int *counter)
{
	if (!form.flag[0])
		while (form.width-- > 1)
			ft_putchar(' ', counter);
	ft_putchar(va_arg(*args, int), counter);
	while (form.width-- > 1)
		ft_putchar(' ', counter);
}
