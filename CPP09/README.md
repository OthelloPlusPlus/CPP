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
This exercise requires you to use the Reverse Polish Notation, which is a faster, but less legible mathematical notation. All numbers and operations are placed in order of processing and therefor no '( )' are required. Each number passed is stored and when a mathematical operator is found it is used to process the top 2 numbers.

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

This exercise requires you to sort a string of numbers using the the [Ford–Johnson algorithm](https://en.wikipedia.org/wiki/Merge-insertion_sort). Sorting in this method is a relatively slow method, however it greatly reduces the amount of comparisons requires. In situations where a comparison is slow (i.e. human execution) this becomes a fast implementation.

<table>
	<thead style="background-color: #C0C0C0;">
		<tr>
			<th rowspan="2">#</th>
			<th rowspan="2">Operation</th>
			<th colspan="3">Example</th>
		</tr>
		<tr>
			<th>Sequence(s)</th>
			<th>Ordening</th>
			<th>Remnant</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td>Starting Array</td>
			<td>[1 3 5 7 9 2 4 6 8 0 10]</td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>1.a</td>
			<td>For an odd array, keep the remnant for later</td>
			<td>[1 3 5 7 9 2 4 6 8 0]</td>
			<td></td>
			<td>[10]</td>
		</tr>
		<tr>
			<td>1.b</td>
			<td>Split the array pairs</td>
			<td>[1 5 9 4 8]<br>[3 7 2 6 0]</td>
			<td></td>
			<td>[10]</td>
		</tr>
		<tr>
			<td>2</td>
			<td>Put the larger component on top for each pair</td>
			<td>[3 7 9 6 8]<br>[1 5 2 4 0]</td>
			<td></td>
			<td>[10]</td>
		</tr>
		<tr>
			<td>3</td>
			<td>Sort the pairs ascending, based on the top value</td>
			<td>[3 6 7 8 9]<br>[1 4 5 0 2]</td>
			<td></td>
			<td>[10]</td>
		</tr>
		<tr>
			<td>4</td>
			<td>Define the <a href="#jacobsthal-sequence">order of insertion</a> for the least comparisons</td>
			<td>[3 6 7 8 9]<br>[1 4 5 0 2]</td>
			<td><br>[0 1 3 2 4]</td>
			<td>[10]</td>
		</tr>
		<tr>
			<td rowspan="5">5</td>
			<td rowspan="5">Insert bottom sequence into top sequence<br> - Using ordering for next to number to merge<br> - Using Binary Search to position to insert</td>
			<td>[1 3 6 7 8 9]<br>[- 4 5 0 2]</td>
			<td><br>[- 1 3 2 4]</td>
			<td rowspan="5">[10]</td>
		</tr>
		<tr>
			<td>[1 3 4 6 7 8 9]<br>[- - 5 0 2]</td>
			<td><br>[- - 3 2 4]</td>
		</tr>
		<tr>
			<td>[0 1 3 4 6 7 8 9]<br>[- - 5 - 2]</td>
			<td><br>[- - 3 - 4]</td>
		</tr>
		<tr>
			<td>[0 1 3 4 5 6 7 8 9]<br>[- - - - 2]</td>
			<td><br>[- - - - 4]</td>
		</tr>
		<tr>
			<td>[0 1 2 3 4 5 6 7 8 9]</td>
			<td></td>
		</tr>
		<tr>
			<td>6</td>
			<td>Add the remnant</td>
			<td>[0 1 2 3 4 5 6 7 8 9 10]</td>
			<td></td>
			<td></td>
		</tr>
	</tbody>
</table>

### Jacobsthal Sequence
The ordering is structured as such, without knowing what the sequence's values are, that the least amount of comparisons have to be made.
An efficient ordering coincides with the Jacobsthal sequence. This is a sequence, starting with 0 and 1 that takes the 2 previous numbers, multiplies the first by 2 and adds the second.
For example 21 43 ==> 21 * 2 + 43 ==> 85

The Jacobsthal Sequence can be used the derive the order of the indexes. Where missing numbers are added, decrementally, after their first higher value (after 11 comes 10, 9, 8, 7 and 6).
<table>
	<thead style="background-color: #C0C0C0;">
		<tr>
			<th colspan="5">Derived Jacobsthal Ordering</th>
		</tr>
		<tr>
			<th rowspan="2">#</th>
			<th rowspan="2">Operation</th>
			<th colspan="3">Example</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td>0</td>
			<td>Jacobsthal Number</td>
			<td>0, 1, 1, 3, 5, 11, 21, 43, ...</td>
		</tr>
		<tr>
			<td>1</td>
			<td>Limit to Sequence Size (23) and remove duplicate</td>
			<td>0, 1, 3, 5, 11, 21, 23</td>
		</tr>
		<tr>
			<td rowspan="3">2</td>
			<td rowspan="3">Add the missing numbers<br> - After each number count down and add each missing number</td>
			<td>0,<br>1,<br>3,<br>5,<br>11,<br>21,<br>23,</td>
		</tr>
		<tr>
			<td>0,<br>1,<br>3, 2,<br>5, 4,<br>11, 10, 9, 8, 7, 6,<br>21, 20, 19, 18, 17, 16, 15, 14, 12,<br>23, 22</td>
		</tr>
		<tr>
			<td>0, 1, 3, 2, 5, 4, 11, 10, 9, 8, 7, 6, 21, 20, 19, 18, 17, 16, 15, 14, 12, 23, 22</td>
		</tr>
	</tbody>
</table>

The value of the Derived Jacobsthal Number tells the turn order of the associated Bottom Sequence to be merged. Sorting the Derived Jacobsthal, keeping the Sequence linked to the same index, displays in what order the Sequence should be merged. For example, '0' is on the 10th spot, but is the 7th to be merged into the Top Sequence.

<table>
	<thead style="background-color: #C0C0C0;">
		<tr>
			<th colspan="11">Ordering</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td colspan="11">Sequence Order</td>
		<tr>
			<td>Sequence</td>
			<td>1</td><td>3</td><td>5</td><td>7</td><td>9</td><td>2</td><td>4</td><td>6</td><td>8</td><td>0</td>
		</tr>
		<tr>
			<td>Derived Jacobsthal</td>
			<td>0</td><td>1</td><td>3</td><td>2</td><td>5</td><td>4</td><td>9</td><td>8</td><td>7</td><td>6</td>
		</tr>
		<tr>
			<td colspan="11">Merge-insertion order</td>
		<tr>
		<tr>
			<td>Sequence</td>
			<td>1</td><td>3</td><td>7</td><td>5</td><td>2</td><td>9</td><td>0</td><td>8</td><td>6</td><td>4</td>
		</tr>
		<tr>
			<td>Derived Jacobsthal</td>
			<td>0</td><td>1</td><td>2</td><td>3</td><td>4</td><td>5</td><td>6</td><td>7</td><td>8</td><td>9</td>
		</tr>
	</tbody>
</table>


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
