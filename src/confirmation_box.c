/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation_box.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:40:15 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/07 10:59:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	confirmation_box_keyup_ig(t_confirmation_box *box, t_env *env)
{
	/*if (((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& env->sdl.my >= box->no.pos.y
					&& env->sdl.my <= box->no.pos.y + box->no.size.y
					&& env->sdl.mx >= box->yes.pos.x
					&& env->sdl.mx <= box->yes.pos.x + box->yes.size.x)
				|| env->sdl.event.key.keysym.sym == SDLK_RETURN))*/
	if (((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& is_mouse_on_button(box->yes,
					new_point(env->sdl.mx, env->sdl.my)))
				|| env->sdl.event.key.keysym.sym == SDLK_RETURN))
		{
			box->state = 0;
			ft_strdel(&box->str);
			SDL_SetRelativeMouseMode(1);
			SDL_GetRelativeMouseState(&env->sdl.mx, &env->sdl.my);
			respawn(env);
		}
	else
		box->yes.state = UP;
	/*if ((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& env->sdl.my >= box->no.pos.y
					&& env->sdl.my <= box->no.pos.y + box->no.size.y
					&& env->sdl.mx >= box->no.pos.x
					&& env->sdl.mx <= box->no.pos.x + box->no.size.x)
			|| env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)*/
	if ((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& is_mouse_on_button(box->no,
					new_point(env->sdl.mx, env->sdl.my)))
			|| env->sdl.event.key.keysym.sym == SDLK_BACKSPACE)
		{
			box->state = 0;
			ft_strdel(&box->str);
			env->running = 0;
		}
	else
		box->no.state = UP;
}

void	confirmation_box_keyup(t_confirmation_box *box, t_env *env)
{
	int	i;

	i = 0;
	if (((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& is_mouse_on_button(box->yes,
					new_point(env->sdl.mx, env->sdl.my)))
				|| env->sdl.event.key.keysym.sym == SDLK_RETURN)
			&& env->editor.selected_sector != -1)
		{
			if (env->player.sector == env->editor.selected_sector)
				env->player.sector = -1;
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
			env->player.sector = get_sector_global(env, env->player.pos);
		}
	else
		box->yes.state = 0;
	if (((env->sdl.event.button.button == SDL_BUTTON_LEFT
					&& is_mouse_on_button(box->no,
					new_point(env->sdl.mx, env->sdl.my)))
			|| env->sdl.event.key.keysym.sym == SDLK_BACKSPACE))
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
			&& is_mouse_on_button(box->yes,
			new_point(env->sdl.mx, env->sdl.my))
			&& env->inputs.left_click) || env->inputs.enter)
		box->yes.state = 1;
	if ((env->sdl.my >= box->no.pos.y
			&& is_mouse_on_button(box->no,
			new_point(env->sdl.mx, env->sdl.my))
			&& env->inputs.left_click) || env->inputs.backspace)
		box->no.state = 1;
}

void	new_buttons(t_confirmation_box *box, int height, t_env *env)
{
	box->no = new_button(new_rectangle(0xFFDD0000, 0xFF990000, 1, 2),
			new_rectangle(0xFF990000, 0xFF990000, 1, 2),
			new_rectangle(0xFF990000, 0xFF990000, 1, 2),
			new_rectangle(0xFF990000, 0xFF990000, 1, 2));
	box->no.size_up.x = box->size.x / 2;
	box->no.size_up.y = height + 5;
	box->no.size_pressed = box->no.size_up;
	box->no.size_down = box->no.size_up;
	box->no.size_hover = box->no.size_up;
	box->no.pos.x = env->w / 2 - box->size.x / 2;
	box->no.pos.y = env->h / 2 + box->size.y / 2 - height - 5;
	box->no.str = ft_strdup("No");
	box->no.font = box->font;
	box->yes = new_button(new_rectangle(0xFF00DD00, 0xFF009900, 1, 2),
			new_rectangle(0xFF009900, 0xFF009900, 1, 2),
			new_rectangle(0xFF009900, 0xFF009900, 1, 2),
			new_rectangle(0xFF009900, 0xFF009900, 1, 2));
	box->yes.size_up.x = box->size.x / 2;
	box->yes.size_up.y = height + 5;
	box->yes.size_pressed = box->yes.size_up;
	box->yes.size_down = box->yes.size_up;
	box->yes.size_hover = box->yes.size_up;
	box->yes.pos.x = env->w / 2;
	box->yes.pos.y = env->h / 2 + box->size.y / 2 - height - 5;
	box->yes.str = "Yes";
	box->yes.font = box->font;
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
	draw_rectangle(env,
			new_rectangle(0xFFAAAAAA, 0xFF666666, 1, 2),
			new_point(env->w / 2 - box.size.x / 2, env->h / 2 - box.size.y / 2),
			new_point(box.size.x, box.size.y));
	draw_button(env, box.yes);
	draw_button(env, box.no);
	print_text(new_point(env->h / 2 - box.size.y / 3,
				env->w / 2 - box.size.x / 2 + 10),
			new_printable_text(box.str, box.font, 0xFFFFFFFF, 0), env);
	return (0);
}
