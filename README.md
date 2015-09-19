## CSCI 2312: Programming Assignment 1

_working with objects_

* * *

C++ lets us program with _objects_. We describe objects in C++ by declaring and defining _classes_. We _declare_ our class's structure in a header file, just like in C, and _define_ it (that is, write the code that actually does the work) in a corresponding source code file.

Here is a sample header file <tt>Point.h</tt> that describes an object that represents a point in two-dimensional Euclidean space:

```c++
// A 2-dimensional point class!
// Coordinates are double-precision floating point.
class Point {

private:
double x;
double y;

public:
// Constructors
Point();                      // default constructor
Point(double x, double y);    // two-argument constructor

// Destructor
~Point();

// Mutator methods
void setX(double newX);
void setY(double newY);

// Accessor methods
double getX();
double getY();
};
```

We can _instantiate_, or create an instance of, our class anywhere in the rest of our code by calling any of the constructors we have defined:

```c++ 
Point myPoint;            // Calls Point::Point()
Point myOtherPoint(5, 3); // Calls two-argument constructor Point::Point(double, double)
```

### Your Task

1.  Fork the [Github repository for CSCI 2312 PA1](https://github.com/ivogeorg/ucd-csci2312-pa1). Then clone it to your local development environment (e.g. laptop). You will find the Point.h and Point.cpp files for the 2D Point class, along with a skeleton driver file pa1.cpp with barely any code in it.

2.  Change the <tt>Point</tt> class to represent points in three dimensions. Make sure to update the comments to match this change!

3.  Add a new member function to <tt>Point</tt> called <tt>distanceTo</tt>. This member function should accept as an argument a <u><tt>Point &</tt></u> (a reference to a <tt>Point</tt>), and it should return a <tt>double</tt> that approximates the distance between the two points.

You will probably find a square-root function useful for this! The C standard library has one, called <tt>sqrt()</tt>. The function takes a double and returns another double.

If you were programming in C, you would
```c++
#include <math.h>
```
but in C++ you say
```c++
#include <cmath>
```
(This means, "Include the C Math header.") And then you are all set.

4.  Create a new source file <tt>pa1.cpp</tt> and implement two functions:

*   <tt>double computeArea(Point &a, Point &b, Point &c)</tt>

which takes by reference three <tt>Point</tt> objects, computes the area within the triangle defined by these points (hint: use [Heron's Formula](http://en.wikipedia.org/wiki/Heron%27s_formula)), and returns it as a double-precision floating point number.

*   <tt>int main()</tt>

which requests three points (nine coordinates) from the user, determines the area inside the triangle described by the three points using the aforementioned function, and displays the result.

In C++, you don't have to declare all variables at the top of a block; you can intermingle variable declarations and statements of code. So, you should only need to use three <tt>double</tt> variables to input the coordinates, and then create each <tt>Point</tt> along the way.

**Don't worry about dealing with bad user input.** For now, you can follow the oft-used program behavior: "Garbage in, garbage out!"

5.  Compile these sources together like so:

```
g++ -Wall lab1.cpp Point.cpp -o pa1
```

Note:
*   <tt>g++</tt> is the GNU C++ compiler.
*   <tt>-Wall</tt> means "output ALL warnings." (If you see any warnings, be sure to fix them.)
*   Next comes the list of source files. (You don't list header files here. They are included by the source files.) The only new part here is that we have _two_ files: <tt>lab1.cc</tt> and <tt>Point.cc</tt>.
*   <tt>-o</tt> specifies the output file. In this case, we are making a program called <tt>lab1</tt>.

CLion uses CMake to create a makefile for your architecture. It uses the directives in the CMakeLists.txt file which can be found in your project's directory. The file looks like this

```
cmake_minimum_required(VERSION 3.2)
project(pa1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Point.cpp PA1.cpp)
add_executable(pa1 ${SOURCE_FILES})
```

For this project, all you need to do to run your Point code on CLion is to list all your *.cpp files as shown above.

6.  Run the generated program:

```
./pa1
```

In CLion, you first have to build (Run-->Build) and then run (Run-->Run 'PA1') your project. Any output will appear in the built-in console.

7.  Go back and test <tt>computeArea</tt> with several boundary and/or extreme cases to make sure your implementation is robust for all triangles, including degenerate ones. Things you might try:

*   Triangles with no area - all three points on the same line
*   Triangles where two points are the same
*   Triangles where all three points are the same
*   Triangles with negative coordinate values
*   etc.

In software-engineering parlance, these degenerate cases are called "edge cases" or "corner cases," because they test combinations of inputs that may be rare, but still possible. Usually, you want to start out by seeing if your program can handle simple cases that will expose obvious issues. Once your program can handle these, then you move on to the more subtle test scenarios.

8.  Update the README.md file in your local repository with a description of your 3D Point class. You can use this file as a guide.

9.  Commit all code changes to your local Github repository, then push the changes to the master repository on Github.

10. Submit the URL of your CSCI 2312 repository on Canvas.

### Grading

An autograding script will test your class on a variety of inputs and assign a grade based on the number of correct outputs. (E.g. if you get 3 out of 6 test cases correct, your correctness score will be 50%). The correctness score will count for 67% of your overall grade. In addition, your code will be evaluated for style (comments, separate h and cpp files, etc). We will say more about style in lecture. Style will be evaluated on a three-point system (1-bad, 2-ok, 3-excellent) and the style grade will count for the remaining 33% of your grade. 

* * *

<font size="-1">ACKNOWLEDGEMENT: Modelled after CS11 Lab 1 at Caltech.</font>

<font size="-1">Some content Copyright (C) 2004-2010, California Institute of Technology.</font>
