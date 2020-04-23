#include "draw_skybox.h"

void	set_skybox_limits3(t_skybox_drawer *drawer, t_env *env)
{
	if (drawer->wall_data.mode == BOTTOM_WALL)
	{
		drawer->min = drawer->render->neighbor_current_floor;
		drawer->max = drawer->render->current_floor;
		drawer->skybox->texture_w =
		env->skyboxes[abs(drawer->render->texture) - 1].
		textures[drawer->skybox->texture].surface->w;
		drawer->skybox->texture_h =
		env->skyboxes[abs(drawer->render->texture) - 1].
		textures[drawer->skybox->texture].surface->h;
	}
	else
	{
		drawer->min = drawer->render->current_ceiling;
		drawer->max = drawer->render->neighbor_current_ceiling;
		drawer->skybox->texture_w =
		env->skyboxes[abs(drawer->render->texture) - 1].
		textures[drawer->skybox->texture].surface->w;
		drawer->skybox->texture_h =
		env->skyboxes[abs(drawer->render->texture) - 1].
		textures[drawer->skybox->texture].surface->h;
	}
}

void	set_skybox_limits2(t_skybox_drawer *drawer, t_env *env)
{
	if (drawer->wall_data.mode == FLOOR)
	{
		drawer->min = drawer->render->current_floor;
		drawer->max = env->ymax[drawer->x];
		drawer->skybox->texture_w =
		env->skyboxes[abs(env->sectors[drawer->render->sector->num].
		floor_texture) - 1].textures[drawer->skybox->texture].surface->w;
		drawer->skybox->texture_h =
		env->skyboxes[abs(env->sectors[drawer->render->sector->num].
		floor_texture) - 1].textures[drawer->skybox->texture].surface->h;
	}
	else if (drawer->wall_data.mode == WALL)
	{
		drawer->min = drawer->render->current_ceiling;
		drawer->max = drawer->render->current_floor;
		drawer->skybox->texture_w =
		env->skyboxes[abs(drawer->render->texture) - 1].
		textures[drawer->skybox->texture].surface->w;
		drawer->skybox->texture_h =
		env->skyboxes[abs(drawer->render->texture) - 1].
		textures[drawer->skybox->texture].surface->h;
	}
	else
		set_skybox_limits3(drawer, env);
}

void	set_skybox_limits(t_skybox_drawer *drawer, t_env *env)
{
	if ((drawer->wall_data.mode == CEILING
	  	&& env->selected_ceiling == drawer->render->sector->num)
		|| (drawer->wall_data.mode == FLOOR
		&& env->selected_floor == drawer->render->sector->num)
		|| ((drawer->wall_data.mode == WALL
		|| drawer->wall_data.mode == UPPER_WALL
		|| drawer->wall_data.mode == BOTTOM_WALL)
		&& env->sectors[drawer->render->sector->num].selected[drawer->render->i]))
		drawer->skybox->selected = 1;
	if (drawer->wall_data.mode == CEILING)
	{
		drawer->min = env->ymin[drawer->x];
		drawer->max = drawer->render->current_ceiling;
		drawer->skybox->texture_w =
		env->skyboxes[abs(env->sectors[drawer->render->sector->num].
		ceiling_texture) - 1].textures[drawer->skybox->texture].surface->w;
		drawer->skybox->texture_h =
		env->skyboxes[abs(env->sectors[drawer->render->sector->num].
		ceiling_texture) - 1].textures[drawer->skybox->texture].surface->h;
	}
	else
		set_skybox_limits2(drawer, env);
}

void	compute_skybox_vline2(t_skybox_drawer *drawer, t_env *env)
{
	drawer->skybox->current_floor = ft_clamp(drawer->skybox->max_floor,
			env->ymin[drawer->x], env->ymax[drawer->x]);
	drawer->skybox->line_height =
	drawer->skybox->max_floor - drawer->skybox->max_ceiling;
	drawer->skybox->ceiling_start =
	drawer->skybox->max_ceiling - drawer->skybox->ceiling_horizon;
	drawer->skybox->floor_start =
	drawer->skybox->max_floor - drawer->skybox->floor_horizon;
}

void	compute_skybox_vline(t_skybox_drawer *drawer, t_env *env)
{
	if (env->skybox[drawer->skybox->i + 1].vz)
		drawer->skybox->texture_w /= env->skybox[drawer->skybox->i + 1].vz;
	else
		drawer->skybox->texture_w /= env->skybox[drawer->skybox->i].clipped_vz2;
	drawer->skybox->alpha = (drawer->x - drawer->v1.x) / drawer->v1.xrange;
	drawer->skybox->clipped_alpha = (drawer->x - drawer->v1.clipped_x1)
	/ drawer->v1.clipped_xrange;
	drawer->skybox->z = 1.0 / ((1.0 - drawer->skybox->alpha) / drawer->v1.vz
			+ drawer->skybox->alpha / env->skybox[drawer->skybox->i + 1].vz);
	drawer->skybox->divider = 1 / (env->skybox[drawer->skybox->i + 1].vz
			+ drawer->skybox->alpha * drawer->v1.zrange);
	drawer->skybox->z = drawer->v1.zcomb * drawer->skybox->divider;
	drawer->skybox->texel.x = (drawer->v1.x0z1 + drawer->skybox->alpha
	* drawer->v1.xzrange) * drawer->skybox->divider;
	drawer->skybox->texel.y = (drawer->v1.y0z1 + drawer->skybox->alpha
	* drawer->v1.yzrange) * drawer->skybox->divider;
	drawer->skybox->max_ceiling = drawer->skybox->clipped_alpha
	* drawer->v1.ceiling_range + drawer->v1.c1;
	drawer->skybox->current_ceiling = ft_clamp(drawer->skybox->max_ceiling,
			env->ymin[drawer->x], env->ymax[drawer->x]);
	drawer->skybox->max_floor = drawer->skybox->clipped_alpha
	* drawer->v1.floor_range + drawer->v1.f1;
	compute_skybox_vline2(drawer, env);
}
