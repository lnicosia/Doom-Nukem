/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:26:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/12 10:51:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

unsigned int	blend_alpha(unsigned int src, unsigned int dest, uint8_t alpha)
{
	int	aalpha;

	aalpha = 255 - alpha;
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

Uint32			apply_light(Uint32 src, Uint32 color, short brightness)
{
	(void)color;
	//src = blend_alpha(src, color, 75);
	if (!brightness)
		return (src);
	if (brightness > 0)
		src = blend_alpha(src, 0xFFFFFFFF, brightness);
	if (brightness < 0)
		src = blend_alpha(src, 0, -brightness);
	return (src);
/*	return (
		(int)((src >> 16 & 0xFF) * brightness / 255) << 16
		| (int)((src >> 8 & 0xFF) * brightness / 255) << 8
		| (int)((src >> 0 & 0xFF) * brightness / 255) << 0);
	return (
		(int)((src >> 16 & 0xFF) * brightness / 25) << 16
		| (int)((src >> 8 & 0xFF) * brightness / 255) << 8
		| (int)((src >> 0 & 0xFF) * brightness / 255) << 0);*/
	/*int	abrightness;

	abrightness = 255 - brightness;
	return (
	(abrightness * (src >> 16 & 0xFF) / 255 + brightness * (color >> 16 & 0xFF) / 255) << 16
	| (abrightness * (src >> 8 & 0xFF) / 255 + brightness * (color >> 8 & 0xFF) / 255) << 8
	| (abrightness * (src & 0xFF) / 255 + brightness * (color & 0xFF) / 255));*/
}
