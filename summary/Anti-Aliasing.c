//! How a 2D Screen Transforms into a 3D World
/*
    ? One of the most confusing ideas in Ray Tracing is:
        "How can a flat 2D screen display a 3D world?"

    * The answer is surprisingly simple.
    * The screen itself is NOT three-dimensional.
    * Instead, every pixel on the screen looks into the 3D world from a
      different direction.

    # The renderer does not draw the world directly.
    # It asks every pixel:
        "What do you see?"

    --------------------------------------------------
    ~ Imagine Standing in Front of a Window
    --------------------------------------------------

    Imagine you are inside a room.

    In front of you is a window.

    Outside the window there are:

        🌳 Tree
        🚗 Car
        🏠 House

    The scene looks like:

                 🌳

          🚗             🏠


    ========================
           Window
    ========================

              👤
            Camera

    * The window represents the screen.

    * The world exists outside.

    * The camera is inside the room.

    --------------------------------------------------
    ~ Does the Camera See Everything?
    --------------------------------------------------

    ? Does the camera instantly know everything in the scene?

    The answer is:

        No.

    * The camera only sees the world THROUGH the window.

    * Anything outside the camera's field of view
      is simply invisible.

    # The screen acts like a viewing window into the world.

    --------------------------------------------------
    ~ The Screen is Made of Pixels
    --------------------------------------------------

    Imagine a very small screen.

    Instead of:

        1920 × 1080 Pixels

    Imagine:

        5 × 5 Pixels

    +---+---+---+---+---+
    |   |   |   |   |   |
    +---+---+---+---+---+
    |   |   |   |   |   |
    +---+---+---+---+---+
    |   |   | X |   |   |
    +---+---+---+---+---+
    |   |   |   |   |   |
    +---+---+---+---+---+
    |   |   |   |   |   |
    +---+---+---+---+---+

    We select only ONE pixel.

    Now we ask:

        "What do you see?"

! complte form here
    --------------------------------------------------
    ~ How Does a Pixel Answer?
    --------------------------------------------------

    A pixel cannot answer by itself.

    It needs to "look" into the world.

    Therefore we draw an imaginary line.

    From:

        Camera

    To:

        The center of the selected pixel.

                     Pixel

                     □

                    /

                   /

                  /

                 ● Camera

    This imaginary line is called:

        Primary Ray

    # Every visible pixel begins with one Primary Ray.

    --------------------------------------------------
    ~ Why Do We Aim at the Center of the Pixel?
    --------------------------------------------------

    ? Why not use:

        - The corner?
        - The edge?
        - A random point?

    Because every pixel must have:

        One stable representative point.

    The best choice is:

        The center.

    * This guarantees consistency.

    * Every pixel always represents the same viewing direction.

    # In the mandatory version of MiniRT:

        One Pixel
            ↓
        One Center
            ↓
        One Primary Ray

    ! Later, advanced techniques such as Anti-Aliasing
      shoot multiple rays inside the same pixel
      to improve image quality.

    ! That is NOT part of the mandatory project.

    --------------------------------------------------
    ~ Now Imagine the Entire Screen
    --------------------------------------------------

    Instead of one pixel...

    We now have thousands.

    □□□□□□□□□□□□□□□□□□□□□□
    □□□□□□□□□□□□□□□□□□□□□□
    □□□□□□□□□□□□□□□□□□□□□□
    □□□□□□□□□□□□□□□□□□□□□□
    □□□□□□□□□□□□□□□□□□□□□□

    Every single pixel asks:

        "What do I see?"

    Therefore...

    Every pixel generates its own ray.

    The result looks like:

    □□□□□□□□□□□□□□

      \   |   /   \   |   /

       \  |  /     \  |  /

        \ | /       \ | /

         \|/

          ● Camera

    # The camera does NOT emit one ray.

    # It emits one ray for every pixel.

    --------------------------------------------------
    ~ Do All Rays Travel in the Same Direction?
    --------------------------------------------------

    The answer is:

        No.

    If every ray had the same direction...

        Every pixel would observe exactly the same point.

    Which means:

        Every pixel would receive the same color.

    And the final image would become:

        One single flat color.

    Instead...

    Every pixel has its own direction.

    Example:

        Upper Pixel

              /

    Camera ●

        Middle Pixel

    ---------------->

        Lower Pixel

              \

    Because every direction is different...

    Every pixel observes a different part of the world.

    --------------------------------------------------
    ~ What is the Camera's Real Job?
    --------------------------------------------------

    Many beginners think the camera:

        Draws objects.

    It does NOT.

    They think the camera:

        Calculates colors.

    It does NOT.

    They think the camera:

        Knows what a sphere is.

    It does NOT.

    The camera has only ONE responsibility:

        Generate the correct direction
        for every Primary Ray.

    # This is the most important idea in this lesson.

    --------------------------------------------------
    ~ What Does Every Pixel Produce?
    --------------------------------------------------

    Notice the sequence:

        Camera

            ↓

        Pixel

            ↓

        Direction

    NOT:

        Camera

            ↓

        Pixel

            ↓

        Color

    # A pixel does NOT immediately produce a color.

    # It first produces a viewing direction.

    * The color will only be calculated later,
      after the ray interacts with the scene.

    --------------------------------------------------
    ~ General Rendering Logic
    --------------------------------------------------

    The renderer can be imagined like this:

    For Every Pixel

            ↓

    Compute Ray Direction

            ↓

    Create Primary Ray

            ↓

    Search for the Closest Object

            ↓

    Compute the Color

            ↓

    Paint the Pixel

    Then...

    Repeat for the next pixel.

    # This loop is the heart of every Ray Tracer.

    --------------------------------------------------
    ~ Why Is This Lesson Important?
    --------------------------------------------------

    Everything that comes later depends on this idea.

    Later you will learn:

        * Vectors

        * Normalize

        * Camera Orientation

        * Field Of View (FOV)

        * Dot Product

        * Cross Product

    At first these concepts may seem unrelated.

    In reality...

    They all exist for one purpose:

        To calculate the correct direction
        of the Primary Ray for every pixel.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

                 3D World

          🌳        🚗        🏠

    ==================================
               Screen
    ==================================

      □ □ □ □ □
      □ □ □ □ □
      □ □ □ □ □
      □ □ □ □ □
      □ □ □ □ □

       \ | / \ | /
        \|/   \|/
          ● Camera

    Every Pixel

        ↓

    Generates

        ↓

    One Direction

        ↓

    One Primary Ray

        ↓

    One View of the World

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # The screen is a flat window looking into a 3D world.

    # The camera does not see everything at once.

    # Every pixel independently asks:
        "What do I see?"

    # To answer that question, one Primary Ray is generated.

    # The ray starts at the camera and passes through the
      center of the pixel.

    # The center is chosen because every pixel must have
      one stable representative point.

    # Every pixel generates a different ray direction.

    # Different directions allow different pixels to see
      different parts of the scene.

    # The camera does NOT calculate colors.

    # The camera's only responsibility is generating the
      correct direction for each Primary Ray.

    # Every rendering algorithm ultimately follows:

        Camera
            ↓
        Pixel
            ↓
        Direction
            ↓
        Ray
            ↓
        Intersection
            ↓
        Color
            ↓
        Draw Pixel
*/