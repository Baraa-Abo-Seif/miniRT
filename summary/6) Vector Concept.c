//! Vector Concept
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? Before learning about vectors, we already know how
      to describe the position of objects.

    Example:

        Camera

        (0,0,0)

        Sphere

        (4,2,-6)

    * Both of these are Positions.

    * They tell us where each object exists
      inside the world.

    But a renderer eventually asks a different question.

    Not:

        "Where is the sphere?"

    Instead:

        "How do I reach the sphere?"

    # This question introduces the concept of a Vector.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine someone asks:

        "Where is your house?"

    You answer with an address.

    Now imagine the same person
    is standing next to you and asks:

        "How do I get there?"

    Would you repeat the address?

    No.

    You would give directions such as:

        * Go forward.
        * Turn right.
        * Walk a little farther.

    Notice the difference.

    The first question asks:

        "Where is it?"

    The second asks:

        "How do I reach it?"

    # Positions answer "Where?"

    # Vectors answer "How do I move?"

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    Suppose we have:

        Camera

        (0,0,0)

        Sphere

        (4,2,-6)

    The camera's position tells us:

        "The camera is here."

    The sphere's position tells us:

        "The sphere is there."

    But the ray does not care
    where the sphere is in the world.

    The ray wants to know:

        "Which direction should I travel?"

    This is NOT a position.

    It is a movement.

    Or more precisely:

        A Displacement.

    A Vector describes:

        * Direction
        * Movement
        * Displacement

    It does NOT describe
    the location of an object.

    Therefore we have two completely different concepts.

        Point

            ↓

        Describes Location

    -----------------------------

        Vector

            ↓

        Describes Movement

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        Camera

        (0,0)

        Treasure

        (5,3)

    Does:

        (5,3)

    tell the player how to move?

    No.

    It only tells where
    the treasure exists.

    The movement instructions are:

        Move 5 units to the right.

        Move 3 units upward.

    Those instructions are the Vector.

    ! Notice:
        These are instructions.
        Not a destination.

    ----------------------------------

    Example 2

        Camera

        (2,1,0)

        Sphere

        (2,6,0)

    Compare each axis.

        X : 2 → 2

            No movement.

        Y : 1 → 6

            Move upward.

        Z : 0 → 0

            No movement.

    Only one axis changed.

    Therefore the movement is:

        Upward.

    ----------------------------------

    Example 3

        Camera

        (3,4,2)

        Sphere

        (8,4,2)

    Compare the coordinates.

        X : 3 → 8

            Changed.

        Y : 4 → 4

            Same.

        Z : 2 → 2

            Same.

    The required movement is:

        To the right.

    Again...

    We are NOT describing
    where the sphere is.

    We are describing
    how to reach it.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Think of a Point as a destination.

                🏠

            "It is here."

    Think of a Vector as the path
    you must follow.

            →

            →

            →

            🏠

    The Point says:

        "This is the destination."

    The Vector says:

        "Move like this."

    Another way to remember it:

        Point

            =

        Location / Destination

    -----------------------------

        Vector

            =

        Movement / Direction to follow / Required movement

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking that a Point and a Vector
      are the same thing.

    ! Assuming that an object's Position
      tells a ray how to move.

    ! Believing that a Vector represents
      a location inside the world.

    ! Forgetting that changing the camera's
      position changes the Vector needed
      to reach the same object.

    ! Treating a Direction as if it were
      another Position.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    One of the first formulas
    you encountered was:

        Ray

            =

        Origin

            +

        Direction

    Now you can understand it better.

        Origin

            →

        Point

        (Starting Position)

    -----------------------------

        Direction

            →

        Vector

        (Movement Direction)

    The ray begins at a Point,
    then travels using a Vector.

    Without the Direction Vector,

    the ray would have
    a starting point,

    but it would never know
    where to go.
    

    Later in MiniRT,
    vectors will be used for:

        * Primary Ray generation

        * Camera Orientation

        * Ray/Object intersections

        * Lighting calculations

        * Reflection

        * Normal vectors

    Understanding the meaning of a Vector
    is essential before learning
    any vector mathematics.


    --------------------------------------------------
    ~ Point vs Vector
    --------------------------------------------------

    Point

        Exists by itself.

        Example:

            Sphere Position

            (4,2,-6)

    ----------------------------------

    Vector

        Cannot exist alone.

        It always represents
        the movement from one Point
        to another Point.

    ----------------------------------

    Changing the camera

            ↓

    Changes the Vector

    ----------------------------------

    Moving the sphere

            ↓

    Changes both:

        Position

        and

        Vector


    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # A Point describes where something is.

    # A Vector describes how to move
      from one Point to another.

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Point = Location.

    # Vector = Direction / Movement / Displacement.

    # A Position tells us where an object exists.

    # A Vector tells us how to travel
      toward another location.

    # A Ray is built from:

        Origin

            →

        Point

        +

        Direction

            →

        Vector

    # A Vector is NOT an object
      inside the world.

    # A Vector is a relationship
      between two Points.

    # The most important idea to remember is:

        A Point answers:

            "Where is it?"

        A Vector answers:

            "How do I get there?"
*/


