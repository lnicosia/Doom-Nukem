/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 18:04:28 by marvin            #+#    #+#             */
/*   Updated: 2020/05/18 19:39:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"
#include "draw.h"

void	draw_selection(t_point pos, t_point size1, t_point size2, t_env *env)
{
	int		x;
	int		y;

	y = pos.x;
	while (y < pos.x + size2.y)
	{
		x = pos.y + size1.x;
		while (x < pos.y + size1.x + size2.x)
		{
			env->sdl.texture_pixels[x + y * env->w] = 0xFF71B3D1;
			x++;
		}
		y++;
	}
}

int		check_res(char **res, char *str, int len)
{
	ft_strdel(res);
	if (!(*res = ft_strsub(str, 0, len - 2)))
		return (0);
	return (1);
}

char	*get_current_box_line(t_input_box *box, char *str)
{
	size_t	len;
	char	*res;
	t_point	size;

	size = new_point(0, 0);
	len = 1;
	if (!(res = ft_strnew(0)))
		return (0);
	while (size.x < box->size.x * 0.99 && ++len <= ft_strlen(str))
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(str, 0, len)))
			return (0);
		if (TTF_SizeText(box->font, res, &size.x, &size.y))
		{
			ft_strdel(&res);
			return (0);
		}
	}
	if (size.x >= box->size.x * 0.99)
	{
		if (!(check_res(&res, str, len)))
			return (0);
	}
	return (res);
}
