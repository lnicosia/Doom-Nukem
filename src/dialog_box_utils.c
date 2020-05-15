/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_box_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:03:11 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/15 22:17:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		size_protection(t_env *env, size_t len, t_point size, char **str)
{
	char *res;

	if (!(res = ft_strnew(0)))
		return (0);
	if (size.x >= env->h_w - 70)
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(*str, 0, len - 2)))
			return (0);
	}
	return (1);
}

char	*get_current_line(char **str, t_env *env)
{
	size_t	len;
	char	*res;
	t_point	size;

	size = new_point(0, 0);
	len = 1;
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
	if (!(size_protection(env, len, size, str)))
		return (0);
	return (res);
}

int		dialog_event(void *param, void *penv)
{
	t_env	*env;

	env = (t_env*)penv;
	if (env->dialog_box_str)
		ft_strdel(&env->dialog_box_str);
	if (!(env->dialog_box_str = ft_strdup((char*)param)))
		return (-1);
	env->dialog_box = 1;
	return (1);
}

/*
**	Finds the maximum number of 'a' characters that can fit in one line
**	of the dialog box
*/

int		find_dialog_box_max_char(t_env *env)
{
	char	*str;
	size_t	len;
	t_point	size;

	size = new_point(0, 0);
	len = 1;
	if (!(str = ft_strnew(0)))
		return (-1);
	while (size.x < env->h_w - 70)
	{
		ft_strdel(&str);
		if (!(str = ft_strnew(len)))
			return (-1);
		ft_memset(str, 'a', len);
		if (TTF_SizeText(env->sdl.fonts.lato_bold30, str, &size.x, &size.y))
		{
			ft_strdel(&str);
			return (-1);
		}
		len++;
	}
	ft_strdel(&str);
	env->dialog_box_line_size = len;
	env->dialog_box_max_lines = (env->h_w / 3.0 - 60) / (double)size.y;
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
