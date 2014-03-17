#ifndef FT_FLAGGER_PRIVATE_H
# define FT_FLAGGER_PRIVATE_H

# include "flagger.h"
# include <ft/astr.h>

typedef enum e_flagtype	t_flagtype;

enum	e_flagtype { FT_NO, FT_ARGS };

struct		s_flag
{
	t_flagtype	type;
	char		c;
	char		*name;
	t_bool		empty;
	t_bool		is_args;
	int			nb_args;
	int			min_args;
	t_bool		active;
	t_astr		*args;
	t_flag		*next;
};

t_bool	ft_flagger_single(t_flagger *flag, char ***argv);
t_bool	ft_flagger_mult(t_flagger *flag, char ***argv);
void	ft_flagger_parse_line(t_flagger *flag, char *line);
void	ft_flagger_opt(t_flag *flag, char *line);
t_bool	ft_flagger_parse(t_flagger *flag, char ***argv);
t_bool	ft_flagger_usage_single(t_flagger *flag, char c);
t_bool	ft_flagger_usage_mult(t_flagger *flag, char *str);
t_bool	ft_flagger_usage_few_args(t_flagger *flag, char c);
t_bool	ft_flagger_usage_few_args_str(t_flagger *flag, char *str);
t_bool	ft_flagger_args(t_flag *find, char ***argv, t_bool go);
t_flag	*ft_flagger_get_single(t_flagger *flag, char c);
t_flag	*ft_flagger_get_mult(t_flagger *flag, char *str);
t_bool	ft_flagger_is_active(t_flagger *flag, char *str);
t_astr	*ft_flagger_get_args(t_flagger *flag, char *str);
void	ft_flagger_free(t_flagger **flag);
void	ft_flagger_print_help(t_flagger *flag);

#endif
