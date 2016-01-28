//
//  Linked_List.cpp
//  Assignment 2, Template singly circular Linked List 
//
//  Created by Jiaying Wang on 1/28/16.
//  Copyright (c) 2016 Jay. All rights reserved.
//


#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef int dataType;

struct node{
	dataType data;
	node *next;
};

class linker{
public:
	linker();	//constructor
	~linker();	//destructor

	void create(); //create a linker
	bool insert(int theIndex, dataType x);	
	int getLength();
	void print();	//print linker

private:
	node *head;	//linker head pointer
};

linker::linker(){
	head = NULL;
}

linker::~linker(){
	node *ptrNode = head;
	node *ptrNodeTemp = NULL;

	while(ptrNode != NULL){
		ptrNodeTemp = ptrNode->next;
		delete ptrNode;
		ptrNode =ptrNodeTemp;
	}
}

void linker::create(){
	node *ptrNode = new node;
	ptrNode->data = 0;
	head = ptrNode;

	// bool flag = true;
	bool flagNum = true;
	dataType data = 0;
	// int x = 0;

	int number;
	cin >> number;

	for(int i = 0; i < number; i++){
		cin >> data;

		if(!flagNum){
			node *temp = new node;
			ptrNode->next = temp;
			ptrNode = temp;
		}
		ptrNode->data = data;
		flagNum = false;
	}
	ptrNode->next = NULL;


	if(head->data == 0){
		head = NULL;
		delete ptrNode;
	}
}

int linker::getLength(){
	int number = 0;
	node *ptrNode = head;

	while(ptrNode!=NULL){
		number++;
		ptrNode = ptrNode->next;
	}

	return number;
}

// int linker::getLength(){
// 	int number = 100;
// 	return number;
// }

bool linker::insert(int position, dataType number){
	if(position < 0 || position > getLength())
		return false;

	node *ptrNodeAhead = head;
	node *ptrNodeNext = NULL;
	int temp = 0;

	while(1){
		if(temp++ == position){
			break;
		}

		ptrNodeNext = ptrNodeAhead;
		ptrNodeAhead = ptrNodeAhead->next;
	}

	node *ptrTempNode = new node;
	ptrTempNode->data = number;

	if(ptrNodeAhead == head){
		ptrTempNode->next = head;
		head = ptrTempNode;
	}

	else{
		ptrNodeNext->next = ptrTempNode;
		ptrTempNode->next = ptrNodeAhead;
	}

	return true;


}


void linker::print(){
	node *ptrNode = head;

	while(ptrNode != NULL){
		cout << ptrNode->data << " ";
		ptrNode = ptrNode->next;
	}
	cout << endl;
}

int main(int argc, char const* argv[]){
	linker x;
	int addition, steps, number,item;
	x.create();
	
	cin>>addition;

	for(int i = 0; i < addition; i++){
		cin>>steps>>number;
		int count = 0;
		for(int j = 0; j < number;j++){
			cin>>item;

			if(j == 0) x.insert(count*2+steps,item);
			else
				x.insert(2*steps+1,item);
		}
	}
	x.print();

}