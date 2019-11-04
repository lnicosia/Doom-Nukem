/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:29:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/04 12:12:54 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_box_utils.h"

int		parse_integer_input(t_input_box *box, t_env *env)
{
	(void)box;
	(void)env;
	return (0);
}

int		parse_double_input(t_input_box *box, t_env *env)
{
	(void)box;
	(void)env;
	return (0);
}

/*
**	Read user input as a string into the input box
**	Light protection, only is_print()
*/

int		parse_str_input(t_input_box *box, t_env *env)
{
	char	*new;

	if (env->sdl.event.key.keysym.sym == SDLK_KP_0)
		ft_printf("input = %d\n", env->sdl.event.key.keysym.sym);
	if (ft_isprint(env->sdl.event.key.keysym.sym))
	{
		/*if (env->sdl.event.key.keysym.sym >= SDLK_KP_0
			&& env->sdl.event.key.keysym.sym <= SDLK_KP_1)
			ft_printf("input = %d\n", env->sdl.event.key.keysym.sym);*/
		new = ft_getchar(env->sdl.event.key.keysym.sym,
		env->inputs.shift);
		if (!box->str || (box->str && box->str[0] == '|'))
		{
			if (box->str)
				ft_strdel(&box->str);
			if (!(box->str = ft_strdup(new)))
				return (-1);
		}
		else if (!(box->str = ft_strjoin_free(box->str, new)))
			return (-1);
		env->sdl.event.key.keysym.sym = 0;
	}
	return (0);
}
