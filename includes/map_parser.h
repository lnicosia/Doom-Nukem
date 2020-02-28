/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:24:27 by lnicosia          #+#    #+#             */
/*   Updated: 2020/02/28 12:17:23 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H
# define WRONG_CHAR 1
# define MISSING_CHAR 2

typedef struct		s_map_parser
{
	char			*line;
	int				nb_vertices;
	int				nb_sectors;
	int				ret;
	int				fd;
	int				line_count;
	int				sectors_count;
	int				vertices_count;
	int				objects_count;
	int				enemies_count;
	int				sector_vertices_count;
	int				sector_neighbors_count;
	int				sector_portals_count;
	int				sector_textures_count;
	int				sector_sprites_count;
	int				sector_floor_sprites_count;
	int				sector_ceiling_sprites_count;
}					t_map_parser;
#endif