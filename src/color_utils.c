/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 17:26:56 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/22 13:55:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

unsigned int	blend_alpha(unsigned int src, unsigned int dest, uint8_t alpha)
{
	return (((dest >> 8 * alpha) / 255 + ((255 - alpha) * src >> 8) / 255) << 8 | 0xFF);
}

unsigned int	blend_add(unsigned int src, unsigned int dest, uint8_t alpha)
{
	return ((src * alpha) / 255 + dest);
}

unsigned int	blend_mul(unsigned int src, unsigned int dest)
{
	return ((src * dest) / 255);
}

Uint32			apply_light(Uint32 color, uint8_t light)
{
	return ((int)((color >> 24 & 0xFF) * light / 255) << 24
		| (int)((color >> 16 & 0xFF) * light / 255) << 16
		| (int)((color >> 8 & 0xFF) * light / 255) << 8
		| (int)((color >> 0 & 0xFF) * light / 255) << 0);
}
