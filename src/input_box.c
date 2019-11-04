/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 09:59:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/04 11:49:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "env.h"
#include "input_box_utils.h"

int	init_input_box(t_input_box *box, t_env *env)
{
	box->state = 1;
	box->type = 2;
	box->del_delay = 100;
	if (!(box->str = ft_strdup("|")))
		return (-1);
	box->pos = new_point(env->h_w, env->h_h);
	box->font = env->sdl.fonts.playfair_display20;
	box->size = new_point(200, 30);
	return (0);
}

void	draw_input_box_content(t_input_box *box, t_env *env)
{
	t_printable_text	text;
	t_point			pos;

	if (!box->str || (box->str && box->str[0] == 0))
		return ;
	pos = new_point(box->pos.y, box->pos.x + 5);
	text = new_printable_text(box->str, box->font, 0x000000, box->size.x);
	print_text(pos, text, env);
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
	draw_input_box_content(box, env);
}

void	input_box_keys(t_input_box *box, t_env *env)
{
	char	*new;

	new = NULL;
	if (env->inputs.enter)
	{
		box->state = 0;
		env->inputs.enter = 0;
		if (box->str)
			ft_strdel(&box->str);
	}
	else if (env->inputs.backspace
		&& SDL_GetTicks() - box->del_timer > box->del_delay)
	{
		box->del_timer = SDL_GetTicks();
		if (!box->str)
		{
			env->sdl.event.key.keysym.sym = 0;
			return ;
		}
		if (ft_strlen(box->str) > 0)
		if (!(new = ft_strsub(box->str, 0, ft_strlen(box->str) - 1)))
			return ;
		ft_strdel(&box->str);
		box->str = new;
	}
	else if (box->type == 0)
		parse_integer_input(box, env);
	else if (box->type == 1)
		parse_double_input(box, env);
	else if (box->type == 2)
		parse_str_input(box, env);
}
