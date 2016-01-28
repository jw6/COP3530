//
//  Linked_List.cpp
//  Assignment 2, Template singly circular Linked List 
//
//  Created by Jiaying Wang on 1/22/16.
//  Copyright (c) 2016 Jay. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class T>
struct chainNode 
{
   // data members
   T element;
   chainNode<T> *next;

   // methods
   chainNode() {}
   chainNode(const T& element){
 	  	this->element = element;
   }
   chainNode(const T& element, chainNode<T>* next){
      	this->element = element;
       	this->next = next;
   }
};						
	// friend class chain;			// provides class chain access
	// friend class linearList;	// provides class linearList access


template <class T>
class linearList{
   public:
      virtual ~linearList() {};

      virtual int size() const = 0;
                  // return number of elements in list
      virtual T& get(int theIndex) const = 0;
                  // return element whose index is theIndex
      virtual void insert(int theIndex, const T& theElement) = 0;
                  // insert theElement so that its index is theIndex
      virtual void output(ostream& out) const = 0;
                  // insert list into stream out
};


template<class T>
class chain : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
   	  chain(int initialCapacity = 10);
      chain(const chain<T>&);
      ~chain();

      // ADT methods
      int size() const {return listSize;}
      T& get(int theIndex) const;
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;

   protected:
   	      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      chainNode<T>* firstNode;  // pointer to first node in chain
      int listSize;             // number of elements in list
};

template<class T>
chain<T>::chain(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1)
   {
    cout << "Initial capacity = " << initialCapacity << " Must be > 0";
   }
   firstNode = NULL;
   listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{// Copy constructor.
   listSize = theList.listSize;

   if (listSize == 0)
   {// theList is empty
      firstNode = NULL;
      return;
   }

   // non-empty list
   chainNode<T>* sourceNode = theList.firstNode;
                    // node in theList to copy from
   firstNode = new chainNode<T>(sourceNode->element);
                    // copy first element of theList
   sourceNode = sourceNode->next;
   chainNode<T>* targetNode = firstNode;
                    // current last node in *this
   while (sourceNode != NULL)
   {// copy remaining elements
      targetNode->next = new chainNode<T>(sourceNode->element);
      targetNode = targetNode->next;
      sourceNode = sourceNode->next;
   }
   targetNode->next = NULL; // end the chain
}

template<class T>
chain<T>::~chain()
{// Chain destructor. Delete all nodes in chain.
   while (firstNode != NULL)
   {// delete firstNode
      chainNode<T>* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {
    cout << "index = " << theIndex << " size = " << listSize << endl;
   }

}

template<class T>
T& chain<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // move to desired node
   chainNode<T>* currentNode = firstNode;
   for (int i = 0; i < theIndex; i++)
      currentNode = currentNode->next;

   return currentNode->element;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      cout << "illegalIndex exception" << endl;
   }

   if (theIndex == 0)
      // insert at front
      firstNode = new chainNode<T>(theElement, firstNode);
   else
   {  // find predecessor of new element
      chainNode<T>* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;
   
      // insert after p
      p->next = new chainNode<T>(theElement, p->next);
   }
   listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const
{// Put the list into the stream out.
   for (chainNode<T>* currentNode = firstNode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
   {x.output(out); return out;}





int main(int argc, char const *agrv[])
{
   	chain<int> y;

   	int numOfElements;
  	cin >> numOfElements;

  	for(int i = 0; i < numOfElements; i++){
      int element;
      cin >> element;
      y.insert(i, element);
   	} cout<< "ok" << endl;

   // y.output(cout);

   	int additionnal_Linked_List;
   	cin >> additionnal_Linked_List;

    for(int i = 0; i < additionnal_Linked_List; i++)
     	{
        
         int stepCount, num_of_Additonal_Elem;
         
         cin >> stepCount;
         cin >> num_of_Additonal_Elem;

         chain<int>* k;
         k = new chain<int>;

         for(int i = 0; i < num_of_Additonal_Elem; i++)
         {
         
            int count = 0;

            for (int i = 0; i < num_of_Additonal_Elem; i++)
            {

               int element;
               cin >> element;
               k->insert(i, element);

               y.insert(count*2 + stepCount, k->get(i));
               count += stepCount;
            
            }cout<< "a" << endl;   

           cout << y << endl;
       

         }cout<< "b" << endl;  

         k = NULL;
         delete k;

      }cout<< "c" << endl;


   cout << y << endl;

   // y.output(cout);

   return 0;
}





































































