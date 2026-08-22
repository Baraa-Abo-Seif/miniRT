//! ************************************************************************** //
//!                           Cylinder Intersection Mathematics
//! ************************************************************************** //

/*
===============================================================================
STEP 1 — CYLINDER CONCEPT
===============================================================================

Concept
-------
A cylinder is not defined by stacked circles.

A cylinder is defined as the set of all points whose perpendicular distance
from the cylinder axis remains constant.

-------------------------------------------------------------------------------
Mathematical Definition
-------------------------------------------------------------------------------

Given:

    C = Cylinder Center
    A = Cylinder Axis (Normalized)
    P = Point on the Cylinder Surface

The vector from the cylinder center to the surface point is

    v = P - C

This vector can be decomposed into two independent components:

    • Parallel Component
    • Perpendicular Component

Only the perpendicular component contributes to the cylinder radius.

-------------------------------------------------------------------------------
Derivation
-------------------------------------------------------------------------------

Projection onto the cylinder axis:

    v_parallel = (v · A) A

Perpendicular component:

    v_perpendicular = v - v_parallel

-------------------------------------------------------------------------------
Surface Condition
-------------------------------------------------------------------------------

A point belongs to the infinite cylinder if

    ||v_perpendicular|| = r

Squaring both sides:

    ||v_perpendicular||² = r²

This is the fundamental equation of an infinite cylinder.

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

Using the squared length avoids the square root operation and transforms the
intersection problem into a quadratic equation, exactly like the sphere.

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• The cylinder is defined by the distance to its axis, NOT by the distance
  to its center.

• The cylinder axis MUST always be normalized.

• At this stage, the cylinder is considered infinite.

• Height limitation will be applied later.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

"A cylinder is the set of all points whose perpendicular distance to the
axis is equal to the radius."

===============================================================================



===============================================================================
STEP 2 — Introducing the Ray Equation
===============================================================================

Concept
-------

The cylinder equation describes any point P on the cylinder surface.

However, during ray tracing we are only interested in points that lie on
the ray.

Therefore, every occurrence of P is replaced by the ray equation.

-------------------------------------------------------------------------------
Ray Equation
-------------------------------------------------------------------------------

A ray is defined as

    P(t) = O + tD

where

    O = Ray Origin
    D = Ray Direction
    t = Distance along the ray

-------------------------------------------------------------------------------
Substitution
-------------------------------------------------------------------------------

The cylinder vector is

    v = P - C

Replacing P with the ray equation gives

    v = (O + tD) - C

-------------------------------------------------------------------------------
Introducing w
-------------------------------------------------------------------------------

To simplify the notation, define

    w = O - C

Therefore,

    v = w + tD

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

The vector (Origin - Center) is constant during the entire intersection
computation.

Computing it once simplifies both the mathematical derivation and the final
implementation.

-------------------------------------------------------------------------------
Relationship with Sphere
-------------------------------------------------------------------------------

Sphere:

    oc = Origin - Center

Cylinder:

    w = Origin - Center

Both represent the constant vector from the object center to the ray origin.

-------------------------------------------------------------------------------
Current Equation
-------------------------------------------------------------------------------

The infinite cylinder equation now becomes

    ||(w + tD)_perpendicular||² = r²

The next step is to extract the perpendicular component of (w + tD).

===============================================================================

===============================================================================
STEP 3 — Computing the Perpendicular Component
===============================================================================

Concept
-------

The cylinder radius is measured only from the cylinder axis.

Therefore, the vector used in the cylinder equation must contain only the
component perpendicular to the axis.

-------------------------------------------------------------------------------
Projection Formula
-------------------------------------------------------------------------------

Given

    v = w + tD

and the normalized cylinder axis

    A

The parallel component of v is

    v_parallel = (v · A) A

-------------------------------------------------------------------------------
Perpendicular Component
-------------------------------------------------------------------------------

The perpendicular component is obtained by subtracting the projection:

    v_perpendicular = v - v_parallel

Substituting the projection formula gives

    v_perpendicular

    = (w + tD)

      -

      ((w + tD) · A) A

-------------------------------------------------------------------------------
Cylinder Surface Equation
-------------------------------------------------------------------------------

The infinite cylinder is defined by

    ||v_perpendicular||² = r²

Substituting the perpendicular component gives

    || (w + tD)

       -

       ((w + tD) · A) A ||

   ²

    = r²

This is the complete geometric equation of an infinite cylinder.

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

The projection removes the component of the vector that lies along the
cylinder axis.

The remaining component represents the shortest distance between the ray
point and the cylinder axis.

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• The projection always uses the normalized axis.

• Only the perpendicular component contributes to the cylinder radius.

• At this stage the equation is still geometric.

• The next step is to expand this equation into a quadratic equation of the
  form

      at² + bt + c = 0

===============================================================================

===============================================================================
STEP 4 — Simplifying the Cylinder Equation
===============================================================================

Concept
-------

The geometric equation still contains a projection operation.

Before expanding the quadratic equation, the expression is simplified by
separating constant and variable terms.

-------------------------------------------------------------------------------
Expanding the Projection
-------------------------------------------------------------------------------

The projection term is

    (w + tD) · A

Using the distributive property of the dot product

    (a + b) · c = a · c + b · c

gives

    (w + tD) · A

    = w · A + t(D · A)

-------------------------------------------------------------------------------
Substitution
-------------------------------------------------------------------------------

Replacing the projection inside the cylinder equation gives

    (w + tD)

    -

    (w · A + t(D · A))A

-------------------------------------------------------------------------------
Grouping Constant and Variable Terms
-------------------------------------------------------------------------------

Constant part

    w - (w · A)A

Variable part

    t(D - (D · A)A)

-------------------------------------------------------------------------------
Introducing New Vectors
-------------------------------------------------------------------------------

Define

    m = w - (w · A)A

This is the perpendicular component of w.

Define

    n = D - (D · A)A

This is the perpendicular component of the ray direction.

-------------------------------------------------------------------------------
Simplified Cylinder Equation
-------------------------------------------------------------------------------

The infinite cylinder equation becomes

    ||m + tn||² = r²

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

The projection disappears completely from the final equation.

The problem is now reduced to a standard vector equation that can be expanded
exactly like the sphere equation.

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• m is constant.

• n is constant.

• The only remaining unknown is t.

• The next step is to expand

      ||m + tn||²

  into

      at² + bt + c = 0

===============================================================================

===============================================================================
STEP 5 — Deriving the Quadratic Equation
===============================================================================

Concept
-------

The simplified cylinder equation

    ||m + tn||² = r²

must be expanded into a quadratic equation that can be solved for t.

-------------------------------------------------------------------------------
Norm Identity
-------------------------------------------------------------------------------

The squared length of any vector is

    ||x||² = x · x

Therefore

    ||m + tn||²

becomes

    (m + tn) · (m + tn)

-------------------------------------------------------------------------------
Dot Product Expansion
-------------------------------------------------------------------------------

Using

    (a + b) · (a + b)

    = a · a

      + 2(a · b)

      + b · b

gives

    m · m

    + 2t(m · n)

    + t²(n · n)

    = r²

-------------------------------------------------------------------------------
Move Everything to One Side
-------------------------------------------------------------------------------

t²(n · n)

+

2t(m · n)

+

m · m

-

r²

=

0

-------------------------------------------------------------------------------
Quadratic Coefficients
-------------------------------------------------------------------------------

a

    = n · n

b

    = 2(m · n)

c

    = m · m - r²

-------------------------------------------------------------------------------
Final Quadratic Equation
-------------------------------------------------------------------------------

    at² + bt + c = 0

-------------------------------------------------------------------------------
Relationship with Sphere
-------------------------------------------------------------------------------

Sphere

    a = D · D

    b = 2(oc · D)

    c = oc · oc - r²

Cylinder

    a = n · n

    b = 2(m · n)

    c = m · m - r²

The algorithm is identical.

Only the perpendicular components are used instead of the original vectors.

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• The quadratic equation represents an infinite cylinder.

• Solving it gives the intersection with the infinite surface.

• A second validation step is still required to verify the cylinder height.

===============================================================================

===============================================================================
STEP 6 — Height Validation (Finite Cylinder)
===============================================================================

Concept
-------

The quadratic equation describes an infinite cylinder.

A second validation step is required to determine whether the intersection
point lies inside the finite cylinder height.

-------------------------------------------------------------------------------
Intersection Point
-------------------------------------------------------------------------------

After solving the quadratic equation, compute

    P = O + tD

-------------------------------------------------------------------------------
Vector from the Cylinder Center
-------------------------------------------------------------------------------

Compute

    H = P - C

where

    C = Cylinder Center

-------------------------------------------------------------------------------
Projection onto the Cylinder Axis
-------------------------------------------------------------------------------

The distance along the cylinder axis is

    h = H · A

where

    A = Normalized Cylinder Axis

Unlike previous projections, only the scalar value is needed.

-------------------------------------------------------------------------------
Height Condition
-------------------------------------------------------------------------------

For a cylinder with height

    Height

the valid range is

    -Height / 2

        ≤ h ≤

     Height / 2

If the condition is satisfied,

    The intersection belongs to the finite cylinder body.

Otherwise,

    The intersection belongs only to the infinite cylinder and must be
    rejected.

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

Solve quadratic equation

        ↓

Compute hit point

        ↓

Compute

    H = P - C

        ↓

Compute

    h = H · A

        ↓

Validate height

        ↓

Accept or reject the intersection

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• This validation is performed AFTER solving the quadratic equation.

• No new quadratic equation is introduced.

• The cylinder body is centered around C.

• The valid range is symmetric around the center.

===============================================================================


===============================================================================
STEP 7 — Cylinder Caps
===============================================================================

Concept
-------

Each cylinder cap is simply

    Plane
        +
    Circular Boundary

The plane intersection algorithm is reused without modification.

A second test determines whether the hit point lies inside the circular cap.

-------------------------------------------------------------------------------
Cap Centers
-------------------------------------------------------------------------------

Bottom Cap

    Cbottom = C - (Height / 2)A

Top Cap

    Ctop = C + (Height / 2)A

where

    C = Cylinder Center

    A = Normalized Cylinder Axis

-------------------------------------------------------------------------------
Cap Normals
-------------------------------------------------------------------------------

Bottom Cap

    N = -A

Top Cap

    N = +A

-------------------------------------------------------------------------------
Plane Intersection
-------------------------------------------------------------------------------

Intersect the ray with the cap plane using the standard plane algorithm.

If no plane intersection exists,

    Reject.

-------------------------------------------------------------------------------
Circular Boundary Test
-------------------------------------------------------------------------------

After computing

    P = O + tD

calculate

    v = P - Ccap

The hit belongs to the cap only if

    v · v ≤ r²

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

Create cap plane

        ↓

Plane intersection

        ↓

Compute hit point

        ↓

Compute

    v = P - Ccap

        ↓

Check

    dot(v,v) ≤ r²

        ↓

Accept or reject

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• The cap uses the existing plane intersection algorithm.

• Only one additional radius test is required.

• Squared distance avoids computing square roots.

• Both caps are identical except for their center and normal direction.

===============================================================================

### STEP 8 — Complete Cylinder Intersection Algorithm

```text
===============================================================================
STEP 8 — COMPLETE CYLINDER INTERSECTION ALGORITHM
===============================================================================

Concept
-------

At this point, every mathematical component required for cylinder
intersection has been derived.

We now combine them into a complete intersection algorithm capable of
handling:

    • Cylinder Body
    • Top Cap
    • Bottom Cap

while always returning the closest valid intersection.

-------------------------------------------------------------------------------
Overall Strategy
-------------------------------------------------------------------------------

The cylinder consists of three independent geometric primitives:

    1. Infinite Cylinder Body

    2. Top Cap

    3. Bottom Cap

Each one can independently intersect the ray.

The renderer must test all possible intersections and keep only the closest
valid one.

-------------------------------------------------------------------------------
Step 1 — Test the Infinite Cylinder
-------------------------------------------------------------------------------

Solve the quadratic equation

    at² + bt + c = 0

If

    discriminant < 0

there is no body intersection.

Otherwise,

compute the valid root.

-------------------------------------------------------------------------------
Step 2 — Validate the Height
-------------------------------------------------------------------------------

For every valid body root,

compute

    P = O + tD

Then

    H = P - C

Project onto the axis

    h = H · A

Accept the body hit only if

    -Height / 2 ≤ h ≤ Height / 2

Otherwise,

discard it.

-------------------------------------------------------------------------------
Step 3 — Test the Top Cap
-------------------------------------------------------------------------------

Treat the top cap as

    Plane

        +

    Circular Boundary

Procedure

    Plane Intersection

            ↓

    Compute Hit Point

            ↓

    Radius Validation

            ↓

    Store if Valid

-------------------------------------------------------------------------------
Step 4 — Test the Bottom Cap
-------------------------------------------------------------------------------

Exactly identical to the top cap.

Only

    Center

and

    Normal

change.

-------------------------------------------------------------------------------
Step 5 — Compare Every Valid Intersection
-------------------------------------------------------------------------------

After testing

    • Body

    • Top Cap

    • Bottom Cap

multiple valid intersections may exist.

The renderer always keeps

    the smallest positive t

inside the current interval.

-------------------------------------------------------------------------------
Example
-------------------------------------------------------------------------------

Suppose

Body

    t = 8

Top Cap

    t = 4

Bottom Cap

    No Hit

The final intersection becomes

    t = 4

because it is the closest visible surface.

-------------------------------------------------------------------------------
Hit Record
-------------------------------------------------------------------------------

Only AFTER the closest valid intersection has been selected do we fill

    record->t

    record->point

    record->normal

    record->front_face

    record->object

This guarantees that the renderer always receives the nearest visible hit.

-------------------------------------------------------------------------------
Complete Algorithm
-------------------------------------------------------------------------------

Ray

        ↓

Solve Infinite Cylinder

        ↓

Discriminant < 0 ?

        ↓

Find Valid Root

        ↓

Height Validation

        ↓

Store Body Hit

        ↓

Test Top Cap

        ↓

Store if Valid

        ↓

Test Bottom Cap

        ↓

Store if Valid

        ↓

Compare All Valid Hits

        ↓

Choose Smallest t

        ↓

Fill Hit Record

        ↓

Return Success

-------------------------------------------------------------------------------
Relationship with Other Objects
-------------------------------------------------------------------------------

Sphere

    One primitive

        ↓

    One quadratic

        ↓

    One final hit

Plane

    One primitive

        ↓

    One linear equation

        ↓

    One final hit

Cylinder

    Three primitives

        ↓

    Quadratic + Two Plane Tests

        ↓

    Compare Multiple Hits

        ↓

    One Final Hit

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Although a cylinder appears to be one object,

the renderer treats it as three independent surfaces.

Each surface is tested separately,

then the nearest valid intersection is selected.

This approach keeps the implementation modular, reusable, and consistent
with the architecture of the ray tracer.

===============================================================================
```



*/




//! Cylinder Object Design

/*
===============================================================================
Cylinder Geometry
===============================================================================

The cylinder structure stores only the geometric properties of the object.

Stored Data
-----------

• Center
• Axis (Normalized)
• Radius
• Height

The cylinder DOES NOT store:

• Color
• Material
• Object type
• Linked-list information

Reason
------

Geometry and rendering properties are intentionally separated.

The generic object structure is responsible for:

    • Object type
    • Color
    • Object linkage

while each primitive stores only its own mathematical data.

Architecture
------------

Object
    │
    ├── Type
    ├── Color
    ├── Next
    └── Geometry

                ↓

        Sphere / Plane / Cylinder

Advantages
----------

• No duplicated fields.

• Cleaner architecture.

• Easier to extend with new primitives.

• Geometry remains independent from rendering attributes.

===============================================================================
===============================================================================
STEP 8 — Cylinder Cap Centers
===============================================================================

Concept
-------

A cylinder cap is a circular plane located at one end of the cylinder.

The cylinder has two caps:

    • Top Cap
    • Bottom Cap

Both caps lie on the cylinder axis.

-------------------------------------------------------------------------------
Cylinder Data
-------------------------------------------------------------------------------

Given

    C = Cylinder Center

    A = Cylinder Axis (Normalized)

    H = Cylinder Height

-------------------------------------------------------------------------------
Top Cap Center
-------------------------------------------------------------------------------

The top cap is located half the cylinder height along the axis.

    C_top = C + (H / 2)A

-------------------------------------------------------------------------------
Bottom Cap Center
-------------------------------------------------------------------------------

The bottom cap is located half the cylinder height in the opposite direction.

    C_bottom = C - (H / 2)A

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

The cylinder center is positioned exactly halfway between both caps.

Moving half the height in either direction reaches each cap center.

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• The cylinder axis must always be normalized.

• These equations compute only the cap centers.

• Plane intersection and circular boundary tests are performed later.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Top Cap:

    Center + Axis × Half Height

Bottom Cap:

    Center - Axis × Half Height

===============================================================================

===============================================================================
STEP 9 — Plane Intersection for Cylinder Caps
===============================================================================

Concept
-------

Each cylinder cap is a plane.

Therefore, the plane intersection algorithm can be reused without any changes.

-------------------------------------------------------------------------------
Top Cap
-------------------------------------------------------------------------------

Plane Point

    P0 = Ctop

Plane Normal

    N = A

-------------------------------------------------------------------------------
Bottom Cap
-------------------------------------------------------------------------------

Plane Point

    P0 = Cbottom

Plane Normal

    N = -A

-------------------------------------------------------------------------------
Plane Intersection
-------------------------------------------------------------------------------

Use the standard plane equation

    t = ((P0 - O) · N) / (D · N)

where

    O = Ray Origin

    D = Ray Direction

-------------------------------------------------------------------------------
Result
-------------------------------------------------------------------------------

If the plane intersection is valid,

Compute

    P = O + tD

This point lies on the cap plane.

-------------------------------------------------------------------------------
Important Note
-------------------------------------------------------------------------------

Being on the plane does NOT mean the point belongs to the cap.

A second circular boundary test is still required.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Cylinder caps reuse the existing plane intersection algorithm.

Only one additional radius test remains.

===============================================================================

===============================================================================
STEP 10 — Cylinder Cap Radius Test
===============================================================================

Concept
-------

The plane intersection only guarantees that the hit point lies on the cap
plane.

A second test determines whether the hit point lies inside the circular cap.

-------------------------------------------------------------------------------
Given
-------------------------------------------------------------------------------

Cap Center

    Ccap

Intersection Point

    P

-------------------------------------------------------------------------------
Vector from the Cap Center
-------------------------------------------------------------------------------

Compute

    v = P - Ccap

-------------------------------------------------------------------------------
Radius Test
-------------------------------------------------------------------------------

The point belongs to the cap if

    ||v|| ≤ r

To avoid the square root,

Square both sides

    ||v||² ≤ r²

Using

    ||v||² = v · v

The final test becomes

    v · v ≤ r²

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

Plane Intersection

        ↓

Compute hit point

        ↓

Compute

    v = P - Ccap

        ↓

Check

    dot(v,v) ≤ r²

        ↓

Accept or Reject

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

Using the squared distance avoids the square root operation and is consistent
with the sphere and cylinder body intersection algorithms.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

A cap hit is valid only if the hit point lies both

    • on the cap plane

and

    • inside the circular boundary.

===============================================================================


*/










