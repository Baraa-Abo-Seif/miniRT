//! How Do We Get a Vector From Two Points?
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? We already know the difference between a Point and a Vector.

        Point

            →

        Describes a Location.

    -----------------------------

        Vector

            →

        Describes a Movement.

    * The next question is:

        "Where does a Vector come from?"

    * A Vector is not created from a single Point.

    # A Vector is created by comparing two Points.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine we have:

        Camera

        (0,0,0)

        Sphere

        (5,2,-3)

    We want to shoot a Ray
    from the Camera to the Sphere.

    Ask yourself:

        Is knowing the Camera Position enough?

    No.

    Is knowing only the Sphere Position enough?

    No.

    To know how to travel,
    we must know:

        * Where we start.

        * Where we want to go.

    # Movement always requires
      both a Start Point and an End Point.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    Imagine standing at:

        A

    and wanting to reach:

        B

    The important question is NOT:

        "Where is A?"

    Or:

        "Where is B?"

    The important question is:

        "How do I move from A to B?"

    To answer that question,
    we compare both positions.

    We compare each axis separately.

    The result tells us:

        * Which direction to move.

        * How much to move.

    This movement is the Vector.

    A Vector is therefore
    the displacement from:

        Start

            →

        Destination

    # Always think:

        "How do I go from here
         to there?"

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        A = (2,3)

        B = (7,8)

    Looking only at X:

        2

            →

        7

    We move:

        5 units to the right.

    Looking only at Y:

        3

            →

        8

    We move:

        5 units upward.

    ----------------------------------

    Example 2

        A = (10,4)

        B = (7,8)

    Compare X:

        10

            →

        7

    Movement:

        3 units to the left.

    Compare Y:

        4

            →

        8

    Movement:

        4 units upward.

    The computer cannot store:

        Left

        Up

    Instead it stores numbers.

    Therefore the movement becomes:

        movement.x = -3

        movement.y = +4

    Positive values represent movement
    in the positive axis direction.

    Negative values represent movement
    in the opposite direction.

    ----------------------------------

    Example 3

    Imagine you want directions
    to a university.

    Knowing only:

        University Address

    is not enough.

    You must also know:

        Your current location.

    Only then can someone tell you
    how to reach your destination.

    A Vector works exactly the same way.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

            Start Point

                  ●

                  │

                  │

                  ▼

                  ●

            Destination

    The Vector is NOT
    either of these Points.

    The Vector is the movement
    connecting them.

    Another way to imagine it:

        Point A

            ↓

        "I am here."

    -----------------------------

        Point B

            ↓

        "I want to go there."

    -----------------------------

        Vector

            ↓

        "Move like this."

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking that a Vector can be created
      from only one Point.

    ! Believing that the destination alone
      defines the movement.

    ! Forgetting that movement always depends
      on both the Start and the Destination.

    ! Memorizing the formula without
      understanding its meaning.

    ! Thinking:

        Start → End

      and

        End → Start

      produce the same Vector.

      They do not.

      They point in opposite directions.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    This idea is used everywhere
    in MiniRT.

    When generating a Primary Ray:

        Direction

            =

        Pixel - Camera

       ! (Destination - Start)

    ----------------------------------

    When computing lighting:

        Light Direction

            =

        Light

            →

        Hit Point

        (Destination - Start)

    ----------------------------------

    When computing the viewing direction:

        View Direction

            =

        Camera

            →

        Hit Point

        (Destination - Start)

    Notice something important.

    The logic never changes.

    Only the Points change.

    Throughout the entire project,
    we repeatedly ask:

        "How do I go
         from this Point
         to that Point?"

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # A Vector is obtained by comparing
      two Points.

    # Always think:

        Destination

            →

        Start

    # In other words:

        ! Vector = End - Start

    This is not just a formula.

    It is the way we think about movement.

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # A Vector cannot exist
      without two Points.

    # One Point represents the Start.

    # One Point represents the Destination.

    # A Vector describes the movement
      needed to reach the Destination.

    # The computer stores that movement
      as numerical values.

    # Positive values indicate movement
      in the positive axis direction.

    # Negative values indicate movement
      in the opposite direction.

    # Always think:

        "How do I go
         from here
         to there?"

    # Never memorize:

       !  Vector = End - Start

      without understanding that it means:

        Movement from the Start Point
        toward the Destination.

    # The most important idea to remember is:

        Almost every Vector used in MiniRT
        is created by asking:

        "How do I move
         from one Point
         to another?"
*/




