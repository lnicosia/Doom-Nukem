/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_menu3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/30 11:15:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 11:15:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "draw.h"

int		start_game_button(t_env *env)
{
	env->start_game_button = new_image_button(ON_RELEASE, &start_game,
		env, env);
	env->start_game_button.pos =
		new_point(env->h_w - env->start_game_button.size_down.x / 2,
		(env->h_h - env->start_game_button.size_down.y / 2) / 2);
	return (0);
}

int		option_menu_ig_button(t_env *env)
{
	env->option_menu_ig = new_image_button(ON_RELEASE, &open_options,
		env, env);
	env->option_menu_ig.pos = new_point(env->h_w - env->option_menu_ig.size_up.x
		/ 2, env->h_h + env->h_h / 4 + env->option_menu_ig.size_up.y);
	return (0);
}

int		exit_button(t_env *env)
{
	env->exit_button = new_image_button(ON_RELEASE, &exit_button_func,
		env, env);
	env->exit_button.pos = new_point(env->h_w - env->exit_button.size_up.x / 2,
		env->h_h + env->h_h / 2 + env->exit_button.size_up.y);
	return (0);
}

int		next_difficulty_button(t_env *env)
{
	env->next_difficulty = new_next_button(ON_RELEASE, &next_difficulty, env,
		env);
	env->next_difficulty.pos = new_point(env->h_w + env->h_w / 2,
		env->h_h + env->next_difficulty.size_down.y);
	return (0);
}

int		prev_difficulty_button(t_env *env)
{
	env->previous_difficulty = new_previous_button(ON_RELEASE,
		&previous_difficulty, env, env);
	env->previous_difficulty.pos = new_point(env->h_w - env->h_w / 2,
		env->h_h + env->previous_difficulty.size_down.y);
	return (0);
}
