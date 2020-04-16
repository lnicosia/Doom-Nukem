#include "events_parser.h"

int		check_align_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0 && event->start_value + time * event->incr > 1000000)
			|| (event->incr < 0
				&& event->start_value + time * event->incr < -1000000)
			|| (!event->speed && (event->goal > 1000000
					|| event->goal < -1000000)))
		return (1);
	return (0);
}

int		check_brightness_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0 && event->start_value + time * event->incr >= 255)
		|| (event->incr < 0 && event->start_value + time * event->incr <= -255)
		|| (!event->speed && (event->goal >= 255 || event->goal <= -255)))
		return (1);
	return (0);
}

int		check_color_event(t_event *event, void *penv)
{
	Uint32	time;

	(void)penv;
	time = SDL_GetTicks() - event->start_time;
	time = time == 0 ? 1 : time;
	if ((event->incr > 0 && event->start_value + time * event->incr >=
				0xFFFFFFFF)
		|| (event->incr < 0 && event->start_value + time * event->incr <= 0)
		|| (!event->speed && ((Uint32)event->goal > 0xFFFFFFFF)))
		return (1);
	return (0);
}
