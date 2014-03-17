#include "flagger_private.h"

t_bool	ft_flagger_usage_single(t_flagger *flag, char c)
{
	char	str[] = "usage: invalid flag [";

	write(2, str, sizeof(str) - 1);
	write(2, &c, 1);
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}

t_bool	ft_flagger_usage_mult(t_flagger *flag, char *str)
{
	char	strb[] = "usage: invalid flag[";

	write(2, strb, sizeof(strb) - 1);
	write(2, str, ft_strlen(str));
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}

t_bool	ft_flagger_usage_few_args(t_flagger *flag, char c)
{
	char	str[] = "usage: to few arguments to flag [";

	write(2, str, sizeof(str) - 1);
	write(2, &c, 1);
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}

t_bool	ft_flagger_usage_few_args_str(t_flagger *flag, char *str)
{
	char	strb[] = "usage: to few arguments to flag[";

	write(2, strb, sizeof(strb) - 1);
	write(2, str, ft_strlen(str));
	write(2, "]\n", 2);
	flag->m_error = true;
	return (false);
}
