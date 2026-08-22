//! Plane Intersection — Mathematical Summary
/*

## 1. Plane Representation

Unlike a sphere, a plane is an infinite flat surface.

A plane is completely defined by:

* A point on the plane (`P₀`)
* A normal vector (`N`)

Where:

* `P₀` determines the plane's position.
* `N` determines the plane's orientation.

The normal vector does **not** represent a distance or length.
It only describes the direction perpendicular to the surface.

---

# 2. Vector Inside the Plane

Let:

* `P₀` = a known point on the plane.
* `P` = an unknown point.

The vector connecting them is:

```text
P - P₀
```

If the point `P` lies on the plane, then this vector lies completely inside the plane.

---

# 3. Fundamental Plane Property

Every vector lying on the plane is perpendicular to the plane's normal.

Therefore:

```text
(P - P₀) · N = 0
```

This is the mathematical equation of a plane.

---

# 4. Ray Equation

Every point on a ray is defined as:

```text
P = O + tD
```

Where:

* `O` = ray origin
* `D` = ray direction
* `t` = distance along the ray

---

# 5. Substituting the Ray into the Plane

Replace `P` with the ray equation:

```text
(O + tD - P₀) · N = 0
```

Expand the expression:

```text
((O - P₀) + tD) · N = 0
```

Using the distributive property of the dot product:

```text
(O - P₀) · N + t(D · N) = 0
```

Solve for `t`:

```text
t(D · N) = -(O - P₀) · N
```

Finally:

```text
t = ((P₀ - O) · N) / (D · N)
```

This is the final ray-plane intersection equation.

---

# 6. Meaning of the Denominator

The denominator is:

```text
D · N
```

Its geometric meaning is extremely important.

If:

```text
D · N = 0
```

then the ray direction is perpendicular to the plane's normal.

This means:

* The ray is parallel to the plane.
* No intersection occurs.

Therefore, the denominator must always be checked before computing `t`.

---

# 7. Why We Check the Denominator First

There are two reasons.

### Mathematical reason

A parallel ray never intersects the plane.

### Programming reason

If:

```text
D · N = 0
```

then the intersection formula becomes:

```text
t = (...) / 0
```

which causes division by zero.

The algorithm must immediately return **No Hit**.

---

# 8. Geometric Interpretation

The complete geometric process is:

```text
Plane

↓

Known Point (P₀)

+

Normal (N)

↓

Ray

↓

Find t

↓

Compute Intersection Point

↓

Generate Hit Record
```

---

# Key Concepts

* A plane is defined by one point and one normal.
* The normal describes orientation, not distance.
* Any vector lying on the plane is perpendicular to the normal.
* The plane equation is derived from the dot product.
* A ray is substituted into the plane equation.
* Solving the equation gives the intersection distance `t`.
* The denominator (`D · N`) determines whether an intersection is possible.
* Parallel rays must be rejected before computing `t`.

*/
//! **************************************************************************
//!                           Plane Intersection Mathematics
//! **************************************************************************

# /*

# STEP 1 — PLANE CONCEPT

## Concept

A plane is the simplest geometric primitive used in ray tracing.

Unlike spheres or cylinders, a plane has:

```
• No radius
• No curvature
• No finite dimensions
```

Instead, a plane is an infinitely large flat surface extending forever in
every direction.

Although infinite, a plane can be completely described using only two pieces
of information.

---

## Mathematical Definition

A plane is defined by

```
C = A Point on the Plane
```

and

```
N = Plane Normal (Normalized)
```

where

```
C represents any point lying on the plane.

N represents a vector perpendicular to the plane.
```

Since every plane has infinitely many points,

the point C is only used as a reference.

---

## Visual Representation

```
                N
                ↑
                │
                │
```

--------------------C-------------------- Plane
P

Every point P located on the plane satisfies one important geometric rule.

The vector

```
P - C
```

always lies inside the plane.

Since

```
N
```

is perpendicular to the plane,

the vector

```
P - C
```

must always be perpendicular to

```
N.
```

---

## Fundamental Property

Two perpendicular vectors always satisfy

```
a · b = 0
```

Therefore

```
(P - C) · N = 0
```

This is the fundamental mathematical equation of every plane.

---

## Why?

The dot product measures how much one vector points toward another.

Since

```
(P - C)
```

contains absolutely no component in the direction of the normal,

its projection onto the normal is zero.

That is exactly what the dot product computes.

---

## Important Notes

• N MUST always be normalized.

• The plane has infinite size.

• Every point satisfying

```
  (P - C) · N = 0
```

belongs to the plane.

---

## Key Idea

"A plane is the set of all points whose displacement from a reference point
is perpendicular to the plane normal."

===============================================================================

===============================================================================
STEP 2 — Introducing the Ray Equation
=====================================

## Concept

The plane equation describes every point belonging to the plane.

However,

during ray tracing,

we are interested only in the points that lie on the ray.

Therefore,

the unknown point P is replaced by the ray equation.

---

## Ray Equation

Every ray is represented as

```
P(t) = O + tD
```

where

```
O = Ray Origin

D = Ray Direction (Normalized)

t = Distance traveled along the ray
```

---

## Substitution

The plane equation is

```
(P - C) · N = 0
```

Replacing

```
P
```

with

```
O + tD
```

gives

```
((O + tD) - C) · N = 0
```

Now,

instead of solving for an unknown point,

we only need to solve for

```
t.
```

---

## Introducing a Constant Vector

Notice that

```
O - C
```

never changes during the intersection.

To simplify the notation,

define

```
w = O - C
```

The equation becomes

```
(w + tD) · N = 0
```

---

## Why?

Computing

```
O - C
```

once is cheaper than recomputing it several times.

It also makes the derivation much easier to read.

---

## Relationship with Sphere

Sphere

```
oc = O - C
```

Plane

```
w = O - C
```

The same idea appears throughout ray tracing.

The vector from the object reference point to the ray origin is always
constant.

===============================================================================

===============================================================================
STEP 3 — Expanding the Dot Product
==================================

## Concept

The current equation is

```
(w + tD) · N = 0
```

To isolate

```
t
```

the dot product must be expanded.

---

## Dot Product Distribution

The dot product satisfies

```
(a + b) · c
```

=

```
a · c
```

+

```
b · c
```

Applying this property gives

```
w · N
```

+

```
t(D · N)
```

=

0

---

## What Happened?

The vector

```
w
```

produces a constant value.

The vector

```
D
```

produces another constant value multiplied by

```
t.
```

No quadratic terms appear.

---

## Why?

Unlike spheres,

the point appears only once inside the plane equation.

There is no squared norm.

Therefore,

the equation remains linear.

---

## Important Observation

At this point,

everything except

```
t
```

is already known.

===============================================================================

===============================================================================
STEP 4 — Solving for t
======================

## Concept

Now that the equation is linear,

isolating

```
t
```

is straightforward.

---

## Current Equation

```
w · N
```

+

```
t(D · N)
```

=

0

---

## Move Constant Term

Subtract

```
w · N
```

from both sides

```
t(D · N)
```

=

-(w · N)

---

## Divide Both Sides

Provided that

```
D · N ≠ 0
```

we obtain

```
             -(w · N)
t = ---------------------------
             D · N
```

---

## Removing the Minus Sign

Since

```
w = O - C
```

then

```
-(O - C)
```

=

(C - O)

Therefore

```
              (C - O) · N
t = -------------------------------
              D · N
```

---

## Final Plane Equation

```
              (C - O) · N
t = -------------------------------
              D · N
```

This is the equation implemented in every ray-plane intersection routine.

---

## Relationship with Sphere

Sphere

```
Quadratic Equation
```

Cylinder

```
Quadratic Equation
```

Plane

```
Linear Equation
```

The plane requires only one division.

No discriminant.

No square roots.

No quadratic solver.

===============================================================================

===============================================================================
STEP 5 — Understanding the Denominator
======================================

## Concept

The denominator

```
D · N
```

has an important geometric meaning.

It measures how much the ray moves toward the plane.

---

## Case 1

If

```
D · N < 0
```

the ray moves toward the front face.

---

## Case 2

If

```
D · N > 0
```

the ray moves toward the back face.

---

## Case 3

If

```
D · N = 0
```

the ray never approaches the plane.

It is perfectly parallel.

---

## Visual Representation

Ray →

------------------------------- Plane

Normal ↑

The ray slides forever.

It never reaches the plane.

---

## Floating Point Issue

Because floating point numbers are imprecise,

we never write

```
D · N == 0
```

Instead

```
fabs(D · N) < EPSILON
```

---

## Why?

Very small denominators produce huge numerical errors.

Treating them as parallel avoids unstable intersections.

===============================================================================

===============================================================================
STEP 6 — Validating the Solution
================================

## Concept

Computing

```
t
```

does not automatically mean that the intersection is useful.

Several invalid solutions exist.

---

## Invalid Cases

Negative t

```
Behind the camera.
```

Small Positive t

```
Self intersection.
```

Very Large t

```
Farther than another object already found.
```

---

## Interval Validation

Instead of checking

```
t > 0
```

MiniRT uses

```
interval.min
```

and

```
interval.max
```

The solution is accepted only if

```
interval.min < t < interval.max
```

---

## Why?

Using an interval allows every primitive to share exactly the same
intersection logic.

It also makes nearest-hit computations extremely simple.

===============================================================================

===============================================================================
STEP 7 — Computing the Hit Point
================================

## Concept

Once

```
t
```

is valid,

the actual intersection point can be computed.

---

## Ray Evaluation

The ray equation is

```
P = O + tD
```

Inside the project,

this is implemented by

```
ray_at(ray, t)
```

---

## Stored Values

The hit record receives

```
record->t

record->point
```

These values are later used by the lighting stage.

---

## Why?

Every lighting computation starts from the exact world-space hit point.

===============================================================================

===============================================================================
STEP 8 — Surface Normal Orientation
===================================

## Concept

A plane has two faces.

The stored normal must always oppose the incoming ray.

Otherwise,

lighting calculations become inconsistent.

---

## Front Face Test

Compute

```
D · N
```

If

```
D · N < 0
```

the ray hits the front face.

Otherwise,

it hits the back face.

---

## Normal Assignment

Front Face

```
normal = N
```

Back Face

```
normal = -N
```

---

## MiniRT Implementation

Rather than repeating this logic inside every primitive,

MiniRT centralizes it inside

```
hit_record_set_face_normal()
```

This function

• Detects front/back faces

• Flips the normal if necessary

• Stores

```
  front_face

  normal
```

---

## Why?

Every primitive shares identical normal orientation rules.

Keeping this code centralized avoids duplication and prevents inconsistent
lighting behavior.

===============================================================================

===============================================================================
STEP 9 — Final Plane Intersection Algorithm
===========================================

## Algorithm

Ray

```
    ↓
```

Compute

```
denominator = D · N

    ↓
```

Parallel ?

```
    ↓
```

Compute

```
t

    ↓
```

Inside Interval ?

```
    ↓
```

Compute Hit Point

```
    ↓
```

Store t

```
    ↓
```

Orient Normal

```
    ↓
```

Store Object Pointer

```
    ↓
```

Return Success

---

## Summary

Plane intersection is the simplest ray-object intersection in ray tracing.

It requires

• One dot product

• One linear equation

• One division

• One interval validation

• One normal orientation

Unlike spheres and cylinders,

it never requires

• Quadratic equations

• Discriminants

• Square roots

• Radius validation

• Height validation

The plane therefore serves as the foundation for understanding more complex
geometric primitives.

===============================================================================




*/
