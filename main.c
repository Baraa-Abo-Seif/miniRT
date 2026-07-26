MiniRT

│

├── main
│      │
│      ├── Initialize
│      ├── Parse Scene
│      ├── Initialize Renderer
│      ├── Start Rendering
│      └── Cleanup
│
├── Scene
│      │
│      ├── Camera
│      ├── Ambient
│      ├── Lights
│      └── Objects
│
├── Parser
│      │
│      ├── Read File
│      ├── Validate
│      ├── Parse Camera
│      ├── Parse Ambient
│      ├── Parse Lights
│      ├── Parse Objects
│      └── Build Scene
│
├── Camera
│      │
│      ├── Initialize Camera
│      ├── Compute Camera Basis
│      ├── Compute Viewport
│      └── Generate Primary Ray
│
├── Objects
│      │
│      ├── Sphere
│      ├── Plane
│      ├── Cylinder
│      ├── Object List
│      └── Object Utilities
│
├── Math
│      │
│      ├── Vector
│      ├── Point
│      ├── Matrix (Future)
│      ├── Color
│      └── Utilities
│
├── Intersector
│      │
│      ├── Sphere Intersection
│      ├── Plane Intersection
│      ├── Cylinder Intersection
│      ├── Find Nearest Hit
│      └── Build Hit Record
│
├── Lighting
│      │
│      ├── Ambient
│      ├── Diffuse
│      ├── Specular
│      ├── Shadow
│      └── Final Color
│
├── Renderer
│      │
│      ├── Render Loop
│      ├── Generate Ray
│      ├── Ask Intersector
│      ├── Ask Lighting
│      └── Write Pixel
│
└── MLX
       │
       ├── Init
       ├── Window
       ├── Image Buffer
       ├── Put Pixel
       └── Display Image



       main()

↓

scene_create()

↓

parse_scene(scene)

↓

render(scene)

↓

scene_destroy()