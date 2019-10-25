
#include "env.h"
#include "map_parser.h"

typedef struct	s_benchmark
{
	double	average;
	double	min;
	double	max;
}		t_benchmark;

void		write_data(int fd, t_benchmark old, t_benchmark new,
	t_env *env)
{
	ft_dprintf(fd, "OLD RENDER\n");
	ft_dprintf(fd, "Average fps = %f\n", (env->avrg_fps + old.average) / 2);
	ft_dprintf(fd, "Min fps = %f\n", (env->min_fps + old.min) / 2);
	ft_dprintf(fd, "Min fps = %f\n", (env->max_fps + old.max) / 2);
	ft_dprintf(fd, "NEW RENDER\n");
	ft_dprintf(fd, "Average fps = %f\n", (env->avrg_fps2 + new.average) / 2);
	ft_dprintf(fd, "Min fps = %f\n", (env->min_fps2 + new.min) / 2);
	ft_dprintf(fd, "Max fps = %f\n", (env->max_fps2 + new.max) / 2);
}

int		read_data(int fd, t_benchmark *old, t_benchmark *new)
{
	char	*str;

	str = NULL;
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	old->average = atof(str);
	get_next_line(fd, &str);
	old->min = atoi(str);
	get_next_line(fd, &str);
	old->max = atoi(str);
	get_next_line(fd, &str);
	get_next_line(fd, &str);
	new->average = atof(str);
	get_next_line(fd, &str);
	new->min = atoi(str);
	get_next_line(fd, &str);
	new->max = atoi(str);
	return (0);
}

int		save_benchmark(t_env *env)
{
	int		fd;
	t_benchmark	old;
	t_benchmark	new;

	ft_printf("Average OLD RENDER fps: %f\nMin fps = %d\nMax fps = %d\n",
		env->avrg_fps, env->min_fps, env->max_fps);
	ft_printf("Average NEW RENDER fps: %f\nMin fps = %d\nMax fps = %d\n",
		env->avrg_fps2, env->min_fps2, env->max_fps2);
	if ((fd = open("benchmark.txt", O_RDONLY)) < 0)
	{
		ft_printf("New benchmark file\n");
		old.average = env->avrg_fps;
		old.min = env->min_fps;
		old.max = env->max_fps;
		new.average = env->avrg_fps2;
		new.min = env->min_fps2;
		new.max = env->max_fps2;
	}
	else if (read_data(fd, &old, &new))
		return (-1);
	if ((fd >= 0) && close(fd))
		return (ft_printf("Could not close the file\n"));
	if ((fd = open("benchmark.txt", O_WRONLY | O_CREAT
		| O_TRUNC, 0000700)) < 0)
		return (ft_printf("{red}Could not open benchmark file{reset\n"));
	write_data(fd, old, new, env);
	if (close(fd))
		return (ft_printf("Could not close the file\n"));
	ft_printf("{reset}");
	return (0);
}
