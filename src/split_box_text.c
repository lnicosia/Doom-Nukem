#include "input_box_utils.h"

int		box_cursor(t_input_box *box, char *str, char *tmp2, t_env *env)
{
	if (box->cursor > box->count
		&& box->cursor <= box->count + ft_strlen(tmp2)
		&& (box->cursor_state || env->inputs.home || env->inputs.end
		|| env->inputs.right || env->inputs.left || env->inputs.up
		|| env->inputs.down || env->inputs.left_click))
	{
		if (draw_cursor(box, box->current_line_pos, ft_strsub(tmp2, 0,
			box->cursor - box->count), env))
			return (-1);
		if (box->up)
		{
			box->up = 0;
			box->cursor = box->prec_count + box->cursor_in_line;
		}
		if (box->down && ft_strlen(str))
		{
			box->down = 0;
			box->change_cursor_line = 1;
		}
	}
	return (0);
}

char	*get_current_str(t_input_box *box, char **str)
{
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	if (!(tmp = get_current_box_line(box, *str)))
		return (0);
	if (ft_strlen(tmp) < ft_strlen(*str) && ft_strrchr(tmp, ' '))
	{
		if (!(tmp2 = ft_strsub(tmp, 0,
			ft_strlen(tmp) - ft_strlen(ft_strrchr(tmp, ' ')))))
			return (0);
		ft_strdel(&tmp);
	}
	else
		tmp2 = tmp;
	if (!(tmp3 = ft_strsub(*str, ft_strlen(tmp2),
		ft_strlen(*str) - ft_strlen(tmp2))))
		return (0);
	ft_strdel(str);
	*str = tmp3;
	return (tmp2);
}

int		draw_current_line2(t_input_box *box, char **str, char *tmp2, t_env *env)
{
	if (env->inputs.left_click
		&& env->sdl.mx >= box->current_line_pos.y
		&& env->sdl.mx <= box->current_line_pos.y + box->size.x
		&& env->sdl.my >= box->current_line_pos.x
		&& env->sdl.my <= box->current_line_pos.x
		+ box->current_text_size.y)
	{
	  	if (input_box_mouse(box, box->current_line_pos, tmp2, env))
			return (-1);
	}
	box->cursor_in_line = box->cursor - box->count;
	if (box_cursor(box, *str, tmp2, env))
	  	return (-1);
	print_text(box->current_line_pos, new_printable_text(tmp2, box->font,
	0x333333FF, 0), env);
	box->prec_count = box->count;
	box->count += ft_strlen(tmp2);
	ft_strdel(&tmp2);
	box->current_line_pos.x += box->current_text_size.y + 5;
	return (0);
}

int		draw_current_line(t_input_box *box, char **str, t_env *env)
{
	char	*tmp2;

	if (box->change_cursor_line)
		box->cursor =
		ft_min(box->count + box->cursor_in_line, ft_strlen(box->str));
		box->change_cursor_line = 0;
	if (!(tmp2 = get_current_str(box, str)))
	  	return (-1);
	TTF_SizeText(box->font, tmp2, &box->current_text_size.x,
	&box->current_text_size.y);
	if (box->select_start != box->select_end
		&& ((box->select_start <= ft_strlen(tmp2) + box->count
		&& box->select_end >= box->count)
		|| (box->select_end <= ft_strlen(tmp2) + box->count
		&& box->select_start >= box->count)))
	{
		if (draw_box_selection(box, box->current_line_pos, tmp2, env))
			return (-1);
	}
	return (draw_current_line2(box, str, tmp2, env));
}

/*
**	If the string is too big to fit in one line
**	Prints the text in multiple lines
*/

int		split_box_text(t_input_box *box, t_env *env)
{
	char	*str;

	box->current_line_pos = new_point(box->pos.y + box->size.y / 100,
	box->pos.x + box->size.x / 100);
	box->cursor_in_line = 0;
	if (!(str = ft_strdup(box->str)))
		return (-1);
	TTF_SizeText(box->font, str, &box->current_text_size.x,
	&box->current_text_size.y);
	while (ft_strlen(str)
		&& box->current_line_pos.x + box->current_text_size.y <= box->pos.y
		+ box->size.y * 0.99)
	{
	  	if (draw_current_line(box, &str, env))
		  	return (-1);
	}
	ft_strdel(&str);
	return (0);
}
