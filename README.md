# MiniRT Project Overview

MiniRT is being developed following a milestone-based roadmap where each
stage is completed only after its underlying theory, architecture, and
implementation have been fully understood.

The project prioritises understanding over speed, ensuring that every
algorithm, mathematical concept, and architectural decision is mastered
before moving to the next milestone.

---

## Current Progress

| Area                    | Status         |
| ----------------------- | -------------- |
| Mathematics             | ✅ Completed    |
| Core Math Library       | ✅ Completed    |
| Architecture Design     | ✅ Completed    |
| Core Engine Foundation  | ✅ Completed    |
| Parser                  | ✅ Completed    |
| MLX Integration         | ✅ Completed    |
| Camera & Ray System     | ✅ Completed    |
| Sphere Intersection     | ✅ Completed    |
| Plane Intersection      | ✅ Completed    |
| Remaining Intersections | 🟡 In Progress |
| Lighting                | ⏳ Pending      |
| Rendering Pipeline      | ⏳ Pending      |
| Bonus Features          | ⏳ Pending      |
| Final Validation        | ⏳ Pending      |

---

## Overall Completion

```text
█████████████████████████░░░░░ 75%
```

---

## Current Stage

**Milestone 6 — Intersections**

The complete camera and primary ray generation pipeline has been fully
implemented and validated.

The renderer now supports complete ray-object intersection for the first
two geometric primitives.

The project currently provides:

- Camera creation and destruction
- Camera orthonormal basis construction
- Viewport computation
- Pixel delta computation
- Camera initialization
- Ray abstraction
- Ray constructor
- Ray position evaluation (`ray_at`)
- Primary ray generation for every pixel
- Complete sphere-ray intersection
- Complete plane-ray intersection
- Quadratic equation solver
- Interval-based root validation
- Hit record generation
- Surface normal computation
- Front-face detection
- Camera and ray mathematical validation
- Mathematical sphere intersection validation
- Mathematical plane intersection validation
- Visual validation using MLX

The renderer is now capable of generating mathematically correct primary
rays and accurately intersecting both spheres and planes.

The remaining work in this milestone focuses on implementing cylinder
intersections, followed by the generic object dispatch system and the
closest-hit search used by the renderer.

---

## Project Timeline

| Milestone               | Estimated Duration | Status |
| ----------------------- | -----------------: | ------ |
| Foundations             |          Completed | ✅ |
| Core Math Library       |          Completed | ✅ |
| Architecture            |          Completed | ✅ |
| Core Engine Foundation  |          Completed | ✅ |
| Parser                  |          Completed | ✅ |
| MLX Integration         |          Completed | ✅ |
| Camera & Ray System     |          Completed | ✅ |
| Sphere Intersection     |          Completed | ✅ |
| Plane Intersection      |          Completed | ✅ |
| Remaining Intersections |            ~2 Days | 🟡 |
| Lighting                |            ~3 Days | ⏳ |
| Rendering Pipeline      |            ~2 Days | ⏳ |
| Bonus                   |            ~4 Days | ⏳ |
| Validation              |            ~2 Days | ⏳ |

---

Approximately **11–13 working days** remain in the current roadmap.

This estimation assumes a steady development pace and may change as the
project evolves.

---

## Current Objective

The immediate objective is to complete the remaining object intersection
system.

The current development sequence is:

```text
Sphere Intersection        ✅
        │
        ▼
Plane Intersection         ✅
        │
        ▼
Cylinder Intersection
        │
        ▼
Generic Object Dispatch
        │
        ▼
Closest Visible Hit
        │
        ▼
Lighting
```

Both sphere and plane intersections have now been fully implemented,
tested, and mathematically validated.

The next development cycle will focus on implementing cylinder
intersections before building the generic object-dispatch system that
allows every scene object to be queried through a unified interface.

Once the complete intersection system has been implemented and verified,
the project will move to the **Lighting** milestone.

