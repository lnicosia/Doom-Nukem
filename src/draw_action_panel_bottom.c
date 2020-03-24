#include "env.h"

int		draw_number_of_uses(t_env *env)
{
	t_point			text_size;

	draw_button(env, env->editor.event_panel.action_panel.max_uses,
	env->snprintf);
	TTF_SizeText(env->sdl.fonts.lato20, "Number of uses", &text_size.x,
	&text_size.y);
	print_text(new_point(env->editor.event_panel.action_panel.max_uses.pos.y
	- text_size.y - 5, env->editor.event_panel.action_panel.max_uses.pos.x +
	env->editor.event_panel.action_panel.max_uses.size_up.x / 2 -
	text_size.x / 2), new_printable_text("Number of uses",
	env->sdl.fonts.lato20, 0x333333FF, 0), env);
	return (0);
}

int		draw_action_panel_bottom(t_env *env)
{
	t_point			text_size;

	TTF_SizeText(env->sdl.fonts.lato20, "Delay (ms)", &text_size.x,
	&text_size.y);
	print_text(new_point(env->editor.event_panel.action_panel.delay.pos.y
	- text_size.y - 5, env->editor.event_panel.action_panel.delay.pos.x +
	env->editor.event_panel.action_panel.delay.size_up.x / 2 - text_size.x / 2),
	new_printable_text("Delay (ms)", env->sdl.fonts.lato20, 0x333333FF, 0),
	env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
	env->editor.event_panel.action_panel.delay_value);
	draw_button(env, env->editor.event_panel.action_panel.delay, env->snprintf);
	if (env->editor.event_panel.event.max_uses)
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "%d",
		env->editor.event_panel.event.max_uses);
	else
		ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Inf.");
	return (draw_number_of_uses(env));
}
