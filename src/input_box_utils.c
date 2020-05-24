/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:29:15 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 13:36:32 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

int		parse_uint32_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new || !ft_ishexa(new))
		return (0);
	if (ft_strlen(box->str) > 9
		&& !(box->select_start == 0 && box->select_end == ft_strlen(box->str)))
		return (0);
	if (box->select_start < 2)
		box->select_start = 2;
	if (box->select_end < 2)
		box->select_end = 2;
	if (box->cursor <= 1)
		box->cursor = 2;
	if (add_char(box, new))
		return (-1);
	return (0);
}

int		parse_integer_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new)
		return (0);
	if (!ft_isdigit(new))
	{
		if (new != '-' || (new == '-' && box->cursor && (box->select_start != 0
			|| box->select_end != ft_strlen(box->str))))
			return (0);
	}
	if (ft_strlen(box->str) - box->minus >= 9 || (box->minus && !box->cursor))
		return (0);
	if (add_char(box, new))
		return (-1);
	if (new == '-')
		box->minus++;
	if (box->int_count >= 9)
		box->cursor = ft_strlen(box->str);
	return (0);
}

/*
**	Read user input as a string into the input box
**	Light protection, only is_print()
*/

int		parse_str_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new)
		return (0);
	env->sdl.event.key.keysym.sym = 0;
	if (!(ft_isalnum(new) || new == '-' || new == '.' || new == '\''
		|| new == '_' || new == '/' || new == ' ' || new == ','
		|| new == '!'))
		return (0);
	if (add_char(box, new))
		return (-1);
	return (0);
}
