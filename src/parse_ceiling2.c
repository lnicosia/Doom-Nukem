#include "map_parser.h"
#include "env.h"

int		parse_ceiling6(t_env *env, char **line, t_map_parser *parser)
{
	if (env->sectors[parser->sectors_count].ceiling_map_scale.y < 1
		|| env->sectors[parser->sectors_count].ceiling_map_scale.y > 100)
		return (custom_error_with_line("Ceiling scale must be"
		"between 1 and 100", parser));

	if (set_sector_ceiling_map_array(&env->sectors[parser->sectors_count], 
		&env->wall_textures[env->sectors[parser->sectors_count].
		ceiling_texture], env))
		return (-1);
	*line = skip_number(*line);
	if (!**line)
		return (missing_data("']' after ceiling texture",parser));
	if (**line != ']')
		return (invalid_char("after ceiling texture", "a digit or ']'",
					**line, parser));
	(*line)++;
	if (!**line)
		return (missing_data("vertices, neighbors, textures and light",
					parser));
	if (**line != ' ')
		return (invalid_char("after ceiling data", "space(s)",
					**line, parser));
	*line = skip_spaces(*line);
	return (0);
}
