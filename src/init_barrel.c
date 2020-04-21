#include "env.h"

void	init_barrel_normal(t_env *env)
{
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
}

void	init_barrel_exploding(t_env *env)
{
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
}


void	init_barrel_exploding_two(t_env *env)
{
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
}

void	init_barrel_exploding_three(t_env *env)
{
	env->object_sprites[21].start[7].x = 552;
	env->object_sprites[21].start[7].y = 198;
	env->object_sprites[21].end[7].x = 630;
	env->object_sprites[21].end[7].y = 281;
	env->object_sprites[21].size[7].x = 79;
	env->object_sprites[21].size[7].y = 84;
}

void	init_barrel(t_env *env)
{
  	init_barrel_normal(env);
  	init_barrel_exploding(env);
  	init_barrel_exploding_two(env);
  	init_barrel_exploding_three(env);
}
