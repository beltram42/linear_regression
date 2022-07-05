/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alambert <alambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 22:02:34 by alambert          #+#    #+#             */
/*   Updated: 2022/07/05 21:14:11 by alambert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static void	malloc_error(char **array, int len)
{
	while (len--)
	{
		free(*array);
		array++;
	}
	free(array);
}

static char	*ft_strtok_rbis(char *str, const char *sep, char ***saveptr)
{
	char	*start;

	if (!str)
		str = **saveptr;
	while (*str && ft_strchr(sep, *str))
		++str;
	if (*str)
	{
		start = (char *)str;
		**saveptr = start + 1;
		while (***saveptr && !ft_strchr(sep, ***saveptr))
			++**saveptr;
		if (***saveptr)
		{
			***saveptr = '\0';
			++**saveptr;
		}
		return (start);
	}
	return (NULL);
}

static int	ft_wordmeter(char *str, const char *set, char **saveptr)
{
	char	*token;
	int		w;

	w = 0;
	token = ft_strtok_rbis(str, set, &saveptr);
	if (token != NULL)
		w++;
	while (token)
	{
		token = ft_strtok_rbis(NULL, set, &saveptr);
		if (!token)
			break ;
		w++;
	}
	return (w);
}

static void	ft_implement(char **split, const char *p, const char *set, int w)
{
	int	len;
	int	wcpy;

	wcpy = w;
	while (wcpy--)
	{
		while (*p && ft_strchr(set, *p))
			++p;
		len = ft_strlen(p) + 1;
		*split = malloc(sizeof(char) * (len));
		if (*split == NULL)
		{
			malloc_error(split, w);
			return ;
		}
		ft_memcpy(*split, p, len);
		p += len;
		split++;
	}
	*split = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	*p;
	char	*saveptr;
	char	set[2];
	int		w;
	char	**split;

	if (s == NULL)
		return (NULL);
	w = ft_strlen(s);
	p = malloc(sizeof(char) * (w + 1));
	if (!p)
		return (NULL);
	ft_memcpy(p, s, w + 1);
	set[0] = c;
	set[1] = '\0';
	saveptr = NULL;
	w = ft_wordmeter(p, (char const *)set, &saveptr);
	split = malloc(sizeof(char *) * (w + 1));
	if (split == NULL)
		return (NULL);
	ft_implement(split, p, set, w);
	free(p);
	return (split);
}
