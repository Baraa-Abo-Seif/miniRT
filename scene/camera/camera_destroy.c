
#include "camera.h"

void        camera_destroy(t_camera *camera)
{
    if (!camera)
        return ;

    free(camera);
}
