/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 17:07:33 by tdefresn          #+#    #+#             */
/*   Updated: 2016/03/14 15:39:17 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	2 steps routine:
**	- fetch flags
**	- fetch directory names
*/

static int		fetch_flags(int argc, char **argv, t_ls_datas *ls_datas)
{
	char	*arg;
	int		reverse;
	int		len;
	int		i;
	int		j;

	i = 0;
	reverse = 0;
	while (++i < argc && argv[i][0] == '-')
	{
		arg = argv[i];
		len = ft_strlen(arg);
		if (len < 2)
			break ;
		j = 0;
		while (++j < len)
		{
			if (arg[j] == 'R')
				ls_datas->flags |= FLAG_BIG_R;
			else if (arg[j] == 'a')
				ls_datas->flags |= FLAG_A;
			else if (arg[j] == 'l')
				ls_datas->print_fn = &print_detailed_line;
			else if (arg[j] == 'r')
				reverse = 1;
			else if (arg[j] == 't')
				ls_datas->sort_fn = &sort_time;
			else
				error_usage(arg[j], ls_datas);
		}
	}
	if (reverse)
	{
		ls_datas->sort_fn = &sort_antilexicographic;
		ls_datas->time_sort_fn = &sort_time_reverse;
	}
	return (i - 1);
}

static void		add_file(t_ls_datas *ls_datas, t_file_datas *file,
								t_list **list)
{
	if (*list)
	{
		(*list)->next = fetch_file_datas(ls_datas, file, "");
		*list = (*list)->next;
	}
	else
	{
		*list = fetch_file_datas(ls_datas, file, "");
		ls_datas->files = *list;
	}
}

static void		add_folder(t_ls_datas *ls_datas, t_file_datas *file,
								t_list **list)
{
	if (*list)
	{
		(*list)->next = ft_lstnew((void *)file, sizeof(t_file_datas));
		*list = (*list)->next;
	}
	else
	{
		*list = ft_lstnew((void *)file, sizeof(t_file_datas));
		ls_datas->directories = *list;
	}
}

void			fetch_args(int argc, char **argv, t_ls_datas *ls_datas)
{
	t_list			*dir_list;
	t_list			*files_list;
	t_file_datas	file;
	struct stat		st_stat;
	int				flag_count;

	dir_list = NULL;
	files_list = NULL;
	flag_count = fetch_flags(argc, argv, ls_datas);
	while (--argc > flag_count)
	{
		file.pathname = NULL;
		file.name = ft_strdup(argv[argc]);
		if (lstat(file.name, &st_stat) < 0)
			error_path(file.name);
		else if (S_ISDIR(st_stat.st_mode))
			add_folder(ls_datas, &file, &dir_list);
		else if (S_ISREG(st_stat.st_mode) || S_ISLNK(st_stat.st_mode))
			add_file(ls_datas, &file, &files_list);
		else
			add_file(ls_datas, &file, &files_list);
	}
	if (!ls_datas->directories && !files_list)
	{
		file.name = ft_strdup(".");
		file.pathname = NULL;
		add_folder(ls_datas, &file, &dir_list);
	}
}
