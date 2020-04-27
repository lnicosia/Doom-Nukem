#include "render.h"

void	init_drawer(t_drawer *drawer, int sprite, t_render *render, t_env *env)
{
	drawer->i = render->current_ceiling - 1;
	drawer->sprite_w =
	env->sprite_textures[env->object_sprites[drawer->sector->wall_sprites
	[render->i].sprite[sprite]].texture].surface->w;
	drawer->pos = drawer->sector->wall_sprites[render->i].pos[sprite].y
	/ (drawer->sector->ceiling - drawer->sector->floor);
	drawer->start = env->object_sprites[drawer->sector->wall_sprites[render->i].
	sprite[sprite]].start[0].y;
	drawer->end = env->object_sprites[drawer->sector->wall_sprites[render->i].
	sprite[sprite]].end[0].y;
	drawer->x = render->sprite_x;
}

void	hover_on_wall_sprite(t_drawer *drawer, int sprite, t_render *render,
t_env *env)
{
	if (env->playing
		&& drawer->sector->wall_sprites[render->i].nb_press_events[sprite])
	{
		if (render->z < 10)
		{
			env->hovered_wall_sprite_wall = render->i;
			env->hovered_wall_sprite_sprite = sprite;
			env->hovered_wall_sprite_sector = drawer->sector->num;
		}
		else
		  	reset_hover(env);
	}
}

int		click_on_wall_sprite(t_drawer *drawer, int sprite, t_render *render,
t_env *env)
{
	if (((env->editor.tab && render->x == env->sdl.mx
	  	&& drawer->i == env->sdl.my) || (!env->editor.tab
		&& render->x == env->h_w && drawer->i == env->h_h)))
	{
		if (env->shooting && render->z <= env->weapons[env->player.
			curr_weapon].range && start_event(&env->sectors[drawer->sector->
			num].wall_sprites[render->i].shoot_events[sprite],
			&env->sectors[drawer->sector->num].wall_sprites[render->i].
			nb_shoot_events[sprite], env))
		{
			env->fatal_error = 1;
			return (1);
		}
		if (env->editor.select)
		{
			reset_selection(env);
			if (env->editor.selected_events == 2)
				env->editor.selected_events = 1;
			env->selected_wall_sprite_wall = render->i;
			env->selected_wall_sprite_sprite = sprite;
			env->editor.selected_sector = drawer->sector->num;
			tabs_gestion(env);
		}
		hover_on_wall_sprite(drawer, sprite, render, env);
	}
	return (0);
}

void	apply_wall_sprite_filters(t_drawer *drawer, int sprite,
t_render *render, t_env *env)
{
	if (!env->editor.select
		&& env->editor.selected_sector == drawer->sector->num
		&& env->selected_wall_sprite_wall == render->i
		&& env->selected_wall_sprite_sprite == sprite)
		env->sdl.texture_pixels[drawer->coord] =
		blend_alpha(env->sdl.texture_pixels[drawer->coord], 0x1ABC9C, 128);
	else if (env->playing && env->hovered_wall_sprite_wall == render->i
			&& env->hovered_wall_sprite_sprite == sprite)
		env->sdl.texture_pixels[drawer->coord] =
		blend_alpha(env->sdl.texture_pixels[drawer->coord],
		env->press_wall_sprite_color, env->press_wall_sprite_intensity);
}
