/* ************************************************************************** */
/*                                                                            */
/*                               Ray Equation                                 */
/*                                                                            */
/* ************************************************************************** */

/*

//===============================================================================
! Introduction
//===============================================================================

~ Everything in MiniRT is built on one fundamental idea:

    "Cast a ray, then ask: What did it hit?"

Before we can test intersections, calculate lighting, or render a scene,
we must first describe how a ray moves through space.

This is exactly what the Ray Equation does.

! Instead of memorizing:

    P = O + tD

we will understand why this equation naturally appears.


//===============================================================================
! Why Do We Need It?
//===============================================================================

! A ray starts from the camera and travels through the scene.

? As it moves, we repeatedly ask questions like:

    • Did it hit the sphere here?
    • Did it hit the plane here?
    • Did it hit another object here?

? To answer these questions, we must always know:

~    "Where is the ray at this moment?"

The Ray Equation gives us the position of the ray after it has traveled
any distance.

Without it, we cannot perform any intersection test.

# This is why almost every stage of MiniRT depends on it.

    Ray Generation
           │
           ▼
     Ray Equation
           │
           ▼
 Sphere Intersection
           │
           ▼
 Plane Intersection
           │
           ▼
      Lighting
           │
           ▼
      Rendering


//===============================================================================
! Core Idea
//===============================================================================

^ A ray is different from the vectors we studied before.

Previously, a vector connected two known points:

    Start -----------------------> End

The ray is different.

% It has:

    • A starting point (Origin)
    • A direction (Direction)

# But it has no predefined ending point.

It keeps moving forward until it intersects an object.

    Origin •────────────────────────────►
                                        ►
                                          ►
                                            ►
                                              ►

! To know where the ray is after moving, we combine two things:

    Current Position

        =

    Starting Point

        +

    Movement

The movement itself is:

    Direction × Distance

! This naturally leads to:

!    Current Point = Origin + (Direction × Distance)

The variable representing the traveled distance is called **t**.

Therefore, the Ray Equation becomes:

!    P = O + tD


//===============================================================================
! Examples
//===============================================================================

Example 1

Origin

    (0,0,0)

Direction

    (1,0,0)

The ray moves only along the X-axis.

If it travels 5 units,

its new position is:

    (5,0,0)


------------------------------------------------------------

Example 2

Origin

    (2,0,0)

Direction

    (1,0,0)

t = 3

Movement:

    Direction × t

    (1,0,0) × 3

    =

    (3,0,0)

New Position:

    Origin + Movement

    (2,0,0)

    +

    (3,0,0)

    =

    (5,0,0)

The ray is now located at:

    (5,0,0)


------------------------------------------------------------

Example 3

Think of a laser pointer.

You never tell the laser:

    "Stop at this point."

Instead, you tell it:

    "Keep moving in this direction."

The ray continues forever until an object blocks it.


//===============================================================================
! Mental Model
//===============================================================================

Imagine walking.

You know:

    Where you started.

You also know:

    Which direction to walk.

Now someone asks:

    "Where will you be after walking 10 meters?"

The answer is simply:

    Starting Position

           +

    Walking Direction

           ×

    10 meters

The Ray Equation follows exactly the same logic.

! It always answers one question:

?    "Where is the ray after traveling t units?"


//===============================================================================
! Common Beginner Mistakes
//===============================================================================

[1] Thinking a ray has an ending point.

Wrong.

A ray has:

    Origin
    Direction

It continues infinitely until something intersects it.


------------------------------------------------------------

[2] Thinking the Ray Equation detects collisions.

Wrong.

The equation only tells us where the ray is.

Collision detection comes afterward.


------------------------------------------------------------

[3] Thinking t is a random variable.

Wrong.

t represents the traveled distance from the Origin along the Direction.


------------------------------------------------------------

[4] Thinking we search directly for the collision point.

Actually, most intersection algorithms search for:

    t

Once we know t, finding the collision point is immediate:

!    P = O + tD


//===============================================================================
! Relation to MiniRT
//===============================================================================

The Ray Equation is used everywhere in MiniRT.

Every intersection algorithm follows the same pattern:

    1. Generate a ray.

    2. Find the correct value of t.

    3. Compute the hit point:

        P = O + tD

    4. Compute the surface normal.

    5. Compute lighting.

Notice something important:

Most mathematical equations in MiniRT are actually trying to find:

    t

The hit point is obtained only after t is known.


//===============================================================================
! Extra Insight
//===============================================================================

The Ray Equation does not move the ray step by step.

Instead, it allows us to compute the position of the ray
at any distance directly.

For example:

    t = 1

gives the position after one unit.

    t = 10

immediately gives the position after ten units.

There is no need to simulate the intermediate movement.

This direct computation is what makes ray tracing efficient.


//===============================================================================
! Golden Idea
//===============================================================================

? The Ray Equation does NOT answer:

    "Did the ray hit something?"

? It answers:

    "If the ray traveled t units,
     where would it be?"

Everything else in MiniRT starts from this answer.


//===============================================================================
! Key Takeaways
//===============================================================================

✓ A ray consists of an Origin and a Direction.

✓ A ray has no predefined ending point.

✓ Rays continue infinitely until they intersect an object.

✓ The Ray Equation computes the current position of the ray.

!✓ Ray Equation:

        P = O + tD

    P = Current Point
    O = Origin
    D = Direction
    t = Distance traveled along the ray

✓ t represents the traveled distance only when the Direction is normalized.

✓ Most intersection algorithms are actually searching for the correct value
  of t.

✓ Once t is known, the hit point is immediately calculated using:

        P = O + tD


//===============================================================================
! Connection to Previous Lessons
//===============================================================================

Point
      ↓
Vector
      ↓
Length
      ↓
Normalize
      ↓
Unit Vector
      ↓
Ray Equation
      ↓
Intersections
      ↓
Lighting
      ↓
Rendering
*/






