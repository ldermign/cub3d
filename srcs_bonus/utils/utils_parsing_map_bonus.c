/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_map_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:54:13 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/13 22:41:03 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	size_tab_char(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (0);
	while (tab[i] != NULL)
		i++;
	return (i);
}

int	cara_in_map(int c)
{
	return (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E' || c == ' ');
}

int	get_position(char **tab, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == (char)c)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strchr_tab_wrong_cara(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!cara_in_map(tab[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	which_is_larger(char **tab)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (tab[i])
	{
		if (len < (int)ft_strlen(tab[i])
			&& !ft_is_either(tab[i]) && tab[i] != NULL)
			len = ft_strlen(tab[i]);
		i++;
	}
	return (len);
}
