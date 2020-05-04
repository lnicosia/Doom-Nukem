/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:52:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/19 09:58:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	validate_input3(t_input_box *box, t_env *env)
{
	if (box->type == STRING)
	{
		if (!box->str_target)
			return (custom_error("Error: no string target for input box\n"));
		if (box->str_target)
			ft_strdel(box->str_target);
		if (!(*(box->str_target) = ft_strdup(box->str))
			&& ft_strlen(box->str))
			return (-1);
	}
	if (box->update && box->update(env))
		return (-1);
	box->state = 0;
	return (0);
}

int	validate_input2(t_input_box *box, t_env *env)
{
	if (box->type == DOUBLE)
	{
		if (!box->double_target)
			return (custom_error("Error: no double target for input box\n"));
		*(box->double_target) = ft_atof(box->str);
	}
	else if (box->type == UINT32)
	{
		if (!box->uint32_target)
			return (custom_error("Error: no Uint32 target for input box\n"));
		*(box->uint32_target) = ft_atoi_base(box->str, "0123456789ABCDEF");
	}
	return (validate_input3(box, env));
}

int	validate_input(t_input_box *box, t_env *env)
{
	if (box->check && box->check(env))
	{
		if (update_confirmation_box(&env->confirmation_box, box->error_message,
			ERROR, env))
			return (-1);
		box->state = 0;
		return (0);
	}
	if (box->type == INT)
	{
		if (!box->int_target)
			return (custom_error("Error: no int target for input box\n"));
		*(box->int_target) = ft_atoi(box->str);
	}
	return (validate_input2(box, env));
}
