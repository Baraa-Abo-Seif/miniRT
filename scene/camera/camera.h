#ifndef CAMERA_H
#define CAMERA_H


#include "../../math/vector/vector.h"
#include "../../math/point/point.h"
#include "../../math/ray/ray.h"
#include "../../Libft/libft.h"
#include <math.h>

#ifndef M_PI
# define M_PI 3.14159265358979323846
#endif


typedef struct s_camera
{
    t_point position;              // Camera position in world space
    t_vec   forward;               // Viewing direction (normalized)
    double  fov;                   // Field of view in degrees

    t_vec   right;                 // Camera local X axis
    t_vec   up;                    // Camera local Y axis

    double  viewport_width;        // Viewport width
    double  viewport_height;       // Viewport height

    t_point viewport_upper_left;   // Top-left corner of the viewport

    t_vec   pixel_delta_x;         // Horizontal distance between pixels
    t_vec   pixel_delta_y;         // Vertical distance between pixels

} t_camera;


t_camera   *camera_create(void);
void        camera_destroy(t_camera *camera);

int         camera_init(t_camera *camera,int image_width,int image_height);


void		camera_build_basis(t_camera *camera);


void		camera_compute_viewport(t_camera *camera,int image_width,int image_height);


void	camera_compute_pixel_delta(t_camera *camera,int image_width,int image_height);

t_ray	camera_ray_through_pixel(t_camera *camera, int j, int i);

#endif