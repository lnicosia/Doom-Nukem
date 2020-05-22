/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_skybox.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:43:04 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 13:48:43 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_SKYBOX_H
# define DRAW_SKYBOX_H
# include "render.h"

typedef struct		s_skybox_drawer
{
	t_render_vertex	v1;
	t_skybox_data	wall_data;
	t_render		*skybox;
	t_render		*render;
	int				max;
	int				min;
	int				x;
}					t_skybox_drawer;

void				draw_vline_skybox(t_vline vline, int mode,
t_render *skybox, t_env *env);
void				draw_vline_floor_skybox(t_vline vline, int mode,
t_render *skybox, t_env *env);
void				draw_vline_ceiling_skybox(t_vline vline, int mode,
t_render *skybox, t_env *env);
void				set_skybox_limits(t_skybox_drawer *drawer, t_env *env);
void				compute_skybox_vline(t_skybox_drawer *drawer, t_env *env);

#endif
