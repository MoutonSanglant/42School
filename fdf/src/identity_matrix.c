/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identity_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdefresn <tdefresn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 18:51:47 by tdefresn          #+#    #+#             */
/*   Updated: 2016/02/02 18:52:52 by tdefresn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	identity_matrix4(t_mat4x4 *m)
{
	(*m)[0] = 1.f;
	(*m)[1] = 0.f;
	(*m)[2] = 0.f;
	(*m)[3] = 0.f;
	(*m)[4] = 0.f;
	(*m)[5] = 1.f;
	(*m)[6] = 0.f;
	(*m)[7] = 0.f;
	(*m)[8] = 0.f;
	(*m)[9] = 0.f;
	(*m)[10] = 1.f;
	(*m)[11] = 0.f;
	(*m)[12] = 0.f;
	(*m)[13] = 0.f;
	(*m)[14] = 0.f;
	(*m)[15] = 1.f;
}