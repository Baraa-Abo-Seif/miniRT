
#ifndef SCENE_H
#define SCENE_H


#include "./object/object.h"
#include "camera/camera.h"
#include "ambient/ambient.h"
#include "light/light.h"



typedef struct s_scene
{
    t_camera    camera;
    t_ambient   ambient;
    t_light     *lights;
    t_object    *objects;
    
}   t_scene;





#endif