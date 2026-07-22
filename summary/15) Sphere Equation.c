/*
# Sphere Equation

//////////////////////////////////////
## Introduction
/////////////////////////////////////////////

/*
! A **Sphere** :
  is defined by one simple geometric rule:
    ? Every point on its surface is the same distance 
    ? from its center.

Instead of memorizing an equation, we build it from 
this idea.

% To describe a sphere, we only need two pieces of information:
  • Center → Where the sphere is located.
  • Radius → How large the sphere is.

Everything else comes from these two values.

---

## Why do we need it?

In MiniRT, rays constantly ask one question:

! "Did I hit this sphere?"

To answer that question, the computer must determine 
whether a point lies:
  • On the sphere
  • Inside the sphere
  • Outside the sphere

Without a mathematical description of a sphere, 
intersection tests would be impossible.

The Sphere Equation gives the computer a precise way 
to make that decision.

---

## Core Idea

A sphere is **not** defined by its shape.

! It is defined by a **distance**.

Imagine a point **P** somewhere in space.

We measure its distance from the sphere's center.

! Three possibilities exist:

? Distance(Center, P) == Radius
    → Point is on the surface.

? Distance(Center, P) < Radius
    → Point is inside the sphere.

? Distance(Center, P) > Radius
    → Point is outside the sphere.


^ So the real definition of a sphere is:
  Distance(Center, Point) = Radius

But we already know how to compute distance.

From previous lessons:

      Point
          ↓
      Subtract
          ↓
      Vector
          ↓
      Length
          ↓
      Distance

Therefore:
  Distance(Center, Point)

  ↓

  Length(Point - Center)


! So the geometric definition becomes:
    Length(Point - Center) = Radius


Now we remember how vector length is calculated.

Using the Pythagorean Theorem:
    Length(V)= √(Vx² + Vy² + Vz²)

! The vector from the center to the point is:
    Point - Center = (x - cx, y - cy, z - cz)

! Replacing the vector components gives:
  Length(Point - Center) = √((x-cx)² +(y-cy)² +(z-cz)²)

Since:
  Length(Point - Center) = Radius

? We square both sides to remove the square root:
!    (x-cx)² + (y-cy)² + (z-cz)² = Radius²


! This is the **Sphere Equation**.

Notice that we did not memorize it.
We discovered it step by step.

---

## Examples

### Example 1

Sphere:


Center = (0,0,0)
Radius = 5

Point:
P = (3,4,0)

Distance from the center:
5

Since:
! Distance == Radius

The point lies exactly on the surface.


### Example 2

Sphere:

Center = (0,0,0)
Radius = 5

Point:
P = (2,1,0)

Distance is smaller than 5.

Therefore:

! Point is inside the sphere.


### Example 3

Sphere:

Center = (0,0,0)
Radius = 5

Point:
P = (8,0,0)

Distance is greater than 5.

Therefore:
! Point is outside the sphere.

---

## Mental Model

Imagine tying a rope to the center of a sphere.

The rope's length is exactly the radius.

Now stretch the rope in any direction.

Every position the rope can reach belongs to the 
sphere's surface.

           P

           ●
         ／
       ／
     ／
   ●
Center

! Distance = Radius

The direction does not matter.

Only the distance matters.

That is the true meaning of a sphere.


## Common Beginner Mistakes

### Mistake 1: Thinking the center alone defines the sphere
Many spheres can share the same center.
The radius is also required.

---

### Mistake 2: Thinking the sphere equation is something to memorize
It is simply the geometric definition translated into mathematics.

  Equal Distance

  ↓

  Vector

  ↓

  Length

  ↓

  Equation

---

### Mistake 3: Confusing Vector with Distance

Point - Center
  produces a **Vector**, not a distance.

  To obtain the distance, we must compute its **Length**.

---

### Mistake 4: Forgetting why squared terms appear

The squared terms do not appear magically.

They come from:

  Vector Length

  ↓

  Pythagorean Theorem

  ↓

  Square both sides

---

## Relation to MiniRT

The Sphere Equation is the mathematical model used during 
sphere intersection.

The renderer repeatedly asks:

    Ray

    ↓

    Current Point

    ↓

    Does this point satisfy
    the sphere equation?

    Later, we combine:

    Ray Equation
      P = O + tD

    with Sphere Equation


    The renderer combines:

    Ray Equation

            with

    Sphere Equation

  to solve for the value of t.

  Once t is known,
  the hit point is obtained immediately
  using the Ray Equation.



to compute the value of **t** where the ray first touches 
the sphere.

That becomes the **Hit Point**.

Everything after that depends on it:

    Hit Point
          ↓
    Surface Normal
          ↓
    Lighting
          ↓
    Shadows
          ↓
    Reflection


The Sphere Equation is therefore the first real geometric 
object used by the ray tracer.

///////////////////////////////////////////////////////////////////////////////
Looking Ahead
///////////////////////////////////////////////////////////////////////////////

At this stage, we can determine whether a single point
belongs to the sphere.

However, in MiniRT we do not already know that point.

Instead, we know a Ray.

The next step is to combine:

    Ray Equation

            with

    Sphere Equation

This allows us to solve for:

        t

which tells us exactly where the ray first intersects
the sphere.


## Golden Idea

A sphere is simply the set of all points whose distance 
from the center equals the radius.

The famous equation is not something to memorize.

It is just the mathematical translation of that geometric
idea.

---

## Key Takeaways

• A sphere is defined by **Center** and **Radius**.
• Every surface point is exactly one radius away from the center.
• Distance is computed by:
  Point → Vector → Length.
• The Sphere Equation comes directly from the Pythagorean Theorem.
• The squared terms exist because we square both sides 
  to remove the square root.
• In MiniRT, the Sphere Equation is combined with the Ray 
  Equation to find ray-sphere intersections.

| Concept | Meaning |
|----------|---------|
| Center | Sphere Position |
| Radius | Sphere Size |
| Point - Center | Vector |
| Length(Vector) | Distance |
| Distance == Radius | Surface |
| Distance < Radius | Inside |
| Distance > Radius | Outside |
| Sphere Equation | Mathematical description of a sphere |

///////////////////////////////////////////////////////////////////////////////
Connection to Previous Lessons
///////////////////////////////////////////////////////////////////////////////

Point
      ↓
Vector Subtraction
      ↓
Vector
      ↓
Length
      ↓
Distance
      ↓
Sphere Equation
      ↓
Ray-Sphere Intersection





*/
