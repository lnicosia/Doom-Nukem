/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:24:27 by lnicosia          #+#    #+#             */
/*   Updated: 2019/05/28 11:53:27 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
	int				sector_vertices_count;
	int				sector_neighbors_count;
}					t_map_parser;

int					parse_vertices(t_env *env, t_map_parser *parser);
int					parse_sectors(t_env *env, t_map_parser *parser);
int					count_vertices(char *line);
int					count_neighbors(char *line);
int					check_vertices_uniqueness(t_sector sector);
int					check_sector_duplicate(t_env *env, t_sector sector, int num);
