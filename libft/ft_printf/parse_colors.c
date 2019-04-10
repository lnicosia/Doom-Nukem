/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:03:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/28 17:28:36 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "color.h"

void	put_colors_2(const char *s, int *i, t_data *data)
{
	if (pf_strnequ(s + *i, "{yellow}", 8) == 1)
	{
		fill_buffer(data, YELLOW, 7);
		(*i) += 7;
	}
	else if (pf_strnequ(s + *i, "{blue}", 6) == 1)
	{
		fill_buffer(data, BLUE, 7);
		(*i) += 5;
	}
	else if (pf_strnequ(s + *i, "{magenta}", 9) == 1)
	{
		fill_buffer(data, MAGENTA, 7);
		(*i) += 8;
	}
}

void	put_colors(const char *s, int *i, t_data *data)
{
	if (pf_strnequ(s + *i, "{red}", 5) == 1)
	{
		fill_buffer(data, RED, 7);
		(*i) += 4;
	}
	else if (pf_strnequ(s + *i, "{green}", 7) == 1)
	{
		fill_buffer(data, GREEN, 7);
		(*i) += 6;
	}
	else if (pf_strnequ(s + *i, "{cyan}", 6) == 1)
	{
		fill_buffer(data, CYAN, 7);
		(*i) += 5;
	}
	else if (pf_strnequ(s + *i, "{reset}", 7) == 1)
	{
		fill_buffer(data, RESET, 4);
		(*i) += 6;
	}
	else
		put_colors_2(s, i, data);
}

void	parse_color(const char *s, int *i, t_data *data)
{
	if (pf_strnequ(s + *i, "{red}", 5) == 1
			|| pf_strnequ(s + *i, "{green}", 7) == 1
			|| pf_strnequ(s + *i, "{cyan}", 6) == 1
			|| pf_strnequ(s + *i, "{reset}", 7) == 1
			|| pf_strnequ(s + *i, "{yellow}", 8) == 1
			|| pf_strnequ(s + *i, "{blue}", 6) == 1
			|| pf_strnequ(s + *i, "{magenta}", 9) == 1)
	{
		if ((*i > 0 && s[*i - 1] != '{') || *i == 0)
			put_colors(s, i, data);
	}
	else
		fill_buffer(data, s + *i, 1);
}
