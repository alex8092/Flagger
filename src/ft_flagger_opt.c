#include "flagger_private.h"
#include <stdlib.h>

static void	free_split(char **tab)
{
	size_t	index;

	index = 0;
	while (tab[index])
	{
		free(tab[index]);
		++index;
	}
	free(tab);
}

void		ft_flagger_opt(t_flag *flag, char *line)
{
	char	**tab;
	size_t	i;

	tab = ft_strsplit(line, ' ', false);
	i = 0;
	while (tab[i])
	{
		if (!ft_strcmp(tab[i], "empty"))
			flag->empty = true;
		else if (!ft_strncmp(tab[i], "args[", 5))
		{
			flag->nb_args = ft_atoi(tab[i] + 5);
			line = ft_strchr(tab[i] + 5, ',');
			flag->min_args = (line) ? ft_atoi(line + 1) : 0;
			flag->is_args = true;
		}
		else if (!ft_strncmp(tab[i], "same[", 5))
		{
			line = ft_strchr(tab[i] + 5, ']');
			if (line)
				flag->name = ft_strndup(tab[i] + 5, line - tab[i] - 5);
		}
		++i;
	}
	free_split(tab);
}
