#include "env.h"

void	init_cyber_demon_pursuit_four5(t_env *env)
{
	env->enemy_sprites[8].start[7].x = 173;
	env->enemy_sprites[8].start[7].y = 464;
	env->enemy_sprites[8].end[7].x = 246;
	env->enemy_sprites[8].end[7].y = 571;
	env->enemy_sprites[8].size[7].x = 74;
	env->enemy_sprites[8].size[7].y = 108;
	env->enemy_sprites[8].reversed[7] = 0;
}

void	init_cyber_demon_pursuit_four4(t_env *env)
{
	env->enemy_sprites[8].start[5].x = 394;
	env->enemy_sprites[8].start[5].y = 464;
	env->enemy_sprites[8].end[5].x = 478;
	env->enemy_sprites[8].end[5].y = 573;
	env->enemy_sprites[8].size[5].x = 85;
	env->enemy_sprites[8].size[5].y = 110;
	env->enemy_sprites[8].reversed[5] = 0;
	env->enemy_sprites[8].start[6].x = 291;
	env->enemy_sprites[8].start[6].y = 464;
	env->enemy_sprites[8].end[6].x = 349;
	env->enemy_sprites[8].end[6].y = 571;
	env->enemy_sprites[8].size[6].x = 59;
	env->enemy_sprites[8].size[6].y = 108;
	env->enemy_sprites[8].reversed[6] = 0;
	init_cyber_demon_pursuit_four5(env);
}

void	init_cyber_demon_pursuit_four3(t_env *env)
{
	env->enemy_sprites[8].start[3].x = 651;
	env->enemy_sprites[8].start[3].y = 464;
	env->enemy_sprites[8].end[3].x = 725;
	env->enemy_sprites[8].end[3].y = 573;
	env->enemy_sprites[8].size[3].x = 75;
	env->enemy_sprites[8].size[3].y = 110;
	env->enemy_sprites[8].reversed[3] = 0;
	env->enemy_sprites[8].start[4].x = 523;
	env->enemy_sprites[8].start[4].y = 464;
	env->enemy_sprites[8].end[4].x = 606;
	env->enemy_sprites[8].end[4].y = 572;
	env->enemy_sprites[8].size[4].x = 84;
	env->enemy_sprites[8].size[4].y = 109;
	env->enemy_sprites[8].reversed[4] = 0;
	init_cyber_demon_pursuit_four4(env);
}

void	init_cyber_demon_pursuit_four2(t_env *env)
{
	env->enemy_sprites[8].start[1].x = 873;
	env->enemy_sprites[8].start[1].y = 464;
	env->enemy_sprites[8].end[1].x = 955;
	env->enemy_sprites[8].end[1].y = 574;
	env->enemy_sprites[8].size[1].x = 83;
	env->enemy_sprites[8].size[1].y = 111;
	env->enemy_sprites[8].reversed[1] = 0;
	env->enemy_sprites[8].start[2].x = 770;
	env->enemy_sprites[8].start[2].y = 464;
	env->enemy_sprites[8].end[2].x = 828;
	env->enemy_sprites[8].end[2].y = 574;
	env->enemy_sprites[8].size[2].x = 59;
	env->enemy_sprites[8].size[2].y = 111;
	env->enemy_sprites[8].reversed[2] = 0;
	init_cyber_demon_pursuit_four3(env);
}

void	init_cyber_demon_pursuit_four(t_env *env)
{
	env->enemy_sprites[8].texture = 24;
	env->enemy_sprites[8].death_counterpart = 12;
	env->enemy_sprites[8].pursuit_sprite = 5;
	env->enemy_sprites[8].firing_sprite = 9;
	env->enemy_sprites[8].rest_sprite = 5;
	env->enemy_sprites[8].curr_sprite = 8;
	env->enemy_sprites[8].oriented = 1;
	env->enemy_sprites[8].nb_death_sprites = 8;
	env->enemy_sprites[8].start[0].x = 44;
	env->enemy_sprites[8].start[0].y = 464;
	env->enemy_sprites[8].end[0].x = 128;
	env->enemy_sprites[8].end[0].y = 572;
	env->enemy_sprites[8].size[0].x = 85;
	env->enemy_sprites[8].size[0].y = 109;
	env->enemy_sprites[8].reversed[0] = 0;
	init_cyber_demon_pursuit_four2(env);
}
