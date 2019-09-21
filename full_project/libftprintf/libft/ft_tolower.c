/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 17:39:03 by cdemetra          #+#    #+#             */
/*   Updated: 2019/05/14 17:34:39 by cdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tolower(int chr)
{
	if (chr >= 'A' && chr <= 'Z')
	{
		return (chr + ('a' - 'A'));
	}
	return (chr);
}