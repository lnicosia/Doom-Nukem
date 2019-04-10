/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:40:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/28 17:06:55 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	return_char(const char *s, int *i, t_data *data)
{
	if (s[*i] != 'd' && s[*i] != 'i' && s[*i] != 'o' && s[*i] != 'u'
			&& s[*i] != 'x' && s[*i] != 'X' && s[*i] != 'f' && s[*i] != 'c'
			&& s[*i] != 's' && s[*i] != 'p' && s[*i] != '%' && s[*i] != 'O'
			&& s[*i] != 'U' && s[*i] != 'D' && s[*i] != 'C' && s[*i] != 'S'
			&& s[*i] != 'F' && s[*i] != 'b')
	{
		data->invalid = s + *i;
		if (s[*i] == '\0')
			(*i)--;
		return (0);
	}
	return (s[*i]);
}

char		parse_flags(const char *s, int *i, t_data *data)
{
	while (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
			|| s[*i] == '.' || s[*i] == '-' || s[*i] == '+' || s[*i] == '#'
			|| s[*i] == ' ' || (s[*i] >= '0' && s[*i] <= '9') || s[*i] == 'L'
			|| s[*i] == '*')
	{
		if (s[*i] == '-' || s[*i] == '+' || s[*i] == '#' || s[*i] == ' '
				|| s[*i] == '0')
			parse_options(s, i, data);
		if (s[*i] >= '1' && s[*i] <= '9')
			parse_l_min(s, i, data);
		if (s[*i] == '.')
			parse_prec(s, i, data);
		if (s[*i] == '*')
			parse_wildcard(i, data);
		if (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
				|| s[*i] == 'L')
			parse_size(s, i, data);
	}
	return (return_char(s, i, data));
}
