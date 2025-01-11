#include <vector>
#include <iostream>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
using namespace fmt;

using namespace std;

// exercise 1.2
void print_pascal_triangle(int n){
    vector<vector<int> > pascal_rows = {{1}};
    for(int i = 1; i < n; i++){
        // always start and end with 1.
        vector<int> new_row = {1};
        for(int j = 1; j < i; j++){
            new_row.push_back(pascal_rows.at(i - 1).at(j - 1) + pascal_rows.at(i - 1).at(j) );
        }
        new_row.push_back(1);
        pascal_rows.push_back(new_row);
     }
     for(auto row : pascal_rows){
        for(auto num : row){
            cout << num << " ";
        }
        cout << endl;
     }
}


/**
 * Output
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
 */
int main(){
    print_pascal_triangle(8);
    return 0;
}