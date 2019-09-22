/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:21:22 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/23 16:35:35 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_without_typs(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	if (fl->minus)
	{
		ql->countchr += write(1, &(ql->sformat)[0], 1);
		ft_print_space(ql->width - 1, ql);
	}
	else
	{
		ft_print_space(ql->width - 1, ql);
		ql->countchr += write(1, &(ql->sformat)[0], 1);
	}
	ql->sformat++;
}

void	ft_print_percent(t_qualfrs *ql)
{
	t_flag *fl;

	fl = ql->flg;
	if (ql->width > 1)
	{
		if (fl->minus)
		{
			ql->countchr += write(1, &(TYPES)[13], 1);
			ft_print_space(ql->width - 1, ql);
		}
		else
		{
			if (fl->zero)
				ft_print_zero(ql->width - 1, ql);
			else
				ft_print_space(ql->width - 1, ql);
			ql->countchr += write(1, &(TYPES)[13], 1);
		}
	}
	else
		ql->countchr += write(1, &(TYPES)[13], 1);
}
