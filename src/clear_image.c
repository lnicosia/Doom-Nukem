/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:54:43 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/12 13:37:33 by aherriau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_image(t_env *env)
{
	int y = 0;
	while (y < env->h)
	{
		int x = 0;
		while (x < env->w)
		{
			env->sdl.img_str[x + y * env->w] = 0x000000FF;
			x++;
		}
		y++;
	}
	/*y = h / 2;
	while (y < h)
	{
		int x = 0;
		while (x < w)
		{
			img_str[x + y * w] = 0x222222FF;
			x++;
		}
		y++;
	}*/
}
