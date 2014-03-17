#include "flagger_private.h"

t_bool	ft_flagger_args(t_flag *find, char ***argv, t_bool go)
{
	if (!find->args)
		find->args = ft_astr_create(0);
	while (go && (*argv)[0] && (*argv)[0][0] != '-')
	{
		find->args->add(find->args, (*argv)[0]);
		++(*argv);
		if (find->nb_args != 0
			&& (int)find->args->m_size == find->nb_args)
			break ;
	}
	if (find->nb_args != 0
		&& (int)find->args->m_size != find->nb_args)
		return (false);
	else if (find->min_args != 0
			&& (int)find->args->m_size < find->min_args)
		return (false);
	return (true);
}
