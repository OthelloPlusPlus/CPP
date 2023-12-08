# Intro
> C++ templates

# Table of Contents
- Excersises
  - [Exercise 00](#exercise-00---start-with-a-few-functions)
  - [Exercise 01](#exercise-01---iter)
  - [Exercise 02](#exercise-02---array)
- [Evaluation](#evaluation)
- [Creator](#creator)

## Exercise 00 - Start with a few functions
This exercise introduces you to the concept of templates. It requires you to create template functions for [swap](ex00/whatever.hpp#L16), [min](ex00/whatever.hpp#L37) and [max](ex00/whatever.hpp#L45) taking all argument types that support all the comparison operators. When compiling with C++11 or later it also allows for [more than 2 arguments](ex00/Makefile#L17) being sent to swap and min.

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
			<td><a href="ex00/Makefile#L35" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and run several tests to demonstrate.</td>
		</tr>
  </tbody>
</table>

## Exercise 01 - Iter
This exercise requires you to create a [template function](ex01/iter.hpp#L23) that takes an array and iterates over it, calling a passed function over each element of the array.

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
			<td><a href="ex01/Makefile#L35" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and run several tests to demonstrate.</td>
		</tr>
  </tbody>
</table>

## Exercise 02 - Array
This excercise requires you to create a [template class](ex02/Array.hpp#L18) which creates an array of the defined type T. It is required for this array to have a [size()](ex02/Array.hpp#L76) member function and each element should be able to be accessed through the [subscript operator []](ex02/Array.hpp#L101).

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
			<td><a href="ex02/Makefile#L35" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and run several tests to demonstrate.</td>
		</tr>
  </tbody>
</table>

# Evaluation
**Score:** 100%
> "Amazing job as always! this project is really class Awesome! I praise you for the fantastic set of tests, customized preprocessor instructions based on different  the compilation standards, advanced use of templates and of course the well curated and colorful output on terminal. Bravo!!!!  "
> 		- Emanuela Licameli

**Score:** 100%
> "Great job on making this project better then what the subject asks, makes thorough tests and really was able to explain every piece of his code when asked. Great eval. Good luck on the following Cpp modules!"
> 		- Kaay Altevogt
# Creator
Othello<br>
[<img alt="LinkedIn" height="32px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png" target="_blank" />](https://github.com/OthelloPlusPlus)
[<img alt="LinkedIn" height="32px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/600px-LinkedIn_logo_initials.png" target="_blank" />](https://nl.linkedin.com/in/orlando-hengelmolen)
