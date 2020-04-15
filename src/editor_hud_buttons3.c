#include "env.h"

int		editor_mode_button(t_env *env)
{
	env->editor.change_mode = new_image_button(ON_RELEASE, &change_mode, env,
	env);
	env->editor.change_mode.str = "2D/3D";
	env->editor.change_mode.pos = new_point(40, 60);
	return (0);
}

int		editor_save_button(t_env *env)
{
	env->editor.save = new_image_button(ON_RELEASE, &save_button, env, env);
	env->editor.save.str = "SAVE";
    env->editor.save.pos = new_point(40, 110);
	return (0);
}

int		editor_launch_game(t_env *env)
{
	env->editor.launch_game =
	new_image_button(ON_RELEASE, &launch_game, env, env);
	env->editor.launch_game.str = "START";
    env->editor.launch_game.pos = new_point(40, 160);
	return (0);
}
