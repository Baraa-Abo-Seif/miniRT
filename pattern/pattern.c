#include "pattern.h"
#include <math.h>

#define SPHERE_CHECKER_SIZE 8
#define CYL_U_SIZE 8
#define CYL_V_SIZE 2
#define PLANE_SCALE 0.5
#define TRI_SCALE 2
#define PARA_SCALE 2

static double   clamp_unit(double value)
{
    if (value < -1.0)
        return (-1.0);
    if (value > 1.0)
        return (1.0);
    return (value);
}

t_color sphere_checker_at(t_pattern *pattern, t_point point)
{
    double  radius;
    double  latitude;
    double  longitude;
    long    latitude_cell;
    long    longitude_cell;

    radius = sqrt(point.x * point.x + point.y * point.y + point.z * point.z);
    if (radius < EPSILON)
        return (pattern->color_a);

    latitude = (acos(clamp_unit(point.y / radius)) / M_PI) * SPHERE_CHECKER_SIZE;
    longitude = ((atan2(point.x, point.z) + M_PI) / (2.0 * M_PI)) * (2 * SPHERE_CHECKER_SIZE);

    latitude_cell = (long)floor(latitude);
    longitude_cell = (long)floor(longitude);

    if (latitude_cell >= SPHERE_CHECKER_SIZE)
        latitude_cell = SPHERE_CHECKER_SIZE - 1;
    if (longitude_cell >= 2 * SPHERE_CHECKER_SIZE)
        longitude_cell = (2 * SPHERE_CHECKER_SIZE) - 1;

    if ((latitude_cell + longitude_cell) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color cylinder_checker_at(t_pattern *pattern, t_point point)
{
    double  u;
    double  v;
    long    u_cell;
    long    v_cell;

    // إذا كانت النقطة على الغطاء العلوي أو السفلي للأسطوانة (السطح المسطح)
    // نفترض أن نصف قطر الأسطوانة محصور، أو أن النقطة محاذية لطرف الارتفاع
    // يمكن الاعتماد على x و z للمربعات المستوية المسطحة
    if (fabs(point.y) >= (5.0 / 2.0) - EPSILON) // 5.0 هي قيمة height الأسطوانة
    {
        u_cell = (long)floor(point.x * 2.0);
        v_cell = (long)floor(point.z * 2.0);
    }
    else
    {
        // جسم الأسطوانة الجانبي
        u = (atan2(point.x, point.z) + M_PI) / (2.0 * M_PI);
        v = point.y;

        u_cell = (long)floor(u * CYL_U_SIZE);
        v_cell = (long)floor(v * CYL_V_SIZE);

        if (u_cell >= CYL_U_SIZE)
            u_cell = CYL_U_SIZE - 1;
    }

    if ((u_cell + v_cell) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}



t_color plane_checker_at(t_pattern *pattern, t_point point)
{
    long    cell_x;
    long    cell_z;

    cell_x = (long)floor(point.x * PLANE_SCALE);
    cell_z = (long)floor(point.z * PLANE_SCALE);

    if ((cell_x + cell_z) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color triangle_checker_at(t_pattern *pattern, t_point point)
{
    long    cell_x;
    long    cell_y;

    cell_x = (long)floor(point.x * TRI_SCALE);
    cell_y = (long)floor(point.y * TRI_SCALE);

    if ((cell_x + cell_y) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color paraboloid_checker_at(t_pattern *pattern, t_point point)
{
    double  u;
    double  v;
    long    u_cell;
    long    v_cell;

    u = (atan2(point.x, point.z) + M_PI) / (2.0 * M_PI);
    v = point.y;

    u_cell = (long)floor(u * 8.0);
    v_cell = (long)floor(v * PARA_SCALE);

    if ((u_cell + v_cell) % 2 == 0)
        return (pattern->color_a);
    return (pattern->color_b);
}

t_color pattern_at(t_pattern *pattern, t_point point)
{
    if (pattern->type == PATTERN_CHECKER)
        return (plane_checker_at(pattern, point));
    return (pattern->color_a);
}

