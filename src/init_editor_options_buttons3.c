#include "env.h"

int		light_option(void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (env->options.lighting)
		env->options.lighting = 0;
	else
		env->options.lighting = 1;
	return (0);
}

int		fps_option(void *param)
{
	t_env *env;

	env = (t_env*)param;
	if (env->options.show_fps)
		env->options.show_fps = 0;
	else
		env->options.show_fps = 1;
	return (0);
}

void	init_quit_options_button(t_env *env)
{
	env->editor.quit_options = new_previous_button_2(ON_RELEASE, &quit_options,
	env, env);
	env->editor.quit_options.str = NULL;
	env->editor.quit_options.pos = new_point(25, 5);
}
