/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 08:41:04 by xli               #+#    #+#             */
/*   Updated: 2021/02/04 08:49:12 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_hex_zero(t_form form, int *counter)
{
	if (!form.flag[0])
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	while (form.width-- > 0)
		ft_putchar(' ', counter);
}

void	ft_hex_hex(t_form form, char *str, int len, int *counter)
{
	form.precision = ft_comp(form.precision - len, 0);
	form.width = ft_comp(form.width - form.precision - len, 0);
	if (!form.flag[0] && !form.flag[1])
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	while (form.precision-- > 0)
		ft_putchar('0', counter);
	if (form.flag[1])
		while (form.width-- > 0)
			ft_putchar('0', counter);
	ft_putstr(str, counter);
	while (form.width-- > 0)
		ft_putchar(' ', counter);
}

void	ft_handle_hex(t_form form, va_list *args, int *counter)
{
	char	*str;
	long	nb;
	int		len;

	str = 0;
	nb = va_arg(*args, unsigned int);
	str = ft_itoa_base(nb, "0123456789abcdef", 16);
	len = ft_strlen(str);
	if (nb == 0 && !form.precision)
		ft_hex_zero(form, counter);
	else
	{
		if (form.precision != -1 || form.flag[0])
			form.flag[1] = 0;
		ft_hex_hex(form, str, len, counter);
	}
	free(str);
}
