/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/02 17:00:39 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int			init_sprites(t_env *env)
{
	if (!(env->sprites = (t_sprite*)malloc(sizeof(t_sprite) * 3)))
		return (ft_printf("Could not malloc sprites\n"));
	env->sprites[0].texture = 33;
	env->sprites[0].death_counterpart = 0;
	env->sprites[0].oriented = 0;
	env->sprites[0].reversed[0] = 0;
	env->sprites[0].start[0].x = 511;
	env->sprites[0].start[0].y = 78;
	env->sprites[0].end[0].x = 562;
	env->sprites[0].end[0].y = 102;
	env->sprites[0].size[0].x = 51;
	env->sprites[0].size[0].y = 24;
	env->sprites[0].width = 2;
	env->sprites[0].height = 2;

	// Sprite oriente
	env->sprites[1].texture = 34;
	env->sprites[1].death_counterpart = 2;
	env->sprites[1].oriented = 1;
	env->sprites[1].width = 2;
	env->sprites[1].height = 2;

	env->sprites[1].start[0].x = 44;
	env->sprites[1].start[0].y = 120;
	env->sprites[1].end[0].x = 87;
	env->sprites[1].end[0].y = 165;
	env->sprites[1].size[0].x = 44;
	env->sprites[1].size[0].y = 46;
	env->sprites[1].reversed[0] = 0;

	env->sprites[1].start[1].x = 374;
	env->sprites[1].start[1].y = 120;
	env->sprites[1].end[1].x = 405;
	env->sprites[1].end[1].y = 172;
	env->sprites[1].size[1].x = 32;
	env->sprites[1].size[1].y = 53;
	env->sprites[1].reversed[1] = 0;

	env->sprites[1].start[2].x = 299;
	env->sprites[1].start[2].y = 120;
	env->sprites[1].end[2].x = 329;
	env->sprites[1].end[2].y = 173;
	env->sprites[1].size[2].x = 31;
	env->sprites[1].size[2].y = 54;
	env->sprites[1].reversed[2] = 0;

	env->sprites[1].start[3].x = 220;
	env->sprites[1].start[3].y = 120;
	env->sprites[1].end[3].x = 254;
	env->sprites[1].end[3].y = 171;
	env->sprites[1].size[3].x = 35;
	env->sprites[1].size[3].y = 52;
	env->sprites[1].reversed[3] = 0;

	env->sprites[1].start[4].x = 132;
	env->sprites[1].start[4].y = 120;
	env->sprites[1].end[4].x = 175;
	env->sprites[1].end[4].y = 165;
	env->sprites[1].size[4].x = 44;
	env->sprites[1].size[4].y = 46;
	env->sprites[1].reversed[4] = 0;

	env->sprites[1].start[5].x = 220;
	env->sprites[1].start[5].y = 120;
	env->sprites[1].end[5].x = 254;
	env->sprites[1].end[5].y = 171;
	env->sprites[1].size[5].x = 35;
	env->sprites[1].size[5].y = 52;
	env->sprites[1].reversed[5] = 1;

	env->sprites[1].start[6].x = 299;
	env->sprites[1].start[6].y = 120;
	env->sprites[1].end[6].x = 329;
	env->sprites[1].end[6].y = 173;
	env->sprites[1].size[6].x = 31;
	env->sprites[1].size[6].y = 54;
	env->sprites[1].reversed[6] = 1;

	env->sprites[1].start[7].x = 374;
	env->sprites[1].start[7].y = 120;
	env->sprites[1].end[7].x = 405;
	env->sprites[1].end[7].y = 172;
	env->sprites[1].size[7].x = 32;
	env->sprites[1].size[7].y = 53;
	env->sprites[1].reversed[7] = 1;

	// sprites de deces du precedent
	env->sprites[2].texture = 34;
	env->sprites[2].death_counterpart = 2;
	env->sprites[2].oriented = 0;
	env->sprites[2].width = 2;
	env->sprites[2].height = 2;

	env->sprites[2].start[0].x = 44;
	env->sprites[2].start[0].y = 448;
	env->sprites[2].end[0].x = 77;
	env->sprites[2].end[0].y = 498;
	env->sprites[2].size[0].x = 34;
	env->sprites[2].size[0].y = 51;
	env->sprites[2].reversed[0] = 0;

	env->sprites[2].start[1].x = 122;
	env->sprites[2].start[1].y = 448;
	env->sprites[2].end[1].x = 157;
	env->sprites[2].end[1].y = 500;
	env->sprites[2].size[1].x = 36;
	env->sprites[2].size[1].y = 53;
	env->sprites[2].reversed[1] = 0;

	env->sprites[2].start[2].x = 202;
	env->sprites[2].start[2].y = 448;
	env->sprites[2].end[2].x = 246;
	env->sprites[2].end[2].y = 495;
	env->sprites[2].size[2].x = 45;
	env->sprites[2].size[2].y = 48;
	env->sprites[2].reversed[2] = 0;

	env->sprites[2].start[3].x = 291;
	env->sprites[2].start[3].y = 448;
	env->sprites[2].end[3].x = 358;
	env->sprites[2].end[3].y = 507;
	env->sprites[2].size[3].x = 68;
	env->sprites[2].size[3].y = 60;
	env->sprites[2].reversed[3] = 0;

	env->sprites[2].start[4].x = 403;
	env->sprites[2].start[4].y = 448;
	env->sprites[2].end[4].x = 490;
	env->sprites[2].end[4].y = 519;
	env->sprites[2].size[4].x = 88;
	env->sprites[2].size[4].y = 72;
	env->sprites[2].reversed[4] = 0;

	env->sprites[2].start[5].x = 535;
	env->sprites[2].start[5].y = 448;
	env->sprites[2].end[5].x = 637;
	env->sprites[2].end[5].y = 537;
	env->sprites[2].size[5].x = 103;
	env->sprites[2].size[5].y = 90;
	env->sprites[2].reversed[5] = 0;
	return (0);
}
