#include "events_parser.h"

void	init_print_condition_target_data6(t_env *env)
{
	env->print_condition_target_data[ENEMY_X] =
	&print_enemy_condition_target;
	env->print_condition_target_data[ENEMY_Y] =
	&print_enemy_condition_target;
	env->print_condition_target_data[ENEMY_Z] =
	&print_enemy_condition_target;
	env->print_condition_target_data[OBJECT_SPRITE] =
	&print_object_condition_target;
	env->print_condition_target_data[OBJECT_SCALE] =
	&print_object_condition_target;
	env->print_condition_target_data[OBJECT_DAMAGE] =
	&print_object_condition_target;
	env->print_condition_target_data[OBJECT_HP] =
	&print_object_condition_target;
	env->print_condition_target_data[OBJECT_X] =
	&print_object_condition_target;
	env->print_condition_target_data[OBJECT_Y] =
	&print_object_condition_target;
	env->print_condition_target_data[OBJECT_Z] =
	&print_object_condition_target;
}
