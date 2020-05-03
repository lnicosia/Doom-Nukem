#include "env.h"

int     fps_option_func(void *target)
{
    t_env *env;

    env = (t_env*)target;
    env->options.show_fps = (env->options.show_fps ? 0 : 1);
    return (1);
}

int		fps_option_button(t_env *env)
{
	env->fps_option = new_image_button(ON_RELEASE, &fps_option_func,
		env, env);
	env->fps_option.pos =
		new_point(env->h_w - env->start_game_button.size_down.x / 2,
		(env->h_h - env->start_game_button.size_down.y / 2) - env->h_h / 4);
	return (0);
}