#include "env.h"
#include "collision.h"

void	game_time(t_env *env)
{
	double	new_time;

	new_time = env->time.milli_s;
	env->time.milli_s = SDL_GetTicks();
	env->player.rotation_speed = ((env->time.milli_s - new_time) / 1000.0)
	* 0.2;
	env->time.tenth_s = env->time.milli_s / 100.0;
}

void	adjust_player_z_after_climb(double slope, t_env *env)
{
	env->player.pos.z = slope;
	env->player.state.climb = 0;
	env->player.velocity = 0;
	env->time.d_time = 0;
}

void	climb(t_env *env)
{
	double	time;
	double	slope;
	t_v3		pos;

	pos.x = env->player.pos.x;
	pos.y = env->player.pos.y;
	slope = get_floor_at_pos(&env->sectors[env->player.highest_sect], pos, env);
	time = SDL_GetTicks() / 100.0;
	if (!env->player.state.climb)
	{
		env->player.state.climb = 1;
		env->time.last_climb = SDL_GetTicks() / 100.0;
		env->player.velocity = 0.4;
	}
	if (env->player.state.climb)
	{
		env->time.d_time = time - env->time.last_climb;
		env->player.pos.z += env->time.d_time * env->player.velocity;
	}
	if (env->player.pos.z >= slope)
	  	adjust_player_z_after_climb(slope, env);
}
