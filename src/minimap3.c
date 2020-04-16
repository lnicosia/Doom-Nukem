#include "env.h"
#include "draw_grid_walls.h"

void	draw_minimap_sector_num(t_env *env, t_sector *sector)
{
	t_grid_wall_drawer	drawer;
	int					i;

	i = 0;
	drawer.nb_angles = 0;
	drawer.sector = sector;
	drawer.center = new_point(0, 0);
	if (sector->num == env->player.sector)
		drawer.color = 0x00FF00FF;
	else
		drawer.color = 0xFFFFFFFF;
	while (i < sector->nb_vertices - 1)
	{
	  	get_current_wall_angle(i, &drawer, env);
		i++;
	}
	get_last_wall_angle(i, &drawer, env);
	print_minimap_sector_num(&drawer, env);
}

void	draw_object_minimap(int i, t_object *object, t_sprite *sprite,
t_env *env)
{
	t_point		pos;
	t_point		size;

	object = &env->objects[i];
	if (!object->exists)
		return ;
	sprite = &env->object_sprites[object->sprite];
	size = new_point(6 * env->options.minimap_scale,
		6 * env->options.minimap_scale / (sprite->size[0].x
			/ (double)sprite->size[0].y));
	pos.y = env->minimap_pos.x + (object->pos.x - env->player.pos.x)
		* env->options.minimap_scale - size.y / 2;
	pos.x = env->minimap_pos.y + (object->pos.y - env->player.pos.y)
		* env->options.minimap_scale - size.x / 2;
	if (pos.y < env->minimap_pos.x - env->minimap_size.y / 2
		|| pos.y + size.y > env->minimap_pos.x + env->minimap_size.x / 2
		|| pos.x < env->minimap_pos.y - env->minimap_size.y / 2
		|| pos.x + size.x > env->minimap_pos.y + env->minimap_size.y / 2)
		return ;
	if (env->selected_object == i)
		apply_sprite_selected(*sprite, pos, size, env);
	else
		apply_sprite(*sprite, pos, size, env);
}

void	draw_objects_minimap(t_env *env)
{
	int			i;

	i = -1;
	while (++i < env->nb_objects)
	{
	  	draw_object_minimap(i, &env->objects[i],
		&env->object_sprites[env->objects[i].sprite], env);
	}
}
