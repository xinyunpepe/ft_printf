/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xli <xli@student.42lyon.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 09:01:22 by xli               #+#    #+#             */
/*   Updated: 2021/02/04 08:57:01 by xli              ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_itoa_rec(unsigned long n, const char *base,
						unsigned long base_len, char **str)
{
	if (n >= base_len)
		ft_itoa_rec(n / base_len, base, base_len, str);
	**str = base[(int)(n % base_len)];
	(*str)++;
}

char		*ft_itoa_base(unsigned long n, const char *base,
						unsigned long base_len)
{
	unsigned long	nb;
	int				len;
	char			*str;
	char			*res;

	nb = n;
	len = 1;
	while (nb >= base_len)
	{
		len++;
		nb /= base_len;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res = str;
	ft_itoa_rec(n, base, base_len, &str);
	*str = '\0';
	return (res);
}
