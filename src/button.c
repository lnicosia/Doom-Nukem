/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   button.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 15:43:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/02 15:57:01 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_button	new_button(t_rectangle up, t_rectangle pressed, t_rectangle down)
{
	t_button	new;

	new.up = up;
	new.pressed = pressed;
	new.down = down;
	new.state = 0;
	return (new);
}

/*void	draw_button(t_env *env, t_button b, t_point pos, t_point size)
{
}*/
