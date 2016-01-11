//
//  main.cpp
//  insectionSort
//
//  Created by Jay on 1/11/16.
//  Copyright (c) 2016 Jay. All rights reserved.
//

#include <iostream>

using namespace std;

void insection_sort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int insert = arr[i];
        int index = i - 1;
        while(index >= 0 && insert < arr[index]){
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1] = insert;
    }
}


int main(int argc, const char * argv[]) {
    int nums[] = {5,3,7,2,1,9,14,8,7,4,30,18,1,23,27};
    int size = sizeof(nums) / sizeof(int);
    //one int is 4 bytes.
    
    insection_sort(nums, size);
    
    for(int i = 0; i < size; i++){
        cout << nums[i] << " ";
    }
    
    return 0;
}
