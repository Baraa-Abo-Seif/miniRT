//! How Does a Computer Represent a Vector?
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? The goal of this lesson is NOT to learn vector mathematics.

    ? The goal is to understand how a computer stores
      a Vector in memory.

    * Before thinking about vectors,
      remember one important rule:

    # A computer does not understand concepts like
      "Sphere", "Camera", or "Movement".

    # It only understands data.

    And data is simply:

        Numbers.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine you are creating a simple game.

    Your character is standing at:

        (2,3)

    Now you want to tell the character:

        * Move 5 units to the right.
        * Move 2 units upward.

    Ask yourself:

        How would a computer store
        this movement?

    Would it save:

        "Move Right"

        "Move Up"

    Of course not.

    Text is unnecessary.

    The computer simply stores
    the numerical values describing
    the movement.

    Example:

        Right  → 5

        Up     → 2

    The movement becomes:

        (5,2)

    # Computers represent movement using numbers,
      not words.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    Suppose the required movement is:

        * No movement on X.
        * Move 3 units upward.
        * Move 4 units forward.

    The computer stores:

        (0,3,4)

    Nothing more.

    It does not store:

        "Forward"

        "Up"

        "Movement"

    It simply stores three values:

        x

        y

        z

    Later, in C,
    this becomes something like:

        t_vec3
        {
            ...
        }

    The structure stores only:
        x
        y
        z
        Nothing else.

    A Vector is therefore represented
    as three numerical components:

        (x, y, z)

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        Movement

            Right : 5

            Up    : 2

    Stored as:

        (5,2)

    ----------------------------------

    Example 2

        Movement

            X : 0

            Y : 3

            Z : 4

    Stored as:

        (0,3,4)

    ----------------------------------

    Example 3

        typedef struct s_vec3
        {
            double x;
            double y;
            double z;
        } t_vec3;

    This structure simply stores:

        x

        y

        z

    It does NOT know
    what those values represent.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Imagine opening the computer's memory.

    You see:

        x = 1

        y = 2

        z = 3

    That's all.

    The computer does NOT see:

        Position

        Direction

        Normal

        Movement

    It only sees three numbers.

    The meaning comes later.

    From the programmer.

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking that a Vector has
      a special memory layout.

    ! Believing that the computer knows
      whether values represent
      a Position or a Direction.

    ! Assuming that Position and Vector
      require different structures.

    ! Forgetting that identical data
      can represent completely different concepts.

    ! Thinking that changing the variable name
        changes the stored data.

        The memory remains identical.

        Only the meaning changes.

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    In MiniRT,
    we will commonly use one structure:

        typedef struct s_vec3
        {
            double x;
            double y;
            double z;
        } t_vec3;

    This same structure will store:

        * Position

        * Direction

        * Normal

        * Movement

        * Camera Orientation

    Sometimes even other quantities
    in graphics engines.

    We do NOT create a different structure
    for every concept.

    The data layout is identical.

    Only the meaning changes.

    This is why almost every mathematical
    operation in MiniRT receives t_vec3
    as its input.


    --------------------------------------------------
    ~ Same Data, Different Meaning
    --------------------------------------------------

    Suppose memory contains:

        (1,2,3)

    Can we know whether it is:

        Position?

        Direction?

        Normal?

    The answer is:

        No.

    The numbers never tell us
    their meaning.

    Only the context does.

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # A computer stores a Vector
      exactly the same way
      it stores a Point.

    # The difference is NOT the data.

    # The difference is the meaning.

    # The memory is identical.

    # The interpretation is different.

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # A Vector is stored as:

        (x, y, z)

    # A Point is also stored as:

        (x, y, z)

    # Their memory representation
      is identical.

    # The computer cannot determine
      whether:

        (4,2,-6)

      is a Point or a Vector.

    # The meaning depends entirely
      on the context.

    Example:

        t_vec3 position = {1,2,3};

    Here:

        (1,2,3)

    represents:

        A Position.

    ----------------------------------

        t_vec3 direction = {1,2,3};

    The same values now represent:

        A Direction.

    ----------------------------------

        t_vec3 normal = {1,2,3};

    The same values now represent:

        A Surface Normal.

    # The computer always sees:

        x = 1

        y = 2

        z = 3

    # The programmer gives
      those numbers their meaning.

    # A Point answers:

        "Where is it?"

    # A Vector answers:

        "How do I move?"

    # A Position should never be used
      directly as a Direction.

    # A Vector is obtained from the
      relationship between two Points,
      not from a single Point.

    # The most important idea to remember is:

        Data and Meaning are different.

        The data may be identical,

        but its meaning depends entirely
        on how you use it.
*/



