/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:20:59 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/21 18:44:58 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Find the largest string of the current text characters that fit in one line
*/

char	*get_current_line(char **str, t_env *env, size_t len)
{
	char	*res;
	t_point	size;

	size = new_point(0, 0);
	if (!(res = ft_strnew(0)))
		return (0);
	while (size.x < env->h_w - 70 && len <= ft_strlen(*str))
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(*str, 0, len)))
			return (0);
		if (TTF_SizeText(env->sdl.fonts.lato_bold30, res, &size.x, &size.y))
		{
			ft_strdel(&res);
			return (0);
		}
		len++;
	}
	if (size.x >= env->h_w - 70)
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(*str, 0, len - 2)))
			return (0);
	}
	return (res);
}

int		print_line_text(t_point *pos, t_point *text_size, char *tmp2,
t_env *env)
{
	if (TTF_SizeText(env->sdl.fonts.lato_bold30, tmp2, &text_size->x,
		&text_size->y))
		return (-1);
	if (print_text(*pos, new_printable_text(tmp2, env->sdl.fonts.lato_bold30,
		0xFFFFFFFF, 0), env))
		return (-1);
	return (0);
}

/*
**	If the string is too big to fit in one line
**	Prints the text in multiple lines
*/

int		split_text(char **str, t_point pos, t_env *env)
{
	int		count;
	t_point	text_size;

	count = 0;
	text_size.x = 0;
	text_size.y = 0;
	while (ft_strlen(*str) && pos.x + text_size.y <= env->h)
	{
		if (compute_current_line(str, &pos, &text_size, env))
			return (-1);
		pos.x += text_size.y + 5;
		count++;
	}
	return (0);
}

/*
**	Draw the dialog box with the given string
*/

int		draw_dialog_box2(char **str, t_env *env, char *tmp, t_point pos)
{
	if (split_text(&tmp, pos, env))
	{
		ft_strdel(&tmp);
		return (-1);
	}
	if (env->next_dialog)
	{
		ft_strdel(str);
		*str = tmp;
		env->next_dialog = 0;
	}
	else
		ft_strdel(&tmp);
	return (0);
}

int		draw_dialog_box(char **str, t_env *env)
{
	t_texture	texture;
	t_point		size;
	t_point		pos;
	char		*tmp;

	if (!str || !*str || !**str)
		return (0);
	if (!(tmp = ft_strdup(*str)))
		return (-1);
	texture = env->ui_textures[60];
	size = new_point(env->h_w, env->h_w / 3);
	pos = new_point(env->h - size.y + 30, env->h_w - size.x / 2 + 35);
	apply_image(texture, new_point(env->h - size.y, env->h_w - size.x / 2),
	size, env);
	return (draw_dialog_box2(str, env, tmp, pos));
}
