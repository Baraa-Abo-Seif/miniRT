# MiniRT Project Overview

MiniRT is being developed following a milestone-based roadmap where each stage is completed only after its underlying theory, architecture, and implementation have been fully understood.

The project prioritises understanding over speed, ensuring that every algorithm, mathematical concept, and architectural decision is mastered before moving to the next milestone.

---

## Current Progress

| Area                     | Status |
| ------------------------ | ------ |
| Mathematics              | ✅ Completed |
| Core Math Library        | ✅ Completed |
| Architecture Design      | ✅ Completed |
| Core Engine Foundation   | ✅ Completed |
| Parser                   | ✅ Completed |
| MLX Integration          | ✅ Completed |
| Camera & Ray System      | ✅ Completed |
| Sphere Intersection      | ✅ Completed |
| Plane Intersection       | ✅ Completed |
| Cylinder Intersection    | ✅ Completed |
| Generic Object Dispatch  | ✅ Completed |
| Closest Visible Hit      | ✅ Completed |
| Lighting                 | ✅ Completed |
| Rendering Pipeline       | 🟡 In Progress |
| Bonus Features           | ⏳ Pending |
| Final Validation         | ⏳ Pending |

---

## Overall Completion

```text
█████████████████████████████████░░ 88%
```

---

## Current Stage

**Milestone 8 — Rendering Pipeline**

The complete visibility and lighting framework has now been fully implemented and validated.

The renderer currently supports:

### Geometry

- Camera creation and destruction
- Camera orthonormal basis construction
- Viewport computation
- Pixel delta computation
- Camera initialization
- Ray abstraction
- Ray constructor
- Ray position evaluation (`ray_at`)
- Primary ray generation

### Intersections

- Complete sphere-ray intersection
- Complete plane-ray intersection
- Complete cylinder-ray intersection
- Cylinder body intersection
- Cylinder cap intersection
- Unified cylinder intersection pipeline
- Generic object dispatch system
- Scene-wide closest-hit search
- Quadratic equation solver
- Interval-based root validation
- Hit record generation
- Surface normal computation
- Front-face detection

### Lighting

- Ambient lighting
- Lambert diffuse lighting
- Multiple light support
- Shadow rays
- Shadow acne prevention (epsilon offset)
- Light visibility testing
- Color accumulation
- Color clamping

### Validation

- Mathematical validation for all primitives
- Visual validation using MLX test scenes

The renderer now possesses a complete geometric visibility system together with a complete mandatory lighting model.

The next development phase focuses on connecting every subsystem into the final rendering loop capable of producing the complete image pixel by pixel.

---

## Project Timeline

| Milestone               | Estimated Duration | Status |
| ----------------------- | -----------------: | ------ |
| Foundations             | Completed | ✅ |
| Core Math Library       | Completed | ✅ |
| Architecture            | Completed | ✅ |
| Core Engine Foundation  | Completed | ✅ |
| Parser                  | Completed | ✅ |
| MLX Integration         | Completed | ✅ |
| Camera & Ray System     | Completed | ✅ |
| Sphere Intersection     | Completed | ✅ |
| Plane Intersection      | Completed | ✅ |
| Cylinder Intersection   | Completed | ✅ |
| Generic Object Dispatch | Completed | ✅ |
| Closest Visible Hit     | Completed | ✅ |
| Lighting                | Completed | ✅ |
| Rendering Pipeline      | ~2 Days | 🟡 |
| Bonus                   | ~4 Days | ⏳ |
| Validation              | ~2 Days | ⏳ |

---

Approximately **6–8 working days** remain in the current roadmap.

This estimation assumes a steady development pace and may change as the project evolves.

---

## Current Objective

The immediate objective is to implement the complete rendering pipeline.

All mandatory mathematical and lighting components are now operational.

The remaining work is to connect every subsystem into the renderer so that each pixel:

1. Generates a primary ray.
2. Finds the closest visible object.
3. Computes ambient illumination.
4. Computes diffuse illumination.
5. Tests shadow visibility.
6. Produces the final pixel color.
7. Writes the pixel into the MLX image.

```text
Primary Ray Generation          ✅
            │
            ▼
World Intersection              ✅
            │
            ▼
Closest Visible Hit             ✅
            │
            ▼
Ambient Lighting                ✅
            │
            ▼
Diffuse Lighting                ✅
            │
            ▼
Shadow Rays                     ✅
            │
            ▼
Rendering Pipeline              🟡
            │
            ▼
MLX Image Output                🟡
            │
            ▼
Bonus Features                  ⏳
            │
            ▼
Final Validation                ⏳
```

With the complete lighting system finished, the project has entered its final implementation phase.

The remaining work focuses on integrating the renderer, generating the final image, polishing the engine, and completing the bonus features before final validation.

