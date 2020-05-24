/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_existing_files2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 20:38:13 by marvin            #+#    #+#             */
/*   Updated: 2020/05/20 20:53:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		skyboxes_textures(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < MAX_SKYBOX * 6)
	{
		if (!(ft_strcmp(name, env->init.skyboxes_names[i]))
		&& env->init.skyboxes[i] == 1)
			return (1);
		i++;
	}
	return (0);
}

int		hud_textures(t_env *env, char *name)
{
	int	i;

	i = 0;
	while (i < NB_HUD_FILES)
	{
		if (!(ft_strcmp(name, env->init.hud_names[i]))
		&& env->init.hud[i] == 1)
			return (1);
		i++;
	}
	return (0);
}
