#include "env.h"

void	init_raygun_sprite(t_env *env)
{
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
}
