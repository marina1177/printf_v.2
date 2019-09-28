/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 18:59:40 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/28 18:29:29 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_print_b(t_qualfrs *ql)
{
	long long int	y;
	char			*bin;

	y = va_arg(ql->ap, long long int);
	if (!(bin = ft_strnew(64)))
		return ;
	print_bits2(&y, bin, 7);
	ql->num = bin;
	ql->countnum = 64;
	ft_print_u2(ql);
	free(ql->num);
}
