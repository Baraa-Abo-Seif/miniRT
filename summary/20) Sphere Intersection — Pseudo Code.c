//! Sphere Intersection — Pseudo Code

/*

Objective

Determine whether a ray intersects a sphere and fill the hit record with the closest valid intersection.

Inputs
Ray
    Origin
    Direction


Sphere
    Center
    Radius


Hit Record
Algorithm
Step 1

Compute the vector from the sphere center to the ray origin.

oc = ray.origin - sphere.center
Step 2

Compute the quadratic coefficients.

a = dot(ray.direction, ray.direction)


b = 2 * dot(oc, ray.direction)


c = dot(oc, oc) - radius²
Step 3

Compute the discriminant.

discriminant = b² - 4ac
Step 4

If:

discriminant < 0

Return:

false

No intersection exists.

Step 5

Compute the square root.

sqrt_discriminant = sqrt(discriminant)
Step 6

Compute both quadratic roots.

t1 = (-b - sqrt_discriminant) / (2a)


t2 = (-b + sqrt_discriminant) / (2a)
Step 7

Choose the nearest valid root.

Rules:

Use the smallest positive root.


If the first root is invalid,
use the second one.


If both are invalid,
return false.

Later we will refine the definition of valid using t_min and t_max.

Step 8

Compute the intersection point.

point = ray_at(ray, t)
Step 9

Compute the outward normal.

outward_normal =
(point - sphere.center) / radius
Step 10

Configure the hit record.

record.t = t


record.point = point


record.object = sphere


hit_record_set_face_normal(
    record,
    ray,
    outward_normal)
Step 11

Return

true
Complete Flow
Ray
 │
 ▼
Compute oc
 │
 ▼
Compute a, b, c
 │
 ▼
Compute Δ
 │
 ▼
Δ < 0 ?
 │
 ├── Yes → No Hit
 │
 └── No
      │
      ▼
Compute Roots
      │
      ▼
Choose Valid Root
      │
      ▼
Compute Hit Point
      │
      ▼
Compute Outward Normal
      │
      ▼
Fill Hit Record
      │
      ▼
Return true



*/
