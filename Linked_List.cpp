//
//  Linked_List.cpp
//  Assignment 2, Template singly circular Linked List 
//
//  Created by Jiaying Wang on 1/22/16.
//  Copyright (c) 2016 Jay. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

template <typename T>
class chainNode{		//a node in a list of element T
public:
	chainNode<T>(){};
	chainNode<T>(const T& element){
		this->element = element;
	}
	chainNode<T>(const T& element, chainNode<T>* next){
		this->element = element;
		this->element = next;
	}

private:
	T element;			//element value
	chainNode<T>* next;	//next item in the list
						
	friend class chain;			// provides class chain access
	friend class linearList;	// provides class linearList access

};

template <typename T>
class linearList{

};


template <typename T>
class chain{

};

int main(int argc, char const *agrv[]){
	return EXIT_SUCCESS;
}
