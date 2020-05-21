/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dialog_box_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:03:11 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:03:12 by lnicosia         ###   ########.fr       */
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
