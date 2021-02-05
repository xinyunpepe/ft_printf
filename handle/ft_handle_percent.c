/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_percent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:00:06 by xli               #+#    #+#             */
/*   Updated: 2021/02/05 10:11:34 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_handle_percent(t_form form, int *counter)
{
	if (!form.flag[0])
	{
		while (form.width-- > 1)
		{
			if (form.flag[1])
				ft_putchar('0', counter);
			else
				ft_putchar(' ', counter);
		}
	}
	ft_putchar('%', counter);
	if (form.flag[0])
		while (form.width-- > 1)
			ft_putchar(' ', counter);
}
