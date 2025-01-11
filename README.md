# HW 1 Submission

## Exercise 1
### Frame Output
```
nicholaslee@Nicholass-MacBook-Pro-2 Frame % cmake -S . -B build/
-- The C compiler identification is AppleClang 16.0.0.16000026
-- The CXX compiler identification is AppleClang 16.0.0.16000026
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (2.5s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/nicholaslee/Desktop/Fourth_Year/Quarter_2/MPCS_51044/week1/hw1/lec01_files/Frame/build
nicholaslee@Nicholass-MacBook-Pro-2 Frame % cmake --build ./build
[ 50%] Building CXX object CMakeFiles/frame.dir/frame.cpp.o
/Users/nicholaslee/Desktop/Fourth_Year/Quarter_2/MPCS_51044/week1/hw1/lec01_files/Frame/frame.cpp:22:9: warning: 'auto' type specifier is a C++11 extension [-Wc++11-extensions]
   22 |   const auto cols = greeting.size() + pad * 2 + 2;
      |         ^
1 warning generated.
[100%] Linking CXX executable frame
[100%] Built target frame
nicholaslee@Nicholass-MacBook-Pro-2 Frame % cd build 
nicholaslee@Nicholass-MacBook-Pro-2 build % ls
CMakeCache.txt          CMakeFiles              Makefile                cmake_install.cmake     frame
nicholaslee@Nicholass-MacBook-Pro-2 build % ./frame
What's your name? Nicholas

****************************
*                          *
*                          *
*                          *
*                          *
*                          *
*     Hello, Nicholas!     *
*                          *
*                          *
*                          *
*                          *
*                          *
****************************
```
### vector_simple
See `./VectorSimpleDemo/CMakeLists.txt` for the CMakeLists.txt file
```
nicholaslee@Nicholass-MacBook-Pro-2 VectorSimpleDemo % cmake -S . -B build/             
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/nicholaslee/Desktop/Fourth_Year/Quarter_2/MPCS_51044/week1/hw1/VectorSimpleDemo/build
nicholaslee@Nicholass-MacBook-Pro-2 VectorSimpleDemo % cmake --build ./build            
[100%] Built target vector_simple_demo
nicholaslee@Nicholass-MacBook-Pro-2 VectorSimpleDemo % ls
CMakeLists.txt          build                   vector_simple_demo.cpp
nicholaslee@Nicholass-MacBook-Pro-2 VectorSimpleDemo % cd build 
nicholaslee@Nicholass-MacBook-Pro-2 build % ls
CMakeCache.txt          CMakeFiles              Makefile                cmake_install.cmake     vector_simple_demo
nicholaslee@Nicholass-MacBook-Pro-2 build % ./vector_simple_demo 
1, 4, 16, %                           
```
## Exercise 2
See hw1-2.cpp
```
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % cmake -S . -B build/    
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % cmake --build ./build
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/nicholaslee/Desktop/Fourth_Year/Quarter_2/MPCS_51044/week1/hw1/build
[ 50%] Built target pascal
[ 75%] Building CXX object CMakeFiles/pascal-brick.dir/hw1-3.cpp.o
[100%] Linking CXX executable pascal-brick
[100%] Built target pascal-brick
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % cd build 
nicholaslee@Nicholass-MacBook-Pro-2 build % ls
CMakeCache.txt          CMakeFiles              Makefile                cmake_install.cmake     pascal                  pascal-brick
nicholaslee@Nicholass-MacBook-Pro-2 build % ./pascal
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
1 5 10 10 5 1 
1 6 15 20 15 6 1 
1 7 21 35 35 21 7 1 
```
## Exercise 3
See hw1-3.cpp
```
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % cmake -S . -B build/    
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % cmake --build ./build
-- Configuring done (0.1s)
-- Generating done (0.0s)
-- Build files have been written to: /Users/nicholaslee/Desktop/Fourth_Year/Quarter_2/MPCS_51044/week1/hw1/build
[ 50%] Built target pascal
[ 75%] Building CXX object CMakeFiles/pascal-brick.dir/hw1-3.cpp.o
[100%] Linking CXX executable pascal-brick
[100%] Built target pascal-brick
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % cd build 
nicholaslee@Nicholass-MacBook-Pro-2 build % ls
CMakeCache.txt          CMakeFiles              Makefile                cmake_install.cmake     pascal                  pascal-brick
nicholaslee@Nicholass-MacBook-Pro-2 build % ./pascal-brick 
                      1                      
                   1     1                   
                1     2     1                
             1     3     3     1             
          1     4     6     4     1          
       1     5    10    10     5     1       
    1     6    15    20    15     6     1    
 1     7    21    35    35    21     7     1 
```
## Exercise 4
The easiest way to break a program is by using keywords that are not defined in the program. For C to break C++, this just means using C++ keywords in C code. 
```c
#include <stdio.h>

int main(){
    int namespace = 5;
    printf("%d\n", namespace);
    return 0;
}
```
This will break the program because `namespace` is a keyword in C++ but not in C. 
```
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % gcc exercise4.c  
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % ./a.out        
5
nicholaslee@Nicholass-MacBook-Pro-2 hw1 % gcc exercise4.cpp
exercise4.cpp:4:9: error: expected unqualified-id
    4 |     int namespace = 5;
      |         ^
exercise4.cpp:5:20: error: expected expression
    5 |     printf("%d\n", namespace);
      |                    ^
2 errors generated.
```
- See exercise4.c for the C code that works. See exercise4.cpp for the C++ code that breaks.

## Exercise 5
- The reason is C++ and not ++C, is because ++ after the variable name is the post-increment operator. Since C++ is built on C, we are incrementing on C but C is still the base language and is used. If it were to be ++C, that is more like an update of C, which is not what we are doing.

# References
- https://cmake.org/cmake/help/v3.20/guide/tutorial/index.html?highlight=destination#:~:text=The%20easiest%20way%20to%20enable,11%20and%20CMAKE_CXX_STANDARD_REQUIRED%20to%20True.
    - To understand how to set the C++ standard in CMakeLists.txt
- https://cmake.org/cmake/help/latest/command/find_package.html
    - To understand how to use find_package in CMakeLists.txt to find fmt library