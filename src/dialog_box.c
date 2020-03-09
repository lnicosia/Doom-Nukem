/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 15:20:59 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/09 15:41:26 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
**	Finds the maximum number of characters that can fit in one line
**	of the dialog box
*/

int		find_dialog_box_max_char(t_env *env)
{
	char	*str;
	size_t	len;
	t_point	size;

	size = new_point(0, 0);
	len = 0;
	if (!(str = ft_strdup("a")))
		return (-1);
	while (size.x < env->h_w)
	{
		ft_strdel(&str);
		if (!(str = ft_strnew(len)))
			return (-1);
		ft_memset(str, 'a', len);
		TTF_SizeText(env->sdl.fonts.lato_bold30, str, &size.x, &size.y);
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
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	t_point	text_size;

	count = 0;
	while (ft_strlen(*str) && count < env->dialog_box_max_lines)
	{
		if (!(tmp = ft_strsub(*str, 0,
			ft_min(env->dialog_box_line_size, ft_strlen(*str)))))
			return (-1);
		if (ft_strlen(tmp) < ft_strlen(*str))
		{
			if (!(tmp2 = ft_strsub(tmp, 0,
				ft_strlen(tmp) - ft_strlen(ft_strrchr(tmp, ' ')))))
				return (-1);
			ft_strdel(&tmp);
		}
		else
			tmp2 = tmp;
		if (!(tmp3 = ft_strsub(*str, ft_strlen(tmp2),
			ft_strlen(*str) - ft_strlen(tmp2))))
			return (-1);
		ft_strdel(str);
		*str = tmp3;
	//	ft_printf("str = '%s'\n", str);
		TTF_SizeText(env->sdl.fonts.lato_bold30, tmp2, &text_size.x,
		&text_size.y);
		print_text(pos, new_printable_text(tmp2, env->sdl.fonts.lato_bold30,
		0xFFFFFFFF, 0), env);
		ft_strdel(&tmp2);
		pos.x += text_size.y + 5; 
		count++;
	}
	return (0);
}

/*
**	Draw the dialog box with the given string
*/

int		draw_dialog_box(char **str, t_env *env)
{
	t_texture	texture;
	t_point		size;
	t_point		pos;
	t_point		text_size;
	char		*tmp;

	if (!str || !*str || !**str)
		return (0);
	if (!(tmp = ft_strdup(*str)))
		return (-1);
	texture = env->ui_textures[60];
	size = new_point(env->h_w, env->h_w / 3);
	pos = new_point(env->h - size.y + 30, env->h_w - size.x / 2 + 50);
	apply_image(texture, new_point(env->h - size.y, env->h_w - size.x / 2),
	size, env);
	if (ft_strlen(tmp) > env->dialog_box_line_size)
	{
		if (split_text(&tmp, pos, env))
			return (-1);
	}
	else
	{
		TTF_SizeText(env->sdl.fonts.lato_bold30, tmp, &text_size.x,
		&text_size.y);
		print_text(pos, new_printable_text(tmp,
		env->sdl.fonts.lato_bold30, 0xFFf1f2f3, 0), env);
		ft_strdel(&tmp);
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
