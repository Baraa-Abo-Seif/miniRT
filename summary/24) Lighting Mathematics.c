//! **************************************************************************
//!                           Lighting Mathematics
//! **************************************************************************

/*
===============================================================================
STEP 1 — What is Lighting?
===============================================================================

Concept
-------

After finding the intersection point, the ray tracer still does not know
how this point should appear on the screen.

Geometry determines

    • Where the object is.

Lighting determines

    • How bright this point should be.

-------------------------------------------------------------------------------
Geometry vs Lighting
-------------------------------------------------------------------------------

Geometry answers:

    • Did the ray hit the object?

    • Where is the hit point?

    • What is the surface normal?

Lighting answers:

    • How much light reaches this point?

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

Without lighting,

every visible point would simply use the object's original color.

Every point would have exactly the same brightness.

The rendered image would appear completely flat.

Lighting creates brightness variation across the surface.

These variations reveal

    • Shape

    • Depth

    • Surface Orientation

-------------------------------------------------------------------------------
Surface Brightness
-------------------------------------------------------------------------------

Each point on the surface receives a different amount of light.

This happens because every point has a different

    Surface Normal

relative to the light direction.

Therefore,

different points produce different brightness values.

-------------------------------------------------------------------------------
Object Color
-------------------------------------------------------------------------------

Lighting does NOT change the object's original color.

Lighting only changes

    • The brightness

of that color.

Example

    Object Color

        Red

            ↓

    Weak Lighting

        Dark Red

            ↓

    Strong Lighting

        Bright Red

The base color remains identical.

Only its intensity changes.

-------------------------------------------------------------------------------
Lighting Components
-------------------------------------------------------------------------------

The mandatory version of MiniRT computes two lighting components:

    • Ambient Light

    • Diffuse Light

Later they are combined to produce the final illumination.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Geometry finds the object.

Lighting reveals the object.

The object's color remains the same.

Only the amount of light received by each point changes.

===============================================================================
*/

//! **************************************************************************
//!                           Lighting Mathematics
//! **************************************************************************

/*
===============================================================================
STEP 2 — Ambient Light
===============================================================================

Concept
-------

Ambient Light represents the constant background illumination that exists
everywhere in the scene.

Unlike direct light, ambient light does not originate from a specific
direction.

Instead, it is considered to illuminate every point equally.

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

If only direct lighting were used,

every surface facing away from the light source would become completely black.

In the real world this never happens because light continuously bounces
between surrounding surfaces.

These indirect light bounces softly illuminate shadowed areas.

MiniRT does not compute those multiple light bounces.

Instead, Ambient Light is introduced as a simple approximation.

-------------------------------------------------------------------------------
Purpose
-------------------------------------------------------------------------------

Ambient Light prevents completely black surfaces.

It provides a minimum level of illumination across the entire scene.

-------------------------------------------------------------------------------
Properties
-------------------------------------------------------------------------------

Ambient Light is independent of

    • Surface Normal

    • Light Direction

    • Surface Orientation

    • Shadow Rays

Every visible point receives exactly the same ambient intensity.

-------------------------------------------------------------------------------
Scene Data
-------------------------------------------------------------------------------

The scene stores

    • Ambient Ratio

    • Ambient Color

The ratio defines the intensity of the global illumination.

Example

    Ambient Ratio

        0.2

means

every point receives

    20%

of the ambient light.

-------------------------------------------------------------------------------
Example
-------------------------------------------------------------------------------

Object Color

    Red

Ambient Ratio

    0.2

Final Ambient Contribution

    Dark Red

Increasing the ambient ratio increases the brightness of every object
equally.

-------------------------------------------------------------------------------
Relationship with Other Lighting
-------------------------------------------------------------------------------

Ambient Light is only the base illumination.

Later,

Diffuse Lighting

will be added on top of it.

Final Lighting becomes

    Ambient

        +

    Diffuse

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• Ambient Light is constant across the entire scene.

• It does not depend on the light position.

• It does not depend on the surface normal.

• It does not create shadows.

• It is simply a constant minimum illumination.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Ambient Light is a simplified approximation of indirect light.

Every visible point in the scene receives the same minimum amount of
illumination regardless of its orientation.

===============================================================================
*/

//! **************************************************************************
//!                     Lighting Mathematics
//! **************************************************************************

/*
===============================================================================
STEP 3 — Diffuse Lighting (Lambert Lighting)
===============================================================================

Concept
-------

Unlike Ambient Light,

Diffuse Light depends on the orientation of the surface relative to the
light source.

The more directly the surface faces the light,

the brighter it appears.

-------------------------------------------------------------------------------
Purpose
-------------------------------------------------------------------------------

Diffuse Lighting creates the brightness variations that reveal

    • Shape

    • Depth

    • Curvature

Without diffuse lighting,

every point on the object would have exactly the same brightness.

-------------------------------------------------------------------------------
Required Vectors
-------------------------------------------------------------------------------

Diffuse Lighting uses two normalized vectors.

Surface Normal

    N

The vector perpendicular to the surface.

Light Direction

    L

The vector pointing from the hit point toward the light source.

-------------------------------------------------------------------------------
Geometric Interpretation
-------------------------------------------------------------------------------

The amount of received light depends only on the angle between

    N

and

    L

Small angle

    More received light

Large angle

    Less received light

Light behind the surface

    No received light

-------------------------------------------------------------------------------
Dot Product
-------------------------------------------------------------------------------

The Dot Product

    N · L

measures how much the surface faces the light.

If

    N

and

    L

point in the same direction

    N · L = 1

Maximum illumination.

-------------------------------------------------------------------------------

If

    N

and

    L

are perpendicular

    N · L = 0

No diffuse illumination.

-------------------------------------------------------------------------------

If

    N

and

    L

point in opposite directions

    N · L < 0

The light is behind the surface.

The front face receives no diffuse illumination.

-------------------------------------------------------------------------------
Clamping
-------------------------------------------------------------------------------

Negative lighting has no physical meaning.

Therefore,

MiniRT always computes

    max(0, N · L)

This guarantees that diffuse light is never negative.

-------------------------------------------------------------------------------
Diffuse Equation
-------------------------------------------------------------------------------

Diffuse Intensity

=

max(0, N · L)

-------------------------------------------------------------------------------
Example
-------------------------------------------------------------------------------

Point A

    Faces the light

    N · L ≈ 1

    Maximum brightness

Point B

    Partially faces the light

    N · L ≈ 0.5

    Medium brightness

Point C

    Faces away from the light

    N · L < 0

    Diffuse = 0

-------------------------------------------------------------------------------
Important Notes
-------------------------------------------------------------------------------

• Surface normals must always be normalized.

• Light direction must always be normalized.

• Diffuse lighting depends only on the angle between both vectors.

• Diffuse lighting never becomes negative.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Diffuse Lighting measures how directly a surface faces the light source.

The Dot Product provides this measurement.

The final diffuse contribution is

    max(0, N · L)

===============================================================================
*/




