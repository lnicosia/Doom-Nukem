/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:26:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/04 10:51:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

unsigned int	blend_alpha(unsigned int src, unsigned int dest, uint8_t alpha)
{
	int	aalpha;

	aalpha = 255 - alpha;
	//return (((dest >> 16 * alpha) / 255 + ((255 - alpha) * src >> 16) / 255) << 16);
	//return ((alpha * src) / 255 + ((255 - alpha) * dest) / 255);
	return (
	(aalpha * (src >> 16 & 0xFF) / 255 + alpha * (dest >> 16 & 0xFF) / 255) << 16
	| (aalpha * (src >> 8 & 0xFF) / 255 + alpha * (dest >> 8 & 0xFF) / 255) << 8
	| (aalpha * (src & 0xFF) / 255 + alpha * (dest & 0xFF) / 255));
}

unsigned int	blend_add(unsigned int src, unsigned int dest, uint8_t alpha)
{
	return ((src * alpha) / 255 + dest);
}

unsigned int	blend_mul(unsigned int src, unsigned int dest)
{
	return ((src * dest) / 255);
}

Uint32			apply_light(Uint32 color, double light)
{
	return (
		(int)((color >> 16 & 0xFF) * light) << 16
		| (int)((color >> 8 & 0xFF) * light) << 8
		| (int)((color >> 0 & 0xFF) * light) << 0);
}
