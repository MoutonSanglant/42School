/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:35:35 by tdefresn          #+#    #+#             */
/*   Updated: 2015/12/09 15:06:34 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	int		i;

	new_str = ft_strnew(ft_strlen(s));
	if (new_str)
	{
		i = 0;
		while (s[i] != '\0')
		{
			new_str[i] = f(s[i]);
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
