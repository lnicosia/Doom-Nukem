/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:45:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/22 14:14:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_PARSER_H
# define EVENTS_PARSER_H
# include "utils.h"
# include "map_parser.h"

typedef enum		e_trigger
{
	GLOBAL,
	PRESS,
	SHOOT,
	STAND,
	WALK_IN,
	WALK_OUT,
	DEATH,
	ENEMY_COLLISION,
	OBJECT_COLLISION
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
	WIN,
	DIALOG
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
	int				trigger_object;
	int				target_vertex;
	int				target_sector;
	int				target_wall;
	int				target_sprite;
	int				target_enemy;
	int				target_weapon;
	int				target_object;
	char			*target_str;
	int				target_index;
	int				target_type;
	int				source_type;
	int				source_sector;
	int				source_wall;
	int				source_sprite;
	int				source_enemy;
	int				source_index;
	int				source_object;
	char			*source_str;
	int				current_index;
	int				current_vertex;
	int				current_sector;
	int				current_wall;
	int				current_sprite;
	int				current_enemy;
	int				current_weapon;
	int				current_object;
	char			*current_str;
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

#endif
