# 42 Project

> **MiniRT Roadmap**
>
> Learning first. Understanding before coding.
>
> Goal:
>
> Build MiniRT from scratch while understanding every mathematical,
> architectural, and rendering concept behind it.

---

# Project Principles

The project follows a small set of engineering principles that should never
be broken during development.

- Understand before implementing.
- Design before coding.
- One responsibility per module.
- Low Coupling.
- High Cohesion.
- Explicit Memory Ownership.
- Every module should be independently testable.
- Every function should exist for a clear reason.
- Keep the architecture stable once validated.

---

# Overall Progress

```text
MiniRT
│
├── ✅ Milestone 0 (Foundations)
│
├── ✅ Core Math Library
│
├── ✅ Milestone 1 (Architecture)
│
├── ⏳ Milestone 2 (Core Engine Foundation)
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
| ✅ Milestone 0 — Foundations | 🟢 Completed | **100%** |
| ✅ Core Math Library | 🟢 Completed | **100%** |
| ✅ Milestone 1 — Architecture | 🟢 Completed | **100%** |
| Milestone 2 — Core Engine Foundation | ⬜ | **0%** |
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
| Core Engine Foundation | ~2 Days |
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

All mathematical foundations required for MiniRT have been completed.

Future concepts will only be introduced naturally during implementation.

---

# Overall Project Progress

```text
██████████████░░░░░░░░░░░░░░

≈ 45%
```
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

## Goal

Build a complete vector mathematics library before integrating it into MiniRT.

Every function must be fully understood, manually implemented, and tested
before becoming part of the renderer.

---

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

---

## Validation

Every function has been manually tested using:

- Normal cases
- Edge cases
- Zero vectors
- Parallel vectors
- Orthogonal vectors
- Reflection validation
- Cross Product validation
- Distance validation

The library is considered stable and production-ready.

---

# Milestone 1 — Architecture

**Status:** ✅ Completed

**Estimated Time:** ~4 Days

## Goal

Design the complete MiniRT architecture before writing the renderer.

Before writing a single project file, the complete project architecture
should be drawable from memory.

---

## Topics

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

---

## Completed Architecture

The following components have been fully designed.

### Project Layout

- ✅ Folder hierarchy
- ✅ Module separation
- ✅ Header organization

### Scene Architecture

- ✅ Scene
- ✅ Camera
- ✅ Ambient
- ✅ Lights
- ✅ Objects

### Object Architecture

- ✅ Generic Object
- ✅ Sphere
- ✅ Plane
- ✅ Cylinder

### Renderer Architecture

- ✅ Renderer
- ✅ Intersector
- ✅ Hit Record
- ✅ Lighting Pipeline

### Ownership Model

- ✅ Scene Ownership
- ✅ Object Ownership
- ✅ Memory Allocation Strategy
- ✅ Create / Destroy Flow

### Execution Flow

```text
main()

↓

Create Scene

↓

Parse Scene

↓

Initialize Camera

↓

Renderer

↓

Generate Rays

↓

Intersections

↓

Lighting

↓

Write Pixels

↓

Cleanup
```

---

## Deliverables

By the end of this milestone the following were completed:

- ✅ Final Folder Hierarchy
- ✅ Module Responsibilities
- ✅ Scene Design
- ✅ Camera Design
- ✅ Object Design
- ✅ Hit Record Design
- ✅ Data Flow
- ✅ Memory Flow
- ✅ Ownership Model
- ✅ Rendering Pipeline
- ✅ Architecture Validation

Milestone 1 is considered complete.

---

# Milestone 2 — Core Engine Foundation

**Status:** ⏳

**Estimated Time:** ~2 Days

## Goal

Start building the real MiniRT engine using the architecture designed during
Milestone 1.

The objective is no longer mathematics.

The objective is building the project foundation.

---

## Topics

```text
Scene Creation

Scene Destroy

Camera Initialization

Object Initialization

Ambient Initialization

Light Initialization

Linked List Utilities

Color Library

Project Integration

Memory Ownership

Public API

Compilation

Header Organization
```

---

## Expected Deliverables

- Scene Create
- Scene Destroy
- Camera Initialization
- Object Creation
- Color Library
- Linked List Utilities
- Stable Foundation for Parser

# Milestone 3 — Parser + MLX

**Status:** ⏳

**Estimated Time:** ~5 Days

## Goal

Build the complete scene loader and initialize the graphical environment.

The parser should transform a `.rt` file into a fully initialized `Scene`
ready for rendering.

The MLX module should provide image creation and pixel drawing without
knowing anything about ray tracing.

---

## Topics

```text
File Reading

Lexer

Tokenizer

Validation

Parser

Scene Builder

Error Handling

MLX Initialization

Window Creation

Image Buffer

Pixel Drawing

Scene Loading
```

---

## Expected Deliverables

- Read `.rt` file
- Parse Camera
- Parse Ambient
- Parse Lights
- Parse Objects
- Build Scene
- Initialize MLX
- Create Image Buffer
- Draw Single Pixel
- Display Window

---

# Milestone 4 — Camera System

**Status:** ⏳

**Estimated Time:** ~3 Days

## Goal

Build a complete camera capable of generating rays correctly.

The camera becomes an independent module responsible only for generating
primary rays.

---

## Topics

```text
Camera Position

Forward Vector

Right Vector

Up Vector

Camera Basis

Aspect Ratio

Viewport Width

Viewport Height

Camera Plane

Pixel Size

Camera Initialization
```

---

## Expected Deliverables

- Camera Initialization
- Camera Basis Computation
- Viewport Computation
- Camera Ready For Rendering

---

# Milestone 5 — Ray Generation

**Status:** ⏳

**Estimated Time:** ~1 Day

## Goal

Generate one primary ray for every screen pixel.

---

## Topics

```text
Primary Rays

Pixel Center

Normalized Device Coordinates (NDC)

Viewport Coordinates

World Coordinates

Perspective Projection

Ray Equation
```

---

## Expected Deliverables

```text
Pixel

↓

Generate Ray

↓

Return Ray
```

One ray should be generated for every rendered pixel.

---

# Milestone 6 — Intersections

**Status:** ⏳

**Estimated Time:** ~5 Days

## Goal

Detect intersections between rays and scene objects.

The Intersector module should remain completely independent from the
Renderer.

---

## Mandatory Objects

```text
Sphere

Plane

Cylinder
```

---

## Topics

```text
Ray-Sphere

Ray-Plane

Ray-Cylinder

Nearest Hit

Discard Negative t

Intersection Dispatcher

Hit Record Construction
```

---

## Expected Deliverables

```text
Ray

↓

Check Objects

↓

Nearest Hit

↓

Hit Record
```

The output of this module is always a complete Hit Record.

---

# Milestone 7 — Lighting

**Status:** ⏳

**Estimated Time:** ~3 Days

## Goal

Compute the final color of every visible surface.

---

## Topics

```text
Ambient

Diffuse

Specular

Surface Normal

View Direction

Reflection Direction

Shadow Rays

Light Attenuation

Color Accumulation

Shading Pipeline
```

---

## Expected Deliverables

```text
Hit Record

+

Lights

↓

Final Color
```

---

# Milestone 8 — Rendering

**Status:** ⏳

**Estimated Time:** ~2 Days

## Goal

Combine every subsystem into one rendering pipeline.

---

## Rendering Pipeline

```text
Scene

↓

Camera

↓

Generate Ray

↓

Intersections

↓

Nearest Hit

↓

Lighting

↓

Final Color

↓

Write Pixel

↓

Display Image
```

---

## Expected Deliverables

- First rendered image
- Complete rendering loop
- Stable rendering pipeline

---

# Milestone 9 — Bonus Integration

**Status:** ⏳

**Estimated Time:** ~4 Days

## Goal

Extend the renderer without changing its architecture.

Since the project was designed with modularity in mind, Bonus should become
feature integration rather than project rewriting.

---

## Possible Features

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

**Status:** ⏳

**Estimated Time:** ~2 Days

## Goal

Finalize the project.

---

## Topics

```text
Memory Leaks

Segmentation Faults

Norminette

Performance

Code Cleanup

Final Review
```

---
---

# Knowledge Map

This roadmap is not only a project tracker.

It is also a map of the knowledge acquired during the development of MiniRT.

## Completed

### Mathematics

- Point & Vector Mathematics
- Vector Operations
- Dot Product
- Cross Product
- Reflection
- Normalization
- Distance
- Ray Equation
- Sphere Equation
- Plane Equation
- Camera Mathematics
- Perspective Projection
- Camera Fundamentals

### Software Architecture

- Module Separation
- Project Structure
- Folder Hierarchy
- Scene Architecture
- Camera Design
- Object Design
- Hit Record Design
- Rendering Pipeline
- Data Flow
- Memory Ownership
- Execution Flow

---

## Remaining Knowledge

### Parsing

- File Parsing
- Validation
- Scene Construction

### Computer Graphics

- Camera Implementation
- Primary Rays
- Ray/Object Intersections
- Lighting Models
- Rendering Loop

### Graphics Programming

- MLX
- Image Buffer
- Window Management

### Optimization

- Performance
- Memory Optimisation
- Code Quality

---

# MiniRT Execution Flow

```text
main()

↓

Create Scene

↓

Parse Scene

↓

Initialize Camera

↓

Initialize Renderer

↓

Render Loop

    ↓

Generate Primary Ray

    ↓

Find Nearest Intersection

    ↓

Build Hit Record

    ↓

Compute Lighting

    ↓

Compute Final Colour

    ↓

Write Pixel

↓

Display Image

↓

Cleanup

↓

Exit
```

---

# Folder Architecture

```text
MINIRT/

├── intersector/
├── math/
│   ├── color/
│   └── vector/
│
├── mlx/
├── parser/
├── renderer/
│
├── scene/
│   ├── ambient/
│   ├── camera/
│   ├── lights/
│   └── objects/
│       ├── sphere/
│       ├── plane/
│       └── cylinder/
│
├── utils/
├── summary/
│
├── main.c
├── minirt.h
├── README.md
└── Makefile
```

---

# Philosophy

The project follows one strict rule:

> **Understand first. Implement second.**

Every equation is derived before it is coded.

Every module is designed before it is implemented.

Every ownership decision is understood before memory is allocated.

Every rendering step is understood before writing a single pixel.

The objective is not simply to finish MiniRT.

The objective is to understand why every line of code exists.

---

# Final Goal

Finish MiniRT while fully understanding:

- Mathematics
- Geometry
- Linear Algebra
- Ray Tracing
- Computer Graphics
- Project Architecture
- Software Engineering
- Memory Management
- Rendering Pipeline
- Modular Design

The goal is not only to complete the project.

The goal is to become capable of rebuilding a ray tracer from scratch
without relying on tutorials or external implementations.

---

# Roadmap Status

```text
██████████████░░░░░░░░░░░░░░

Completed ≈ 45%

Current Stage:

→ Milestone 2 — Core Engine Foundation
```
