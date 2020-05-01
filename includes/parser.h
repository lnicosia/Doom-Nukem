/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:09:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 17:51:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "env.h"

/*
**	Parser functions
*/

int						parse_bmp(char *file, int index, t_env *env);
int						parse_bmp_wall_textures(char *file, int index,
t_env *env);
int						parse_bmp_ui_textures(char *file, int index,
t_env *env);
int						parse_bmp_mini_enemies_textures(char *file, int index,
t_env *env);
int						parse_bmp_skybox_textures(char *file, int index,
int num_sky, t_env *env);
int						parse_bmp_mini_enemies_textures(char *file, int index,
t_env *env);
int						parse_bmp_mini_objects_textures(char *file, int index,
t_env *env);
int						parse_bmp_mini_skyboxes_textures(char *file, int index,
t_env *env);
int						parse_bmp_skybox_textures(char *file, int index,
int num_sky, t_env *env);
int						parse_map(char *file, t_env *env);
char					*skip_number(char *line);
char					*skip_hexa(char *line);
char					*skip_spaces(char *line);
int						parse_floor(t_env *env, char **line,
t_map_parser *parser);
int						parse_floor6(t_env *env, char **line,
t_map_parser *parser);
int						parse_ceiling(t_env *env, char **line,
t_map_parser *parser);
int						parse_ceiling6(t_env *env, char **line,
t_map_parser *parser);
int						parse_sector_vertices(t_env *env, char **line,
t_map_parser *parser);
int						parse_sector_neighbors(t_env *env, char **line,
t_map_parser *parser);
int						parse_sector_portals(t_env *env, char **line,
t_map_parser *parser);
int						parse_sector_textures(t_env *env, char **line,
t_map_parser *parser);
int						parse_sector_wall_sprites(t_env *env, char **line,
t_map_parser *parser);
int						parse_current_sprite(t_env *env, char **line,
t_map_parser *parser, t_point index);
int						parse_sector_general(t_env *env, char **line,
t_map_parser *parser);
int						parse_vertices(t_env *env, t_map_parser *parser);
int						parse_sectors(t_env *env, t_map_parser *parser);
int						parse_floor_sprites(t_env *env, char **line,
t_map_parser *parser);
int						parse_ceiling_sprites(t_env *env, char **line,
t_map_parser *parser);
int						parse_objects(t_env *env, t_map_parser *parser);
int						parse_object_pos(t_env *env, char **line,
t_map_parser *parser);
int						parse_object_sprite(t_env *env, char **line,
t_map_parser *parser);
int						parse_enemies(t_env *env, t_map_parser *parser);
int						parse_enemy_pos(t_env *env, char **line,
t_map_parser *parser);
int						parse_enemy_sprite(t_env *env, char **line,
t_map_parser *parser);
int						parse_enemy_data(t_env *env, char **line,
t_map_parser *parser);
int						parse_events(t_env *env, t_map_parser *parser);
int						parse_player(t_env *env, t_map_parser *parser);
int						parse_resources(t_env *env, t_map_parser *parser);
int						check_vertices_uniqueness(t_sector sector);
int						check_sector_duplicate(t_env *env, t_sector sector,
		int num);
int						valid_number(char *line, t_map_parser *parser);
int						valid_int(char *line, t_map_parser *parser);
int						valid_double(char *line, t_map_parser *parser);
int						valid_hexa(char *line, t_map_parser *parser);
int						count_vertices(char *line, t_map_parser *parser);
int						count_neighbors(char *line, t_map_parser *parser);
int						count_portals(char *line, t_map_parser *parser);
int						count_textures(char *line, t_map_parser *parser);
int						count_sprites(char *line, t_map_parser *parser);
int						count_wall_sprites(char *line, t_map_parser *parser);
int						count_floor_sprites(char *line, t_map_parser *parser);
int						parse_sound(t_env *env, t_map_parser *parser);
int						parse_bmp_file(t_env *env, t_map_parser *parser);
int						parse_font_file(t_env *env, t_map_parser *parser);

#endif
