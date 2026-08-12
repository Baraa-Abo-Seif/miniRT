
#include "camera.h"

void		camera_compute_viewport(
t_camera *camera,int image_width,int image_height)
{
    double fov_rad ;
    double aspect_ratio;
    t_point viewport_center;

    if (!camera)
        return;

    aspect_ratio = (double)image_width / (double)image_height;
    fov_rad = camera->fov * (M_PI / 180.0);

    camera->viewport_height = 2.0 * tan(fov_rad / 2.0);
    camera->viewport_width = camera->viewport_height * aspect_ratio;
    viewport_center = point_add_vec(camera->position, camera->forward);


    camera->viewport_upper_left = point_sub_vec(
            viewport_center,
            vec_scale(camera->right, camera->viewport_width / 2.0));

    camera->viewport_upper_left = point_add_vec(
        camera->viewport_upper_left,
        vec_scale(camera->up, camera->viewport_height / 2.0));

}
