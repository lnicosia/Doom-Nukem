/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 12:12:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/12 16:55:40 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "collision.h"
#include "events_parser.h"

int		check_true_false_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value != 0 && value != 1)
		return (1);
	return (0);
}

int		check_portal_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value != 0 && value != 1)
		return (1);
	if (intersects_with_wall_no_portal_check(&env->
		sectors[env->editor.selected_sector], env->player.pos,
	env->editor.selected_wall, env))
		return (1);
	return (0);
}

int		check_health_input_box(void *penv)
{
	int		value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atoi(env->input_box.str);
	if (value <= 0 || value >= 10000)
		return (1);
	return (0);
}

int		check_speed_input_box(void *penv)
{
	double	value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atof(env->input_box.str);
	if (value < 0 || value > 100)
		return (1);
	return (0);
}

int		check_angle_input_box(void *penv)
{
	double	value;
	t_env	*env;

	env = (t_env*)penv;
	value = ft_atof(env->input_box.str);
	if (value < 0 || value > 360)
		return (1);
	return (0);
}
