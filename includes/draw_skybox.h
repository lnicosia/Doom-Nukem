/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:43:04 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/10 12:01:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SKYBOX_H
# define DRAW_SKYBOX_H
#include "env.h"

void	draw_vline_skybox(t_vline vline, t_render skybox, t_env *env);
void	draw_vline_floor_skybox(t_vline vline, t_render skybox, t_env *env);
void	draw_vline_ceiling_skybox(t_vline vline, t_render skybox, t_env *env);

#endif
