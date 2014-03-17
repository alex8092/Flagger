#include "flagger_private.h"

t_flag	*ft_flagger_get_mult(t_flagger *flag, char *str)
{
	t_flag	*cur;

	cur = flag->m_begin;
	while (cur)
	{
		if (cur->name && !ft_strcmp(cur->name, str))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_bool	ft_flagger_mult(t_flagger *flag, char ***argv)
{
	char	*str;
	t_flag	*find;

	str = (*argv)[0] + 2;
	++(*argv);
	find = ft_flagger_get_mult(flag, str);
	if (find)
	{
		if (!find->empty)
		{
			if (!ft_flagger_args(find, argv, true))
				return (ft_flagger_usage_few_args_str(flag, str));
		}
		find->active = true;
	}
	else
		return (ft_flagger_usage_mult(flag, str));
	return (true);
}
