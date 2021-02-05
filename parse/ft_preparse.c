/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_preparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 20:37:37 by xli               #+#    #+#             */
/*   Updated: 2021/01/29 10:10:55 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_init_form(t_form *form)
{
	form->flag[0] = 0;
	form->flag[1] = 0;
	form->width = -1;
	form->precision = -1;
	form->specifier = -1;
}

void	ft_get_flags(char **str, t_form *form)
{
	char flag[2];

	flag[0] = '-';
	flag[1] = '0';
	while (**str)
	{
		if (**str == flag[0])
			form->flag[0] = 1;
		else if (**str == flag[1])
			form->flag[1] = 1;
		else
			break ;
		(*str)++;
	}
}

void	ft_get_width(char **str, va_list *args, t_form *form)
{
	if (**str == '*')
	{
		form->width = va_arg(*args, int);
		if (form->width < 0)
		{
			(form->width) *= -1;
			(form->flag[0])++;
		}
		(*str)++;
	}
	else
	{
		form->width = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}

void	ft_get_precision(char **str, va_list *args, t_form *form)
{
	if (**str != '.')
		return ;
	(*str)++;
	if (**str == '*')
	{
		form->precision = va_arg(*args, int);
		if (form->precision < 0)
			form->precision = -1;
		(*str)++;
	}
	else
	{
		form->precision = ft_atoi(*str);
		while (**str >= '0' && **str <= '9')
			(*str)++;
	}
}

void	ft_get_specifier(char **str, t_form *form)
{
	char	specifier[9];
	int		i;

	specifier[0] = 'd';
	specifier[1] = 'i';
	specifier[2] = 'u';
	specifier[3] = 'x';
	specifier[4] = 'X';
	specifier[5] = 'c';
	specifier[6] = 's';
	specifier[7] = 'p';
	specifier[8] = '%';
	i = -1;
	while (++i < 9)
	{
		if (**str == specifier[i])
		{
			form->specifier = i;
			(*str)++;
			return ;
		}
	}
}
