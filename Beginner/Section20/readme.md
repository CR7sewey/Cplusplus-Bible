## STL

- Library that contains:
  algorithms (ex - sort, accumulate, find, max, min etc),
  iterators (forward, reverse, by value, by reference, constant etc),
  containers (ex - array, vector, deque, set, map, queue, priority queue)
  c++ templates

## Containers

data structures that can store object of almost any type

each container has member functions (some specific others available to all)

each container has an associated header file

common:
default constructor;
overloaded constructors;
copy constructor;
move constructor;
destructor;
copy assignment(=);
Move assignment;
size;
empty;
insert;
< and <=;
...

all primitive types can be stored
element should be copyable and assignable, moveable

## Iterators

Container as a sequence of elements, does not matter what the container is
Work like pointers - operations like ++it; it->, ìt, it = it1 etc

syntax:
container_type::iterator_type name;
ex:
std::map<std::string, int>::iterator it;
std::vector<int>::reverse_iterator it;

begin and end methods (container methods) - return an iterator object that is pointing to something (1 or after 3 ex.)
if std::vec<int> vec {1,2,3};
vec.begin() - 1
vec.end() - location after the last element (after 3)

ex:
std::vector<int>::iterator it = vec.begin()
auto it = vec.begin()

## Algorithms

work on sequences of a container elements provided to them by an iterator

Iterator invalidation
ex: iterating over a vecotr and peform the clean while iterating

ex: find
std::vector<int> vec {1,2,3};
std::find(vec.begin(), vec.end(), 3);

ex: for_each
