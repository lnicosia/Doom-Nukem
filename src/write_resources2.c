#include "env.h"
#include "bmp_parser.h"

int		writing_bmp(int file, int fd, char *name)
{
	unsigned char	resource[10000];
	unsigned char	header[14];
	int				ret;
	int32_t			size;

	if (read(file, header, 14) != 14)
		return (ft_printf("Invalid bmp file\n"));
	size = read_int32(header, 2);
	ft_dprintf(fd, "%s\n%d\n", name, size);
	write(fd, header, 14);
	while ((ret = (read(file, resource, 10000))) > 0)
		write(fd, resource, ret);
	write(fd, "\n", 1);
	if (close(file))
		return (ft_printf("Could not close the resource\n"));
	return (0);
}

int		write_textures(int fd, t_env *env)
{
	(void)env;
	ft_printf("saving textures\n");
	ft_dprintf(fd, "T %d\n", MAX_WALL_TEXTURE);
	if (write_textures1(fd))
		return (-1);
	if (write_textures2(fd))
		return (-1);
	if (write_textures3(fd))
		return (-1);
	return (0);
}
