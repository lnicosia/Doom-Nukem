/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:59:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/31 12:26:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "env.h"
#include "input_box_utils.h"

int	new_input_box(t_input_box *box, t_point pos, int type, void *target)
{
	if (type < 0 || type > 2 || !target)
		return (-1);
	box->size = new_point(200, 50);
	box->pos = pos;
	box->type = type;
	box->state = 1;
	box->accept_inputs = 0;
	if (type == INT)
	{
		box->int_target = (int*)target;
		if (!(box->str = ft_itoa(*((int*)target))))
			return (-1);
		set_double_stats(box);
	}
	else if (type == DOUBLE)
	{
		box->double_target = (double*)target;
		if (!(box->str = ft_itoa((int)*((double*)target))))
			return (-1);
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		box->str_target = (char**)target;
		if (box->str)
			ft_strdel(&box->str);
		box->str = ft_strdup(*(char**)target);
	}
	box->cursor = ft_strlen(box->str);
	return (0);
}

int	new_input_var(t_input_box *box, t_point pos, int type, void *target)
{
	if (type < 0 || type > 2 || !target)
		return (-1);
	box->size = new_point(96, 32);
	box->pos = pos;
	box->type = type;
	box->state = 1;
	box->accept_inputs = 0;
	if (type == INT)
	{
		box->int_target = (int*)target;
		if (!(box->str = ft_itoa(*((int*)target))))
			return (-1);
		set_double_stats(box);
	}
	else if (type == DOUBLE)
	{
		box->double_target = (double*)target;
		if (!(box->str = ft_itoa((int)*((double*)target))))
			return (-1);
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		box->str_target = (char**)target;
		if (box->str)
			ft_strdel(&box->str);
		box->str = ft_strdup(*(char**)target);
	}
	box->cursor = ft_strlen(box->str);
	box->accept_inputs = 1;
	return (0);
}

int	init_input_box(t_input_box *box, t_env *env)
{
	ft_bzero(box, sizeof(*box));
	box->type = DOUBLE;
	box->del_delay = 25;
	box->input_delay = 100;
	box->move_cursor_delay = 100;
	box->cursor_delay = 500;
	if (!(box->str = ft_strnew(0)))
		return (-1);
	box->size = new_point(200, 30);
	box->pos = new_point(env->h_w - box->size.x / 2, env->h_h - box->size.y / 2);
	box->font = env->sdl.fonts.lato20;
	return (0);
}

void	draw_input_box_content(t_input_box *box, t_env *env)
{
	t_printable_text	text;
	t_point			pos;
	t_point			size;

	if (!box->str || (box->str && box->str[0] == 0) || !box->font)
		return ;
	TTF_SizeText(box->font, box->str, &size.x, &size.y);
	pos = new_point(box->pos.y + box->size.y / 2 - size.y / 2,
	box->pos.x + 6);
	text = new_printable_text(box->str, box->font, 0x000000, box->size.x);
	print_text(pos, text, env);
}

void	draw_cursor(t_input_box *box, t_env *env)
{
	t_point	size;
	int	y;
	char	*sub;

	sub = ft_strsub(box->str, 0, box->cursor);
	TTF_SizeText(box->font, sub, &size.x, &size.y);
	y = box->pos.y + 5;
	while (y < box->pos.y + box->size.y - 4)
	{
		env->sdl.texture_pixels[box->pos.x + size.x + 5 + env->w * y] = 0xFF606060;
		y++;
	}
	ft_strdel(&sub);
}

void	draw_box_selection(t_input_box *box, t_env *env)
{
	t_point	size1;
	t_point	size2;
	size_t	start;
	size_t	end;
	int	x;
	int	y;
	char	*sub;

	if (box->select_start > box->select_end)
	{
		start = box->select_end;
		end = box->select_start;
	}
	else
	{
		start = box->select_start;
		end = box->select_end;
	}
	sub = ft_strsub(box->str, 0, start);
	TTF_SizeText(box->font, sub, &size1.x, &size1.y);
	if (sub)
		ft_strdel(&sub);
	sub = ft_strsub(box->str, 0, end);
	TTF_SizeText(box->font, sub, &size2.x, &size2.y);
	if (sub)
		ft_strdel(&sub);
	y = box->pos.y + 5;
	while (y < box->pos.y + box->size.y - 4)
	{
		x = box->pos.x + 5 + size1.x;
		while (x < box->pos.x + 5 + size2.x)
		{
			//env->sdl.texture_pixels[x + y * env->w] = blend_alpha(env->sdl.texture_pixels[x + y * env->w], 0xFF71B3D1, 128);
			env->sdl.texture_pixels[x + y * env->w] = 0xFF71B3D1;
			x++;
		}
		y++;
	}
}

void	draw_input_box(t_input_box *box, t_env *env)
{
	int	x;
	int	y;

	y = box->pos.y;
	while (y < box->pos.y + box->size.y)
	{
		x =  box->pos.x;
		while (x < box->pos.x + box->size.x)
		{
			if (x < box->pos.x + box->size.x - 3 && y < box->pos.y + box->size.y - 3
				&& x > box->pos.x + 3 && y > box->pos.y + 3)
				env->sdl.texture_pixels[x + env->w * y] = 0xFFFFFFFF;
			else
				env->sdl.texture_pixels[x + env->w * y] = 0xFF606060;
			x++;
		}
		y++;
	}
	if (box->select_start != box->select_end)
		draw_box_selection(box, env);
	draw_input_box_content(box, env);
	if (box->cursor_state
		|| env->inputs.home
		|| env->inputs.end
		|| env->inputs.right
		|| env->inputs.left
		|| env->inputs.left_click)
		draw_cursor(box, env);
	if (SDL_GetTicks() - box->cursor_timer > box->cursor_delay)
	{
		box->cursor_timer = SDL_GetTicks();
		box->cursor_state = box->cursor_state ? 0 : 1;
	}
}

void	input_box_keys(t_input_box *box, t_env *env)
{
	if (env->inputs.enter
		|| env->sdl.event.key.keysym.sym == SDLK_KP_ENTER)
	{
		validate_input(box, env);
		env->inputs.enter = 0;
		env->editor.enter_locked = 1;
	}
	else if (env->inputs.backspace)
	{
		if (box->select_start != box->select_end)
			delete_box_selection(box);
		else if (SDL_GetTicks() - box->del_timer > box->del_delay
		&& box->cursor > 0 && (box->str[box->cursor - 1] != '.'
			|| box->float_count + box->int_count <= 9))
			del_char(box, 0);
		env->inputs.backspace = 0;
	}
	else if (env->inputs.del)
	{
		if (box->select_start != box->select_end)
			delete_box_selection(box);
		else if (SDL_GetTicks() - box->del_timer > box->del_delay
		&& box->cursor < ft_strlen(box->str)
		&& (box->str[box->cursor] != '.'
			|| box->float_count + box->int_count <= 9))
			del_char(box, 1);
		env->inputs.del = 0;
	}
	else if (env->sdl.event.key.keysym.sym == SDLK_LEFT
		&& box->cursor > 0 && SDL_GetTicks()
		- box->move_cursor_timer > box->move_cursor_delay)
	{
		if (box->select_start == box->select_end)
			box->cursor--;
		else
		{
			box->cursor = ft_min(box->select_end, box->select_start);
			box->select_start = 0;
			box->select_end = 0;
		}
		box->move_cursor_timer = SDL_GetTicks();
	}
	else if (env->sdl.event.key.keysym.sym == SDLK_RIGHT
		&& box->cursor < ft_strlen(box->str) && SDL_GetTicks()
		- box->move_cursor_timer > box->move_cursor_delay)
	{
		if (box->select_start == box->select_end)
			box->cursor++;
		else
		{
			box->cursor = ft_max(box->select_end, box->select_start);
			box->select_start = 0;
			box->select_end = 0;
		}
		box->move_cursor_timer = SDL_GetTicks();
	}
	else if (env->inputs.end)
		box->cursor = ft_strlen(box->str);
	else if (env->inputs.home)
		box->cursor = 0;
	else if (env->inputs.a && env->inputs.lgui)
	{
		box->select_start = 0;
		box->select_end = ft_strlen(box->str);
	}
	else if (env->sdl.event.type == SDL_KEYUP && !env->inputs.lgui)
	{
		if (box->accept_inputs)
		{
			if (box->type == INT)
				parse_integer_input(box, env);
			else if (box->type == DOUBLE)
				parse_double_input(box, env);
			else if (box->type == STRING)
				parse_str_input(box, env);
		}
		else if (box->type == STRING && env->sdl.event.key.keysym.sym == 's')
			box->accept_inputs = 1;
	}
	else if (env->inputs.left_click)
	{
		input_box_mouse(box, env);
		if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN
			&& (env->sdl.mx < box->pos.x
			|| env->sdl.mx > box->pos.x + box->size.x
			|| env->sdl.my < box->pos.y
			|| env->sdl.my > box->pos.y + box->size.y))
		{
			box->state = 0;
			if (env->editor.in_game)
			{
				SDL_SetRelativeMouseMode(1);
				SDL_GetRelativeMouseState(&env->sdl.mouse_x,
				&env->sdl.mouse_y);
				SDL_GetRelativeMouseState(&env->sdl.mouse_x,
				&env->sdl.mouse_y);
			}
		}
	}
	else if (env->sdl.event.type == SDL_MOUSEBUTTONUP)
		box->selecting = 0;

	else
		return ;
	if (!box->state)
		return ;
	/*ft_printf("size = %d\n", ft_strlen(box->str));
	ft_printf("cursor index = %d\n", box->cursor);
	ft_printf("period index = %d\n", box->period_index);
	if (box->cursor > 0)
		ft_printf("backspace char = '%c'\n", box->str[box->cursor - 1]);
	else
		ft_printf("backspace char = ''\n");
	ft_printf("del char = '%c'\n", box->str[box->cursor]);
	ft_printf("int count = %d\n", box->int_count);
	ft_printf("float count = %d\n", box->float_count);
	ft_printf("total digit count = %d\n", box->float_count + box->int_count);
	ft_printf("minus state = %d\n", box->minus);
	ft_printf("period state = %d\n", box->period);
	ft_printf("\n");*/
}
