/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:38:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/02 17:53:51 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	draw_buttons(t_env *env)
{
}

t_point	get_box_size(t_confirmation_box box)
{
	t_point	text_size;
	t_point	yes_size;
	t_point	size;

	TTF_SizeText(box.font, box.str, &text_size.x, &text_size.y);
	TTF_SizeText(box.font, "Yes", &yes_size.x, &yes_size.y);
	size.x = ft_max(yes_size.x * 3, text_size.x + 10);
	size.y = ft_max(yes_size.y * 3, text_size.y + 10);
	return (size);
}

int		confirmation_box(t_confirmation_box box, t_env *env)
{
	t_point	size;

	if (!box.str)
		return (custom_error("Confirmation box message is empty"));
	if (!box.font)
		return (custom_error("Confirmation font is NULL"));
	size = get_box_size(box);
	draw_rectangle(env,
			new_rectangle(0xFFDDDDDD, 0xFF888888, 1, 2),
			new_point(env->w / 2 - size.x / 2, env->h / 2 - size.y / 2),
			new_point(size.x, size.y));
	draw_buttons(env);
	print_text(new_point(env->h / 2 - size.y / 4, env->w / 2 - size.x / 4),
			new_printable_text(box.str,
			box.font,
			0xFFFFFFFF,
			0),
			env);
	(void)box;
	(void)env;
	return (1);
}
