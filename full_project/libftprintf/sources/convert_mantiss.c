/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_mantiss.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:20 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/28 20:02:09 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*lead_zeros(long long exp, char *part, char flag)
{
	if (flag == 'f')
	{
		while (exp >= 0)
		{
			*part = '0';
			part++;
			exp--;
		}
		return (&(*part));
	}
	if (flag == 'i')
	{
		while (exp >= 0)
		{
			*part = '0';
			part++;
			exp--;
		}
		*part = '\0';
	}
	return (part);
}

void	frac_to_str(void *src, char *f_p, int i,int k, t_qualfrs *fmt)
{
	unsigned char	*s;
	unsigned char	bit;
	size_t			zeros;
	size_t			l;

	l = i * 8 + k;
	s = (unsigned char*)src;
	k == 0 ? k = 7 : k--;
	zeros = 0;
	while (i >= 0)
	{
		while (k >= 0)
		{
			bit = (s[i] >> k) & 1;
			bit == 0 ? zeros++ : 1;
			*f_p = bit + '0';
			f_p++;
			k--;
		}
		k = 7;
		i--;
	}
	*f_p = '\0';
	if (zeros == l)
		fmt->ld->fflg = 1;
}

void	replace_bit_min(void *src, char *f_p, size_t size, long long exp)
{
	unsigned char	*s;
	unsigned char	bit;
	int				i;
	int				k;

	s = (unsigned char*)src;
	i = size - 1;
	k = 7;
	if (exp != 0)
		f_p = lead_zeros(exp, &(*f_p), 'f');
	while (i >= 0)
	{
		while (k >= 0)
		{
			bit = (s[i] >> k) & 1;
			*f_p = bit + '0';
			f_p++;
			k--;
		}
		k = 7;
		i--;
	}
	*f_p = '\0';
}

static void	end_action(long long exp, char *i_p)
{
	if (exp >= 0)
		lead_zeros(exp, &(*i_p), 'i');
	else
		*i_p = '\0';
}

static void	begin_action(long long *exp, int *i, int *k, t_qualfrs *fmt)
{
	size_t	size;

	size = 8;
	*exp = fmt->ld->exp;
	*i = size - 1;
	*k = 7;
}

void	replace_bit_max(void *src, char *i_p, char *f_p, t_qualfrs *fmt)
{
	unsigned char	*s;
	unsigned char	bit;
	int				ind[2];
	long long		exp;

	begin_action(&exp, &(ind[0]), &(ind[1]), fmt);
	s = (unsigned char*)src;
	while (ind[0] >= 0 && exp >= 0)
	{
		while (ind[1] >= 0 && exp >= 0)
		{
			bit = (s[ind[0]] >> ind[1]) & 1;
			*i_p = bit + '0';
			i_p++;
			if (exp == 0)
				frac_to_str(src, f_p, ind[0], ind[1], fmt);
			exp--;
			ind[1]--;
		}
		ind[1] = 7;
		ind[0]--;
	}
	end_action(exp, &(*i_p));
}
