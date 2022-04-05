/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_fusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 16:00:02 by ldermign          #+#    #+#             */
/*   Updated: 2021/04/25 14:11:20 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fusion_conv_strflag(char *str, int nbr, t_flag_len *flag)
{
	int	len_str;

	len_str = ft_strlen(str);
	if ((flag->conv_c == 1 && flag->padded_zero == 0 && flag->precision == -1)
		|| flag->conv_per == 1)
		fusion_c(nbr, flag);
	else if (flag->conv_s == 1 && flag->padded_zero == 0)
		prep_fus(str, flag->nbr_width, flag->nbr_precision, flag);
	else if (flag->conv_p == 1)
		fusion_p(str, flag->nbr_width, len_str, flag);
	else if (flag->conv_d_i == 1 || flag->conv_u == 1 || flag->conv_x == 1)
	{
		if (flag->nbr_precision < 0)
			flag->precision *= -1;
		fusion_d_i_u_x(str, nbr, flag);
	}
}
