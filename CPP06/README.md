# Intro
> C++ casts

# Table of Contents
- Excersises
  - [Exercise 00](#exercise-00---conversion-of-scalar-types)
  - [Exercise 01](#exercise-01---serialization)
  - [Exercise 02](#exercise-02---identify-real-type)
- [Evaluation](#evaluation)
- [Creator](#creator)

## Exercise 00 - Conversion of scalar types
[static_cast<target-type ﻿>(expression ﻿)](https://en.cppreference.com/w/cpp/language/static_cast)<br>
This exercise requires you to convert a value passed on the stdin to char, int, float and double.
Static cast is used to convert the values, however here the static cast is overloaded to add specific algorithms and protections to the conversions.

## Exercise 01 - Serialization
[reinterpret_cast< target-type >( expression )](https://en.cppreference.com/w/cpp/language/reinterpret_cast)<br>
This exercise requires you to convert an address pointer into an [uintptr_t](https://en.cppreference.com/w/cpp/types/integer) (C++11) and vice versa. The information stored at the pointers location should remain accessible.

## Exercise 02 - Identify real type
[dynamic_cast< target-type >( expression )](https://en.cppreference.com/w/cpp/language/dynamic_cast)<br>
This exercise requires you to test for a valid conversion using casting. This is done with dynamic_cast which, unlike static_cast and reinterpret_cast can fail during runtime. This makes it safer, yet slower. Invalid conversions can either return an error or throw one.

# Evaluation
**Score:** %
> ""
> 		- 

**Score:** %
> ""
> 		- 
> 
# Creator
Othello<br>
[<img alt="LinkedIn" height="32px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png" target="_blank" />](https://github.com/OthelloPlusPlus)
[<img alt="LinkedIn" height="32px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/600px-LinkedIn_logo_initials.png" target="_blank" />](https://nl.linkedin.com/in/orlando-hengelmolen)
