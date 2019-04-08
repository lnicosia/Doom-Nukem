/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 11:02:11 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/28 17:06:31 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_options(const char *s, int *i, t_data *data)
{
	while (s[*i] == '-' || s[*i] == '+' || s[*i] == '#' || s[*i] == ' '
			|| s[*i] == '0')
	{
		if (s[*i] == '-')
			data->left = 1;
		else if (s[*i] == '+')
			data->plus = 1;
		else if (s[*i] == ' ')
			data->space = 1;
		else if (s[*i] == '#')
			data->sharp = 1;
		else if (s[*i] == '0')
			data->zero = 1;
		(*i)++;
	}
}

void	parse_l_min(const char *s, int *i, t_data *data)
{
	int	nb;

	if (s[*i] >= '1' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->l_min = nb;
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
}

void	parse_prec(const char *s, int *i, t_data *data)
{
	int	nb;

	while (s[*i] == '.')
		(*i)++;
	if (s[*i] >= '0' && s[*i] <= '9')
	{
		nb = pf_atoi(s + *i);
		data->prec = nb;
		while (s[*i] >= '0' && s[*i] <= '9')
			(*i)++;
	}
	else if (s[*i] == '*')
	{
		data->prec = va_arg(data->ap, int);
		if (data->prec < 0)
			data->prec = -1;
		(*i)++;
	}
	else
		data->prec = 0;
}

void	parse_size(const char *s, int *i, t_data *data)
{
	int	l;
	int	h;
	int	lu;

	l = 0;
	h = 0;
	lu = 0;
	while (s[*i] == 'l' || s[*i] == 'h' || s[*i] == 'z' || s[*i] == 'j'
			|| s[*i] == 'L')
	{
		l += (s[*i] == 'l') ? 1 : 0;
		h += (s[*i] == 'h') ? 1 : 0;
		lu += (s[*i] == 'L') ? 1 : 0;
		(*i)++;
	}
	if (l == 0 && h == 0)
		data->size = 4;
	else if (l >= 1)
		data->size = 8;
	else if (h == 1)
		data->size = 2;
	else if (h == 2)
		data->size = 1;
	if (lu >= 1)
		data->size = 16;
}

void	parse_wildcard(int *i, t_data *data)
{
	data->l_min = va_arg(data->ap, int);
	if (data->l_min < 0)
	{
		data->left = 1;
		data->l_min = -data->l_min;
	}
	(*i)++;
}
