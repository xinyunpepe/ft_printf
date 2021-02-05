/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:18:50 by xli               #+#    #+#             */
/*   Updated: 2021/01/29 10:10:52 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse(char **str, va_list *args, t_form *form)
{
	ft_init_form(form);
	ft_get_flags(str, form);
	ft_get_width(str, args, form);
	ft_get_precision(str, args, form);
	ft_get_specifier(str, form);
}
