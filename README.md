# **42 — CPP Module 00-04** 
<div align="center">
  <img src="https://i.imgur.com/gUzwHBa.jpeg" alt="cpp modules Banner" width="400">
</div>
<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue.svg" />
  <img src="https://img.shields.io/github/languages/top/HajerZam/cub3D-COCAINE?style=flat-square" />
  <img src="https://img.shields.io/github/repo-size/HajerZam/cub3D-COCAINE?style=flat-square" />
  <img src="https://img.shields.io/github/last-commit/HajerZam/cub3D-COCAINE?style=flat-square" />
  <img src="https://img.shields.io/github/issues/HajerZam/cub3D-COCAINE?style=flat-square" />
  <img src="https://img.shields.io/badge/42-Common%20Core-critical" />
  <img src="https://img.shields.io/badge/score-91-brightgreen?style=flat-square">
</p>

<p align="center">
  I feel like I am back at square one and CPP is like a C soup word (ᵕ • ᴗ •) 
</p>
<p align="center">so here are notes for fellow confused students!</p>

## **General Rules & Eval Traps** 
<div align="center">


```
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

|**Forbidden**|**Penalty**|
|---|---|
|`printf`/`scanf`/`*alloc`/`free`|Grade 0|
|`using namespace`or`friend`(anywhere)|Grade −42|
|STL containers / algorithms (before Module 08–09)|Grade −42|
|Function implementation in a header (non-template)|Grade 0|
|Missing include guards|Grade 0|
|C++11 / Boost features|Grade 0|



**MEMORY** Leaks are checked live with `valgrind` or `leaks` during defense. Every `new` needs a matching `delete` ; every `new[]` a matching `delete[]` . 

**DEFENSE** Be ready to justify stack vs heap choices out loud — the evaluation sheet explicitly asks evaluators to check that "the student must justify their choices" for ex00's `randomChump` . 

**INSTANT 0 / −42** Flags that end the evaluation immediately: Empty work · Incomplete work · Invalid compilation · Cheat · Crash · Forbidden function. Double-check your repo is clean before defense.
</div>

# CPP MODULE00 - NOTES
Namespaces · Classes · Member Functions · iostream · Init Lists · static · const 

## **Namespaces** 

A **namespace** groups related code under a name to avoid naming conflicts — think of it like a folder. 

## **Basic usage** 

```
namespace MyNamespace {
    int x = 42;
}
int main() {
    std::cout << MyNamespace::x;   // scope resolution operator ::
    return 0;
}
```

## **The std namespace** 

Everything in the standard library lives in `std` . Write `std::cout` , `std::cin` , `std::endl` — or bring them in with `using namespace std;` . 

**Without using namespace std With using namespace std** `std::cout << "Hello\n"; cout << "Hello\n";` 

I **In headers: NEVER use** `using namespace` — grade − **42** per the subject rules. 

## **Why use namespaces?** 

- Avoid name conflicts in large projects 

- Organise code into logical groups 

- Separate your code from library code 

II Prefer explicit `MyNamespace::x` over `using namespace` in large codebases. 

## **Classes & Objects** 

A **class** is a user-defined blueprint. An **object** is an instance of that blueprint. Attributes = member variables. Methods = member functions. 

## **Access specifiers** 

|**Specifier**|**Meaning**|
|---|---|
|`public`|Accessible from anywhere|
|`private`|Accessible only within the class itself (default for class members)|



`protected` Accessible within the class and its derived classes (inheritance) 

I Rule of thumb: data members should be **private** ; expose them via public getters/setters. The eval sheet checks this explicitly. 

## **Creating a class & objects** 

```
class Car {
public:
    std::string brand;   // attribute
    std::string model;
    int         year;
};
int main() {
    Car myCar;           // object instantiation
    myCar.brand = "BMW";
    myCar.year  = 1999;
    std::cout << myCar.brand << std::endl;
    return 0;
}
```

## **Member Functions** 

## **Defined inside the class (inline)** 

```
class Box {
public:
    double length, breadth, height;
    double getVolume() {
        return length * breadth * height;
    }
};
```

## **Defined outside the class (scope resolution ::)** 

```
class Box {
public:
    double length, breadth, height;
    double getVolume();   // declaration only
};
// Definition outside — must prefix with ClassName::
double Box::getVolume() {
    return length * breadth * height;
}
```

## **const member functions** 

Append `const` after the parameter list to promise the function won't modify any member variables. Required for functions called on const objects. 

```
int getX() const { return x; }   // safe to call on a const object
```

## **Calling member functions** 

```
Box myBox;
myBox.getVolume();   // dot operator on an object
```

## **iostream Library (stdio streams)** 

|**Object**|**Description**|
|---|---|
|`std::cout`|Output stream→console|
|`std::cin`|Input stream←keyboard|
|`std::cerr`|Output stream for error messages (unbuffered)|
|`std::clog`|Output stream for log messages (buffered)|
|`std::endl`|Inserts newline + flushes buffer|
|`wcout/wcin`|Wide-char versions of cout/cin (wchar_t)|



I Use `std::cin` (not `scanf` ) and `std::cout` (not `printf` ). This is C++, not C. 

## **Initializer Lists** 

## Syntax: **ConstructorName(params) : member1(val1), member2(val2) { }** 

```
class Point {
private:
    int x;
    int y;
public:
    Point(int i = 0, int j = 0) : x(i), y(j) {}   // init list
    int getX() const { return x; }
    int getY() const { return y; }
};
```

## **When initializer lists are REQUIRED** 

- **const members** — `const` data cannot be assigned after construction; must be initialised here 

- **Reference members** — `int &ref;` must bind at the moment of construction 

- **Member objects without a default constructor** — if a member class has no no-arg constructor, you must 

- pass args here 

- **Base class with parameterized constructor** — call parent constructor from the init list 

- **Same name for param & member** — avoids shadowing issues without needing {ic('this->')} 

## I **Initializer order gotcha** 

II Members are initialised in the order they are **declared in the class** , NOT the order they appear in the initializer list. Reordering your init list doesn't change execution order — it only creates confusion. Always match list order to declaration order. 

## **Parameter () vs Uniform {} initialisation** 

Prefer `{}` (uniform initialisation) over `()` in init lists — it triggers a compiler error on narrowing conversions (e.g. fitting 300 into a `char` ), making bugs visible at compile time. 

```
// () — silently truncates, may give wrong result
MyClass(int a) : x(a) {}
```

```
// {} — error/warning if narrowing conversion detected (safer)
MyClass(int a) : x{a} {}
```

## **static & const** 

## **static members** 

A `static` member belongs to the **class itself** , not to any individual object. All instances share the same value. Must be **defined** outside the class (in the .cpp file). 

```
class Counter {
public:
    static int count;          // declaration
    Counter()  { count++; }
    ~Counter() { count--; }
};
int Counter::count = 0;        // definition (in .cpp)
// Access without an object:
std::cout << Counter::count;
```

## **static member functions** 

Can be called without an object ( `Counter::getCount()` ). Cannot access non-static members (no `this` pointer). 

```
class Counter {
    static int count;
public:
    static int getCount() { return count; }
};
```

## **const members (quick ref)** 

|**Usage**|**What it means**|
|---|---|
|`const int x`|Value cannot change after init — MUST use initializer list|
|`int getX() const`|Function won't modify any member — callable on const objects|
|`const MyClass obj`|Object whose members can't be changed after construction|



```
void f(const MyClass &obj;)
```

Pass by const reference — read-only, no copy overhead 

## **Include Guards** 

I Every header file MUST have include guards. Missing guards = **grade 0** . 

```
#ifndef CLASSNAME_HPP
# define CLASSNAME_HPP
class ClassName {
    // ...
};
#endif
```

Convention: use the filename in caps with dots replaced by underscores, e.g. `PHONEBOOK_HPP` . 

## **Exercise Quick Reference** 

## **ex00 — Megaphone** 

Uppercase all argv strings. No args → print feedback noise. 

```
#include <iostream>
#include <cctype>   // std::toupper
int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; i++)
        for (int j = 0; argv[i][j]; j++)
            std::cout << (char)std::toupper(argv[i][j]);
    std::cout << std::endl;
    return 0;
}
```

## **ex01 — My Awesome PhoneBook** 

- Two classes: **PhoneBook** (array of 8 Contact) and **Contact** 

- No dynamic allocation ( `new` forbidden here so only option is a circular buffer) 

- Commands: ADD / SEARCH / EXIT (anything else ignored) 

- ADD: prompts all 5 fields; empty field not saved 

- SEARCH: 4 columns × 10 chars wide, right-aligned, pipe-separated; text > 10 chars truncated with '.' 

- Use `#include` with `std::setw(10)` and `std::right` 

- Read with `std::cin` , not scanf 

- 9th contact replaces the oldest (circular index)

### How the 9th contact replaces the oldest?
with a a circular buffer, it's just a fixed-size array where you reuse slots by wrapping around, instead of shifting things or allocating new memory.
```
Contact _contacts[8];  // fixed array, lives on the stack
int     _oldest;       // tracks which slot to overwrite next
```
### How it works?
So every time a contact is added:

```
cpp_contacts[_oldest] = newContact;
_oldest = (_oldest + 1) % 8;
```

The % 8 wraps it back to 0 Whenever the _oldest hits 8. So the array behaves like a "cycle":
```
slots:   [ 0 ][ 1 ][ 2 ][ 3 ][ 4 ][ 5 ][ 6 ][ 7 ]
          ↑                                        ↑
       oldest                                    newest
          |_________________wrap____________________↑
```
After 8 contacts, the 9th overwrites slot 0 (the oldest), the 10th overwrites slot 1, just index arithmetic.

_count — how many contacts exist (caps at 8, used to validate SEARCH index and stop displaying garbage slots)
_oldest — where to write next (keeps moving even after _count maxes out)

Once you're full, _count stops incrementing but _oldest keeps spinning. That's why they need to be separate variables.


```
// SEARCH column formatting example
std::cout << std::setw(10) << std::right << field << "|"
```

I Truncation logic: if field.length() > 10, print field.substr(0, 9) + '.' 


# CPP MODULE01 - NOTES
*Memory allocation, pointers to members,
references and switch statements*

## **Stack vs Heap** 

**Stack** objects are automatic — they're destroyed when execution leaves their scope. **Heap** objects are created with `new` and live until you explicitly `delete` them. 

```
Zombie *z = new Zombie("Rick");   // heap: outlives this function
z->announce();
delete z;                         // you must free it yourself
Zombie z2("Carl");                // stack: destroyed automatically
z2.announce();                    // at the closing brace, dtor runs
```

## **newZombie() vs randomChump()** 

- `newZombie()` returns a `Zombie*` that must outlive the function call → **heap** . 

- `randomChump()` only needs the zombie inside the function → **stack** works fine, and cleans itself up. 

**MUST** Every `new` needs a matching `delete` . Every `new[]` needs a matching `delete[]` — mixing the two is undefined behaviour, not just a leak. 

## **References vs Pointers** 

||**Pointer**|**Reference**|
|---|---|---|
|Can be NULL|Yes|No — must always refer to a valid object|
|Can be reassigned|Yes|No — bound for life at creation|
|Must be initialised at declaration|No|Yes|
|Access syntax|`*ptr`|used directly, no operator|



```
std::string str = "HI THIS IS BRAIN";
std::string *stringPTR = &str;
std::string &stringREF = str;
```

```
std::cout << &str << std::endl;        // same address
std::cout << stringPTR << std::endl;   // same address
std::cout << &stringREF << std::endl;  // same address, too
```

**NOTE** A reference isn't a new object — it's just another name for the same memory. That's why `&stringREF` prints the exact same address as `&str` . 

## **Reference Members & Initializer Lists** 

A reference member can't be assigned in the constructor body — it must be bound in the **initializer list** , at construction time, since references can't be re-pointed afterward. 

```
class HumanA {
    Weapon &weapon;
public:
    HumanA(std::string name, Weapon &weapon)
        : name(name), weapon(weapon) {}
//                       ^ NOT &weapon — weapon is already a reference
};
```

**COMMON BUG** `weapon(&weapon)` in the init list is a classic mix-up — that syntax is for _pointer_ members, not reference members. 

|**Class**|**Member type**|**Why**|
|---|---|---|
|HumanA|`Weapon&`|Always armed — weapon set once, at construction|
|HumanB|`Weapon*`|May start unarmed;`setWeapon()`assigns it later, can be NULL|



## **Pointers to Member Functions** 

In C, a function-pointer table looks like `void (*funcs[4])(void) = {f1, f2, f3, f4};` then `funcs[i]();` . In C++, a _member_ function pointer needs the class baked into its type, because calling it requires an object ( `this` ) to act on. 

```
void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info,
                                     &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
        if (level == levels[i])
            return ((this->*funcs[i])());   // ->* calls a member-fn pointer
    std::cout << "Invalid level!" << std::endl;
}
```

**WON'T COMPILE** `switch` cannot operate on `std::string` — only on integral or enum types. A string-keyed switch isn't a style mistake, it's a compile error. Save `switch` for ex06. 

## **Switch Statements** (ex06) 

`switch` only accepts integral/enum values, needs a `default` case, and falls through to the next case unless you `break;` . 

```
switch (level)
{
    case DEBUG:
        std::cout << debugMsg << std::endl;
// no break: DEBUG also prints INFO, WARNING, ERROR below
    case INFO:
        std::cout << infoMsg << std::endl;
    case WARNING:
        std::cout << warnMsg << std::endl;
        break;
    case ERROR:
        std::cout << errorMsg << std::endl;
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
```

**TIP** ex06 wants "this level and everything louder" (DEBUG < INFO < WARNING < ERROR). Intentionally _omitting_ `break` between the quieter levels is the natural way to get that cascade — just make sure ERROR still breaks (or is last). 

## **File I/O — ifstream / ofstream** (ex04) 

|**C**|**C++**|
|---|---|
|`FILE *fp = fopen(path, "r")`|`std::ifstream infile(path)`|
|`FILE *fp = fopen(path, "w")`|`std::ofstream outfile(path)`|
|`if (!fp)`|`if (!infile.is_open())`|
|`fclose(fp)`|automatic when the stream goes out of scope (RAII)|



```
std::ifstream infile(filename.c_str());   // .c_str(): C++98 ctor wants const char*
if (!infile.is_open()) { /* error */ }
```

```
std::stringstream buffer;
buffer << infile.rdbuf();                // slurp whole file into one string
std::string content = buffer.str();
```

**FORBIDDEN** `std::string::replace` is banned in ex04 — build the replacement using `substr()` + `find()` instead. 

**TIP** `.c_str()` is required when passing a `std::string` to the `ifstream` / `ofstream` constructor in C++98 — the `std::string` overload doesn't exist until C++11.

## **Exercise Quick Reference** 

## **ex00 — BraiiiiiiinnnzzzZ** 

- Zombie has a private `name` ; `announce()` prints `<name>: BraiiiiiiinnnzzzZ...` — don't forget the colon. 

- Destructor **must** print a debug message including the zombie's name. 

- `newZombie(name)` → heap, returns `Zombie*` . 

- `randomChump(name)` → stack, destroyed automatically. 

## **ex01 — Moar brainz!** 

- Zombie needs a **default constructor** — you allocate first with `new[]` , then set names after. 

- `zombieHorde(N, name)` : one single `new Zombie[N]` allocation, not a loop of individual `new` . 

- Delete all of them together at the end with one `delete[]` . 

## **ex02 — HI THIS IS BRAIN** 

- One string, one pointer to it, one reference to it. 

- Print all three addresses first, then all three values. 

- All three addresses come out identical — that's the entire point of the exercise. 

## **ex03 — Unnecessary violence** 

- Weapon: private `type` , `getType()` returns `const std::string&` , `setType()` sets it. 

- HumanA: `Weapon&` member, bound in the initializer list, always armed. 

- HumanB: `Weapon*` member, `setWeapon()` assigns it later, can stay unset. 

## **ex04 — Sed is for losers** 

- `ifstream` to read, `ofstream` to write to `<filename>.replace` . 

- `std::string::replace` is forbidden — use `substr` / `find` . 

- Handle: missing file, missing args, empty `s1` , `s1` not found in the file. 

## **ex05 — Harl 2.0** 

- Harl: 4 private functions ( `debug` / `info` / `warning` / `error` ) + 1 public `complain(std::string)` . 

- `complain()` must dispatch through a pointer-to-member-function array — no `if` / `else if` chain allowed. 

- Any implementation is valid as long as it avoids the if/else chain — exact message wording doesn't matter. 

**ex06 — Harl filter** (optional — you can pass the module without it) 

- Executable must be named `harlFilter` , exactly. 

- Takes one level argument, prints that level and everything louder (DEBUG < INFO < WARNING < ERROR). 

- Must use a `switch` statement with a `default` case — no if/else chain here either. 



# CPP MODULE02 - NOTES
*Ad-hoc polymorphism · Operator overloading · Orthodox Canonical Form*

---

## — THE THEORY

### 1.1 — I come from C. What changed?

In C, if I want to add two things, I write one function per type: `add_int()`, `add_float()`, `add_vector()`. The function name is unique. The compiler matches the name exactly and goes there. Simple. Rigid.

In C++, I can write three functions all named `add()`, each taking different parameter types. The compiler looks at what I passed in, figures out which version I meant, and calls it. This is called **function overloading** — and it is the foundation of everything in Module 02.

**C — one name, one function**
```c
int add_int(int a, int b)
float add_float(float a, float b)
// I choose the name myself. No ambiguity. No magic.
```

**C++ — one name, many functions**
```cpp
int add(int a, int b)
float add(float a, float b)
// Compiler chooses for me, based on the types I pass in.
```

---

### 1.2 — Ad-hoc polymorphism

*Ad-hoc* means "for this specific case" in Latin. So ad-hoc polymorphism = "I write the same function name for specific cases and the compiler picks the right one."

This is different from runtime polymorphism (virtual functions, inheritance). Ad-hoc polymorphism happens entirely **at compile time**. The compiler reads my code, sees the types, and decides. By the time the program runs, the choice is already baked in.

**What does the compiler actually do?**
When it sees `a + b`, it looks at the types of `a` and `b`. If they are `int`s, it uses the int version. If they are my `Fixed` objects, it looks for a function called `operator+` that takes `Fixed` parameters. If it finds one, great. If not, compile error. This lookup process is called **overload resolution**.

---

### 1.3 — Operator overloading

In C, operators like `+`, `-`, `==`, `<<` only work on built-in types. I can't write `myStruct + myStruct` — I have to write a function and call it explicitly.

In C++, operators are just functions with special names. `a + b` is literally the same as calling `operator+(a, b)`. So I can write my own version of `operator+` for my class, and suddenly `+` works on my objects.

```cpp
// These two lines mean EXACTLY the same thing to the compiler:
Fixed result = a + b;
Fixed result = a.operator+(b);

// And the insertion operator works the same way:
std::cout << a;
operator<<(std::cout, a); // same thing
```

**Why was this invented?** Readability. Writing `a + b` is much clearer than `fixed_add(a, b)`, especially when expressions get complex like `Fixed::max(a + b, c * d)`.

---

### 1.4 — The Orthodox Canonical Form

In C, a struct is just memory. Copy it with `memcpy`, pass it around, nobody cares.

In C++, a class can **own resources** — heap memory, file handles, connections. If I copy the class carelessly, two objects point to the same memory, and when one dies it takes the other's data with it.

The Orthodox Canonical Form is the contract I make with the compiler: *"I promise I handle copying, assignment, and destruction correctly."* From Module 02 onwards, every class must have these 4 things:

| Function | When it runs | What it does |
|---|---|---|
| `Fixed()` | `Fixed a;` | Creates a brand new object from scratch |
| `Fixed(const Fixed &other)` | `Fixed b(a);` / `Fixed b = a;` | Creates a new object as a copy of an existing one |
| `Fixed &operator=(const Fixed &other)` | `a = b;` (a already exists) | Overwrites an existing object with values from another |
| `~Fixed()` | `}` end of scope / `delete obj;` | Cleans up when the object dies |

**Copy constructor vs copy assignment — what is the difference?**
- **Copy constructor:** the object does not exist yet. I am *building* it from another.
- **Copy assignment:** the object already exists. I am *replacing* its contents.

The compiler knows which one to call based on context. I just need both.

---

### 1.5 — Fixed-point numbers

Integers are fast but cannot represent `1.5`. Floats can represent `1.5` but are imprecise and slow on hardware without an FPU (graphics chips, embedded systems).

**Fixed-point** is the middle ground: I store an integer, but I agree that the last 8 bits represent the fractional part. So the number is always `raw_value / 2^8 = raw_value / 256`.

```cpp
// To store 1.5:
int raw = 384;          // 1.5 × 256 = 384
float val = raw / 256.0f; // = 1.5 (reading back)

// Storing 42.42f:
int raw = roundf(42.42f * 256); // = roundf(10859.52) = 10860
float back = 10860 / 256.0f;   // = 42.4219 (tiny precision loss, expected)
```

---

## — THE CODE

### 2.1 — Fixed.hpp

```cpp
#pragma once
#include <iostream>
#include <cmath>

class Fixed {
private:
    int _fixedPointValue;
    static const int _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int value);
    Fixed(const float value);
    Fixed(const Fixed &other);
    ~Fixed();

    Fixed &operator=(const Fixed &other);

    int   getRawBits(void) const;
    void  setRawBits(int const raw);
    float toFloat(void) const;
    int   toInt(void) const;

    bool operator>(const Fixed &other) const;
    // ... more operators ...

    static Fixed       &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &f);
```

| Line | What it means |
|---|---|
| `#pragma once` | Include guard — stops the header from being pasted twice. Without this: duplicate declaration errors. |
| `static const int _fractionalBits = 8` | `static`: belongs to the class itself, not any individual object. `const`: never changes. |
| `Fixed(const Fixed &other)` | Copy constructor. Takes a `const` reference — not a copy — to avoid infinite recursion. |
| `Fixed &operator=(const Fixed &other)` | Copy assignment. Returns `*this` by reference so I can chain: `a = b = c;` |
| `int getRawBits(void) const` | Trailing `const`: this function promises not to modify the object. Callable on `const Fixed` objects. |
| `static Fixed &min(...)` | `static` member function: called as `Fixed::min(a, b)`, no object needed. Returns a reference — not a copy — so I get the actual `a` or `b` back. |
| `operator<<` outside class | Not a member of `Fixed` because the left side is `std::ostream`, not `Fixed`. Free function taking both. |

---

### 2.2 — Constructors

```cpp
Fixed::Fixed() : _fixedPointValue(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) : _fixedPointValue(value << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
    : _fixedPointValue(roundf(value * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // calls operator= which does the actual copy
}
```

- `: _fixedPointValue(0)` — **initializer list**: sets the member variable *before* the constructor body runs. More efficient than setting it inside the body, and required for `const` members.
- `value << _fractionalBits` — left bit shift by 8 = multiply by 256. `int 10` → raw value `2560`. Divide back by 256 → `10`.
- `roundf(value * 256)` — multiply the float by 256 to scale it up, then round to nearest int. `42.42 × 256 = 10859.52` → rounds to `10860`.

---

### 2.3 — Copy assignment operator

```cpp
Fixed &Fixed::operator=(const Fixed &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)             // self-assignment guard
        _fixedPointValue = other.getRawBits();
    return *this;                   // return the object itself
}
```

- `this` is a pointer to the current object. `*this` is the object itself.
- `if (this != &other)` — guard against `a = a`. Without this, I'd overwrite my own data before reading it.
- `return *this` — returning a reference to myself allows chaining: `a = b = c` works because `b = c` returns `b`, then `a = b` runs.

---

### 2.4 — Arithmetic operators

```cpp
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
// same pattern for - and /
```

I convert both operands to float, do the math in float, then convert the result back into a `Fixed`. This creates a temporary `Fixed` object which gets returned.

**Why float and not raw int math?** Because multiplying raw fixed-point values directly gives wrong results — the scale factor would be squared. Float math sidesteps this cleanly.

---

### 2.5 — Increment/decrement operators

```cpp
Fixed &Fixed::operator++(void) {   // PRE-increment: ++a
    ++_fixedPointValue;
    return *this;                  // return AFTER incrementing
}

Fixed Fixed::operator++(int) {     // POST-increment: a++
    Fixed temp(*this);             // save current state
    ++_fixedPointValue;            // increment
    return temp;                   // return BEFORE state
}
```

- The `(int)` parameter is a **dummy** — it has no value. The compiler uses it only to distinguish post-increment from pre-increment.
- `++a` returns a reference: increment then return myself. No copy needed.
- `a++` returns a copy: save state first, increment, return the old copy. This is why post-increment is slightly slower.
- Adding `1` to raw value = the smallest epsilon, because raw `1` = `1/256` in actual value.

---

### 2.6 — Comparison operators and min/max

```cpp
bool Fixed::operator>(const Fixed &other) const {
    return _fixedPointValue > other._fixedPointValue;
}
// same pattern for <, >=, <=, ==, !=

static Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a < b) ? a : b;
}

static const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a < b) ? a : b;
}
```

- **Why compare raw values directly?** The scale factor (256) is the same for both objects. Larger raw value = larger number. No float conversion needed.
- **Why two versions of min/max?** One takes non-const references (mutable objects), one takes const references (const objects). The compiler picks the right one automatically.

---

### 2.7 — toFloat, toInt, operator<<

```cpp
float Fixed::toFloat(void) const {
    return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}
```

- `static_cast<float>`: must cast to float *before* dividing, otherwise integer division truncates everything (`10860 / 256 = 42`, not `42.42`).
- `>> _fractionalBits`: right shift by 8 = divide by 256 and discard the fractional part.
- `operator<<` returns the stream: enables chaining `std::cout << a << b << std::endl`.


# CPP MODULE03 - NOTES
*Inheritance*
---

## 1. What even IS inheritance?

**The honest one-sentence explanation:**
Inheritance lets me write a new class that automatically gets everything an existing class already has — all its variables, all its functions — and then I can add extra stuff on top, or change specific things.

In C I had to copy-paste structs and manually pass pointers everywhere. In C++ I just say "ScavTrap is a ClapTrap" and it works.

### A comparison that makes sense to me

| C way | C++ inheritance way |
|---|---|
| I make a t_robot struct with name, hp, energy. Then I make a t_scavrobot struct and copy ALL the same fields into it again plus new ones. | I make a ClapTrap class with name, hp, energy. Then ScavTrap just says `: public ClapTrap` and it HAS all of those automatically. |
| If I fix a bug in t_robot I have to fix it in t_scavrobot too. | If I fix a bug in ClapTrap, ScavTrap gets the fix for free. |

---

## 2. What actually happens in the compiler?

When the compiler sees `ScavTrap : public ClapTrap`, it thinks:

- ScavTrap objects need memory space for ALL of ClapTrap's variables PLUS ScavTrap's own.
- When I construct a ScavTrap, it first runs ClapTrap's constructor, then ScavTrap's.
- When it destructs, reverse order: ScavTrap destructor first, then ClapTrap.
- If ScavTrap has its own attack(), that overrides ClapTrap's version for ScavTrap objects.

### Memory layout of a ScavTrap object

```
┌─────────────────────────────────┐
│  ScavTrap object in memory      │
│  ┌───────────────────────────┐  │
│  │  ClapTrap part            │  │
│  │   _name                   │  │
│  │   _hit_points             │  │
│  │   _energy_points          │  │
│  │   _attack_damage          │  │
│  └───────────────────────────┘  │
│  (ScavTrap has no extra fields) │
└─────────────────────────────────┘
```

ScavTrap has no new attributes — it just reuses ClapTrap's and sets them to different values.

---

## 3. Constructor & Destructor chaining — the ORDER matters!

**When I write:** `ScavTrap lancer("Lancer");`

**What runs, in this exact order:**
1. `ClapTrap::ClapTrap("Lancer")` ← the PARENT builds first
2. `ScavTrap::ScavTrap("Lancer")` ← then the CHILD finishes

**When lancer goes out of scope:**
1. `ScavTrap::~ScavTrap()` ← CHILD destructs first
2. `ClapTrap::~ClapTrap()` ← then PARENT cleans up

> Why reversed? Because the child was built ON TOP of the parent. When demolishing a building you remove the top floors first.

---

## 4. private vs protected — why I had to change it

| private | protected | public |
|---|---|---|
| Only THIS class can see it. ScavTrap CANNOT access it even though it inherits. | This class AND any child class can see it. ScavTrap CAN access it. ✓ | Everyone can see it from outside. Used for functions I want to call in main(). |
| `_name` in ClapTrap originally | `_name` after I changed it so ScavTrap can use `_name`, `_hit_points` etc. | `attack()`, `takeDamage()`, `beRepaired()` |

---

## 5. ClapTrap.hpp — line by line

**`#pragma once`**
Include guard — if this file gets included twice by accident, the compiler ignores the second time. Replaces the old `#ifndef` guard pattern.

**`#include <iostream>` / `#include <string>`**
I need `std::cout` (from iostream) and `std::string` (from string). These are the C++ versions of stdio.h and string.h.

**`class ClapTrap {`**
Declares a new class called ClapTrap. A class is like a struct in C but with functions built in and access control (private/protected/public).

**`protected:`**
Everything below this line is accessible by ClapTrap AND any class that inherits from it (like ScavTrap, FragTrap). NOT accessible from main().

**`std::string _name; int _hit_points; int _energy_points; int _attack_damage;`**
The robot's data. I use `_underscore` prefix to visually separate member variables from local variables. `std::string` is C++'s built-in text type — no char arrays, no malloc.

**`bool haveEnergy(); bool isAlive();`**
Helper functions also protected. Only ClapTrap and its children can call these. They check internal state — no need to expose them publicly.

**`public:`**
Everything below is accessible from anywhere, including main(). These are the functions the outside world is allowed to call.

**`void attack(const std::string &target);`**
The `&` means "reference" — like a pointer but cleaner syntax. `const` means I promise not to modify target. This avoids copying the entire string.

**`ClapTrap(std::string name);`**
Parametrized constructor — called when I write `ClapTrap c("name");`. This is the one that actually sets up the robot.

**`ClapTrap(const ClapTrap &copy);`**
Copy constructor — called when I write `ClapTrap b = a;` or pass a ClapTrap by value to a function. Orthodox Canonical Form requires this.

**`~ClapTrap();`**
Destructor — called automatically when the object goes out of scope or gets deleted. The `~` means "un-constructor". I print a message here so peer evaluators can see it fires.

**`ClapTrap &operator=(const ClapTrap &assign);`**
Assignment operator — called when I write `a = b;` AFTER both are already constructed. Returns `*this` so I can chain assignments. Orthodox Canonical Form requires this.

**`};`**
End of class. The semicolon is REQUIRED after a class definition — easy to forget, compiler cries.

---

## 6. ClapTrap.cpp — the juicy implementation

**`ClapTrap::ClapTrap(std::string name) : _name(name)`**
The `::` is the scope operator — it means "this attack() belongs to ClapTrap, not some random global function". The `: _name(name)` part is an initializer list — it sets `_name` BEFORE the constructor body runs. Faster and cleaner than `_name = name` inside `{}`.

**`_hit_points = 10; _energy_points = 10; _attack_damage = 0;`**
Setting the default stats inside the constructor body. I could also put these in the initializer list but this reads more clearly for the exercises.

**`std::cout << "Default Constructor called" << std::endl;`**
The `<<` operator is "stream insertion" — I'm inserting text into cout (the terminal output stream). `std::endl` flushes the stream and adds a newline. I could use `'\n'` instead (faster) but endl is fine here.

**`ClapTrap::ClapTrap(const ClapTrap &copy) { *this = copy; }`**
`*this` dereferences the `this` pointer — this is a pointer to the current object. So `*this = copy` calls my assignment operator on myself, copying all fields. This avoids rewriting copy logic twice.

**`ClapTrap &ClapTrap::operator=(const ClapTrap &assign) { this->_name = assign._name; ... return *this; }`**
The assignment operator copies field by field. I access the other object's private fields because I'm inside the same class. `return *this` returns a reference to myself — this allows chaining like `a = b = c`.

**`if (!isAlive()) ... else if (!haveEnergy()) ...`**
Guard clauses. I check if the robot is dead or out of energy before doing anything. The `!` means NOT. This pattern reads as "if not alive, bail out".

**`_energy_points -= 1;`**
Both attack() and beRepaired() cost 1 energy. I subtract AFTER the action succeeds.

**`if ((unsigned int)_hit_points <= amount)`**
The cast to unsigned int prevents a signed/unsigned comparison warning. `_hit_points` is int (can be negative) but `amount` is unsigned int (can't be negative). The compiler warns when comparing these directly.

---

## 7. ScavTrap — inheriting and overriding

**`class ScavTrap : public ClapTrap {`**
The colon means "inherits from". `public` means ClapTrap's public stuff stays public in ScavTrap — it doesn't get hidden. If I wrote `private` instead, all inherited stuff would become private (almost never what I want).

**`ScavTrap::ScavTrap(std::string name) : ClapTrap(name)`**
The `: ClapTrap(name)` in the initializer list EXPLICITLY calls ClapTrap's constructor with the name. If I don't do this, C++ tries to call ClapTrap's DEFAULT (no-argument) constructor — which doesn't exist here, so it would fail.

**`_hit_points = 100; _energy_points = 50; _attack_damage = 20;`**
I can set these because they're "protected" in ClapTrap. If they were "private" this would be a compile error. This is why I had to change private to protected.

**`ScavTrap(const ScavTrap &copy) : ClapTrap(copy)`**
Copy constructor. The `: ClapTrap(copy)` calls ClapTrap's copy constructor to handle copying the parent's fields. I don't have to copy `_name` etc manually — the parent does it.

**`ClapTrap::operator=(assign);`**
Inside ScavTrap's `operator=`, I call the parent's `operator=` to copy the parent's fields. Then I'd copy ScavTrap-specific fields (but ScavTrap has none, so this is all I need).

**`void ScavTrap::attack(const std::string &target)`**
This OVERRIDES ClapTrap's attack(). When I call attack() on a ScavTrap object, THIS version runs instead of ClapTrap's. The function signatures must match exactly.

**`void ScavTrap::guardGate()`**
A brand new function that only ScavTrap has. ClapTrap doesn't know about this. I can only call it on ScavTrap objects (or classes that inherit from ScavTrap).
