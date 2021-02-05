/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:48:03 by xli               #+#    #+#             */
/*   Updated: 2021/02/03 22:46:25 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void	ft_int_zero(t_form form, int *counter)
{
	if (!form.flag[0])
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	while (form.width-- > 0)
		ft_putchar(' ', counter);
}

void	ft_int_int(t_form form, char *str, int len, long nb, int *counter)
{
	form.precision = ft_comp(form.precision - len, 0);
	form.width = ft_comp(form.width - form.precision
	- (len + (nb < 0 ? 1 : 0)), 0);
	if (!form.flag[0] && !form.flag[1])
		while (form.width-- > 0)
			ft_putchar(' ', counter);
	if (nb < 0)
		ft_putchar('-', counter);
	while (form.precision-- > 0)
		ft_putchar('0', counter);
	if (form.flag[1])
		while (form.width-- > 0)
			ft_putchar('0', counter);
	ft_putstr(str, counter);
	while (form.width-- > 0)
		ft_putchar(' ', counter);
}

void	ft_handle_int(t_form form, va_list *args, int *counter)
{
	char	*str;
	long	nb;
	int		len;

	str = 0;
	nb = va_arg(*args, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (nb == 0 && !form.precision)
		ft_int_zero(form, counter);
	else
	{
		if (form.precision != -1 || form.flag[0])
			form.flag[1] = 0;
		ft_int_int(form, str, len, nb, counter);
	}
	free(str);
}
