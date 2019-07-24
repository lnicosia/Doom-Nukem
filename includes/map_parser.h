/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:24:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/24 15:16:37 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MAP_PARSER_H
# define MAP_PARSER_H
# include "env.h"

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
	int				sector_vertices_count;
	int				sector_neighbors_count;
	int				sector_textures_count;
}					t_map_parser;

int					parse_vertices(t_env *env, t_map_parser *parser);
int					parse_sectors(t_env *env, t_map_parser *parser);
int					init_objects(t_env *env, t_map_parser *parser);
int					parse_objects(t_env *env, t_map_parser *parser);
int					count_numbers(char *line, t_map_parser *parser);
int					check_vertices_uniqueness(t_sector sector);
int					check_sector_duplicate(t_env *env, t_sector sector, int num);
int					valid_number(char *line, t_map_parser *parser);

#endif
