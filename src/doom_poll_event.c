#include "env.h"

int		doom_poll_event(t_env *env)
{
	while (SDL_PollEvent(&env->sdl.event))
	{
		if (env->sdl.event.type == SDL_QUIT || (env->sdl.event.type == SDL_KEYUP
			&& env->sdl.event.key.keysym.sym == SDLK_ESCAPE))
			env->running = 0;
		else if (env->sdl.event.type == SDL_KEYDOWN
				|| env->sdl.event.type == SDL_KEYUP
				|| env->sdl.event.type == SDL_MOUSEBUTTONDOWN
				|| env->sdl.event.type == SDL_MOUSEBUTTONUP
				|| env->sdl.event.type == SDL_MOUSEWHEEL)
			update_inputs(env);
		if (env->sdl.event.type == SDL_KEYUP
			|| env->sdl.event.type == SDL_MOUSEBUTTONUP)
		{
			if (keyup(env))
				return (crash("Keyup failed\n", env));
		}
		if (env->sdl.event.type == SDL_MOUSEWHEEL && !env->weapon_change.
		  	on_going && !env->shot.on_going && env->player.health > 0)
		{
			env->player.next_weapon = next_possessed_weapon(env);
			if (env->player.next_weapon >= 0)
				weapon_change(env);
		}
	}
	return (0);
}
