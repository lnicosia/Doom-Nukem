/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:50:28 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/28 11:46:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

unsigned int	blend_alpha(unsigned int src, unsigned int dest, uint8_t alpha)
{
	int	aalpha;

	aalpha = 256 - alpha;
	return (
	((aalpha * (src >> 16 & 0xFF) + alpha * (dest >> 16 & 0xFF)) / 256) << 16
	| ((aalpha * (src >> 8 & 0xFF) + alpha * (dest >> 8 & 0xFF)) / 256) << 8
	| ((aalpha * (src & 0xFF) + alpha * (dest & 0xFF)) / 256));
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

Uint32			apply_lightl(Uint32 src, Uint32 color, short brightness)
{
	int	aalpha;
	int	alpha;
	Uint32	dest;

	alpha = 64;
	aalpha = 256 - alpha;
	dest = color;
	if (!brightness && color == 0xFFFFFFFF)
		return (src);
	src = ft_clamp((aalpha * (src >> 16 & 0xFF) + alpha * (dest >> 16 & 0xFF)) / 256, 0, 255) << 16
	| ft_clamp((aalpha * (src >> 8 & 0xFF) + alpha * (dest >> 8 & 0xFF)) / 256, 0, 255) << 8
	| ft_clamp((aalpha * (src & 0xFF) + alpha * (dest & 0xFF)) / 256, 0, 255);
	return (src);
}

Uint32			apply_light(Uint32 src, Uint32 color, short brightness)
{
	(void)color;
	if (!brightness)
		return (src);
	if (brightness > 0)
		src = blend_alpha(src, 0xFFFFFFFF, brightness);
	if (brightness < 0)
		src = blend_alpha(src, 0, -brightness);
	return (src);
}
