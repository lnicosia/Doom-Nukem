/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:24:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/08/30 14:48:49 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H
# include "env.h"
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
	int				sector_textures_count;
}					t_map_parser;

int					parse_vertices(t_env *env, t_map_parser *parser);
int					parse_sectors(t_env *env, t_map_parser *parser);
int					init_objects(t_env *env, t_map_parser *parser);
int					parse_objects(t_env *env, t_map_parser *parser);
int					init_enemies(t_env *env, t_map_parser *parser);
int					parse_enemies(t_env *env, t_map_parser *parser);
int					parse_player(t_env *env, t_map_parser *parser);
int					check_vertices_uniqueness(t_sector sector);
int					check_sector_duplicate(t_env *env, t_sector sector,
		int num);
int					valid_number(char *line, t_map_parser *parser);
int					count_vertices(char *line, t_map_parser *parser);
int					count_neighbors(char *line, t_map_parser *parser);
int					count_textures(char *line, t_map_parser *parser);

/*
**	Protection
*/

int					invalid_char(const char *location, const char *expected,
		char c, t_map_parser *parser);
int					missing_data(const char *missing_data, t_map_parser *parser);
int					extra_data(const char *missing_data, t_map_parser *parser);
int					custom_error_with_line(const char *message, t_map_parser *parser);
int					sector_error(const char *message, int sector, t_map_parser *parser);

#endif
