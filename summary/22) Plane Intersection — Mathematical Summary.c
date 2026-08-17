//! Plane Intersection — Mathematical Summary
/*

## 1. Plane Representation

Unlike a sphere, a plane is an infinite flat surface.

A plane is completely defined by:

* A point on the plane (`P₀`)
* A normal vector (`N`)

Where:

* `P₀` determines the plane's position.
* `N` determines the plane's orientation.

The normal vector does **not** represent a distance or length.
It only describes the direction perpendicular to the surface.

---

# 2. Vector Inside the Plane

Let:

* `P₀` = a known point on the plane.
* `P` = an unknown point.

The vector connecting them is:

```text
P - P₀
```

If the point `P` lies on the plane, then this vector lies completely inside the plane.

---

# 3. Fundamental Plane Property

Every vector lying on the plane is perpendicular to the plane's normal.

Therefore:

```text
(P - P₀) · N = 0
```

This is the mathematical equation of a plane.

---

# 4. Ray Equation

Every point on a ray is defined as:

```text
P = O + tD
```

Where:

* `O` = ray origin
* `D` = ray direction
* `t` = distance along the ray

---

# 5. Substituting the Ray into the Plane

Replace `P` with the ray equation:

```text
(O + tD - P₀) · N = 0
```

Expand the expression:

```text
((O - P₀) + tD) · N = 0
```

Using the distributive property of the dot product:

```text
(O - P₀) · N + t(D · N) = 0
```

Solve for `t`:

```text
t(D · N) = -(O - P₀) · N
```

Finally:

```text
t = ((P₀ - O) · N) / (D · N)
```

This is the final ray-plane intersection equation.

---

# 6. Meaning of the Denominator

The denominator is:

```text
D · N
```

Its geometric meaning is extremely important.

If:

```text
D · N = 0
```

then the ray direction is perpendicular to the plane's normal.

This means:

* The ray is parallel to the plane.
* No intersection occurs.

Therefore, the denominator must always be checked before computing `t`.

---

# 7. Why We Check the Denominator First

There are two reasons.

### Mathematical reason

A parallel ray never intersects the plane.

### Programming reason

If:

```text
D · N = 0
```

then the intersection formula becomes:

```text
t = (...) / 0
```

which causes division by zero.

The algorithm must immediately return **No Hit**.

---

# 8. Geometric Interpretation

The complete geometric process is:

```text
Plane

↓

Known Point (P₀)

+

Normal (N)

↓

Ray

↓

Find t

↓

Compute Intersection Point

↓

Generate Hit Record
```

---

# Key Concepts

* A plane is defined by one point and one normal.
* The normal describes orientation, not distance.
* Any vector lying on the plane is perpendicular to the normal.
* The plane equation is derived from the dot product.
* A ray is substituted into the plane equation.
* Solving the equation gives the intersection distance `t`.
* The denominator (`D · N`) determines whether an intersection is possible.
* Parallel rays must be rejected before computing `t`.

*/