/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   button.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/02 15:43:06 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/11/06 18:47:11 by lnicosia         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void		draw_button_text(t_button b, t_env *env)
{
	t_printable_text	text;
	t_point			pos;
	t_point			size;
	Uint32			color;

	if (!b.str || !b.font)
		return ;
	color = 0xFFFFFFFF;
	if (b.anim_state == HOVER)
		color = b.hover_color;
	else if (b.anim_state == PRESSED)
		color = b.pressed_color;
	else if (b.state == UP)
		color = b.up_color;
	else if (b.state == DOWN)
		color = b.down_color;
	TTF_SizeText(b.font, b.str, &size.x, &size.y);
	pos = new_point(b.pos.y + b.size.y / 2 - size.y / 2,
	b.pos.x + b.size.x / 2 - size.x / 2);
	text = new_printable_text(b.str, b.font, color, b.size.y);
	print_text(pos, text, env);
}

t_button	new_button(t_rectangle up, t_rectangle pressed, t_rectangle down, t_rectangle hover)
{
	t_button	new;

	new.up = up;
	new.hover = hover;
	new.pressed = pressed;
	new.down = down;
	new.img_up = NULL;
	new.img_hover = NULL;
	new.img_pressed = NULL;
	new.img_down = NULL;
	new.up_color = 0xFFFFFFFF;
	new.hover_color = 0xFFFFFFFF;
	new.pressed_color = 0xFFFFFFFF;
	new.down_color = 0xFFFFFFFF;
	new.state = UP;
	new.anim_state = REST;
	new.pos = new_point(0, 0);
	new.size = new_point(0, 0);
	new.str = NULL;
	new.font = NULL;
	new.down_action = NULL;
	new.press_action = NULL;
	return (new);
}

t_button	new_button_img(t_texture *up,
t_texture *pressed, t_texture *down, t_texture *hover)
{
	t_button	new;

	if (!up || !pressed || !down || !hover)
		ft_printf("Null texture!\n");
	new.img_up = up;
	new.img_hover = hover;
	new.img_pressed = pressed;
	new.img_down = down;
	new.up_color = 0xFFFFFFFF;
	new.hover_color = 0xFFFFFFFF;
	new.pressed_color = 0xFFFFFFFF;
	new.down_color = 0xFFFFFFFF;
	new.state = UP;
	new.anim_state = REST;
	new.down_action = NULL;
	new.press_action = NULL;
	new.str = NULL;
	new.font = NULL;
	new.pos = new_point(0, 0);
	new.size = new_point(up->surface->w, up->surface->h);
	return (new);
}

void	draw_button(t_env *env, t_button b)
{
	t_point	pos;

	pos = new_point(b.pos.y, b.pos.x);
	if (b.anim_state == HOVER)
	{
		if (b.img_hover)
			apply_surface(b.img_hover->surface, pos, b.size, env);
		else
			draw_rectangle(env, b.hover, b.pos, b.size);
	}
	else if (b.anim_state == PRESSED)
	{
		if (b.img_pressed)
			apply_surface(b.img_pressed->surface, pos, b.size, env);
		else
			draw_rectangle(env, b.pressed, b.pos, b.size);
	}
	else if (b.state == UP)
	{
		if (b.img_up)
			apply_surface(b.img_up->surface, pos, b.size, env);
		else	
			draw_rectangle(env, b.up, b.pos, b.size);
	}
	else if (b.state == DOWN)
	{
		if (b.img_down)
			apply_surface(b.img_down->surface, pos, b.size, env);
		else
			draw_rectangle(env, b.down, b.pos, b.size);
	}
	draw_button_text(b, env);
}
