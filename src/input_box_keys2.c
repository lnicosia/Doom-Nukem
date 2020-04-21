#include "input_box_utils.h"

int		input_box_keys7(t_input_box *box, t_env *env)
{
	if (env->inputs.left_click)
	{
		box->click = 1;
		if (env->sdl.event.type == SDL_MOUSEBUTTONDOWN
			&& (env->sdl.mx < box->pos.x || env->sdl.mx > box->pos.x
			+ box->size.x || env->sdl.my < box->pos.y
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
	return (0);
}

int		input_box_keys6(t_input_box *box, t_env *env)
{
	if (env->sdl.event.type == SDL_KEYUP && !env->inputs.lgui)
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
	return (input_box_keys7(box, env));
}
