/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:38:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/03 11:45:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_buttons(t_env *env, t_confirmation_box box)
{
	draw_rectangle(env,
			new_rectangle(0xFF888888, 0xFF444444, 1, 2),
			new_point(env->w / 2 - box.size.x / 2 + 5 , env->h / 2 - box.size.y / 3),
			new_point(box.size.x - 10, 25));
	draw_button(env, box.yes);
}

t_point	get_box_size(t_confirmation_box box)
{
	t_point	text_size;
	t_point	yes_size;
	t_point	size;

	TTF_SizeText(box.font, box.str, &text_size.x, &text_size.y);
	TTF_SizeText(box.font, "Yes", &yes_size.x, &yes_size.y);
	size.x = ft_max(yes_size.x * 3, text_size.x + 20);
	size.y = ft_max(yes_size.y * 3, 300);
	size.y = size.x;
	//ft_printf("size.x = %d size.y = %d\n", size.x, size.y);
	return (size);
}

int		new_confirmation_box(t_confirmation_box *box, t_env *env)
{
	if (!box->str)
		return (custom_error("Confirmation box message is empty"));
	if (!box->font)
		return (custom_error("Confirmation box font is NULL"));
	box->size = get_box_size(*box);
	(void)env;
	//new_buttons(box, env);
	return (1);
}

void	draw_confirmation_box(t_confirmation_box box, t_env *env)
{
	draw_rectangle(env,
			new_rectangle(0xFF444444, 0xFF888888, 1, 2),
			new_point(env->w / 2 - box.size.x / 2, env->h / 2 - box.size.y / 2),
			new_point(box.size.x, box.size.y));
	print_text(new_point(env->h / 2 - box.size.y / 3, env->w / 2 - box.size.x / 2 + 10),
			new_printable_text(box.str,
			box.font,
			0xFFFFFFFF,
			0),
			env);
	draw_buttons(env, box);
}
