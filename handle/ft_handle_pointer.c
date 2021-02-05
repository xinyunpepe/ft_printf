/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:56:08 by xli               #+#    #+#             */
/*   Updated: 2021/02/04 09:51:06 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pointer_null(t_form form, int *counter)
{
	if (form.precision == -1)
		form.precision = 1;
	form.precision = ft_comp(form.precision, 0);
	form.width = ft_comp(form.width - form.precision - 2, 0);
	if (!form.flag[0] && !form.flag[1])
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	ft_putstr("0x", counter);
	if (form.flag[1])
		while (form.width-- > 0)
			ft_putchar('0', counter);
	while (form.precision-- > 0)
		ft_putchar('0', counter);
	while (form.width-- > 0)
		ft_putchar(' ', counter);
}

void	ft_pointer_pointer(t_form form, char *str, int *counter)
{
	if (form.flag[1])
	{
		ft_putstr("0x", counter);
		while (form.width-- > 0)
			ft_putchar('0', counter);
		ft_putstr(str, counter);
	}
	else if (!form.flag[0])
	{
		while (form.width-- > 0)
			ft_putchar(' ', counter);
		ft_putstr("0x", counter);
		while (form.precision-- > 0)
			ft_putchar('0', counter);
		ft_putstr(str, counter);
	}
	else
	{
		ft_putstr("0x", counter);
		while (form.precision-- > 0)
			ft_putchar('0', counter);
		ft_putstr(str, counter);
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	}
}

void	ft_handle_pointer(t_form form, va_list *args, int *counter)
{
	void	*ptr;
	char	*str;
	int		len;

	ptr = va_arg(*args, void*);
	str = ft_itoa_base((unsigned long)ptr, "0123456789abcdef", 16);
	len = ft_strlen(str);
	if (form.precision != -1 || form.flag[0])
		form.flag[1] = 0;
	if (ptr == NULL)
		ft_pointer_null(form, counter);
	else
	{
		form.precision = ft_comp(form.precision - len, 0);
		form.width = ft_comp(form.width - form.precision - len - 2, 0);
		ft_pointer_pointer(form, str, counter);
	}
	free(str);
}
