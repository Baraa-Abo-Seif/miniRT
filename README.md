# MiniRT — 42 Project

> **Learning Roadmap**
>
> Build MiniRT from scratch while understanding every mathematical,
> architectural, and rendering concept behind it.
>
> **Philosophy**
>
> Understand first.
>
> Design second.
>
> Implement last.

---

# Project Vision

MiniRT is not treated as a simple graphics project.

It is treated as a complete software engineering project whose objective is
to understand every layer involved in building a ray tracer.

The project is divided into independent milestones.

Each milestone introduces only the concepts required for the next stage.

Nothing is implemented before it is fully understood.

# Project Principles

The following principles define the architecture of this project.

Every design decision made during development should respect these rules.

---

## Learning Principles

- Understand before implementing.
- Design before coding.
- Derive every equation before writing it.
- Never copy code without understanding it.
- Every concept should be introduced only when it becomes necessary.

---

## Software Engineering Principles

- One responsibility per module.
- High Cohesion.
- Low Coupling.
- Explicit Memory Ownership.
- Stable Public APIs.
- Predictable execution flow.
- Deterministic behaviour whenever possible.

---

## Code Principles

- Every function should exist for one clear reason.
- Avoid hidden side effects.
- Prefer simplicity over cleverness.
- Keep modules independently testable.
- Avoid unnecessary allocations.
- Separate data from behaviour whenever possible.

---

## Architecture Rules

The following rules were established during Milestone 1 and Milestone 2.

These rules should not be broken during future implementation.

### Rule #1

Geometry never owns colour.

### Rule #2

Renderer never allocates permanent memory.

### Rule #3

Every allocation has exactly one owner.

### Rule #4

Modules communicate only through their public interface.

### Rule #5

Scene owns the world.

### Rule #6

Objects own only their geometry.

### Rule #7

Geometry never knows the renderer.

### Rule #8

The Math Library never depends on MiniRT.

### Rule #9

Architecture is validated before implementation.

### Rule #10

Once an architecture decision is validated, it should only change if a better design is clearly justified.

# Overall Progress

```text
MiniRT
│
├── ✅ Milestone 0 — Foundations
│
├── ✅ Core Math Library
│
├── ✅ Milestone 1 — Architecture
│
├── ✅ Milestone 2 — Core Engine Foundation
│
├── ⏳ Milestone 3 — Parser + MLX
│
├── ⏳ Milestone 4 — Camera System
│
├── ⏳ Milestone 5 — Ray Generation
│
├── ⏳ Milestone 6 — Intersections
│
├── ⏳ Milestone 7 — Lighting
│
├── ⏳ Milestone 8 — Rendering
│
├── ⏳ Milestone 9 — Bonus Integration
│
└── ⏳ Milestone 10 — Debug & Optimisation
```

---

# Current Status

| Stage | Status | Progress |
|--------|--------|---------:|
| ✅ Milestone 0 — Foundations | 🟢 Completed | **100%** |
| ✅ Core Math Library | 🟢 Completed | **100%** |
| ✅ Milestone 1 — Architecture | 🟢 Completed | **100%** |
| ✅ Milestone 2 — Core Engine Foundation | 🟢 Completed | **100%** |
| ⏳ Milestone 3 — Parser + MLX | ⚪ Not Started | **0%** |
| ⏳ Milestone 4 — Camera System | ⚪ Not Started | **0%** |
| ⏳ Milestone 5 — Ray Generation | ⚪ Not Started | **0%** |
| ⏳ Milestone 6 — Intersections | ⚪ Not Started | **0%** |
| ⏳ Milestone 7 — Lighting | ⚪ Not Started | **0%** |
| ⏳ Milestone 8 — Rendering | ⚪ Not Started | **0%** |
| ⏳ Milestone 9 — Bonus Integration | ⚪ Not Started | **0%** |
| ⏳ Milestone 10 — Debug & Optimisation | ⚪ Not Started | **0%** |

---

# Current Milestone

```text
Milestone 3

Parser + MLX

Status

Ready To Start
```

---

# Overall Completion

```text
██████████████████░░░░░░░░░

Completed ≈ 55%
```

# Estimated Timeline

| Stage | Estimated Time |
|--------|---------------:|
| Parser + MLX | ~5 Days |
| Camera System | ~3 Days |
| Ray Generation | ~1 Day |
| Intersections | ~5 Days |
| Lighting | ~3 Days |
| Rendering | ~2 Days |
| Bonus Integration | ~4 Days |
| Debug & Optimisation | ~2 Days |

---

# Estimated Remaining Time

Approximately:

```text
25 Days
```

> The timeline is only an estimation.
>
> The priority is understanding the implementation rather than finishing as
> quickly as possible.


# Current Objective

The current objective is to build the complete parsing system and integrate
it with MLX.

The parser should produce a fully initialised `Scene`, while the MLX module
should provide a stable graphical environment for the renderer.

At the end of this milestone, the project should be capable of loading a
scene and displaying an empty window ready for rendering.


# Theoretical Foundations

✅ Completed

All mathematical foundations required for MiniRT have been completed.

Future concepts will only be introduced naturally during implementation.

---
```
MiniRT

├── Scene
│
├── Parser
│
├── Renderer
│
├── Intersector
│
├── Lighting
│
├── Math
│
└── MLX
```
```
Dependencies

Parser
↓

Scene

Renderer
↓

Scene

Renderer
↓

Intersector

Lighting
↓

Hit Record

MLX
↓

Renderer
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

**Status:** ✅ Completed

**Estimated Time:** ~2 Days

---

# Goal

Build the complete foundation of the MiniRT engine using the architecture
designed during Milestone 1.

At the end of this milestone, every core structure, ownership rule, and
execution flow should be fully validated before implementing the renderer.

---

# Topics

```text
Scene Creation

Scene Destroy

Camera Initialization

Ambient Initialization

Light Initialization

Object Initialization

Geometry Design

Linked List Design

Color Library Integration

Project Integration

Memory Ownership

Execution Flow

Public API

Header Organization
```

---

# Completed Components

## Scene Module

- ✅ Scene Structure
- ✅ Scene Ownership
- ✅ Scene Creation Design
- ✅ Scene Destruction Design

---

## Camera Module

- ✅ Camera Structure
- ✅ Camera Basis Design
- ✅ Viewport Information
- ✅ Cached Rendering Values

---

## Ambient Module

- ✅ Ambient Structure
- ✅ Brightness
- ✅ Colour

---

## Light Module

- ✅ Linked List Design
- ✅ Ownership Model
- ✅ Public Interface

---

## Object Module

- ✅ Generic Object
- ✅ Object Type
- ✅ Object Colour
- ✅ Geometry Ownership
- ✅ Linked List Integration

---

## Geometry Modules

Implemented design for:

- ✅ Sphere
- ✅ Plane
- ✅ Cylinder

---

## Public APIs

Designed and validated:

```text
Scene API

Camera API

Ambient API

Light API

Object API

Geometry API
```

---

# Architecture Completed

The following architectural components have been fully validated.

## Module Responsibilities

- ✅ Scene
- ✅ Camera
- ✅ Ambient
- ✅ Light
- ✅ Object
- ✅ Geometry

---

## Ownership Model

Validated:

- ✅ Ownership Tree
- ✅ Responsibility Tree
- ✅ Allocation Ownership
- ✅ Destroy Flow

---

## Execution Model

Validated:

```text
Program

↓

Scene

↓

Parser

↓

Renderer

↓

Cleanup
```

---

## Memory Model

Validated:

```text
malloc(Scene)

↓

malloc(Light)

↓

malloc(Object)

↓

Renderer

(No permanent allocations)

↓

scene_destroy()

↓

free(Light)

↓

free(Object)

↓

free(Scene)
```

---

# Deliverables

By the end of this milestone the following have been completed.

- ✅ Stable Engine Foundation
- ✅ Stable Public APIs
- ✅ Stable Folder Hierarchy
- ✅ Stable Header Organisation
- ✅ Stable Ownership Model
- ✅ Stable Execution Flow
- ✅ Stable Memory Flow
- ✅ Stable Core Structures

---

# Result

The project is now ready to begin real implementation.

The architecture is considered stable.

Future milestones should focus only on implementation rather than redesign.

Milestone 2 is officially completed.

## Layered Architecture

## 1. Scene Module
```
Scene
│
├── owns
│   ├── Camera
│   ├── Ambient
│   ├── Lights List
│   └── Objects List
│
├── knows
│   ├── Camera
│   ├── Ambient
│   ├── Light
│   └── Object
│
├── doesn't know
│   ├── MLX
│   ├── Rendering
│   ├── Intersections
│   └── Lighting
│
├── creates
│   └── Empty Scene
│
└── destroys
    ├── Lights
    └── Objects


## 2. Camera Module

Camera
│
├── owns
│   ├── Position
│   ├── Forward
│   ├── Right
│   ├── Up
│   ├── FOV
│   ├── Viewport
│   └── Pixel Size
│
├── knows
│   └── Math Library
│
├── doesn't know
│   ├── Scene
│   ├── Objects
│   ├── Lights
│   └── MLX
│
├── creates
│   └── Camera Basis
│
└── destroys
    └── Nothing


## 3. Ambient Module

Ambient
│
├── owns
│   ├── Brightness
│   └── Color
│
├── knows
│   └── Color
│
├── doesn't know
│   ├── Objects
│   ├── Camera
│   ├── Renderer
│   └── MLX
│
├── creates
│   └── Nothing
│
└── destroys
    └── Nothing


## 4. Light Module

Light
│
├── owns
│   ├── Position
│   ├── Brightness
│   ├── Color
│   └── Next
│
├── knows
│   ├── Point
│   └── Color
│
├── doesn't know
│   ├── Scene
│   ├── Objects
│   ├── Renderer
│   └── MLX
│
├── creates
│   └── One Light Node
│
└── destroys
    └── One Light Node
    

## 5. Object Module


Object
│
├── owns
│   ├── Type
│   ├── Color
│   ├── Geometry (Union)
│   └── Next
│
├── knows
│   ├── Sphere
│   ├── Plane
│   └── Cylinder
│
├── doesn't know
│   ├── Scene
│   ├── Camera
│   ├── Renderer
│   └── MLX
│
├── creates
│   └── One Object Node
│
└── destroys
    └── One Object Node

## 6. Geometry Modules

Sphere
│
├── owns
│   ├── Center
│   └── Radius
│
├── knows
│   └── Point
│
└── doesn't know
    └── Everything else

Plane
│
├── owns
│   ├── Point
│   └── Normal
│
└── doesn't know
    └── Everything else

Cylinder
│
├── owns
│   ├── Center
│   ├── Axis
│   ├── Radius
│   └── Height
│
└── doesn't know
    └── Everything else

## tree :

main()

│

▼

Scene
├───────────────┐
│               │
│ owns          │ owns
│               │
▼               ▼

Camera       Ambient

│

│ owns

▼

Nothing


Scene

│

├───────────────┐

│               │

▼               ▼

Light List    Object List

│               │

│ owns          │ owns

▼               ▼

Light Node    Object Node

                │

                ▼

           Geometry (Union)

                │

      ┌─────────┼─────────┐

      ▼         ▼         ▼

   Sphere     Plane    Cylinder

```

## how it work :

```
Program Start

↓

main()

↓

Validate Arguments

↓

scene_create() // (malloc(Scene))

↓

Parser // (malloc(Scene) + malloc(Object) + malloc(Light))

↓

Scene Ready

↓

Renderer (free())

↓

MLX Loop

↓

scene_destroy()

↓

Exit

/////


main()

│

├──────────────┐

│              │

malloc         free

│              │

▼              ▲

Scene──────────┘

│

├──────────────┐

│              │

▼              ▼

Lights       Objects

│              │

malloc       malloc

│              │

▼              ▼

Light        Object

│              │

free         free

```

# Milestone 3 — Parser + MLX

**Status:** ⏳ Ready To Start

**Estimated Time:** ~5 Days

---

# Goal

Build the complete scene loading system and initialise the graphical
environment.

At the end of this milestone, MiniRT should be capable of:

- Reading a `.rt` file.
- Building a valid `Scene`.
- Initialising MLX.
- Creating an image buffer.
- Opening a rendering window.

No ray tracing will happen during this milestone.

The objective is only to prepare the engine.

---

# Topics

```text
File Reading

Lexer

Tokenizer

Validation

Parser

Scene Builder

Scene Population

Error Handling

MLX Initialisation

Window Creation

Image Creation

Image Buffer

Pixel Drawing

Window Events
```

---

# Expected Architecture

```text
.rt File

↓

File Reader

↓

Lexer

↓

Parser

↓

Scene Builder

↓

Scene

↓

MLX Initialisation

↓

Window

↓

Image Buffer

↓

Ready For Rendering
```

---

# Modules

## Parser

Responsible for:

- Reading the scene file.
- Validating every line.
- Creating scene components.
- Populating the Scene.

The parser never performs rendering.

---

## MLX

Responsible for:

- Window creation.
- Image allocation.
- Pixel drawing.
- Display management.
- Event handling.

MLX never knows anything about Scene objects.

---

# Deliverables

By the end of this milestone the project should support:

- Reading `.rt` files.
- Camera parsing.
- Ambient parsing.
- Light parsing.
- Sphere parsing.
- Plane parsing.
- Cylinder parsing.
- Scene construction.
- Stable MLX initialisation.
- Window creation.
- Image creation.
- Pixel drawing.

---

# Result

MiniRT will now be capable of loading a complete scene and opening a
graphical window.

The renderer will still not perform ray tracing.

The project will simply be ready to start rendering during the next
milestone.


# Milestone 4 — Camera Implementation

**Status:** ⏳

**Estimated Time:** ~3 Days

---

# Goal

Implement the camera module designed during the previous milestones.

The objective of this milestone is to transform the camera from a data
structure into a fully functional system capable of describing the virtual
view of the scene.

No rays are generated yet.

Only the camera mathematics and viewport construction are implemented.

---

# Topics

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

Viewport Construction

Camera Initialisation
```

---

# Responsibilities

## Camera

Responsible for:

- Defining the viewer position.
- Building the camera basis.
- Computing viewport dimensions.
- Computing pixel size.
- Providing all information required to generate rays.

The camera never performs rendering.

---

## Renderer

The renderer may read camera data.

The renderer never modifies the camera.

---

# Expected Architecture

```text
Scene

↓

Camera

↓

Build Camera Basis

↓

Compute Viewport

↓

Compute Pixel Size

↓

Camera Ready
```

---

# Deliverables

At the end of this milestone the following should be completed.

- Camera Initialisation
- Camera Basis
- Viewport Width
- Viewport Height
- Pixel Size
- Camera Plane
- Aspect Ratio Support

---

# Result

The project will now contain a complete virtual camera capable of describing
how the world should be viewed.

The next milestone will use this information to generate one ray for every
pixel.


# Milestone 5 — Primary Ray Generation

**Status:** ⏳

**Estimated Time:** ~1 Day

---

# Goal

Generate one primary ray for every pixel on the viewport.

This milestone connects the mathematical camera with the rendering pipeline.

For the first time, the renderer becomes capable of asking:

> "Which direction should I look for this pixel?"

No intersections or lighting are performed yet.

The only objective is producing mathematically correct rays.

---

# Topics

```text
Pixel Coordinates

Pixel Centre

Normalized Device Coordinates (NDC)

Viewport Coordinates

World Coordinates

Camera Plane

Perspective Projection

Primary Rays

Ray Origin

Ray Direction

Ray Normalization
```

---

# Responsibilities

## Camera

Provides:

- Camera Position
- Forward
- Right
- Up
- Viewport Dimensions
- Pixel Size

The camera never creates rays directly.

---

## Renderer

Responsible for:

- Visiting every pixel.
- Computing the pixel centre.
- Computing the world-space position.
- Creating one primary ray.

---

## Ray

A ray contains:

```text
Origin

Direction
```

The direction must always be normalized.

---

# Expected Pipeline

```text
Pixel

↓

Pixel Centre

↓

Viewport Coordinates

↓

World Coordinates

↓

Ray Origin

+

Ray Direction

↓

Primary Ray
```

---

# Deliverables

At the end of this milestone the project should support:

- Generate one ray per pixel.
- Correct viewport mapping.
- Correct perspective projection.
- Normalized ray directions.
- Stable ray generation pipeline.

---

# Result

The renderer is now capable of producing a mathematically correct ray for
every screen pixel.

These rays will become the input of the intersection system during the next
milestone.


# Milestone 6 — Ray–Object Intersections

**Status:** ⏳

**Estimated Time:** ~5 Days

---

# Goal

Build the complete intersection system capable of detecting the first object
hit by a primary ray.

This milestone transforms the renderer from generating rays into
understanding the geometry of the scene.

The renderer should be capable of answering:

> "Which object is hit first by this ray?"

No lighting calculations are performed yet.

Only geometric intersections are computed.

---

# Topics

```text
Ray Equation

Hit Distance (t)

Ray–Sphere Intersection

Ray–Plane Intersection

Ray–Cylinder Intersection

Quadratic Equations

Plane Equations

Cylinder Mathematics

Nearest Hit

Discard Negative t

Object Dispatcher

Hit Record Construction
```

---

# Responsibilities

## Intersector

Responsible for:

- Testing every object.
- Computing intersections.
- Returning the closest valid hit.

The intersector never computes colours.

The intersector never performs lighting.

---

## Renderer

Responsible for:

- Sending one ray.
- Asking the intersector for the nearest hit.
- Receiving one Hit Record.

The renderer never computes the mathematics of each object.

---

## Objects

Each object is responsible only for describing its geometry.

```text
Sphere

↓

Sphere Intersection

Plane

↓

Plane Intersection

Cylinder

↓

Cylinder Intersection
```

Every geometry algorithm remains independent.

---

# Hit Record

The output of this milestone is a complete Hit Record.

Example:

```text
Hit

├── Object
├── Hit Point
├── Surface Normal
├── Distance (t)
└── Colour
```

The Hit Record becomes the communication bridge between:

```text
Intersector

↓

Lighting
```

---

# Expected Pipeline

```text
Primary Ray

↓

Loop Through Objects

↓

Test Intersection

↓

Discard Invalid Hits

↓

Find Nearest Hit

↓

Build Hit Record

↓

Return Hit Record
```

---

# Deliverables

At the end of this milestone the project should support:

- Ray–Sphere Intersection
- Ray–Plane Intersection
- Ray–Cylinder Intersection
- Object Dispatcher
- Nearest Hit Selection
- Negative t Rejection
- Hit Record Construction
- Stable Intersection API

---

# Result

The renderer will now be capable of determining exactly which object is
visible through every generated ray.

The project will finally understand the geometry of the world.

The next milestone will use the Hit Record to compute illumination.

# Milestone 7 — Lighting & Shading

**Status:** ⏳

**Estimated Time:** ~3 Days

---

# Goal

Compute the final colour of every visible surface.

This milestone transforms geometric intersections into visible images by
simulating how light interacts with scene objects.

The renderer should now be capable of answering:

> "What colour should this pixel be?"

---

# Topics

```text
Ambient Lighting

Diffuse Lighting

Lambert's Law

Surface Normal

Light Direction

View Direction

Specular Lighting

Phong Reflection Model

Reflection Vector

Shadow Rays

Light Visibility

Colour Accumulation

Final Surface Colour
```

---

# Responsibilities

## Lighting Module

Responsible for:

- Computing illumination.
- Combining light contributions.
- Producing the final colour.

The lighting module never computes intersections.

The lighting module never generates rays.

---

## Intersector

Provides:

```text
Hit Record
```

Only.

---

## Renderer

Responsible for:

```text
Primary Ray

↓

Hit Record

↓

Lighting

↓

Final Pixel Colour
```

---

# Lighting Pipeline

```text
Hit Record

↓

Ambient

↓

For Every Light

↓

Shadow Test

↓

Diffuse

↓

Specular

↓

Accumulate Colour

↓

Clamp Colour

↓

Final Colour
```

---

# Hit Record

The Lighting module receives only:

```text
Hit Record

├── Position

├── Surface Normal

├── Object Colour

├── Distance

└── Object Pointer
```

Lighting never knows:

- Sphere
- Plane
- Cylinder

It only understands the Hit Record.

---

# Shadow Rays

For every light:

```text
Hit Point

↓

Generate Shadow Ray

↓

Check Visibility

↓

Visible ?

│

├── Yes

│     Compute Lighting

│

└── No

      Ambient Only
```

---

# Colour Pipeline

```text
Ambient

+

Diffuse

+

Specular

↓

Clamp

↓

Final RGB
```

---

# Deliverables

At the end of this milestone the project should support:

- Ambient Lighting
- Diffuse Lighting
- Specular Lighting
- Phong Reflection Model
- Shadow Rays
- Multiple Light Contribution
- Colour Accumulation
- Colour Clamping
- Stable Lighting API

---

# Result

The renderer will now be capable of producing a correctly illuminated image.

Objects will no longer appear as simple geometric shapes.

They will now react to light and shadows, producing the first visually
recognisable render of the scene.


# Milestone 8 — Rendering Pipeline

**Status:** ⏳

**Estimated Time:** ~2 Days

---

# Goal

Integrate every previously developed subsystem into one complete rendering
pipeline capable of producing the final image.

At this point, every module should already be stable.

The objective of this milestone is not to introduce new mathematics.

The objective is to connect everything together.

---

# Modules

```text
Scene

Camera

Renderer

Intersector

Lighting

MLX
```

All modules communicate through well-defined interfaces.

---

# Rendering Pipeline

```text
Load Scene

↓

Initialize Camera

↓

Create Image

↓

For Every Pixel

        │

        ▼

Generate Primary Ray

        │

        ▼

Ray–Object Intersections

        │

        ▼

Nearest Hit

        │

        ▼

Lighting

        │

        ▼

Final Colour

        │

        ▼

Write Pixel

↓

Display Image
```

---

# Renderer Responsibilities

The renderer becomes the project coordinator.

It is responsible for:

- Traversing the image.
- Requesting rays.
- Requesting intersections.
- Requesting lighting.
- Writing pixels.

The renderer owns none of the mathematics.

The renderer owns none of the geometry.

It simply coordinates every subsystem.

---

# Data Flow

```text
Scene

↓

Camera

↓

Primary Ray

↓

Intersector

↓

Hit Record

↓

Lighting

↓

RGB Colour

↓

Image Buffer

↓

Window
```

---

# Expected Deliverables

At the end of this milestone the project should support:

- Full rendering loop
- Image generation
- Pixel writing
- Window display
- Stable rendering pipeline
- First complete rendered scene

---

# Result

MiniRT is now capable of rendering a complete scene from start to finish.

Every subsystem developed during previous milestones is now integrated into
one coherent rendering engine.


# Milestone 9 — Bonus Integration

**Status:** ⏳

**Estimated Time:** ~4 Days

---

# Goal

Extend the renderer while preserving the architecture established during the
mandatory part.

Every bonus feature should integrate into the existing pipeline without
requiring a redesign of the engine.

The renderer should become more capable, not more complicated.

---

# Philosophy

The Bonus is not a second project.

It is an extension of the existing one.

Every new feature should plug naturally into the current architecture.

No core module should require major modifications.

---

# Possible Features

```text
Multiple Lights

Object Transformations

Checkerboard Materials

Reflection

Refraction

Soft Shadows

Anti-Aliasing

Camera Movement

Object Selection

Advanced Scene Parsing
```

---

# Integration Strategy

Every bonus feature should extend one existing module.

Examples:

```text
Reflection

↓

Lighting Module

-----------------------

Checkerboard

↓

Material System

-----------------------

Multiple Lights

↓

Light List

-----------------------

Camera Movement

↓

Camera Module

-----------------------

Anti-Aliasing

↓

Primary Ray Generation
```

No feature should bypass the existing rendering pipeline.

---

# Updated Rendering Pipeline

```text
Scene

↓

Camera

↓

Generate Primary Rays

↓

Intersections

↓

Hit Record

↓

Material Evaluation

↓

Lighting

↓

Reflection / Refraction (Optional)

↓

Final Colour

↓

Write Pixel
```

---

# Expected Deliverables

Depending on the available time, the renderer may support:

- Multiple light sources
- Reflective materials
- Transparent materials
- Checkerboard textures
- Soft shadows
- Anti-aliasing
- Camera interaction
- Improved parser

---

# Result

The renderer evolves from a minimal educational ray tracer into a more
complete rendering engine while preserving the same architecture and design
principles established throughout the project.



# Milestone 10 — Validation & Optimisation

**Status:** ⏳

**Estimated Time:** ~2 Days

---

# Goal

Validate the entire project before submission.

This milestone focuses on stability, correctness, performance, and code
quality rather than adding new features.

Every subsystem should already be complete.

The objective is to ensure that the final project behaves exactly as
expected under all supported scenarios.

---

# Validation Areas

```text
Memory Management

Error Handling

Project Stability

Performance

Code Quality

Norm Compliance

Rendering Validation
```

---

# Topics

```text
Memory Leaks

Invalid Frees

Segmentation Faults

NULL Safety

Parser Validation

Edge Cases

Performance Profiling

Code Refactoring

Norminette

Documentation Review

Final Architecture Review
```

---

# Validation Checklist

## Memory

- No memory leaks.
- No invalid frees.
- No double frees.
- No dangling pointers.

---

## Parser

- Invalid files rejected.
- Invalid values rejected.
- Error messages remain consistent.
- Scene ownership remains valid.

---

## Renderer

- Stable rendering loop.
- Correct image generation.
- No undefined behaviour.
- Stable lighting pipeline.
- Stable intersection pipeline.

---

## Code Quality

- Norminette passes.
- No duplicated logic.
- Low Coupling maintained.
- High Cohesion maintained.
- Public APIs remain clean.
- Modules remain independent.

---

## Architecture Review

Before submission, verify that the project still respects every rule defined
during Milestone 1.

Examples:

- Geometry never owns colour.
- Scene owns the world.
- Renderer coordinates but does not compute geometry.
- Intersector only computes intersections.
- Lighting only computes illumination.
- Every allocation has exactly one owner.

---

# Expected Deliverables

At the end of this milestone the project should provide:

- Stable executable.
- Leak-free execution.
- Norm-compliant source code.
- Clean architecture.
- Stable rendering.
- Complete documentation.

---

# Result

MiniRT is now considered complete.

The project has evolved from mathematical foundations into a fully
functional ray tracer with a stable architecture, well-defined module
boundaries, and a complete rendering pipeline.

The renderer is not only capable of producing images, but the entire codebase
remains understandable, maintainable, and extensible.

# Project Completion

By completing this roadmap, the following topics have been fully studied
and implemented.

## Mathematics

- Linear Algebra
- Geometry
- Camera Mathematics
- Perspective Projection
- Ray Mathematics

## Computer Graphics

- Ray Tracing
- Lighting Models
- Visibility
- Rendering Pipeline

## Software Engineering

- Modular Architecture
- Memory Ownership
- Public APIs
- Data Flow
- Responsibility Separation

## Low-Level Programming

- Memory Management
- Linked Lists
- Parsing
- Graphics Programming (MLX)

---

> The objective of this roadmap was never simply to complete MiniRT.

> The objective was to become capable of rebuilding a ray tracer from
> scratch while understanding every design decision behind it.



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

--

v0.1

Completed Mathematics

----------------

v0.2

Completed Core Math Library

----------------

v0.3

Completed Architecture

----------------

v0.4

Completed Core Engine Foundation

...

