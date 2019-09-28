/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int_part.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:28:25 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/28 18:37:25 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	begin_action(uint64_t *buf, char *s_int)
{
	buf[0] = 1;
	buf[1] = 0;
	if (*s_int == '\0')
		return (buf);
}

uint64_t	*convert_integer(uint64_t *buf, char *s_int)
{
	unsigned	maxpow;
	unsigned	i;
	uint64_t	buf_2n[2000];

	begin_action(buf, s_int);
	i = 0;
	maxpow = ft_strlen(s_int) - 1;
	while (s_int[maxpow - i] == '0')
	{
		if (maxpow - i == 0)
			return (buf);
		i++;
	}
	pow_of_two(buf_2n, i);
	while (i <= maxpow)
	{
		if (i == 0)
			buf[1] = 0;
		if (s_int[maxpow - i] == '1')
			add(buf, buf_2n);
		mul_s(buf_2n, 2);
		i++;
	}
	return (buf);
}
