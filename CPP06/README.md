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

<table>
	<thead style="background-color: #C0C0C0;">
		<tr><th colspan="3">Terminal Commands</th></tr>
		<tr>
			<th>Command</th>
			<th>Arguments</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><a href="ex00/test.sh" target="_blank">./test.sh</a></td>
			<td></td>
			<td>Runs the Makefile and then runs the binary with a series of passed variables.</td>
		</tr>
		<tr>
			<td>./convert</td>
			<td>[values to be converted]</td>
			<td>Runs the binary with passed arguments</td>
		</tr>
  </tbody>
</table>

## Exercise 01 - Serialization
[reinterpret_cast< target-type >( expression )](https://en.cppreference.com/w/cpp/language/reinterpret_cast)<br>
This exercise requires you to convert an address pointer into an [uintptr_t](https://en.cppreference.com/w/cpp/types/integer) (C++11) and vice versa. The information stored at the pointers location should remain accessible.

<table>
	<thead style="background-color: #C0C0C0;">
		<tr><th colspan="3">Terminal Commands</th></tr>
		<tr>
			<th>Command</th>
			<th>Arguments</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><a href="ex01/Makefile#L22" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and run several tests to demonstrate.</td>
		</tr>
  </tbody>
</table>

## Exercise 02 - Identify real type
[dynamic_cast< target-type >( expression )](https://en.cppreference.com/w/cpp/language/dynamic_cast)<br>
This exercise requires you to test for a valid conversion using casting. This is done with dynamic_cast which, unlike static_cast and reinterpret_cast can fail during runtime. This makes it safer, yet slower. Invalid conversions can either return an error or throw one.
The output of the tests [changes](ex02/main.cpp#L112) depending on the C++ version.

<table>
	<thead style="background-color: #C0C0C0;">
		<tr><th colspan="3">Terminal Commands</th></tr>
		<tr>
			<th>Command</th>
			<th>Arguments</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><a href="ex02/Makefile#L22" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and run several tests to demonstrate.</td>
		</tr>
  </tbody>
</table>

# Evaluation
**Score:** 100%
> "Really really nice code. Went way above what the subject was asking for and the explanations were perfect. I am currently working on this project at the moment and with so much precise information I now feel comfortable doing it ! Thanks and good luck for your next projects"
> 		- Maximilien Bernede

**Score:** %
> ""
> 		- 
> 
# Creator
Othello<br>
[<img alt="LinkedIn" height="32px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png" target="_blank" />](https://github.com/OthelloPlusPlus)
[<img alt="LinkedIn" height="32px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/600px-LinkedIn_logo_initials.png" target="_blank" />](https://nl.linkedin.com/in/orlando-hengelmolen)
