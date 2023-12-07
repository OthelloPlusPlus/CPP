# Intro
> Templated containers, iterators, algorithms

## Exercise 00 - Easy find
This exercise required you to make a template function which finds the first occurence of an integer in a container.

[Containers](https://en.cppreference.com/w/cpp/container) are class templates which store information and allow for easy access.

<table>
	<thead style="background-color: #C0C0C0;">
		<tr>
			<th>Container Class</th>
			<th>Subtype</th>
			<th>Container</th>
			<th>Compatible</th>
			<th>Information</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan="12">Sequence</td>
			<td rowspan="5"><a href="https://en.cppreference.com/w/cpp/container#Sequence_containers">Sequence</a></td>
			<td>vector</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td>deque</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td>list</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td>array(C++11)</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td>forward_list(C++11)</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td rowspan="7"><a href="https://en.cppreference.com/w/cpp/container#Container_adaptors">Adaptor</a></td>
			<td>stack</td>
			<td>No</td></td>
			<td rowspan="3">The underlying container is protected.</td>
		</tr>
		<tr>
			<td>queue</td>
			<td>No</td>
		</tr>
		<tr>
			<td>priority_queue</td>
			<td>No</td>
		</tr>
		<tr>
			<td>flat_set(C++23)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td>flat_map(C++23)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td>flat_multiset(C++23)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td>flat_multimap(C++23)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td rowspan="8">Associative</td>
			<td rowspan="4"><a href="https://en.cppreference.com/w/cpp/container#Associative_containers">Ordered</a></td>
			<td>set</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td>multiset</td>
			<td>Yes</td>
			<td></td>
		</tr>
		<tr>
			<td>map</td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td>multimap</td>
			<td></td>
			<td></td>
		</tr>
		<tr>
			<td rowspan="4"><a href="https://en.cppreference.com/w/cpp/container#Unordered_associative_containers">Unordered</a></td>
			<td>unordered_set(C23++)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td>unordered_multiset(C23++)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td>unordered_map(C23++)</td>
			<td>???</td>
			<td></td>
		</tr>
		<tr>
			<td>unordered_multimap(C23++)</td>
			<td>???</td>
			<td></td>
		</tr>
	</tbody>
</table>

## Exercise 01 - Span
This exercise requires you to make a class Span which can contain a list of integers.

It can then find the shortest and longest spans between these integers.