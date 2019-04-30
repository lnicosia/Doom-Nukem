/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:46:05 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/30 15:40:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

int		read_int(unsigned char *str, int index)
{
	int		res;

	ft_printf("{reset}");
	ft_printf("%d\n", str[index]);
	ft_printf("%d\n", str[index + 1]);
	ft_printf("%d\n", str[index + 2]);
	ft_printf("%d\n", str[index + 3]);
	res = str[index + 3] << 24
		| str[index + 2] << 16
		| str[index + 1] << 8
		| str[index + 0];
	return (res);
}
