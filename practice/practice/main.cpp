//
//  main.cpp
//  practice
//
//  Created by Jay on 1/16/16.
//  Copyright (c) 2016 Jay. All rights reserved.
//

#include <iostream>
using namespace std;

void functionC(int a[], int size, int target){
    int i,j;
    i = 0;
    j = size - 1;
    
    while(i < j){
        if(a[i] + a[j] == target){
            cout << a[i] << " " << a[j];
            break;
        }
    
        else if (a[i] + a[j] > target)
            j--;
        else
            i++;
    }
}
int main(int argc, const char * argv[]) {
    int a[] = {1,5,6,7,8,9};
    int b = sizeof(a)/ sizeof(int);
    int c = 9;

    functionC(a,b,c);

    
    return EXIT_SUCCESS;
}
