#include "env.h"

/*
**	Moves the cursor according to the click
*/

int	input_box_mouse(t_input_box *box, t_env *env)
{
	int	i;
	char	*sub;
	t_point	size;
	t_point	size2;

	(void)env;
	i = 0;
	size = new_point(0, 0);
	while (box->str[i])
	{
		sub = ft_strsub(box->str, 0, i + 1);
		//ft_printf("sub = %s\n", sub);
		TTF_SizeText(box->font, sub, &size2.x, &size2.y);
		if (sub)
			ft_strdel(&sub);
		if (env->sdl.mx < box->pos.x + 5 + size2.x)
		{
			if ((box->pos.x + 5 + size2.x) - env->sdl.mx
				> env->sdl.mx - (box->pos.x + 5 + size.x))
				box->cursor = i;
			else
				box->cursor = i + 1;
			return (0);
		}
		size = size2;
		i++;
	}
	box->cursor = ft_strlen(box->str);
	return (0);
}
