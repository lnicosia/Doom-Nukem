/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_mouseup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:44:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/06 15:39:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	editor_mouseup(t_env *env)
{
	if (env->editor.in_game && env->sdl.event.button.button == SDL_BUTTON_LEFT)
		env->editor.select = 1;
	//if (env->sdl.mx > 
	return (0);
}
