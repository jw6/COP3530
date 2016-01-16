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
        int j = i - 1;
        while(j >= 0 && insert < arr[j]){
            arr[j+1] = arr[j];
            j--;
            /*compare right to left*/
        }
        arr[j+1] = insert;
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
