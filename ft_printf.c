/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:33:32 by xli               #+#    #+#             */
/*   Updated: 2021/01/29 10:11:10 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

static void	ft_output(char **str, va_list *args, int *counter)
{
	t_form form;

	(*str)++;
	ft_parse(str, args, &form);
	ft_handle_specifier(form, args, counter);
}

int			ft_printf(const char *format, ...)
{
	int		counter;
	char	*str;
	va_list	args;

	counter = 0;
	va_start(args, format);
	str = (char *)format;
	while (*str)
	{
		if (*str == '%')
			ft_output(&str, &args, &counter);
		else
			ft_putchar(*(str++), &counter);
	}
	va_end(args);
	return (counter);
}
