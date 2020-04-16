#include "env.h"
#include "draw_grid_walls.h"

void	draw_minimap_near_z(t_env *env)
{
	t_point	p0;
	t_point	p1;

	p0.x = env->player.camera.angle_cos * env->player.camera.near_z
	* env->options.minimap_scale + env->minimap_pos.x;
	p0.y = env->player.camera.angle_sin * env->player.camera.near_z
	* env->options.minimap_scale + env->minimap_pos.y;
	p1.x = p0.x + env->player.camera.perp_cos * env->w
	* env->options.minimap_scale;
	p1.y = p0.y + env->player.camera.perp_sin * env->w
	* env->options.minimap_scale;
	p0.x = p0.x - env->player.camera.perp_cos * env->w
	* env->options.minimap_scale;
	p0.y = p0.y - env->player.camera.perp_sin * env->w
	* env->options.minimap_scale;
	p0.x = env->minimap_pos.x;
	p0.y = env->minimap_pos.y;
	p1.x = env->player.camera.angle_cos * env->player.camera.near_z
	* env->options.minimap_scale + p0.x;
	p1.y = env->player.camera.angle_sin * env->player.camera.near_z
	* env->options.minimap_scale + p0.y;
	draw_line_minimap(p0, p1, env, 0xFFFFFFFF);
}

void	draw_minimap_fov_lines(t_v3 triangle[3], t_env *env)
{
	t_point	p0;
	t_point	p1;

	p0.x = triangle[2].x;
	p0.y = triangle[2].y;
	p1.x = triangle[1].x;
	p1.y = triangle[1].y;
	draw_line_minimap(p0, p1, env, 0xFFFFFF00);
	triangle[2] = new_v3(
		(env->player.camera.angle_cos * env->player.camera.far_z
		- env->player.camera.angle_sin * env->player.camera.far_right)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.angle_sin * env->player.camera.far_z
		+ env->player.camera.angle_cos * env->player.camera.far_right)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	fill_triangle_minimap(triangle, env);
	p0.x = triangle[0].x;
	p0.y = triangle[0].y;
	p1.x = triangle[2].x;
	p1.y = triangle[2].y;
	draw_line_minimap(p0, p1, env, 0xFFFFFF00);	
}

void	draw_minimap_fov(t_v3 triangle[3], t_env *env)
{
	triangle[2] = new_v3(
		(env->player.camera.near_left_pos.x - env->player.pos.x)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.near_left_pos.y - env->player.pos.y)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	triangle[1] = new_v3(
		(env->player.camera.angle_cos * env->player.camera.far_z
		- env->player.camera.angle_sin * env->player.camera.far_left)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.angle_sin * env->player.camera.far_z
		+ env->player.camera.angle_cos * env->player.camera.far_left)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	triangle[0] = new_v3(
		(env->player.camera.near_right_pos.x - env->player.pos.x)
		* env->options.minimap_scale + env->minimap_pos.x,
		(env->player.camera.near_right_pos.y - env->player.pos.y)
		* env->options.minimap_scale + env->minimap_pos.y, 0);
	fill_triangle_minimap(triangle, env);
}

void	draw_minimap_player_sprites(t_point *pos, t_point *size, t_env *env)
{
	if (pos->y >= env->minimap_pos.x - env->minimap_size.y / 2
		&& pos->y + size->y <= env->minimap_pos.x + env->minimap_size.x / 2
		&& pos->x >= env->minimap_pos.y - env->minimap_size.y / 2
		&& pos->x + size->x <= env->minimap_pos.y + env->minimap_size.y / 2)
		apply_sprite(env->object_sprites[CAMERA_SPRITE], *pos, *size, env);
	pos->y = env->minimap_pos.x + (env->player.starting_pos.x
			- env->player.pos.x) * env->options.minimap_scale;
	pos->x = env->minimap_pos.y + (env->player.starting_pos.y
			- env->player.pos.y) * env->options.minimap_scale;
	if (pos->y >= env->minimap_pos.x - env->minimap_size.y / 2
		&& pos->y + size->y <= env->minimap_pos.x + env->minimap_size.x / 2
		&& pos->x >= env->minimap_pos.y - env->minimap_size.y / 2
		&& pos->x + size->x <= env->minimap_pos.y + env->minimap_size.y / 2)
	{
		if (env->editor.selected_start_player == 1)
			apply_sprite_selected(env->object_sprites[DOOM_GUY_FACE],
			*pos, *size, env);
		else
			apply_sprite(env->object_sprites[DOOM_GUY_FACE], *pos, *size, env);
	}
}

void	draw_minimap_player(t_env *env)
{
	t_point	pos;
	t_point	size;
	t_v3	triangle[3];

	size = new_point(7 * env->options.minimap_scale,
			7 * env->options.minimap_scale);
	pos = new_point(env->minimap_pos.y - size.y / 2,
			env->minimap_pos.x - size.x / 2);
	draw_minimap_player_sprites(&pos, &size, env);
	draw_minimap_fov(triangle, env);
	draw_minimap_fov_lines(triangle, env);
	draw_minimap_near_z(env);
}
