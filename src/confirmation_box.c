/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 16:38:58 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/27 14:41:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	confirmation_box_keyup_ig(t_confirmation_box *box, t_env *env)
{
	if (((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& env->sdl.my >= box->no.pos.y
					&& env->sdl.my <= box->no.pos.y + box->no.size.y
					&& env->sdl.mx >= box->yes.pos.x
					&& env->sdl.mx <= box->yes.pos.x + box->yes.size.x)
				|| env->sdl.event.key.keysym.sym == SDLK_RETURN))
		{
			box->state = 0;
			ft_strdel(&box->str);
			SDL_SetRelativeMouseMode(1);
			SDL_GetRelativeMouseState(&env->sdl.mx, &env->sdl.my);
			respawn(env);
		}
	else
		box->yes.state = 0;
	if ((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& env->sdl.my >= box->no.pos.y
					&& env->sdl.my <= box->no.pos.y + box->no.size.y
					&& env->sdl.mx >= box->no.pos.x
					&& env->sdl.mx <= box->no.pos.x + box->no.size.x)
			|| env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
		{
			box->state = 0;
			ft_strdel(&box->str);
			env->running = 0;
		}
	else
		box->no.state = 0;
}

void	confirmation_box_keyup(t_confirmation_box *box, t_env *env)
{
	int	i;

	i = 0;
	if (((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& env->sdl.my >= box->no.pos.y
					&& env->sdl.my <= box->no.pos.y + box->no.size.y
					&& env->sdl.mx >= box->yes.pos.x
					&& env->sdl.mx <= box->yes.pos.x + box->yes.size.x)
				|| env->sdl.event.key.keysym.sym == SDLK_RETURN)
			&& env->editor.selected_sector != -1)
		{
			delete_sector(env, env->editor.selected_sector);
			delete_invalid_sectors(env);
			delete_invalid_vertices(env);
			box->state = 0;
			ft_strdel(&box->str);
			env->editor.selected_sector = -1;
			clear_portals(env);
			while (i < env->nb_sectors)
			{
				create_portals(env, env->sectors[i]);
				i++;
			}
		}
	else
		box->yes.state = 0;
	if ((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& env->sdl.my >= box->no.pos.y
					&& env->sdl.my <= box->no.pos.y + box->no.size.y
					&& env->sdl.mx >= box->no.pos.x
					&& env->sdl.mx <= box->no.pos.x + box->no.size.x)
			|| env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
		{
			box->state = 0;
			ft_strdel(&box->str);
		}
	else
		box->no.state = 0;
}

void	confirmation_box_keys(t_confirmation_box *box, t_env *env)
{
	if ((env->sdl.my >= box->no.pos.y
			&& env->sdl.my <= box->no.pos.y + box->no.size.y
			&& env->sdl.mx >= box->yes.pos.x
			&& env->sdl.mx <= box->yes.pos.x + box->yes.size.x
			&& env->inputs.left_click) || env->inputs.enter)
		box->yes.state = 1;
	if ((env->sdl.my >= box->no.pos.y
			&& env->sdl.my <= box->no.pos.y + box->no.size.y
			&&env->sdl.mx >= box->no.pos.x
			&& env->sdl.mx <= box->no.pos.x + box->no.size.x
			&& env->inputs.left_click) || env->inputs.backspace)
		box->no.state = 1;
}

void	new_buttons(t_confirmation_box *box, int height, t_env *env)
{
	box->no = new_button(new_rectangle(0xFFDD0000, 0xFF990000, 1, 2),
			new_rectangle(0xFF990000, 0xFF990000, 1, 2),
			new_rectangle(0xFF990000, 0xFF990000, 1, 2));
	box->no.size.x = box->size.x / 2;
	box->no.size.y = height + 5;
	box->no.pos.x = env->w / 2 - box->size.x / 2;
	box->no.pos.y = env->h / 2 + box->size.y / 2 - height - 5;
	box->yes = new_button(new_rectangle(0xFF00DD00, 0xFF009900, 1, 2),
			new_rectangle(0xFF009900, 0xFF009900, 1, 2),
			new_rectangle(0xFF009900, 0xFF009900, 1, 2));
	box->yes.size.x = box->size.x / 2;
	box->yes.size.y = height + 5;
	box->yes.pos.x = env->w / 2;
	box->yes.pos.y = env->h / 2 + box->size.y / 2 - height - 5;
}

void	draw_buttons(t_confirmation_box box, t_env *env)
{
	/*draw_rectangle(env,
			new_rectangle(0xFF888888, 0xFF444444, 1, 2),
			new_point(env->w / 2 - box.size.x / 2 + 5 , env->h / 2 - box.size.y / 3),
			new_point(box.size.x - 10, 25));*/
	draw_button(env, box.yes);
	draw_button(env, box.no);
}

int		get_box_size(t_confirmation_box *box)
{
	t_point	text_size;
	t_point	yes_size;

	TTF_SizeText(box->font, box->str, &text_size.x, &text_size.y);
	TTF_SizeText(box->font, "Yes", &yes_size.x, &yes_size.y);
	box->size.x = ft_max(yes_size.x * 3, text_size.x + 20);
	box->size.y = ft_max(yes_size.y * 3, 50);
	//box->size.y = box->size.x;
	return (yes_size.y);
}

int		new_confirmation_box(t_confirmation_box *box, t_env *env)
{
	if (!box->str)
		return (custom_error("Confirmation box message is empty"));
	if (!box->font)
		return (custom_error("Confirmation box font is NULL"));
	new_buttons(box, get_box_size(box), env);
	return (1);
}

int		draw_confirmation_box(t_confirmation_box box, t_env *env)
{
	t_point	size;

	draw_rectangle(env,
			new_rectangle(0xFFAAAAAA, 0xFF666666, 1, 2),
			new_point(env->w / 2 - box.size.x / 2, env->h / 2 - box.size.y / 2),
			new_point(box.size.x, box.size.y));
	draw_buttons(box, env);
	print_text(new_point(env->h / 2 - box.size.y / 3,
				env->w / 2 - box.size.x / 2 + 10),
			new_printable_text(box.str, box.font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(box.font, "Yes", &size.x, &size.y);
	print_text(new_point(box.yes.pos.y + 2,
				box.yes.pos.x + box.yes.size.x / 2 - size.x / 2),
			new_printable_text("Yes", box.font, 0xFFFFFFFF, 0), env);
	TTF_SizeText(box.font, "No", &size.x, &size.y);
	print_text(new_point(box.no.pos.y + 2,
				box.no.pos.x + box.no.size.x / 2 - size.x / 2),
			new_printable_text("No", box.font, 0xFFFFFFFF, 0), env);
	return (0);
}
