#include "render.h"

void	new_wall_bullet_hole(t_drawer *drawer, t_render *render, t_env *env)
{
	env->new_wall_bullet_hole = 1;
	env->new_bullet_hole_pos =
	new_v2(((render->alpha / render->camera->v[drawer->sector->num]
	[render->i + 1].vz) / ((1 - render->alpha) / render->
	camera->v[drawer->sector->num][render->i].vz + render->alpha
	/ render->camera->v[drawer->sector->num][render->i + 1].vz))
	* drawer->sector->wall_width[render->i], drawer->yalpha
	* (drawer->sector->ceiling - drawer->sector->floor));
	env->new_bullet_hole_sector = drawer->sector->num;
	env->new_bullet_hole_wall = render->i;
}

void	click_on_wall(t_drawer *drawer, t_render *render, t_env *env)
{
	if ((env->editor.tab && drawer->vline.x == env->sdl.mx
	  	&& drawer->i == env->sdl.my) || (!env->editor.tab
		&& drawer->vline.x == env->h_w && drawer->i == env->h_h))
	{
		if (env->editor.select)
		{
			reset_selection(env);
			env->editor.selected_sector = drawer->sector->num;
			env->editor.selected_wall = render->i;
			env->selected_wall1
			= env->sectors[render->sector->num].vertices[render->i];
			env->selected_wall2
			= env->sectors[render->sector->num].vertices[render->i + 1];
			tabs_gestion(env);				
			env->editor.just_selected = 1;
		}
		if (env->shooting
			&& render->z <= env->weapons[env->player.curr_weapon].range)
		  	new_wall_bullet_hole(drawer, render, env);
		if (env->playing)
			reset_hover(env);
	}
}

void	get_wall_x(t_drawer *drawer, t_render *render, t_env *env)
{
	if (env->options.mipmapping)
		render->map_lvl = get_current_wall_map(render->texture, render->z,
		render, env);
	drawer->x = render->alpha
		* render->camera->v[render->sector->num][render->i]
		.texture_scale[render->map_lvl].x * render->z
		- render->camera->v[render->sector->num][render->i]
		.texture_align[render->map_lvl].x;
	if (drawer->x != drawer->x)
		return ;
	if (drawer->x >= render->texture_w || drawer->x < 0)
		drawer->x = ft_abs((int)drawer->x % render->texture_w);
	drawer->x = ft_fclamp(drawer->x, 0, render->texture_w);
	drawer->i = drawer->vline.start;
}

void	get_wall_y(t_drawer *drawer, t_render *render)
{
	drawer->yalpha = (drawer->i - render->no_slope_current_ceiling)
	/ render->line_height;
	drawer->y = drawer->yalpha * render->camera->v[render->sector->num]
	[render->i].texture_scale[render->map_lvl].y
	- render->camera->v[render->sector->num][render->i].
	texture_align[render->map_lvl].y;
	if (drawer->y >= render->texture_h || drawer->y < 0)
		drawer->y = ft_abs((int)drawer->y % render->texture_h);
}
