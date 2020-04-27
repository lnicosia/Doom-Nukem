#include "env.h"

void	update_enemy(t_env *env, int i)
{
	update_enemy_light(env, i);
	update_enemy_z(env, i);
}

void	update_object(t_env *env, int i)
{
	update_object_light(env, i);
	update_object_z(env, i);
}
