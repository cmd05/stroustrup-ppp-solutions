# Interactive Skip List 

C++ implementation of a skip list data-structure, along with an interactive console to visualize and experiment with the list.

```
-INF <-----------------------------------------------------> 75.000000 <----> INF
-INF <-----------------------------------------------------> 75.000000 <----> INF
-INF <-------------------> 1.000000 <----------------------> 75.000000 <----> INF
-INF <-------------------> 1.000000 <-----> 10.000000 <----> 75.000000 <----> INF
-INF <--> -100.000000 <--> 1.000000 <-----> 10.000000 <----> 75.000000 <----> INF
```

## Demo
<p align="center">
    <img src='https://user-images.githubusercontent.com/63466463/151653318-a2aa3f00-5efd-4c79-bd79-1242eaaaf3e0.gif'>
</p>

## Example
```cpp
std::vector<double> v = {90, 15, -59, 48, -1, -28};
Skip_List skip_list{v};

/// Operations
skip_list.insert(5);
skip_list.remove(90);
Node* node = skip_list.search(-1);
skip_list.remove(5);

/// Console
Console console{skip_list, "output.txt"};
console.write_to_file("output.txt");
console.run();
```