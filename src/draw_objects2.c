#include "render.h"

void	update_objects_z(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].sector == env->sectors[env->selected_floor].num)
			env->objects[i].pos.z =
			get_floor_at_pos(&env->sectors[env->selected_floor],
			new_v3(env->objects[i].pos.x, env->objects[i].pos.y, 0), env);
		i++;
	}
}

int		get_object_direction2(t_object *object, double angle)
{
	if (angle < object->angle - 22.5 && angle >= object->angle - 67.5)
		return (3);
	else if (angle < object->angle - 67.5 && angle >= object->angle - 112.5)
		return (2);
	else if (angle < object->angle - 112.5 && angle >= object->angle - 157.5)
		return (1);
	else if (angle < object->angle - 157.5 && angle >= object->angle - 202.5)
		return (0);
	else if (angle < object->angle - 202.5 && angle >= object->angle - 247.5)
		return (7);
	else if (angle < object->angle - 247.5 && angle >= object->angle - 292.5)
		return (6);
	else if (angle < object->angle - 292.5 && angle >= object->angle - 337.5)
		return (5);
	else if (angle < object->angle - 337.5)
		return (4);
	else
		return (0);
}

int		get_object_direction(t_object *object)
{
	double	angle;

	angle = (int)((atan2(object->translated_pos.z, object->translated_pos.x))
	* CONVERT_DEGREES) % 360;
	if (angle < 0)
		angle += 360;
	if (angle >= object->angle - 22.5 && angle < object->angle + 22.5)
		return (4);
	else if (angle >= object->angle + 22.5 && angle < object->angle + 67.5)
		return (5);
	else if (angle >= object->angle + 67.5 && angle < object->angle + 112.5)
		return (6);
	else if (angle >= object->angle + 112.5 && angle < object->angle + 157.5)
		return (7);
	else if (angle >= object->angle + 157.5 && angle < object->angle + 202.5)
		return (0);
	else if (angle >= object->angle + 202.5 && angle < object->angle + 247.5)
		return (1);
	else if (angle >= object->angle + 247.5 && angle < object->angle + 292.5)
		return (2);
	else if (angle >= object->angle + 292.5 && angle < object->angle + 337.5)
		return (3);
	else if (angle >= object->angle + 337.5)
		return (4);
	else
	  	return (get_object_direction2(object, angle));
}

void	get_sprite_y(t_render_object *orender, t_sprite_drawer *drawer)
{
	drawer->yalpha = (drawer->y - orender->y1) / orender->yrange;
	drawer->texty = (1.0 - drawer->yalpha)
	* drawer->sprite->start[orender->index].y + drawer->yalpha
	* drawer->sprite->end[orender->index].y;
}

void	apply_object_filter(t_sprite_drawer *drawer, t_env *env)
{
	if (!env->editor.select
	  	&& env->selected_object == drawer->object->num)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		blend_alpha(env->sdl.texture_pixels[drawer->x + drawer->y
		* env->w], 0x1abc9c, 128);
}
