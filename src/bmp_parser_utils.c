/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 14:46:05 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/02 12:27:07 by lnicosia         ###   ########.fr       */
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

int32_t		read_int16(unsigned char *str, int index)
{
	int32_t		res;

	if (!(str + index) || !(str + index + 1))
	{
		ft_printf("String is not well formated. Can not parse int\n");
		return (0);
	}
	res = str[index + 1] << 8
		| str[index];
	return (res);
}

/*
**	Read a integer of 8 bits
**	TODO Better protection
*/

int32_t		read_int8(unsigned char *str, int index)
{
	if (!(str + index))
	{
		ft_printf("String is not well formated. Can not parse int\n");
		return (0);
	}
	return (str[index] | 0xFF);
}

/*
**	Read a integer of 4 bits
**	TODO Better protection
*/

int32_t		read_int4(unsigned char *str, double index)
{
	int32_t		res;

	(void)str;
	(void)index;
	res = 0;
	return (res);
}

/*
**	Read a integer of 1 bits
**	TODO Better protection
*/

int32_t		read_int1(unsigned char *str, double index)
{
	double	trash;

	if (modf(index, &trash) == 0)
	{
		if (str[(int)index] >> 7 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.125)
	{
		if (str[(int)index] >> 6 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.25)
	{
		if (str[(int)index] >> 5 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.375)
	{
		if (str[(int)index] >> 4 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.5)
	{
		if (str[(int)index] >> 3 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.625)
	{
		if (str[(int)index] >> 2 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.75)
	{
		if (str[(int)index] >> 1 & 1)
			return (0xFFFFFFFF);
	}
	else if (modf(index, &trash) == 0.875)
	{
		if (str[(int)index] >> 0 & 1)
			return (0xFFFFFFFF);
	}
	return (0xFF);
}
