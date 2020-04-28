/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   bmp_parser_utils.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/30 14:46:05 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/07/24 14:55:24 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

uint32_t		read_color16(unsigned char *str, int index)
{
	uint32_t		res;

	res = str[index + 1] << 8
		| str[index];
	return (res);
}

/*
**	Read a integer of 8 bits
**	TODO Better protection
*/

uint32_t		read_color8(unsigned char *str, int index, t_bmp_parser *parser)
{
	int	res;

	if (parser->color_used)
		return (parser->colors[str[index]]);
	res =  (str[(int)index] >> 0 & 7) << 24
		| (str[(int)index] >> 6 & 7) << 16
		| (str[(int)index] >> 3 & 7) << 8
		| 0xFF;
	ft_printf("color = 0x%x\n", res);
	return (res);
}

/*
**	Read a integer of 4 bits
**	TODO Better protection
*/

uint32_t		read_color4(unsigned char *str, double index,
unsigned int *colors)
{
	double	trash;

	if (modf(index, &trash) == 0)
		return (colors[str[(int)index] >> 4 & 0xF]);
	else if (modf(index, &trash) == 0.5)
		return (colors[str[(int)index] & 0xF]);
	return (colors[0]);
}

/*
**	Read a integer of 1 bits
**	TODO Better protection
*/

uint32_t		read_color1(unsigned char *str, double index,
unsigned int *colors)
{
	double	trash;

	if (modf(index, &trash) == 0)
		return (colors[str[(int)index] >> 7 & 1]);
	else if (modf(index, &trash) == 0.125)
		return (colors[str[(int)index] >> 6 & 1]);
	else if (modf(index, &trash) == 0.25)
		return (colors[str[(int)index] >> 5 & 1]);
	else if (modf(index, &trash) == 0.375)
		return (colors[str[(int)index] >> 4 & 1]);
	else if (modf(index, &trash) == 0.5)
		return (colors[str[(int)index] >> 3 & 1]);
	else if (modf(index, &trash) == 0.625)
		return (colors[str[(int)index] >> 2 & 1]);
	else if (modf(index, &trash) == 0.75)
		return (colors[str[(int)index] >> 1 & 1]);
	else if (modf(index, &trash) == 0.875)
		return (colors[str[(int)index] >> 0 & 1]);
	return (colors[0]);
}
