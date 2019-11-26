/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:02:23 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/26 11:43:30 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADD_VERTEX_H
# define ADD_VERTEX_H

# include "env.h"



int					add_vertex_in_sector(t_env *env);
int					modify_vertices(t_env *env);
int					modify_sector(t_env *env, int sector);
int					modify_textures(t_env *env, int index, int sector);
int					modify_neighbors(t_env *env, int index, int sector);
int					modify_vertices_in_sector(t_env *env, int index, int sector);
int					select_vertices(t_env *env);
int					*get_sectors_list(t_env *env, int v1, int v2);

#endif