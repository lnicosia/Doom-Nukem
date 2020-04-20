/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/11 16:28:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int			init_object_sprites(t_env *env)
{
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
	
	// rocket sprites
	env->object_sprites[1].texture = 25;
	env->object_sprites[1].death_counterpart = 22;
	env->object_sprites[1].pursuit_sprite = 1;
	env->object_sprites[1].firing_sprite = 1;
	env->object_sprites[1].rest_sprite = 1;
	env->object_sprites[1].curr_sprite = 1;
	env->object_sprites[1].oriented = 1;
	env->object_sprites[1].nb_death_sprites = 3;

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

	// health pack

	env->object_sprites[2].texture = 22;
	env->object_sprites[2].death_counterpart = 2;
	env->object_sprites[2].oriented = 0;
	env->object_sprites[2].rest_sprite = 2;
	env->object_sprites[2].reversed[0] = 0;
	env->object_sprites[2].start[0].x = 47;
	env->object_sprites[2].start[0].y = 70;
	env->object_sprites[2].end[0].x = 80;
	env->object_sprites[2].end[0].y = 88;
	env->object_sprites[2].size[0].x = 34;
	env->object_sprites[2].size[0].y = 19;

	// shotgun ammo

	env->object_sprites[3].texture = 22;
	env->object_sprites[3].death_counterpart = 3;
	env->object_sprites[3].oriented = 0;
	env->object_sprites[3].rest_sprite = 3;
	env->object_sprites[3].reversed[0] = 0;
	env->object_sprites[3].start[0].x = 426;
	env->object_sprites[3].start[0].y = 179;
	env->object_sprites[3].end[0].x = 452;
	env->object_sprites[3].end[0].y = 193;
	env->object_sprites[3].size[0].x = 27;
	env->object_sprites[3].size[0].y = 15;

	//Rockets ammo

	env->object_sprites[4].texture = 22;
	env->object_sprites[4].death_counterpart = 22;
	env->object_sprites[4].oriented = 0;
	env->object_sprites[4].rest_sprite = 4;
	env->object_sprites[4].reversed[0] = 0;
	env->object_sprites[4].start[0].x = 586;
	env->object_sprites[4].start[0].y = 118;
	env->object_sprites[4].end[0].x = 639;
	env->object_sprites[4].end[0].y = 146;
	env->object_sprites[4].size[0].x = 54;
	env->object_sprites[4].size[0].y = 29;

	// regular ammo

	env->object_sprites[5].texture = 22;
	env->object_sprites[5].death_counterpart = 5;
	env->object_sprites[5].oriented = 0;
	env->object_sprites[5].rest_sprite = 5;
	env->object_sprites[5].reversed[0] = 0;
	env->object_sprites[5].start[0].x = 219;
	env->object_sprites[5].start[0].y = 328;
	env->object_sprites[5].end[0].x = 246;
	env->object_sprites[5].end[0].y = 343;
	env->object_sprites[5].size[0].x = 28;
	env->object_sprites[5].size[0].y = 16;

	// Energy cell pack

	env->object_sprites[6].texture = 22;
	env->object_sprites[6].death_counterpart = 6;
	env->object_sprites[6].oriented = 0;
	env->object_sprites[6].rest_sprite = 6;
	env->object_sprites[6].reversed[0] = 0;
	env->object_sprites[6].start[0].x = 343;
	env->object_sprites[6].start[0].y = 115;
	env->object_sprites[6].end[0].x = 374;
	env->object_sprites[6].end[0].y = 135;
	env->object_sprites[6].size[0].x = 32;
	env->object_sprites[6].size[0].y = 21;

	// lamp anim 1

	env->object_sprites[7].texture = 22;
	env->object_sprites[7].death_counterpart = 7;
	env->object_sprites[7].oriented = 0;
	env->object_sprites[7].rest_sprite = 8;
	env->object_sprites[7].reversed[0] = 0;
	env->object_sprites[7].start[0].x = 449;
	env->object_sprites[7].start[0].y = 329;
	env->object_sprites[7].end[0].x = 471;
	env->object_sprites[7].end[0].y = 412;
	env->object_sprites[7].size[0].x = 23;
	env->object_sprites[7].size[0].y = 84;

	// lamp anim 2

	env->object_sprites[8].texture = 22;
	env->object_sprites[8].death_counterpart = 8;
	env->object_sprites[8].oriented = 0;
	env->object_sprites[8].rest_sprite = 9;
	env->object_sprites[8].reversed[0] = 0;
	env->object_sprites[8].start[0].x = 479;
	env->object_sprites[8].start[0].y = 329;
	env->object_sprites[8].end[0].x = 501;
	env->object_sprites[8].end[0].y = 412;
	env->object_sprites[8].size[0].x = 23;
	env->object_sprites[8].size[0].y = 84;

	// lamp anim 3

	env->object_sprites[9].texture = 22;
	env->object_sprites[9].death_counterpart = 9;
	env->object_sprites[9].oriented = 0;
	env->object_sprites[9].rest_sprite = 10;
	env->object_sprites[9].reversed[0] = 0;
	env->object_sprites[9].start[0].x = 509;
	env->object_sprites[9].start[0].y = 329;
	env->object_sprites[9].end[0].x = 531;
	env->object_sprites[9].end[0].y = 412;
	env->object_sprites[9].size[0].x = 23;
	env->object_sprites[9].size[0].y = 84;

	// lamp anim 4

	env->object_sprites[10].texture = 22;
	env->object_sprites[10].death_counterpart = 10;
	env->object_sprites[10].oriented = 0;
	env->object_sprites[10].rest_sprite = 7;
	env->object_sprites[10].reversed[0] = 0;
	env->object_sprites[10].start[0].x = 539;
	env->object_sprites[10].start[0].y = 329;
	env->object_sprites[10].end[0].x = 561;
	env->object_sprites[10].end[0].y = 412;
	env->object_sprites[10].size[0].x = 23;
	env->object_sprites[10].size[0].y = 84;

	// monitor off

	env->object_sprites[11].texture = 22;
	env->object_sprites[11].death_counterpart = 16;
	env->object_sprites[11].nb_death_sprites = 1;
	env->object_sprites[11].oriented = 0;
	env->object_sprites[11].rest_sprite = 11;
	env->object_sprites[11].reversed[0] = 0;
	env->object_sprites[11].start[0].x = 511;
	env->object_sprites[11].start[0].y = 122;
	env->object_sprites[11].end[0].x = 538;
	env->object_sprites[11].end[0].y = 148;
	env->object_sprites[11].size[0].x = 28;
	env->object_sprites[11].size[0].y = 27;

	// monitor on anim 1

	env->object_sprites[12].texture = 22;
	env->object_sprites[12].death_counterpart = 16;
	env->object_sprites[12].nb_death_sprites = 1;
	env->object_sprites[12].oriented = 0;
	env->object_sprites[12].rest_sprite = 13;
	env->object_sprites[12].reversed[0] = 0;
	env->object_sprites[12].start[0].x = 48;
	env->object_sprites[12].start[0].y = 228;
	env->object_sprites[12].end[0].x = 75;
	env->object_sprites[12].end[0].y = 254;
	env->object_sprites[12].size[0].x = 28;
	env->object_sprites[12].size[0].y = 27;

	//monitor on anim 2

	env->object_sprites[13].texture = 22;
	env->object_sprites[13].death_counterpart = 16;
	env->object_sprites[13].nb_death_sprites = 1;
	env->object_sprites[13].oriented = 0;
	env->object_sprites[13].rest_sprite = 14;
	env->object_sprites[13].reversed[0] = 0;
	env->object_sprites[13].start[0].x = 78;
	env->object_sprites[13].start[0].y = 228;
	env->object_sprites[13].end[0].x = 105;
	env->object_sprites[13].end[0].y = 254;
	env->object_sprites[13].size[0].x = 28;
	env->object_sprites[13].size[0].y = 27;

	//monitor on anim 3

	env->object_sprites[14].texture = 22;
	env->object_sprites[14].death_counterpart = 16;
	env->object_sprites[14].nb_death_sprites = 1;
	env->object_sprites[14].oriented = 0;
	env->object_sprites[14].rest_sprite = 15;
	env->object_sprites[14].reversed[0] = 0;
	env->object_sprites[14].start[0].x = 108;
	env->object_sprites[14].start[0].y = 228;
	env->object_sprites[14].end[0].x = 135;
	env->object_sprites[14].end[0].y = 254;
	env->object_sprites[14].size[0].x = 28;
	env->object_sprites[14].size[0].y = 27;

	// monitor on anim 4

	env->object_sprites[15].texture = 22;
	env->object_sprites[15].death_counterpart = 16;
	env->object_sprites[15].nb_death_sprites = 1;
	env->object_sprites[15].oriented = 0;
	env->object_sprites[15].rest_sprite = 12;
	env->object_sprites[15].reversed[0] = 0;
	env->object_sprites[15].start[0].x = 138;
	env->object_sprites[15].start[0].y = 228;
	env->object_sprites[15].end[0].x = 165;
	env->object_sprites[15].end[0].y = 254;
	env->object_sprites[15].size[0].x = 28;
	env->object_sprites[15].size[0].y = 27;

	//monitor destroyed

	env->object_sprites[16].texture = 22;
	env->object_sprites[16].death_counterpart = 16;
	env->object_sprites[16].nb_death_sprites = 1;
	env->object_sprites[16].oriented = 0;
	env->object_sprites[16].rest_sprite = 16;
	env->object_sprites[16].reversed[0] = 0;
	env->object_sprites[16].start[0].x = 646;
	env->object_sprites[16].start[0].y = 268;
	env->object_sprites[16].end[0].x = 673;
	env->object_sprites[16].end[0].y = 294;
	env->object_sprites[16].size[0].x = 28;
	env->object_sprites[16].size[0].y = 27;

	// armor green

	env->object_sprites[17].texture = 22;
	env->object_sprites[17].death_counterpart = 17;
	env->object_sprites[17].oriented = 0;
	env->object_sprites[17].rest_sprite = 17;
	env->object_sprites[17].reversed[0] = 0;
	env->object_sprites[17].start[0].x = 337;
	env->object_sprites[17].start[0].y = 224;
	env->object_sprites[17].end[0].x = 367;
	env->object_sprites[17].end[0].y = 240;
	env->object_sprites[17].size[0].x = 31;
	env->object_sprites[17].size[0].y = 17;

	// candle

	env->object_sprites[18].texture = 22;
	env->object_sprites[18].death_counterpart = 19;
	env->object_sprites[18].nb_death_sprites = 1;
	env->object_sprites[18].oriented = 0;
	env->object_sprites[18].rest_sprite = 18;
	env->object_sprites[18].reversed[0] = 0;
	env->object_sprites[18].start[0].x = 597;
	env->object_sprites[18].start[0].y = 159;
	env->object_sprites[18].end[0].x = 612;
	env->object_sprites[18].end[0].y = 173;
	env->object_sprites[18].size[0].x = 16;
	env->object_sprites[18].size[0].y = 15;

	// destroyed candle

	env->object_sprites[19].texture = 22;
	env->object_sprites[19].death_counterpart = 19;
	env->object_sprites[19].oriented = 0;
	env->object_sprites[19].rest_sprite = 19;
	env->object_sprites[19].reversed[0] = 0;
	env->object_sprites[19].start[0].x = 528;
	env->object_sprites[19].start[0].y = 280;
	env->object_sprites[19].end[0].x = 558;
	env->object_sprites[19].end[0].y = 293;
	env->object_sprites[19].size[0].x = 31;
	env->object_sprites[19].size[0].y = 14;

	//barrel

	env->object_sprites[20].texture = 34;
	env->object_sprites[20].death_counterpart = 21;
	env->object_sprites[20].nb_death_sprites = 8;
	env->object_sprites[20].oriented = 0;
	env->object_sprites[20].rest_sprite = 20;
	env->object_sprites[20].reversed[0] = 0;
	env->object_sprites[20].start[0].x = 6;
	env->object_sprites[20].start[0].y = 205;
	env->object_sprites[20].end[0].x = 40;
	env->object_sprites[20].end[0].y = 254;
	env->object_sprites[20].size[0].x = 35;
	env->object_sprites[20].size[0].y = 50;

	//barrel exploding

	env->object_sprites[21].texture = 34;
	env->object_sprites[21].death_counterpart = 21;
	env->object_sprites[21].nb_death_sprites = 8;
	env->object_sprites[21].oriented = 0;
	env->object_sprites[21].rest_sprite = 21;
	env->object_sprites[21].reversed[0] = 0;

	env->object_sprites[21].start[0].x = 48;
	env->object_sprites[21].start[0].y = 202;
	env->object_sprites[21].end[0].x = 88;
	env->object_sprites[21].end[0].y = 255;
	env->object_sprites[21].size[0].x = 41;
	env->object_sprites[21].size[0].y = 54;

	env->object_sprites[21].start[1].x = 95;
	env->object_sprites[21].start[1].y = 201;
	env->object_sprites[21].end[1].x = 138;
	env->object_sprites[21].end[1].y = 255;
	env->object_sprites[21].size[1].x = 44;
	env->object_sprites[21].size[1].y = 55;

	env->object_sprites[21].start[2].x = 147;
	env->object_sprites[21].start[2].y = 201;
	env->object_sprites[21].end[2].x = 193;
	env->object_sprites[21].end[2].y = 255;
	env->object_sprites[21].size[2].x = 47;
	env->object_sprites[21].size[2].y = 55;

	env->object_sprites[21].start[3].x = 200;
	env->object_sprites[21].start[3].y = 158;
	env->object_sprites[21].end[3].x = 285;
	env->object_sprites[21].end[3].y = 259;
	env->object_sprites[21].size[3].x = 86;
	env->object_sprites[21].size[3].y = 102;

	env->object_sprites[21].start[4].x = 294;
	env->object_sprites[21].start[4].y = 158;
	env->object_sprites[21].end[4].x = 373;
	env->object_sprites[21].end[4].y = 253;
	env->object_sprites[21].size[4].x = 80;
	env->object_sprites[21].size[4].y = 86;

	env->object_sprites[21].start[5].x = 381;
	env->object_sprites[21].start[5].y = 171;
	env->object_sprites[21].end[5].x = 459;
	env->object_sprites[21].end[5].y = 253;
	env->object_sprites[21].size[5].x = 79;
	env->object_sprites[21].size[5].y = 83;

	env->object_sprites[21].start[6].x = 467;
	env->object_sprites[21].start[6].y = 166;
	env->object_sprites[21].end[6].x = 542;
	env->object_sprites[21].end[6].y = 252;
	env->object_sprites[21].size[6].x = 76;
	env->object_sprites[21].size[6].y = 87;

	env->object_sprites[21].start[7].x = 552;
	env->object_sprites[21].start[7].y = 198;
	env->object_sprites[21].end[7].x = 630;
	env->object_sprites[21].end[7].y = 281;
	env->object_sprites[21].size[7].x = 79;
	env->object_sprites[21].size[7].y = 84;

	// explosion animation

	env->object_sprites[22].texture = 25;
	env->object_sprites[22].death_counterpart = 22;
	env->object_sprites[22].curr_sprite = 22;
	env->object_sprites[22].nb_death_sprites = 3;
	env->object_sprites[22].oriented = 0;
	env->object_sprites[22].rest_sprite = 22;
	env->object_sprites[22].reversed[0] = 0;

	env->object_sprites[22].start[0].x = 1;
	env->object_sprites[22].start[0].y = 858;
	env->object_sprites[22].end[0].x = 73;
	env->object_sprites[22].end[0].y = 917;
	env->object_sprites[22].size[0].x = 73;
	env->object_sprites[22].size[0].y = 60;

	env->object_sprites[22].start[1].x = 75;
	env->object_sprites[22].start[1].y = 846;
	env->object_sprites[22].end[1].x = 162;
	env->object_sprites[22].end[1].y = 917;
	env->object_sprites[22].size[1].x = 88;
	env->object_sprites[22].size[1].y = 72;

	env->object_sprites[22].start[2].x = 164;
	env->object_sprites[22].start[2].y = 832;
	env->object_sprites[22].end[2].x = 266;
	env->object_sprites[22].end[2].y = 917;
	env->object_sprites[22].size[2].x = 103;
	env->object_sprites[22].size[2].y = 86;

	// Grille
	env->object_sprites[23].texture = 31;
	env->object_sprites[23].death_counterpart = 0;
	env->object_sprites[23].pursuit_sprite = 0;
	env->object_sprites[23].rest_sprite = 23;
	env->object_sprites[23].curr_sprite = 0;
	env->object_sprites[23].oriented = 0;
	env->object_sprites[23].nb_death_sprites = 0;
	env->object_sprites[23].start[0].x = 0;
	env->object_sprites[23].start[0].y = 0;
	env->object_sprites[23].end[0].x = 128;
	env->object_sprites[23].end[0].y = 256;
	env->object_sprites[23].size[0].x = 128;
	env->object_sprites[23].size[0].y = 256;
	env->object_sprites[23].reversed[0] = 0;
	
	// Bouton OFF
	env->object_sprites[24].texture = 32;
	env->object_sprites[24].death_counterpart = 1;
	env->object_sprites[24].pursuit_sprite = 1;
	env->object_sprites[24].rest_sprite = 24;
	env->object_sprites[24].curr_sprite = 1;
	env->object_sprites[24].oriented = 0;
	env->object_sprites[24].nb_death_sprites = 1;
	env->object_sprites[24].start[0].x = 0;
	env->object_sprites[24].start[0].y = 0;
	env->object_sprites[24].end[0].x = 64;
	env->object_sprites[24].end[0].y = 64;
	env->object_sprites[24].size[0].x = 64;
	env->object_sprites[24].size[0].y = 64;
	env->object_sprites[24].reversed[0] = 0;

	// Bouton ON
	env->object_sprites[25].texture = 33;
	env->object_sprites[25].death_counterpart = 2;
	env->object_sprites[25].pursuit_sprite = 2;
	env->object_sprites[25].rest_sprite = 25;
	env->object_sprites[25].curr_sprite = 0;
	env->object_sprites[25].oriented = 0;
	env->object_sprites[25].nb_death_sprites = 2;
	env->object_sprites[25].start[0].x = 0;
	env->object_sprites[25].start[0].y = 0;
	env->object_sprites[25].end[0].x = 64;
	env->object_sprites[25].end[0].y = 64;
	env->object_sprites[25].size[0].x = 64;
	env->object_sprites[25].size[0].y = 64;
	env->object_sprites[25].reversed[0] = 0;

	// Bullet hole
	env->object_sprites[26].texture = 35;
	env->object_sprites[26].death_counterpart = 3;
	env->object_sprites[26].pursuit_sprite = 3;
	env->object_sprites[26].rest_sprite = 26;
	env->object_sprites[26].curr_sprite = 0;
	env->object_sprites[26].oriented = 0;
	env->object_sprites[26].nb_death_sprites = 0;
	env->object_sprites[26].start[0].x = 0;
	env->object_sprites[26].start[0].y = 0;
	env->object_sprites[26].end[0].x = 600;
	env->object_sprites[26].end[0].y = 600;
	env->object_sprites[26].size[0].x = 600;
	env->object_sprites[26].size[0].y = 600;
	env->object_sprites[26].reversed[0] = 0;

	//Lost soul
	env->object_sprites[27].texture = 23;
	env->object_sprites[27].death_counterpart = 4;
	env->object_sprites[27].pursuit_sprite = 2;
	env->object_sprites[27].firing_sprite = 2;
	env->object_sprites[27].rest_sprite = 27;
	env->object_sprites[27].curr_sprite = 0;
	env->object_sprites[27].oriented = 0;
	env->object_sprites[27].nb_death_sprites = 6;
	env->object_sprites[27].start[0].x = 44;
	env->object_sprites[27].start[0].y = 120;
	env->object_sprites[27].end[0].x = 87;
	env->object_sprites[27].end[0].y = 165;
	env->object_sprites[27].size[0].x = 44;
	env->object_sprites[27].size[0].y = 46;
	env->object_sprites[27].reversed[0] = 0;

	// cyber demon
	env->object_sprites[28].texture = 24;
	env->object_sprites[28].death_counterpart = 12;
	env->object_sprites[28].pursuit_sprite = 6;
	env->object_sprites[28].firing_sprite = 9;
	env->object_sprites[28].rest_sprite = 28;
	env->object_sprites[28].curr_sprite = 5;
	env->object_sprites[28].oriented = 0;
	env->object_sprites[28].nb_death_sprites = 8;
	env->object_sprites[28].start[0].x = 44;
	env->object_sprites[28].start[0].y = 33;
	env->object_sprites[28].end[0].x = 125;
	env->object_sprites[28].end[0].y = 140;
	env->object_sprites[28].size[0].x = 82;
	env->object_sprites[28].size[0].y = 108;
	env->object_sprites[28].reversed[0] = 0;

	// Doom guy face
	env->object_sprites[29].texture = 37;
	env->object_sprites[29].oriented = 0;
	env->object_sprites[29].rest_sprite = 29;
	env->object_sprites[29].start[0].x = 40;
	env->object_sprites[29].start[0].y = 13;
	env->object_sprites[29].end[0].x = 64;
	env->object_sprites[29].end[0].y = 42;
	env->object_sprites[29].size[0].x = 24;
	env->object_sprites[29].size[0].y = 29;
	env->object_sprites[29].reversed[0] = 0;

	// Camera sprite
	env->object_sprites[30].texture = 38;
	env->object_sprites[30].oriented = 0;
	env->object_sprites[30].rest_sprite = 30;
	env->object_sprites[30].start[0].x = 0;
	env->object_sprites[30].start[0].y = 0;
	env->object_sprites[30].end[0].x = 431;
	env->object_sprites[30].end[0].y = 377;
	env->object_sprites[30].size[0].x = 431;
	env->object_sprites[30].size[0].y = 377;
	env->object_sprites[30].reversed[0] = 0;

	// Shotgun sprite
	env->object_sprites[31].texture = 22;
	env->object_sprites[31].oriented = 0;
	env->object_sprites[31].rest_sprite = 31;
	env->object_sprites[31].start[0].x = 512;
	env->object_sprites[31].start[0].y = 42;
	env->object_sprites[31].end[0].x = 560;
	env->object_sprites[31].end[0].y = 53;
	env->object_sprites[31].size[0].x = 48;
	env->object_sprites[31].size[0].y = 11;
	env->object_sprites[31].reversed[0] = 0;

	// Raygun sprite
	env->object_sprites[32].texture = 39;
	env->object_sprites[32].oriented = 0;
	env->object_sprites[32].rest_sprite = 32;
	env->object_sprites[32].start[0].x = 0;
	env->object_sprites[32].start[0].y = 0;
	env->object_sprites[32].end[0].x = 608;
	env->object_sprites[32].end[0].y = 253;
	env->object_sprites[32].size[0].x = 608;
	env->object_sprites[32].size[0].y = 253;
	env->object_sprites[32].reversed[0] = 0;

	// Doom guy sprite
	env->object_sprites[33].texture = 36;
	env->object_sprites[33].oriented = 1;
	env->object_sprites[33].rest_sprite = 33;
	env->object_sprites[33].start[0].x = 44;
	env->object_sprites[33].start[0].y = 421;
	env->object_sprites[33].end[0].x = 70;
	env->object_sprites[33].end[0].y = 476;
	env->object_sprites[33].size[0].x = 26;
	env->object_sprites[33].size[0].y = 56;
	env->object_sprites[33].reversed[0] = 1;

	env->object_sprites[33].start[1].x = 114;
	env->object_sprites[33].start[1].y = 421;
	env->object_sprites[33].end[1].x = 157;
	env->object_sprites[33].end[1].y = 476;
	env->object_sprites[33].size[1].x = 43;
	env->object_sprites[33].size[1].y = 55;
	env->object_sprites[33].reversed[1] = 1;

	env->object_sprites[33].start[2].x = 201;
	env->object_sprites[33].start[2].y = 421;
	env->object_sprites[33].end[2].x = 252;
	env->object_sprites[33].end[2].y = 474;
	env->object_sprites[33].size[2].x = 51;
	env->object_sprites[33].size[2].y = 53;
	env->object_sprites[33].reversed[2] = 1;

	env->object_sprites[33].start[3].x = 296;
	env->object_sprites[33].start[3].y = 421;
	env->object_sprites[33].end[3].x = 334;
	env->object_sprites[33].end[3].y = 473;
	env->object_sprites[33].size[3].x = 38;
	env->object_sprites[33].size[3].y = 52;
	env->object_sprites[33].reversed[3] = 1;

	env->object_sprites[33].start[4].x = 378;
	env->object_sprites[33].start[4].y = 421;
	env->object_sprites[33].end[4].x = 404;
	env->object_sprites[33].end[4].y = 472;
	env->object_sprites[33].size[4].x = 26;
	env->object_sprites[33].size[4].y = 51;
	env->object_sprites[33].reversed[4] = 1;

	env->object_sprites[33].start[5].x = 448;
	env->object_sprites[33].start[5].y = 421;
	env->object_sprites[33].end[5].x = 496;
	env->object_sprites[33].end[5].y = 477;
	env->object_sprites[33].size[5].x = 48;
	env->object_sprites[33].size[5].y = 56;
	env->object_sprites[33].reversed[5] = 1;

	env->object_sprites[33].start[6].x = 540;
	env->object_sprites[33].start[6].y = 421;
	env->object_sprites[33].end[6].x = 596;
	env->object_sprites[33].end[6].y = 476;
	env->object_sprites[33].size[6].x = 56;
	env->object_sprites[33].size[6].y = 56;
	env->object_sprites[33].reversed[6] = 1;

	env->object_sprites[33].start[7].x = 640;
	env->object_sprites[33].start[7].y = 421;
	env->object_sprites[33].end[7].x = 688;
	env->object_sprites[33].end[7].y = 476;
	env->object_sprites[33].size[7].x = 48;
	env->object_sprites[33].size[7].y = 56;
	env->object_sprites[33].reversed[7] = 1;

	// HD sprite
	env->object_sprites[34].texture = 52;
	env->object_sprites[34].oriented = 0;
	env->object_sprites[34].rest_sprite = 34;
	env->object_sprites[34].start[0].x = 0;
	env->object_sprites[34].start[0].y = 0;
	env->object_sprites[34].end[0].x = 467;
	env->object_sprites[34].end[0].y = 518;
	env->object_sprites[34].size[0].x = 467;
	env->object_sprites[34].size[0].y = 518;
	env->object_sprites[34].reversed[0] = 0;
	return (0);
}
int		init_enemy_sprites(t_env *env)
{
	init_lost_soul_sprite(env);
	init_lost_soul_rest(env);
	init_lost_soul_pursuit(env);
	init_lost_soul_pursuit_two(env);
	init_lost_soul_death(env);
	init_cyber_demon_pursuit(env);
	init_cyber_demon_pursuit_two(env);
	init_cyber_demon_pursuit_three(env);
	init_cyber_demon_pursuit_four(env);
	init_cyber_demon_firing_anim(env);
	init_cyber_demon_firing_anim_two(env);
	init_cyber_demon_firing_anim_three(env);
	init_cyber_demon_death(env);
	env->enemies_main_sprites[0] = LOST_SOUL;
	env->enemies_main_sprites[1] = CYBER_DEMON;
	init_objects_main_sprites(env);
	return (0);
}
