#include "render.h"

void	set_clipped_coords(int i, t_camera *camera, t_sector *sector,
		t_v2 inter)
{
	if (camera->v[sector->num][i].vz < camera->near_z)
	{
		camera->v[sector->num][i].clipped_vx1 = inter.x;
		camera->v[sector->num][i].clipped_vz1 = inter.y;
	}
	else
	{
		camera->v[sector->num][i].clipped_vx1 = camera->v[sector->num][i].vx;
		camera->v[sector->num][i].clipped_vz1 = camera->v[sector->num][i].vz;
	}
	if (camera->v[sector->num][i + 1].vz < camera->near_z)
	{
		camera->v[sector->num][i].clipped_vx2 = inter.x;
		camera->v[sector->num][i].clipped_vz2 = inter.y;
	}
	else
	{
		camera->v[sector->num][i].clipped_vx2 =
		camera->v[sector->num][i + 1].vx;
		camera->v[sector->num][i].clipped_vz2 =
		camera->v[sector->num][i + 1].vz;
	}
}

void	get_intersections2(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	camera->v[sector->num][i].clipped_pos_x2 =
	camera->v[sector->num][i].clipped_vx2 * camera->angle_sin
	+ camera->v[sector->num][i].clipped_vz2 * camera->angle_cos + camera->pos.x;
	camera->v[sector->num][i].clipped_pos_y2 =
		camera->v[sector->num][i].clipped_vz2 * camera->angle_sin
		- camera->v[sector->num][i].clipped_vx2 * camera->angle_cos
		+ camera->pos.y;
	camera->v[sector->num][i].clipped_vf2 = get_floor_at_pos(sector,
		new_v3(camera->v[sector->num][i].clipped_pos_x2,
		camera->v[sector->num][i].clipped_pos_y2, 0), env);
	camera->v[sector->num][i].clipped_vc2 = get_ceiling_at_pos(sector,
		new_v3(camera->v[sector->num][i].clipped_pos_x2,
		camera->v[sector->num][i].clipped_pos_y2, 0), env);
}

void	get_intersections(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	t_v2	inter;

	inter = get_intersection(
		new_v2(camera->v[sector->num][i].vx, camera->v[sector->num][i].vz),
		new_v2(camera->v[sector->num][i + 1].vx,
		camera->v[sector->num][i + 1].vz),
		new_v2(camera->near_left, camera->near_z),
		new_v2(camera->near_right, camera->near_z));
	set_clipped_coords(i, camera, sector, inter);
	camera->v[sector->num][i].clipped_pos_x1 =
	camera->v[sector->num][i].clipped_vx1 * camera->angle_sin
	+ camera->v[sector->num][i].clipped_vz1 * camera->angle_cos + camera->pos.x;
	camera->v[sector->num][i].clipped_pos_y1 =
		camera->v[sector->num][i].clipped_vz1 * camera->angle_sin
		- camera->v[sector->num][i].clipped_vx1 * camera->angle_cos
		+ camera->pos.y;
	camera->v[sector->num][i].clipped_vf1 = get_floor_at_pos(sector,
		new_v3(camera->v[sector->num][i].clipped_pos_x1,
		camera->v[sector->num][i].clipped_pos_y1, 0), env);
	camera->v[sector->num][i].clipped_vc1 = get_ceiling_at_pos(sector,
		new_v3(camera->v[sector->num][i].clipped_pos_x1,
		camera->v[sector->num][i].clipped_pos_y1, 0), env);
	get_intersections2(i, camera, sector, env);
}
