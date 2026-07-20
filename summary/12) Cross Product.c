//! Cross Product
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? In the previous lesson,
      the Dot Product answered:

        "How similar are the directions
         of two Vectors?"

    The Cross Product answers
    a completely different question:

        "Given two Vectors,
         what is the third Vector
         that is perpendicular
         to both of them?"

    # Unlike the Dot Product,
      the Cross Product does NOT
      compare directions.

    # It creates a brand-new Direction.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine a camera.

        Position:

            (0,0,0)

        Look Direction:

            (0,0,-1)

    We know:

        * Where the camera is.

        * Where it is looking.

    But is that enough
    to render an image?

    No.

    Imagine someone says:

        "Move the Ray
         10 pixels to the right."

    How do we know
    where "Right" is?

    We only know:

        * Position

        * Forward Direction

    We still do not know:

        * Right

        * Up

    # The Cross Product helps us
      build these missing directions.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    Think about the world's axes.

             Y (Up)
             ↑
             │
             │
             ●────► X (Right)
            /
           /
          ▼
      Z (Forward)

    Every axis is perpendicular
    to the other two.

    Suppose we already know:

        Forward

    and

        World Up

    What is missing?

        Right.

    There is only one direction
    that is perpendicular
    to both vectors
    (assuming they are not parallel).

    The Cross Product finds
    that direction.

    Conceptually:

        Forward

            +

        World Up

            ↓

      Cross Product

            ↓

          Right

    Once we have Right,
    we can compute
    the camera's real Up vector.

        Right

            +

        Forward

            ↓

      Cross Product

            ↓

        Camera Up

    --------------------------------------------------
    ~ Why is the Result Perpendicular?
     --------------------------------------------------

        Two non-parallel Vectors define
        a Plane.

        The Cross Product does not return
        another Vector inside that Plane.

        Instead, it returns the unique
        Vector that points out of the Plane,
        making it perpendicular to
        both input Vectors.

        Think of placing a sheet of paper
        on a table.

        The paper represents the Plane.

        A pencil standing straight out
        of the paper represents
        the Cross Product.

        # Two Vectors define the Plane.

        # The Cross Product defines
        the direction leaving that Plane.
    
    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

    Camera knows only:

        Forward

    It cannot answer:

        Where is Right?

    The Cross Product creates it.

    ----------------------------------

    Example 2

        Forward

            +

        World Up

            ↓

      Cross Product

            ↓

          Right

    Now the camera knows:

        * Forward

        * Right

    ----------------------------------

    Example 3

        Right

            +

        Forward

            ↓

      Cross Product

            ↓

        Camera Up

    Now the camera has
    a complete coordinate system.

    ----------------------------------

    Example 4

    Consider these two operations:

        right =
        cross(forward, world_up);

    and

        right =
        cross(world_up, forward);

    Are they identical?

    No.

    They point
    in opposite directions.

    One produces:

        Right

    The other produces:

        Left

    This happens because
    the Cross Product
    depends on the order
    of its operands.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Imagine using your right hand.

    This is known as
    the Right-Hand Rule.

    Point:

        Your index finger

    toward the first Vector.

    Point:

        Your middle finger

    toward the second Vector.

    Your thumb indicates
    the Cross Product.

    If you swap
    the first and second Vector,

    your thumb points
    in the opposite direction.

    # Changing the order
      changes the resulting Vector.

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking the Cross Product
      compares two vectors.

    ! Expecting it to return
      a number like the Dot Product.

    ! Forgetting that the order
      of the operands matters.

    ! Assuming World Up
      is always the camera's
      actual Up direction.

    ! Forgetting to normalize
      the resulting Vector
      before using it.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    The Cross Product is essential
    when building the Camera.

    Initially, the camera knows only:

        * Position

        * Forward

    We compute:

        camera.right =
        normalize(
            cross(camera.forward, world_up)
        );

    Then:

        camera.up =
        cross(camera.right,
              camera.forward);

    After these two operations,
    the camera has:

        * Forward

        * Right

        * Up

    These three perpendicular axes
    form the camera's own
    coordinate system.

    This allows the renderer
    to determine:

        * Where the image extends
          to the right.

        * Where it extends upward.

        * How to generate
          one Ray for every Pixel.

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # The Dot Product compares
      two Directions.

    # The Cross Product creates
      a new Direction.

    # The new Vector is always
      perpendicular
      to both input Vectors.

      Dot Product

        ↓

        Vector + Vector

        ↓

        Number

        -------------------------

        Cross Product

        ↓

        Vector + Vector

        ↓

        Vector
    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Cross Product takes:

        Vector + Vector

    and returns:

        A new Vector.

    # The resulting Vector is
      perpendicular to
      both input Vectors.

    # The order matters.

        cross(A, B)

        is NOT the same as

        cross(B, A).

    # The Cross Product
      is used to construct
      the camera's local axes.

    # The camera eventually owns
      its own coordinate system:

        * Forward

        * Right

        * Up

    instead of only:

        Position

        +

        Look Direction.

    # Without the Cross Product,
      the camera would know
      where it is looking,

      but it would never know
      where "Right" or "Up" are.

    # The most important idea
      to remember is:

        Dot Product

            →

        Measures similarity.

        Cross Product

            →

        Generates a new
        perpendicular Direction.

        The Cross Product is not used to create random vectors.
        It is used to build the Camera's local coordinate system.



*/




