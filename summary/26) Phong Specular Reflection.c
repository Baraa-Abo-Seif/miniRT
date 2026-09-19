1. Objective

The first official MiniRT Bonus feature is:

Add specular reflection to achieve a full Phong reflection model.

Our Mandatory renderer already handles:

Ambient Lighting
+
Diffuse Lighting

The goal of this Bonus is to extend the lighting model to:

Ambient
+
Diffuse
+
Specular

This gives us the Full Phong Reflection Model.

Conceptually:

// Mandatory
Final Color = Ambient + Diffuse

// Bonus
Final Color = Ambient + Diffuse + Specular

The important point is that we are extending the existing lighting system, not replacing it.

2. What Is Specular Reflection?

When light reaches a surface, the resulting illumination can be understood through different components.

For our current renderer, we care about three:

// 1. Ambient
//    General background illumination.

// 2. Diffuse
//    Illumination caused by the surface orientation
//    relative to the light.

// 3. Specular
//    The bright highlight produced when the
//    reflected light points toward the viewer.

The most important distinction is:

Diffuse  -> How directly does the surface face the light?

Specular -> How directly does the reflected light face the camera?

That distinction is fundamental.

3. The Four Important Vectors

At the intersection point P, we work with four important directions.

                 Camera
                   |
                   | V
                   ↓
                   P
                  /|
                 / |
                /  | N
               /
              L
             /
           Light

We have:

Symbol	Meaning
N	Surface normal
L	Direction from the hit point toward the light
V	Direction from the hit point toward the camera
R	Direction of the reflected light

These vectors are the foundation of the Specular calculation.

4. The Surface Normal — N

N is the normal vector at the intersection point.

It represents the direction perpendicular to the surface.

// N tells us the orientation of the surface
// at the exact point where the ray hits.

For lighting calculations, the normal should be normalized:

$$ |N|=1 $$

We already use this vector in our Diffuse calculation.

Therefore, we do not need a new concept here.

The existing normal calculation becomes part of the Specular calculation as well.

5. The Light Direction — L

L represents the direction:

$$ P \rightarrow Light $$

In other words:

// Start at the intersection point.
// Move toward the light.

We normally normalize it:

$$ |L|=1 $$

This is also already part of our existing lighting system.

6. The View Direction — V

V represents the direction:

$$ P \rightarrow Camera $$

So:

// Start at the intersection point.
// Move toward the camera.

Again, we want:

$$ |V|=1 $$

This vector is especially important for Specular lighting.

Why?

Because Specular reflection depends on whether the reflected light is travelling toward the viewer.

7. The Reflection Direction — R

This is the new important concept.

When light hits a surface, it reflects.

We need to calculate the direction of that reflected light.

The reflection vector is:

$$ \boxed{ R = 2(N\cdot L)N-L } $$

This is one of the most important equations in today's implementation.

8. Understanding the Reflection Equation

Let's break it down:

$$ R = 2(N\cdot L)N-L $$

First:

$$ N\cdot L $$

tells us how aligned the surface normal is with the light direction.

Then:

$$ 2(N\cdot L)N $$

gives us the appropriate projection along the normal.

Finally:

$$ -L $$

accounts for the incoming direction so that we obtain the outgoing reflected direction.

The result is:

$$ \boxed{R} $$

which represents:

// The direction in which the light
// is reflected from the surface.
9. Simple Reflection Example

Suppose:

$$ N=(0,1,0) $$

and:

$$ L=(0,1,0) $$

Then:

$$ N\cdot L=1 $$

Therefore:

$$ R=2(1)N-L $$

Substituting:

$$ R=2(0,1,0)-(0,1,0) $$

So:

$$ \boxed{ R=(0,1,0) } $$

The reflected direction is therefore:

R = (0, 1, 0)
10. Diffuse Lighting Reminder

Before introducing Specular, remember what our renderer already does.

Diffuse lighting uses:

$$ N\cdot L $$

and:

$$ \boxed{ I_{diffuse}=\max(0,N\cdot L) } $$

This answers:

How directly does the surface face the light?

If:

$$ N\cdot L>0 $$

the light contributes to the surface.

If:

$$ N\cdot L\leq0 $$

there is no Diffuse contribution from that light.

11. Specular Is Different

Specular does not simply use:

$$ N\cdot L $$

Instead, we first calculate the reflected direction:

$$ R $$

Then we compare it with the viewer direction:

$$ V $$

Using the dot product:

$$ \boxed{ R\cdot V } $$

This answers:

How closely is the reflected light aligned with the viewer?

That is the core idea of Specular lighting.

12. Understanding R · V

The dot product gives us the alignment between the two vectors.

If:

$$ R\cdot V\approx1 $$

then:

// R and V point in nearly the same direction.
// The reflected light is heading toward the viewer.
// Strong highlight.

If:

$$ R\cdot V\approx0 $$

then:

// R and V are approximately perpendicular.
// Very weak or no highlight.

If:

$$ R\cdot V<0 $$

then:

// The reflected light points away from the viewer.
// No Specular contribution.
13. Why Do We Use max(0, R · V)?

The basic Specular calculation starts with:

$$ R\cdot V $$

But this value can be negative.

We do not want negative light.

Therefore:

$$ \boxed{ \max(0,R\cdot V) } $$

is used.

So:

// Positive value
// -> possible Specular contribution.

// Zero
// -> no Specular contribution.

// Negative value
// -> clamp to zero.

Mathematically:

$$ R\cdot V<0 $$

becomes:

$$ 0 $$
14. Shininess

Now we introduce another important parameter:

$$ \boxed{shininess} $$

The Specular intensity is calculated as:

$$ \boxed{ I_{specular} = \left( \max(0,R\cdot V) \right)^{shininess} } $$

The shininess parameter controls the appearance of the highlight.

15. Low Shininess

For example:

$$ shininess=10 $$

The highlight becomes:

// Wider
// Softer
// More spread out

Conceptually:

          █████
       ███████████
     ███████████████
16. High Shininess

For example:

$$ shininess=100 $$

The highlight becomes:

// Smaller
// Sharper
// More concentrated

Conceptually:

          █
         ███
        █████

So:

// Low shininess
// -> broad highlight

// High shininess
// -> sharp highlight
17. Complete Specular Formula

The complete Specular intensity is:

$$ \boxed{ I_s= \left( \max(0,R\cdot V) \right)^{shininess} } $$

where:

R = Reflection direction
V = View direction
shininess = Material highlight parameter

And:

$$ R=2(N\cdot L)N-L $$

Therefore, the complete process is:

// Step 1
// Calculate N · L

// Step 2
// Calculate reflection vector R

R = 2(N · L)N - L

// Step 3
// Compare reflection with view direction

R · V

// Step 4
// Remove negative values

max(0, R · V)

// Step 5
// Apply shininess

pow(max(0, R · V), shininess)
18. Full Phong Model

Now we can combine everything.

Ambient
Ambient contribution
Diffuse
$$ \boxed{ I_d=\max(0,N\cdot L) } $$
Specular
$$ \boxed{ I_s= \left( \max(0,R\cdot V \right)^{shininess} } $$

Therefore conceptually:

$$ \boxed{ Color_{final} = Color_{ambient} + Color_{diffuse} + Color_{specular} } $$

This is our Full Phong Model.

19. The Difference Between Diffuse and Specular

This distinction should be permanently clear.

Diffuse
N  <---->  L

We ask:

How much is the surface facing the light?

Formula:

$$ \boxed{ \max(0,N\cdot L) } $$
Specular
R  <---->  V

We ask:

How much is the reflected light facing the viewer?

Formula:

$$ \boxed{ \left(\max(0,R\cdot V)\right)^{shininess} } $$

Therefore:

Diffuse:
    N · L

Specular:
    R · V

This is one of the most important things to remember.

20. Complete Lighting Pipeline

Our existing renderer conceptually does:

Ray
 │
 ▼
Intersection
 │
 ▼
Hit Point
 │
 ▼
Normal
 │
 ▼
Light Direction
 │
 ▼
Diffuse
 │
 ▼
Final Color

After today's Bonus:

Ray
 │
 ▼
Intersection
 │
 ▼
Hit Point
 │
 ├───────────────┐
 │               │
 ▼               ▼
Normal          View Direction
 │               │
 │               │
 ▼               │
Light Direction  │
 │               │
 ├──────┐        │
 │      │        │
 ▼      ▼        │
Diffuse Reflection
        │        │
        ▼        │
        R        │
        │        │
        └──┬─────┘
           ▼
         R · V
           │
           ▼
      max(0, ...)
           │
           ▼
       Shininess
           │
           ▼
       Specular
           │
           ▼
    Ambient + Diffuse + Specular
           │
           ▼
       Final Color
21. What Changes in Our Architecture?

The important architectural principle is:

We do not redesign the Mandatory renderer.

We already have:

Hit Point
Normal
Light
Diffuse
Shadow
Color accumulation

The Bonus extends this pipeline.

Conceptually:

// Existing
Hit → Normal → Light → Diffuse

// Bonus
Hit → Normal → Light → Diffuse
                    ↘
                      Reflection → View → Specular

This is exactly why our existing architecture was designed to be extensible.

22. What Information Does Specular Need?

The Specular calculation requires:

// From the intersection
Hit Point P
Normal N

// From the light
Light Position
Light Direction L

// From the camera
Camera Position
View Direction V

// From the material
Shininess
Specular parameters

So before writing implementation code, we need to inspect our existing structures and determine where each piece of information already exists.

23. Important Implementation Principle

We should not immediately create random new fields or duplicate data.

Instead:

// First inspect what already exists.

// Then determine what is missing.

// Then introduce the smallest architectural
// addition necessary for the Bonus.

For example, if the project already has a material structure, shininess should naturally belong there.

If the project already has a hit record containing the intersection point and normal, we should reuse it.

If the renderer already knows the camera position, we should derive V from it rather than duplicating unnecessary information.

24. Mathematical Checklist

Before implementation, the following must be understood:

[✓] N = Surface normal
[✓] L = Direction toward the light
[✓] V = Direction toward the camera
[✓] R = Reflected light direction

[✓] Diffuse uses N · L

[✓] Reflection:
    R = 2(N · L)N - L

[✓] Specular uses R · V

[✓] Negative values are clamped:
    max(0, R · V)

[✓] Shininess controls highlight sharpness

[✓] Specular:
    pow(max(0, R · V), shininess)

[✓] Full Phong:
    Ambient + Diffuse + Specular
25. The Mental Model to Keep

The simplest way to remember the whole system is:

                    LIGHT
                      │
                      │ L
                      ▼
                    P •
                     │\
                     │ \
                     │  \ R
                     │   \
                     │    \────────►
                     │              CAMERA
                     │                 ▲
                     │                 │
                     │                 │ V
                     N                 │

The process is:

// 1. Where is the surface facing?
N

// 2. Where is the light?
L

// 3. Where does the light reflect?
R

// 4. Where is the camera?
V

// 5. Does the reflected light point toward the camera?
R · V

// 6. How sharp should the highlight be?
shininess

Then:

Ambient
   +
Diffuse
   +
Specular
   =
Full Phong