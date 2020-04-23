#include "render.h"

t_v2	set_v2(int i)
{
	t_v2	res;

	res = new_v2(0, 0);
	if (i == 1)
		res.x = 10;
	else if (i == 2)
		res = new_v2(10, 10);
	else if (i == 3)
		res.y = 10;
	return (res);
}

void	precompute_skybox_values(int i, t_env *env)
{
	t_v2 pos1;
	t_v2 pos2;

	pos1 = set_v2(i);
	pos2 = set_v2(i + 1);
	env->skybox[i].clipped_xrange = env->skybox[i].clipped_x2
		- env->skybox[i].clipped_x1;
	env->skybox[i].xrange = env->skybox[i + 1].x - env->skybox[i].x;
	env->skybox[i].floor_range = env->skybox[i].f2 - env->skybox[i].f1;
	env->skybox[i].ceiling_range = env->skybox[i].c2 - env->skybox[i].c1;
	if (env->skybox[i + 1].vz)
		env->skybox[i].texture_scale[0].x = env->skyboxes[2].textures[0 + i].
			surface->w / env->skybox[i + 1].vz;
	else
		env->skybox[i].texture_scale[0].x = env->skyboxes[2].textures[0 + i].
			surface->w / env->skybox[i].clipped_vz2;
	env->skybox[i].texture_scale[0].y =
	env->skyboxes[2].textures[0 + i].surface->h;
	env->skybox[i].x0z1 = pos1.x * env->skybox[i + 1].vz;
	env->skybox[i].x1z0 = pos2.x * env->skybox[i].vz;
	env->skybox[i].xzrange = env->skybox[i].x1z0 - env->skybox[i].x0z1;
	env->skybox[i].y0z1 = pos1.y * env->skybox[i + 1].vz;
	env->skybox[i].y1z0 = pos2.y * env->skybox[i].vz;
	env->skybox[i].yzrange = env->skybox[i].y1z0 - env->skybox[i].y0z1;
	env->skybox[i].zrange = env->skybox[i].vz - env->skybox[i + 1].vz;
	env->skybox[i].zcomb = env->skybox[i].vz * env->skybox[i + 1].vz;
}
