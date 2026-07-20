//! Dot Product
/*
    --------------------------------------------------
    ~ Introduction
    --------------------------------------------------

    ? The Dot Product is one of the most important
      concepts in the theoretical part of MiniRT.

    Many people introduce it as:

        A · B = AxBx + AyBy + AzBz

    and immediately ask you to memorize it.

    We will not.

    Instead, we begin with one simple question:

        "How similar are the directions
         of two Vectors?"

    # The Dot Product is not about Positions.

    # It is not about Distance.

    # It is about comparing Directions.

    --------------------------------------------------
    ~ Why do we need it?
    --------------------------------------------------

    Imagine holding a flashlight.

    -----------------------------

    Case 1

        🔦 --------> █

    The flashlight points directly
    toward the wall.

    Result:

        Maximum light reaches the wall.

    -----------------------------

    Case 2

             ↗
        🔦
               █

    The flashlight is tilted.

    Result:

        Less light reaches the wall.

    -----------------------------

    Case 3

        🔦 -------->

        ██████████

    The flashlight is parallel
    to the wall.

    Result:

        Almost no light reaches
        the front face.

    -----------------------------

    Case 4

        █ <-------- 🔦

    The flashlight points
    in the opposite direction.

    Result:

        No light reaches
        the visible face.

    Notice something important.

    Nothing changed except:

        The angle between
        the flashlight direction
        and the wall.

    # The Dot Product measures
      this relationship.

    --------------------------------------------------
    ~ Core Idea
    --------------------------------------------------

    The Dot Product answers
    one simple question:

        "How much does one Vector
         point in the same direction
         as another Vector?"

    Think of this scale:

        <-----------|----------->
            -1       0         +1

    +1

        Same direction.

    -----------------------------

    0

        Perpendicular (90°).

    -----------------------------

    -1

        Opposite directions.

    When two normalized vectors
    point more closely together,

    the Dot Product becomes larger.

    When they point farther apart,

    the Dot Product becomes smaller.

    --------------------------------------------------
    ~ Examples
    --------------------------------------------------

    Example 1

        A = (1,0,0)

        B = (1,0,0)

    Compare each component:

        X

            1 × 1 = 1

        Y

            0 × 0 = 0

        Z

            0 × 0 = 0

    Sum:

        1 + 0 + 0 = 1

    Result:

        Dot Product = 1

    Meaning:

        Both vectors point
        in exactly the same direction.

    ----------------------------------

    Example 2

        A = (1,0,0)

        B = (0,1,0)

    Compare each component:

        X

            1 × 0 = 0

        Y

            0 × 1 = 0

        Z

            0 × 0 = 0

    Sum:

        0 + 0 + 0 = 0

    Result:

        Dot Product = 0

    Meaning:

        The vectors are perpendicular.

    ----------------------------------

    Example 3

    Imagine a sphere.

               📷
                │
                │
                ●
             ◯ Sphere

    The arrow pointing outward
    from the surface is called:

        Normal Vector

    Now add a light source.

             💡
               ↘
                 \
                  ●
               ◯ Sphere

    We now have two directions:

        * Light Direction

        * Surface Normal

    The Dot Product compares them.

    If they point in nearly
    the same direction,

    the surface receives
    strong illumination.

    If they differ greatly,

    the lighting becomes weaker.

    If they point
    in opposite directions,

    the surface receives
    no direct light.

    --------------------------------------------------
    ~ Mental Model
    --------------------------------------------------

    Imagine two arrows.

        →

        →

    Almost identical.

    Result:

        Large Dot Product.

    -----------------------------

        →

        ↗

    Similar.

    Result:

        Medium Dot Product.

    -----------------------------

        →

        ↑

    Perpendicular.

    Result:

        Zero.

    -----------------------------

        →

        ←

    Opposite.

    Result:

        Negative.

    Think of the Dot Product
    as a similarity meter
    for Directions.

    --------------------------------------------------
    ~ Common Beginner Mistakes
    --------------------------------------------------

    ! Thinking the Dot Product
      measures distance.

    ! Believing it compares Positions.

    ! Memorizing the formula
      without understanding
      what the result means.

    ! Forgetting that the interpretation

        +1

        0

        -1

      assumes normalized vectors.

    ! Treating the Dot Product
      as "just another equation."

    --------------------------------------------------
    ~ Relation to MiniRT
    --------------------------------------------------

    Lighting in MiniRT
    is fundamentally based on
    comparing two directions:

        * Light Direction

        * Surface Normal

    We compute:

        intensity = dot(normal, light_dir);

    Suppose:

        intensity = 0.87

    This means:

        The light direction
        is very close
        to the Normal.

    Therefore:

        The surface receives
        strong illumination.

    If:

        intensity ≈ 0

    The light arrives
    almost perpendicular
    to the surface.

    Lighting becomes very weak.

    If:

        intensity < 0

    The light is behind the surface.

    The visible face
    receives no direct light.

    The Dot Product is used repeatedly
    in MiniRT for:

        * Diffuse Lighting

        * Reflection calculations

        * Visibility tests

        * Angle comparisons

    --------------------------------------------------
    ~ Golden Idea
    --------------------------------------------------

    # The Dot Product is NOT
      just a mathematical operation.

    # It is a way to convert
      the relationship between
      two Directions

      into

      a single number.

    That number tells us
    how similar those directions are.

    --------------------------------------------------
    ~ Key Takeaways
    --------------------------------------------------

    # The Dot Product compares
      two Direction Vectors.

    # It answers:

        "How much do these vectors
         point in the same direction?"

    # For normalized vectors:

        +1

            Same direction.

        0

            Perpendicular.

        -1

            Opposite directions.

    # The computer cannot understand
      concepts like:

        →

        ↗

        ↑

    It only understands numbers.

    The Dot Product converts
    directional similarity
    into a numerical value.

    # Lighting in MiniRT
      is simply the comparison
      between:

        Light Direction

            and

        Surface Normal.

    # The closer the Light Direction
      is to the Normal,

      the stronger the illumination.

    # The most important idea
      to remember is:

        The Dot Product does not ask:

            "Where is the object?"

        It asks:

            "How similar are
             these two directions?"
*/

