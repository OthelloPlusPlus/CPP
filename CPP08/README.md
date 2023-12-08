# Intro
> Templated containers, iterators, algorithms

[Containers](https://en.cppreference.com/w/cpp/container) are objects that store and manage collections of elements. They provide a way to organize and manipulate data in a structured manner. Containers are part of the C++ Standard Template Library (STL) and are implemented as templates, allowing them to work with different data types.

There are two main categories of containers in the STL: [Sequence containers](https://en.cppreference.com/w/cpp/container#Sequence_containers) and [Associative containers](https://en.cppreference.com/w/cpp/container#Associative_containers).
- Sequence containers store data in a linear order, allowing easy access to each element based on its location.
- Associative containers store data based on keys. These keys specify a reference value which is coupled to the stored data, allowing easy access to each element based on its key.

The STL also contains a variety of template functions. These templates can be accessed with a variety of types and adjust their functionality accordingly. This adaptability is limited and should be considered by the programmer.

## Exercise 00 - Easy find
This exercise introduces you to the containers and template functions stored in the STL. It requires you to create a template function which can find an integer value stored in a container<int>. For this [std::find()](https://en.cppreference.com/w/cpp/algorithm/find) and container.begin() and container.end() are used. These options are broadly complatible, but not universal.

<table>
	<thead style="background-color: #C0C0C0;">
		<tr>
			<th colspan="4">Container compatability with <a href="ex00/easyfind.hpp#L20">easyfind()</a></th>
		</tr>
		<tr>
			<th>Container Class</th>
			<th>Subtype</th>
			<th>Container</th>
			<th>Compatible</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan="12">Sequence</td>
			<td rowspan="5"><a href="https://en.cppreference.com/w/cpp/container#Sequence_containers">Sequence</a></td>
			<td>vector</td>
			<td rowspan="5">Yes</td>
		</tr>
		<tr>	<td>deque</td>	</tr>
		<tr>	<td>list</td>	</tr>
		<tr>	<td>array(C++11)</td>	</tr>
		<tr>	<td>forward_list(C++11)</td>	</tr>
		<tr>
			<td rowspan="7"><a href="https://en.cppreference.com/w/cpp/container#Container_adaptors">Adaptor</a></td>
			<td>stack</td>
			<td rowspan="3">The underlying container is protected</td>
		</tr>
		<tr>	<td>queue</td>	</tr>
		<tr>	<td>priority_queue</td>	</tr>
		<tr>
			<td>flat_set(C++23)</td>
			<td rowspan="4">C++23 Unsupported</td>
		</tr>
		<tr>	<td>flat_map(C++23)</td>	</tr>
		<tr>	<td>flat_multiset(C++23)</td>	</tr>
		<tr>	<td>flat_multimap(C++23)</td>	</tr>
		<tr>
			<td rowspan="8">Associative</td>
			<td rowspan="4"><a href="https://en.cppreference.com/w/cpp/container#Associative_containers">Ordered</a></td>
			<td>set</td>
			<td rowspan="2">Yes</td>
		</tr>
		<tr>	<td>multiset</td>	</tr>
		<tr>
			<td>map</td>
			<td rowspan="2">Incompatible with <a href="https://en.cppreference.com/w/cpp/algorithm/find">std::find</a></td>
		</tr>
		<tr>	<td>multimap</td>	</tr>
		<tr>
			<td rowspan="4"><a href="https://en.cppreference.com/w/cpp/container#Unordered_associative_containers">Unordered</a></td>
			<td>unordered_set(C23++)</td>
			<td rowspan="4">C++23 Unsupported</td>
		</tr>
		<tr>	<td>unordered_multiset(C23++)</td>	</tr>
		<tr>	<td>unordered_map(C23++)</td>	</tr>
		<tr>	<td>unordered_multimap(C23++)</td>	</tr>
	</tbody>
</table>

## Exercise 01 - Span
This exercise expands on the use of STL's containers and template functions. It requires you to make a class which can [store an integer array](ex01/Span.hpp#L25). After adding values to the array you have to be able to request the [shortest](ex01/Span.cpp#L91) and [longest](ex01/Span.cpp#L102) span between them, using STL algorithms.

## Exercise 02 - Mutated abomination
This exercise further expands on the use of containers. It familiarises you on their member functions and the use of [iterators](ex02/Mutantstack.hpp#L27). It requires you to create a new container [MutantStack](ex02/MutantStack.hpp#L20) which inherits from [std::stack](https://en.cppreference.com/w/cpp/header/stack).
After the addition of iterators and [associated member functions](ex02/MutantStack.hpp#L33) the class is expected to behave, in these aspects, as [std::list](https://en.cppreference.com/w/cpp/header/list).

<table>
	<thead>
		<tr>
			<th colspan="5"><a href="https://en.cppreference.com/w/cpp/container#Member_function_table">Member function table</a></th>
		</tr>
		<tr>
			<th>Member Type</th>
			<th>Member Function</th>
			<th><a href="https://en.cppreference.com/w/cpp/header/list">std::list</a></th>
			<th><a href="https://en.cppreference.com/w/cpp/header/stack">std::stack</a></th>
			<th><a href="ex02/MutantStack.hpp#L20">MutantStack</a></th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan="4">Iterators</td>
			<td>begin</td>
			<td>begin</td>
			<td></td>
			<td><a href="ex02/MutantStack.hpp#L33">begin</a></td>
		</tr>
  		<tr>
			<td>end</td>
			<td>end</td>
			<td></td>
			<td><a href="ex02/MutantStack.hpp#L36">end</a></td>
		</tr>
  		<tr>
			<td>rbegin</td>
			<td>rbegin</td>
			<td></td>
			<td><a href="ex02/MutantStack.hpp#L34">rbegin</a></td>
		</tr>
  		<tr>
			<td>rend</td>
			<td>rend</td>
			<td></td>
			<td><a href="ex02/MutantStack.hpp#L37">rend</a></td>
		</tr>
		<tr>
			<td rowspan="5">Element access</td>
			<td>at</td>
			<td></td>
			<td></td>
			<td></td>
		</tr>
  		<tr>
			<td>operator[]</td>
			<td></td>
			<td></td>
			<td><a href="ex02/MutantStack.hpp#L44">operator[]</a></td>
		</tr>
  		<tr>
			<td>front</td>
			<td>front</td>
			<td></td>
			<td></td>
		</tr>
  		<tr>
			<td rowspan="2">back</td>
			<td rowspan="2">back</td>
			<td rowspan="2">top</td>
			<td><a href="ex02/MutantStack.hpp#L35">back</a></td>
		</tr>
		<tr>
			<td>top</td>
		</tr>
  		<tr>
			<td rowspan="1">Misc</td>
   			<td>push_back</td>
      			<td>push_back</td>
      			<td>push</td>	
      			<td>push</td>	
		</tr>
	</tbody>
</table>
