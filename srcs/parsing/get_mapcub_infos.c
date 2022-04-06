/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mapcub_infos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 17:15:51 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/06 14:59:23 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_floor(t_arg *data, char *str)
{
	int	i;

	i = 0;
	check_floor_sky(data, str);
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
	check_floor_sky(data, str);
	if (data->ciel_r != 0 || data->ciel_g != 0 || data->ciel_b != 0)
		return (quit_parsing(data,
				"You've duplicated info about the sky.\n", 0, 0));
	while (str[i] && space_or_element(str[i]))
		i++;
	data->ciel_r = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->ciel_g = ft_atoi((const char *)str + i);
	while (ft_isdigit(str[i]))
		i++;
	while (str[i] && (str[i] == ' ' || str[i] == ','))
		i++;
	data->ciel_b = ft_atoi((const char *)str + i);
	return (1);
}

char	*get_texture(t_arg *data, char *str, char a, char b)
{
	int		i;
	int		len;
	char	*text;

	i = 0;
	data->tmp = 0;
	text = NULL;
	while (str[i] && (str[i] == ' ' || str[i] == a || str[i] == b))
	{
		if (str[i] == a || (str[i] == b && b != ' '))
			data->tmp++;
		i++;
	}
	if ((b != ' ' && (i < 2 || data->tmp > 2))
		|| (b == ' ' && data->tmp > 1))
		quit_parsing(data,
			"Something's wrong in one of the texture.\n", 0, 0);
	text = ft_strdup(&str[i]);
	len = ft_strlen(text);
	if (len <= 4 || ft_strchr(text, ' ') || text[len - 1] != 'm'
		|| text[len - 2] != 'p' || text[len - 3] != 'x'
		|| text[len - 4] != '.')
		quit_parsing(data, "Check name of texture.\n", 0, 0);
	return (text);
}

int	if_texture(t_arg *data, char *str)
{
	const t_text	which[] = {
	{"NO ", get_texture, &data->north}, {"SO ", get_texture, &data->south},
	{"EA ", get_texture, &data->east}, {"WE ", get_texture, &data->west},
	{"S ", get_texture, &data->sprite}, {"", NULL, NULL}
	};
	int				i;

	i = 0;
	while (which[i].f)
	{
		if (ft_int_strstr(str, (char *)which[i].conv))
		{
			if (*which[i].ptr != NULL)
				return (quit_parsing(data, "Some info are duplicated.\n", 0, 0));
			*which[i].ptr = which[i].f(data, str,
					which[i].conv[0], which[i].conv[1]);
			break ;
		}
		++i;
	}
	return (1);
}
