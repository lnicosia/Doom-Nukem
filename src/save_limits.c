/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_limits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 17:54:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/30 18:23:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	save_limits(int *ymin, int *ymax, t_render *render, t_env *env)
{
	int	x;

	x = render->xmin;
	while (x <= render->xmax)
	{
		ymin[x] = env->ymin[x];
		ymax[x] = env->ymax[x];
		x++;
	}
	render->ymin = ymin;
	render->ymax = ymax;
}
