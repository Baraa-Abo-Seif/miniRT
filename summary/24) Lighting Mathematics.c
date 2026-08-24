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


//! **************************************************************************
//!                           Ambient Lighting
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Ambient lighting represents the constant background illumination present in
the entire scene.

Unlike direct lighting, ambient light does not depend on:

    • Surface Normal

    • Light Direction

    • Camera Direction

Every visible point receives the same ambient contribution.

-------------------------------------------------------------------------------
Formula
-------------------------------------------------------------------------------

Ambient Contribution

=

Object Color

×

Ambient Color

×

Ambient Ratio

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

Object Color

        ×

Ambient Color

        ↓

Scale by Ambient Ratio

        ↓

Final Ambient Contribution

-------------------------------------------------------------------------------
Purpose
-------------------------------------------------------------------------------

Ambient lighting prevents objects from becoming completely black in areas
where no direct light reaches them.

It provides the minimum illumination visible in the scene.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Ambient lighting is the simplest lighting component.

It is constant for every visible point and serves as the base layer of the
final rendered color.

===============================================================================
*/

//! **************************************************************************
//!                    Diffuse Lighting — Fundamental Idea
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Diffuse lighting simulates the amount of light reaching a surface depending
on the angle between the incoming light and the surface.

Unlike ambient lighting, diffuse lighting is NOT constant.

Every point on the object receives a different amount of light.

-------------------------------------------------------------------------------
Principle
-------------------------------------------------------------------------------

• Light hitting the surface perpendicularly produces the strongest
  illumination.

• As the angle increases, the illumination decreases.

• When the light reaches 90 degrees, no diffuse light remains.

• When the light is behind the surface, it contributes nothing.

-------------------------------------------------------------------------------
Required Directions
-------------------------------------------------------------------------------

Diffuse lighting compares two normalized vectors:

    • Surface Normal

    • Light Direction

-------------------------------------------------------------------------------
Mathematical Tool
-------------------------------------------------------------------------------

The comparison is performed using the Dot Product.

The dot product measures how well the two directions align.

Result

    1  → Maximum illumination

    0  → No illumination

   <0  → Light is behind the surface

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Diffuse lighting depends entirely on the angle between the surface normal
and the incoming light direction.

This is why the Dot Product is the core of Lambertian Reflection.

===============================================================================
*/

//! **************************************************************************
//!                     Lambert's Cosine Law
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Diffuse lighting follows Lambert's Cosine Law.

The amount of light received by a surface depends on the cosine of the angle
between the surface normal and the incoming light direction.

-------------------------------------------------------------------------------
Formula
-------------------------------------------------------------------------------

Light Intensity

∝

cos(θ)

where

    θ = angle between

        • Surface Normal

        • Light Direction

-------------------------------------------------------------------------------
Special Cases
-------------------------------------------------------------------------------

θ = 0°

    cos = 1

    Maximum illumination

---------------------------------------

θ = 45°

    cos ≈ 0.707

    Partial illumination

---------------------------------------

θ = 90°

    cos = 0

    No diffuse lighting

---------------------------------------

θ > 90°

    cos < 0

    Light is behind the surface

    Diffuse contribution becomes zero.

-------------------------------------------------------------------------------
Connection with the Dot Product
-------------------------------------------------------------------------------

When both vectors are normalized,

    N · L = cos(θ)

Therefore,

the renderer never computes the angle directly.

Instead, it computes

    dot(N, L)

which immediately provides the cosine required by Lambert's Law.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

The Dot Product is used because, for normalized vectors, it directly equals
the cosine of the angle between the surface normal and the light direction.

This makes diffuse lighting both mathematically correct and computationally
efficient.

===============================================================================
*/

//! **************************************************************************
//!                 Diffuse Lighting — Step 1 (Light Direction)
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Before computing diffuse lighting, the renderer must determine the direction
from the surface point toward the light source.

-------------------------------------------------------------------------------
Formula
-------------------------------------------------------------------------------

Light Direction

=

Light Position

-

Hit Point

-------------------------------------------------------------------------------
Normalization
-------------------------------------------------------------------------------

The resulting vector must always be normalized.

Only normalized vectors allow the dot product to directly represent

    cos(theta)

used by Lambert's Cosine Law.

-------------------------------------------------------------------------------
Why the Hit Point?
-------------------------------------------------------------------------------

Lighting is computed for every visible point independently.

Different points on the same object have different directions toward the
light source.

Therefore, the light direction is always computed from the hit point,
not from the object's center.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

The first step of diffuse lighting is simply constructing a normalized
vector pointing from the hit point toward the light source.

===============================================================================
*/

//! **************************************************************************
//!              Diffuse Lighting — Step 2 (Light Intensity)
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Diffuse lighting strength is determined by the alignment between the surface
normal and the light direction.

-------------------------------------------------------------------------------
Formula
-------------------------------------------------------------------------------

Intensity

=

dot(N, L)

where

    N = Surface Normal

    L = Light Direction

Both vectors must be normalized.

-------------------------------------------------------------------------------
Meaning
-------------------------------------------------------------------------------

dot = 1

    Maximum illumination

---------------------------------------

dot = 0

    No illumination

---------------------------------------

dot < 0

    Light is behind the surface

-------------------------------------------------------------------------------
Clamping
-------------------------------------------------------------------------------

Negative light intensity has no physical meaning.

Therefore,

    Intensity = max(0, dot(N, L))

-------------------------------------------------------------------------------
Result
-------------------------------------------------------------------------------

The final intensity is always between

    0

and

    1

This value will later scale the light contribution.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

The dot product directly measures how much of the incoming light reaches the
surface.

It becomes the diffuse light intensity after clamping negative values to zero.

===============================================================================
*/
//! **************************************************************************
//!                  Diffuse Lighting — Final Formula
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Diffuse lighting computes the light reflected from a surface according to
Lambert's Cosine Law.

The reflected light depends on:

    • Surface Color

    • Light Color

    • Angle between the Normal and the Light Direction

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

1.

Compute the normalized light direction.

        L = normalize(Light Position - Hit Point)

---------------------------------------

2.

Compute the diffuse intensity.

        intensity = dot(N, L)

---------------------------------------

3.

Clamp negative values.

        intensity = max(0, intensity)

---------------------------------------

4.

Apply the lighting equation.

        Diffuse

        =

        Object Color

        ×

        Light Color

        ×

        intensity

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Diffuse lighting first computes how much light reaches the surface using the
dot product, then scales the object's reflected light by that amount.

===============================================================================
*/

//! **************************************************************************
//!                  Final Lighting Composition
//! **************************************************************************

/*
===============================================================================
CONCEPT
===============================================================================

Each lighting component is computed independently.

The renderer combines these components to produce the final pixel color.

-------------------------------------------------------------------------------
Formula
-------------------------------------------------------------------------------

Final Color

=

Ambient Contribution

+

Diffuse Contribution

-------------------------------------------------------------------------------
Algorithm
-------------------------------------------------------------------------------

Compute Ambient

        ↓

Compute Diffuse

        ↓

Add Both Contributions

        ↓

Final Pixel Color

-------------------------------------------------------------------------------
Architecture
-------------------------------------------------------------------------------

render_ambient()

    Computes only ambient lighting.

---------------------------------------

render_diffuse()

    Computes only diffuse lighting.

---------------------------------------

Renderer

    Combines both contributions into the final color.

-------------------------------------------------------------------------------
Key Idea
-------------------------------------------------------------------------------

Lighting components remain independent.

The renderer is responsible for combining them to obtain the final color
displayed on the screen.

===============================================================================
*/

//! ************************************************************************** //
//!                     Diffuse Brightness Scaling
//! ************************************************************************** //

/*
===============================================================================
CONCEPT
===============================================================================

The Lambert term only describes how much light reaches the surface because
of the angle between the surface normal and the light direction.

It does NOT describe how strong the light source is.

-------------------------------------------------------------------------------
Diffuse Intensity
-------------------------------------------------------------------------------

Diffuse Intensity

=

Lambert

×

Light Brightness

-------------------------------------------------------------------------------
Implementation
-------------------------------------------------------------------------------

intensity = dot(normal, light_direction);

if (intensity < 0.0)
	intensity = 0.0;

intensity *= light->brightness;

-------------------------------------------------------------------------------
Why?
-------------------------------------------------------------------------------

Lambert controls the angle.

Brightness controls the power of the light source.

Both are required to produce the final diffuse illumination.

===============================================================================
*/



