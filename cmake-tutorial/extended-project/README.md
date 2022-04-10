## C++ Project using CMake 

This is an example project using CMake inspired by [modern-cmake](https://gitlab.com/CLIUtils/modern-cmake/)

The requirements are:

- CMake 3.11 or better; 3.14+ highly recommended.
- A C++17 compatible compiler
- The Boost libararies (header only part is fine)
- Git
- Doxygen (optional)

## Build and Run

### Build

The build requires absolute path to boost library installed on the system to be passed `BOOST_PATH` variable.

```
cmake -S . -B build -G "MinGW Makefiles" -DBOOST_PATH="C:/path_to_boost/boost_1_66_0/boost_1_66_0"
```

### Make
```   
make -C build
```

### Run
```
build\apps\app
```

### Run Tests
To test (--target can be written as -t in CMake 3.15+):

```
cmake --build build --target test
```

### Build Docs

To build docs (requires Doxygen, output in build/docs/html):

```
cmake --build build --target docs
```

### Open in IDE

To use an IDE, such as Xcode:
```
cmake -S . -B xbuild -GXcode
cmake --open xbuild
```

