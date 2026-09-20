
````md
## Bonus Roadmap

The Mandatory part has been fully implemented, tested, and stabilized.

The project architecture was designed with extensibility in mind, allowing the Bonus features to be added without breaking the existing Mandatory implementation.

### Development Philosophy

Each Bonus feature follows the same development workflow:

> Theory → Mathematical Model → Architecture → Implementation → Integration → Testing → Visual Validation → Stability

The goal is to understand and validate each feature before moving to the next one.

---

### Bonus Features

#### 1. Phong Specular Reflection — COMPLETED

Implemented the specular component of the Phong illumination model.

The lighting model now supports:

- Ambient lighting
- Diffuse lighting
- Specular reflection
- Configurable material shininess
- Light-dependent specular highlights
- Shadow-aware specular contribution

The material now supports an optional `shininess` parameter.

Example:

```text
sp 0,0,0 10 255,0,0 32
````

If the shininess parameter is omitted, the object keeps the Mandatory behavior and produces no specular highlight.

#### Validation

The following cases were tested:

* Reflection vector calculation
* View direction calculation
* Reflection/view dot product
* Negative dot product clamping
* Different shininess values
* Specular highlight visibility
* Specular behavior with shadows
* Objects with and without specular highlights
* Multiple objects with different shininess values
* Parser support for optional shininess
* Mandatory scene regression

Visual comparison confirmed that higher shininess values produce smaller and more concentrated highlights.

---

#### 2. Checkerboard Pattern — NEXT

Implement a procedural checkerboard pattern that can be applied to supported objects.

Planned pipeline:

```text
Ray
 ↓
Intersection
 ↓
Surface Position
 ↓
Pattern Evaluation
 ↓
Base Color
 ↓
Lighting
 ↓
Final Color
```

The pattern system will be designed independently from the lighting system so that it can correctly interact with:

* Diffuse lighting
* Specular reflection
* Shadows
* Different object types

Planned validation:

* Checkerboard on a plane
* Checkerboard on a sphere
* Checkerboard on a cylinder
* Pattern boundaries
* Pattern scaling/orientation
* Checkerboard + specular reflection
* Checkerboard + shadows
* Mandatory regression

---

#### 3. Colored and Multiple Spot Lights — PLANNED

Extend the lighting system to support multiple colored light sources.

Planned architecture:

```text
For each light:
    Calculate visibility
    Calculate diffuse contribution
    Calculate specular contribution
    Accumulate contribution
```

Planned validation:

* Single white light
* Single colored light
* Multiple lights
* Different light colors
* Independent shadows
* Colored light + specular reflection
* Colored light + checkerboard

---

#### 4. Additional Second-Degree Object — PLANNED

Add one additional second-degree object supported by the Bonus specification.

Candidate:

* Cone

Implementation will include:

* Mathematical equation
* Ray/object intersection
* Quadratic solution
* Valid intersection interval
* Surface normal calculation
* Object dispatch
* Shadow interaction
* Lighting interaction

Planned validation:

* Hit
* Miss
* Tangent
* Inside-object rays
* Different orientations
* Shadows
* Lighting
* Mandatory regression

---

#### 5. Bump Map Textures — PLANNED

Implement bump mapping without changing the actual geometry.

Planned pipeline:

```text
Ray
 ↓
Intersection
 ↓
Original Normal
 ↓
Bump Map Sampling
 ↓
Modified Normal
 ↓
Phong Lighting
 ↓
Final Color
```

The implementation will include:

* Texture representation
* Texture loading
* Texture sampling
* Object coordinate mapping
* Normal perturbation
* Lighting integration

Planned validation:

* No bump map
* Basic bump map
* Strong bump map
* Sphere
* Cylinder
* Bump map + specular reflection
* Bump map + shadows

---

## Bonus Integration

After implementing all individual features, the Bonus implementation will be validated as a complete system.

### Combined Feature Tests

Test interactions between:

* Specular + Checkerboard
* Specular + Multiple Lights
* Checkerboard + Multiple Lights
* Checkerboard + Shadows
* Bump Mapping + Specular
* Bump Mapping + Multiple Lights
* Additional Object + Specular
* Additional Object + Shadows
* All compatible Bonus features together

---

## Bonus Parser

The parser will be extended only when required by each Bonus feature.

Current parser extension:

```text
Sphere:
sp POSITION DIAMETER COLOR [SHININESS]

Plane:
pl POSITION NORMAL COLOR [SHININESS]

Cylinder:
cy POSITION ORIENTATION DIAMETER HEIGHT COLOR [SHININESS]

Triangle:
tr POINT_A POINT_B POINT_C COLOR [SHININESS]
```

The Bonus parameters remain optional so existing Mandatory `.rt` scenes continue to work.

---

## Testing Strategy

Every Bonus feature must pass the following validation stages:

```text
[✓] Theory understood
[✓] Formula understood
[✓] Architecture decided
[✓] Implementation complete
[✓] Parser support
[✓] Basic test
[✓] Edge cases
[✓] Visual test
[✓] Mandatory regression
[ ] Norminette
[ ] Valgrind
[ ] Git commit
```

For each new feature, the checklist is reset and completed independently before moving to the next feature.

---

## Current Bonus Status

```text
Bonus Progress

[✓] 1. Phong Specular Reflection
[ ] 2. Checkerboard Pattern
[ ] 3. Colored and Multiple Spot Lights
[ ] 4. Additional Second-Degree Object
[ ] 5. Bump Map Textures
[ ] 6. Bonus Integration
[ ] 7. Final Bonus Parser Validation
[ ] 8. Complete Bonus Test Suite
[ ] 9. Memory & Stability Validation
[ ] 10. Final Bonus Audit
```

### Current Milestone

**Milestone 1 — Phong Specular Reflection: COMPLETED**

The project is now ready to proceed to:

**Milestone 2 — Checkerboard Pattern**

```

**هذه هي النسخة التي أنصح بوضعها الآن**؛ وبعد إنهاء Checkerboard سنعود ونحدّث حالة Milestone 2 بنفس الأسلوب بدل تعديل الخطة كاملة كل مرة.
```
