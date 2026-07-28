/*
! Union

//////////////////////////////////////
## Introduction
//////////////////////////////////////

A **union** is a user-defined data type in C that allows multiple members
to share the **same memory location**.

Unlike a structure (`struct`), where each member has its own memory,
a union stores all of its members in a single shared memory block.

This means:

* Only one member can hold a meaningful value at a time.
* Writing to one member overwrites the previous member's data.

The size of a union is determined by the size of its **largest member**.

---

## Why do we need it?

Sometimes, the same memory can represent different types of data,
but never at the same time.

Instead of allocating separate memory for each possible type,
a union lets all members reuse the same memory block.

This provides two main advantages:

* Saves memory.
* Allows one piece of memory to be interpreted in different ways.

---

## Core Idea

Think of a union as **one storage box with multiple labels**.

```

```
        +----------------------+
```

int number  |                      |
float value |      Same Memory     |
char c      |                      |
+----------------------+

````

Although there are multiple member names, there is only **one memory area**.

If you write through one member, all other members now refer to that same
memory with a different interpretation.

---

## Syntax

```c
union Data
{
    int   number;
    float value;
    char  letter;
};
````

Creating a variable:

```c
union Data data;
```

Accessing members:

```c
data.number = 42;
```

or

```c
data.value = 3.14f;
```

---

## Memory Layout

Suppose we have:

```c
union Data
{
    int   number;   // 4 bytes
    float value;    // 4 bytes
    char  letter;   // 1 byte
};
```

Memory:

```
Address

0x1000
+--------------------+
|                    |
|   Shared Memory    |
|                    |
+--------------------+

number
value
letter
```

All members begin at the **same address**.

If `int` and `float` are both 4 bytes, then:

```
sizeof(union Data) == 4
```

because the largest member occupies 4 bytes.

---

## Example 1

```c
union Data
{
    int number;
    float value;
};

union Data data;

data.number = 100;
```

Current value:

```
number = 100
```

Now write:

```c
data.value = 5.5f;
```

The previous integer value is overwritten.

The union now contains:

```
value = 5.5
```

Reading `number` after this does **not** give the original value anymore.

---

## Example 2

```c
union Character
{
    char letter;
    int  number;
};

union Character c;

c.letter = 'A';
```

The shared memory now contains the byte representing `'A'`.

If you later write:

```c
c.number = 100;
```

the previous character is replaced.

---

## Union vs Struct

```c
struct Example
{
    int   a;
    float b;
    char  c;
};
```

Memory:

```
+-----+-----+-----+
|  a  |  b  |  c  |
+-----+-----+-----+
```

Each member has its own storage.

---

```c
union Example
{
    int   a;
    float b;
    char  c;
};
```

Memory:

```
+------------------+
| Shared Memory    |
+------------------+

a
b
c
```

All members occupy the same location.

---

## Mental Model

Imagine a single parking space.

```
+-----------+
| Parking   |
|   Space   |
+-----------+
```

Different vehicles can use it:

* Car
* Motorcycle
* Bicycle

But only **one vehicle can be parked there at a time**.

A union behaves the same way.

It has multiple possible members,
but only one occupies the shared memory at any given moment.

---

## Common Beginner Mistakes

### Mistake 1: Thinking all members exist simultaneously

Many beginners expect every member to keep its own value.

This is false.

All members share the same memory.

Writing to one replaces the previous content.

---

### Mistake 2: Expecting the size to be the sum of all members

Example:

```c
union Example
{
    int a;      // 4
    double b;   // 8
    char c;     // 1
};
```

The size is:

```
8 bytes
```

Not:

```
13 bytes
```

because only the largest member determines the union's size.

---

### Mistake 3: Reading a different member than the one written

Example:

```c
data.number = 42;

printf("%f", data.value);
```

The result is generally meaningless because the same bits are being interpreted
as a different type.

---

### Mistake 4: Confusing union with struct

A `struct` stores all members independently.

A `union` stores only one meaningful member at a time.

---

## When is a Union Useful?

Typical use cases include:

* Saving memory when only one value is needed at a time.
* Representing data that may have different types.
* Low-level programming.
* Embedded systems.
* Hardware registers.
* Binary file formats.
* Network protocols.

---

## Golden Idea

A **union** allows multiple members to share **one memory location**.

Only one member should be considered valid at a time.

Writing to one member replaces the data of all the others.

---

## Key Takeaways

* A **union** stores all members in the **same memory location**.
* The size of a union equals the size of its **largest member**.
* All members begin at the same memory address.
* Writing to one member overwrites the previous data.
* A union saves memory because members do not have separate storage.
* Unlike a `struct`, only one member should contain meaningful data at a time.

---

| Concept | Meaning                                                         |
| ------- | --------------------------------------------------------------- |
| union   | Multiple members share one memory block                         |
| Memory  | Shared between all members                                      |
| Size    | Largest member only                                             |
| Write   | Overwrites previous value                                       |
| Purpose | Memory efficiency and multiple interpretations of the same data |

*/

