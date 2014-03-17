#include "flagger_private.h"
#include <ft/common.h>
#include <ft/getnextline.h>
#include <fcntl.h>
#include <stdlib.h>

static void	ft_flagger_init(t_flagger *flag)
{
	flag->parse = ft_flagger_parse;
	flag->is_active = ft_flagger_is_active;
	flag->get_args = ft_flagger_get_args;
	flag->free = ft_flagger_free;
	flag->print_help = ft_flagger_print_help;
}

t_flagger	*ft_flagger_create(char *conffile, char *prog_name)
{
	t_flagger	*flag;
	int			fd;
	char		*line;

	flag = (t_flagger*)ft_memalloc(sizeof(t_flagger));
	if (flag)
	{
		ft_flagger_init(flag);
		flag->prog_name = prog_name;
		fd = open(conffile, O_RDONLY);
		if (fd != -1)
		{
			while (get_next_line(fd, &line) > 0)
			{
				ft_flagger_parse_line(flag, line);
				free(line);
			}
		}
		close(fd);
	}
	return (flag);
}

