/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpaez-mo <bpaez-mo@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 10:52:23 by bpaez-mo          #+#    #+#             */
/*   Updated: 2025/05/16 10:52:26 by bpaez-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	if (s[0] == '\0')
		return (0);
	count = 0;
	if (s[0] != c)
		count++;
	i = 1;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static size_t	get_word_len(const char *s, char c)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

static void	free_tab(char **tab, int i)
{
	if (!tab)
		return ;
	while (i--)
		free(tab[i]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	char	**result_array;
	size_t	i;
	size_t	j;

	result_array = (char **)malloc(sizeof(char *) * (get_word(s, c) + 1));
	if (result_array == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < get_word(s, c))
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		result_array[i] = ft_substr(s, j, get_word_len(&s[j], c));
		if (!result_array[i])
		{
			free_tab(result_array, i);
			return (NULL);
		}
		j = j + get_word_len(&s[j], c);
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
