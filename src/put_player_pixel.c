#include "env.h"
#include "render.h"

void	apply_player_filter(t_sprite_drawer *drawer, t_env *env)
{
	if (!env->editor.select
		&& env->editor.selected_start_player == 1)
		env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
		blend_alpha(env->sdl.texture_pixels[drawer->x + drawer->y
		* env->w], 0x1abc9c, 128);
}

void	put_player_pixel(t_render_object *orender, t_sprite_drawer *drawer,
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
	apply_player_filter(drawer, env);
	env->zbuffer[drawer->x + drawer->y * env->w] =
	drawer->object->rotated_pos.z;
}
