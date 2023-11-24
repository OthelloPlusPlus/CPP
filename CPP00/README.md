# Intro
> Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuff

# Table of Contents
- Excersises
  - [Exercise 00](#exercise-00---megaphone)
  - [Exercise 01](#exercise-01---my-awesome-phonebook)
  - [Exercise 02](#exercise-02---the-job-of-your-dreams)
- [Evaluation](#evaluation)
- [Creator](#creator)

## Exercise 00 - MegaPhone
This exercise introduces the concept of Namespaces. Here you use them to convert a character string to upper case.
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
			<td><a href="ex00/Makefile#L18" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and run several tests to demonstrate.</td>
		</tr>
	</tbody>
</table>

## Exercise 01 - My Awesome PhoneBook
This exercise introduces the concept of Classes. Here you create two Classes. A [PhoneBook](ex01/PhoneBook.hpp) class which stores 8 members of the [Contact](ex01/Contact.hpp) class.

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
			<td><a href="ex01/Makefile#L24" target="_blank">make</a></td>
			<td>subject</td>
			<td>Compiles the program and runs the phonebook program.</td>
		</tr>
		<tr>
			<td>./phonebook</td>
			<td></td>
			<td>Runs the phonebook program.</td>
		</tr>
	</tbody>
</table>
<table>
	<thead style="background-color: #C0C0C0;">
		<tr><th colspan="2">PhoneBook Commands</th></tr>
		<tr>
			<th>Command</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td><a href="ex01/PhoneBook.cpp#L58" target="_blank">ADD</a></td>
			<td>Prompts user to add a contact.</td>
		</tr>
		<tr>
			<td><a href="ex01/PhoneBook.cpp#L83" target="_blank">FILL</a></td>
			<td>Fills all empty spots in the Phonebook with Contacts for testing purposes.</td>
		</tr>
		<tr>
			<td><a href="ex01/PhoneBook.cpp#L109" target="_blank">DELETE</a></td>
			<td>Displays a list of existing Contacts and prompts user which to delete.</td>
		</tr>
		<tr>
			<td><a href="ex01/PhoneBook.cpp#L130" target="_blank">SEARCH</a></td>
			<td>Displays a list of existing Contacts and prompts user which to display in detail.</td>
		</tr>
		<tr>
			<td><a href="ex01/PhoneBook.cpp#L142" target="_blank">HELP</a></td>
			<td>Displays options.</td>
		</tr>
		<tr>
			<td><a href="ex01/main.cpp#L41" target="_blank">EXIT</a></td>
			<td>Cleanly exits the program.</td>
		</tr>
	</tbody>
</table>

## Exercise 02 - The Job Of Your Dreams
This exercise introduces the concept static variables and member functions in Classes. It provides you a [main](ex02/tests.cpp#L16), a [header file](ex02/Account.hpp#L19) and an [expected output](ex02/19920104_091532.log) and requires you to create the appropriate [source file](ex02/Account.cpp).

The Class Account is used to track bank account information, but also stores the collective information for the all Account objects through [static variables](ex02/Account.hpp#L43).

# Evaluation
**Score:** 100%
> "Really nice implementation, a lot of different corner cases handled quite well, very handy additional commands for the 01 exercise. Nice project! Good luck!"
> 		- Dmitrii Mikhailenko

**Score:** 94%
> "- sign in phonebook gives an error in search index"
> 		- Astrid Geels

# Creator
Othello<br>
[<img alt="LinkedIn" height="32px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png" target="_blank" />](https://github.com/OthelloPlusPlus)
[<img alt="LinkedIn" height="32px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/600px-LinkedIn_logo_initials.png" target="_blank" />](https://nl.linkedin.com/in/orlando-hengelmolen)
