/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:01:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/04 12:13:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx_keycode.h"

/*
**	Returns a string of you keyboard input (+ '\0')
**	according to the shift key
**	TODO
**	Only works with qwerty mac keyboard and SDL inputs
**	Add other possibilities
*/

static char	maj_key(int input)
{
	char	res;

	if (ft_isalpha(input))
		res = ft_toupper(input);
	if (input == '1')
		res = '!';
	if (input == '2')
		res = '@';
	if (input == '3')
		res = '#';
	if (input == '4')
		res = '$';
	if (input == '5')
		res = '%';
	if (input == '6')
		res = '^';
	if (input == '7')
		res = '&';
	if (input == '8')
		res = '*';
	if (input == '9')
		res = '(';
	if (input == '0')
		res = ')';
	if (input == '-')
		res = '_';
	return (res);
}

char		*ft_getchar(int input, int shift)
{
	static char	res[2];

	res[1] = '\0';
	if (shift)
		res[0] = maj_key(input);
	else
		res[0] = input;
	return (res);
}
