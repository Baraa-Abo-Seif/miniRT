#include "hit_record.h"

void	hit_record_set_face_normal(t_hit_record *record,t_ray ray,t_vec outward_normal)
{
    if (!record)
        return;

    record->front_face = (vec_dot(ray.direction, outward_normal) < 0);

    if ( record->front_face)
        record->normal = outward_normal;

    else
        record->normal = vec_scale(outward_normal, -1.0);
}

/*
Purpose

Configure the surface normal after a ray-object intersection so that the normal always points against the incoming ray.

Why is it needed?

A ray can intersect an object from either:

Outside the object
Inside the object

The outward normal always points away from the object's surface, so it is not always the correct normal to use for shading.

This function determines whether the ray hit the front face or the back face, then adjusts the normal accordingly.

Parameters
t_hit_record *record
The intersection record to update.
t_ray ray
The ray that hit the object.
t_vec outward_normal
The geometric normal pointing away from the object's surface.
Updates

The function modifies:

record->front_face
record->normal

It does not return a value (void).

Algorithm
Compute:
dot(ray.direction, outward_normal)
If:
dot < 0

The ray hit the outside of the surface.

front_face = true
normal = outward_normal
Otherwise:
dot > 0

The ray is inside the object.

front_face = false
normal = -outward_normal
Final Result

After calling this function:

record->front_face correctly indicates whether the ray hit the outside or inside of the object.
record->normal always points opposite to the incoming ray direction.

This guarantees consistent behavior for:

Diffuse lighting
Specular lighting
Reflection
Refraction
Shadow calculations
Responsibility

This function does not compute intersections.

Its only responsibility is to orient the surface normal correctly after an intersection has already been found.
*/