/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid_walls.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 13:47:36 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 13:47:37 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_GRID_WALLS_H
# define DRAW_GRID_WALLS_H

typedef struct	s_grid_wall_drawer
{
	t_point		v[3];
	t_point		center;
	t_point		text_size;
	t_sector	*sector;
	Uint32		color;
	int			i;
	int			nb_angles;
	int			font_size;

}				t_grid_wall_drawer;

void			get_current_wall_angle(int i, t_grid_wall_drawer *drawer,
t_env *env);
void			get_last_wall_angle(int i, t_grid_wall_drawer *drawer,
t_env *env);
int				print_minimap_sector_num(t_grid_wall_drawer *drawer,
t_env *env);

#endif
