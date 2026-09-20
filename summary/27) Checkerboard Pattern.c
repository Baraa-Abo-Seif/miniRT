┌────┬────┬────┬────┐
│ A  │ B  │ A  │ B  │
├────┼────┼────┼────┤
│ B  │ A  │ B  │ A  │
├────┼────┼────┼────┤
│ A  │ B  │ A  │ B  │
└────┴────┴────┴────┘

                 Surface Point
                       │
                       ▼
                Pattern Coordinates
                       │
             ┌─────────┴─────────┐
             │                   │
          floor(x)            floor(y)
             │                   │
             └─────────┬─────────┘
                       │
                  + floor(z)
                       │
                       ▼
                    parity
                  /        \
              even        odd
                │            │
                ▼            ▼
             Color A       Color B




   P = (x, y, z)

value = floor(x) + floor(y) + floor(z)

if value % 2 == 0
    Color A
else
    Color B
    
    
Ray
 ↓
Intersection
 ↓
Surface Point
 ↓
Pattern Coordinates
 ↓
Checker Evaluation
 ↓
Base Color
 ↓
Ambient + Diffuse + Specular
 ↓
Final Color
