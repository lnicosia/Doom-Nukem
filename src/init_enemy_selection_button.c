#include "env.h"

int		init_enemy_selection_button2(t_env *env)
{
	env->editor.current_enemy_selection = new_image_button(ON_RELEASE,
	&open_enemy_selection, env, env);
	env->editor.current_enemy_selection.size_up = new_point(64, 64);
	env->editor.current_enemy_selection.size_down = new_point(64, 64);
    env->editor.current_enemy_selection.size_hover = new_point(64, 64);
    env->editor.current_enemy_selection.size_pressed = new_point(64, 64);	
    env->editor.current_enemy_selection.pos = new_point(233, 317);
	return (1);
}

int		init_enemy_selection_button(t_env *env)
{
	int	i;
	int	mod;

	if (MAX_ENEMIES > 20)
		mod = 10;
	else
		mod = 5;
	i = 0;
 	while (i < MAX_ENEMIES)
	{
		env->editor.enemy_tab[i].img_up = env->wall_textures[i].maps[6];
		env->editor.enemy_tab[i] = new_image_button(ON_RELEASE,
		&save_enemy, new_button_target(env, i), env);
		env->editor.enemy_tab[i].size_up = new_point(64, 64);
		env->editor.enemy_tab[i].size_down = new_point(64, 64);
        env->editor.enemy_tab[i].size_hover = new_point(64, 64);
        env->editor.enemy_tab[i].size_pressed = new_point(64, 64);
		env->editor.enemy_tab[i].pos =
		new_point(280 + (64 * (i % mod)) + 5, 380 + 5 + (64 * (i / mod)));
		i++;
	}
	return (init_enemy_selection_button2(env));
}
