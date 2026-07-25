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
├── ✅ Core Math Library
│
├── ⏳ Milestone 1 (Architecture)
│
├── ⏳ Milestone 2 (Project Math Integration)
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
├── ⏳ Milestone 9 (Bonus Integration)
│
└── ⏳ Milestone 10 (Debug & Optimization)
```

---

# Progress

| Stage | Status | Progress |
|--------|--------|---------:|
| ✅ Milestone 0 (Foundations) | 🟢 Completed | **100%** |
| ✅ Core Math Library | 🟢 Completed | **100%** |
| Milestone 1 — Architecture | ⬜ | **0%** |
| Milestone 2 — Project Math Integration | ⬜ | **0%** |
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
| Milestone 1 — Architecture | ~4 Days |
| Project Math Integration | ~1 Day |
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

All mathematical foundations required to begin the implementation phase have been completed.

Future concepts will be introduced only when they naturally appear during implementation.

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

# Core Math Library

**Status:** ✅ Completed

## Implemented

```c
vec_add();

vec_sub();

vec_scale();

vec_length();

normalize();

vec_dot();

vec_cross();

vec_distance();

vec_reflect();
```

## Validation

Every function has been tested manually using:

- Normal cases
- Edge cases
- Orthogonal vectors
- Zero vectors
- Reflection tests
- Distance tests
- Cross product validation

The library is considered stable and ready to be integrated into MiniRT.

---

# Milestone 1 — Architecture

**Estimated Time:** ~4 Days

## Goal

Design the complete project before writing the renderer.

Topics

```text
Folders

Headers

Modules

Structures

Ownership

Memory Flow

Data Flow

Initialization

Destroy

Project Layout

Dependencies

Execution Pipeline

Initialization Order

Rendering Flow

Error Propagation

Build System

Makefile Organization

Library Organization
```

At the end of this milestone, the complete architecture of MiniRT should be finalized before implementing any rendering logic.

---

# Milestone 2 — Project Math Integration

**Estimated Time:** ~1 Day

Goal

Integrate the already-tested math library into the MiniRT project.

Topics

```text
Folder Organization

Header Organization

Compilation

Public API

Static Functions

Color Library

color_add()

color_scale()

color_clamp()

Integration with Project
```

---

# Milestone 3 — Parser + MLX

**Estimated Time:** ~5 Days

Topics

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

Parser will be designed with Bonus support from the beginning.

---

# Milestone 4 — Camera System

**Estimated Time:** ~3 Days

Topics

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

---

# Milestone 5 — Ray Generation

**Estimated Time:** ~1 Day

Topics

```text
Primary Rays

Pixel Center

Normalized Device Coordinates

Viewport Coordinates

World Coordinates

Perspective Projection

Ray Equation

Generate One Ray Per Pixel
```

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

Topics

```text
Ambient

Diffuse

Specular

Surface Normal

View Direction

Reflection Direction

Shadow Rays

Light Attenuation
```

---

# Milestone 8 — Rendering

**Estimated Time:** ~2 Days

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

---

# Milestone 9 — Bonus Integration

**Estimated Time:** ~4 Days

Possible additions

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

Topics

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
███████████░░░░░░░░░░░░░░░░░

≈ 35%
```

---

# Philosophy

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

