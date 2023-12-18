# Intro
> STL

Within the STL there are [several containers](https://en.cppreference.com/w/cpp/container) to choose from. Each having its own perks and limitations. The purpose of this project is learning to select the most suitable container from all available options.

# Table of Contents
- Excersises
  - [Exercise 00](#exercise-00---bitcoin-exchange)
  - [Exercise 01](#exercise-01---reverse-polish-notation)
  - [Exercise 02](#exercise-02---pmergeme)
- [Evaluation](#evaluation)
- [Creator](#creator)

## Exercise 00 - Bitcoin Exchange
| Container | [std::map](https://en.cppreference.com/w/cpp/container/map) |
| :--- | :--- |
| Template | `<std::string, double>` |
| Type | [Ordered Associative Container](https://en.cppreference.com/w/cpp/container#Associative_containers) |

This exercise requires you to create a program which calculates the current value of someones Bitcoin Portfolio. This does this using 2 files. One which contains the [history of Bitcoin value](ex00/file/data.csv) and one which contains the [persons Portfolio](ex00/file/input.txt). As an Ordered Associative Container [std::map](https://en.cppreference.com/w/cpp/container/map) is the most suitable for this. std::map can use the date as a key to store information, and its approach to sorted storing allows for easy retrieval of the correct current value of Bitcoin.

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
			<td><a href="ex00/Makefile" target="_blank">.make</a></td>
			<td></td>
			<td>Creates the binary 'btc'</td>
		</tr>
		<tr>
			<td>./btc</td>
			<td>[path/to/portfolio]</td>
			<td>Calculates and prints the portfolio (date | value) value on each given moment.</td>
		</tr>
		<tr>
			<td><a href="ex00/test.sh" target="_blank">./test.sh</a></td>
			<td></td>
			<td>Runs the Makefile and then runs the binary with a series of files.</td>
		</tr>
  </tbody>
</table>


## Exercise 01 - Reverse Polish Notation
| Container | [std::stack](https://en.cppreference.com/w/cpp/container/stack) |
| :--- | :--- |
| Template | `<double>` |
| Type | [Container Adeptor](https://en.cppreference.com/w/cpp/container#Container_adaptors) |

There are three types of mathematical notation. The most commonly used is the [Infix Notation](https://en.wikipedia.org/wiki/Infix_notation). the less known ones are the [Prefix/Polish Notation](https://en.wikipedia.org/wiki/Polish_notation) and [Postfix/Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).
This exersize requires you to use the Reverse Polish Notation, which is a faster, but less legible mathematical notation. All numbers and operations are placed in order of processing and therefor no '( )' are required. Each number passed is stored and when a mathematical operator is found it is used to process the top 2 numbers.

| Infix n | PN | RPN |
| :--- | :--- | :--- |
| 1 / (2 - 3 * (4 + 5)) |  / 1 - 2 * 3 + 4 5 | 1 2 3 4 5 + * - / |
| 1 / (2 - 3 * 9 ) |  / 1 - 2 * 3 9 | 1 2 3 9 * - / |
| 1 / (2 - 27) |  / 1 - 2 * 27  | 1 2 27 - / |
| 1 / -25 |  / 1 -25 | 1 -25 \ |
| -0.04 |  -0.04 | - 0.04 |

## Exercise 02 - PmergeMe
|||
| :--- | :--- |
| Containers | [std::vector](https://en.cppreference.com/w/cpp/container/vector) |
|| [std::deque](https://en.cppreference.com/w/cpp/container/deque) |
|| [std::list](https://en.cppreference.com/w/cpp/container/list) |
| Template | `<int>` |
| Type | [Sequence Containers](https://en.cppreference.com/w/cpp/container#Sequence_containers) |

https://en.wikipedia.org/wiki/Merge-insertion_sort

# Evaluation
**Score:** %
> ""
> 		- 

**Score:** %
> ""
> 		- 

# Creator
Othello<br>
[<img alt="LinkedIn" height="32px" src="https://github.githubassets.com/images/modules/logos_page/GitHub-Mark.png" target="_blank" />](https://github.com/OthelloPlusPlus)
[<img alt="LinkedIn" height="32px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/LinkedIn_logo_initials.png/600px-LinkedIn_logo_initials.png" target="_blank" />](https://nl.linkedin.com/in/orlando-hengelmolen)
