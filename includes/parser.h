/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 17:09:38 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 14:14:38 by marvin           ###   ########.fr       */
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
int						parse_current_floor_sprite(t_env *env, char **line,
t_map_parser *parser, int i);
int						parse_ceiling_sprites(t_env *env, char **line,
t_map_parser *parser);
int						parse_current_ceiling_sprite(t_env *env, char **line,
t_map_parser *parser, int i);
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

/*
**	Events parsing
*/

int						parse_event_target(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						parse_event_type(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						parse_event_launch_conditions(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int						parse_event_exec_conditions(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int						parse_event_various_data(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
void					init_events_parser(t_events_parser *eparser);
void					init_events_parser_target_parsers(
t_events_parser *eparser);
void					init_events_parser_target_types(
t_events_parser *eparser);
void					init_events_parser_checkers(
t_events_parser *eparser);
void					init_events_parser_updaters(
t_events_parser *eparser);
void					init_events_parser_links_protection(
	t_events_parser *eparser);
void					init_events_parser_var(t_events_parser *eparser);
int						new_parser_global_event(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int						new_parser_press_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						new_parser_shoot_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						new_parser_stand_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						new_parser_walk_in_event(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int						new_parser_walk_out_event(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int						new_parser_death_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						new_parser_enemy_collision_event(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int						new_parser_object_collision_event(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
void					*set_event_target(t_env *env, t_events_parser *parser);
void					*set_event_target4(t_env *env, t_events_parser *parser);
void					*set_condition_target(t_env *env,
t_events_parser *parser);
void					*set_condition_target4(t_env *env,
t_events_parser *parser);
void					*set_event_function(t_env *env,
t_events_parser *parser);
int						set_event_target_type(t_env *env,
t_events_parser *parser);
int						set_event_target_type4(t_env *env,
t_events_parser *parser);
int						count_conditions(char *line, t_map_parser *parser);
int						intersects_with_wall(t_sector *sector, t_v3 pos,
int wall, t_env *env);
int						intersects_with_wall_no_portal_check(t_sector *sector,
t_v3 pos, int wall, t_env *env);
int						intersects_with_sector(t_sector *sector, t_v3 pos,
t_env *env);
int						pos_changed_sector(t_env *env, t_sector *sector,
t_point data, t_v3 pos);
int						parse_events_links(t_env *env, t_map_parser *parser);
int						parse_link_target(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);

/*
**	Unit parsers
*/

int						no_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						sector_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						enemy_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						wall_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						wall_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						floor_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						ceiling_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						vertex_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						weapon_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						object_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						event_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int						dialog_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);

/*
**	Unit writers
*/

void					init_events_writers(void (*writers[])(int, t_event));
void					no_writer(int fd, t_event event);
void					sector_writer(int fd, t_event event);
void					enemy_writer(int fd, t_event event);
void					wall_sprite_writer(int fd, t_event event);
void					wall_writer(int fd, t_event event);
void					floor_sprite_writer(int fd, t_event event);
void					ceiling_sprite_writer(int fd, t_event event);
void					vertex_writer(int fd, t_event event);
void					weapon_writer(int fd, t_event event);
void					object_writer(int fd, t_event event);
void					dialog_writer(int fd, t_event event);
void					event_writer(int fd, t_event event);
void					condition_no_writer(int fd, t_condition condition);
void					condition_sector_writer(int fd, t_condition condition);
void					condition_enemy_writer(int fd,
t_condition condition);
void					condition_wall_sprite_writer(int fd,
t_condition condition);
void					condition_wall_writer(int fd, t_condition condition);
void					condition_floor_sprite_writer(int fd,
t_condition condition);
void					condition_ceiling_sprite_writer(int fd,
t_condition condition);
void					condition_vertex_writer(int fd, t_condition condition);
void					condition_weapon_writer(int fd, t_condition condition);
void					condition_object_writer(int fd, t_condition condition);
void					condition_event_writer(int fd, t_condition condition);
void					write_event_conditions(int fd, t_event event);
void					write_event_link(int fd, t_condition condition);
void					init_event_conditions_writers(void (*writers[])(int,
t_condition));

/*
**	Links
*/

int						set_event_link(t_env *env, t_events_parser *eparser);
int						global_event_exists(t_env *env,
t_events_parser *eparser);
int						press_event_exists(t_env *env,
t_events_parser *eparser);
int						shoot_event_exists(t_env *env,
t_events_parser *eparser);
int						stand_event_exists(t_env *env,
t_events_parser *eparser);
int						walk_out_event_exists(t_env *env,
t_events_parser *eparser);
int						walk_in_event_exists(t_env *env,
t_events_parser *eparser);
int						death_event_exists(t_env *env,
t_events_parser *eparser);
int						enemy_collision_event_exists(t_env *env,
t_events_parser *eparser);
int						object_collision_event_exists(t_env *env,
t_events_parser *eparser);
t_event					*get_global_event(t_env *env, t_events_parser *eparser,
int mode);
t_event					*get_shoot_event(t_env *env, t_events_parser *eparser,
int mode);
t_event					*get_press_event(t_env *env, t_events_parser *eparser,
int mode);
t_event					*get_stand_event(t_env *env, t_events_parser *eparser,
int mode);
t_event					*get_walk_in_event(t_env *env,
t_events_parser *eparser, int mode);
t_event					*get_walk_out_event(t_env *env,
t_events_parser *eparser, int mode);
t_event					*get_death_event(t_env *env, t_events_parser *eparser,
int mode);
t_event					*get_enemy_collision_event(t_env *env,
t_events_parser *eparser, int mode);
t_event					*get_object_collision_event(t_env *env,
t_events_parser *eparser, int mode);

#endif
