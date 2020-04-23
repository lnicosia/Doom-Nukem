#include "env.h"

int		int_incr_event(t_event *curr, int *target)
{
	double	new_total;

	new_total = curr->total + (SDL_GetTicks() - curr->last_tick)
	* fabs(curr->incr);
	if (floor(new_total) != floor(curr->total))
	{
		if (curr->start_incr > 0)
			(*target)++;
		else
			(*target)--;
	}
	if (new_total < fabs(curr->start_incr))
	{
		curr->total = new_total;
		curr->last_tick = SDL_GetTicks();
	}
	else
		return (1);
	return (0);
}

int		int_fixed_event(t_event *curr, int *target, Uint32 time)
{
	*target = curr->start_value + time * curr->incr;
	if ((curr->incr > 0 && *target >= curr->goal)
			|| (curr->incr < 0 && *target <= curr->goal))
	{
		*target = curr->goal;
		return (1);
	}
	return (0);
}

int		int_event(t_event *curr)
{
	Uint32	time;
	int		*target;

	target = (int*)curr->target;
	if (!curr->speed)
	{
		*target = curr->goal;
		curr->end_time = SDL_GetTicks();
		return (1);
	}
	time = SDL_GetTicks() - curr->start_time;
	time = time == 0 ? 1 : time;
	if (curr->mod_type == FIXED)
	{
	  	if (int_fixed_event(curr, target, time))
		  	return (1);
	}
	else
	{
	  	if (int_incr_event(curr, target))
		  	return (1);
	}
	return (0);
}
