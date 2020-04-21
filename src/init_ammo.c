#include "env.h"

void	init_shotgun_ammo(t_env *env)
{
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
}

void	init_rocket_ammo(t_env *env)
{
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
}

void	init_regular_ammo(t_env *env)
{
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
}

void	init_energy_cell(t_env *env)
{
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
}

void	init_ammo(t_env *env)
{
  	init_shotgun_ammo(env);
  	init_rocket_ammo(env);
  	init_regular_ammo(env);
  	init_energy_cell(env);
}
