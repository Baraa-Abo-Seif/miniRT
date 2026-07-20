//! Vector Length (Magnitude)
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? A Vector does not only describe a direction.

    * It also has a size.

    * This size is called:

        Length

        or

        Magnitude

    # Every Vector has two independent properties:

        * Direction

        * Length

    Understanding the difference between them
    is one of the most important ideas in MiniRT.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine two vectors.

        A = (3,4)

        B = (300,400)

    Ask yourself:

        Do they point in the same direction?

    Yes.

    Are they the same length?

    No.

    One vector is much longer than the other.

    This immediately tells us something important.

    # Direction and Length are NOT the same thing.

    A Vector always contains both.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    In 2D, finding the length of a Vector
    is exactly the same as finding
    the hypotenuse of a right triangle.

              ●
              |\
              | \
            y |  \ Length
              |   \
              |    \
        ●-----●
             x

    We use the Pythagorean Theorem.

    Now imagine a 3D Vector.

        (x, y, z)

    At first, it may seem that
    the old idea no longer works.

    But it actually does.

    We simply extend it.

    First:

        Find the distance
        in the XY plane.

    Then:

        Add the Z component
        to create another right triangle.

    Finally:

        Apply the same idea again.

    # 3D does NOT introduce
      a completely new concept.

    # It simply extends
      the same geometric idea
      from 2D into another dimension.

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        A = (3,4)

        B = (300,400)

    They both point
    in exactly the same direction.

    But:

        B is much longer.

    ----------------------------------

    Example 2

        A = (1,1)

        B = (1000,1000)

    Again...

    Both vectors point
    in the same direction.

    Ask yourself:

        If a Ray only needs to know
        where to travel...

    Does it really matter
    whether the arrow is:

        1 unit long?

        1000 units long?

    The answer is:

        No.

    The Ray only needs
    the direction.

    ----------------------------------

    Example 3

    Imagine giving directions
    to a friend.

    Instead of saying:

        "Walk exactly
         1000 meters
         in this direction."

    You simply point:

        "Go this way."

    The direction is important.

    The length of your finger
    is not.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Imagine every Vector
    as an arrow.

    -----------------------------

        →

    A short arrow.

    -----------------------------

        ----------------------->

    A long arrow.

    Both arrows point
    in the same direction.

    The only difference is:

        Their Length.

    Think of every Vector as having:

        Arrow Direction

            +

        Arrow Size

    Those are two completely
    independent properties.

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking that two vectors
      with different lengths
      must have different directions.

    ! Believing that a Ray needs
      a very long Direction Vector.

    ! Mixing the concepts of:

        Direction

        and

        Distance.

    ! Forgetting that Length
      is only one property
      of a Vector.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    During ray tracing,
    a Direction Vector is used to answer:

        "Which way should the Ray travel?"

    It does NOT answer:

        "How far should the Ray travel?"

    The distance traveled by the Ray
    will later be controlled
    by another value:

        t

    Therefore:

        Direction

            and

        Distance

    are kept separate.

    Throughout MiniRT,
    we will frequently transform
    Direction Vectors so that
    they all have the same Length.

    This allows every mathematical formula
    to work with a consistent standard.

    In the next lesson,
    you will learn the operation
    that performs this transformation:

        Normalize

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # A Vector contains
      both Direction and Length.

    # Sometimes we only care
      about the Direction.

    # The Length can be changed
      without changing
      the Direction.
      

    # The actual distance traveled by the Ray
    is NOT stored inside the Direction Vector.

    # The Direction tells the Ray where to go.

    # The value "t" determines how far the Ray travels.


    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Every Vector has:

        * Direction

        * Length (Magnitude)

    # Two vectors can point
      in exactly the same direction
      while having different lengths.

    # A Ray only needs
      the Direction.

    # The distance traveled by the Ray
      is handled separately.

    # Using Direction Vectors
      with a fixed Length
      makes mathematical calculations
      simpler and more consistent.

    # The next important idea is:

        Normalize

    which changes:

        Length

    while preserving:

        Direction.

    # The most important idea to remember is:

        Direction and Length
        are two different properties.

        Changing one
        does not necessarily
        change the other.
*/

