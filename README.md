# XLDate
A C++ Date class based on the new C++20 date namespace and compatible with Excel's date indexing

# Quickstart
To run `main()` with docker
````
src> docker build -t XLDate:latest .
src> docker run XLDate:latest
````
Catch2 tests can be executed in Docker as well
````
src> docker run XLDate:latest /build/XLDateTests -s
````
![Docker running XLDateMain abd XLDateTests](docs/docker-build-run.gif)
# Contributing
## Building
[CMake](https://cmake.org) is used to generate platform specific build sources.
````
src> cmake -S XLDate -B /path/to/build/dir
````
Snippet above generates `Makefile` builds by default on *nix systems

Alternatively, CMake GUI can be used to generate build sources as well
![CMake generating XCode project](docs/CMake-XCode.gif)

## Running Tests
````
build> make XLDateTests
build> ./XLDateTests -s
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
XLDateTests is a Catch v2.13.1 host application.
Run with -? for options

-------------------------------------------------------------------------------
Test YYYY,MM,DD date format to integer representation
-------------------------------------------------------------------------------
/src/XLDate/DateTests/Tests_Dates.cpp:10
...............................................................................

/src/XLDate/DateTests/Tests_Dates.cpp:11: PASSED:
  CHECK( d1.serialDate() == 26963 )
with expansion:
  26963 (0x6953) == 26963 (0x6953)

/src/XLDate/DateTests/Tests_Dates.cpp:12: PASSED:
  CHECK( d2.serialDate() == 42573 )
with expansion:
  42573 (0xa64d) == 42573 (0xa64d)
  
  ...
 
````





