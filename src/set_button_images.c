/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_button_images.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 20:25:42 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/06 20:33:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	set_button_up_image(t_button *button, t_env *env, SDL_Surface *surface)
{
	if (!surface)
		return ;
	button->img_up = surface;
	button->size_up = new_point(button->img_up->w, button->img_up->h);
	(void)button;
	(void)env;
	(void)surface;
}

void	set_button_up_rectangle(t_button *button, t_env *env,
t_rectangle rectangle)
{
	button->up = rectangle;
	(void)button;
	(void)env;
	(void)rectangle;
}
