/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/19 17:01:26 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int			init_wall_sprites(t_env *env)
{
	if (!(env->wall_sprites = (t_sprite*)malloc(sizeof(t_sprite) * 1)))
		return (ft_printf("Could not malloc enemy_sprites\n"));
	
	// Grille
	env->wall_sprites[0].texture = 31;
	env->wall_sprites[0].death_counterpart = 0;
	env->wall_sprites[0].pursuit_sprite = 0;
	env->wall_sprites[0].rest_sprite = 0;
	env->wall_sprites[0].curr_sprite = 0;
	env->wall_sprites[0].oriented = 0;
	env->wall_sprites[0].nb_death_sprites = 9;
	env->wall_sprites[0].start[0].x = 0;
	env->wall_sprites[0].start[0].y = 0;
	env->wall_sprites[0].end[0].x = 128;
	env->wall_sprites[0].end[0].y = 256;
	env->wall_sprites[0].size[0].x = 128;
	env->wall_sprites[0].size[0].y = 256;
	env->wall_sprites[0].reversed[0] = 0;
	return (0);
}

int			init_object_sprites(t_env *env)
{
	if (!(env->object_sprites = (t_sprite*)malloc(sizeof(t_sprite) * 2)))
		return (ft_printf("Could not malloc enemy_sprites\n"));
	
	//	objects sprite sheet
	env->object_sprites[0].texture = 22;
	env->object_sprites[0].death_counterpart = 0;
	env->object_sprites[0].oriented = 0;
	env->object_sprites[0].rest_sprite = 0;
	env->object_sprites[0].reversed[0] = 0;
	env->object_sprites[0].start[0].x = 511;
	env->object_sprites[0].start[0].y = 78;
	env->object_sprites[0].end[0].x = 562;
	env->object_sprites[0].end[0].y = 102;
	env->object_sprites[0].size[0].x = 51;
	env->object_sprites[0].size[0].y = 24;
	
		// rocket enemy_sprites
	env->object_sprites[1].texture = 25;
	env->object_sprites[1].death_counterpart = 1;
	env->object_sprites[1].pursuit_sprite = 1;
	env->object_sprites[1].firing_sprite = 1;
	env->object_sprites[1].rest_sprite = 1;
	env->object_sprites[1].curr_sprite = 1;
	env->object_sprites[1].oriented = 1;
	env->object_sprites[1].nb_death_sprites = 8;

	env->object_sprites[1].start[0].x = 1;
	env->object_sprites[1].start[0].y = 817;
	env->object_sprites[1].end[0].x = 15;
	env->object_sprites[1].end[0].y = 830;
	env->object_sprites[1].size[0].x = 15;
	env->object_sprites[1].size[0].y = 14;
	env->object_sprites[1].reversed[0] = 0;

	env->object_sprites[1].start[1].x = 110;
	env->object_sprites[1].start[1].y = 817;
	env->object_sprites[1].end[1].x = 141;
	env->object_sprites[1].end[1].y = 830;
	env->object_sprites[1].size[1].x = 32;
	env->object_sprites[1].size[1].y = 14;
	env->object_sprites[1].reversed[1] = 0;

	env->object_sprites[1].start[2].x = 60;
	env->object_sprites[1].start[2].y = 817;
	env->object_sprites[1].end[2].x = 108;
	env->object_sprites[1].end[2].y = 830;
	env->object_sprites[1].size[2].x = 49;
	env->object_sprites[1].size[2].y = 14;
	env->object_sprites[1].reversed[2] = 0;

	env->object_sprites[1].start[3].x = 33;
	env->object_sprites[1].start[3].y = 817;
	env->object_sprites[1].end[3].x = 58;
	env->object_sprites[1].end[3].y = 830;
	env->object_sprites[1].size[3].x = 26;
	env->object_sprites[1].size[3].y = 14;
	env->object_sprites[1].reversed[3] = 0;

	env->object_sprites[1].start[4].x = 17;
	env->object_sprites[1].start[4].y = 817;
	env->object_sprites[1].end[4].x = 31;
	env->object_sprites[1].end[4].y = 830;
	env->object_sprites[1].size[4].x = 15;
	env->object_sprites[1].size[4].y = 14;
	env->object_sprites[1].reversed[4] = 0;

	env->object_sprites[1].start[5].x = 33;
	env->object_sprites[1].start[5].y = 817;
	env->object_sprites[1].end[5].x = 58;
	env->object_sprites[1].end[5].y = 830;
	env->object_sprites[1].size[5].x = 26;
	env->object_sprites[1].size[5].y = 14;
	env->object_sprites[1].reversed[5] = 1;

	env->object_sprites[1].start[6].x = 60;
	env->object_sprites[1].start[6].y = 817;
	env->object_sprites[1].end[6].x = 108;
	env->object_sprites[1].end[6].y = 830;
	env->object_sprites[1].size[6].x = 49;
	env->object_sprites[1].size[6].y = 14;
	env->object_sprites[1].reversed[6] = 1;

	env->object_sprites[1].start[7].x = 110;
	env->object_sprites[1].start[7].y = 817;
	env->object_sprites[1].end[7].x = 141;
	env->object_sprites[1].end[7].y = 830;
	env->object_sprites[1].size[7].x = 32;
	env->object_sprites[1].size[7].y = 14;
	env->object_sprites[1].reversed[7] = 1;
	
	return (0);
}
int			init_enemy_sprites(t_env *env)
{
	if (!(env->enemy_sprites = (t_sprite*)malloc(sizeof(t_sprite) * 10)))
		return (ft_printf("Could not malloc enemy_sprites\n"));

	// Sprite oriente, lost soul
	env->enemy_sprites[0].texture = 23;
	env->enemy_sprites[0].death_counterpart = 4;
	env->enemy_sprites[0].pursuit_sprite = 2;
	env->enemy_sprites[0].firing_sprite = 2;
	env->enemy_sprites[0].rest_sprite = 1;
	env->enemy_sprites[0].curr_sprite = 0;
	env->enemy_sprites[0].oriented = 1;
	env->enemy_sprites[0].nb_death_sprites = 6;

	env->enemy_sprites[0].start[0].x = 44;
	env->enemy_sprites[0].start[0].y = 120;
	env->enemy_sprites[0].end[0].x = 87;
	env->enemy_sprites[0].end[0].y = 165;
	env->enemy_sprites[0].size[0].x = 44;
	env->enemy_sprites[0].size[0].y = 46;
	env->enemy_sprites[0].reversed[0] = 0;

	env->enemy_sprites[0].start[1].x = 374;
	env->enemy_sprites[0].start[1].y = 120;
	env->enemy_sprites[0].end[1].x = 405;
	env->enemy_sprites[0].end[1].y = 172;
	env->enemy_sprites[0].size[1].x = 32;
	env->enemy_sprites[0].size[1].y = 53;
	env->enemy_sprites[0].reversed[1] = 0;

	env->enemy_sprites[0].start[2].x = 299;
	env->enemy_sprites[0].start[2].y = 120;
	env->enemy_sprites[0].end[2].x = 329;
	env->enemy_sprites[0].end[2].y = 173;
	env->enemy_sprites[0].size[2].x = 31;
	env->enemy_sprites[0].size[2].y = 54;
	env->enemy_sprites[0].reversed[2] = 0;

	env->enemy_sprites[0].start[3].x = 220;
	env->enemy_sprites[0].start[3].y = 120;
	env->enemy_sprites[0].end[3].x = 254;
	env->enemy_sprites[0].end[3].y = 171;
	env->enemy_sprites[0].size[3].x = 35;
	env->enemy_sprites[0].size[3].y = 52;
	env->enemy_sprites[0].reversed[3] = 0;

	env->enemy_sprites[0].start[4].x = 132;
	env->enemy_sprites[0].start[4].y = 120;
	env->enemy_sprites[0].end[4].x = 175;
	env->enemy_sprites[0].end[4].y = 165;
	env->enemy_sprites[0].size[4].x = 44;
	env->enemy_sprites[0].size[4].y = 46;
	env->enemy_sprites[0].reversed[4] = 0;

	env->enemy_sprites[0].start[5].x = 220;
	env->enemy_sprites[0].start[5].y = 120;
	env->enemy_sprites[0].end[5].x = 254;
	env->enemy_sprites[0].end[5].y = 171;
	env->enemy_sprites[0].size[5].x = 35;
	env->enemy_sprites[0].size[5].y = 52;
	env->enemy_sprites[0].reversed[5] = 1;

	env->enemy_sprites[0].start[6].x = 299;
	env->enemy_sprites[0].start[6].y = 120;
	env->enemy_sprites[0].end[6].x = 329;
	env->enemy_sprites[0].end[6].y = 173;
	env->enemy_sprites[0].size[6].x = 31;
	env->enemy_sprites[0].size[6].y = 54;
	env->enemy_sprites[0].reversed[6] = 1;

	env->enemy_sprites[0].start[7].x = 374;
	env->enemy_sprites[0].start[7].y = 120;
	env->enemy_sprites[0].end[7].x = 405;
	env->enemy_sprites[0].end[7].y = 172;
	env->enemy_sprites[0].size[7].x = 32;
	env->enemy_sprites[0].size[7].y = 53;
	env->enemy_sprites[0].reversed[7] = 1;

	// animation repos lost soul
	env->enemy_sprites[1].texture = 23;
	env->enemy_sprites[1].death_counterpart = 4;
	env->enemy_sprites[1].pursuit_sprite = 2;
	env->enemy_sprites[1].firing_sprite = 2;
	env->enemy_sprites[1].rest_sprite = 0;
	env->enemy_sprites[1].curr_sprite = 1;
	env->enemy_sprites[1].oriented = 1;
	env->enemy_sprites[1].nb_death_sprites = 6;

	env->enemy_sprites[1].start[0].x = 44;
	env->enemy_sprites[1].start[0].y = 33;
	env->enemy_sprites[1].end[0].x = 87;
	env->enemy_sprites[1].end[0].y = 79;
	env->enemy_sprites[1].size[0].x = 44;
	env->enemy_sprites[1].size[0].y = 47;
	env->enemy_sprites[1].reversed[0] = 0;

	env->enemy_sprites[1].start[1].x = 132;
	env->enemy_sprites[1].start[1].y = 33;
	env->enemy_sprites[1].end[1].x = 163;
	env->enemy_sprites[1].end[1].y = 79;
	env->enemy_sprites[1].size[1].x = 32;
	env->enemy_sprites[1].size[1].y = 47;
	env->enemy_sprites[1].reversed[1] = 0;

	env->enemy_sprites[1].start[2].x = 208;
	env->enemy_sprites[1].start[2].y = 33;
	env->enemy_sprites[1].end[2].x = 238;
	env->enemy_sprites[1].end[2].y = 86;
	env->enemy_sprites[1].size[2].x = 31;
	env->enemy_sprites[1].size[2].y = 54;
	env->enemy_sprites[1].reversed[2] = 0;

	env->enemy_sprites[1].start[3].x = 283;
	env->enemy_sprites[1].start[3].y = 33;
	env->enemy_sprites[1].end[3].x = 317;
	env->enemy_sprites[1].end[3].y = 84;
	env->enemy_sprites[1].size[3].x = 35;
	env->enemy_sprites[1].size[3].y = 52;
	env->enemy_sprites[1].reversed[3] = 0;

	env->enemy_sprites[1].start[4].x = 362;
	env->enemy_sprites[1].start[4].y = 33;
	env->enemy_sprites[1].end[4].x = 405;
	env->enemy_sprites[1].end[4].y = 78;
	env->enemy_sprites[1].size[4].x = 44;
	env->enemy_sprites[1].size[4].y = 46;
	env->enemy_sprites[1].reversed[4] = 0;

	env->enemy_sprites[1].start[5].x = 283;
	env->enemy_sprites[1].start[5].y = 33;
	env->enemy_sprites[1].end[5].x = 317;
	env->enemy_sprites[1].end[5].y = 84;
	env->enemy_sprites[1].size[5].x = 35;
	env->enemy_sprites[1].size[5].y = 52;
	env->enemy_sprites[1].reversed[5] = 1;

	env->enemy_sprites[1].start[6].x = 208;
	env->enemy_sprites[1].start[6].y = 33;
	env->enemy_sprites[1].end[6].x = 238;
	env->enemy_sprites[1].end[6].y = 86;
	env->enemy_sprites[1].size[6].x = 31;
	env->enemy_sprites[1].size[6].y = 54;
	env->enemy_sprites[1].reversed[6] = 1;

	env->enemy_sprites[1].start[7].x = 132;
	env->enemy_sprites[1].start[7].y = 33;
	env->enemy_sprites[1].end[7].x = 163;
	env->enemy_sprites[1].end[7].y = 79;
	env->enemy_sprites[1].size[7].x = 32;
	env->enemy_sprites[1].size[7].y = 47;
	env->enemy_sprites[1].reversed[7] = 1;
	
	// lost soul pursuit 1

	env->enemy_sprites[2].texture = 23;
	env->enemy_sprites[2].death_counterpart = 4;
	env->enemy_sprites[2].pursuit_sprite = 3;
	env->enemy_sprites[2].firing_sprite = 3;
	env->enemy_sprites[2].rest_sprite = 0;
	env->enemy_sprites[2].curr_sprite = 2;
	env->enemy_sprites[2].oriented = 1;
	env->enemy_sprites[2].nb_death_sprites = 6;

	env->enemy_sprites[2].start[0].x = 44;
	env->enemy_sprites[2].start[0].y = 207;
	env->enemy_sprites[2].end[0].x = 87;
	env->enemy_sprites[2].end[0].y = 250;
	env->enemy_sprites[2].size[0].x = 44;
	env->enemy_sprites[2].size[0].y = 44;
	env->enemy_sprites[2].reversed[0] = 0;

	env->enemy_sprites[2].start[1].x = 132;
	env->enemy_sprites[2].start[1].y = 207;
	env->enemy_sprites[2].end[1].x = 191;
	env->enemy_sprites[2].end[1].y = 242;
	env->enemy_sprites[2].size[1].x = 60;
	env->enemy_sprites[2].size[1].y = 36;
	env->enemy_sprites[2].reversed[1] = 0;

	env->enemy_sprites[2].start[2].x = 236;
	env->enemy_sprites[2].start[2].y = 207;
	env->enemy_sprites[2].end[2].x = 302;
	env->enemy_sprites[2].end[2].y = 239;
	env->enemy_sprites[2].size[2].x = 67;
	env->enemy_sprites[2].size[2].y = 33;
	env->enemy_sprites[2].reversed[2] = 0;

	env->enemy_sprites[2].start[3].x = 347;
	env->enemy_sprites[2].start[3].y = 207;
	env->enemy_sprites[2].end[3].x = 400;
	env->enemy_sprites[2].end[3].y = 238;
	env->enemy_sprites[2].size[3].x = 54;
	env->enemy_sprites[2].size[3].y = 32;
	env->enemy_sprites[2].reversed[3] = 0;

	env->enemy_sprites[2].start[4].x = 445;
	env->enemy_sprites[2].start[4].y = 207;
	env->enemy_sprites[2].end[4].x = 488;
	env->enemy_sprites[2].end[4].y = 232;
	env->enemy_sprites[2].size[4].x = 44;
	env->enemy_sprites[2].size[4].y = 26;
	env->enemy_sprites[2].reversed[4] = 0;

	env->enemy_sprites[2].start[5].x = 347;
	env->enemy_sprites[2].start[5].y = 207;
	env->enemy_sprites[2].end[5].x = 400;
	env->enemy_sprites[2].end[5].y = 238;
	env->enemy_sprites[2].size[5].x = 54;
	env->enemy_sprites[2].size[5].y = 32;
	env->enemy_sprites[2].reversed[5] = 1;

	env->enemy_sprites[2].start[6].x = 236;
	env->enemy_sprites[2].start[6].y = 207;
	env->enemy_sprites[2].end[6].x = 302;
	env->enemy_sprites[2].end[6].y = 239;
	env->enemy_sprites[2].size[6].x = 67;
	env->enemy_sprites[2].size[6].y = 33;
	env->enemy_sprites[2].reversed[6] = 1;

	env->enemy_sprites[2].start[7].x = 132;
	env->enemy_sprites[2].start[7].y = 207;
	env->enemy_sprites[2].end[7].x = 191;
	env->enemy_sprites[2].end[7].y = 242;
	env->enemy_sprites[2].size[7].x = 60;
	env->enemy_sprites[2].size[7].y = 36;
	env->enemy_sprites[2].reversed[7] = 1;

	// lost soul pursuit 2

	env->enemy_sprites[3].texture = 23;
	env->enemy_sprites[3].death_counterpart = 4;
	env->enemy_sprites[3].pursuit_sprite = 2;
	env->enemy_sprites[3].firing_sprite = 2;
	env->enemy_sprites[3].rest_sprite = 0;
	env->enemy_sprites[3].curr_sprite = 3;
	env->enemy_sprites[3].oriented = 1;
	env->enemy_sprites[3].nb_death_sprites = 6;

	env->enemy_sprites[3].start[0].x = 44;
	env->enemy_sprites[3].start[0].y = 284;
	env->enemy_sprites[3].end[0].x = 87;
	env->enemy_sprites[3].end[0].y = 327;
	env->enemy_sprites[3].size[0].x = 44;
	env->enemy_sprites[3].size[0].y = 44;
	env->enemy_sprites[3].reversed[0] = 0;

	env->enemy_sprites[3].start[1].x = 132;
	env->enemy_sprites[3].start[1].y = 284;
	env->enemy_sprites[3].end[1].x = 184;
	env->enemy_sprites[3].end[1].y = 319;
	env->enemy_sprites[3].size[1].x = 53;
	env->enemy_sprites[3].size[1].y = 36;
	env->enemy_sprites[3].reversed[1] = 0;

	env->enemy_sprites[3].start[2].x = 229;
	env->enemy_sprites[3].start[2].y = 284;
	env->enemy_sprites[3].end[2].x = 295;
	env->enemy_sprites[3].end[2].y = 316;
	env->enemy_sprites[3].size[2].x = 67;
	env->enemy_sprites[3].size[2].y = 33;
	env->enemy_sprites[3].reversed[2] = 0;

	env->enemy_sprites[3].start[3].x = 340;
	env->enemy_sprites[3].start[3].y = 284;
	env->enemy_sprites[3].end[3].x = 387;
	env->enemy_sprites[3].end[3].y = 315;
	env->enemy_sprites[3].size[3].x = 48;
	env->enemy_sprites[3].size[3].y = 32;
	env->enemy_sprites[3].reversed[3] = 0;

	env->enemy_sprites[3].start[4].x = 433;
	env->enemy_sprites[3].start[4].y = 284;
	env->enemy_sprites[3].end[4].x = 475;
	env->enemy_sprites[3].end[4].y = 309;
	env->enemy_sprites[3].size[4].x = 44;
	env->enemy_sprites[3].size[4].y = 26;
	env->enemy_sprites[3].reversed[4] = 0;

	env->enemy_sprites[3].start[5].x = 340;
	env->enemy_sprites[3].start[5].y = 284;
	env->enemy_sprites[3].end[5].x = 387;
	env->enemy_sprites[3].end[5].y = 315;
	env->enemy_sprites[3].size[5].x = 48;
	env->enemy_sprites[3].size[5].y = 32;
	env->enemy_sprites[3].reversed[5] = 1;

	env->enemy_sprites[3].start[6].x = 229;
	env->enemy_sprites[3].start[6].y = 284;
	env->enemy_sprites[3].end[6].x = 295;
	env->enemy_sprites[3].end[6].y = 316;
	env->enemy_sprites[3].size[6].x = 67;
	env->enemy_sprites[3].size[6].y = 33;
	env->enemy_sprites[3].reversed[6] = 1;

	env->enemy_sprites[3].start[7].x = 132;
	env->enemy_sprites[3].start[7].y = 284;
	env->enemy_sprites[3].end[7].x = 184;
	env->enemy_sprites[3].end[7].y = 319;
	env->enemy_sprites[3].size[7].x = 53;
	env->enemy_sprites[3].size[7].y = 36;
	env->enemy_sprites[3].reversed[7] = 1;

	// death lost soul
	env->enemy_sprites[4].texture = 23;
	env->enemy_sprites[4].death_counterpart = 4;
	env->enemy_sprites[4].pursuit_sprite = 4;
	env->enemy_sprites[4].firing_sprite = 4;
	env->enemy_sprites[4].rest_sprite = 4;
	env->enemy_sprites[4].curr_sprite = 4;
	env->enemy_sprites[4].oriented = 0;
	env->enemy_sprites[4].nb_death_sprites = 6;

	env->enemy_sprites[4].start[0].x = 44;
	env->enemy_sprites[4].start[0].y = 448;
	env->enemy_sprites[4].end[0].x = 77;
	env->enemy_sprites[4].end[0].y = 498;
	env->enemy_sprites[4].size[0].x = 34;
	env->enemy_sprites[4].size[0].y = 51;
	env->enemy_sprites[4].reversed[0] = 0;

	env->enemy_sprites[4].start[1].x = 122;
	env->enemy_sprites[4].start[1].y = 448;
	env->enemy_sprites[4].end[1].x = 157;
	env->enemy_sprites[4].end[1].y = 500;
	env->enemy_sprites[4].size[1].x = 36;
	env->enemy_sprites[4].size[1].y = 53;
	env->enemy_sprites[4].reversed[1] = 0;

	env->enemy_sprites[4].start[2].x = 202;
	env->enemy_sprites[4].start[2].y = 448;
	env->enemy_sprites[4].end[2].x = 246;
	env->enemy_sprites[4].end[2].y = 495;
	env->enemy_sprites[4].size[2].x = 45;
	env->enemy_sprites[4].size[2].y = 48;
	env->enemy_sprites[4].reversed[2] = 0;

	env->enemy_sprites[4].start[3].x = 291;
	env->enemy_sprites[4].start[3].y = 448;
	env->enemy_sprites[4].end[3].x = 358;
	env->enemy_sprites[4].end[3].y = 507;
	env->enemy_sprites[4].size[3].x = 68;
	env->enemy_sprites[4].size[3].y = 60;
	env->enemy_sprites[4].reversed[3] = 0;

	env->enemy_sprites[4].start[4].x = 403;
	env->enemy_sprites[4].start[4].y = 448;
	env->enemy_sprites[4].end[4].x = 490;
	env->enemy_sprites[4].end[4].y = 519;
	env->enemy_sprites[4].size[4].x = 88;
	env->enemy_sprites[4].size[4].y = 72;
	env->enemy_sprites[4].reversed[4] = 0;

	env->enemy_sprites[4].start[5].x = 535;
	env->enemy_sprites[4].start[5].y = 448;
	env->enemy_sprites[4].end[5].x = 637;
	env->enemy_sprites[4].end[5].y = 537;
	env->enemy_sprites[4].size[5].x = 103;
	env->enemy_sprites[4].size[5].y = 90;
	env->enemy_sprites[4].reversed[5] = 0;

	// cyber_demon enemy_sprites
	env->enemy_sprites[5].texture = 24;
	env->enemy_sprites[5].death_counterpart = 9;
	env->enemy_sprites[5].pursuit_sprite = 5;
	env->enemy_sprites[5].firing_sprite = 7;
	env->enemy_sprites[5].rest_sprite = 6;
	env->enemy_sprites[5].curr_sprite = 5;
	env->enemy_sprites[5].oriented = 1;
	env->enemy_sprites[5].nb_death_sprites = 8;

	env->enemy_sprites[5].start[0].x = 44;
	env->enemy_sprites[5].start[0].y = 33;
	env->enemy_sprites[5].end[0].x = 125;
	env->enemy_sprites[5].end[0].y = 140;
	env->enemy_sprites[5].size[0].x = 82;
	env->enemy_sprites[5].size[0].y = 108;
	env->enemy_sprites[5].reversed[0] = 0;

	env->enemy_sprites[5].start[1].x = 925;
	env->enemy_sprites[5].start[1].y = 33;
	env->enemy_sprites[5].end[1].x = 999;
	env->enemy_sprites[5].end[1].y = 141;
	env->enemy_sprites[5].size[1].x = 75;
	env->enemy_sprites[5].size[1].y = 109;
	env->enemy_sprites[5].reversed[1] = 0;

	env->enemy_sprites[5].start[2].x = 798;
	env->enemy_sprites[5].start[2].y = 33;
	env->enemy_sprites[5].end[2].x = 880;
	env->enemy_sprites[5].end[2].y = 141;
	env->enemy_sprites[5].size[2].x = 84;
	env->enemy_sprites[5].size[2].y = 109;
	env->enemy_sprites[5].reversed[2] = 0;

	env->enemy_sprites[5].start[3].x = 670;
	env->enemy_sprites[5].start[3].y = 33;
	env->enemy_sprites[5].end[3].x = 752;
	env->enemy_sprites[5].end[3].y = 142;
	env->enemy_sprites[5].size[3].x = 83;
	env->enemy_sprites[5].size[3].y = 110;
	env->enemy_sprites[5].reversed[3] = 0;

	env->enemy_sprites[5].start[4].x = 544;
	env->enemy_sprites[5].start[4].y = 33;
	env->enemy_sprites[5].end[4].x = 625;
	env->enemy_sprites[5].end[4].y = 142;
	env->enemy_sprites[5].size[4].x = 82;
	env->enemy_sprites[5].size[4].y = 110;
	env->enemy_sprites[5].reversed[4] = 0;

	env->enemy_sprites[5].start[5].x = 424;
	env->enemy_sprites[5].start[5].y = 33;
	env->enemy_sprites[5].end[5].x = 499;
	env->enemy_sprites[5].end[5].y = 142;
	env->enemy_sprites[5].size[5].x = 76;
	env->enemy_sprites[5].size[5].y = 110;
	env->enemy_sprites[5].reversed[5] = 0;

	env->enemy_sprites[5].start[6].x = 301;
	env->enemy_sprites[5].start[6].y = 33;
	env->enemy_sprites[5].end[6].x = 379;
	env->enemy_sprites[5].end[6].y = 139;
	env->enemy_sprites[5].size[6].x = 79;
	env->enemy_sprites[5].size[6].y = 107;
	env->enemy_sprites[5].reversed[6] = 0;

	env->enemy_sprites[5].start[7].x = 170;
	env->enemy_sprites[5].start[7].y = 33;
	env->enemy_sprites[5].end[7].x = 256;
	env->enemy_sprites[5].end[7].y = 139;
	env->enemy_sprites[5].size[7].x = 87;
	env->enemy_sprites[5].size[7].y = 107;
	env->enemy_sprites[5].reversed[7] = 0;
	
	// cyber_demnon rest
	env->enemy_sprites[6].texture = 24;
	env->enemy_sprites[6].death_counterpart = 9;
	env->enemy_sprites[6].pursuit_sprite = 6;
	env->enemy_sprites[6].firing_sprite = 7;
	env->enemy_sprites[6].rest_sprite = 5;
	env->enemy_sprites[6].curr_sprite = 6;
	env->enemy_sprites[6].oriented = 1;
	env->enemy_sprites[6].nb_death_sprites = 8;

	env->enemy_sprites[6].start[0].x = 44;
	env->enemy_sprites[6].start[0].y = 608;
	env->enemy_sprites[6].end[0].x = 129;
	env->enemy_sprites[6].end[0].y = 717;
	env->enemy_sprites[6].size[0].x = 86;
	env->enemy_sprites[6].size[0].y = 110;
	env->enemy_sprites[6].reversed[0] = 0;

	env->enemy_sprites[6].start[1].x = 996;
	env->enemy_sprites[6].start[1].y = 608;
	env->enemy_sprites[6].end[1].x = 1110;
	env->enemy_sprites[6].end[1].y = 717;
	env->enemy_sprites[6].size[1].x = 115;
	env->enemy_sprites[6].size[1].y = 110;
	env->enemy_sprites[6].reversed[1] = 0;

	env->enemy_sprites[6].start[2].x = 855;
	env->enemy_sprites[6].start[2].y = 608;
	env->enemy_sprites[6].end[2].x = 951;
	env->enemy_sprites[6].end[2].y = 717;
	env->enemy_sprites[6].size[2].x = 97;
	env->enemy_sprites[6].size[2].y = 110;
	env->enemy_sprites[6].reversed[2] = 0;

	env->enemy_sprites[6].start[3].x = 729;
	env->enemy_sprites[6].start[3].y = 608;
	env->enemy_sprites[6].end[3].x = 810;
	env->enemy_sprites[6].end[3].y = 717;
	env->enemy_sprites[6].size[3].x = 82;
	env->enemy_sprites[6].size[3].y = 110;
	env->enemy_sprites[6].reversed[3] = 0;

	env->enemy_sprites[6].start[4].x = 600;
	env->enemy_sprites[6].start[4].y = 608;
	env->enemy_sprites[6].end[4].x = 684;
	env->enemy_sprites[6].end[4].y = 717;
	env->enemy_sprites[6].size[4].x = 85;
	env->enemy_sprites[6].size[4].y = 110;
	env->enemy_sprites[6].reversed[4] = 0;

	env->enemy_sprites[6].start[5].x = 451;
	env->enemy_sprites[6].start[5].y = 608;
	env->enemy_sprites[6].end[5].x = 555;
	env->enemy_sprites[6].end[5].y = 716;
	env->enemy_sprites[6].size[5].x = 106;
	env->enemy_sprites[6].size[5].y = 109;
	env->enemy_sprites[6].reversed[5] = 0;

	env->enemy_sprites[6].start[6].x = 301;
	env->enemy_sprites[6].start[6].y = 608;
	env->enemy_sprites[6].end[6].x = 405;
	env->enemy_sprites[6].end[6].y = 717;
	env->enemy_sprites[6].size[6].x = 105;
	env->enemy_sprites[6].size[6].y = 110;
	env->enemy_sprites[6].reversed[6] = 0;

	env->enemy_sprites[6].start[7].x = 174;
	env->enemy_sprites[6].start[7].y = 608;
	env->enemy_sprites[6].end[7].x = 256;
	env->enemy_sprites[6].end[7].y = 717;
	env->enemy_sprites[6].size[7].x = 83;
	env->enemy_sprites[6].size[7].y = 110;
	env->enemy_sprites[6].reversed[7] = 0;

	//cyber_demon firing anim 1
	env->enemy_sprites[7].texture = 24;
	env->enemy_sprites[7].death_counterpart = 9;
	env->enemy_sprites[7].pursuit_sprite = 5;
	env->enemy_sprites[7].firing_sprite = 8;
	env->enemy_sprites[7].rest_sprite = 5;
	env->enemy_sprites[7].curr_sprite = 7;
	env->enemy_sprites[7].oriented = 1;
	env->enemy_sprites[7].nb_death_sprites = 8;

	env->enemy_sprites[7].start[0].x = 44;
	env->enemy_sprites[7].start[0].y = 608;
	env->enemy_sprites[7].end[0].x = 129;
	env->enemy_sprites[7].end[0].y = 717;
	env->enemy_sprites[7].size[0].x = 86;
	env->enemy_sprites[7].size[0].y = 110;
	env->enemy_sprites[7].reversed[0] = 0;

	env->enemy_sprites[7].start[1].x = 174;
	env->enemy_sprites[7].start[1].y = 608;
	env->enemy_sprites[7].end[1].x = 256;
	env->enemy_sprites[7].end[1].y = 717;
	env->enemy_sprites[7].size[1].x = 83;
	env->enemy_sprites[7].size[1].y = 110;
	env->enemy_sprites[7].reversed[1] = 0;

	env->enemy_sprites[7].start[2].x = 301;
	env->enemy_sprites[7].start[2].y = 608;
	env->enemy_sprites[7].end[2].x = 405;
	env->enemy_sprites[7].end[2].y = 717;
	env->enemy_sprites[7].size[2].x = 105;
	env->enemy_sprites[7].size[2].y = 110;
	env->enemy_sprites[7].reversed[2] = 0;

	env->enemy_sprites[7].start[3].x = 450;
	env->enemy_sprites[7].start[3].y = 608;
	env->enemy_sprites[7].end[3].x = 555;
	env->enemy_sprites[7].end[3].y = 716;
	env->enemy_sprites[7].size[3].x = 106;
	env->enemy_sprites[7].size[3].y = 109;
	env->enemy_sprites[7].reversed[3] = 0;

	env->enemy_sprites[7].start[4].x = 600;
	env->enemy_sprites[7].start[4].y = 608;
	env->enemy_sprites[7].end[4].x = 684;
	env->enemy_sprites[7].end[4].y = 717;
	env->enemy_sprites[7].size[4].x = 85;
	env->enemy_sprites[7].size[4].y = 110;
	env->enemy_sprites[7].reversed[4] = 0;

	env->enemy_sprites[7].start[5].x = 729;
	env->enemy_sprites[7].start[5].y = 608;
	env->enemy_sprites[7].end[5].x = 810;
	env->enemy_sprites[7].end[5].y = 717;
	env->enemy_sprites[7].size[5].x = 82;
	env->enemy_sprites[7].size[5].y = 110;
	env->enemy_sprites[7].reversed[5] = 0;

	env->enemy_sprites[7].start[6].x = 855;
	env->enemy_sprites[7].start[6].y = 608;
	env->enemy_sprites[7].end[6].x = 951;
	env->enemy_sprites[7].end[6].y = 717;
	env->enemy_sprites[7].size[6].x = 97;
	env->enemy_sprites[7].size[6].y = 110;
	env->enemy_sprites[7].reversed[6] = 0;

	env->enemy_sprites[7].start[7].x = 996;
	env->enemy_sprites[7].start[7].y = 608;
	env->enemy_sprites[7].end[7].x = 1110;
	env->enemy_sprites[7].end[7].y = 717;
	env->enemy_sprites[7].size[7].x = 115;
	env->enemy_sprites[7].size[7].y = 110;
	env->enemy_sprites[7].reversed[7] = 0;

	//cyber_demon firing anim 2
	env->enemy_sprites[8].texture = 24;
	env->enemy_sprites[8].death_counterpart = 9;
	env->enemy_sprites[8].pursuit_sprite = 5;
	env->enemy_sprites[8].firing_sprite = 7;
	env->enemy_sprites[8].rest_sprite = 5;
	env->enemy_sprites[8].curr_sprite = 8;
	env->enemy_sprites[8].oriented = 1;
	env->enemy_sprites[8].nb_death_sprites = 8;

	env->enemy_sprites[8].start[0].x = 44;
	env->enemy_sprites[8].start[0].y = 751;
	env->enemy_sprites[8].end[0].x = 142;
	env->enemy_sprites[8].end[0].y = 860;
	env->enemy_sprites[8].size[0].x = 99;
	env->enemy_sprites[8].size[0].y = 110;
	env->enemy_sprites[8].reversed[0] = 0;

	env->enemy_sprites[8].start[1].x = 187;
	env->enemy_sprites[8].start[1].y = 751;
	env->enemy_sprites[8].end[1].x = 280;
	env->enemy_sprites[8].end[1].y = 860;
	env->enemy_sprites[8].size[1].x = 94;
	env->enemy_sprites[8].size[1].y = 110;
	env->enemy_sprites[8].reversed[1] = 0;

	env->enemy_sprites[8].start[2].x = 325;
	env->enemy_sprites[8].start[2].y = 751;
	env->enemy_sprites[8].end[2].x = 445;
	env->enemy_sprites[8].end[2].y = 860;
	env->enemy_sprites[8].size[2].x = 121;
	env->enemy_sprites[8].size[2].y = 110;
	env->enemy_sprites[8].reversed[2] = 0;

	env->enemy_sprites[8].start[3].x = 490;
	env->enemy_sprites[8].start[3].y = 751;
	env->enemy_sprites[8].end[3].x = 608;
	env->enemy_sprites[8].end[3].y = 859;
	env->enemy_sprites[8].size[3].x = 119;
	env->enemy_sprites[8].size[3].y = 109;
	env->enemy_sprites[8].reversed[3] = 0;

	env->enemy_sprites[8].start[4].x = 653;
	env->enemy_sprites[8].start[4].y = 751;
	env->enemy_sprites[8].end[4].x = 741;
	env->enemy_sprites[8].end[4].y = 860;
	env->enemy_sprites[8].size[4].x = 89;
	env->enemy_sprites[8].size[4].y = 110;
	env->enemy_sprites[8].reversed[4] = 0;

	env->enemy_sprites[8].start[5].x = 786;
	env->enemy_sprites[8].start[5].y = 751;
	env->enemy_sprites[8].end[5].x = 878;
	env->enemy_sprites[8].end[5].y = 860;
	env->enemy_sprites[8].size[5].x = 93;
	env->enemy_sprites[8].size[5].y = 110;
	env->enemy_sprites[8].reversed[5] = 0;

	env->enemy_sprites[8].start[6].x = 923;
	env->enemy_sprites[8].start[6].y = 751;
	env->enemy_sprites[8].end[6].x = 1036;
	env->enemy_sprites[8].end[6].y = 860;
	env->enemy_sprites[8].size[6].x = 114;
	env->enemy_sprites[8].size[6].y = 110;
	env->enemy_sprites[8].reversed[6] = 0;

	env->enemy_sprites[8].start[7].x = 1081;
	env->enemy_sprites[8].start[7].y = 751;
	env->enemy_sprites[8].end[7].x = 1210;
	env->enemy_sprites[8].end[7].y = 860;
	env->enemy_sprites[8].size[7].x = 130;
	env->enemy_sprites[8].size[7].y = 110;
	env->enemy_sprites[8].reversed[7] = 0;

	// death cyber_demon
	env->enemy_sprites[9].texture = 24;
	env->enemy_sprites[9].death_counterpart = 9;
	env->enemy_sprites[9].pursuit_sprite = 5;
	env->enemy_sprites[9].firing_sprite = 7;
	env->enemy_sprites[9].rest_sprite = 5;
	env->enemy_sprites[9].curr_sprite = 9;
	env->enemy_sprites[9].oriented = 0;
	env->enemy_sprites[9].nb_death_sprites = 8;

	env->enemy_sprites[9].start[0].x = 44;
	env->enemy_sprites[9].start[0].y = 1038;
	env->enemy_sprites[9].end[0].x = 165;
	env->enemy_sprites[9].end[0].y = 1148;
	env->enemy_sprites[9].size[0].x = 122;
	env->enemy_sprites[9].size[0].y = 111;
	env->enemy_sprites[9].reversed[0] = 0;

	env->enemy_sprites[9].start[1].x = 210;
	env->enemy_sprites[9].start[1].y = 1038;
	env->enemy_sprites[9].end[1].x = 320;
	env->enemy_sprites[9].end[1].y = 1150;
	env->enemy_sprites[9].size[1].x = 111;
	env->enemy_sprites[9].size[1].y = 113;
	env->enemy_sprites[9].reversed[1] = 0;

	env->enemy_sprites[9].start[2].x = 365;
	env->enemy_sprites[9].start[2].y = 1038;
	env->enemy_sprites[9].end[2].x = 464;
	env->enemy_sprites[9].end[2].y = 1153;
	env->enemy_sprites[9].size[2].x = 100;
	env->enemy_sprites[9].size[2].y = 116;
	env->enemy_sprites[9].reversed[2] = 0;

	env->enemy_sprites[9].start[3].x = 509;
	env->enemy_sprites[9].start[3].y = 1038;
	env->enemy_sprites[9].end[3].x = 621;
	env->enemy_sprites[9].end[3].y = 1154;
	env->enemy_sprites[9].size[3].x = 113;
	env->enemy_sprites[9].size[3].y = 117;
	env->enemy_sprites[9].reversed[3] = 0;

	env->enemy_sprites[9].start[4].x = 666;
	env->enemy_sprites[9].start[4].y = 1038;
	env->enemy_sprites[9].end[4].x = 790;
	env->enemy_sprites[9].end[4].y = 1161;
	env->enemy_sprites[9].size[4].x = 125;
	env->enemy_sprites[9].size[4].y = 124;
	env->enemy_sprites[9].reversed[4] = 0;

	env->enemy_sprites[9].start[5].x = 836;
	env->enemy_sprites[9].start[5].y = 1038;
	env->enemy_sprites[9].end[5].x = 970;
	env->enemy_sprites[9].end[5].y = 1168;
	env->enemy_sprites[9].size[5].x = 136;
	env->enemy_sprites[9].size[5].y = 131;
	env->enemy_sprites[9].reversed[5] = 0;

	env->enemy_sprites[9].start[6].x = 1015;
	env->enemy_sprites[9].start[6].y = 1038;
	env->enemy_sprites[9].end[6].x = 1155;
	env->enemy_sprites[9].end[6].y = 1171;
	env->enemy_sprites[9].size[6].x = 141;
	env->enemy_sprites[9].size[6].y = 134;
	env->enemy_sprites[9].reversed[6] = 0;

	env->enemy_sprites[9].start[7].x = 1200;
	env->enemy_sprites[9].start[7].y = 1038;
	env->enemy_sprites[9].end[7].x = 1338;
	env->enemy_sprites[9].end[7].y = 1171;
	env->enemy_sprites[9].size[7].x = 139;
	env->enemy_sprites[9].size[7].y = 134;
	env->enemy_sprites[9].reversed[7] = 0;
	return (0);
}
