#include "input_box_utils.h"

int		parse_double_input3(char new, t_input_box *box)
{
	if (new == '.')
	{
		box->period_index = box->cursor - 1;
		box->float_count = ft_strlen(box->str) - box->period_index
		- 1;
		box->int_count -= box->float_count;
		box->period++;
	}
	if (new == '-')
		box->minus++;
	if (ft_strlen(box->str) - box->minus >= 9 && !box->period)
	{
		box->cursor = 9 + box->minus;
		box->period_index = box->cursor;
		if (add_char(box, '.'))
			return (-1);
		box->period++;
	}
	if (box->int_count >= 9)
		box->cursor = ft_strlen(box->str);
	return (0);
}

int		parse_double_input2(char new, t_input_box *box)
{
	if (ft_strlen(box->str) - box->minus >= 9 && !box->period && new != '.')
	{
		box->cursor = 9 + box->minus;
		box->period_index = box->cursor;
		if (add_char(box, '.'))
			return (-1);
		box->period++;
	}
	if (add_char(box, new))
		return (-1);
	if (ft_isdigit(new))
	{
		if (box->cursor - 1 <= box->period_index || !box->period)
		{
			box->int_count++;
			box->period_index++;
		}
		if (box->period && box->cursor - 1 > box->period_index)
			box->float_count++;
	}
	return (parse_double_input3(new, box));
}

int		parse_double_input(t_input_box *box, t_env *env)
{
	char	new;

	new = ft_getchar(env->sdl.event.key.keysym.sym, env->inputs.shift);
	if (!new)
		return (0);
	if (!ft_isdigit(new))
	{
		if ((new != '.' && new != '-')
			|| (new == '.' && box->period)
			|| (new == '-' && box->cursor && (box->select_start != 0
			|| box->select_end != ft_strlen(box->str))))
			return (0);
	}
	else if ((box->float_count >= 5 && box->cursor > box->period_index)
		|| (box->minus && !box->cursor)
		|| (box->int_count >= 9 && box->cursor <= box->period_index))
	{
		if (!(box->select_start == 0 && box->select_end == ft_strlen(box->str)))
			return (0);
	}
	return (parse_double_input2(new, box));
}
