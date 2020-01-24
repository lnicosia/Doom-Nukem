/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:45:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/24 16:02:35 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_PARSER_H
# define EVENTS_PARSER_H
# include "map_parser.h"
# define MAX_TRIGGER_TYPES 6
# define MAX_TARGET_TYPES 66

typedef enum		e_trigger
{
	GLOBAL,
	PRESS,
	SHOOT,
	STAND,
	WALK_IN,
	WALK_OUT,
	DEATH
}					t_trigger;

typedef enum		e_events_targets
{
	SECTOR_FLOOR_HEIGHT,
	SECTOR_FLOOR_SLOPE,
	SECTOR_FLOOR_TEXTURE,
	SECTOR_FLOOR_ALIGN_X,
	SECTOR_FLOOR_ALIGN_Y,
	SECTOR_FLOOR_SCALE_X,
	SECTOR_FLOOR_SCALE_Y,
	SECTOR_CEILING_HEIGHT,
	SECTOR_CEILING_SLOPE,
	SECTOR_CEILING_TEXTURE,
	SECTOR_CEILING_ALIGN_X,
	SECTOR_CEILING_ALIGN_Y,
	SECTOR_CEILING_SCALE_X,
	SECTOR_CEILING_SCALE_Y,
	SECTOR_WALL_TEXTURE,
	SECTOR_WALL_ALIGN_X,
	SECTOR_WALL_ALIGN_Y,
	SECTOR_WALL_SCALE_X,	
	SECTOR_WALL_SCALE_Y,
	SECTOR_WALL_PORTAL,
	SECTOR_WALL_SPRITES_SPRITE,
	SECTOR_WALL_SPRITES_POS_X,
	SECTOR_WALL_SPRITES_POS_Y,
	SECTOR_WALL_SPRITES_SCALE_X,
	SECTOR_WALL_SPRITES_SCALE_Y,
	SECTOR_FLOOR_SPRITES_SPRITE,
	SECTOR_FLOOR_SPRITES_POS_X,
	SECTOR_FLOOR_SPRITES_POS_Y,
	SECTOR_FLOOR_SPRITES_SCALE_X,
	SECTOR_FLOOR_SPRITES_SCALE_Y,
	SECTOR_CEILING_SPRITES_SPRITE,
	SECTOR_CEILING_SPRITES_POS_X,
	SECTOR_CEILING_SPRITES_POS_Y,
	SECTOR_CEILING_SPRITES_SCALE_X,
	SECTOR_CEILING_SPRITES_SCALE_Y,
	SECTOR_BRIGHTNESS,
	SECTOR_LIGHT_COLOR,
	SECTOR_INTENSITY,
	SECTOR_GRAVITY,
	VERTEX_X,
	VERTEX_Y,
	PLAYER_X,
	PLAYER_Y,
	PLAYER_Z,
	PLAYER_HP,
	PLAYER_ARMOR,
	PLAYER_SPEED,
	PLAYER_INVINCIBLE,
	PLAYER_INFINITE_AMMO,
	PLAYER_SECTOR,
	WEAPON_DAMAGE,
	WEAPON_RANGE,
	ENEMY_SPRITE,
	ENEMY_SCALE,
	ENEMY_DAMAGE,
	ENEMY_HP,
	ENEMY_SPEED,
	ENEMY_X,
	ENEMY_Y,
	ENEMY_Z,
	OBJECT_SPRITE,
	OBJECT_SCALE,
	OBJECT_DAMAGE,
	OBJECT_HP,
	OBJECT_X,
	OBJECT_Y,
	OBJECT_Z,
	END_OF_EVENT
}					t_events_targets;

typedef struct		s_events_parser
{
	t_event			event;
	int				link_type;
	int				trigger_sector;
	int				trigger_wall;
	int				trigger_sprite;
	int				trigger_enemy;
	int				trigger_index;
	int				target_vertex;
	int				target_sector;
	int				target_wall;
	int				target_sprite;
	int				target_enemy;
	int				target_weapon;
	int				target_object;
	int				target_index;
	int				target_type;
	int				source_type;
	int				source_sector;
	int				source_wall;
	int				source_sprite;
	int				source_enemy;
	int				source_index;
	int				current_index;
	int				current_vertex;
	int				current_sector;
	int				current_wall;
	int				current_sprite;
	int				current_enemy;
	int				current_weapon;
	int				current_object;
	int				condition_vertex;
	int				condition_sector;
	int				condition_wall;
	int				condition_sprite;
	int				condition_enemy;
	int				condition_weapon;
	int				condition_object;
	int				condition_index;
	int				nb_conditions;
	int				condition_count;
	int				(*trigger_parsers[MAX_TRIGGER_TYPES + 1])(t_env *,
	t_map_parser *, char **, struct s_events_parser *);
	int				(*new_events[MAX_TRIGGER_TYPES + 1])(t_env *,
	t_map_parser *, char **, struct s_events_parser *);
	int				(*event_exists[MAX_TRIGGER_TYPES + 1])(t_env *,
	struct s_events_parser *);
	t_event			*(*get_event_array[MAX_TRIGGER_TYPES + 1])(t_env *,
	struct s_events_parser *, int);
	size_t			*(*get_event_nb[MAX_TRIGGER_TYPES + 1])(t_env *,
	struct s_events_parser *, int);
	int				(*target_parsers[MAX_TARGET_TYPES + 1])(t_env *,
	t_map_parser *, char **, struct s_events_parser *);
	int				(*updaters[MAX_TARGET_TYPES + 1])(t_event *, void *);
	int				(*checkers[MAX_TARGET_TYPES + 1])(t_event *, void *);
	int				target_types[MAX_TARGET_TYPES + 1];
}					t_events_parser;

/*
**	Functions
*/

int					parse_event_target(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					parse_event_type(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					parse_event_launch_conditions(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int					parse_event_exec_conditions(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
int					parse_event_various_data(t_env *env,
t_map_parser *parser, char **line, t_events_parser *eparser);
void				init_events_parser(t_events_parser *eparser);
void				init_events_parser_target_parsers(t_events_parser *eparser);
void				init_events_parser_target_types(t_events_parser *eparser);
void				init_events_parser_checkers(t_events_parser *eparser);
void				init_events_parser_updaters(t_events_parser *eparser);
void				init_events_parser_links_protection(t_events_parser *eparser);
int					new_global_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					new_press_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					new_shoot_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					new_stand_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					new_walk_in_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					new_walk_out_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					new_death_event(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
void				*set_event_target(t_env *env, t_events_parser *parser);
void				*set_event_target4(t_env *env, t_events_parser *parser);
void				*set_condition_target(t_env *env, t_events_parser *parser);
void				*set_condition_target4(t_env *env, t_events_parser *parser);
int					set_event_target_type(t_env *env, t_events_parser *parser);
int					set_event_target_type4(t_env *env, t_events_parser *parser);
int					count_conditions(char *line, t_map_parser *parser);
int					intersects_with_wall(t_sector *sector, t_v3 pos, int wall,
t_env *env);
int					intersects_with_wall_no_portal_check(t_sector *sector,
t_v3 pos, int wall, t_env *env);
int					intersects_with_sector(t_sector *sector, t_v3 pos, 
t_env *env);
int					pos_changed_sector(t_env *env, t_sector *sector,
t_point data, t_v3 pos);
int					parse_events_links(t_env *env, t_map_parser *parser);

/*
**	Unit parsers
*/

int					no_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					sector_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					enemy_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					wall_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					wall_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					floor_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					ceiling_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					vertex_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					weapon_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					object_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					event_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);

/*
**	Unit writers
*/

void				init_events_writers(void (*writers[])(int, t_event));
void				no_writer(int fd, t_event event);
void				sector_writer(int fd, t_event event);
void				enemy_writer(int fd, t_event event);
void				wall_sprite_writer(int fd, t_event event);
void				wall_writer(int fd, t_event event);
void				floor_sprite_writer(int fd, t_event event);
void				ceiling_sprite_writer(int fd, t_event event);
void				vertex_writer(int fd, t_event event);
void				weapon_writer(int fd, t_event event);
void				object_writer(int fd, t_event event);
void				event_writer(int fd, t_event event);
void				condition_no_writer(int fd, t_condition condition);
void				condition_sector_writer(int fd, t_condition condition);
void				condition_enemy_writer(int fd, t_condition condition);
void				condition_wall_sprite_writer(int fd, t_condition condition);
void				condition_wall_writer(int fd, t_condition condition);
void				condition_floor_sprite_writer(int fd, t_condition condition);
void				condition_ceiling_sprite_writer(int fd,
t_condition condition);
void				condition_vertex_writer(int fd, t_condition condition);
void				condition_weapon_writer(int fd, t_condition condition);
void				condition_object_writer(int fd, t_condition condition);
void				condition_event_writer(int fd, t_condition condition);
void				write_event_conditions(int fd, t_event event);
void				init_event_conditions_writers(void (*writers[])(int,
t_condition));

/*
**	Links
*/

int					set_event_link(t_env *env, t_events_parser *eparser);
int					global_event_exists(t_env *env, t_events_parser *eparser);
int					press_event_exists(t_env *env, t_events_parser *eparser);
int					shoot_event_exists(t_env *env, t_events_parser *eparser);
int					stand_event_exists(t_env *env, t_events_parser *eparser);
int					walk_out_event_exists(t_env *env, t_events_parser *eparser);
int					walk_in_event_exists(t_env *env, t_events_parser *eparser);
int					death_event_exists(t_env *env, t_events_parser *eparser);
t_event				*get_global_event(t_env *env, t_events_parser *eparser,
int mode);
t_event				*get_shoot_event(t_env *env, t_events_parser *eparser,
int mode);
t_event				*get_press_event(t_env *env, t_events_parser *eparser,
int mode);
t_event				*get_stand_event(t_env *env, t_events_parser *eparser,
int mode);
t_event				*get_walk_in_event(t_env *env, t_events_parser *eparser,
int mode);
t_event				*get_walk_out_event(t_env *env, t_events_parser *eparser,
int mode);
t_event				*get_death_event(t_env *env, t_events_parser *eparser,
int mode);
#endif
