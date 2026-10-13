#include <stdio.h>
#include <math.h>
#include "../../pattern/pattern.h"

static int	color_equal(t_color a, t_color b)
{
	double	eps;

	eps = 1e-6;
	return (fabs(a.r - b.r) < eps
		&& fabs(a.g - b.g) < eps
		&& fabs(a.b - b.b) < eps);
}

static void	test_case(const char *name, t_pattern *pattern,
				t_point point, t_color expected)
{
	t_color	result;

	result = plane_checker_at(pattern, point, (t_vec){0.0, 1.0, 0.0});
	if (color_equal(result, expected))
		printf("[PASS] %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		printf("       Expected: (%f, %f, %f)\n",
			expected.r, expected.g, expected.b);
		printf("       Got:      (%f, %f, %f)\n",
			result.r, result.g, result.b);
	}
}
static void	test_sphere_case(const char *name, t_pattern *pattern,
				t_point point, t_color expected)
{
	t_color	result;

	result = sphere_checker_at(pattern, point);
	if (color_equal(result, expected))
		printf("[PASS] %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		printf("       Expected: (%f, %f, %f)\n",
			expected.r, expected.g, expected.b);
		printf("       Got:      (%f, %f, %f)\n",
			result.r, result.g, result.b);
	}
}
static void	test_cylinder_case(const char *name, t_pattern *pattern,
				t_point point, t_color expected)
{
	t_color	result;

	result = cylinder_checker_at(pattern, point, 5.0);
	if (color_equal(result, expected))
		printf("[PASS] %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		printf("       Expected: (%f, %f, %f)\n",
			expected.r, expected.g, expected.b);
		printf("       Got:      (%f, %f, %f)\n",
			result.r, result.g, result.b);
	}
}
static void	test_triangle_case(const char *name, t_pattern *pattern,
				t_point point, t_color expected)
{
	t_color	result;

	result = triangle_checker_at(pattern, point);
	if (color_equal(result, expected))
		printf("[PASS] %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		printf("       Expected: (%f, %f, %f)\n",
			expected.r, expected.g, expected.b);
		printf("       Got:      (%f, %f, %f)\n",
			result.r, result.g, result.b);
	}
}
static void	test_paraboloid_case(const char *name, t_pattern *pattern,
				t_point point, t_color expected)
{
	t_color	result;

	result = paraboloid_checker_at(pattern, point);
	if (color_equal(result, expected))
		printf("[PASS] %s\n", name);
	else
	{
		printf("[FAIL] %s\n", name);
		printf("       Expected: (%f, %f, %f)\n",
			expected.r, expected.g, expected.b);
		printf("       Got:      (%f, %f, %f)\n",
			result.r, result.g, result.b);
	}
}


int	main(void)
{
	t_pattern	pattern;

	pattern.type = PATTERN_CHECKER;
	pattern.color_a = (t_color){1.0, 0.0, 0.0};
	pattern.color_b = (t_color){0.0, 0.0, 1.0};

	printf("=== Plane Checker Test ===\n");

	test_case("origin",
		&pattern,
		(t_point){0.0, 0.0, 0.0},
		pattern.color_a);

	test_case("inside first cell",
		&pattern,
		(t_point){1.0, 0.0, 1.0},
		pattern.color_a);

	test_case("cross X boundary",
		&pattern,
		(t_point){2.0, 0.0, 1.0},
		pattern.color_b);

	test_case("inside second X cell",
		&pattern,
		(t_point){3.0, 0.0, 1.0},
		pattern.color_b);

	test_case("cross Z boundary",
		&pattern,
		(t_point){1.0, 0.0, 2.0},
		pattern.color_b);

	test_case("both X and Z crossed",
		&pattern,
		(t_point){2.0, 0.0, 2.0},
		pattern.color_a);

	printf("\n=== Sphere Checker Test ===\n");

	test_sphere_case("sphere +Y",
		&pattern,
		(t_point){0.0, 1.0, 0.0},
		pattern.color_a);

	test_sphere_case("sphere -Y",
		&pattern,
		(t_point){0.0, -1.0, 0.0},
		pattern.color_b);

	test_sphere_case("sphere +Z",
		&pattern,
		(t_point){0.0, 0.0, 1.0},
		pattern.color_a);

	test_sphere_case("sphere -Z",
		&pattern,
		(t_point){0.0, 0.0, -1.0},
		pattern.color_b);

	test_sphere_case("sphere +X",
		&pattern,
		(t_point){1.0, 0.0, 0.0},
		pattern.color_a);

	test_sphere_case("sphere -X",
		&pattern,
		(t_point){-1.0, 0.0, 0.0},
		pattern.color_a);

	test_sphere_case("sphere origin",
		&pattern,
		(t_point){0.0, 0.0, 0.0},
		pattern.color_a);

	test_sphere_case("sphere upper interior",
		&pattern,
		(t_point){0.3, 0.8, 0.4},
		pattern.color_a);

	test_sphere_case("sphere lower interior",
		&pattern,
		(t_point){-0.3, -0.8, 0.4},
		pattern.color_a);

	test_sphere_case("sphere diagonal",
		&pattern,
		(t_point){1.0, 1.0, 1.0},
		pattern.color_a);

	test_sphere_case("sphere interior B",
		&pattern,
		(t_point){0.3, 0.5, 0.4},
		pattern.color_b);

	test_sphere_case("sphere interior B negative",
		&pattern,
		(t_point){-0.3, -0.5, 0.4},
		pattern.color_a);


		printf("\n=== Cylinder Checker Test ===\n");

	test_cylinder_case("cylinder side +Z upper",
		&pattern,
		(t_point){0.0, 0.5, 1.0},
		pattern.color_b);

	test_cylinder_case("cylinder side -Z upper",
		&pattern,
		(t_point){0.0, 0.5, -1.0},
		pattern.color_a);

	test_cylinder_case("cylinder side +Z lower",
		&pattern,
		(t_point){0.0, -0.5, 1.0},
		pattern.color_b);

	test_cylinder_case("cylinder side +X upper",
		&pattern,
		(t_point){1.0, 1.5, 0.0},
		pattern.color_b);

	test_cylinder_case("cylinder top cap origin cell",
		&pattern,
		(t_point){0.25, 2.5, 0.25},
		pattern.color_a);

	test_cylinder_case("cylinder top cap cross X",
		&pattern,
		(t_point){0.75, 2.5, 0.25},
		pattern.color_b);

	test_cylinder_case("cylinder top cap cross Z",
		&pattern,
		(t_point){0.25, 2.5, 0.75},
		pattern.color_b);

	test_cylinder_case("cylinder top cap cross XZ",
		&pattern,
		(t_point){0.75, 2.5, 0.75},
		pattern.color_a);

	test_cylinder_case("cylinder bottom cap origin cell",
		&pattern,
		(t_point){0.25, -2.5, 0.25},
		pattern.color_a);

	test_cylinder_case("cylinder bottom cap cross XZ",
		&pattern,
		(t_point){0.75, -2.5, 0.75},
		pattern.color_a);

	test_cylinder_case("cylinder top cap epsilon inside",
	&pattern,
	(t_point){0.25, 2.4999995, 0.25},
	pattern.color_a);

	test_cylinder_case("cylinder side epsilon outside",
		&pattern,
		(t_point){0.25, 2.499998, 0.25},
		pattern.color_b);

	printf("\n=== Triangle Checker Test ===\n");

	test_triangle_case("triangle origin",
		&pattern,
		(t_point){0.0, 0.0, 0.0},
		pattern.color_a);

	test_triangle_case("triangle inside first cell",
		&pattern,
		(t_point){0.25, 0.25, 0.0},
		pattern.color_a);

	test_triangle_case("triangle cross X boundary",
		&pattern,
		(t_point){0.5, 0.25, 0.0},
		pattern.color_b);

	test_triangle_case("triangle cross Y boundary",
		&pattern,
		(t_point){0.25, 0.5, 0.0},
		pattern.color_b);

	test_triangle_case("triangle cross X and Y",
		&pattern,
		(t_point){0.5, 0.5, 0.0},
		pattern.color_a);

	test_triangle_case("triangle negative coordinates",
		&pattern,
		(t_point){-0.25, -0.25, 0.0},
		pattern.color_a);
test_triangle_case("triangle just below X boundary",
	&pattern,
	(t_point){0.499999, 0.25, 0.0},
	pattern.color_a);

test_triangle_case("triangle on X boundary",
	&pattern,
	(t_point){0.5, 0.25, 0.0},
	pattern.color_b);

test_triangle_case("triangle just below Y boundary",
	&pattern,
	(t_point){0.25, 0.499999, 0.0},
	pattern.color_a);

test_triangle_case("triangle on Y boundary",
	&pattern,
	(t_point){0.25, 0.5, 0.0},
	pattern.color_b);

	printf("\n=== Paraboloid Checker Test ===\n");

	test_paraboloid_case("paraboloid origin",
		&pattern,
		(t_point){0.0, 0.0, 0.0},
		pattern.color_a);

	test_paraboloid_case("paraboloid +Z",
		&pattern,
		(t_point){0.0, 0.0, 1.0},
		pattern.color_a);

	test_paraboloid_case("paraboloid -Z",
		&pattern,
		(t_point){0.0, 0.0, -1.0},
		pattern.color_a);

	test_paraboloid_case("paraboloid +X",
		&pattern,
		(t_point){1.0, 0.0, 0.0},
		pattern.color_a);

	test_paraboloid_case("paraboloid -X",
		&pattern,
		(t_point){-1.0, 0.0, 0.0},
		pattern.color_a);

	test_paraboloid_case("paraboloid upper",
		&pattern,
		(t_point){0.0, 0.5, 1.0},
		pattern.color_b);

	test_paraboloid_case("paraboloid just below Y boundary",
	&pattern,
	(t_point){0.0, 0.499999, 1.0},
	pattern.color_a);

test_paraboloid_case("paraboloid on Y boundary",
	&pattern,
	(t_point){0.0, 0.5, 1.0},
	pattern.color_b);



test_paraboloid_case("paraboloid just below Y boundary",
	&pattern,
	(t_point){0.0, 0.499999, 1.0},
	pattern.color_a);

test_paraboloid_case("paraboloid on Y boundary",
	&pattern,
	(t_point){0.0, 0.5, 1.0},
	pattern.color_b);

test_paraboloid_case("paraboloid just before +X angle",
	&pattern,
	(t_point){0.999999, 0.0, 0.000001},
	pattern.color_b);

test_paraboloid_case("paraboloid +X angle",
	&pattern,
	(t_point){1.0, 0.0, 0.0},
	pattern.color_a);



	return (0);
}








