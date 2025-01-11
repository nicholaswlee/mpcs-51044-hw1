#include <vector>
#include <iostream>
#define FMT_HEADER_ONLY
#include <fmt/format.h>
using namespace fmt;

using namespace std;

// exercise 1.3 helper
string generate_empty_brick(int size){
    string brick = "";
    for(int i = 0; i < size; i++){
        brick += " ";
    }
    return brick;
}

// exercise 1.3 helper
string generate_padding(int brick_count, int brick_size){
    string padding = "";
    for(int i = 0; i < brick_count; i++){
        padding += generate_empty_brick(brick_size);
    }
    return padding;
}

// exercise 1.3
void print_brick_pascal_triangle(int n){
    vector<vector<int> > pascal_rows = {{1}};
    int maximum_brick_size = 1;
    for(int i = 1; i < n; i++){
        vector<int> new_row = {1};
        for(int j = 1; j < i; j++){
            new_row.push_back(pascal_rows.at(i - 1).at(j - 1) + pascal_rows.at(i - 1).at(j) );
            maximum_brick_size = max(maximum_brick_size, (int) to_string(new_row.back()).length());
        }
        new_row.push_back(1);
        pascal_rows.push_back(new_row);
     }
     maximum_brick_size = (maximum_brick_size % 2 == 0) ? maximum_brick_size + 1: maximum_brick_size;
     int brick_count = 2 * n - 1;
     for(int i = 0; i < n; i++){
        // print the padding 
        int padding_bricks = (brick_count - 1) / 2 - i;
        cout << generate_padding(padding_bricks, maximum_brick_size);
        vector<int> row = pascal_rows[i];
        // print first element so we can join
        cout << format("{:^{}}", row[0], maximum_brick_size); 
        for(int j = 1; j < row.size(); j++){
            cout << generate_empty_brick(maximum_brick_size);
            cout << format("{:^{}}", row[j], maximum_brick_size);
        }
        // print the padding
        cout << generate_padding(padding_bricks, maximum_brick_size) << endl;
     }
}
/* Output
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
 */
int main(){
    print_brick_pascal_triangle(8);
    return 0;
}