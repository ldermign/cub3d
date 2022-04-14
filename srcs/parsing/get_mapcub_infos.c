/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/14 13:10:23 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_floor(t_arg *data, char *str)
{
	int	i;

	i = 0;
	if (check_floor_sky(data, str) == -1)
		return (-1);
	if (data->flr_r != 0 || data->flr_g != 0 || data->flr_b != 0)
		return (quit_parsing(data,
				"You've duplicated info about the floor.\n", 0, 0));
	while (str[i] && space_or_element(str[i]))
		i++;
	data->flr_r = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->flr_g = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->flr_b = ft_atoi((const char *)str + i);
	return (1);
}

int	get_sky(t_arg *data, char *str)
{
	int	i;

	i = 0;
	if (check_floor_sky(data, str) == -1)
		return (-1);
	if (data->ciel_r != 0 || data->ciel_g != 0 || data->ciel_b != 0)
		return (quit_parsing(data,
				"You've duplicated info about the sky.\n", 0, 0));
	while (str[i] && space_or_element(str[i]))
		i++;
	data->ciel_r = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == ','))
		i++;
	data->ciel_g = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == ','))
		i++;
	data->ciel_b = ft_atoi((const char *)str + i);
	return (1);
}

char	*get_name_texture(t_arg *data, char *new_text, char *needle)
{
	int		i;
	int		len;
	char	*text;

	i = 0;
	text = NULL;
	while (new_text[i] && (new_text[i] == ' ' || new_text[i] == '\t'))
		i++;
	i += ft_strlen(needle);
	while (new_text[i] && new_text[i] == ' ')
		i++;
	text = ft_strdup(&new_text[i]);
	len = ft_strlen(&new_text[i]);
	if (len <= 4 || text[len - 1] != 'm'
		|| text[len - 2] != 'p' || text[len - 3] != 'x'
		|| text[len - 4] != '.')
	{
		free(text);
		quit_parsing(data, "Check name of texture.\n", 0, 0);
		return (NULL);
	}
	return (text);
}
