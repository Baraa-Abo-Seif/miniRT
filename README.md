# 42 Project

> **MiniRT Roadmap**
>
> Learning first. Understanding before coding.
>
> Goal: Build MiniRT from scratch while understanding every mathematical,
> architectural, and rendering concept behind it.

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
| ✅ Milestone 0 (Foundations) | 🟢 Completed | **100%** |
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
| Math Exercises | ~1 Day |
| Architecture | ~4 Days |
| Math Library | 1–2 Days |
| Parser + MLX | ~5 Days |
| Camera System | ~3 Days |
| Ray Generation | ~1 Day |
| Intersections | ~5 Days |
| Lighting | ~3 Days |
| Rendering | ~2 Days |
| Bonus Integration | ~4 Days |
| Debug & Optimization | ~2 Days |

---

# Theoretical Foundations

✅ Completed

The remaining concepts will be introduced naturally during implementation
whenever they become necessary.

---

# Milestone 0 — Foundations

## Mathematics

Completed Topics

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
- ✅ Ray Equation
- ✅ Sphere Equation
- ✅ Plane Equation
- ✅ Camera Plane
- ✅ Field Of View (FOV)
- ✅ Perspective Projection
- ✅ Camera Fundamentals

---

# Math Exercises

**Estimated Time:** ~1 Day

## Goal

Build confidence writing vector mathematics before using it inside MiniRT.

This stage focuses only on implementation.

No new theory is introduced.

Functions to implement:

```c
vec_add();

vec_sub();

vec_scale();

vec_dot();

vec_cross();

vec_length();

vec_distance();

normalize();

vec_reflect();
```

After this stage, vector mathematics should become second nature.

---

# Milestone 1 — Architecture

**Estimated Time:** ~4 Days

## Goal

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

Object Ownership

Execution Pipeline

Error Propagation
```

At the end of this milestone, the complete project architecture should be
clear before writing any rendering code.

---

# Milestone 2 — Math Library

**Estimated Time:** 1–2 Days

The first real MiniRT code.

Functions:

```c
vec_add();

vec_sub();

vec_scale();

vec_dot();

vec_cross();

vec_length();

vec_distance();

normalize();

vec_reflect();

color_add();

color_scale();

color_clamp();
```

This library becomes the mathematical foundation of the renderer.

---

# Milestone 3 — Parser + MLX

**Estimated Time:** ~5 Days

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

**Estimated Time:** ~3 Days

Topics:

```text
Camera

Forward

Right

Up

Camera Basis

Viewport

Camera Plane

Aspect Ratio

Viewport Size

Pixel Size

Camera Initialization
```

The camera becomes a complete local coordinate system.

---

# Milestone 5 — Ray Generation

**Estimated Time:** ~1 Day

Topics:

```text
Primary Rays

Pixel Center

Normalized Device Coordinates (NDC)

Viewport Coordinates

World Coordinates

Perspective Projection

Ray Equation

Generate One Ray Per Pixel
```

This is where real ray tracing begins.

---

# Milestone 6 — Intersections

**Estimated Time:** ~5 Days

Mandatory Objects

```text
Sphere

Plane

Cylinder
```

Core Concepts

```text
Nearest Hit

Discard Negative t

Hit Record
```

Possible Bonus Objects

```text
Cone

Triangle

Cube
```

---

# Milestone 7 — Lighting

**Estimated Time:** ~3 Days

Topics:

```text
Ambient

Diffuse

Specular

Surface Normal

View Direction

Reflection Direction

Shadow Rays

Light Attenuation (if needed)
```

---

# Milestone 8 — Rendering

**Estimated Time:** ~2 Days

Everything comes together.

Pipeline

```text
Scene

↓

Camera

↓

Generate Rays

↓

Intersections

↓

Nearest Hit

↓

Surface Normal

↓

Lighting

↓

Final Color

↓

Image Output
```

The first complete rendered image will be produced here.

---

# Milestone 9 — Bonus Integration

**Estimated Time:** ~4 Days

Since the project is designed for extensibility from the beginning,
Bonus becomes feature integration rather than rewriting.

Possible additions:

```text
Multiple Lights

Checkerboard

Reflection

Soft Shadows

Camera Movement

Object Selection

Advanced Parsing
```

---

# Milestone 10 — Debug & Optimization

**Estimated Time:** ~2 Days

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
████████░░░░░░░░░░░░░░░░░░░░

≈ 27%
```

---

# Philosophy

The project follows one strict rule:

> **Understand first. Implement second.**

Every equation is derived before it is coded.

Every module is designed before it is implemented.

The objective is not simply to finish MiniRT,
but to understand why every line of code exists.

---

# Final Goal

Finish MiniRT while fully understanding:

- Mathematics
- Geometry
- Ray Tracing
- Computer Graphics
- Project Architecture
- Memory Management
- Rendering Pipeline

The objective is not only to complete the project,
but to understand every line of code that will be written.
