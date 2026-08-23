# MiniRT Project Overview

MiniRT is being developed following a milestone-based roadmap where each stage is completed only after its underlying theory, architecture, and implementation have been fully understood.

The project prioritises understanding over speed, ensuring that every algorithm, mathematical concept, and architectural decision is mastered before moving to the next milestone.

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
| Cylinder Intersection   | ✅ Completed    |
| Generic Object Dispatch | ✅ Completed    |
| Closest Visible Hit     | ✅ Completed    |
| Lighting                | 🟡 In Progress |
| Rendering Pipeline      | ⏳ Pending      |
| Bonus Features          | ⏳ Pending      |
| Final Validation        | ⏳ Pending      |

---

## Overall Completion

```text
█████████████████████████████░ 82%
```

---

## Current Stage

**Milestone 7 — Lighting**

The complete camera and primary ray generation pipeline has been fully implemented and validated.

The renderer now supports a complete visibility pipeline for every mandatory geometric primitive.

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
* Complete plane-ray intersection
* Complete cylinder-ray intersection
* Cylinder body intersection
* Cylinder cap intersection
* Unified cylinder intersection pipeline
* Generic object dispatch system
* Scene-wide closest-hit search
* Quadratic equation solver
* Interval-based root validation
* Hit record generation
* Surface normal computation
* Front-face detection
* Camera and ray mathematical validation
* Mathematical sphere intersection validation
* Mathematical plane intersection validation
* Mathematical cylinder intersection validation
* Visual validation using MLX

The renderer is now capable of generating mathematically correct primary rays, intersecting every mandatory primitive, dispatching intersections through a unified interface, and selecting the closest visible object inside the scene.

With the complete intersection framework finished, development now moves to the lighting stage.

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
| Plane Intersection      |          Completed | ✅      |
| Cylinder Intersection   |          Completed | ✅      |
| Generic Object Dispatch |          Completed | ✅      |
| Closest Visible Hit     |          Completed | ✅      |
| Lighting                |            ~3 Days | 🟡     |
| Rendering Pipeline      |            ~2 Days | ⏳      |
| Bonus                   |            ~4 Days | ⏳      |
| Validation              |            ~2 Days | ⏳      |

---

Approximately **8–10 working days** remain in the current roadmap.

This estimation assumes a steady development pace and may change as the project evolves.

---

## Current Objective

The immediate objective is to implement the complete lighting model.

The renderer now possesses a complete visibility system capable of determining the closest object intersected by every primary ray.

The next development phase focuses on transforming geometric intersections into visible images through physically correct lighting calculations, beginning with ambient illumination, diffuse shading (Lambert), and shadow rays.

```text
Sphere Intersection         ✅
        │
        ▼
Plane Intersection          ✅
        │
        ▼
Cylinder Intersection       ✅
        │
        ▼
Generic Object Dispatch     ✅
        │
        ▼
Closest Visible Hit         ✅
        │
        ▼
Lighting
        │
        ▼
Rendering Pipeline
        │
        ▼
Bonus Features
        │
        ▼
Final Validation
```

With the visibility pipeline complete, the project has entered its final major implementation phase. The remaining work focuses on converting the mathematically correct ray tracer into a complete renderer capable of producing fully shaded scenes.

