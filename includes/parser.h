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

#endif
