#ifndef CAMERA_H
#define CAMERA_H


#include "../../math/vector/vector.h"
#include "../../math/point/point.h"


typedef struct s_camera
{
    t_point position;
    t_vec   forward;
    double  fov;

    t_vec   right;
    t_vec   up;
    
    double  viewport_width;
    double  viewport_height;
    double  pixel_size;
}   t_camera;





#endif