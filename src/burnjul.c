/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burnjul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasyush <mmasyush@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 14:10:25 by mmasyush          #+#    #+#             */
/*   Updated: 2019/02/02 14:10:26 by mmasyush         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		burnjul(t_core *core, t_args *args, int x, int y)
{
	args->rx = x / args->zoom + args->xmove;
	args->iy = y / args->zoom + args->ymove;
	args->it = 0;
	while (args->rx * args->rx + args->iy \
			* args->iy < 4 && args->it < core->iteration)
	{
		args->xx = args->rx;
		args->yy = args->iy;
		args->rx = args->xx * args->xx - args->iy * args->iy - args->cx;
		args->iy = 2 * fabs(args->xx * args->yy) - args->cy;
		args->it++;
	}
	if (args->it == core->iteration)
		return (0x000000);
	else
		return (core->color->set[core->color->c] * args->it);
}

void	set_burnjul(t_core *core, t_args *args)
{
	args->cx = 0;
	args->cy = 0;
	args->zoom = 250;
	args->xmove = -2.55;
	args->ymove = -1.45;
	core->color->c = 6;
	core->iteration = 100;
	core->jmouse = 0;
	core->zoomit = 0;
}
