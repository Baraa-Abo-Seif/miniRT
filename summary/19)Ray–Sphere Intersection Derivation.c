//! Ray–Sphere Intersection Derivation
/*
Objective

Determine whether a ray intersects a sphere, and if so, compute the intersection distance t.

Given
Ray Equation

A ray is represented by:

P(t) = O + tD

Where:

O → Ray origin
D → Ray direction (normalized)
t → Distance along the ray
P(t) → Point on the ray
Sphere Equation

A sphere consists of all points whose distance from the center equals the radius.

Mathematically:

distance(P, C) = r

Where:

P → Any point on the sphere
C → Sphere center
r → Sphere radius
Removing the Square Root

Computing the distance requires a square root:

distance(P, C) = √((P − C) · (P − C))

Since square roots are computationally expensive, we square both sides:

distance²(P, C) = r²

Using the dot product:

(P − C) · (P − C) = r²

This becomes the mathematical equation of the sphere used by the ray tracer.

Substituting the Ray Equation

Replace:

P = O + tD

inside the sphere equation:

(O + tD − C) · (O + tD − C) = r²

Rearrange the constant terms:

((O − C) + tD) · ((O − C) + tD) = r²

Define a helper vector:

oc = O − C

The equation becomes:

(oc + tD) · (oc + tD) = r²
Expanding the Dot Product

Expand exactly like:

(a + b)(a + b)

Result:

oc·oc
+
oc·(tD)
+
(tD)·oc
+
(tD)·(tD)

Extract the scalar t:

oc·oc
+
t(oc·D)
+
t(D·oc)
+
t²(D·D)

Since the dot product is commutative:

D·oc = oc·D

The equation simplifies to:

(D·D)t²
+
2(oc·D)t
+
(oc·oc)
=
r²

Move r² to the left side:

(D·D)t²
+
2(oc·D)t
+
(oc·oc)
−
r²
=
0
Quadratic Equation

The equation now has the standard quadratic form:

at² + bt + c = 0

Where:

a = D·D


b = 2(oc·D)


c = (oc·oc) − r²
Solving for t

Use the quadratic formula:

          -b ± √Δ
t = ------------------
             2a

Where:

Δ = b² − 4ac
Interpreting the Discriminant
Δ < 0

No real solutions.

The ray misses the sphere.

Ray ---------->


        ○ Sphere
Δ = 0

One real solution.

The ray touches the sphere exactly once (tangent).

Ray --------●


           ○
Δ > 0

Two real solutions.

The ray enters and exits the sphere.

        ●──────●
      /          \
Ray ─●            ●──>
      \          /
        ●──────●

The two solutions correspond to:

Entry point
Exit point

The smallest positive t is usually the visible intersection.

Why define oc?

Instead of repeatedly writing:

O − C

we define:

oc = O − C

Benefits:

Simpler equations
Cleaner implementation
Avoids recomputing the same vector
Improves readability
Final Mathematical Pipeline
Ray Equation
        │
        ▼
P = O + tD


        │
        ▼
Sphere Equation


(P − C) · (P − C) = r²


        │
        ▼
Substitute P


        │
        ▼
(oc + tD) · (oc + tD) = r²


        │
        ▼
Expand Dot Product


        │
        ▼
Quadratic Equation


at² + bt + c = 0


        │
        ▼
Compute Δ


        │
        ▼
Solve for t


        │
        ▼
Intersection Point

*/