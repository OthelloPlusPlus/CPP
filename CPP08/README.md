# Intro
> Templated containers, iterators, algorithms
https://en.cppreference.com/w/cpp/container

## Exercise 00 - Easy find
This exercise required you to make a template function which finds the first occurence of an integer in a container.

There are 2 main types of (containers)[https://en.cppreference.com/w/cpp/container], which store and access information differently.
<table>
  <tr>
    <th colspan="2">Container Class</th>
  </tr>
  <tr>
    <td>Sequence</td>
    <td>Associative</td>
  </tr>
  <tr>
    <th>Subtype</th>
    <th>Subtype</th>
    <th>Compatible</th>
    <th>Information</th>
  </tr>
  <tr>
    <td rowspan="2">Sequence</td>
    <td rowspan="2">Ordered</td>
    <td>T</td>
    <td>Holds a collection of elements in sequential order.</td>
  </tr>
  <tr>
    <td>Unordered</td>
    <td>T*, const T*</td>
    <td>Does not store elements in sequential order.</td>
  </tr>
  <tr>
    <td rowspan="2">Adaptor</td>
    <td rowspan="2">None</td>
    <td>T, const T&, T*</td>
    <td>Provides alternative ways to access and modify elements in a container.</td>
  </tr>
  <tr>
    <td>None</td>
    <td>T&, const T&, T*</td>
    <td></td>
  </tr>
</table>

- Sequence containers
It has been made compatible for (Sequence containers)[https://en.cppreference.com/w/cpp/container] and the Associative containers
