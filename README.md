# 42 Project

> **MiniRT Roadmap**
>
> Learning first. Understanding before coding.
>
> Goal: Build MiniRT from scratch while understanding every mathematical and architectural concept behind it.

---

# Overall Progress

```text
MiniRT
│
├── ✅ Milestone 0 (Foundations)
│
├── ⏳ Math Exercises
│
├── ⏳ Milestone 1 (Architecture)
│
├── ⏳ Milestone 2 (Math Library)
│
├── ⏳ Milestone 3 (Parser + MLX)
│
├── ⏳ Milestone 4 (Camera System)
│
├── ⏳ Milestone 5 (Ray Generation)
│
├── ⏳ Milestone 6 (Intersections)
│
├── ⏳ Milestone 7 (Lighting)
│
├── ⏳ Milestone 8 (Rendering)
│
├── ⏳ Milestone 9 (Optimization)
│
└── ⏳ Milestone 10 (Bonus Integration)
```

---

# Progress

| Stage | Status | Progress |
|--------|--------|---------:|
| ✅ Milestone 0 (Foundations) | 🟢 In Progress | **95%** |
| Math Exercises | ⬜ | **0%** |
| Architecture | ⬜ | **0%** |
| Math Library | ⬜ | **0%** |
| Parser + MLX | ⬜ | **0%** |
| Camera System | ⬜ | **0%** |
| Ray Generation | ⬜ | **0%** |
| Intersections | ⬜ | **0%** |
| Lighting | ⬜ | **0%** |
| Rendering | ⬜ | **0%** |
| Bonus Integration | ⬜ | **0%** |
| Debug & Optimization | ⬜ | **0%** |

---

# Estimated Timeline

| Stage | Estimated Time |
|--------|---------------:|
| Finish Milestone 0 | ~ Half Day |
| Math Exercises | 1 Day |
| Architecture | 4 Days |
| Math Library | 1–2 Days |
| Parser + MLX | 5 Days |
| Camera System | 3 Days |
| Ray Generation | 1 Day |
| Intersections | 5 Days |
| Lighting | 3 Days |
| Rendering | 2 Days |
| Bonus Integration | 4 Days |
| Debug & Optimization | 2 Days |

---

# Remaining Theory

Only a few concepts remain before finishing the theoretical foundation.

```text
⏳ Ray Equation

⏳ Sphere Equation

⏳ Plane Equation

⏳ Camera Plane

⏳ Perspective Projection

⏳ Field Of View (FOV)

⏳ Final Mental Model
```

After these lessons, **Milestone 0 will be complete.**

---

# Milestone 0 — Foundations

## Mathematics

- ✅ Point
- ✅ Position
- ✅ Vector
- ✅ Vector Representation
- ✅ Point vs Vector
- ✅ Vector From Two Points
- ✅ Vector Length (Magnitude)
- ✅ Normalize
- ✅ Unit Vector
- ✅ Dot Product
- ✅ Cross Product

Remaining:

- ⏳ Ray Equation
- ⏳ Sphere Equation
- ⏳ Plane Equation
- ⏳ Camera Plane
- ⏳ Perspective Projection
- ⏳ Field Of View
- ⏳ Final Review

---

# Math Exercises

**Duration:** ~1 Day

Purpose:

Become comfortable with vector mathematics before entering the real project.

These exercises are **not part of MiniRT**.

We will implement:

```c
vec_add();

vec_sub();

vec_scale();

vec_dot();

vec_cross();

vec_length();

normalize();
```

After this stage, vector math should become second nature.

---

# Milestone 1 — Architecture

**Duration:** ~4 Days

Goal:

Design the entire project before writing the renderer.

Topics:

```text
Folders

Headers

Structures

Modules

Ownership

Memory Flow

Data Flow

Initialization

Destroy

Project Layout

Dependencies

Initialization Order

Rendering Flow
```

At the end of this milestone, the complete project architecture should be clear.

---

# Milestone 2 — Math Library

**Duration:** 1–2 Days

The first real code inside MiniRT.

Functions:

```c
vec_add();

vec_sub();

vec_scale();

vec_dot();

vec_cross();

vec_length();

normalize();

color_add();

color_scale();

color_clamp();
```

This library will be used everywhere else.

---

# Milestone 3 — Parser + MLX

**Duration:** ~5 Days

Topics:

```text
Lexer

Tokenizer

Split

Validation

Parser

Scene Builder

Error Handling

MLX Initialization

Window

Image Buffer

Pixel Drawing

Scene Loading
```

The parser will be designed with Bonus support from the beginning.

---

# Milestone 4 — Camera System

**Duration:** ~3 Days

Topics:

```text
Camera

Forward

Right

Up

Viewport

Camera Plane

Camera Basis

Camera Initialization
```

The camera becomes a complete local coordinate system.

---

# Milestone 5 — Ray Generation

**Duration:** ~1 Day

Topics:

```text
Primary Rays

Pixel Coordinates

Viewport Mapping

Perspective Projection

Ray Equation

Generate One Ray Per Pixel
```

This is where the real ray tracing begins.

---

# Milestone 6 — Intersections

**Duration:** ~5 Days

Mandatory Objects:

```text
Sphere

Plane

Cylinder
```

Possible Bonus Extensions:

```text
Cone

Triangle

Cube
```

---

# Milestone 7 — Lighting

**Duration:** ~3 Days

Topics:

```text
Ambient

Diffuse

Specular

Shadow Rays

Light Attenuation (if needed)
```

---

# Milestone 8 — Rendering

**Duration:** ~2 Days

Everything comes together.

Pipeline:

```text
Scene

↓

Camera

↓

Generate Rays

↓

Intersections

↓

Lighting

↓

Image Output
```

The first complete rendered image will be produced here.

---

# Milestone 9 — Bonus Integration

**Duration:** ~4 Days

Since the project is designed for extensibility from the beginning, Bonus becomes feature integration instead of rewriting.

Possible additions:

```text
Multiple Lights

Checkerboard

Camera Movement

Object Selection

Advanced Parsing

Reflection

Soft Shadows
```

---

# Milestone 10 — Debug & Optimization

**Duration:** ~2 Days

Final polishing:

```text
Memory Leaks

Segmentation Faults

Norminette

Performance

Code Cleanup

Final Review
```

---

# Overall Project Progress

```text
███████░░░░░░░░░░░░░░░░░░░░░░

≈ 22%
```

---

# Goal

Finish MiniRT while fully understanding:

- Mathematics
- Ray Tracing
- Computer Graphics
- Project Architecture

Rather than simply making the project work.

The objective is not only to complete the project, but to understand every line of code that will be written.

