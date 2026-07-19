//! Camera Orientation (Look Direction)
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? Until now, we described a camera using only one property:

        Camera
            ↓
        Position

    * However, this is NOT enough.

    * A camera must answer two different questions:

        1. Where am I?
        2. Where am I looking?

    # A camera is defined by both its Position
      and its Look Direction.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine two cameras.

    Camera A

        Position

        (0,0,0)

    Camera B

        Position

        (0,0,0)

    Both cameras occupy exactly the same position.

    But...

    Camera A looks forward.

            →

    Camera B looks upward.

            ↑

    Ask yourself:

        Will both cameras see the same image?

    The answer is:

        No.

    Even though they share the same position,
    they observe completely different parts
    of the world.

    # Position tells us where the camera is.

    # Look Direction tells us what the camera sees.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    Think about yourself standing
    in the middle of a room.

    Your position never changes.

    First...

    You look at the door.

            🚪

             👤

    Then...

    You turn your head
    toward the window.

            🪟

             👤

    Then...

    You look at the ceiling.

            ⬆

             👤

    Ask yourself:

        Did you move?

    No.

    Did the room change?

    No.

    Did what you see change?

    Yes.

    Why?

    Because your head rotated.

    Your position remained the same,
    but your viewing direction changed.

    The camera behaves exactly the same way.

    A camera has:

        Position

            +
        
        Look Direction

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        Camera Position

        (0,0,0)

        Look Direction

        (0,0,-1)

    Meaning:

        The camera is looking forward.

        Position

            ↓

        Unchanged


        Look Direction

            ↓

        Changed

    ----------------------------------

    Example 2

        Camera Position

        (0,0,0)

        Look Direction

        (1,0,0)

    Meaning:

        The camera is looking to the right.

    ----------------------------------

    Example 3

        Camera Position

        (0,0,0)

        Look Direction

        (0,1,0)

    Meaning:

        The camera is looking upward.

    ----------------------------------

    Notice something important.

    The Position never changed.

    Only the Look Direction changed.

    That single change is enough
    to produce a completely different image.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Think of the camera as a person.
    
    A person can stand still
    while changing only
    their viewing direction.

                    👤

                Position

    Position answers:

        "Where am I standing?"

    ----------------------------------

                    👀

             Look Direction

    Look Direction answers:

        "Where am I looking?"

    The final camera is therefore:

        Camera

            =

        Position

            +

        Look Direction

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking that Position alone
      completely defines a camera.

    ! Believing that moving the camera
      and rotating the camera
      are the same operation.

    ! Confusing Position with Look Direction.

    ! Assuming that two cameras
      at the same position
      always produce the same image.

    ! Forgetting that changing only the
      Look Direction changes the entire view.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    In the .rt scene file,
    the camera is described like this:

        C 0,0,0 0,0,-1 70

        Notice:
            The Look Direction is NOT
            a target point.

            It is a direction vector
            that tells the camera
            where to look.


    At this point, you should already recognize:

        0,0,0

            →

        Camera Position

    ----------------------------------

        0,0,-1

            →

        Camera Look Direction

    ----------------------------------

        70

            →

        Camera Field Of View (FOV)

    ! The FOV will be explained
      in a separate lesson.

    During rendering,
    the camera uses:

        Position

            +

        Look Direction

    to generate the correct Primary Ray
    for every pixel.

    This concept will later be connected with:

        * Camera Space

        * Viewport

        * Ray Generation

        * Vectors

        * Normalize

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # A camera is NOT defined
      only by where it is.

    # A camera is defined by:

        Position

            +

        Look Direction

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Every camera has a Position.

    # Every camera also has a Look Direction.

    # Two cameras can share the same Position
      while producing completely different images.

    # Changing the Look Direction changes
      what the camera sees,
      even if the Position never changes.

    # In MiniRT, the camera description includes:

        Position

            +

        Look Direction

            +

        Field Of View (FOV)

    # The most important idea to remember is:

        Camera

            =

        Position

            +

        Look Direction
*/

