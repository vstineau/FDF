/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_is_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vstineau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:52:05 by vstineau          #+#    #+#             */
/*   Updated: 2023/11/28 11:35:09 by vstineau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_is_int(int i)
{
	ft_putnbr(i);
	return (ft_intlen(i));
}
/*
int main()
{
	printf("%d\n",type_is_int(5));
}*/
