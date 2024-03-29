/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_mod_l_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharity <bcharity@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:28 by bcharity          #+#    #+#             */
/*   Updated: 2019/09/20 17:32:31 by bcharity         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int simple_case_div_mod(uint64_t *buf_a, uint64_t *buf_b, uint64_t *res)
{
    if ((buf_a[0] < buf_b[0]) || ( buf_a[0] == buf_b[0] && buf_a[buf_a[0]] < buf_b[buf_b[0]]))
    {
        res[0] = 1;
        res[1] = 0;
        return (1);
    }
    else if ( buf_b[0] == 1)
    {
        div_mod_s( buf_a, buf_b[1], res, &buf_a[1]);
        buf_a[0] = 1;
        return (1);
    }
    else
        return (0);
}

void buf_normalize(uint64_t *scale, uint64_t *buf_a, uint64_t *buf_b)
{
    *scale = BASE / ( buf_b[buf_b[0]] + 1 );
    if (*scale > 1)
    {
        mul_s(buf_a, *scale);
        mul_s(buf_b, *scale);
    }
}


void get_zero_buf(uint64_t *buf, uint64_t m)
{
    long long temp1;

    buf[0] = m;
    temp1 = 1;
    while(temp1 <= (long long)m)
    {
        buf[temp1++] = 0;
    }
}

void guess_stabilization(uint64_t *r, uint64_t *qGuess, uint64_t nextpart, uint64_t *buf_b)
{
    long long       temp2;
    uint64_t        temp1;
    uint64_t        n;

    n=buf_b[0];
    while (*r < BASE)
    {
        temp2 = buf_b[n-1]*(*qGuess);
        temp1 = (*r)*BASE + nextpart;
        if (((uint64_t)temp2 > temp1) || ((*qGuess) == BASE))
        {
            --(*qGuess);
            (*r) += buf_b[n];
        }
        else break;
    }
}