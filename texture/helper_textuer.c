#include "texture.h"

t_uv	uv_range(t_uv uv, int only_v)
{
	if (uv.u < 0.0 && !only_v)
		uv.u = 0.0;
	if (uv.u > 1.0 && !only_v)
		uv.u = 1.0;
	if (uv.v < 0.0)
		uv.v = 0.0;
	if (uv.v > 1.0)
		uv.v = 1.0;
	return (uv);
}
