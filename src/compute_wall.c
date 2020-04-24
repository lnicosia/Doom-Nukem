#include "render.h"

void	clip_wall(int i, t_camera *camera, t_sector *sector, t_env *env)
{
	if ((camera->v[sector->num][i].vz < camera->near_z
				&& camera->v[sector->num][i + 1].vz < camera->near_z)
			|| (camera->v[sector->num][i].vz > camera->far_z
				&& camera->v[sector->num][i + 1].vz > camera->far_z)
			|| (camera->v[sector->num][i].vx < camera->far_left
				&& camera->v[sector->num][i + 1].vx < camera->far_left)
			|| (camera->v[sector->num][i].vx > camera->far_right
				&& camera->v[sector->num][i + 1].vx > camera->far_right))
		camera->v[sector->num][i].draw = 0;
	else
		camera->v[sector->num][i].draw = 1;
	get_intersections(i, camera, sector, env);
}

void	compute_wall(int i, t_camera *camera, t_sector *sector, t_env *env)
{
	double	vx;
	double	vz;

	vx = env->vertices[sector->vertices[i]].x - camera->pos.x;
	vz = env->vertices[sector->vertices[i]].y - camera->pos.y;
	camera->v[sector->num][i].vx = vx * camera->angle_sin
		- vz * camera->angle_cos;
	camera->v[sector->num][i].vz = vx * camera->angle_cos
		+ vz * camera->angle_sin;
}
