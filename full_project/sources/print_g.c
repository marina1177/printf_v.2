/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 17:53:02 by cdemetra          #+#    #+#             */
/*   Updated: 2019/09/19 16:47:04 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*void	ft_print_nan_inf(t_qualfrs *ql, int f)
{
	if (f == 1)
	{
		if (ql->typs >= 65 && ql->typs <= 90)
			ql->countchr += write(1, INF_NAN[0], 3);
		else
			ql->countchr += write(1, INF_NAN[1], 3);
	}
	else if (f == 2)
	{
		if (ql->typs >= 65 && ql->typs <= 90)
			ql->countchr += write(1, INF_NAN[2], 3);
		else
			ql->countchr += write(1, INF_NAN[3], 3);
	}
}

int		ft_inf_nan(char *s_int, t_qualfrs *ql)
{
	int i;

	i = 0;
	while (s_int[i] == '1' && i < 15)
		i++;
	if (i != 14)
		return (0);
	else if (s_int[i] == '1')
	{
		while (s_int[i] == '0' && s_int[i])
			i++;
		if (i < 64)
			ft_print_nan_inf(ql, 1);
		else
		{
			if (s_int[0] == '0')
				ql->countchr += write(1, &MINUS, 1);
		//	ft_print_nan_inf(ql, 2);
		}
		return (1);
	}
	return (0);
}*/


