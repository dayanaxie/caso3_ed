#include <iostream>

#ifndef NODE 

#define NODE 1

using namespace std;

template <class T>
class Node {
    private:
        T* data;
        int priority;
        Node* next;
        Node* behind;
    
    public:
        Node() {
            priority = NULL;
            data = NULL;
            next = NULL;
            behind = NULL;
        }

        Node(T *pData, int pPriority) {
            this->data = pData;
            this->priority = pPriority;
            next = NULL;
            behind = NULL;
        }

        void setBehind(Node *pValue){
            this->behind = pValue;
        }

        Node* getBehind(){
            return behind;
        }

        int getPriority(){
            return priority;
        }

        T* getData() {
            return data;
        }

        Node* getNext() {
            return next;
        }

        void setNext(Node *pValue) {
            this->next = pValue;
        }
};

#endif
