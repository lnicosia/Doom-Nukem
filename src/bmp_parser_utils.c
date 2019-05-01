/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:46:05 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/01 15:25:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "bmp_parser.h"

/*
 **	Read a integer of 32 bits
 **	TODO Better protection
 */

int32_t		read_int32(unsigned char *str, int index)
{
	int32_t		res;

	if (!(str + index) || !(str + index + 1) || !(str + index + 2) || !(str + index + 3))
	{
		ft_printf("String is not well formated. Can not parse int\n");
		return (0);
	}
	res = str[index + 3] << 24
		| str[index + 2] << 16
		| str[index + 1] << 8
		| str[index];
	return (res);
}

/*
 **	Read a integer of 24 bits
 **	TODO Better protection
 */

int32_t		read_int24(unsigned char *str, int index)
{
	int32_t		res;

	if (!(str + index) || !(str + index + 1) || !(str + index + 2) || !(str + index + 3))
	{
		ft_printf("String is not well formated. Can not parse int\n");
		return (0);
	}
	res = str[index + 2] << 24
		| str[index + 1] << 16
		| str[index + 0] << 8
		| 0xFF;
	return (res);
}

/*
**	Read a integer of 16 bits
**	TODO Better protection
*/

int16_t		read_int16(unsigned char *str, int index)
{
	int16_t		res;

	if (!(str + index) || !(str + index + 1))
	{
		ft_printf("String is not well formated. Can not parse int\n");
		return (0);
	}
	res = str[index + 1] << 8
		| str[index];
	return (res);
}
