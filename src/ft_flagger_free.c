#include "flagger_private.h"
#include <stdlib.h>

static void	ft_flagger_free_flag(t_flag *flag)
{
	if (flag->name)
		free(flag->name);
	if (flag->args)
		flag->args->free(&flag->args, false);
	free(flag);
}

void		ft_flagger_free(t_flagger **flag)
{
	t_flag	*cur;
	t_flag	*tmp;

	cur = (*flag)->m_begin;
	while (cur)
	{
		tmp = cur->next;
		ft_flagger_free_flag(cur);
		cur = tmp;
	}
	free(*flag);
	*flag = NULL;
}
