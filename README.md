# MiniRT — Bonus Development Roadmap

The Mandatory part of MiniRT has been fully implemented, integrated, tested, and validated.

The project was designed with extensibility in mind, allowing the Bonus features to be implemented on top of the existing rendering engine without restructuring the completed Mandatory architecture.

According to the official MiniRT specification, the Bonus phase focuses on five main extensions:

* Specular reflection for a complete Phong reflection model.
* Checkerboard color disruption.
* Colored and multi-spot lights.
* An additional second-degree object.
* Bump map textures.

The Bonus phase will therefore extend the existing engine incrementally while preserving the correctness and stability of the Mandatory implementation.

---

## Current Progress

| Area                            | Status      |
| ------------------------------- | ----------- |
| Mathematics                     | ✅ Completed |
| Core Math Library               | ✅ Completed |
| Architecture Design             | ✅ Completed |
| Core Engine Foundation          | ✅ Completed |
| Parser                          | ✅ Completed |
| MLX Integration                 | ✅ Completed |
| Camera & Ray System             | ✅ Completed |
| Sphere Intersection             | ✅ Completed |
| Plane Intersection              | ✅ Completed |
| Cylinder Intersection           | ✅ Completed |
| Generic Object Dispatch         | ✅ Completed |
| Closest Visible Hit             | ✅ Completed |
| Ambient Lighting                | ✅ Completed |
| Diffuse Lighting                | ✅ Completed |
| Shadow Rays                     | ✅ Completed |
| Multiple Light Support          | ✅ Completed |
| Rendering Pipeline              | ✅ Completed |
| Mandatory Validation            | ✅ Completed |
| Bonus Architecture              | 🟢 Ready    |
| Phong Specular Reflection       | ⏳ Pending   |
| Checkerboard Pattern            | ⏳ Pending   |
| Colored Lights                  | ⏳ Pending   |
| Multi-Spot Lights               | ⏳ Pending   |
| Additional Second-Degree Object | ⏳ Pending   |
| Bump Map Textures               | ⏳ Pending   |
| Bonus Validation                | ⏳ Pending   |
| Final Audit                     | ⏳ Pending   |

---

## Overall Completion

```text
██████████████████████████████████░░ 90%
```

The Mandatory implementation is complete.

The remaining work consists of implementing, integrating, and validating the five official Bonus features, followed by final testing, memory validation, and project auditing.

---

# Bonus Development Philosophy

The Bonus implementation will follow the same methodology used throughout the project.

Each feature will be developed through the following cycle:

```text
Theory
   │
   ▼
Mathematical Model
   │
   ▼
Architecture
   │
   ▼
Implementation
   │
   ▼
Integration
   │
   ▼
Testing
   │
   ▼
Visual Validation
   │
   ▼
Stable Feature
```

A Bonus feature will only be considered complete once its mathematical behaviour, implementation, integration, and rendering behaviour have been validated.

---

# Milestone 1 — Phong Specular Reflection

The first Bonus extension is the addition of specular reflection in order to extend the existing ambient + diffuse lighting model into a complete Phong reflection model.

### Objectives

* Understand the Phong reflection model.
* Implement the specular component mathematically.
* Calculate the reflection direction of the incoming light.
* Calculate the view direction.
* Introduce a shininess/specular parameter.
* Integrate specular contribution with the existing lighting system.
* Preserve ambient and diffuse lighting.
* Ensure specular contribution respects shadows where appropriate.
* Clamp the final accumulated colour.

### Target Lighting Pipeline

```text
Surface Hit
     │
     ├── Ambient
     │
     ├── Diffuse
     │
     └── Specular
            │
            ▼
      Light Contribution
            │
            ▼
      Final Surface Colour
```

### Validation

* Matte surface.
* Shiny surface.
* Different viewing directions.
* Different light directions.
* Different shininess values.
* Shadowed surfaces.
* Multiple objects.

### Status

⏳ Pending

---

# Milestone 2 — Checkerboard Pattern

The second Bonus feature introduces colour disruption through a checkerboard pattern.

### Objectives

* Understand spatial pattern evaluation.
* Implement alternating colour regions.
* Determine the pattern from the appropriate surface coordinates.
* Integrate the pattern with the existing material colour system.
* Preserve the existing lighting model.
* Support checkerboard behaviour on the relevant primitives.
* Validate pattern boundaries and orientation.

### Target Pipeline

```text
Ray
 │
 ▼
Intersection
 │
 ▼
Surface Point
 │
 ▼
Pattern Evaluation
 │
 ├── Colour A
 │
 └── Colour B
 │
 ▼
Lighting
 │
 ▼
Final Colour
```

### Validation

* Sphere with checkerboard.
* Plane with checkerboard.
* Cylinder with checkerboard.
* Different object positions.
* Pattern boundaries.
* Pattern under shadows.
* Pattern combined with specular reflection.

### Status

⏳ Pending

---

# Milestone 3 — Colored and Multi-Spot Lights

The third Bonus feature extends the existing lighting system to support coloured and multiple spot lights.

The Mandatory implementation already contains the basic infrastructure for multiple lights, making this extension an evolution of the existing lighting system rather than a new lighting architecture.

### Objectives

* Support coloured light sources.
* Preserve light intensity handling.
* Calculate coloured diffuse contributions.
* Support multiple simultaneous lights.
* Accumulate contributions from all visible lights.
* Perform shadow testing independently for each light.
* Prevent colour overflow through final clamping.
* Validate interaction between multiple coloured lights.

### Target Architecture

```text
                 ┌── Light 1
                 │
Surface Hit ─────┼── Light 2
                 │
                 ├── Light 3
                 │
                 └── Light N
                        │
                        ▼
                 Light Contributions
                        │
                        ▼
                 Colour Accumulation
                        │
                        ▼
                  Final Colour
```

### Validation

* One coloured light.
* Multiple lights with identical colours.
* Multiple lights with different colours.
* Different light intensities.
* Overlapping light contributions.
* Shadows from individual lights.
* Coloured lights combined with specular reflection.
* Coloured lights combined with checkerboard patterns.

### Status

⏳ Pending

---

# Milestone 4 — Additional Second-Degree Object

The fourth Bonus feature introduces one additional second-degree geometric primitive.

The subject allows several choices:

* Cone
* Hyperboloid
* Paraboloid

The final primitive will be selected according to the existing architecture and implementation complexity.

### Objectives

* Derive the mathematical intersection equation.
* Implement ray-object intersection.
* Solve the resulting quadratic equation.
* Validate the resulting roots against the object's bounds.
* Implement surface normal calculation.
* Integrate the primitive with generic object dispatch.
* Integrate the primitive with the existing lighting system.
* Support shadows.
* Support the existing material/pattern system where applicable.

### Target Geometry Pipeline

```text
Primary Ray
     │
     ▼
Object Intersection
     │
     ▼
Quadratic Solver
     │
     ▼
Valid Roots
     │
     ▼
Closest Hit
     │
     ▼
Surface Normal
     │
     ▼
Lighting
```

### Validation

* Direct hit.
* Miss.
* Tangent hit.
* Multiple intersections.
* Object boundaries.
* Inside-object rays.
* Rotated object.
* Translated object.
* Shadows.
* Interaction with existing primitives.

### Status

⏳ Pending

---

# Milestone 5 — Bump Map Textures

The fifth Bonus feature introduces bump map textures.

The purpose is to modify the perceived surface detail through normal perturbation without changing the underlying geometric intersection.

### Objectives

* Understand bump mapping mathematically.
* Introduce texture representation.
* Map surface coordinates to texture coordinates.
* Sample the bump map.
* Calculate normal perturbation.
* Integrate the perturbed normal into the lighting system.
* Preserve the original geometric intersection.
* Support bump mapping together with existing lighting.
* Validate behaviour across different primitives.

### Target Pipeline

```text
Ray
 │
 ▼
Geometric Intersection
 │
 ▼
Surface Point
 │
 ▼
Texture Coordinates
 │
 ▼
Bump Map Sampling
 │
 ▼
Normal Perturbation
 │
 ▼
Modified Surface Normal
 │
 ▼
Lighting
 │
 ▼
Final Colour
```

### Validation

* Surface without bump map.
* Surface with a simple bump map.
* Different bump intensities.
* Different light directions.
* Bump map under shadows.
* Bump map combined with specular reflection.
* Bump map combined with checkerboard/material features.

### Status

⏳ Pending

---

# Milestone 6 — Bonus Integration

After each individual feature has been implemented and validated, all Bonus systems will be tested together.

### Target Feature Interaction

```text
                    ┌── Phong Specular
                    │
                    ├── Checkerboard
Scene ──► Objects ──┼── Colored Lights
                    │
                    ├── Additional Primitive
                    │
                    └── Bump Mapping
                            │
                            ▼
                       Final Renderer
```

### Integration Tests

The final Bonus scenes will combine multiple features rather than testing each feature in isolation only.

Examples:

```text
Checkerboard + Specular
Checkerboard + Colored Lights
Specular + Multiple Lights
Bump Mapping + Specular
Bump Mapping + Colored Lights
Additional Object + Shadows
Additional Object + Checkerboard
All Bonus Features Combined
```

### Status

⏳ Pending

---

# Milestone 7 — Bonus Parser & Scene Format

The subject explicitly allows modifications and additions to the scene description format when necessary to support Bonus features.

The parser will therefore be extended only after the underlying Bonus functionality has been implemented and validated internally.

### Objectives

* Define clear Bonus scene syntax.
* Extend token recognition.
* Validate Bonus-specific parameters.
* Preserve all Mandatory syntax.
* Handle invalid Bonus configurations.
* Maintain clean parser error handling.
* Document the extended scene format.

### Development Principle

```text
Feature
   │
   ▼
Internal Representation
   │
   ▼
Renderer
   │
   ▼
Testing
   │
   ▼
Parser Support
   │
   ▼
Scene Format Documentation
```

### Status

⏳ Pending

---

# Milestone 8 — Bonus Testing

Every Bonus feature will have dedicated tests.

## Functional Tests

```text
Valid Scene
     │
     ▼
Feature Enabled
     │
     ▼
Expected Behaviour
```

## Invalid Input Tests

```text
Missing Parameter
Invalid Parameter
Invalid Range
Invalid Syntax
Invalid Combination
Unknown Identifier
```

## Mathematical Edge Cases

```text
Zero Values
Negative Values
Boundary Values
Extreme Values
Tangent Rays
Parallel Rays
Inside / Outside Objects
```

## Visual Tests

Dedicated `.rt` scenes will be created for every Bonus feature.

The test collection will contain both isolated feature scenes and combined Bonus scenes.

### Status

⏳ Pending

---

# Milestone 9 — Memory & Stability Validation

Once all Bonus features are integrated, the complete program will undergo a final memory and stability audit.

### Objectives

* Verify all Bonus allocations are freed.
* Verify texture cleanup.
* Verify additional object cleanup.
* Verify parser cleanup on invalid Bonus scenes.
* Verify light cleanup.
* Verify MLX resource cleanup.
* Check for double frees.
* Check for invalid memory access.
* Check for leaks.
* Verify repeated execution.

### Required Conditions

```text
No Segmentation Fault
No Double Free
No Invalid Access
No Memory Leak
No Regression
```

### Status

⏳ Pending

---

# Milestone 10 — Final Bonus Audit

The final stage will compare the implementation directly against the official Bonus requirements.

| Official Bonus                  | Implemented | Tested | Integrated | Validated |
| ------------------------------- | ----------- | ------ | ---------- | --------- |
| Phong Specular Reflection       | ☐           | ☐      | ☐          | ☐         |
| Checkerboard Pattern            | ☐           | ☐      | ☐          | ☐         |
| Colored Lights                  | ☐           | ☐      | ☐          | ☐         |
| Multi-Spot Lights               | ☐           | ☐      | ☐          | ☐         |
| Additional Second-Degree Object | ☐           | ☐      | ☐          | ☐         |
| Bump Map Textures               | ☐           | ☐      | ☐          | ☐         |

The final audit will also verify that:

* Mandatory behaviour remains intact.
* Bonus files follow the required project structure.
* The `bonus` Makefile rule is correct.
* Bonus code passes the Norm.
* All allocated memory is released.
* The README documents the Bonus functionality.
* Test scenes are available for evaluation and defence.

---

# Complete Bonus Roadmap

```text
MANDATORY COMPLETE
        │
        ▼
Bonus Infrastructure
        │
        ▼
Milestone 1
Phong Specular Reflection
        │
        ▼
Milestone 2
Checkerboard Pattern
        │
        ▼
Milestone 3
Colored & Multi-Spot Lights
        │
        ▼
Milestone 4
Additional Second-Degree Object
        │
        ▼
Milestone 5
Bump Map Textures
        │
        ▼
Milestone 6
Bonus Integration
        │
        ▼
Milestone 7
Bonus Parser
        │
        ▼
Milestone 8
Bonus Testing
        │
        ▼
Milestone 9
Memory & Stability
        │
        ▼
Milestone 10
Final Audit
        │
        ▼
BONUS COMPLETE
```

---

# Development Rules

The Bonus phase will continue following the project's original development philosophy.

### 1. Understand Before Implementing

Every mathematical model and rendering technique will be understood before implementation.

### 2. One Feature at a Time

Each Bonus feature will be completed and validated before moving to the next major feature.

### 3. Preserve Mandatory Behaviour

Bonus development must never compromise the completed Mandatory implementation.

### 4. Separate Responsibilities

Geometry, materials, lighting, textures, parsing, and rendering should remain independent wherever possible.

### 5. Validate Mathematically and Visually

Every feature will be verified through both mathematical reasoning and rendered test scenes.

### 6. Test Interactions

A feature is not considered fully complete until it works together with the existing renderer and other completed Bonus features.

### 7. Maintain Memory Safety

All Bonus allocations and error paths must remain leak-free and safe.

---

# Current Objective

The Mandatory part of MiniRT is complete and validated.

The project has now entered the Bonus development phase.

The immediate objective is to implement the official Bonus features incrementally, beginning with the extension of the existing lighting model and continuing through patterns, coloured and multiple lights, additional geometry, and bump mapping.

The current development direction is:

```text
Mandatory Engine                  ✅
        │
        ▼
Bonus Infrastructure              🟢
        │
        ▼
Phong Specular Reflection         ⏳
        │
        ▼
Checkerboard Pattern              ⏳
        │
        ▼
Colored & Multi-Spot Lights       ⏳
        │
        ▼
Additional Second-Degree Object   ⏳
        │
        ▼
Bump Map Textures                 ⏳
        │
        ▼
Bonus Integration                 ⏳
        │
        ▼
Bonus Testing                     ⏳
        │
        ▼
Memory & Stability                ⏳
        │
        ▼
Final Audit                       ⏳
        │
        ▼
BONUS COMPLETE
```

The project has transitioned from **building and validating the Mandatory ray tracer** to **extending the completed engine with the official Bonus features while preserving mathematical correctness, architectural consistency, rendering quality, and memory safety**.
