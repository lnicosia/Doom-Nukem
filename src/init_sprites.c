/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:46 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/27 16:38:30 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "map_parser.h"

int			init_wall_sprites(t_env *env)
{
	if (!(env->wall_sprites = (t_sprite*)malloc(sizeof(t_sprite) * MAX_WALL_SPRITES)))
		return (ft_printf("Could not malloc wall sprites\n"));
	
	// Grille
	env->wall_sprites[0].texture = 31;
	env->wall_sprites[0].death_counterpart = 0;
	env->wall_sprites[0].pursuit_sprite = 0;
	env->wall_sprites[0].rest_sprite = 0;
	env->wall_sprites[0].curr_sprite = 0;
	env->wall_sprites[0].oriented = 0;
	env->wall_sprites[0].nb_death_sprites = 0;
	env->wall_sprites[0].start[0].x = 0;
	env->wall_sprites[0].start[0].y = 0;
	env->wall_sprites[0].end[0].x = 128;
	env->wall_sprites[0].end[0].y = 256;
	env->wall_sprites[0].size[0].x = 128;
	env->wall_sprites[0].size[0].y = 256;
	env->wall_sprites[0].reversed[0] = 0;
	
	// Bouton OFF
	env->wall_sprites[1].texture = 32;
	env->wall_sprites[1].death_counterpart = 1;
	env->wall_sprites[1].pursuit_sprite = 1;
	env->wall_sprites[1].rest_sprite = 1;
	env->wall_sprites[1].curr_sprite = 1;
	env->wall_sprites[1].oriented = 1;
	env->wall_sprites[1].nb_death_sprites = 1;
	env->wall_sprites[1].start[0].x = 0;
	env->wall_sprites[1].start[0].y = 0;
	env->wall_sprites[1].end[0].x = 64;
	env->wall_sprites[1].end[0].y = 64;
	env->wall_sprites[1].size[0].x = 64;
	env->wall_sprites[1].size[0].y = 64;
	env->wall_sprites[1].reversed[0] = 0;

	// Bouton ON
	env->wall_sprites[2].texture = 33;
	env->wall_sprites[2].death_counterpart = 2;
	env->wall_sprites[2].pursuit_sprite = 2;
	env->wall_sprites[2].rest_sprite = 2;
	env->wall_sprites[2].curr_sprite = 0;
	env->wall_sprites[2].oriented = 2;
	env->wall_sprites[2].nb_death_sprites = 2;
	env->wall_sprites[2].start[0].x = 0;
	env->wall_sprites[2].start[0].y = 0;
	env->wall_sprites[2].end[0].x = 64;
	env->wall_sprites[2].end[0].y = 64;
	env->wall_sprites[2].size[0].x = 64;
	env->wall_sprites[2].size[0].y = 64;
	env->wall_sprites[2].reversed[0] = 0;
	return (0);
}

int			init_object_sprites(t_env *env)
{
	if (!(env->object_sprites = (t_sprite*)malloc(sizeof(t_sprite) * 22)))
		return (ft_printf("Could not malloc enemy sprites\n"));
	
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

	// health pack

	env->object_sprites[2].texture = 22;
	env->object_sprites[2].death_counterpart = 2;
	env->object_sprites[2].oriented = 0;
	env->object_sprites[2].rest_sprite = 0;
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
	env->object_sprites[3].rest_sprite = 0;
	env->object_sprites[3].reversed[0] = 0;
	env->object_sprites[3].start[0].x = 426;
	env->object_sprites[3].start[0].y = 179;
	env->object_sprites[3].end[0].x = 452;
	env->object_sprites[3].end[0].y = 193;
	env->object_sprites[3].size[0].x = 27;
	env->object_sprites[3].size[0].y = 15;

	//Rockets ammo

	env->object_sprites[4].texture = 22;
	env->object_sprites[4].death_counterpart = 4;
	env->object_sprites[4].oriented = 0;
	env->object_sprites[4].rest_sprite = 0;
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
	env->object_sprites[5].rest_sprite = 0;
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
	env->object_sprites[6].rest_sprite = 0;
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
	env->object_sprites[10].rest_sprite = 0;
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
	env->object_sprites[11].rest_sprite = 0;
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
	env->object_sprites[17].rest_sprite = 0;
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
	env->object_sprites[18].rest_sprite = 0;
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
	env->object_sprites[21].rest_sprite = 0;
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
	return (0);
}
int			init_enemy_sprites(t_env *env)
{
	if (!(env->enemy_sprites = (t_sprite*)malloc(sizeof(t_sprite) * 13)))
		return (ft_printf("Could not malloc enemy_sprites\n"));
	if (!(env->editor.enemy_tab = (int *)malloc(sizeof(int) * MAX_ENEMIES)))
		return (ft_printf("Could not malloc editor's array for enemies main sprite\n"));
	env-Weditor.enemy_tab[0] = LOST_SOUL;
	env-Weditor.enemy_tab[1] = CYBER_DEMON;

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
	env->enemy_sprites[5].death_counterpart = 12;
	env->enemy_sprites[5].pursuit_sprite = 6;
	env->enemy_sprites[5].firing_sprite = 9;
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
	
	// cyber_demon pursuit 2

	env->enemy_sprites[6].texture = 24;
	env->enemy_sprites[6].death_counterpart = 12;
	env->enemy_sprites[6].pursuit_sprite = 7;
	env->enemy_sprites[6].firing_sprite = 9;
	env->enemy_sprites[6].rest_sprite = 7;
	env->enemy_sprites[6].curr_sprite = 6;
	env->enemy_sprites[6].oriented = 1;
	env->enemy_sprites[6].nb_death_sprites = 8;

	env->enemy_sprites[6].start[0].x = 44;
	env->enemy_sprites[6].start[0].y = 176;
	env->enemy_sprites[6].end[0].x = 128;
	env->enemy_sprites[6].end[0].y = 284;
	env->enemy_sprites[6].size[0].x = 85;
	env->enemy_sprites[6].size[0].y = 109;
	env->enemy_sprites[6].reversed[0] = 0;

	env->enemy_sprites[6].start[1].x = 873;
	env->enemy_sprites[6].start[1].y = 176;
	env->enemy_sprites[6].end[1].x = 955;
	env->enemy_sprites[6].end[1].y = 284;
	env->enemy_sprites[6].size[1].x = 83;
	env->enemy_sprites[6].size[1].y = 109;
	env->enemy_sprites[6].reversed[1] = 0;

	env->enemy_sprites[6].start[2].x = 770;
	env->enemy_sprites[6].start[2].y = 176;
	env->enemy_sprites[6].end[2].x = 828;
	env->enemy_sprites[6].end[2].y = 284;
	env->enemy_sprites[6].size[2].x = 59;
	env->enemy_sprites[6].size[2].y = 109;
	env->enemy_sprites[6].reversed[2] = 0;

	env->enemy_sprites[6].start[3].x = 651;
	env->enemy_sprites[6].start[3].y = 176;
	env->enemy_sprites[6].end[3].x = 725;
	env->enemy_sprites[6].end[3].y = 283;
	env->enemy_sprites[6].size[3].x = 75;
	env->enemy_sprites[6].size[3].y = 108;
	env->enemy_sprites[6].reversed[3] = 0;

	env->enemy_sprites[6].start[4].x = 523;
	env->enemy_sprites[6].start[4].y = 176;
	env->enemy_sprites[6].end[4].x = 606;
	env->enemy_sprites[6].end[4].y = 283;
	env->enemy_sprites[6].size[4].x = 84;
	env->enemy_sprites[6].size[4].y = 108;
	env->enemy_sprites[6].reversed[4] = 0;

	env->enemy_sprites[6].start[5].x = 394;
	env->enemy_sprites[6].start[5].y = 176;
	env->enemy_sprites[6].end[5].x = 478;
	env->enemy_sprites[6].end[5].y = 285;
	env->enemy_sprites[6].size[5].x = 85;
	env->enemy_sprites[6].size[5].y = 110;
	env->enemy_sprites[6].reversed[5] = 0;

	env->enemy_sprites[6].start[6].x = 291;
	env->enemy_sprites[6].start[6].y = 176;
	env->enemy_sprites[6].end[6].x = 349;
	env->enemy_sprites[6].end[6].y = 283;
	env->enemy_sprites[6].size[6].x = 59;
	env->enemy_sprites[6].size[6].y = 108;
	env->enemy_sprites[6].reversed[6] = 0;

	env->enemy_sprites[6].start[7].x = 173;
	env->enemy_sprites[6].start[7].y = 176;
	env->enemy_sprites[6].end[7].x = 246;
	env->enemy_sprites[6].end[7].y = 283;
	env->enemy_sprites[6].size[7].x = 74;
	env->enemy_sprites[6].size[7].y = 108;
	env->enemy_sprites[6].reversed[7] = 0;

	//cyber demon pursuit 3

	env->enemy_sprites[7].texture = 24;
	env->enemy_sprites[7].death_counterpart = 12;
	env->enemy_sprites[7].pursuit_sprite = 8;
	env->enemy_sprites[7].firing_sprite = 9;
	env->enemy_sprites[7].rest_sprite = 8;
	env->enemy_sprites[7].curr_sprite = 7;
	env->enemy_sprites[7].oriented = 1;
	env->enemy_sprites[7].nb_death_sprites = 8;

	env->enemy_sprites[7].start[0].x = 44;
	env->enemy_sprites[7].start[0].y = 319;
	env->enemy_sprites[7].end[0].x = 125;
	env->enemy_sprites[7].end[0].y = 428;
	env->enemy_sprites[7].size[0].x = 82;
	env->enemy_sprites[7].size[0].y = 110;
	env->enemy_sprites[7].reversed[0] = 0;

	env->enemy_sprites[7].start[1].x = 926;
	env->enemy_sprites[7].start[1].y = 319;
	env->enemy_sprites[7].end[1].x = 1020;
	env->enemy_sprites[7].end[1].y = 430;
	env->enemy_sprites[7].size[1].x = 95;
	env->enemy_sprites[7].size[1].y = 112;
	env->enemy_sprites[7].reversed[1] = 0;

	env->enemy_sprites[7].start[2].x = 806;
	env->enemy_sprites[7].start[2].y = 319;
	env->enemy_sprites[7].end[2].x = 881;
	env->enemy_sprites[7].end[2].y = 429;
	env->enemy_sprites[7].size[2].x = 76;
	env->enemy_sprites[7].size[2].y = 111;
	env->enemy_sprites[7].reversed[2] = 0;

	env->enemy_sprites[7].start[3].x = 682;
	env->enemy_sprites[7].start[3].y = 319;
	env->enemy_sprites[7].end[3].x = 761;
	env->enemy_sprites[7].end[3].y = 428;
	env->enemy_sprites[7].size[3].x = 80;
	env->enemy_sprites[7].size[3].y = 110;
	env->enemy_sprites[7].reversed[3] = 0;

	env->enemy_sprites[7].start[4].x = 555;
	env->enemy_sprites[7].start[4].y = 319;
	env->enemy_sprites[7].end[4].x = 637;
	env->enemy_sprites[7].end[4].y = 428;
	env->enemy_sprites[7].size[4].x = 83;
	env->enemy_sprites[7].size[4].y = 110;
	env->enemy_sprites[7].reversed[4] = 0;

	env->enemy_sprites[7].start[5].x = 419;
	env->enemy_sprites[7].start[5].y = 319;
	env->enemy_sprites[7].end[5].x = 510;
	env->enemy_sprites[7].end[5].y = 429;
	env->enemy_sprites[7].size[5].x = 92;
	env->enemy_sprites[7].size[5].y = 111;
	env->enemy_sprites[7].reversed[5] = 0;

	env->enemy_sprites[7].start[6].x = 295;
	env->enemy_sprites[7].start[6].y = 319;
	env->enemy_sprites[7].end[6].x = 374;
	env->enemy_sprites[7].end[6].y = 425;
	env->enemy_sprites[7].size[6].x = 80;
	env->enemy_sprites[7].size[6].y = 107;
	env->enemy_sprites[7].reversed[6] = 0;

	env->enemy_sprites[7].start[7].x = 170;
	env->enemy_sprites[7].start[7].y = 319;
	env->enemy_sprites[7].end[7].x = 250;
	env->enemy_sprites[7].end[7].y = 427;
	env->enemy_sprites[7].size[7].x = 81;
	env->enemy_sprites[7].size[7].y = 109;
	env->enemy_sprites[7].reversed[7] = 0;

	//cyber demon pursuit 4

	env->enemy_sprites[8].texture = 24;
	env->enemy_sprites[8].death_counterpart = 12;
	env->enemy_sprites[8].pursuit_sprite = 5;
	env->enemy_sprites[8].firing_sprite = 9;
	env->enemy_sprites[8].rest_sprite = 5;
	env->enemy_sprites[8].curr_sprite = 8;
	env->enemy_sprites[8].oriented = 1;
	env->enemy_sprites[8].nb_death_sprites = 8;

	env->enemy_sprites[8].start[0].x = 44;
	env->enemy_sprites[8].start[0].y = 464;
	env->enemy_sprites[8].end[0].x = 128;
	env->enemy_sprites[8].end[0].y = 572;
	env->enemy_sprites[8].size[0].x = 85;
	env->enemy_sprites[8].size[0].y = 109;
	env->enemy_sprites[8].reversed[0] = 0;

	env->enemy_sprites[8].start[1].x = 873;
	env->enemy_sprites[8].start[1].y = 464;
	env->enemy_sprites[8].end[1].x = 955;
	env->enemy_sprites[8].end[1].y = 574;
	env->enemy_sprites[8].size[1].x = 83;
	env->enemy_sprites[8].size[1].y = 111;
	env->enemy_sprites[8].reversed[1] = 0;

	env->enemy_sprites[8].start[2].x = 770;
	env->enemy_sprites[8].start[2].y = 464;
	env->enemy_sprites[8].end[2].x = 828;
	env->enemy_sprites[8].end[2].y = 574;
	env->enemy_sprites[8].size[2].x = 59;
	env->enemy_sprites[8].size[2].y = 111;
	env->enemy_sprites[8].reversed[2] = 0;

	env->enemy_sprites[8].start[3].x = 651;
	env->enemy_sprites[8].start[3].y = 464;
	env->enemy_sprites[8].end[3].x = 725;
	env->enemy_sprites[8].end[3].y = 573;
	env->enemy_sprites[8].size[3].x = 75;
	env->enemy_sprites[8].size[3].y = 110;
	env->enemy_sprites[8].reversed[3] = 0;

	env->enemy_sprites[8].start[4].x = 523;
	env->enemy_sprites[8].start[4].y = 464;
	env->enemy_sprites[8].end[4].x = 606;
	env->enemy_sprites[8].end[4].y = 572;
	env->enemy_sprites[8].size[4].x = 84;
	env->enemy_sprites[8].size[4].y = 109;
	env->enemy_sprites[8].reversed[4] = 0;

	env->enemy_sprites[8].start[5].x = 394;
	env->enemy_sprites[8].start[5].y = 464;
	env->enemy_sprites[8].end[5].x = 478;
	env->enemy_sprites[8].end[5].y = 573;
	env->enemy_sprites[8].size[5].x = 85;
	env->enemy_sprites[8].size[5].y = 110;
	env->enemy_sprites[8].reversed[5] = 0;

	env->enemy_sprites[8].start[6].x = 291;
	env->enemy_sprites[8].start[6].y = 464;
	env->enemy_sprites[8].end[6].x = 349;
	env->enemy_sprites[8].end[6].y = 571;
	env->enemy_sprites[8].size[6].x = 59;
	env->enemy_sprites[8].size[6].y = 108;
	env->enemy_sprites[8].reversed[6] = 0;

	env->enemy_sprites[8].start[7].x = 173;
	env->enemy_sprites[8].start[7].y = 464;
	env->enemy_sprites[8].end[7].x = 246;
	env->enemy_sprites[8].end[7].y = 571;
	env->enemy_sprites[8].size[7].x = 74;
	env->enemy_sprites[8].size[7].y = 108;
	env->enemy_sprites[8].reversed[7] = 0;

	//cyber_demon firing anim 1

	env->enemy_sprites[9].texture = 24;
	env->enemy_sprites[9].death_counterpart = 12;
	env->enemy_sprites[9].pursuit_sprite = 5;
	env->enemy_sprites[9].firing_sprite = 10;
	env->enemy_sprites[9].rest_sprite = 5;
	env->enemy_sprites[9].curr_sprite = 9;
	env->enemy_sprites[9].oriented = 1;
	env->enemy_sprites[9].nb_death_sprites = 8;

	env->enemy_sprites[9].start[0].x = 44;
	env->enemy_sprites[9].start[0].y = 608;
	env->enemy_sprites[9].end[0].x = 129;
	env->enemy_sprites[9].end[0].y = 717;
	env->enemy_sprites[9].size[0].x = 86;
	env->enemy_sprites[9].size[0].y = 110;
	env->enemy_sprites[9].reversed[0] = 0;

	env->enemy_sprites[9].start[1].x = 174;
	env->enemy_sprites[9].start[1].y = 608;
	env->enemy_sprites[9].end[1].x = 256;
	env->enemy_sprites[9].end[1].y = 717;
	env->enemy_sprites[9].size[1].x = 83;
	env->enemy_sprites[9].size[1].y = 110;
	env->enemy_sprites[9].reversed[1] = 0;

	env->enemy_sprites[9].start[2].x = 301;
	env->enemy_sprites[9].start[2].y = 608;
	env->enemy_sprites[9].end[2].x = 405;
	env->enemy_sprites[9].end[2].y = 717;
	env->enemy_sprites[9].size[2].x = 105;
	env->enemy_sprites[9].size[2].y = 110;
	env->enemy_sprites[9].reversed[2] = 0;

	env->enemy_sprites[9].start[3].x = 450;
	env->enemy_sprites[9].start[3].y = 608;
	env->enemy_sprites[9].end[3].x = 555;
	env->enemy_sprites[9].end[3].y = 716;
	env->enemy_sprites[9].size[3].x = 106;
	env->enemy_sprites[9].size[3].y = 109;
	env->enemy_sprites[9].reversed[3] = 0;

	env->enemy_sprites[9].start[4].x = 600;
	env->enemy_sprites[9].start[4].y = 608;
	env->enemy_sprites[9].end[4].x = 684;
	env->enemy_sprites[9].end[4].y = 717;
	env->enemy_sprites[9].size[4].x = 85;
	env->enemy_sprites[9].size[4].y = 110;
	env->enemy_sprites[9].reversed[4] = 0;

	env->enemy_sprites[9].start[5].x = 729;
	env->enemy_sprites[9].start[5].y = 608;
	env->enemy_sprites[9].end[5].x = 810;
	env->enemy_sprites[9].end[5].y = 717;
	env->enemy_sprites[9].size[5].x = 82;
	env->enemy_sprites[9].size[5].y = 110;
	env->enemy_sprites[9].reversed[5] = 0;

	env->enemy_sprites[9].start[6].x = 855;
	env->enemy_sprites[9].start[6].y = 608;
	env->enemy_sprites[9].end[6].x = 951;
	env->enemy_sprites[9].end[6].y = 717;
	env->enemy_sprites[9].size[6].x = 97;
	env->enemy_sprites[9].size[6].y = 110;
	env->enemy_sprites[9].reversed[6] = 0;

	env->enemy_sprites[9].start[7].x = 996;
	env->enemy_sprites[9].start[7].y = 608;
	env->enemy_sprites[9].end[7].x = 1110;
	env->enemy_sprites[9].end[7].y = 717;
	env->enemy_sprites[9].size[7].x = 115;
	env->enemy_sprites[9].size[7].y = 110;
	env->enemy_sprites[9].reversed[7] = 0;

	//cyber_demon firing anim 2

	env->enemy_sprites[10].texture = 24;
	env->enemy_sprites[10].death_counterpart = 12;
	env->enemy_sprites[10].pursuit_sprite = 5;
	env->enemy_sprites[10].firing_sprite = 11;
	env->enemy_sprites[10].rest_sprite = 5;
	env->enemy_sprites[10].curr_sprite = 10;
	env->enemy_sprites[10].oriented = 1;
	env->enemy_sprites[10].nb_death_sprites = 8;

	env->enemy_sprites[10].start[0].x = 44;
	env->enemy_sprites[10].start[0].y = 751;
	env->enemy_sprites[10].end[0].x = 142;
	env->enemy_sprites[10].end[0].y = 860;
	env->enemy_sprites[10].size[0].x = 99;
	env->enemy_sprites[10].size[0].y = 110;
	env->enemy_sprites[10].reversed[0] = 0;

	env->enemy_sprites[10].start[1].x = 187;
	env->enemy_sprites[10].start[1].y = 751;
	env->enemy_sprites[10].end[1].x = 280;
	env->enemy_sprites[10].end[1].y = 860;
	env->enemy_sprites[10].size[1].x = 94;
	env->enemy_sprites[10].size[1].y = 110;
	env->enemy_sprites[10].reversed[1] = 0;

	env->enemy_sprites[10].start[2].x = 325;
	env->enemy_sprites[10].start[2].y = 751;
	env->enemy_sprites[10].end[2].x = 445;
	env->enemy_sprites[10].end[2].y = 860;
	env->enemy_sprites[10].size[2].x = 121;
	env->enemy_sprites[10].size[2].y = 110;
	env->enemy_sprites[10].reversed[2] = 0;

	env->enemy_sprites[10].start[3].x = 490;
	env->enemy_sprites[10].start[3].y = 751;
	env->enemy_sprites[10].end[3].x = 608;
	env->enemy_sprites[10].end[3].y = 859;
	env->enemy_sprites[10].size[3].x = 119;
	env->enemy_sprites[10].size[3].y = 109;
	env->enemy_sprites[10].reversed[3] = 0;

	env->enemy_sprites[10].start[4].x = 653;
	env->enemy_sprites[10].start[4].y = 751;
	env->enemy_sprites[10].end[4].x = 741;
	env->enemy_sprites[10].end[4].y = 860;
	env->enemy_sprites[10].size[4].x = 89;
	env->enemy_sprites[10].size[4].y = 110;
	env->enemy_sprites[10].reversed[4] = 0;

	env->enemy_sprites[10].start[5].x = 786;
	env->enemy_sprites[10].start[5].y = 751;
	env->enemy_sprites[10].end[5].x = 878;
	env->enemy_sprites[10].end[5].y = 860;
	env->enemy_sprites[10].size[5].x = 93;
	env->enemy_sprites[10].size[5].y = 110;
	env->enemy_sprites[10].reversed[5] = 0;

	env->enemy_sprites[10].start[6].x = 923;
	env->enemy_sprites[10].start[6].y = 751;
	env->enemy_sprites[10].end[6].x = 1036;
	env->enemy_sprites[10].end[6].y = 860;
	env->enemy_sprites[10].size[6].x = 114;
	env->enemy_sprites[10].size[6].y = 110;
	env->enemy_sprites[10].reversed[6] = 0;

	env->enemy_sprites[10].start[7].x = 1081;
	env->enemy_sprites[10].start[7].y = 751;
	env->enemy_sprites[10].end[7].x = 1210;
	env->enemy_sprites[10].end[7].y = 860;
	env->enemy_sprites[10].size[7].x = 130;
	env->enemy_sprites[10].size[7].y = 110;
	env->enemy_sprites[10].reversed[7] = 0;

//FIRING ANIM 3

	env->enemy_sprites[11].texture = 24;
	env->enemy_sprites[11].death_counterpart = 12;
	env->enemy_sprites[11].pursuit_sprite = 5;
	env->enemy_sprites[11].firing_sprite = 9;
	env->enemy_sprites[11].rest_sprite = 5;
	env->enemy_sprites[11].curr_sprite = 11;
	env->enemy_sprites[11].oriented = 1;
	env->enemy_sprites[11].nb_death_sprites = 8;

	env->enemy_sprites[11].start[0].x = 44;
	env->enemy_sprites[11].start[0].y = 894;
	env->enemy_sprites[11].end[0].x = 166;
	env->enemy_sprites[11].end[0].y = 1003;
	env->enemy_sprites[11].size[0].x = 123;
	env->enemy_sprites[11].size[0].y = 110;
	env->enemy_sprites[11].reversed[0] = 0;

	env->enemy_sprites[11].start[1].x = 211;
	env->enemy_sprites[11].start[1].y = 894;
	env->enemy_sprites[11].end[1].x = 301;
	env->enemy_sprites[11].end[1].y = 1004;
	env->enemy_sprites[11].size[1].x = 91;
	env->enemy_sprites[11].size[1].y = 111;
	env->enemy_sprites[11].reversed[1] = 0;

	env->enemy_sprites[11].start[2].x = 346;
	env->enemy_sprites[11].start[2].y = 894;
	env->enemy_sprites[11].end[2].x = 439;
	env->enemy_sprites[11].end[2].y = 1003;
	env->enemy_sprites[11].size[2].x = 94;
	env->enemy_sprites[11].size[2].y = 110;
	env->enemy_sprites[11].reversed[2] = 0;

	env->enemy_sprites[11].start[3].x = 484;
	env->enemy_sprites[11].start[3].y = 894;
	env->enemy_sprites[11].end[3].x = 601;
	env->enemy_sprites[11].end[3].y = 1003;
	env->enemy_sprites[11].size[3].x = 118;
	env->enemy_sprites[11].size[3].y = 110;
	env->enemy_sprites[11].reversed[3] = 0;

	env->enemy_sprites[11].start[4].x = 646;
	env->enemy_sprites[11].start[4].y = 894;
	env->enemy_sprites[11].end[4].x = 747;
	env->enemy_sprites[11].end[4].y = 1002;
	env->enemy_sprites[11].size[4].x = 102;
	env->enemy_sprites[11].size[4].y = 109;
	env->enemy_sprites[11].reversed[4] = 0;

	env->enemy_sprites[11].start[5].x = 792;
	env->enemy_sprites[11].start[5].y = 894;
	env->enemy_sprites[11].end[5].x = 882;
	env->enemy_sprites[11].end[5].y = 1003;
	env->enemy_sprites[11].size[5].x = 91;
	env->enemy_sprites[11].size[5].y = 110;
	env->enemy_sprites[11].reversed[5] = 0;

	env->enemy_sprites[11].start[6].x = 927;
	env->enemy_sprites[11].start[6].y = 894;
	env->enemy_sprites[11].end[6].x = 1001;
	env->enemy_sprites[11].end[6].y = 1003;
	env->enemy_sprites[11].size[6].x = 75;
	env->enemy_sprites[11].size[6].y = 110;
	env->enemy_sprites[11].reversed[6] = 0;

	env->enemy_sprites[11].start[7].x = 1046;
	env->enemy_sprites[11].start[7].y = 894;
	env->enemy_sprites[11].end[7].x = 1152;
	env->enemy_sprites[11].end[7].y = 1002;
	env->enemy_sprites[11].size[7].x = 107;
	env->enemy_sprites[11].size[7].y = 109;
	env->enemy_sprites[11].reversed[7] = 0;

	// death cyber_demon
	env->enemy_sprites[12].texture = 24;
	env->enemy_sprites[12].death_counterpart = 12;
	env->enemy_sprites[12].pursuit_sprite = 12;
	env->enemy_sprites[12].firing_sprite = 12;
	env->enemy_sprites[12].rest_sprite = 12;
	env->enemy_sprites[12].curr_sprite = 12;
	env->enemy_sprites[12].oriented = 0;
	env->enemy_sprites[12].nb_death_sprites = 8;

	env->enemy_sprites[12].start[0].x = 44;
	env->enemy_sprites[12].start[0].y = 1038;
	env->enemy_sprites[12].end[0].x = 165;
	env->enemy_sprites[12].end[0].y = 1148;
	env->enemy_sprites[12].size[0].x = 122;
	env->enemy_sprites[12].size[0].y = 111;
	env->enemy_sprites[12].reversed[0] = 0;

	env->enemy_sprites[12].start[1].x = 210;
	env->enemy_sprites[12].start[1].y = 1038;
	env->enemy_sprites[12].end[1].x = 320;
	env->enemy_sprites[12].end[1].y = 1150;
	env->enemy_sprites[12].size[1].x = 111;
	env->enemy_sprites[12].size[1].y = 113;
	env->enemy_sprites[12].reversed[1] = 0;

	env->enemy_sprites[12].start[2].x = 365;
	env->enemy_sprites[12].start[2].y = 1038;
	env->enemy_sprites[12].end[2].x = 464;
	env->enemy_sprites[12].end[2].y = 1153;
	env->enemy_sprites[12].size[2].x = 100;
	env->enemy_sprites[12].size[2].y = 116;
	env->enemy_sprites[12].reversed[2] = 0;

	env->enemy_sprites[12].start[3].x = 509;
	env->enemy_sprites[12].start[3].y = 1038;
	env->enemy_sprites[12].end[3].x = 621;
	env->enemy_sprites[12].end[3].y = 1154;
	env->enemy_sprites[12].size[3].x = 113;
	env->enemy_sprites[12].size[3].y = 117;
	env->enemy_sprites[12].reversed[3] = 0;

	env->enemy_sprites[12].start[4].x = 666;
	env->enemy_sprites[12].start[4].y = 1038;
	env->enemy_sprites[12].end[4].x = 790;
	env->enemy_sprites[12].end[4].y = 1161;
	env->enemy_sprites[12].size[4].x = 125;
	env->enemy_sprites[12].size[4].y = 124;
	env->enemy_sprites[12].reversed[4] = 0;

	env->enemy_sprites[12].start[5].x = 836;
	env->enemy_sprites[12].start[5].y = 1038;
	env->enemy_sprites[12].end[5].x = 970;
	env->enemy_sprites[12].end[5].y = 1168;
	env->enemy_sprites[12].size[5].x = 136;
	env->enemy_sprites[12].size[5].y = 131;
	env->enemy_sprites[12].reversed[5] = 0;

	env->enemy_sprites[12].start[6].x = 1015;
	env->enemy_sprites[12].start[6].y = 1038;
	env->enemy_sprites[12].end[6].x = 1155;
	env->enemy_sprites[12].end[6].y = 1171;
	env->enemy_sprites[12].size[6].x = 141;
	env->enemy_sprites[12].size[6].y = 134;
	env->enemy_sprites[12].reversed[6] = 0;

	env->enemy_sprites[12].start[7].x = 1200;
	env->enemy_sprites[12].start[7].y = 1038;
	env->enemy_sprites[12].end[7].x = 1338;
	env->enemy_sprites[12].end[7].y = 1171;
	env->enemy_sprites[12].size[7].x = 139;
	env->enemy_sprites[12].size[7].y = 134;
	env->enemy_sprites[12].reversed[7] = 0;
	return (0);
}
