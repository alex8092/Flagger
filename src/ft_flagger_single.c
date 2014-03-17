#include "flagger_private.h"
#include <ft/astr.h>

t_flag			*ft_flagger_get_single(t_flagger *flag, char c)
{
	t_flag	*cur;

	cur = flag->m_begin;
	while (cur)
	{
		if (cur->c == c)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_bool			ft_flagger_single(t_flagger *flag, char ***argv)
{
	char	*str;
	t_flag	*find;

	str = (*argv)[0] + 1;
	++(*argv);
	while (*str)
	{
		find = ft_flagger_get_single(flag, *str);
		if (!find)
			return (ft_flagger_usage_single(flag, *str));
		if (!find->empty && (!(*(str + 1)) || !find->nb_args))
		{
			if (!ft_flagger_args(find, argv, !(*(str + 1))))
				return (ft_flagger_usage_few_args(flag, *str));
		}
		else if (!find->empty)
			return (ft_flagger_usage_few_args(flag, *str));
		find->active = true;
		++str;
	}
	return (true);
}
