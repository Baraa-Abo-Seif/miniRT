/* ************************************************************************** */
/*                                                                            */
/*                              Unit Vector                                   */
/*                                                                            */
/* ************************************************************************** */

/*
===============================================================================
Introduction
===============================================================================

A Unit Vector is simply a vector whose length is exactly 1.

It is not a different type of vector or a different data structure.
It is simply a regular vector whose length has been adjusted while preserving
its direction.

Relationship:

    Vector
       │
       ▼
 Normalize()
       │
       ▼
 Unit Vector

Normalize  → Operation
Unit Vector → Result


===============================================================================
Why Do We Need It?
===============================================================================

In MiniRT, most vectors represent directions rather than distances.

Example:

    A = (3,4)      Length = 5
    B = (0.6,0.8)  Length = 1

Both vectors point in exactly the same direction.

If a ray only needs to know where to travel, then the vector's length is
irrelevant. Using vectors with a fixed length makes every mathematical
calculation consistent and predictable.


===============================================================================
Core Idea
===============================================================================

Every vector has two independent properties:

• Direction
• Length (Magnitude)

Normalization changes only one property:

    Direction  → Unchanged
    Length     → Becomes 1

After normalization, the resulting vector is called a Unit Vector.

Think of it as:

    Keep the direction.
    Remove the original length.
    Replace it with a standard length of 1.


===============================================================================
Examples
===============================================================================

Example 1

    A = (3,4)
    Length = 5

Result:
    NOT a Unit Vector.


------------------------------------------------------------

Example 2

    B = (0.6,0.8)
    Length = 1

Result:
    Unit Vector.


------------------------------------------------------------

Example 3

Long Arrow

---------------------->

Short Arrow

------>

Both arrows point in the same direction.

Only their lengths are different.

Normalization changes the length only.


===============================================================================
Mental Model
===============================================================================

Imagine a compass.

A compass answers:

    "Which direction should I walk?"

It never answers:

    "How far should I walk?"

A Unit Vector behaves exactly the same way.

It stores direction only.

Distance is handled separately during ray tracing.


===============================================================================
Common Beginner Mistakes
===============================================================================

[1] Thinking Normalize and Unit Vector are different concepts.

    Normalize  → Operation
    Unit Vector → Result


------------------------------------------------------------

[2] Thinking normalization changes the direction.

    Wrong.

    It changes only the length.


------------------------------------------------------------

[3] Believing every vector is a Unit Vector.

    Length = 2
    Length = 5
    Length = 100

These are normal vectors.

Only vectors whose length equals 1 are Unit Vectors.


------------------------------------------------------------

[4] Thinking normalization is necessary so a ray knows where to go.

Wrong.

The ray already knows the direction.

Normalization exists because mathematical formulas become simpler,
cleaner, and more consistent.


===============================================================================
Relation to MiniRT
===============================================================================

Almost every direction vector in MiniRT is expected to be a Unit Vector.

Examples:

    • Ray Direction
    • Camera Forward
    • Camera Right
    • Camera Up
    • Light Direction
    • Surface Normal
    • Reflection Direction

Advantages:

    ✔ Consistent direction vectors
    ✔ Simpler intersection calculations
    ✔ More accurate lighting
    ✔ Ray parameter (t) represents real distance
    ✔ Cleaner mathematical formulas

Typical code:

    ray.direction = normalize(direction);

Meaning:

    "Keep the direction.
     Remove the influence of the vector's length."


===============================================================================
Golden Idea
===============================================================================

Normalize is the process.

Unit Vector is the result.

The direction never changes.

Only the length becomes exactly 1.


===============================================================================
Key Takeaways
===============================================================================

✓ A Unit Vector has a length of exactly 1.

✓ Normalize() produces a Unit Vector.

✓ Normalization changes the length, not the direction.

✓ Direction and magnitude are independent properties.

✓ Every Unit Vector is normalized.

✓ Not every vector is a Unit Vector.

✓ MiniRT relies heavily on Unit Vectors because they make all direction-based
  calculations consistent.


===============================================================================
Summary
===============================================================================

Vector
    ↓
Can have any length

Normalize()
    ↓
Changes the length to 1

Unit Vector
    ↓
Direction only
Length = 1
*/

