/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:50:28 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/27 16:06:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

unsigned int	blend_alpha(unsigned int src, unsigned int dest, uint8_t alpha)
{
	int	aalpha;

	aalpha = 256 - alpha;
	return (
	(aalpha * (src >> 16 & 0xFF) / 256 + alpha * (dest >> 16 & 0xFF) / 256) << 16
	| (aalpha * (src >> 8 & 0xFF) / 256 + alpha * (dest >> 8 & 0xFF) / 256) << 8
	| (aalpha * (src & 0xFF) / 256 + alpha * (dest & 0xFF) / 256));
	/*return (
	(aalpha * (src >> 16 & 0xFF) + alpha * (dest >> 16 & 0xFF)) / 256 << 16
	| (aalpha * (src >> 8 & 0xFF) + alpha * (dest >> 8 & 0xFF)) / 265 << 8
	| (aalpha * (src & 0xFF) + alpha * (dest & 0xFF)) / 256);*/
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
	//src = blend_alpha(src, color, 16);
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
