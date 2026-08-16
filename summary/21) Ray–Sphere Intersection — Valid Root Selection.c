//! Ray–Sphere Intersection — Valid Root Selection

/*
Objective

Determine whether an intersection point is valid before accepting it as the final hit.

Although solving the quadratic equation produces mathematical solutions, not every solution represents a visible intersection in ray tracing.

Why are t_min and t_max needed?

The quadratic equation may return one or two values of t.

However, a valid intersection must satisfy additional constraints depending on the ray tracing context.

To control this, every intersection test receives an interval:

t_min < t < t_max

Only values inside this interval are considered valid.

t_min
Purpose

Defines the minimum acceptable distance along the ray.

It prevents invalid intersections that occur:

Behind the ray origin
At the ray origin itself
Extremely close to the surface due to floating-point precision
Why is this important?

Without t_min, a ray could intersect the surface it was generated from.

This produces rendering artifacts such as:

Self Intersection
Shadow Acne
Reflection Errors
Refraction Errors
Typical Value
t_min = 0.001

A small positive epsilon is usually sufficient.

t_max
Purpose

Defines the maximum acceptable distance along the ray.

It limits how far an intersection test is allowed to search.

Why is this important?

When tracing a scene, the renderer is only interested in the closest visible object.

If a closer object has already been found, any intersection farther away should be ignored.

Valid Root Condition

A quadratic root is accepted only if:

t_min < t < t_max

Otherwise, the root is discarded.

Root Selection Strategy
Compute both roots.
Test the smaller root first.
If it is outside the valid interval, test the second root.
If both roots are invalid, the ray does not hit the object.
Advantages

Using t_min and t_max provides:

Stable numerical behavior
Correct visibility
Prevention of self-intersections
Efficient closest-hit detection
A unified interface for all geometric objects
Standard Intersection Prototype

Most ray tracers expose intersection functions using the following interface:

bool object_hit(
    object,
    ray,
    t_min,
    t_max,
    hit_record);

Every geometric primitive (Sphere, Plane, Cylinder, etc.) follows the same pattern.

Summary
Quadratic Equation
        │
        ▼
Compute Roots
        │
        ▼
Check t_min
        │
        ▼
Check t_max
        │
        ▼
Accept Valid Root
        │
        ▼
Fill Hit Record
Key Concepts
t_min prevents invalid intersections near or behind the ray origin.
t_max limits the search distance and allows selecting the nearest visible object.
A root is valid only if it lies inside the interval:
t_min < t < t_max
Every intersection routine in the ray tracer should follow the same validation rule to ensure consistent behavior throughout the rendering pipeline.
*/
