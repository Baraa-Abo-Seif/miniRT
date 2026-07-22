/*
###############################################################################
# Camera Fundamentals
###############################################################################

//////////////////////////////////////
## Introduction
//////////////////////////////////////

The camera is the starting point of every ray in MiniRT.

Before we can detect intersections, calculate lighting, or render an image,
we first need to answer one simple question:

> How do we generate a different ray for every pixel?

Everything that follows in the renderer depends on this step.

The complete pipeline is:

Camera
    ↓
Generate Rays
    ↓
Ray Equation
    ↓
Intersections
    ↓
Lighting
    ↓
Rendering

This lesson explains how a camera creates thousands of rays that together
form an image.

===============================================================================
1. Camera Plane
===============================================================================

//////////////////////////////////////
## Why do we need a Camera Plane?
//////////////////////////////////////

Imagine a camera that only shoots one ray.

                Ray

Camera ●────────────────────────►

What would happen?

It would only compute the color of a single point.

That means:

One Ray
    ↓
One Pixel

But an image contains thousands (or even millions) of pixels.

Example:

800 × 600

=

480,000 Pixels

Therefore we need:

480,000 Rays

One ray for every pixel.

-------------------------------------------------------------------------------

The next question becomes:

How do we make every ray point in a slightly different direction?

If every ray has exactly the same direction...

→
→
→
→
→

They all hit nearly the same place.

The result would be almost one repeated color.

Clearly this cannot produce an image.

So we need something that tells each pixel where its ray should go.

That "something" is called the:

Camera Plane
(or Image Plane)

-------------------------------------------------------------------------------

Imagine placing an invisible screen in front of the camera.

                Camera Plane

      ┌────────────────────────┐
      │ □ □ □ □ □ □ □ □ □ □ □ │
      │ □ □ □ □ □ □ □ □ □ □ □ │
      │ □ □ □ □ □ □ □ □ □ □ □ │
      └────────────────────────┘
                 ▲
                 │
                 │
                 ● Camera

Each square represents one pixel.

Instead of saying:

"Rotate the ray a little."

We simply say:

"Choose another pixel on the Camera Plane."

Then draw a line from:

Camera

to

That Pixel.

That line becomes the Ray.

-------------------------------------------------------------------------------
## Why is the Camera Plane perpendicular to Forward?
-------------------------------------------------------------------------------

The camera already knows:

• Position
• Forward Direction

Forward always represents the center of the image.

Therefore the Camera Plane must be placed so that Forward passes exactly
through its center.

             Camera Plane

      ┌──────────────────────┐
      │                      │
      │          ×           │
      │                      │
      └──────────────────────┘
                 ▲
                 │ Forward
                 │
                 ● Camera

Notice something important.

The Camera Plane is **perpendicular** to the Forward vector.

Mathematically:

Forward ⟂ Camera Plane

-------------------------------------------------------------------------------
## Why is Forward the Plane Normal?
-------------------------------------------------------------------------------

From the Plane Equation lesson we learned:

Every plane is defined by:

• A Point
• A Normal

The Camera Plane is simply another plane.

Plane Point

↓

Center of the Camera Plane

Plane Normal

↓

Forward

So:

Forward = Normal of the Camera Plane

The Camera Plane is not a special mathematical object.

It is simply a Plane whose normal points where the camera looks.

===============================================================================
2. Field Of View (FOV)
===============================================================================

//////////////////////////////////////
## What is the Field Of View?
//////////////////////////////////////

The Field Of View (FOV) describes:

> How much of the world the camera can see.

It is **not**:

✗ Screen Size

✗ Camera Plane Size

✗ Number of Pixels

It is the angle formed by the outermost rays.

Small FOV

      \   /
       \ /
        ●

The rays stay close together.

Result:

• Smaller visible area
• Objects appear larger (Zoom)

-------------------------------------------------------------------------------

Large FOV

\                 /
 \               /
  \             /
   \           /
    \         /
     \       /
      \     /
       \   /
        \ /
         ●

The rays spread farther apart.

Result:

• Larger visible area
• Objects appear smaller

-------------------------------------------------------------------------------
## Why don't we move the Camera Plane?
-------------------------------------------------------------------------------

A common beginner mistake is believing that increasing the FOV means moving
the Camera Plane farther away.

This is incorrect.

Instead:

The distance stays fixed.

Only the size of the Camera Plane changes.

Distance = 1

↓

Change Plane Size

↓

Change FOV

-------------------------------------------------------------------------------
## Why is the distance fixed to 1?
-------------------------------------------------------------------------------

We intentionally separate two independent concepts.

1. Distance to the Camera Plane

2. Camera Field Of View

If both changed simultaneously, the mathematics would become unnecessarily
complicated.

Instead we keep:

Distance = 1

Then the FOV controls only the Plane Size.

-------------------------------------------------------------------------------
## How does FOV determine the Plane Size?
-------------------------------------------------------------------------------

Look at half of the camera.

                Plane Top
                    ●
                   /|
                  / |
                 /  |
                /θ  | 1
               ●────┘
             Camera

The triangle tells us:

Adjacent = 1

Angle = FOV / 2

We want:

Half Plane Height

This is a right triangle.

The relationship is:

tan(θ)

=

Opposite / Adjacent

Since Adjacent = 1

Half Height

=

tan(FOV / 2)

This famous equation allows us to compute the Camera Plane size directly
from the FOV.

The larger the FOV...

↓

The larger the Camera Plane.

===============================================================================
3. Perspective Projection
===============================================================================

//////////////////////////////////////
## From Pixel to 3D Point
//////////////////////////////////////

Now the Camera Plane exists.

We know:

• Position
• Forward
• Right
• Up
• Plane Center
• Plane Size

The remaining question is:

How do we transform a 2D pixel into a 3D position?

-------------------------------------------------------------------------------

Suppose we know the center of the Camera Plane.

              ×

If we want a pixel on the right:

┌──────────────────────────┐
│                          │
│          ×──────►        │
│                          │
└──────────────────────────┘

We move along:

Right

-------------------------------------------------------------------------------

If we want a pixel higher:

┌──────────────────────────┐
│            ▲             │
│            │             │
│            ×             │
└──────────────────────────┘

We move along:

Up

-------------------------------------------------------------------------------

Therefore every pixel position is built like this:

Pixel Position

=

Plane Center

+

(Horizontal Offset × Right)

+

(Vertical Offset × Up)

Notice that:

Forward only reaches the Plane Center.
Every other pixel is simply an offset from that center.
Right moves horizontally.

Up moves vertically.

Together they allow us to reach **any pixel**.

-------------------------------------------------------------------------------
## Why do we start from the Plane Center?
-------------------------------------------------------------------------------

The Plane Center is the natural reference point.

Every pixel is simply an offset from this center.

Instead of calculating every point independently...

We compute:

Center

↓

Horizontal Movement

↓

Vertical Movement

This makes the mathematics simple and symmetric.

===============================================================================
4. Ray Generation
===============================================================================

//////////////////////////////////////
## Creating the Ray
//////////////////////////////////////

Once the Pixel Position is known...

We already know two points:

Camera Position

Pixel Position

How do we obtain the ray direction?

We use something we learned much earlier.

Vector

=

End

-

Start

Therefore:

Ray Direction

=

Pixel Position

-

Camera Position

-------------------------------------------------------------------------------

But this vector may have any length.

We only care about its direction.

So we normalize it.

Ray Direction

=

normalize(

Pixel Position

-

Camera Position

)

Now the ray is complete.

Ray Origin

=

Camera Position

Ray Direction

=

normalize(

Pixel Position

-

Camera Position

)
Notice that every generated ray has the same origin (the camera position), but a different direction depending on the pixel.
-------------------------------------------------------------------------------
## Final Pipeline
-------------------------------------------------------------------------------

Everything learned so far connects together naturally.

Camera

↓

Forward

↓

Right + Up

↓

Camera Plane

↓

Field Of View

↓

Plane Size

↓

Pixel

↓

Pixel Position

↓

Pixel Position - Camera Position

↓

Normalize

↓

Ray Direction

↓

Ray Equation

↓
↓

Solve for t

↓

Hit Point

↓

Intersections

↓

Lighting

↓

Rendering

===============================================================================
## Mental Model
===============================================================================

Imagine standing behind a window.

The window represents the Camera Plane.

Every point on the window corresponds to exactly one ray.

You don't rotate the rays manually.

You simply choose a different point on the window.

Draw a straight line from your eye to that point.

That line is the ray.

===============================================================================
## Common Beginner Mistakes
===============================================================================

1. Thinking the camera shoots one ray.

Wrong.

Every pixel needs its own ray.

-------------------------------------------------------------------------------

2. Thinking the Camera Plane is parallel to Forward.

Wrong.

It is always perpendicular to Forward.

-------------------------------------------------------------------------------

3. Thinking FOV moves the Camera Plane.

Wrong.

The distance remains fixed.

Only the Plane Size changes.

-------------------------------------------------------------------------------

4. Thinking Forward alone is enough.

Wrong.

Forward reaches only the Plane Center.

Right and Up are required to reach every pixel.

-------------------------------------------------------------------------------

5. Forgetting to normalize the ray direction.

The subtraction gives the direction.

Normalization converts it into a Unit Vector.

===============================================================================
## Relation to MiniRT
===============================================================================

Every rendered image follows exactly this sequence:

Camera

↓

Camera Plane

↓

Perspective Projection

↓

Ray Generation

↓

Ray Equation

↓

Intersection Tests

↓

Lighting

↓

Final Pixel Color

Without this process, no rays can be generated, and therefore nothing can
be rendered.

===============================================================================
## Golden Idea
===============================================================================

The Camera does not randomly shoot rays.

Every pixel corresponds to one point on the Camera Plane.

The ray is simply the normalized vector from the Camera Position to that
pixel.

===============================================================================
## Key Takeaways
===============================================================================

• A rendered image requires one ray per pixel.
• The Camera Plane is an imaginary screen in front of the camera.
• The Camera Plane is perpendicular to Forward.
• Forward is the Normal of the Camera Plane.
• The Camera Plane stays at a fixed distance (usually 1).
• FOV changes the Plane Size, not its distance.
• Perspective Projection converts a 2D pixel into a 3D point.
• Right and Up move across the Camera Plane.
• Ray Direction = normalize(Pixel Position - Camera Position).
• This process connects directly to the Ray Equation.

+----------------------+----------------------------------------------+
| Concept              | Meaning                                      |
+----------------------+----------------------------------------------+
| Camera Plane         | Imaginary screen in front of the camera      |
| Forward              | Plane Normal                                |
| FOV                  | Viewing Angle                               |
| Plane Size           | Determined by the FOV                        |
| Perspective          | Convert Pixel → 3D Point                     |
| Right / Up           | Move across the Camera Plane                 |
| Ray Generation       | Create one ray per pixel                     |
+----------------------+----------------------------------------------+

*/

