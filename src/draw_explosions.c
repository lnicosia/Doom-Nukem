#include "render.h"

int		draw_explosions(t_camera *camera, t_env *env)
{
	t_list			*tmp;
	t_explosion		*explosion;
	int				sprite_index;

	get_explosion_relative_pos(camera, env);
	tmp = env->explosions;
	while (tmp)
	{
		explosion = (t_explosion*)tmp->content;
		if (explosion->rotated_pos.z > 1)
		{
			sprite_index = explosion_animation(env, explosion,
			env->object_sprites[explosion->sprite].nb_death_sprites);
			if (sprite_index >= 0)
			{
				if (draw_explosion(camera, explosion, env, sprite_index))
					return (-1);
				tmp = tmp->next;
			}
			else
				tmp = ft_lstdelnode(&env->explosions, tmp);
		}
		else
			tmp = tmp->next;
	}
	return (0);
}
