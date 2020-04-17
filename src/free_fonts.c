#include "env.h"

void		free_fonts3(t_env *env)
{
	if (env->sdl.fonts.lato_black50)
		TTF_CloseFont(env->sdl.fonts.lato_black50);
	if (env->sdl.fonts.lato_bold10)
		TTF_CloseFont(env->sdl.fonts.lato_bold10);
	if (env->sdl.fonts.lato_bold15)
		TTF_CloseFont(env->sdl.fonts.lato_bold15);
	if (env->sdl.fonts.lato_bold20)
		TTF_CloseFont(env->sdl.fonts.lato_bold20);
	if (env->sdl.fonts.lato_bold25)
		TTF_CloseFont(env->sdl.fonts.lato_bold25);
	if (env->sdl.fonts.lato_bold30)
		TTF_CloseFont(env->sdl.fonts.lato_bold30);
	if (env->sdl.fonts.lato_bold35)
		TTF_CloseFont(env->sdl.fonts.lato_bold35);
	if (env->sdl.fonts.lato_bold40)
		TTF_CloseFont(env->sdl.fonts.lato_bold40);
	if (env->sdl.fonts.lato_bold45)
		TTF_CloseFont(env->sdl.fonts.lato_bold45);
	if (env->sdl.fonts.lato_bold50)
		TTF_CloseFont(env->sdl.fonts.lato_bold50);
	if (env->sdl.fonts.bebasneue)
		TTF_CloseFont(env->sdl.fonts.bebasneue);
}

void		free_fonts2(t_env *env)
{
	if (env->sdl.fonts.lato40)
		TTF_CloseFont(env->sdl.fonts.lato40);
	if (env->sdl.fonts.lato45)
		TTF_CloseFont(env->sdl.fonts.lato45);
	if (env->sdl.fonts.lato50)
		TTF_CloseFont(env->sdl.fonts.lato50);
	if (env->sdl.fonts.lato_black10)
		TTF_CloseFont(env->sdl.fonts.lato_black10);
	if (env->sdl.fonts.lato_black15)
		TTF_CloseFont(env->sdl.fonts.lato_black15);
	if (env->sdl.fonts.lato_black20)
		TTF_CloseFont(env->sdl.fonts.lato_black20);
	if (env->sdl.fonts.lato_black25)
		TTF_CloseFont(env->sdl.fonts.lato_black25);
	if (env->sdl.fonts.lato_black30)
		TTF_CloseFont(env->sdl.fonts.lato_black30);
	if (env->sdl.fonts.lato_black35)
		TTF_CloseFont(env->sdl.fonts.lato_black35);
	if (env->sdl.fonts.lato_black40)
		TTF_CloseFont(env->sdl.fonts.lato_black40);
	if (env->sdl.fonts.lato_black45)
		TTF_CloseFont(env->sdl.fonts.lato_black45);
	free_fonts3(env);
}

void		free_fonts(t_env *env)
{
	if (env->sdl.fonts.amazdoom70)
		TTF_CloseFont(env->sdl.fonts.amazdoom70);
	if (env->sdl.fonts.amazdoom50)
		TTF_CloseFont(env->sdl.fonts.amazdoom50);
	if (env->sdl.fonts.amazdoom20)
		TTF_CloseFont(env->sdl.fonts.amazdoom20);
	if (env->sdl.fonts.alice30)
		TTF_CloseFont(env->sdl.fonts.alice30);
	if (env->sdl.fonts.alice70)
		TTF_CloseFont(env->sdl.fonts.alice70);
	if (env->sdl.fonts.lato10)
		TTF_CloseFont(env->sdl.fonts.lato10);
	if (env->sdl.fonts.lato15)
		TTF_CloseFont(env->sdl.fonts.lato15);
	if (env->sdl.fonts.lato20)
		TTF_CloseFont(env->sdl.fonts.lato20);
	if (env->sdl.fonts.lato25)
		TTF_CloseFont(env->sdl.fonts.lato25);
	if (env->sdl.fonts.lato30)
		TTF_CloseFont(env->sdl.fonts.lato30);
	if (env->sdl.fonts.lato35)
		TTF_CloseFont(env->sdl.fonts.lato35);
	free_fonts2(env);
}
