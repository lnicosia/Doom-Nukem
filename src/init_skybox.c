/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_skybox.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:47:08 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/18 19:49:17 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_skybox(t_env *env)
{
	int		j;

	j = 0;
	while (j < 5)
	{
		if (!(env->skybox[j].texture_scale = (t_v2*)malloc(sizeof(t_v2))))
			return (ft_perror("Could not malloc skybox scales"));
		j++;
	}
	return (0);
}
