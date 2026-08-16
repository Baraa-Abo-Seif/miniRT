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
| Remaining Intersections | 🟡 In Progress |
| Lighting                | ⏳ Pending      |
| Rendering Pipeline      | ⏳ Pending      |
| Bonus Features          | ⏳ Pending      |
| Final Validation        | ⏳ Pending      |

---

## Overall Completion

```text
███████████████████████░░░░░░░ 70%
```

---

## Current Stage

**Milestone 6 — Intersections**

The complete camera and primary ray generation pipeline has been fully
implemented and validated.

The first complete object intersection system has now been successfully
implemented.

The project currently provides:

* Camera creation and destruction
* Camera orthonormal basis construction
* Viewport computation
* Pixel delta computation
* Camera initialization
* Ray abstraction
* Ray constructor
* Ray position evaluation (`ray_at`)
* Primary ray generation for every pixel
* Complete sphere-ray intersection
* Quadratic equation solver
* Root validation using intervals
* Hit record generation
* Surface normal computation
* Front-face detection
* Camera and ray mathematical validation
* Mathematical sphere intersection validation
* Visual validation using MLX

The renderer is now capable of generating mathematically correct primary
rays and performing complete sphere intersection tests.

The remaining work in this milestone focuses on implementing the remaining
geometric primitives and the generic object intersection interface.

---

## Project Timeline

| Milestone               | Estimated Duration | Status |
| ----------------------- | -----------------: | ------ |
| Foundations             |          Completed | ✅      |
| Core Math Library       |          Completed | ✅      |
| Architecture            |          Completed | ✅      |
| Core Engine Foundation  |          Completed | ✅      |
| Parser                  |          Completed | ✅      |
| MLX Integration         |          Completed | ✅      |
| Camera & Ray System     |          Completed | ✅      |
| Sphere Intersection     |          Completed | ✅      |
| Remaining Intersections |            ~3 Days | 🟡     |
| Lighting                |            ~3 Days | ⏳      |
| Rendering Pipeline      |            ~2 Days | ⏳      |
| Bonus                   |            ~4 Days | ⏳      |
| Validation              |            ~2 Days | ⏳      |

---

Approximately **12–14 working days** remain in the current roadmap.

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
Plane Intersection
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

The sphere intersection implementation has been fully completed and
validated.

The next development cycle will focus on implementing plane intersections,
followed by cylinders, before building the generic object-dispatch system
that will allow the renderer to query every object uniformly.

Once the complete intersection system has been implemented and verified,
the project will move to the **Lighting** milestone.


