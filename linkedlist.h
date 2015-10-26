#ifndef LINKEDLIST_
#define LINKEDLIST_
#include <iostream>

using namespace std;

template <typename DataType>
struct Node{
    Node* nextNode;
    Node* previousNode;
    DataType data;
    Node(DataType inputData);
};

template <typename DataType>
Node<DataType>::Node(DataType inputData){
    data = inputData;
    nextNode = 0;
    previousNode = 0;
}

template <typename DataType>
class LinkedListClass{
    
    private:
    Node<DataType>* head;
    Node<DataType>* tail;
    
    public:
    LinkedListClass(){
        head = 0;
        tail = 0;
    }
    ~LinkedListClass(){
        clearList();
    }
    
    void Prepend(DataType inputData){
        Node<DataType>* newNode = new Node<DataType>(inputData);
        if(head == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            Node<DataType>* tempNode = head;
            newNode->nextNode = head;
            head = newNode;
            tempNode->previousNode = head;
        }
    }
    
    void Append(DataType inputData){
        Node<DataType>* newNode = new Node<DataType>(inputData);
        if(tail == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            Node<DataType>* tempNode = tail;
            tail->nextNode = newNode;
            tail = newNode;
            tail->previousNode = tempNode;
        }
        
    }
    
    void DeleteNodeStructs(DataType inputData){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//if there are no nodes at all nothing to delete so just break;
                break;
            }
            if(currentNode->data.key == inputData.key){// this is the node you want to delete
                if(currentNode->previousNode == 0 && currentNode->nextNode == 0){
                    delete currentNode;
                    head = 0;
                    tail = 0;
                }
                else if(currentNode->previousNode == 0){//meaing ur deleteing the head
                    currentNode->nextNode->previousNode = 0;
                    head = currentNode->nextNode;
                    delete currentNode;
                    
                }
                else if(currentNode->nextNode == 0){//meaing ur deleteing the head
                    currentNode->previousNode->nextNode = 0;
                    tail = currentNode->previousNode;
                    delete currentNode;
                }
                else {
                    currentNode->previousNode->nextNode = currentNode->nextNode;
                    currentNode->nextNode->previousNode = currentNode->previousNode;
                    delete currentNode;
                }
                    
                return;
            }
            else if(currentNode == tail){//if it reached the end and there is no node to delete
                return;
            }
            currentNode = currentNode->nextNode; // increment to the next node in the list
        }
    }
    
    void DeleteNode(DataType inputData){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//if there are no nodes at all nothing to delete so just break;
                break;
            }
            if(currentNode->data == inputData){// this is the node you want to delete
                if(currentNode->previousNode == 0 && currentNode->nextNode == 0){
                    delete currentNode;
                    head = 0;
                    tail = 0;
                }
                else if(currentNode->previousNode == 0){//meaing ur deleteing the head
                    currentNode->nextNode->previousNode = 0;
                    delete currentNode;
                }
                else if(currentNode->nextNode == 0){//meaning ur deleting the tail
                    currentNode->previousNode->nextNode = 0;
                    delete currentNode;
                }
                else {
                    currentNode->previousNode->nextNode = currentNode->nextNode;
                    currentNode->nextNode->previousNode = currentNode->previousNode;
                    delete currentNode;
                }
                    
                break;
            }
            else if(currentNode == tail){//if it reached the end and there is no node to delete
                break;
            }
            currentNode = currentNode->nextNode; // increment to the next node in the list
        }
    }
    
    Node<DataType>* searchStructs(DataType inputData){ 
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//no nodes in the list
                return 0;
            }
            if(currentNode->data.key == inputData.key){//found the node, return true
                return currentNode;
            }
             else if(currentNode == tail){
                return 0;
            }
            
            currentNode = currentNode->nextNode;
        }
    }
    
     Node<DataType>* searchInts(DataType inputData){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//no nodes in the list
                return 0;
            }
            if(currentNode->data == inputData){//found the node, return true
                return currentNode;
            }
            else if(currentNode == tail){
                return 0;
            }
            
            
            currentNode = currentNode->nextNode;
        }
    }
    
    void clearList(){
        Node<DataType>* currentNode = head;
        while(true){
            if(currentNode == 0){//no nodes in the list, thus nothing to delete
                 break;
            }
            Node<DataType>* tempNode = currentNode;
            currentNode = currentNode->nextNode;
            if (currentNode != 0){
                delete tempNode; // gets rid of that node
            }
             //delete tempNode; // gets rid of that node
            
        }
    }
    
    int countNodes(){
        Node<DataType>* currentNode = head;
        int numNodes = 0;
        while(true){
            if(head == 0){//there are no nodes
                return 0;
            }
            numNodes += 1;
            if(currentNode->nextNode == 0){//no more nodes in the list
                 return numNodes;
            }
            currentNode = currentNode->nextNode;
            
        }
    }
    
    Node<DataType>* getHeadNode(){
        return head;
    }
    
};

#endif