# Project Overview

MiniRT is being developed following a milestone-based roadmap where each
stage is completed only after its underlying theory, architecture, and
implementation have been fully understood.

The project prioritises understanding over speed, ensuring that every
algorithm, mathematical concept, and architectural decision is mastered
before moving to the next milestone.

---

## Current Progress

| Area                   | Status         |
| ---------------------- | -------------- |
| Mathematics            | ✅ Completed   |
| Core Math Library      | ✅ Completed   |
| Architecture Design    | ✅ Completed   |
| Core Engine Foundation | ✅ Completed   |
| Parser                 | ✅ Completed   |
| MLX Integration        | ✅ Completed   |
| Camera System          | ✅ Completed   |
| Ray Generation         | 🟡 In Progress |
| Intersections          | ⏳ Pending     |
| Lighting               | ⏳ Pending     |
| Rendering Pipeline     | ⏳ Pending     |
| Bonus Features         | ⏳ Pending     |
| Final Validation       | ⏳ Pending     |

---

## Overall Completion

```text
██████████████████░░░░░░░░░░░░ 55%
```

---

## Current Stage

**Milestone 5 — Primary Ray Generation**

The Camera System milestone has been completed and fully validated.

The camera implementation now provides:

- Camera creation and destruction
- Camera basis construction
- Forward / Right / Up orthonormal basis
- Field of view computation
- Viewport dimension calculation
- Viewport upper-left corner calculation
- Pixel delta computation
- Complete camera initialization
- Independent camera testing

The complete camera geometry has been verified using a dedicated
mathematical integration test.

The renderer is now ready to begin generating primary rays.

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
| Camera System          |          Completed | ✅ |
| Primary Rays           |            ~2 Days | 🟡 |
| Intersections          |            ~5 Days | ⏳ |
| Lighting               |            ~3 Days | ⏳ |
| Rendering Pipeline     |            ~2 Days | ⏳ |
| Bonus                  |            ~4 Days | ⏳ |
| Validation             |            ~2 Days | ⏳ |

---

Approximately **18–20 working days** remain in the current roadmap.

This estimation assumes a steady development pace and may change as the
project evolves.

---

## Current Objective

The immediate objective is to complete **Milestone 5 — Primary Ray Generation**.

The Camera System has been fully implemented and validated.

The next development cycle will focus on:

```text
Camera
   │
   ▼
Pixel Coordinates
   │
   ▼
Viewport Position
   │
   ▼
Image Plane Point
   │
   ▼
Primary Ray
```

Once the first complete primary-ray generation pipeline has been implemented
and verified, the project will move to the **Intersections** milestone.

