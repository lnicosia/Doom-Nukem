#include "env.h"

int		set_new_string_input_box(t_input_box *box, void *target)
{
	box->str_target = (char**)target;
	if (box->str)
		ft_strdel(&box->str);
	if (*(char**)target)
	{
		if (!(box->str = ft_strdup(*(char**)target))
			&& ft_strlen(*(char**)target))
			return (-1);
	}
	else
	{
		if (!(box->str = ft_strnew(0)))
			return (-1);
	}
	return (0);
}
