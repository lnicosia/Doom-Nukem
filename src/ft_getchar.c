/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:01:55 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/04 17:40:45 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL.h>
#include "libft.h"

/*
**	Returns a string of you keyboard input (+ '\0')
**	according to the shift key
**	TODO
**	Only works with qwerty mac keyboard and SDL inputs
**	Add other possibilities
*/


static char	keypad_numkey2(int input, char res)
{
	if (input == SDLK_KP_9)
		res = '9';
	else if (input == SDLK_KP_PERIOD)
		res = '.';
	else if (input == SDLK_KP_DIVIDE)
		res = '/';
	else if (input == SDLK_KP_MULTIPLY)
		res = '*';
	else if (input == SDLK_KP_EQUALS)
		res = '=';
	else if (input == SDLK_KP_PLUS)
		res = '+';
	else if (input == SDLK_KP_MINUS)
		res = '-';
	return (res);
}

/*
**	Get keys from keypad
*/

static char	keypad_numkey(int input)
{
	char	res;
	
	res = 0;
	if (input == SDLK_KP_0)
		res = '0';
	else if (input == SDLK_KP_1)
		res = '1';
	else if (input == SDLK_KP_2)
		res = '2';
	else if (input == SDLK_KP_3)
		res = '3';
	else if (input == SDLK_KP_4)
		res = '4';
	else if (input == SDLK_KP_5)
		res = '5';
	else if (input == SDLK_KP_6)
		res = '6';
	else if (input == SDLK_KP_7)
		res = '7';
	else if (input == SDLK_KP_8)
		res = '8';
	return (keypad_numkey2(input, res));
}


static char	maj_key2(int input, char res)
{
	if (input == '9')
		res = '(';
	if (input == '0')
		res = ')';
	if (input == '-')
		res = '_';
	if (input == '=')
		res = '+';
	if (input == '[')
		res = '{';
	if (input == ']')
		res = '}';
	if (input == '\\')
		res = '|';
	if (input == ';')
		res = ':';
	if (input == '\'')
		res = '"';
	if (input == ',')
		res = '<';
	if (input == '.')
		res = '>';
	if (input == '/')
		res = '?';
	return (res);
}

/*
**	Get every keyboard input with shift
*/

static char	maj_key(int input)
{
	char	res;

	res = 0;
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
	return (maj_key2(input, res));
}

char		ft_getchar(int input, int shift)
{
	char	res;

	res = '\0';
	if (shift)
		res = maj_key(input);
	else if ((res = keypad_numkey(input)))
		return (res);
	else if (ft_isprint(input))
		res = input;
	return (res);
}
