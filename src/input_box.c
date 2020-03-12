/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:59:10 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/12 15:33:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "env.h"
#include "input_box_utils.h"

int	new_input_box(t_input_box *box, t_point pos, int type, void *target)
{
	size_t	len;
	size_t	dec_len;
	char	*tmp;

	if (type < 0 || type > 3 || !target)
		return (-1);
	box->size = new_point(250, 60);
	box->pos = pos;
	box->rectangle = new_rectangle(0xFFFFFFFF, 0xFF606060, 1, 3);
	box->type = type;
	box->state = 1;
	box->accept_inputs = 0;
	len = 0;
	if (type == INT)
	{
		box->int_target = (int*)target;
		if (box->str)
			ft_strdel(&box->str);
		if (!(box->str = ft_itoa(*((int*)target))))
			return (-1);
		if (*box->int_target < 0)
			box->minus = 1;
		set_double_stats(box);
	}
	else if (type == DOUBLE)
	{
		box->double_target = (double*)target;
		if (box->str)
			ft_strdel(&box->str);
		len = get_double_len(*(box->double_target));
		dec_len = get_decimal_len(*(box->double_target));
		if (!(box->str = ft_strnew(len)))
			return (-1);
		if (*box->double_target < 0)
			box->minus = 1;
		if (dec_len)
		{
			box->period = 1;
			box->period_index = len - dec_len + box->minus;
		}
		ft_snprintf(box->str, len + 1, "%.5f", dec_len,
		*(box->double_target));
		set_double_stats(box);
	}
	else if (type == UINT32)
	{
		box->uint32_target = (Uint32*)target;
		if (box->str)
			ft_strdel(&box->str);
		if (!(tmp = ft_strnew(15)))
			return (-1);
		ft_snprintf(tmp, 15, "0x%X", *box->uint32_target);
		if (!(box->str = ft_strdup(tmp)))
			return (-1);
		ft_strdel(&tmp);
		if (*box->uint32_target < 0)
			box->minus = 1;
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		box->str_target = (char**)target;
		if (box->str)
			ft_strdel(&box->str);
		box->str = ft_strdup(*(char**)target);
	}
	if (find_input_box_max_char(box))
		return (-1);
	box->cursor = ft_strlen(box->str);
	box->select_start = 0;
	box->select_end = ft_strlen(box->str);
	box->check = 0;
	box->update = 0;
	box->count = 0;
	box->error_message = "Error";
	return (0);
}

int	new_input_var(t_input_box *box, t_point pos, int type, void *target)
{
	size_t	len;
	size_t	dec_len;
	char	*tmp;

	if (type < 0 || type > 3 || !target)
		return (-1);
	box->size = new_point(192, 32);
	box->pos = pos;
	box->rectangle = new_rectangle(0xFFFFFFFF, 0xFF606060, 1, 3);
	box->type = type;
	box->state = 1;
	box->accept_inputs = 0;
	len = 0;
	if (type == INT)
	{
		box->int_target = (int*)target;
		if (!(box->str = ft_itoa(*((int*)target))))
			return (-1);
		if (*box->int_target < 0)
			box->minus = 1;
		set_double_stats(box);
	}
	else if (type == DOUBLE)
	{
		box->double_target = (double*)target;
		if (box->str)
			ft_strdel(&box->str);
		len = get_double_len(*(box->double_target));
		dec_len = get_decimal_len(*(box->double_target));
		if (!(box->str = ft_strnew(len)))
			return (-1);
		if (*box->double_target < 0)
			box->minus = 1;
		if (dec_len)
		{
			box->period = 1;
			box->period_index = len - dec_len;
		}
		ft_snprintf(box->str, len + 1, "%.5f", dec_len,
		*(box->double_target));
		set_double_stats(box);
	}
	else if (type == UINT32)
	{
		box->uint32_target = (Uint32*)target;
		if (box->str)
			ft_strdel(&box->str);
		if (!(tmp = ft_strnew(15)))
			return (-1);
		ft_snprintf(tmp, 15, "0x%X", *box->uint32_target);
		if (!(box->str = ft_strdup(tmp)))
			return (-1);
		if (*box->uint32_target < 0)
			box->minus = 1;
		ft_strdel(&tmp);
		set_double_stats(box);
	}
	else if (type == STRING)
	{
		box->str_target = (char**)target;
		if (box->str)
			ft_strdel(&box->str);
		box->str = ft_strdup(*(char**)target);
	}
	if (find_input_box_max_char(box))
		return (-1);
	box->cursor = ft_strlen(box->str);
	box->accept_inputs = 1;
	box->select_start = 0;
	box->select_end = ft_strlen(box->str);
	box->check = 0;
	box->update = 0;
	box->count = 0;
	box->error_message = "Error";
	return (0);
}

int		init_input_box(t_input_box *box, t_env *env)
{
	ft_bzero(box, sizeof(*box));
	box->type = DOUBLE;
	box->del_delay = 25;
	box->input_delay = 50;
	box->move_cursor_delay = 100;
	box->cursor_delay = 500;
	if (!(box->str = ft_strnew(0)))
		return (-1);
	box->size = new_point(200, 30);
	box->pos = new_point(env->h_w - box->size.x / 2, env->h_h - box->size.y / 2);
	box->font = env->sdl.fonts.lato20;
	return (0);
}

/*
**	Finds the maximum number of characters that can fit in one line
**	of the input box
*/

int		find_input_box_max_char(t_input_box *box)
{
	char	*str;
	size_t  len;
	t_point size;

	size = new_point(0, 0);
	len = 1;
	if (!(str = ft_strnew(0)))
		return (-1);
	while (size.x < box->size.x * 0.99)
	{
		ft_strdel(&str);
		if (!(str = ft_strnew(len)))
			return (-1);
		ft_memset(str, 'a', len);
		TTF_SizeText(box->font, str, &size.x, &size.y);
		len++;
	}
	ft_strdel(&str);
	box->line_size = len;
	box->max_lines = (box->size.y * 0.99) / (double)size.y;
	return (0);
}

/*
**	Find the largest string of te current text characters that fit in one line
*/

static char	*get_current_line(t_input_box *box, char *str, char *tmp)
{
	size_t	len;
	char	*res;
	t_point	size;

	size = new_point(0, 0);
	(void)tmp;
	len = 1;
	if (!(res = ft_strnew(0)))
		return (0);
	while (size.x < box->size.x * 0.99 && len <= ft_strlen(str))
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(str, 0, len)))
			return (0);
		TTF_SizeText(box->font, res, &size.x, &size.y);
		len++;
	}
	if (size.x >= box->size.x * 0.99)
	{
		ft_strdel(&res);
		if (!(res = ft_strsub(str, 0, len - 2)))
			return (0);
	}
	return (res);
}

/*
**	Draws the cursor
*/

int	draw_cursor(t_input_box *box, t_point pos, char *sub, t_env *env)
{
	t_point	size;
	int		y;

	if (!sub)
		return (-1);
	TTF_SizeText(box->font, sub, &size.x, &size.y);
	y = pos.x;
	while (y < pos.x + size.y)
	{
		env->sdl.texture_pixels[pos.y + size.x + env->w * y] =
		0xFF606060;
		y++;
	}
	ft_strdel(&sub);
	return (0);
}

/*
**	Highlight the current selection with blue
*/

int		draw_box_selection(t_input_box *box, t_point pos, char *str, t_env *env)
{
	t_point	size1;
	t_point	size2;
	size_t	start;
	size_t	end;
	int		x;
	int		y;
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
	start = ft_max(0, start - box->count);
	end = ft_min(end - box->count, ft_strlen(str));
	sub = ft_strsub(str, 0, start);
	TTF_SizeText(box->font, sub, &size1.x, &size1.y);
	if (sub)
		ft_strdel(&sub);
	if (!(sub = ft_strsub(str, start, end - start)))
	{
		ft_printf("select start = %d\n", box->select_start);
		ft_printf("select end = %d\n", box->select_end);
		ft_printf("char count = %d\n", box->count);
		ft_printf("{red}Input box selection sub str empty!\n");
		ft_printf("Start = %d\n", start);
		ft_printf("End = %d{reset}\n", end);
		return (-1);
	}
	TTF_SizeText(box->font, sub, &size2.x, &size2.y);
	if (sub)
		ft_strdel(&sub);
	y = pos.x;
	while (y < pos.x + size2.y)
	{
		x = pos.y + size1.x;
		while (x < pos.y + size1.x + size2.x)
		{
			env->sdl.texture_pixels[x + y * env->w] = 0xFF71B3D1;
			x++;
		}
		y++;
	}
	return (0);
}

/*
**	If the string is too big to fit in one line
**	Prints the text in multiple lines
*/

int		split_box_text(t_input_box *box, t_env *env)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*str;
	int		i;
	t_point text_size;
	t_point	pos;

	i = 0;
	pos = new_point(box->pos.y + box->size.y / 100,
	box->pos.x + box->size.x / 100);
	if (!(str = ft_strdup(box->str)))
		return (-1);
	TTF_SizeText(box->font, str, &text_size.x, &text_size.y);
	while (ft_strlen(str)
		&& pos.x + text_size.y <= box->pos.y + box->size.y * 0.99)
	{
		if (!(tmp = get_current_line(box, str, tmp)))
			return (-1);
		//ft_printf("tmp = '%s'\n", tmp);
		if (ft_strlen(tmp) < ft_strlen(str) && ft_strrchr(tmp, ' '))
		{
			if (!(tmp2 = ft_strsub(tmp, 0,
				ft_strlen(tmp) - ft_strlen(ft_strrchr(tmp, ' ')))))
				return (-1);
			ft_strdel(&tmp);
		}
		else
			tmp2 = tmp;
		//ft_printf("tmp2 = '%s'\n", tmp2);
		//ft_printf("str = '%s'\n", str);
		if (!(tmp3 = ft_strsub(str, ft_strlen(tmp2),
			ft_strlen(str) - ft_strlen(tmp2))))
			return (-1);
		ft_strdel(&str);
		str = tmp3;
		TTF_SizeText(box->font, tmp2, &text_size.x, &text_size.y);
		// Draw input box selection
		if (box->select_start != box->select_end
			&& ((box->select_start <= ft_strlen(tmp2) + box->count
			&& box->select_end >= box->count)
			|| (box->select_end <= ft_strlen(tmp2) + box->count
			&& box->select_start >= box->count)))
		{
			if (draw_box_selection(box, pos, tmp2, env))
				return (-1);
		}
		if (env->inputs.left_click
			&& env->sdl.mx >= pos.y && env->sdl.mx <= pos.y + box->size.x
			&& env->sdl.my >= pos.x && env->sdl.my <= pos.x + text_size.y)
		{
			if (input_box_mouse(box, pos, tmp2, env))
				return (-1);
		}
		if (box->cursor > box->count
			&& box->cursor <= box->count + ft_strlen(tmp2)
			&& (box->cursor_state || env->inputs.home || env->inputs.end
			|| env->inputs.right || env->inputs.left || env->inputs.left_click))
		{
			if (draw_cursor(box, pos, ft_strsub(tmp2, 0,
				box->cursor - box->count), env))
				return (-1);
		}
		print_text(pos, new_printable_text(tmp2, box->font,
		0x333333FF, 0), env);
		box->count += ft_strlen(tmp2);
		ft_strdel(&tmp2);
		pos.x += text_size.y + 5;
		i++;
	}
	ft_strdel(&str);
	return (0);
}

int		draw_input_box_content(t_input_box *box, t_env *env)
{
	t_printable_text	text;
	t_point				pos;
	t_point				size;

	if (!box->str || (box->str && box->str[0] == 0) || !box->font)
		return (0);
	TTF_SizeText(box->font, box->str, &size.x, &size.y);
	box->count = 0;
	if (size.x < box->size.x * 0.99 || box->type != STRING)
	{
		pos = new_point(box->pos.y + box->size.y / 2 - size.y / 2,
		box->pos.x + 6);
		if (box->select_start != box->select_end
			&& draw_box_selection(box, pos, box->str, env))
			return (-1);
		if (env->inputs.left_click && input_box_mouse(box, pos, box->str, env))
			return (-1);
		text = new_printable_text(box->str, box->font, 0x333333FF, box->size.x);
		print_text(pos, text, env);
		if (box->cursor_state || env->inputs.home || env->inputs.end
			|| env->inputs.right || env->inputs.left || env->inputs.left_click)
		{
			if (draw_cursor(box, pos, ft_strsub(box->str, 0, box->cursor), env))
				return (-1);
		}
	}
	else if (box->type == STRING)
	{
		if (split_box_text(box, env))
			return (-1);
	}
	return (0);
}

int		draw_input_box(t_input_box *box, t_env *env)
{
	draw_rectangle(env, box->rectangle, box->pos, box->size);
	if (draw_input_box_content(box, env))
		return (-1);
	if (SDL_GetTicks() - box->cursor_timer > box->cursor_delay)
	{
		box->cursor_timer = SDL_GetTicks();
		box->cursor_state = box->cursor_state ? 0 : 1;
	}
	return (0);
}

int		input_box_keys(t_input_box *box, t_env *env)
{
	int		res;

	if (env->inputs.enter
		|| env->sdl.event.key.keysym.sym == SDLK_KP_ENTER)
	{
		if ((res = validate_input(box, env)) == -1)
			return (-1);
		else if (res == 1)
			return (0);
		env->inputs.enter = 0;
		env->editor.enter_locked = 1;
	}
	else if (env->inputs.backspace)
	{
		if (box->select_start != box->select_end
			&& (box->type != UINT32 || (box->select_start > 2
			&& box->select_end > 2)))
			delete_box_selection(box);
		else if (SDL_GetTicks() - box->del_timer > box->del_delay
		&& box->cursor > 0 && (box->str[box->cursor - 1] != '.'
			|| box->float_count + box->int_count <= 9)
		&& (box->type != UINT32 || box->cursor > 2))
			del_char(box, 0);
		env->inputs.backspace = 0;
	}
	else if (env->inputs.del)
	{
		if (box->select_start != box->select_end
			&& (box->type != UINT32 || (box->select_start > 2
			&& box->select_end > 2)))
			delete_box_selection(box);
		else if (SDL_GetTicks() - box->del_timer > box->del_delay
		&& box->cursor < ft_strlen(box->str)
		&& (box->str[box->cursor] != '.'
			|| box->float_count + box->int_count <= 9)
		&& (box->type != UINT32 || box->cursor > 1))
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
		&& box->cursor <= ft_strlen(box->str) && SDL_GetTicks()
		- box->move_cursor_timer > box->move_cursor_delay)
	{
		if (box->select_start == box->select_end
			&& box->cursor < ft_strlen(box->str))
			box->cursor++;
		else
		{
			if (box->cursor < ft_strlen(box->str))
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
		if (box->accept_inputs
			&& (!box->text_size || ft_strlen(box->str) < box->text_size))
		{
			if (box->type == INT)
				parse_integer_input(box, env);
			else if (box->type == DOUBLE)
				parse_double_input(box, env);
			else if (box->type == UINT32)
				parse_uint32_input(box, env);
			else if (box->type == STRING)
				parse_str_input(box, env);
		}
		else if (box->type == STRING && env->sdl.event.key.keysym.sym == 's')
			box->accept_inputs = 1;
	}
	else if (env->inputs.left_click)
	{
		box->click = 1;
		if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN
			&& (env->sdl.mx < box->pos.x
			|| env->sdl.mx > box->pos.x + box->size.x
			|| env->sdl.my < box->pos.y
			|| env->sdl.my > box->pos.y + box->size.y))
		{
			box->state = 0;
			if (env->editor.in_game && !env->editor.tab)
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
		return (0);
	if (!box->state)
		return (0);
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
	return (0);
}
