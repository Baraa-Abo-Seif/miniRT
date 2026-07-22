/*
# Plane Equation

//////////////////////////////////////
## Introduction
/////////////////////////////////////////////

/*
! A Plane 
    is an infinite flat surface.

Unlike a sphere, a plane has:
    • No radius.
    • No volume.
    • No boundaries.

It extends infinitely in every direction.

To describe a plane, we only need two pieces of information:
    • A Point on the plane.
    • A Normal Vector that defines its orientation.

Unlike a sphere, the plane is not defined by size, 
but by **position and orientation**.

---

## Why do we need it?

In MiniRT, rays must interact with different geometric 
objects.
    One of the simplest objects is the **Plane**.

To determine whether a ray hits a plane, the computer first
needs a mathematical description of that plane.

Without the Plane Equation, the renderer cannot answer 
questions like:
    • Does the ray intersect the floor?
    • Where does the intersection occur?
    • Which point should receive lighting?

The Plane Equation provides that mathematical description.

---

## Core Idea

Suppose we know:


Plane Point -> P₀

and

Plane Normal -> N

Now we receive another point: --> P


? The question is:

! Does P lie on the plane?

Instead of measuring a distance (like we did with a sphere)
, we examine the relationship between vectors.

First, create the vector:
    P - P₀

If P really lies on the plane, then this vector stays 
**inside the plane**.

But we already know another important fact:

The Normal Vector is **perpendicular** to the plane.

Therefore:

(P - P₀) ⊥ N

From the Dot Product lesson:

Perpendicular Vectors

    ↓

    Dot Product = 0

So the Plane Equation naturally becomes:

N · (P - P₀) = 0

Notice that we did not memorize this equation.

We derived it from geometry.


## Examples

### Example 1

Suppose we have:


Plane Point -> P₀

and

Plane Normal -> N


If another point P belongs to the plane, then:
    P - P₀

is a vector lying inside the plane.

Since it is perpendicular to the Normal:
    N · (P - P₀) = 0

---

### Example 2

Imagine a perfectly flat table.

──────────────

Pick two points on the table.

The vector connecting them always lies along the surface.

The table's Normal always points upward.

Because they are perpendicular:

    Dot Product = 0

---

### Example 3

Compare a Sphere and a Plane.

Sphere: Defined by
    Center +  Radius


Plane: Defined by
    Point + Normal

The sphere depends on **distance**.

The plane depends on **perpendicularity**.

---

Plane Point

    P₀ = (0,0,0)

Normal

    N = (0,1,0)

Point

    P = (5,0,-2)

    P - P₀ = (5,0,-2)

Dot Product

    (0,1,0) · (5,0,-2) = 0

Therefore,

P lies on the plane.

---

## Mental Model

Imagine placing a pencil upright on a sheet of paper.

        ↑
        │
        │ Normal
        │
    ──────────────
        Paper

The paper represents the Plane.

The pencil represents the Normal.

Now draw a line across the paper.

That line stays on the surface and is always perpendicular 
to the pencil.

This is exactly the relationship used by the Plane Equation.

---

## Common Beginner Mistakes

### Mistake 1: Thinking one point defines a plane

A single point is not enough.

Infinitely many planes can pass through the same point.

A Normal Vector is also required.

---

### Mistake 2: Thinking a plane needs a radius

Unlike a sphere, a plane extends infinitely.

It has no size parameter.

---

### Mistake 3: Forgetting what (P - P₀) represents

    P - P₀

is a vector connecting two points.

It is **not** the plane itself.

---

### Mistake 4: Memorizing the equation

The Plane Equation is simply another way of saying:

> "The vector inside the plane is perpendicular to the 
plane's Normal."

---

## Relation to MiniRT

The Plane Equation alone only describes the plane.

To find an intersection, we combine it with the Ray 
Equation.

We already know that every point on a ray is:

P = O + tD

Substitute this into the Plane Equation:

N · ((O + tD) - P₀) = 0

Now solve for:

t


Once t is known:

P = O + tD


gives the exact Hit Point.

This follows the same workflow used for every object in
MiniRT:

        Ray Equation

            +

     Object Equation

            ↓

        Solve for t

            ↓

        Hit Point

            ↓

        Lighting

For a sphere:

    Ray Equation
        +
    Sphere Equation

For a plane:

    Ray Equation
        +
    Plane Equation

The pattern never changes.

---

///////////////////////////////////////////////////////////////////////////////
Looking Ahead
///////////////////////////////////////////////////////////////////////////////

At this stage, we know how to describe a Plane 
mathematically.

However, MiniRT does not stop here.

The next step is to build the Camera Plane.

Once we understand the Camera Plane,
we can generate one ray for every pixel on the screen.

That is where the renderer truly begins.


## Golden Idea

A plane is defined by one simple geometric property:

Every vector lying inside the plane is perpendicular 
to the plane's Normal.

The Plane Equation is simply the mathematical expression 
of that idea.

The Sphere asks:

    "How far?"

The Plane asks:

    "How aligned?"
---

## Key Takeaways

• A Plane is infinite and has no radius.
• A Plane is defined by a Point and a Normal Vector.
• A point lies on the plane if:
    ```
    N · (P - P₀) = 0
    ```
• The equation comes directly from the concept of 
    perpendicular vectors.
• Dot Product equals zero because the vector inside the 
    plane is perpendicular to the Normal.
• In MiniRT, the Plane Equation is combined with the Ray 
    Equation to solve for t and compute the Hit Point.

| Object | Defined By | Main Idea |
|----------|------------|-----------|
| Sphere | Center + Radius | Equal Distance |
| Plane | Point + Normal | Perpendicularity |
| Sphere Equation | Distance = Radius | Length Comparison |
| Plane Equation | N · (P - P₀) = 0 | Dot Product = 0 |


///////////////////////////////////////////////////////////////////////////////
Connection to Previous Lessons
///////////////////////////////////////////////////////////////////////////////

Point
      ↓
Vector Subtraction
      ↓
Vector
      ↓
Dot Product
      ↓
Plane Equation
      ↓
Ray-Plane Intersection
      ↓
Lighting




*/

