#include <stdio.h>
#include <sstream>
#include <iostream>
#include <algorithm>
int main(){

    std::string line;
    std::getline(std::cin, line); // read a line of integers from standard input

    std::istringstream iss(line);

    int each;
    int nums[30010];
    int size=0;
    while (iss >> each) {
        nums[size++] = each; // parse the integers and store them in a vector
    }
    
    int rightmost=0;
    for(int i=0;i<size;i++){
        if (i <= rightmost) {
            rightmost = std::max(rightmost, i + nums[i]);
            if (rightmost >= size - 1) {
                printf("true");
                return 0;
            }
        }
    }
    printf("false");

    return 0;
}