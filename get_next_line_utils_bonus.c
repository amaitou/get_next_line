/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: amait-ou <amait-ou@student.1337.ma>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/10/25 11:27:15 by amait-ou		  #+#	#+#			 */
/*   Updated: 2022/11/08 19:58:06 by amait-ou         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	char	*p;

	if (!s)
		return (0);
	p = (char *)s;
	while (*p && *p != (char)c)
		++p;
	if (*p == (char)c)
		return (p);
	return ((void *)0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*p;

	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		++i;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
	free(s1);
	return (p);
}

char	*get_one_line(char *stash)
{
	char	*line;
	int		i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		++i;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*free_stash(char *reserve)
{
	char	*stash;
	int		i;
	int		j;

	if (!reserve)
		return (NULL);
	i = 0;
	j = 0;
	while (reserve[i] != '\n' && reserve[i])
		++i;
	if (!reserve[i] || (reserve[i] == '\n' && reserve[i + 1] == '\0'))
	{
		free(reserve);
		return (NULL);
	}
	stash = malloc((ft_strlen(reserve) - i));
	if (stash)
	{
		while (reserve[++i])
			stash[j++] = reserve[i];
		stash[j] = '\0';
	}
	free(reserve);
	return (stash);
}
