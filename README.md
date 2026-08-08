# Project Overview

MiniRT is being developed following a milestone-based roadmap where each
stage is completed only after its underlying theory, architecture, and
implementation have been fully understood.

The project prioritises understanding over speed, ensuring that every
algorithm, mathematical concept, and architectural decision is mastered
before moving to the next milestone.

---

## Current Progress

| Area                   | Status |
| ---------------------- | ------ |
| Mathematics            | ✅ Completed |
| Core Math Library      | ✅ Completed |
| Architecture Design    | ✅ Completed |
| Core Engine Foundation | ✅ Completed |
| Parser                 | ✅ Completed |
| MLX Integration        | ✅ Completed |
| Camera System          | ⏳ Pending |
| Ray Generation         | ⏳ Pending |
| Intersections           | ⏳ Pending |
| Lighting               | ⏳ Pending |
| Rendering Pipeline      | ⏳ Pending |
| Bonus Features          | ⏳ Pending |
| Final Validation        | ⏳ Pending |

---

## Overall Completion

```text
████████████████░░░░░░░░░░░░░░ 50%
```


Current Stage

Milestone 4 — Camera & Ray Generation

The MLX integration milestone has been completed and validated.

The project now has a working graphical foundation including:

Window creation and destruction
Image creation and destruction
Image buffer access
Pixel manipulation
Image display
Event initialisation
Window close handling
Keyboard event handling
MLX event loop
Clean resource destruction

The MLX layer has also been tested independently using a dedicated
integration test.

Milestone 4 — Camera & Ray Generation
Objective

Build the complete mathematical and architectural foundation required to
generate primary rays from the camera through every pixel of the image.

This milestone connects the existing mathematical library with the future
rendering pipeline.

4.1 Camera Structure

Implement the camera abstraction.

Required data
Camera origin
Camera orientation
Camera forward direction
Camera right direction
Camera up direction
Field of view
Image aspect ratio
Viewport dimensions
Required work
Define the camera structure
Create the camera constructor
Validate camera parameters
Keep the camera independent from MLX
Use the existing tuple/vector mathematics
4.2 Camera Orientation

Implement camera orientation using the existing vector mathematics.

Required concepts
Forward direction
Up direction
Right direction
Orthogonal basis
Normalisation
Cross product
Dot product
Required work
Build an orthonormal camera basis
Ensure the three camera axes remain perpendicular
Handle normalisation correctly
Avoid duplicated vector logic
Integrate with the existing math library
4.3 Field of View

Implement the camera field-of-view system.

Required concepts
Horizontal field of view
Vertical field of view
Aspect ratio
Half viewport size
Perspective projection
Required work
Convert the camera FOV into the required viewport dimensions
Account for image aspect ratio
Calculate half-width and half-height
Use the correct trigonometric relationships
Verify the resulting viewport mathematically
4.4 Pixel-to-Viewport Mapping

Implement the mapping between image pixels and the camera viewport.

Required work

For every pixel:

Convert the pixel coordinate into normalised image coordinates.
Convert the normalised coordinates into viewport coordinates.
Translate the viewport position relative to the camera.
Construct the corresponding point on the image plane.
Important considerations
Pixel centre sampling
Image coordinate system
Viewport coordinate system
Horizontal orientation
Vertical orientation
Aspect ratio
FOV scaling
4.5 Primary Ray Generation

Implement the first complete camera ray-generation pipeline.

For every pixel:

Determine the pixel centre.
Map the pixel to the viewport.
Determine the corresponding point on the image plane.
Calculate the direction from the camera origin to that point.
Normalise the direction.
Construct the ray.

Required result
```
Camera
   │
   ▼
Pixel
   │
   ▼
Viewport Position
   │
   ▼
Image Plane Point
   │
   ▼
Ray Direction
   │
   ▼
Primary Ray
```

4.6 Ray Structure

Define the ray abstraction.

Required data
Ray origin
Ray direction
Required functions
Ray constructor
Ray position at time/distance t
Ray transformation helpers if required by the architecture
Mathematical relationship
P(t) = O + D × t

Where:

O = ray origin
D = ray direction
t = distance along the ray
P(t) = resulting point
4.7 Camera API

Expose a clean camera interface.

The rendering layer should not need to know the internal details of the
camera implementation.

The camera API should provide the ability to:

Create a camera
Configure its position
Configure its orientation
Configure its FOV
Generate a ray for a pixel
Destroy the camera
4.8 Camera & Ray Tests

Before leaving Milestone 4, all camera and ray mathematics must be tested.

Required tests
Camera creation
Camera default orientation
Camera position
Camera orientation
Vector normalisation
Cross product
Dot product
FOV calculation
Aspect ratio handling
Viewport dimensions
Centre pixel ray
Corner pixel ray
Horizontal ray direction
Vertical ray direction
Ray origin
Ray direction normalisation
Ray position at different t values
Edge cases
Very small image
Very wide image
Very tall image
Different FOV values
Camera positioned away from the origin
Camera rotated from the default orientation
4.9 Integration Test

Create a dedicated camera/ray integration test.

The test must demonstrate that:

Camera
   ↓
Pixel
   ↓
Viewport
   ↓
Primary Ray

produces mathematically correct results.

The test should be independent from the final renderer.

4.10 Milestone 4 Completion Criteria

Milestone 4 is considered complete only when all of the following are
true:

 Camera structure implemented
 Camera constructor implemented
 Camera orientation implemented
 Orthonormal camera basis implemented
 FOV calculation implemented
 Aspect ratio handling implemented
 Viewport calculation implemented
 Ray structure implemented
 Ray constructor implemented
 Ray position function implemented
 Pixel-to-viewport mapping implemented
 Primary ray generation implemented
 Camera API cleaned and documented
 Unit tests completed
 Integration test completed
 -Wall -Wextra -Werror compilation succeeds
 No memory leaks
 Existing MLX integration remains functional
 Existing parser and math systems remain unaffected

----

Project Timeline
| Milestone               | Estimated Duration | Status |
| ----------------------- | -----------------: | ------ |
| Foundations             |          Completed | ✅      |
| Core Math Library       |          Completed | ✅      |
| Architecture            |          Completed | ✅      |
| Core Engine Foundation  |          Completed | ✅      |
| Parser                  |          Completed | ✅      |
| MLX Integration         |          Completed | ✅      |
| Camera & Ray Generation |            ~4 Days | 🟡     |
| Intersections           |            ~5 Days | ⏳      |
| Lighting                |            ~3 Days | ⏳      |
| Rendering Pipeline      |            ~2 Days | ⏳      |
| Bonus                   |            ~4 Days | ⏳      |
| Validation              |            ~2 Days | ⏳      |



⏳

Approximately 20 working days remain in the current roadmap.

This estimation assumes a steady development pace and may change as the
project evolves.

Current Objective

The immediate objective is to complete Milestone 4 — Camera & Ray
Generation.

The MLX layer is already complete and validated.

The next development cycle will therefore focus entirely on:

Camera
   ↓
Camera Orientation
   ↓
Viewport
   ↓
Pixel Mapping
   ↓
Primary Ray

Once Milestone 4 is completed and validated, the temporary Milestone 4
plan will be removed from this README and the project will move to the
Intersections milestone.
