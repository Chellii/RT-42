/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ihi <aait-ihi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 19:45:35 by aait-ihi          #+#    #+#             */
/*   Updated: 2019/11/29 16:17:25 by aait-ihi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

const char	*set_color_2(const char *str)
{
	if (!ft_strncmp(str, "{yellow}", 8))
	{
		ft_putstr("\033[33;01m");
		return (str + 8);
	}
	if (!ft_strncmp(str, "{blue}", 6))
	{
		ft_putstr("\033[34;01m");
		return (str + 6);
	}
	if (!ft_strncmp(str, "{pink}", 6))
	{
		ft_putstr("\033[35;01m");
		return (str + 6);
	}
	if (!ft_strncmp(str, "{eoc}", 5))
	{
		ft_putstr("\033[00m");
		return (str + 5);
	}
	return (str);
}

const char	*set_color(const char *str)
{
	if (!ft_strncmp(str, "{cyan}", 6))
	{
		ft_putstr("\033[36;01m");
		return (str + 6);
	}
	if (!ft_strncmp(str, "{grey}", 6))
	{
		ft_putstr("\033[30;01m");
		return (str + 6);
	}
	if (!ft_strncmp(str, "{orange}", 8))
	{
		ft_putstr("\033[31;01m");
		return (str + 8);
	}
	if (!ft_strncmp(str, "{green}", 7))
	{
		ft_putstr("\033[32;01m");
		return (str + 7);
	}
	return (set_color_2(str));
}
