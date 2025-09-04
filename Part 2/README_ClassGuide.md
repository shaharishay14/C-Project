# C++ OOP Class Design Guide

## Project Requirements Checklist

### ✅ Requirements Met in Your Classes:

1. **No Default Constructor**

   - All constructors must require parameters
   - ❌ Bad: `ClassName() = default;`
   - ✅ Good: `ClassName(const std::string& param);`

2. **Copy Constructor Implementation**

   - Must explicitly implement copy constructor
   - Must save ALL properties from the source object
   - ✅ Format: `ClassName(const ClassName& other);`

3. **Destructor Implementation**

   - Must be explicitly implemented (even if empty)
   - ✅ Format: `~ClassName();`

4. **Data Integrity Validation**

   - Validate all input data
   - Use private validation methods to avoid code duplication
   - Throw exceptions for invalid data

5. **No Code Duplication**

   - Create private validation methods
   - Reuse validation logic across constructors and setters

6. **Separate .h and .cpp Files**
   - Declarations in `.h` file
   - Implementations in `.cpp` file

## Class Structure Template

### Header File (.h)

```cpp
#pragma once
#include <string>
#include <stdexcept>

class YourClass {
private:
    // Private data members
    std::string member1;
    int member2;

    // Private validation method (prevents code duplication)
    void validateData() const;

public:
    // 1. NO default constructor - parameters required
    YourClass(const std::string& param1, int param2);

    // 2. Copy constructor - saves ALL properties
    YourClass(const YourClass& other);

    // 3. Assignment operator (recommended)
    YourClass& operator=(const YourClass& other);

    // 4. Destructor - must be implemented
    ~YourClass();

    // Getters and setters
    const std::string& getMember1() const;
    int getMember2() const;
    void setMember1(const std::string& value);
    void setMember2(int value);
};
```

### Implementation File (.cpp)

```cpp
#include "YourClass.h"

// Private validation - no code duplication
void YourClass::validateData() const {
    if (member1.empty()) {
        throw std::invalid_argument("Member1 cannot be empty");
    }
    if (member2 < 0) {
        throw std::invalid_argument("Member2 must be positive");
    }
}

// Constructor with validation
YourClass::YourClass(const std::string& param1, int param2)
    : member1(param1), member2(param2) {
    validateData();
}

// Copy constructor - saves ALL properties
YourClass::YourClass(const YourClass& other)
    : member1(other.member1), member2(other.member2) {
    // All properties copied as required
}

// Assignment operator
YourClass& YourClass::operator=(const YourClass& other) {
    if (this != &other) {
        member1 = other.member1;
        member2 = other.member2;
    }
    return *this;
}

// Destructor implementation
YourClass::~YourClass() {
    // Clean up if needed
}
```

## Key Points to Remember

1. **Always validate in constructor** - Use `validateData()` method
2. **Copy constructor copies ALL properties** - This is explicitly required
3. **No default values in constructor** - All parameters must be provided
4. **Use member initialization list** - More efficient than assignment
5. **Throw exceptions for invalid data** - Use `std::invalid_argument`
6. **Private validation method** - Reuse across constructor and setters

## Your Fixed CAddress Class

Your `CAddress` class now follows all requirements:

- ✅ No default constructor
- ✅ Copy constructor implemented
- ✅ Destructor implemented
- ✅ Data validation with no duplication
- ✅ All properties saved in copy constructor
- ✅ Separate .h and .cpp files

Use this pattern for all your future classes!
