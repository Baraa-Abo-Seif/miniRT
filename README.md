# miniRT

## Project Overview

`miniRT` is a 3D ray-tracing project written in C. It renders 3D scenes containing geometric objects, lighting, shadows, and camera perspectives using the MiniLibX graphics library.

The Mandatory part has been fully implemented, tested, and stabilized.

Development is focused on completing and validating the Bonus features through a structured, incremental workflow.

---

## Mandatory Part — COMPLETED

The Mandatory requirements have been implemented and are working as expected.

---

## Bonus Roadmap

Bonus features are developed incrementally. Each feature is studied, implemented, integrated, and validated before moving to the next one.

### Development Philosophy

Each Bonus feature follows this workflow:

> Theory → Mathematical Model → Architecture → Implementation → Integration → Testing → Visual Validation → Stability

The objective is to understand and validate each feature before proceeding to the next one.

---

### 1. Phong Specular Reflection — COMPLETED

The specular reflection component has been implemented as part of the lighting system.

Final combined-feature validation remains part of the Bonus integration phase.

### 2. Checkerboard Pattern — COMPLETED

Checkerboard patterns have been implemented for supported geometric surfaces.

Individual checkerboard tests have been executed successfully. Combined-feature and regression testing remain part of the final validation phase.

### 3. Colored and Multiple Lights — IMPLEMENTED

Colored and multiple-light support has been implemented.

Final validation must confirm that light contributions, shadows, and interactions with the other Bonus features behave correctly in combined scenes.

### 4. Additional Second-Degree Object: Paraboloid — IMPLEMENTED

A paraboloid has been implemented as the additional second-degree object.

#### Implementation

- Implemented ray-paraboloid intersection calculations.
- Solved the quadratic equation and selected valid intersection roots.
- Handled misses, tangent intersections, and rays originating behind or outside the valid surface region.
- Calculated surface normals.
- Integrated the object into object dispatch.
- Integrated the object into scene construction and parsing.
- Added a dedicated paraboloid test program.

#### Validation Completed

- Axis-parallel ray.
- Ray crossing the paraboloid.
- Ray missing the paraboloid.
- Nearest valid root selection.
- Rejection of intersections above the configured height.
- Surface normal at the vertex.
- Surface normal on the curved surface.
- Tangent ray.
- Intersection at the height boundary.
- Rejection of intersections beyond the height limit.
- Rejection of intersections behind the ray.

**Current result:** All 11 dedicated paraboloid tests pass. The project builds successfully, and the paraboloid scene has been rendered successfully.

#### Remaining Validation

- Confirm shadow behavior in combined scenes.
- Validate diffuse and specular lighting.
- Test different orientations and configurations.
- Run regression tests on existing Mandatory scenes.
- Validate interactions with all other Bonus features.

---

### 5. Bump Map Textures — PLANNED

Implement bump mapping to create the appearance of surface detail by perturbing surface normals without changing the underlying geometry.

The implementation will integrate with the existing lighting pipeline.

#### Planned Pipeline

```text
Ray
 ↓
Intersection
 ↓
Original Surface Normal
 ↓
Bump Map Sampling
 ↓
Modified Surface Normal
 ↓
Phong Lighting
 ↓
Final Color
```

#### Planned Implementation

- Define a representation for bump map data.
- Determine how texture data will be loaded and stored.
- Implement texture sampling.
- Define coordinate mapping for supported objects.
- Calculate the perturbation applied to surface normals.
- Integrate modified normals into the lighting pipeline.
- Preserve the original geometry and intersection calculations.
- Handle scenes that do not use bump mapping.
- Define and validate the parser syntax if new scene parameters are required.

#### Planned Validation

- Objects without a bump map.
- Basic bump map sampling.
- Different bump map intensities.
- Texture mapping on supported objects.
- Normal perturbation at different surface positions.
- Bump mapping with diffuse lighting.
- Bump mapping with specular reflection.
- Bump mapping with shadows.
- Visual comparison between mapped and unmapped surfaces.

---

## Bonus Integration — PENDING

After the remaining feature work is completed, validate the Bonus implementation as a complete system.

### Combined Feature Tests

Test interactions between:

- Specular reflection and checkerboard patterns.
- Specular reflection and multiple lights.
- Checkerboard patterns and multiple lights.
- Checkerboard patterns and shadows.
- Bump mapping and specular reflection.
- Bump mapping and multiple lights.
- The paraboloid and specular reflection.
- The paraboloid and shadows.
- All compatible Bonus features together.

The objective is to ensure that adding one feature does not break an existing feature.

---

## Bonus Parser Validation — PENDING

The parser will be reviewed and extended wherever required by the Bonus features.

### Planned Validation

- Verify the syntax of each new object or parameter.
- Validate argument counts and value ranges.
- Handle invalid vectors, colors, and dimensions.
- Reject malformed scene descriptions.
- Ensure error messages identify invalid input clearly.
- Confirm existing Mandatory `.rt` scenes remain compatible.
- Test scenes containing multiple Bonus features.

---

## Complete Bonus Test Suite — IN PROGRESS

Each feature must be tested independently before the complete renderer is validated.

### Testing Workflow

```text
[✓] Paraboloid implementation completed
[✓] Paraboloid dedicated tests passed
[✓] Paraboloid scene rendered successfully
[ ] Remaining individual feature tests reviewed
[ ] Parser integration fully validated
[ ] Combined feature tests passed
[ ] Mandatory regression tests passed
[ ] Visual behavior validated across combined scenes
[ ] Memory and stability checks completed
[ ] Final audit completed
```

The checklist will be updated as each task is verified.

---

## Memory and Stability Validation — PENDING

Validate the application after integrating the remaining Bonus features.

### Planned Checks

- Run available scenes and test cases.
- Check for memory leaks using Valgrind where supported.
- Check for invalid memory access.
- Verify allocation and cleanup paths.
- Test repeated rendering and window closure.
- Confirm error handling does not leave allocated resources behind.
- Build with the required compiler flags.
- Run Norminette and address applicable issues.

---

## Final Bonus Audit — PENDING

Before considering the Bonus complete, compare the implementation against the official project subject.

### Final Checklist

- [ ] All selected Bonus features are implemented.
- [ ] The implementation matches the official subject.
- [ ] The parser accepts valid scenes and rejects invalid ones.
- [ ] Existing Mandatory scenes still work.
- [ ] Individual feature tests pass.
- [ ] Combined feature tests pass.
- [ ] Visual output is validated.
- [ ] Memory and stability checks are completed.
- [ ] Norminette checks are completed.
- [ ] Final code review is completed.
- [ ] README documentation reflects the final implementation.

---

## Current Bonus Status

```text
[✓] 1. Phong Specular Reflection — implemented
[✓] 2. Checkerboard Pattern — implemented
[✓] 3. Colored and Multiple Lights — implemented
[✓] 4. Paraboloid — implemented and dedicated tests passed
[ ] 5. Bump Map Textures
[ ] 6. Bonus Integration
[ ] 7. Final Bonus Parser Validation
[ ] 8. Complete Bonus Test Suite
[ ] 9. Memory and Stability Validation
[ ] 10. Final Bonus Audit
```

### Current Milestone

**Next: Bump Map Textures**

The paraboloid implementation and its dedicated tests are complete. The next development milestone is to study the existing texture and lighting architecture, then design a bump mapping implementation that fits the project without breaking existing behavior.

---

## Project Status

**Mandatory: COMPLETED**

**Bonus: IN PROGRESS**

