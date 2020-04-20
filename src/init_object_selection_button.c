#include "env.h"

int		init_object_selection_button2(t_env *env)
{
	env->editor.current_object_selection = new_image_button(ON_RELEASE,
	&open_object_selection, env, env);
	env->editor.current_object_selection.size_up = new_point(64, 64);
	env->editor.current_object_selection.size_down = new_point(64, 64);
    env->editor.current_object_selection.size_hover = new_point(64, 64);
    env->editor.current_object_selection.size_pressed = new_point(64, 64);	
    env->editor.current_object_selection.pos = new_point(233, 217);
	return (1);
}

int		init_object_selection_button(t_env *env)
{
	int	i;
	int	mod;

	if (MAX_ENEMIES > 20)
		mod = 10;
	else
		mod = 5;
	i = 0;
 	while (i < MAX_OBJECTS)
	{
		env->editor.object_tab[i] = new_image_button(ON_RELEASE,
		&save_object, new_button_target(env, i), env);
		env->editor.object_tab[i].size_up = new_point(64, 64);
		env->editor.object_tab[i].size_down = new_point(64, 64);
        env->editor.object_tab[i].size_hover = new_point(64, 64);
        env->editor.object_tab[i].size_pressed = new_point(64, 64);
		env->editor.object_tab[i].pos =
		new_point(280 + (66 * (i % mod)) + 8, 280 + 8 + (66 * (i / mod)));
		i++;
	}
	return (init_object_selection_button2(env));
}
