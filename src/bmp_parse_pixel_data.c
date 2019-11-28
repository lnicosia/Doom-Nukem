/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   bmp_parse_pixel_data.c							 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/05/01 13:22:47 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/11/26 13:47:37 by lnicosia         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "env.h"
#include "bmp_parser.h"

static unsigned int	get_pixel(double byte, unsigned char *str, t_bmp_parser *parser)
{
	if (parser->bpp == 32)
		return (read_color32(str, byte));
	if (parser->bpp == 24)
		return (read_color24(str, byte));
	if (parser->bpp == 16)
		return (read_color16(str, byte));
	if (parser->bpp == 8)
		return (read_color8(str, byte, parser));
	if (parser->bpp == 4)
		return (read_color4(str, byte, parser->colors));
	if (parser->bpp == 1)
		return (read_color1(str, byte, parser->colors));
	return (0);
}

int					parse_pixel_data(int fd, t_bmp_parser *parser, int index, t_env *env)
{
	double			byte;
	double			trash;
	int				x;
	int				y;
	int				ret;
	int				size;
	unsigned char	*str;

	ft_printf("{cyan}");
	if (parser->image_size)
		size = parser->image_size;
	else
		size = ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h;
	//ft_printf("size = %d\n", ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h);
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (ft_printf("Could not malloc buffer for pixel data\n"));
	if ((ret = read(fd, str, size)) > 0)
	{
		byte = 0;
		x = 0;
		y = parser->h - 1;
		while (byte + 4 < ret)
		{
			env->sprite_textures[index].str[x + y * parser->w] = get_pixel(byte, str, parser); 
			byte += parser->bpp / 8.0;
			x++;
			if (x >= parser->w)
			{
				while (modf(byte, &trash) != 0)
					byte += parser->bpp / 8.0;
				while ((int)byte % 4 != 0)
					byte ++;
				x = 0;
				y--;
			}
		}
	}
	ft_memdel((void**)&str);
	return (0);
}

int					parse_pixel_data_wall(int fd, t_bmp_parser *parser, int index, t_env *env)
{
	double			byte;
	double			trash;
	int				x;
	int				y;
	int				ret;
	int				size;
	unsigned char	*str;

	ft_printf("{cyan}");
	if (parser->image_size)
		size = parser->image_size;
	else
		size = ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h;
	//ft_printf("size = %d\n", ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h);
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (ft_printf("Could not malloc buffer for pixel data\n"));
	if ((ret = read(fd, str, size)) > 0)
	{
		byte = 0;
		x = 0;
		y = parser->h - 1;
		while (byte + 4 < ret)
		{
			env->wall_textures[index].str[x + y * parser->w] = get_pixel(byte, str, parser); 
			byte += parser->bpp / 8.0;
			x++;
			if (x >= parser->w)
			{
				while (modf(byte, &trash) != 0)
					byte += parser->bpp / 8.0;
				while ((int)byte % 4 != 0)
					byte ++;
				x = 0;
				y--;
			}
		}
	}
	ft_memdel((void**)&str);
	return (0);
}

int					parse_pixel_data_skybox(int fd, t_bmp_parser *parser, int num_sky, int index, t_env *env)
{
	double			byte;
	double			trash;
	int				x;
	int				y;
	int				ret;
	int				size;
	unsigned char	*str;

	ft_printf("{cyan}");
	if (parser->image_size)
		size = parser->image_size;
	else
		size = ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h;
	//ft_printf("size = %d\n", ceil((parser->w * parser->bpp) / 32.0) * 4 * parser->h);
	if (!(str = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (ft_printf("Could not malloc buffer for pixel data\n"));
	if ((ret = read(fd, str, size)) > 0)
	{
		byte = 0;
		x = 0;
		y = parser->h - 1;
		while (byte + 4 < ret)
		{
			env->skyboxes[num_sky].textures[index].str[x + y * parser->w] = get_pixel(byte, str, parser); 
			byte += parser->bpp / 8.0;
			x++;
			if (x >= parser->w)
			{
				while (modf(byte, &trash) != 0)
					byte += parser->bpp / 8.0;
				while ((int)byte % 4 != 0)
					byte ++;
				x = 0;
				y--;
			}
		}
	}
	ft_memdel((void**)&str);
	return (0);
}
