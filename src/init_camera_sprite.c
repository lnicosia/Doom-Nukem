#include "env.h"

void	init_camera_sprite(t_env *env)
{
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
}
