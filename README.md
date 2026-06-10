## **42 — CPP Module 00-04** 

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

## CPP MODULE00 - NOTES
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

## **General Rules & Eval Traps** 

## **Compilation** 

```
c++ -Wall -Wextra -Werror -std=c++98 *.cpp -o program
```

## **Forbidden** → **grade 0 or** − **42** 

|**Forbidden**|**Penalty**|
|---|---|
|`printf / scanf / malloc /`<br>`free / alloc`|Grade 0|
|`using namespace`or`friend`<br>(in headers or at all)|Grade−42|
|STL containers/algorithms before<br>Module 08|Grade−42|
|Function implementation in a<br>header (non-template)|Grade 0|
|Missing include guards|Grade 0|
|C++11 / Boost features|Grade 0|



## **Memory** 

II Memory leaks are checked with `valgrind` or `leaks` . Every `new` must have a matching `delete` . 

## **File naming** 

- Class names: **UpperCamelCase** (e.g. PhoneBook, BrickWall) 

- Files named after the class: BrickWall.hpp / BrickWall.cpp 

- Exercise directories: ex00/, ex01/, ex02/ 

- Each header must be independently includable (self-contained) 

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

- No dynamic allocation ( `new` forbidden here) 

- Commands: ADD / SEARCH / EXIT (anything else ignored) 

- ADD: prompts all 5 fields; empty field not saved 

- SEARCH: 4 columns × 10 chars wide, right-aligned, pipe-separated; text > 10 chars truncated with '.' 

- Use `#include` with `std::setw(10)` and `std::right` 

- Read with `std::cin` , not scanf 

- 9th contact replaces the oldest (circular index) 

```
// SEARCH column formatting example
std::cout << std::setw(10) << std::right << field << "|"
```

I Truncation logic: if field.length() > 10, print field.substr(0, 9) + '.' 

## **ex02 — The Job Of Your Dreams (optional)** 

Recreate Account.cpp from Account.hpp + tests.cpp + the log file. Output must match the log exactly — timestamps excepted (they'll differ). Static members track totals across all Account instances. 

I Destructor call order may differ between compilers/OS — reverse order is acceptable. 
