
#include <stdio.h>
#include "../../pattern/pattern.h"

static void	print_color(const char *name, t_color color)
{
	printf("%s = (%f, %f, %f)\n",
		name, color.r, color.g, color.b);
}

int	main(void)
{
	t_pattern	pattern;
	t_point		point;
	t_color		result;

	pattern.type = PATTERN_CHECKER;
	pattern.color_a = (t_color){1.0, 0.0, 0.0};
	pattern.color_b = (t_color){0.0, 1.0, 0.0};

	point = (t_point){0.2, 0.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("0.2", result);

	point = (t_point){0.9, 0.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("0.9", result);

	point = (t_point){1.0, 0.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("1.0", result);

	point = (t_point){1.1, 0.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("1.1", result);

	point = (t_point){1.2, 1.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("1.2,1.2,0.2", result);

	point = (t_point){1.2, 1.2, 1.2};
	result = pattern_at(&pattern, point);
	print_color("1.2,1.2,1.2", result);

	point = (t_point){-0.2, 0.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("-0.2", result);

	point = (t_point){-1.0, 0.2, 0.2};
	result = pattern_at(&pattern, point);
	print_color("-1.0", result);

	return (0);
}
