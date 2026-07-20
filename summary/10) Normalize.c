//! Normalization
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? In the previous lesson,
      we learned that every Vector has:

        * Direction

        * Length (Magnitude)

    Sometimes, however,
    the Length is not important.

    We only care about
    the Direction.

    This is where
    Normalization comes in.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine two vectors:

        A = (3,4)

        Length = 5

    and

        B = (300,400)

        Length = 500

    Ask yourself:

        Do they point
        in different directions?

    No.

    They point in exactly
    the same direction.

    The only difference
    is their Length.

    Now imagine a Ray.

    Does the Ray care whether
    the Direction Vector is:

        Length = 5

        or

        Length = 500

    No.

    The Ray only needs
    to know which way to travel.

    # Keeping different lengths
      only makes calculations
      more complicated.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    Instead of allowing Direction Vectors
    to have random lengths like:

        5

        50

        500

        8000

    we convert them all
    into a common standard.

    Every Direction Vector
    will always have:

        Length = 1

    while keeping exactly
    the same Direction.

    This process is called:

        Normalization

    # Normalization changes
      the Length.

    # It never changes
      the Direction.

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        (3,4)

        Length = 5

    After normalization:

        Same Direction

        New Length = 1

    ----------------------------------

    Example 2

        (300,400)

        Length = 500

    After normalization:

        Same Direction

        New Length = 1

    Notice that both vectors
    become identical in Direction.

    Only their Length changes.

    ----------------------------------

    Example 3

    Imagine an arrow.

    A very long arrow:

    ----------------------------->

    and a short arrow:

            →

    If both arrows point
    in the same direction,

    then shortening the arrow
    does not change
    where it points.

    It only changes
    its size.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Imagine asking yourself:

        "This arrow is
         8 units long.

         I want it to become
         exactly 1 unit long."

    What should you do?

    You simply shrink it.

    The arrow still points
    in the same direction.

    It simply becomes
    a standard-sized arrow.

    Think of Normalization as:

        Removing the Length

    while preserving:

        The Direction.

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking that normalization
      changes the Direction.

    ! Memorizing the formula
      without understanding
      why it works.

    ! Believing that longer vectors
      are "better" Direction Vectors.

    ! Forgetting that Direction
      and Length
      are independent properties.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    In MiniRT,
    almost every Direction Vector
    must be normalized.

    Before creating a Ray:

        ray.direction

    should represent:

        Direction only.

    Not:

        Direction + Random Length.

    This guarantees that
    every mathematical operation
    behaves consistently.

    Later,
    normalized vectors will be used in:

        * Ray Intersections

        * Lighting

        * Shadows

        * Reflections

        * Refractions

    A common step in MiniRT is:

        ray.direction = normalize(direction);

    This means:

        "Keep the Direction,
         remove the influence
         of the Length."

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # Normalization does NOT
      change where a Vector points.

    # It only changes
      how long the Vector is.

    # After normalization,
      every Direction Vector
      has:

        Length = 1

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Different vectors
      can have the same Direction
      but different Lengths.

    # Rays care about Direction,
      not Vector Length.

    # Using Direction Vectors
      with a fixed Length
      makes calculations
      simpler, cleaner,
      and more predictable.

    # Instead of remembering:

       ! Normalize = Vector / Length

    Think logically:

        "If an arrow is too long
         and I want it to become
         exactly one unit long,

         I simply scale it down."

    The formula comes naturally
    from this idea.

    # The most important idea
      to remember is:

        Normalization removes
        the influence of Length,

        leaving only
        the pure Direction.
*/



