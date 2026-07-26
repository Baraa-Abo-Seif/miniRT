//! ============================================================================
//! MiniRT Architecture
//! ============================================================================

/*

###############################################################################
# The Big Picture
###############################################################################

MiniRT is a rendering pipeline.

The entire project can be summarized as:

        scene.rt
            │
            ▼
        Parse Scene
            │
            ▼
        Build Scene
            │
            ▼
        Render Image
            │
            ▼
        Display Window

Everything in the project belongs to one of these two phases.

===============================================================================
Phase 1 : Initialization
===============================================================================

scene.rt

↓

Parser

↓

Build Scene

↓

Scene

The parser only reads the file.

Its responsibility is:

• Read the scene file.
• Validate the input.
• Create all scene objects.
• Fill the Scene structure.

Once parsing finishes...

Its job is over.

===============================================================================
Phase 2 : Rendering
===============================================================================

Scene

↓

Renderer

↓

Camera

↓

Generate Rays

↓

Intersections

↓

Lighting

↓

Pixel Color

↓

Image Buffer

↓

Window

The renderer never reads the file.

It only uses the already-built Scene.

===============================================================================
Overall Pipeline
===============================================================================

scene.rt

↓

Parser

↓

Scene

↓

Renderer

↓

Camera

↓

Generate Ray

↓

Intersector

↓

Hit Record

↓

Lighting

↓

Pixel Color

↓

Image Buffer

↓

Window

###############################################################################
# Scene Ownership
###############################################################################

The Scene has only one owner.

main()

↓

Create Scene

↓

Parser fills it

↓

Renderer uses it

↓

Destroy Scene

↓

Exit

Important:

• main() owns the Scene.
• Parser builds the Scene.
• Renderer only reads the Scene.

The renderer never owns it.

###############################################################################
# Scene Structure
###############################################################################

                Scene

        ┌────────┼────────┐
        ▼        ▼        ▼

    Camera    Lights   Objects

The Scene is simply a container.

It stores everything required to render the image.

###############################################################################
# Module Responsibilities
###############################################################################

Every module knows only one job.

Parser

↓

File

↓

Scene

----------------------------------------

Camera

↓

Generate Rays

----------------------------------------

Intersector

↓

Ray

↓

Nearest Hit

----------------------------------------

Lighting

↓

Hit Record

↓

Final Color

----------------------------------------

Renderer

↓

Coordinates everything

It does NOT perform every calculation itself.

###############################################################################
# Rendering Flow
###############################################################################

Renderer

↓

Read Camera

↓

Camera Setup

↓

for each Pixel

↓

Generate Ray

↓

Find Nearest Intersection

↓

Compute Lighting

↓

Write Pixel

↓

Next Pixel

###############################################################################
# Design Philosophy
###############################################################################

Think of the project as a team.

👨‍💼 Parser

"I only read the file."

────────────────────────

📷 Camera

"I only generate rays."

────────────────────────

🎯 Intersector

"I only find what the ray hits."

────────────────────────

💡 Lighting

"I only compute the final color."

────────────────────────

⚪ Objects

"We only store geometry."

────────────────────────

🎬 Renderer

"I coordinate everyone."

###############################################################################
# Layered Architecture
###############################################################################

                main()

                   │

                   ▼

                 Scene

        ┌────────┼────────┐

        ▼        ▼        ▼

    Camera    Lights   Objects

        ▲                  ▲
        │                  │

        └──── Renderer ────┘

Renderer never owns Camera or Objects.

It simply asks them to perform their jobs.

###############################################################################
# Golden Idea
###############################################################################

MiniRT is not one huge algorithm.

It is a collection of small modules.

Each module has exactly one responsibility.

The renderer simply connects them together.

###############################################################################
# Key Takeaways
###############################################################################

• MiniRT is a rendering pipeline.
• Parsing and Rendering are two separate phases.
• The Parser builds the Scene.
• The Renderer only uses the Scene.
• main() owns the Scene.
• Camera generates Rays.
• Intersector finds intersections.
• Lighting computes colors.
• Renderer coordinates all modules.
• Every module should have one clear responsibility.

*/
