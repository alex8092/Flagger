#include "flagger_private.h"
#include <ft/common.h>

static t_flag	*ft_flag_add(t_flag *parent, char c, char *name)
{
	t_flag	*f;

	f = (t_flag*)ft_memalloc(sizeof(t_flag));
	if (f)
	{
		f->c = c;
		f->nb_args = 1;
		if (name)
			f->name = ft_strdup(name);
		if (parent)
			parent->next = f;
	}
	return (f);
}

void			ft_flagger_parse_line(t_flagger *flag, char *line)
{
	char	*find;
	int		len;

	find = ft_strchr(line, ':');
	if (find)
	{
		len = find - line;
		*find = 0;
		if (len == 1)
			flag->m_end = ft_flag_add(flag->m_end, *line, NULL);
		else
			flag->m_end = ft_flag_add(flag->m_end, 0, line);
		ft_flagger_opt(flag->m_end, find + 1);
		if (!flag->m_begin)
			flag->m_begin = flag->m_end;
		*find = ':';
	}
}

static t_bool	ft_flagger_parse_arg(t_flagger *flag, char ***argv)
{
	if ((*argv)[0][1] == '-' && (*argv)[0][2] == 0)
	{
		++(*argv);
		return (false);
	}
	else if ((*argv)[0][1] != '-')
		return (ft_flagger_single(flag, argv));
	return (ft_flagger_mult(flag, argv));
}

t_bool		ft_flagger_parse(t_flagger *flag, char ***argv)
{
	char	**av;

	av = *argv;
	while (*av)
	{
		if (av[0][0] == '-')
		{
			if (!ft_flagger_parse_arg(flag, &av))
				break ;
		}
		else
			break ;
	}
	*argv = av;
	return (!flag->m_error);
}
