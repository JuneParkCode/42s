
#include "ft_bsq.h"

int is_duplicate_char(t_rules *my_rule)
{
    return (my_rule -> empty == my_rule -> obstacle || 
			my_rule -> empty == my_rule -> full ||
			my_rule -> full == my_rule -> obstacle);
}

int is_printable_sign(t_rules *my_rule)
{
	return (ft_is_printable(my_rule -> empty) &&
			ft_is_printable(my_rule -> full) &&
			ft_is_printable(my_rule -> obstacle));
}

t_rules	*get_rule(char *rule_str, char **input)
{
	int		size;
	int		len_str;
	t_rules	*my_rule;

	my_rule = malloc(sizeof(my_rule));
	if (!my_rule)
		return (0);
	len_str = ft_strlen(rule_str);
	size = ft_atoi(rule_str, len_str - 3);
	my_rule -> map_row = size;
	my_rule -> map_col = ft_strlen(input[1]);
	my_rule -> empty = rule_str[len_str - 3];
	my_rule -> obstacle = rule_str[len_str - 2];
	my_rule -> full = rule_str[len_str - 1];
	if (is_duplicate_char(my_rule) || !is_printable_sign(my_rule) || !size)
	{
		free(my_rule);
        return (0);
	}
	return (my_rule);
}