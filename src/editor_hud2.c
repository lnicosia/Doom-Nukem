#include "env.h"

void	print_on_off(t_env *env, int bool, t_point p)
{
	if (bool)
		print_text(p, new_printable_text("ON", env->sdl.fonts.lato20,
			0x009246FF, 20), env);
	else
		print_text(p, new_printable_text("OFF", env->sdl.fonts.lato20,
			0xCC0000FF, 20), env);
}

void	editor_options_rectangles(t_env *env)
{
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 40), new_point(360, 230));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 310), new_point(360, 112));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 435), new_point(360, 112));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 560), new_point(360, 92));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 665), new_point(360, 52));
	draw_rectangle(env,
		new_rectangle(0xe3e4e8, 0xbdc3c7, 1, 0),
		new_point(20, 730), new_point(360, 150));
}

void	editor_options_buttons(t_env *env)
{
	draw_button(env, env->editor.quit_options,
		env->editor.quit_options.str);
	print_text(new_point(5, 155), new_printable_text("OPTIONS",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env);
	print_text(new_point(275, 167), new_printable_text("HELP",
		env->sdl.fonts.lato_bold25, 0x000000FF, 25), env);
	draw_button(env, env->editor.mipmapping,
		env->editor.mipmapping.str);
	draw_button(env, env->editor.zbuffer, env->editor.zbuffer.str);
	draw_button(env, env->editor.light, env->editor.light.str);
	draw_button(env, env->editor.fps, env->editor.fps.str);
	print_on_off(env, env->options.mipmapping, new_point(64, 265));
	print_on_off(env, env->options.zbuffer, new_point(114, 265));
	print_on_off(env, env->options.lighting, new_point(164, 265));
	print_on_off(env, env->options.show_fps, new_point(214, 265));
}

void	editor_options_ceil_floor(t_env *env)
{
	print_text(new_point(315, 50), new_printable_text("Ceiling/Floor",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	print_text(new_point(340, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Height%*s", 53, "+/-");
	print_text(new_point(360, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Slope %*s", 56, "ctrl +/-");
	print_text(new_point(380, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Start slope%*s", 45,
		"ctrl shift <-/->");
	print_text(new_point(400, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}

void	editor_options_textures(t_env *env)
{
	print_text(new_point(440, 50), new_printable_text("Textures",
		env->sdl.fonts.lato_bold15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Select%*s", 55, "left-click");
	print_text(new_point(465, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Add texture%*s", 41, "T");
	print_text(new_point(485, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Scale %*s", 57,
		"ctrl shift +/-");
	print_text(new_point(505, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
	ft_snprintf(env->snprintf, SNPRINTF_SIZE, "Align %*s", 57,
		"ctrl shift </>");
	print_text(new_point(525, 70), new_printable_text(env->snprintf,
		env->sdl.fonts.lato15, 0x000000FF, 15), env);
}
