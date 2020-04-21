#include "env.h"

void	init_hd_sprite(t_env *env)
{
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
}
