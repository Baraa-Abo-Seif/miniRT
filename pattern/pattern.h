#ifndef PATTERN_H
#define PATTERN_H

#include "../math/math.h"

typedef enum e_pattern_type
{
    PATTERN_NONE,
    PATTERN_CHECKER
}   t_pattern_type;


typedef struct s_pattern
{
    t_pattern_type type;
    t_color        color_a;
    t_color        color_b;
}   t_pattern;



// t_color	pattern_at(t_pattern *pattern, t_point point);
// t_color	checker_at(t_pattern *pattern, t_point point);
// t_color	sphere_checker_at(t_pattern *pattern, t_point point);


t_color sphere_checker_at(t_pattern *pattern, t_point point);
t_color cylinder_checker_at(t_pattern *pattern, t_point point);
t_color plane_checker_at(t_pattern *pattern, t_point point);
t_color triangle_checker_at(t_pattern *pattern, t_point point);
t_color paraboloid_checker_at(t_pattern *pattern, t_point point);
t_color pattern_at(t_pattern *pattern, t_point point);


#endif