
//! Ray Tracing
/*
    ? Ray Tracing is a rendering technique used to generate realistic images by
    ? simulating the visible effects of light

    * Instead of simply drawing triangles or objects on the screen,
    * Ray Tracing asks a simple question for every pixel:
        "If I look through this pixel, what object do I see?"

    * The answer determines:
        - The pixel color
        - Shadows
        - Reflections
        - Refractions
        - Lighting
        - Visibility

    # Ray Tracing does NOT simulate every photon in the universe.
    # It only computes the rays necessary to produce the final image.

    --------------------------------------------------
    ~ Basic Components of a Ray Tracer
    --------------------------------------------------

    * Camera
        - Represents the viewer.
        - Generates viewing rays.

    * Screen (Image Plane)
        - A grid of pixels.
        - Every pixel represents one viewing direction.

    * Ray
        - An imaginary mathematical line.
        - Starts from the camera.
        - Travels into the scene.

    * Objects
        - Sphere
        - Plane
        - Cylinder
        - etc.

    * Light Sources
        - Point light
        - Directional light

    * Materials
        - Define how objects interact with light.
        - Examples:
            - Matte
            - Reflective
            - Transparent

    --------------------------------------------------
    ~ What is a Ray?
    --------------------------------------------------

    ? A ray is simply:

        Origin
            +
        Direction

    * Origin:
        The point where the ray starts.

    * Direction:
        The direction in which the ray travels.

    * Example:

            Camera
               ●
                \
                 \
                  \
                   --------->

    # The ray itself has no color.
    # It is only used to search for objects.

    --------------------------------------------------
    ~ Why do we cast rays FROM the camera?
    --------------------------------------------------

    ? At first glance it seems more logical to emit rays from lights,
      because light physically travels from lamps to objects.

    * In reality:
        Light indeed travels:

            Light
               ↓
            Object
               ↓
            Camera

    * However...

    --------------------------------------------------
    ~ If We Shoot Rays From the Light
    --------------------------------------------------

    Imagine:

            Light
              ●
             /|\
            / | \
           /  |  \
         Millions of rays

    * Most rays will:
        - Fly into empty space.
        - Never reach the camera.
        - Never contribute to the final image.

    * Therefore:

        Millions (or billions) of calculations
        ↓
        Almost all are wasted.

    # This is extremely inefficient.

    --------------------------------------------------
    ~ If We Shoot Rays From the Camera
    --------------------------------------------------

    Imagine a monitor:

        +-------------+
        |             |
        |   Pixels    |
        |             |
        +-------------+

    Every pixel asks:

        "What am I looking at?"

    So:

        Pixel (0,0)
            ↓
        Shoot one ray

        Pixel (0,1)
            ↓
        Shoot one ray

        Pixel (0,2)
            ↓
        Shoot one ray

    ...

    Every pixel receives exactly one primary ray
    (or more when anti-aliasing is enabled).

    # Every ray contributes directly to the final image.

    --------------------------------------------------
    ~ Reverse Ray Tracing
    --------------------------------------------------

    ? Ray Tracing actually performs the reverse of real light transport.

    Real World

        Light
            ↓
        Object
            ↓
        Eye

    Ray Tracer

        Eye (Camera)
            ↓
        Object
            ↓
        Light

    * This technique is called:

        Backward Ray Tracing

    * It produces the same visible result while avoiding billions
      of unnecessary calculations.

    --------------------------------------------------
    ~ How does the program determine ONE pixel color?
    --------------------------------------------------

    Suppose we want to compute:

            Pixel (350, 120)

    The program performs the following steps.

    --------------------------------------------------
     ~ Step 1 : Generate Primary Ray
    --------------------------------------------------

        Pixel
        ↓

        Generate Ray

        ↓

        Camera + Pixel coordinate

        ↓

        Direction

    * Compute the direction from the camera
      through the center of the pixel.

    Result:

        Ray(camera_position, direction)

    --------------------------------------------------
    ~ Step 2 : Find Intersections
    --------------------------------------------------

    The ray is tested against ALL scene objects.

    Example:

        Ray
         \
          \
           \
          Sphere
             X

    * Every object performs its own intersection test.

    Examples:

        Sphere
            -> Solve sphere equation

        Plane
            -> Solve plane equation

        Triangle
            -> Solve triangle intersection

    --------------------------------------------------
    ~ Step 3 : Find the Closest Object
    --------------------------------------------------

    A ray may intersect:

        Sphere

        then

        Plane

        then

        Wall

    We only keep:

        The closest intersection.

    Because:

        The first object blocks everything behind it.

    # Only the nearest visible object matters.

    --------------------------------------------------
    ~ Step 4 : Compute Surface Information
    --------------------------------------------------

    Once we know the hit point:

        We compute:

        * Hit position

        * Surface normal

        * Material

        * Texture (optional)

    Example:

        Hit Point

             ●

        Normal

             ↑

    --------------------------------------------------
    ~ Step 5 : Check Every Light
    --------------------------------------------------

    For each light source:

        Compute:

        * Direction to light

        * Distance

        * Intensity

    Example:

        Light
          ●
          |
          |
          |
         Hit

    --------------------------------------------------
    ~ Step 6 : Shadow Test
    --------------------------------------------------

    Before adding light:

    Another ray is shot:

        Hit Point
            ↓
        Light

    This is called:

        Shadow Ray

    If another object blocks it:

        Shadow

    Otherwise:

        Light reaches the surface.

    --------------------------------------------------
    ~ Step 7 : Compute Lighting
    --------------------------------------------------

    The final color is influenced by:

        Ambient

        +

        Diffuse

        +

        Specular

        +

        Reflection (optional)

        +

        Refraction (optional)

    The resulting RGB value becomes:

        Pixel Color

    --------------------------------------------------
    ~ What if the ray hits nothing?
    --------------------------------------------------

    Then:

        No object exists in that direction.

    The pixel becomes:

        * Background color

        OR

        * Skybox color

    --------------------------------------------------
    ~ General Program Execution Flow
    --------------------------------------------------

    ? From program launch until the image appears:

    1.

        Start Program

            ↓

    2.

        Initialize Window

            ↓

    3.

        Load Scene

            ↓

    4.

        Create Camera

            ↓

    5.

        Create Objects

            ↓

    6.

        Create Lights

            ↓

    7.

        For each pixel

            ↓

        Generate Ray

            ↓
        
        Hit Test

            ↓

        Find Closest Object

            ↓

        Compute Hit Information

            ↓

        Check Shadows

            ↓

        Compute Lighting

            ↓

        Store RGB Color

    8.

        After all pixels are computed

            ↓

        Draw the image to the screen

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

                Program Starts
                      │
                      ▼
                Load Scene
                      │
                      ▼
               Create Camera
                      │
                      ▼
            Loop Over Every Pixel
                      │
                      ▼
             Generate Primary Ray
                      │
                      ▼
          Does the ray hit an object?
                 │            │
               Yes            No
                │              │
                ▼              ▼
      Compute Surface      Background
            │
            ▼
      Check Every Light
            │
            ▼
      Shadow Test
            │
            ▼
     Compute Final Color
            │
            ▼
      Store Pixel Color
            │
            ▼
      Next Pixel
            │
            ▼
      Display Image

    --------------------------------------------------
    ~ Why is Ray Tracing considered realistic?
    --------------------------------------------------

    * Because it models the physical behavior of light.

    * Every visible pixel is the result of:
        - Geometry
        - Visibility
        - Lighting
        - Material interaction

    * This naturally produces:
        - Accurate shadows
        - Reflections
        - Refractions
        - Global illumination (advanced implementations)

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Ray Tracing determines the color of every pixel independently.

    # One primary ray is usually generated for each pixel.

    # Rays start from the camera because every generated ray contributes
      directly to the final image.

    # The closest intersected object is always the visible one.

    # Lighting is computed only after an intersection is found.

    # Shadow rays determine whether light actually reaches the surface.

    # If no object is hit, the background color is used.

    # The complete rendering process is essentially:
        Camera
            →
        Ray
            →
        Intersection
            →
        Lighting
            →
        Pixel Color
    
    # Renderer
        ? "Renderer is a function that determines the color of every pixel."
*/

