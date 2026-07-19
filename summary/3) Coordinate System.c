
//! Coordinate System (3D Coordinate System)
/*
    ? A Coordinate System is a method used to describe the exact position
    ? of every object inside the 3D world.

    * Every object in a scene must have a location.
    * Without a coordinate system, the computer would not know where
      anything exists.

    # A Coordinate System is the "map" of the virtual world.

    --------------------------------------------------
    ~ Why Do We Need Coordinates?
    --------------------------------------------------

    Imagine you are playing Minecraft.

    You tell your friend:

        "Come to my house."

    Your friend immediately asks:

        "Where?"

    If you answer:

        "Somewhere in the world."

    They will never find it.

    We need a precise way to describe locations.

    --------------------------------------------------
    ~ How Do We Describe Locations?
    --------------------------------------------------

    In real life, we usually use:

        * Country
        * City
        * Street
        * House Number

    These pieces of information together describe one location.

    In Computer Graphics...

    We use something much simpler:

        Coordinates

    --------------------------------------------------
    ~ Coordinates in 2D
    --------------------------------------------------

    Imagine a sheet of paper.

               •

    Looking at the point alone tells us nothing.

    We first draw two axes.

              Y
              ↑
              │
              │
              │
    ──────────┼──────────→ X
              │
              │

    Now we can describe the point.

    Example:

        (3, 2)

    Every person looking at this coordinate system
    will understand where the point is located.

    # Coordinates remove ambiguity.

    --------------------------------------------------
    ~ MiniRT Lives in a 3D World
    --------------------------------------------------

    MiniRT is NOT a 2D application.

    The world has depth.

    Therefore we add a third axis.

                 Y
                 ↑
                 │
                 │
                 │
                 │
                 ●────────→ X
                /
               /
              /
             Z

    Now every position is described using:

        (X, Y, Z)

    --------------------------------------------------
    ~ Meaning of Each Axis
    --------------------------------------------------

    ? X Axis

        Moves left and right.

        - ←────────0────────→ +

    --------------------------------------------------

    ? Y Axis

        Moves up and down.

            +
            ↑
            │
            0
            │
            ↓
            -

    --------------------------------------------------

    ? Z Axis

        Represents depth.

        Forward / Backward

              Camera

                 ●

                 │
                 │
                 │

                 Z

    # The exact positive and negative direction of Z
      depends on the coordinate system being used.

    * Some graphics engines use:

        Right-Handed System

    * Others use:

        Left-Handed System

    ! For MiniRT, at this stage,
      you do NOT need to worry about which direction
      is positive or negative.

    # The important idea is:

        Z represents depth.

    * We will study the exact axis directions later
      when building the camera.

    --------------------------------------------------
    ~ Example
    --------------------------------------------------

    Imagine a sphere.

        Sphere

        Position

        (4, 2, -6)

    What does this mean?

    Starting from the origin:

        Move:

            4 units on X

        Then:

            2 units on Y

        Then:

            6 units on Z
            (according to its direction)

    You have reached the sphere's center.

    ! note :
    The position
        (4,2,-6)
        represents one single point
        inside the 3D coordinate system.
        It is NOT a sequence of movements

    --------------------------------------------------
    ~ What is the Origin?
    --------------------------------------------------

    Every coordinate system needs a reference point.

    This point is called:

        Origin

    It is always:

        (0, 0, 0)

    Everything inside the world is measured
    relative to this point.

    Example:

                  Y
                  ↑
                  │
                  │
                  ● Origin (0,0,0)
                 /
                /
               Z

    # The Origin is NOT a special object.

    # It is simply the starting reference for measurements.

    --------------------------------------------------
    ~ Does the Sphere Know It Is at (4,2,-6)?
    --------------------------------------------------

    The answer is:

        No.

    The sphere does NOT know anything.

    The coordinate:

        (4, 2, -6)

    is NOT part of the sphere itself.

    It is simply:

        A description of where the sphere
        exists inside the world.

    # Coordinates describe location.

    # They are not physical parts of the object.

    --------------------------------------------------
    ~ The Computer Only Sees Numbers
    Geometry is simply mathematics
        interpreted visually.
    --------------------------------------------------

    When we look at a scene, we see:

        Sphere

        Camera

        Light

    The computer does NOT.

    Inside memory there are no spheres.

    There are only numbers.

    Example:

        Sphere

        Center

        (2, 5, -8)

        Radius

        3

    ----------------------------------

        Camera

        Position

        (0, 0, 0)

    ----------------------------------

        Light

        Position

        (10, 8, -4)

    # Everything inside the scene
      is represented as numerical data.

    # The renderer transforms these numbers
      into an image.

    --------------------------------------------------
    ~ Why Is This Important?
    --------------------------------------------------

    Almost every operation inside MiniRT
    starts with one simple question:

        "Where is this object?"

    Before we calculate:

        * Rays

        * Shadows

        * Lighting

        * Intersections

    We must first know:

        The object's position.

    Without coordinates...

    Nothing can be rendered.

    --------------------------------------------------
    ~ Relation to the .rt File
    --------------------------------------------------

    Later, while building the parser,
    you will encounter lines like:

        sp 0,0,20 20 255,0,0

    Do not worry about the entire line yet.

    But one thing should immediately be clear.

        0,0,20

    represents:

        The sphere's position
        inside the 3D coordinate system.

    Later you will learn that the remaining values
    describe the sphere's size and color.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

              3D World

                    🌳

          🚗                  🏠

                   ⚽

                     💡

                      📷

    Every object asks the same question:

        "Where am I?"

    The answer is always:

        Position

            ↓

        (X, Y, Z)

    The renderer uses these coordinates
    to build the entire scene.

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # A Coordinate System provides a precise way to describe
      locations inside the world.

    # MiniRT uses a 3D coordinate system.

    # Every position is represented by:

        (X, Y, Z)

    # X controls horizontal movement.

    # Y controls vertical movement.

    # Z represents depth.

    # The Origin is always:

        (0, 0, 0)

    # Every object's position is measured
      relative to the Origin.

    # Coordinates are descriptions of location,
      not properties of the object itself.

    # The computer does not see spheres,
      cameras, or lights.

    # It only sees numerical data that represents them.

    # In the .rt file, values such as:

        0,0,20

      represent an object's position
      inside the 3D world.

    # The single most important idea to remember is:

        Every object in the scene must have a Position,
        and that Position is expressed using coordinates
        inside a three-dimensional Coordinate System.
*/

//! Golden Sentence
/*
    "Every object in a 3D scene is defined by its position
    , and that position is represented using coordinates
     relative to the Origin."
*/


