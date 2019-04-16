/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 15:16:14 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/16 15:17:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_options(t_env *env)
{
	env->options.contouring = 1;
	env->options.render_sectors = 1;
	env->options.lighting = 0;
	env->options.show_minimap = 1;
}
