/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_hud_buttons.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 13:52:01 by sipatry           #+#    #+#             */
/*   Updated: 2020/04/29 18:09:02 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	next_ambiance_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.ambient_music < NB_MUSICS - 1)
		env->sound.ambient_music++;
	return (0);
}

int	previous_ambiance_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.ambient_music > 0)
		env->sound.ambient_music--;
	return (0);
}

int	next_fighting_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.fight_music < NB_MUSICS - 1)
		env->sound.fight_music++;
	return (0);
}

int	previous_fighting_music(void *target)
{
	t_env	*env;

	env = (t_env *)target;
	if (env->sound.fight_music > 0)
		env->sound.fight_music--;
	return (0);
}
