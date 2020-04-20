#include "env.h"

void	init_selection_tabs2(int tmp, t_env *env)
{
	int		mod;

	env->editor.wall_sprite_selection_size = env->editor.object_selection_size;
	tmp = MAX_WALL_TEXTURE + MAX_SKYBOX;
	if (tmp > 25)
		mod = 10;
	else
		mod = 5;
	while (tmp % mod != 0)
		tmp++;
	env->editor.texture_selection_size = new_point((66 * mod) + 11,
	(66 * (tmp / mod)) + 30);
	env->editor.enemy_selection_pos = new_point(280, 380);
	env->editor.texture_selection_pos = new_point(300, 150);
	env->editor.object_selection_pos = new_point(280, 280);
	env->editor.wall_sprite_selection_pos = new_point(180, 490);
}

void	init_selection_tabs(t_env *env)
{
	int		mod;
	int		tmp;

	tmp = MAX_ENEMIES;
	if (tmp > 25)
		mod = 10;
	else
		mod = 5;
	while (tmp % mod != 0)
		tmp++;
	env->editor.enemy_selection_size = new_point((66 * mod) + 13,
	(66 * (tmp / mod)) + 13);
	tmp = MAX_OBJECTS;
	if (tmp > 25)
		mod = 10;
	else
		mod = 5;
	while (tmp % mod != 0)
		tmp++;
	env->editor.object_selection_size = new_point((66 * mod) + 13,
	(66 * (tmp / mod)) + 13);
	init_selection_tabs2(tmp, env);
}
