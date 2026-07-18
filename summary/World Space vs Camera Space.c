//! World Space vs Camera Space
/*
    ? In a 3D scene, every object has a position.
    ? However, that position can be described from different points of view.

    * The two most common ways are:

        - World Space
        - Camera Space

    # These are NOT two different worlds.

    # They are simply two different ways of describing
      the same scene.

    --------------------------------------------------
    ~ Imagine a Simple Scene
    --------------------------------------------------

    We have:

              🌳 Tree

                      ⚽ Sphere

          💡 Light

                  📷 Camera

    Every object has coordinates.

    Example:

        Camera : (0, 0, 0)

        Sphere : (4, 2, -6)

        Light  : (8, 6, -2)

    All of these coordinates exist inside
    the same coordinate system.

    This system is called:

        World Space

    --------------------------------------------------
    ~ What is World Space?
    --------------------------------------------------

    ? World Space is the main coordinate system
      of the entire scene.

    * Every object describes its position
      relative to the World's Origin.

    Example:

        Origin (0,0,0)

              ↓

           Camera

              ↓

           Sphere

              ↓

            Light

              ↓

            Plane

    All of them "live" inside the same world.

    # World Space answers one question:

        "Where is this object inside the world?"

    --------------------------------------------------
    ~ Does the Camera See the World This Way?
    --------------------------------------------------

    The answer is:

        No.

    This is where the important idea begins.

    --------------------------------------------------
    ~ Imagine Yourself Instead of the Camera
    --------------------------------------------------

    Imagine you are standing
    and looking forward.

              🚗 Car

                ↑

               You

    The car is directly in front of you.

    Now...

    Turn around 180 degrees.

        🚗 Car


               You

    Ask yourself:

        Did the car move?

    The answer is:

        No.

    The world stayed exactly the same.

    Then why did the car disappear
    from your view?

    Because:

        Your point of view changed.

    # The world did not change.

    # Your perspective changed.

    --------------------------------------------------
    ~ The Same Idea Applies to the Camera
    --------------------------------------------------

    A camera behaves exactly the same way.

    The objects remain where they are.

    But the camera describes them
    relative to itself.

    Therefore we have two different descriptions.

    --------------------------------------------------
    ~ World Space
    --------------------------------------------------

    World Space answers:

        "Where is the object in the world?"

    Example:

        Sphere

        (4, 2, -6)

    This position never depends
    on where the camera is.

    --------------------------------------------------
    ~ Camera Space
    --------------------------------------------------

    Camera Space answers
    a completely different question.

        "Where is the object
         relative to the camera?"

    This difference is extremely important.

    --------------------------------------------------
    ~ Example 1
    --------------------------------------------------

    World:

        Camera

        (0,0,0)

        Sphere

        (0,0,-5)

    World Space says:

        Sphere = (0,0,-5)

    Camera Space says:

        The sphere is directly
        in front of me.

    Same object.

    Different description.

    --------------------------------------------------
    ~ Example 2
    --------------------------------------------------

    Move the camera.

        Camera

        (10,0,0)

        Sphere

        (0,0,-5)

    Ask yourself:

        Did the sphere move?

    No.

    Did World Space change?

    No.

    Did the camera's view change?

    Yes.

    Why?

    Because the relationship
    between the camera and the sphere
    has changed.

    # The camera is interested in:

        "Where is the sphere
         relative to me?"

    --------------------------------------------------
    ~ A Simple Analogy
    --------------------------------------------------

    Imagine you are inside a car.

    A tree is standing beside the road.

            🌳

    ------------------------ Road

            🚗

    As the car moves...

    Does the tree move?

    No.

    But from inside the car...

    It appears to move.

    The tree stayed still.

    Your frame of reference changed.

    # Camera Space works the same way.

    --------------------------------------------------
    ~ Why Do We Need Camera Space?
    --------------------------------------------------

    Many rendering questions depend
    on the camera's point of view.

    For example:

        * Is the object in front of the camera?

        * Is it behind the camera?

        * Is it inside the Field Of View (FOV)?

        * In which direction should
          a Primary Ray be generated?

    None of these questions can be answered
    using World Space alone.

    --------------------------------------------------
    ~ Do We Move the Objects?
    --------------------------------------------------

    Beginners often misunderstand this idea.

    The answer is:

        No.

    We NEVER move the world
    just to satisfy the camera.

    The objects remain exactly
    where they are.

    What changes is:

        The way we describe them
        relative to the camera.

    You can imagine saying:

        "Pretend the camera
         is now the Origin."

    ! Later you will learn that graphics engines
      achieve this mathematically using
      Transformations (Transforms).

    ! For now, understanding the idea
      is enough.

    --------------------------------------------------
    ~ Final Example
    --------------------------------------------------

    World Space:

        Camera

        (5,0,0)

        Sphere

        (8,0,0)

    Ask the world:

        "Where is the sphere?"

    Answer:

        (8,0,0)

    Now ask the camera:

        "Where is the sphere
         relative to you?"

    Answer:

        (3,0,0)

    Because:

        The sphere is 3 units
        away from the camera
        along the X axis.

    Notice...

    The sphere is exactly the same.

    Only the description changed.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

                  World Space

            🌳        ⚽        💡

                    📷

    Every object asks:

        "Where am I
         inside the world?"

    ----------------------------------

                 Camera Space

                    📷

                     ↓

            🌳        ⚽        💡

    Every object asks:

        "Where am I
         relative to the camera?"

    Same scene.

    Same objects.

    Different point of view.

    --------------------------------------------------
    ~ Why Is This Lesson Important?
    --------------------------------------------------

    In the next lessons you will learn about:

        * Camera Orientation

        * Viewing Direction

        * Field Of View (FOV)

        * Vectors

        * Normalize

        * Cross Product

    At first they may seem unrelated.

    In reality...

    They all help answer one question:

        "How does the camera
         perceive the world?"

    --------------------------------------------------
    ~ The Golden Idea
    --------------------------------------------------

    # World Space describes where objects
      exist relative to the world.

    # Camera Space describes where objects
      exist relative to the camera.

    # There are NOT two worlds.

    # There are NOT two copies of the sphere.

    # They are simply two different descriptions
      of the exact same reality.

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # Every object has one position
      inside the world.

    # World Space is the global coordinate system
      of the scene.

    # Camera Space is the camera's personal view
      of the same scene.

    # Moving the camera does NOT move the world.

    # What changes is the relationship
      between the camera and every object.

    # Camera Space is essential for determining:

        - Whether an object is in front or behind.
        - Whether it is inside the FOV.
        - The direction of Primary Rays.
        - How the scene appears to the viewer.

    # The most important idea to remember is:

        World Space describes objects
        relative to the world.

        Camera Space describes objects
        relative to the camera.

        Same scene.

        Same objects.

        Different reference frame.
*/