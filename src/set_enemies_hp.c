#include "env.h"

void	set_enemies_hp(t_env *env)
{
	int i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].exists)
			env->enemies[i].health = env->enemies[i].map_hp *
				env->difficulty;
		i++;
	}
}
