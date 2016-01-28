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
    
    void create(int &x); //create a linker
    // bool insert();
    //insert data
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

void linker::create(int &numOfElement){
    node *ptrNode = new node;
    ptrNode->data = 0;
    head = ptrNode;
    
    
    bool flagNum = true;
    dataType data = 0;
    
    // for(int x = numOfElement; x >= 0; x--){
    while(numOfElement >= 0){
        
        if(numOfElement == 0){
            ptrNode->next = NULL;
            --numOfElement;
        }
        else{
            cin >> data;
            
            ptrNode->data = data;
            flagNum = false;
            
            if(!flagNum){ //keep create slot
                node *temp = new node;
                ptrNode->next = temp;
                ptrNode = temp;
            }
            
            --numOfElement;
        }
        
    }
    
    if(head->data == 0){
        head = NULL;
        delete ptrNode;
    }
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
    int numOfElement;
    x.create(numOfElement);
    
    x.print();
    
 
}