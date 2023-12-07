# Intro
> Templated containers, iterators, algorithms
https://en.cppreference.com/w/cpp/container

## Exercise 00 - Easy find
This exercise required you to make a template function which finds the first occurence of an integer in a container.

There are 2 main types of (containers)[https://en.cppreference.com/w/cpp/container], which store and access information differently.
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
			<td rowspan="4">Sequence</td>
			<td rowspan="2">Sequence</td>
			<td rowspan="2">Adaptor</td>
		</tr>
		<tr>
			<td rowspan="4">Associative</td>
			<td rowspan="2">Ordered</td>
			<td rowspan="2">Unordered</td>
			<td>Array</td>
			<td>yes</td>
		</tr>
		<tr>
			<td>vector</td>
			<td>yes</td>
		</tr>
	</tbody>
</table>

- Sequence containers
It has been made compatible for (Sequence containers)[https://en.cppreference.com/w/cpp/container] and the Associative containers
