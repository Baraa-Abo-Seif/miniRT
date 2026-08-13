# Project Overview

MiniRT is being developed following a milestone-based roadmap where each
stage is completed only after its underlying theory, architecture, and
implementation have been fully understood.

The project prioritises understanding over speed, ensuring that every
algorithm, mathematical concept, and architectural decision is mastered
before moving to the next milestone.

---

## Current Progress

| Area                   | Status        |
| ---------------------- | ------------- |
| Mathematics            | ✅ Completed  |
| Core Math Library      | ✅ Completed  |
| Architecture Design    | ✅ Completed  |
| Core Engine Foundation | ✅ Completed  |
| Parser                 | ✅ Completed  |
| MLX Integration        | ✅ Completed  |
| Camera & Ray System    | ✅ Completed  |
| Intersections          | 🟡 In Progress |
| Lighting               | ⏳ Pending    |
| Rendering Pipeline     | ⏳ Pending    |
| Bonus Features         | ⏳ Pending    |
| Final Validation       | ⏳ Pending    |

---

## Overall Completion

```text
█████████████████████░░░░░░░░░ 65%
```

---

## Current Stage

**Milestone 6 — Intersections**

The complete camera and primary ray generation pipeline has been fully
implemented and validated.

The project now provides:

- Camera creation and destruction
- Camera orthonormal basis construction
- Viewport computation
- Pixel delta computation
- Camera initialization
- Ray abstraction
- Ray constructor
- Ray position evaluation (`ray_at`)
- Primary ray generation for every pixel
- Camera and ray mathematical validation
- Visual validation using MLX
- Temporary sphere-hit validation to verify ray correctness

The renderer is now capable of generating mathematically correct primary
rays for every pixel on the image plane.

The next milestone begins the implementation of the real object
intersection system.

---

## Project Timeline

| Milestone              | Estimated Duration | Status |
| ---------------------- | -----------------: | ------ |
| Foundations            |          Completed | ✅ |
| Core Math Library      |          Completed | ✅ |
| Architecture           |          Completed | ✅ |
| Core Engine Foundation |          Completed | ✅ |
| Parser                 |          Completed | ✅ |
| MLX Integration        |          Completed | ✅ |
| Camera & Ray System    |          Completed | ✅ |
| Intersections          |            ~5 Days | 🟡 |
| Lighting               |            ~3 Days | ⏳ |
| Rendering Pipeline     |            ~2 Days | ⏳ |
| Bonus                  |            ~4 Days | ⏳ |
| Validation             |            ~2 Days | ⏳ |

---

Approximately **15–17 working days** remain in the current roadmap.

This estimation assumes a steady development pace and may change as the
project evolves.

---

## Current Objective

The immediate objective is to complete **Milestone 6 — Intersections**.

The camera system and primary ray generation pipeline have already been
completed and validated.

The next development cycle will focus on:

```text
Primary Ray
      │
      ▼
Object Intersection
      │
      ▼
Closest Hit
      │
      ▼
Hit Record
```

The first implementation will support sphere intersections, followed by
planes and cylinders.

Once the complete intersection system has been implemented and verified,
the project will move to the **Lighting** milestone.