/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_sounds.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 13:14:58 by marvin            #+#    #+#             */
/*   Updated: 2020/05/11 15:42:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		check_existing_sounds(t_env *env, char *name)
{
	int i;

	i = 0;
	while (i < NB_SOUNDS)
	{
		if (!(ft_strcmp(name, env->init.sounds_names[i]))
		&& env->init.sounds[i] == 1)
			return (1);
		i++;
	}
	i = 0;
	while (i < NB_MUSICS)
	{
		if (!(ft_strcmp(name, env->init.musics_names[i]))
		&& env->init.musics[i] == 1)
			return (1);
		i++;
	}
	return (0);
}
