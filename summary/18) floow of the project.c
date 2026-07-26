./miniRT scene.rt
//! steps
/*
    ~ 1) Read the scene file and parse its contents to extract information about the objects, lights, and camera settings.
            User
            ↓
            scene.rt
            ↓
            Load Scene


    ~ 2) Initialize the rendering engine and set up the necessary data structures to hold the scene information.

            User
            ↓
            scene.rt
            ↓
            Load Scene
            ↓
            Parse Scene
            ↓
            Build Scene

    ~ 3) For each pixel in the output image, cast a ray from the camera through the pixel and into the scene to determine what object (if any) the ray intersects.

            User
            ↓
            scene.rt
            ↓
            Load Scene
            ↓
            Parse Scene
            ↓
            Build Scene
            ↓
            Camera
            ↓
            Generate Ray
            ↓
            Intersection
            ↓
            Lighting
            ↓
            Pixel Color
            ↓
            Image 



*/


Scene

↓

Camera

↓

Ray

↓

Objects

↓

Light

↓

Pixel

//////////////////////

Parser

↓

Scene

↓

Renderer


              scene.rt
                  │
                  ▼
             ┌─────────┐
             │ Parser  │
             └─────────┘
                  │
                  ▼
             ┌─────────┐
             │  Scene  │
             └─────────┘
                  │
                  ▼
             ┌─────────┐
             │Renderer │
             └─────────┘
          ┌─────┼─────┬──────┐
          ▼     ▼     ▼      ▼
      Camera Objects Lighting Image







      Parser

↓

Build Scene

↓

Scene

↓

Renderer

------------------

main()

↓

Scene

↓

Parser fills it

↓

Renderer uses it

↓

Destroy Scene

↓

Exit
---------------
Renderer

↓

Uses

NOT

Owns

main()

↓

Create Scene

↓

Parser

↓

Fill Scene

↓

Renderer

↓

Read Scene

↓

Destroy Scene

↓

Exit
------------------

Parser
Build Scene
Renderer
Use Scene
Main
Own Scene

----------------
المشروع عبارة عن Pipeline.

✅ الـ Parser يبني الـ Scene.

✅ الـ Renderer لا يملك الـ Scene.

✅ الـ Renderer يستخدم الـ Scene فقط.

✅ الـ Renderer لا يعرف تفاصيل الـ Sphere أو الـ Plane.

✅ الـ Intersector سيكون مسؤولًا عن الاصطدامات.

✅ الـ Main سيكون المالك الحقيقي للـ Scene.
-----------------------------
Math

↓

يعرف الأرقام.
Parser

↓

يعرف الملف.
Camera

↓

تعرف توليد Rays.
Lighting

↓

تعرف حساب اللون.
Renderer

↓

يعرف كيف ينسق بين الجميع.

-------------------------

Phase 1

Initialization

↓

Parse

↓

Build Scene

──────────────────────────

Phase 2

Rendering

↓

Generate Rays

↓

Intersections

↓

Lighting

↓

Pixels

-----------------------
                main()

                   │

        ┌──────────┴──────────┐

        ▼                     ▼

 Initialization          Rendering

(Parser)              (Renderer Engine)


main()

│

▼

Scene

├──────────────┐
│              │
▼              ▼

Camera      Lights

│

▼

Objects

│

▼

Object

│

▼

Object

│

▼

Object

بدل أن نفكر في ملفات، فكر في أشخاص.

👨‍💼 Parser

"أنا أقرأ الملف فقط."

📷 Camera

"أنا أعرف كيف أُولد الأشعة فقط."

💡 Lighting

"أنا أعرف كيف أحسب الإضاءة فقط."

⚪ Object

"أنا فقط أخزن بياناتي."

🎬 Renderer

"أنا المدير... أطلب من كل شخص أن يقوم بوظيفته."

              main()

                 │

                 ▼

               Scene

        ┌────────┼────────┐

        ▼        ▼        ▼

    Camera    Lights   Objects

        ▲                  ▲
        │                  │

        └────── Renderer ──┘



        File

↓

Parser

↓

Scene

↓

Renderer


Renderer

↓

Read Camera

↓

Camera Setup

↓

for every Pixel

    ↓

Generate Ray

    ↓

Find Intersection

    ↓

Nearest Hit

    ↓

Lighting

    ↓

Write Pixel






File

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


كل Module أصبح يعرف شيئًا واحدًا فقط.

Parser

يعرف:

File

↓

Scene
Camera

تعرف:

Generate Ray
Intersector

يعرف:

Ray

↓

Hit
Lighting

يعرف:

Hit

↓

Color
Renderer

يعرف:

كيف يجعل الجميع يعملون معًا.

وليس كيف ينفذ كل العمليات بنفسه.



