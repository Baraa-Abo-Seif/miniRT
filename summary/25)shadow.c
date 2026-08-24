//! ************************************************************************** //
//!                           Shadow Ray Concept
//! ************************************************************************** //

/*
===============================================================================
CONCEPT
===============================================================================

Diffuse lighting should only be applied if the light can actually reach the
surface.

Another object may block the light before it reaches the hit point.

-------------------------------------------------------------------------------
Solution
-------------------------------------------------------------------------------

Create a second ray.

This ray starts at the hit point and points toward the light source.

This ray is called the Shadow Ray.

-------------------------------------------------------------------------------
Shadow Ray
-------------------------------------------------------------------------------

Origin

    Hit Point

Direction

    Light Position - Hit Point

-------------------------------------------------------------------------------
Shadow Test
-------------------------------------------------------------------------------

Cast the shadow ray into the world.

If another object intersects the ray BEFORE it reaches the light,

    The point is in shadow.

Otherwise,

    The point receives diffuse lighting.

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

Hit Point

        ↓

Create Shadow Ray

        ↓

Intersect World

        ↓

Blocked ?

    YES → Diffuse = 0

    NO  → Compute Diffuse

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Diffuse lighting is computed only when the light has a clear line of sight
to the surface.

===============================================================================
*/
//! ************************************************************************** //
//!                         Shadow Acne Prevention
//! ************************************************************************** //

/*
===============================================================================
CONCEPT
===============================================================================

A Shadow Ray starts from the surface hit point.

If it starts exactly on the surface, floating-point precision causes the ray
to immediately intersect the same object again.

This produces false shadows.

This artifact is called

    Shadow Acne

-------------------------------------------------------------------------------
Solution
-------------------------------------------------------------------------------

Move the ray origin a very small distance outside the surface.

Instead of

    Origin = Hit Point

use

    Origin = Hit Point + ε × Normal

where

    ε

is a very small positive constant.

-------------------------------------------------------------------------------
Typical Value
-------------------------------------------------------------------------------

ε = 0.0001

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

The surface normal always points outside the object.

Moving along the normal guarantees that the shadow ray starts just outside the
surface instead of inside it.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Never start a shadow ray exactly from the hit point.

Always offset the origin slightly along the surface normal.

===============================================================================
*/

//! **************************************************************************
//!                   Shadow Ray Intersection Interval
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

A shadow ray is only interested in objects located between

    Hit Point

and

    Light Source.

-------------------------------------------------------------------------------
Why not Infinity?
-------------------------------------------------------------------------------

Using

    [EPSILON, ∞)

would allow intersections with objects located behind the light source.

Those objects cannot block the light and therefore must be ignored.

-------------------------------------------------------------------------------
Correct Interval
-------------------------------------------------------------------------------

tmin = EPSILON

tmax = DistanceToLight

Only intersections inside this interval can cast a shadow.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

The shadow ray stops at the light source.

Anything beyond the light is irrelevant.
===============================================================================
*/


