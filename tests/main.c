#include "flagger.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	t_flagger	*flag;
	t_astr		*args;
	size_t		index;

	if (ac >= 2)
	{
		flag = ft_flagger_create(av[1], av[0]);
		av += 2;
		if (flag->parse(flag, &av))
		{
			if (flag->is_active(flag, "c"))
				printf("c active\n");
			if (flag->is_active(flag, "f"))
			{
				printf("f active\n");
				args = flag->get_args(flag, "f");
				index = 0;
				while (args && index < args->m_size)
				{
					printf("\targ : %s\n", args->get(args, index));
					++index;
				}
			}
		}
		else
			flag->print_help(flag);
		flag->free(&flag);
	}
	return (0);
}
