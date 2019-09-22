/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 17:40:19 by cdemetra          #+#    #+#             */
/*   Updated: 2019/08/20 18:51:52 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numbcounter(unsigned long long n)
{
	int				i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa2(unsigned long long int n, int *x)
{
	char			*str;
	int				q;

	q = ft_numbcounter(n);
	*x = q;
	if (!(str = ft_strnew(q)))
		return (NULL);
	while (--q >= 0)
	{
		str[q] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
