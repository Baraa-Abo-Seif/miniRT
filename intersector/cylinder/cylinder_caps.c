/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_caps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babo-sai <babo-sai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:54:09 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/26 18:58:36 by babo-sai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder_hit.h"

bool	find_cap_root(t_cap_context *ctx,t_point cap_center,
	t_vec cap_normal,double *root)
{
	double	denom;

	denom = vec_dot(ctx->ray.direction,cap_normal);
	if (fabs(denom) < EPSILON)
		return (false);
	*root = vec_dot(point_sub_point(cap_center,ctx->ray.origin),
	cap_normal) / denom;
	if (*root <= ctx->interval.min || *root >= ctx->interval.max)
		return (false);
	return (true);
}

bool	check_single_cap(t_cylinder *cylinder,int side,t_cap_context *ctx)
{
	t_point	cap_center;
	t_vec	cap_normal;
	double	root;
	t_point	hit_point;
	t_vec	offset;

	cap_normal = vec_normalize(vec_scale(cylinder->axis, (double)side));
	cap_center = point_add_vec(cylinder->center,
		vec_scale(cylinder->axis,side * (cylinder->height / 2.0)));
	if (!find_cap_root(ctx,cap_center,cap_normal,&root))
		return (false);
	hit_point = ray_at(ctx->ray,root);
	offset = point_sub_point(hit_point,cap_center);
	if (vec_dot(offset, offset) > (cylinder->radius * cylinder->radius))
		return (false);
	ctx->record->t = root;
	ctx->record->point = hit_point;
	hit_record_set_face_normal(ctx->record, ctx->ray, cap_normal);
	ctx->record->object = cylinder;
	return (true);
}
bool	check_caps(t_cylinder *cylinder, t_cap_context *ctx)
{
	int		side;
	bool	hit;

	side = -1;
	hit = false;
	while (side <= 1)
	{
		if (check_single_cap(cylinder, side, ctx))
		{
			hit = true;
			ctx->interval.max = ctx->record->t;
		}
		side += 2;
	}
	return (hit);
}

//! steps:
/*
	Cap data:
	1) Use side s in {-1, +1} to select a cap.
	2) Build the cap normal and center:
		cap_normal = normalize(s*a),
		cap_center = C + s*(height/2)*a.

	Cap intersection:
	4) A cap is the plane (P - cap_center) . cap_normal = 0.
	5) Substitute P(t) = O + t*d and compute:
		denom = d . cap_normal.
		Reject when |denom| < EPSILON.
	6) Solve for the ray parameter:
		t = ((cap_center - O) . cap_normal) / denom.
	7) Reject when t <= interval.min or t >= interval.max.
	8) Compute P = O + t*d and offset = P - cap_center.
	9) Accept only when the point is inside the disk:
		offset . offset <= r^2.
	10) Store the hit and orient cap_normal against the ray.

	Both caps:
	11) Test s = -1 and s = +1.
	12) After each valid cap hit, set interval.max = t so the next hit must be closer.
*/



