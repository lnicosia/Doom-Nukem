/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 11:45:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/01/15 17:56:09 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_PARSER_H
# define EVENTS_PARSER_H
# include "map_parser.h"
# define MAX_TRIGGER_TYPES 6
# define MAX_TARGET_TYPES 62

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
	SECTOR_FLOOR_HEIGHT
}					t_events_targets;

typedef struct		s_events_parser
{
	int				trigger_sector;
	int				trigger_wall;
	int				trigger_sprite;
	int				trigger_enemy;
	int				trigger;
	int				target_index;
	int				(*trigger_types[MAX_TRIGGER_TYPES + 1])(t_env *,
	t_map_parser *, char **, struct s_events_parser *);
	int				target_types[MAX_TARGET_TYPES + 1];
}					t_events_parser;

/*
**	Functions
*/

int					parse_target(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
void				init_events_parser(t_events_parser *eparser);
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

/*
**	Unit parsers
*/

int					sector_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					enemy_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);
int					wall_sprite_parser(t_env *env, t_map_parser *parser,
char **line, t_events_parser *eparser);

#endif
