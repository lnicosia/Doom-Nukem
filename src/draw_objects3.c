#include "render.h"

void	put_object_pixel(t_render_object *orender, t_sprite_drawer *drawer,
t_env *env)
{
	if (!env->options.lighting || (!drawer->sector->brightness
		&& !drawer->sector->intensity))
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w];
	else if (!drawer->sector->brightness)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_color(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w],
		orender->light_color, orender->intensity);
	else if (!drawer->sector->intensity)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_brightness(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w],
		orender->brightness);
	else
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		apply_light_both(drawer->texture->str[drawer->textx
		+ drawer->texty * drawer->texture->surface->w],
		orender->light_color, orender->intensity,
		orender->brightness);
	apply_object_filter(drawer, env);
	env->zbuffer[drawer->x + drawer->y * env->w] =
	drawer->object->rotated_pos.z;
}

void	draw_vline_object(t_render_object *orender, t_sprite_drawer *drawer,
t_env *env)
{
	Uint32			*texture_pixels;

	texture_pixels = drawer->texture->str;
	drawer->xalpha = (drawer->x - orender->x1) / orender->xrange;
	if (drawer->sprite->reversed[orender->index])
		drawer->xalpha = 1.0 - drawer->xalpha;
	drawer->textx = (1.0 - drawer->xalpha)
	* drawer->sprite->start[orender->index].x + drawer->xalpha
	* drawer->sprite->end[orender->index].x;
	if ((drawer->object->rotated_pos.z < env->zbuffer[drawer->x
	  	+ drawer->y * env->w] && texture_pixels[drawer->textx + drawer->texty
		* drawer->texture->surface->w] != 0xFFC10099))
	{
		env->objects[drawer->object->num].seen = 1;
		if (env->editor.select && ((env->editor.tab
		&& drawer->x == env->sdl.mx && drawer->y == env->sdl.my)
		|| (!env->editor.tab && drawer->x == env->h_w
		&& drawer->y == env->h_h)))
		{
			reset_selection(env);
			env->selected_object = drawer->object->num;
			tabs_gestion(env);
		}
		put_object_pixel(orender, drawer, env);
	}
}

void	*object_loop(void *param)
{
	t_env			*env;
	t_render_object	*orender;
	t_sprite_drawer	drawer;

	orender = ((t_object_thread*)param)->orender;
	env = ((t_object_thread*)param)->env;
	drawer.object = ((t_object_thread*)param)->object;
	drawer.sprite = &env->object_sprites[drawer.object->sprite];
	drawer.texture = &env->sprite_textures[drawer.sprite->texture];
	drawer.xend = ((t_object_thread*)param)->xend;
	drawer.y = orender->ystart;
	drawer.yend = orender->yend;
	drawer.sector = &env->sectors[drawer.object->sector];
	drawer.param = param;
	while (++drawer.y < drawer.yend)
	{
		drawer.x = ((t_object_thread*)drawer.param)->xstart;
		get_sprite_y(orender, &drawer);
		while (drawer.x < drawer.xend)
		{
		  	draw_vline_object(orender, &drawer, env);
			drawer.x++;
		}
	}
	return (NULL);
}

int		threaded_object_loop(t_object *object, t_render_object *orender,
t_env *env)
{
	t_object_thread	ot[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		ot[i].env = env;
		ot[i].object = object;
		ot[i].orender = orender;
		ot[i].xstart = orender->xstart + (orender->xend - orender->xstart)
		/ (double)THREADS * i;
		ot[i].xend = orender->xstart + (orender->xend - orender->xstart)
		/ (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, object_loop, &ot[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}
