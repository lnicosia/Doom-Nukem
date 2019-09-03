/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_confirmation_box.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 11:16:07 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/03 11:18:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		init_confirmation_box(t_env *env)
{
	if (env.confirmation_box.font == NULL)
		env.confirmation_box.font = env.sdl.fonts.montserrat20;
	env.confirmation_box.yes_pressed = 0;
	env.confirmation_box.no_pressed = 0;
	env.confirmation_box.str = NULL;
}
