/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejahan <ejahan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 14:49:10 by ldermign          #+#    #+#             */
/*   Updated: 2022/04/13 22:41:00 by ejahan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/cub3d_bonus.h"

int	space_or_element(int c)
{
	return (c == ' ' || c == 'F' || c == 'C');
}

int	ft_is_player(int c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

int	ft_is_texture(char *str)
{
	return (ft_int_strstr(str, "NO ")
		|| ft_int_strstr(str, "SO ") || ft_int_strstr(str, "WE ")
		|| ft_int_strstr(str, "EA "));
}

int	ft_is_noting(char *str)
{
	return (!ft_int_strstr(str, "F ")
		&& !ft_int_strstr(str, "C ") && !ft_int_strstr(str, "NO ")
		&& !ft_int_strstr(str, "SO ") && !ft_int_strstr(str, "WE ")
		&& !ft_int_strstr(str, "EA "));
}

int	ft_is_either(char *str)
{
	return (ft_int_strstr(str, "F ")
		|| ft_int_strstr(str, "C ") || ft_int_strstr(str, "NO ")
		|| ft_int_strstr(str, "SO ") || ft_int_strstr(str, "WE ")
		|| ft_int_strstr(str, "EA "));
}
