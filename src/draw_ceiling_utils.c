#include "env.h"
#include "render.h"

void	get_ceiling_z(t_render *render, t_drawer *drawer, t_env *env)
{
	drawer->coord = render->x + env->w * drawer->i;
	drawer->alpha =
	(render->max_ceiling - drawer->i) / render->ceiling_height;
	drawer->divider = 1 / (render->camera->near_z + drawer->alpha
	* render->zrange);
	drawer->z = render->z_near_z * drawer->divider;
}

void	get_texels(t_render *render, t_drawer *drawer)
{
	drawer->y = (render->texel_y_near_z + drawer->alpha
	* render->texel_y_camera_range) * drawer->divider;
	drawer->x = (render->texel_x_near_z + drawer->alpha
	* render->texel_x_camera_range) * drawer->divider;
}
