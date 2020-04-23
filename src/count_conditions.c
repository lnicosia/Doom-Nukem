#include "events_parser.h"
#include "events_conditions.h"

int		check_current_condition(char *line, t_map_parser *parser, int *count,
int *open)
{
	if (!*line)
		return (missing_data("']' after event launch conditions", parser));
	if (*line == '{')
	{
		if (*open)
			return (custom_error_with_line("Unbalanced \'{\' and \'}\'",
			parser));
			(*open)++;
		(*count)++;
		if ((*count) > 2147483646)
			return (custom_error_with_line("Too much launch conditions",
			parser));
	}
	if (*line == '}')
	{
		if (!(*open))
			return (custom_error_with_line("Unbalanced \'{\' and \'}\'",
			parser));
			(*open)--;
	}
	return (0);
}

int		count_conditions(char *line, t_map_parser *parser)
{
	int	count;
	int	open;

	count = 0;
	open = 0;
	while (*line != ']')
	{
	  	if (check_current_condition(line, parser, &count, &open))
		  	return (-1);
		line++;
	}
	return (count);
}
