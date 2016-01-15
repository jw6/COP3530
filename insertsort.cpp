//
//  main.cpp
//  insectionSort
//
//  Created by Jay on 1/11/16.
//  Copyright (c) 2016 Jay. All rights reserved.
//

#include <iostream>

using namespace std;

void insertion_sort(int arr[], int size){
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
    int size; 
    cin >> size ;

    int nums[size];

    for(int i = 0; i < size; i++){
        cin >> nums[i];
    }

    
    insertion_sort(nums, size);

    cout << endl;
    for(int i = 0; i < size; i++){
        cout << nums[i] << endl;
    }
    
    return 0;
}
