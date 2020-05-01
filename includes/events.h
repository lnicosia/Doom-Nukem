#ifndef EVENTS_H
# define EVENTS_H
# include "env.h"

/*
**	Event functions
*/

int						update_event(t_event *event);
int						pop_events(t_env *env);
int						double_event(t_event *curr);
int						int_event(t_event *curr);
int						uint32_event(t_event *curr);
t_event					new_fixed_event(int type, void *target, double goal,
double speed);
t_event					new_func_event(int (*func)(void *, void *),
void *param);
t_event					new_incr_event(int type, void *target, double incr,
double speed);
int						start_event(t_event **events, size_t *size,
t_env *env);
int						start_event_free(t_event **events, size_t *size,
t_env *env);
int						check_launch_conditions(t_event *event,
t_condition *tab, size_t nb, t_env *env);
int						check_exec_conditions(t_event *event, t_condition *tab,
size_t nb, t_env *env);
t_event_param			new_event_param(int num, double equ_value,
double diff_value);
t_event_param			empty_event_param(void);

int						update_sector_event(t_event *event, void *penv);
int						update_player_pos_event(t_event *event, void *penv);
int						update_player_z_event(t_event *event, void *penv);
int						update_wall_texture_event(t_event *event, void *penv);
int						update_floor_texture_event(t_event *event, void *penv);
int						update_ceiling_texture_event(t_event *event,
void *penv);
int						update_sector_entities_light_event(t_event *event,
void *penv);
int						update_object_sector_event(t_event *event, void *penv);
int						update_enemy_sector_event(t_event *event, void *penv);
int						update_object_sprite_event(t_event *event, void *penv);
int						update_enemy_sprite_event(t_event *event, void *penv);
int						update_wall_sprite_event(t_event *event, void *penv);
int						update_floor_sprite_event(t_event *event, void *penv);
int						update_ceiling_sprite_event(t_event *event,
void *penv);
int						update_vertex_event(t_event *event, void *penv);
int						delete_itself_event(t_event *event, void *penv);

#endif
