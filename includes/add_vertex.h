/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:02:23 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/29 15:15:39 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_VERTEX_H
# define ADD_VERTEX_H

# include "env.h"

int					add_vertex_in_sector(t_env *env);
int					modify_vertices(t_env *env);
int					modify_sector(t_env *env, int sector);
int					modify_t_wall_sprites_tab_in_sector(t_env *env, int index,
int sector, t_wall_sprites **tab);
int					modify_t_list_tab_in_sector(t_env *env, int index,
int sector, t_list ***tab);
int					modify_textures(t_env *env, int index, int sector);
int					modify_double_tab_in_sector(t_env *env, int index,
int sector, double **tab);
int					modify_int_tab_in_sector(t_env *env, int index,
int sector, int **tab);
int					modify_t_v2_tab_in_sector(t_env *env, int index,
int sector, t_v2 **tab);
int					modify_walls_map_lvl(t_env *env, int sector);
int					modify_textures(t_env *env, int index, int sector);
int					modify_neighbors(t_env *env, int index, int sector);
int					modify_vertices_in_sector(t_env *env, int index,
int sector);
int					is_mouse_on_a_wall(t_env *env);
int					*get_sectors_list(t_env *env, int v1, int v2);

#endif
