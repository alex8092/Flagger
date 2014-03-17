#include "flagger_private.h"

t_bool	ft_flagger_is_active(t_flagger *flag, char *str)
{
	t_flag	*find;

	if (ft_strlen(str) > 1)
		find = ft_flagger_get_mult(flag, str);
	else
		find = ft_flagger_get_single(flag, *str);
	if (find)
		return (find->active);
	return (false);
}

t_astr	*ft_flagger_get_args(t_flagger *flag, char *str)
{
	t_flag	*find;

	if (ft_strlen(str) > 1)
		find = ft_flagger_get_mult(flag, str);
	else
		find = ft_flagger_get_single(flag, *str);
	if (find)
		return (find->args);
	return (NULL);
}
