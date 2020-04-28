#include "env.h"

void		draw_rectangle_button(t_env *env, t_button b)
{
	if (b.anim_state == HOVER)
		draw_rectangle(env, b.hover, b.pos, b.size_up);
	else if (b.anim_state == PRESSED)
		draw_rectangle(env, b.pressed, b.pos, b.size_pressed);
	else if (b.state == UP)
		draw_rectangle(env, b.up, b.pos, b.size_up);
	else if (b.state == DOWN)
		draw_rectangle(env, b.down, b.pos, b.size_down);
}

void		draw_image_button(t_env *env, t_button b, t_point pos)
{
	if (b.anim_state == HOVER)
		apply_surface(b.img_hover, pos, b.size_up, env);
	else if (b.anim_state == PRESSED)
		apply_surface(b.img_pressed, pos, b.size_pressed, env);
	else if (b.state == UP)
		apply_surface(b.img_up, pos, b.size_up, env);
	else if (b.state == DOWN)
		apply_surface(b.img_down, pos, b.size_down, env);
}

void		draw_button(t_env *env, t_button b, char *str)
{
	if (!b.img_up || !b.img_pressed || !b.img_down || !b.img_hover)
	{
	  	draw_rectangle_button(env, b);
	}
	else
	{
	  	draw_image_button(env, b, new_point(b.pos.y, b.pos.x));
	}
	draw_button_text(b, str, env);
}
