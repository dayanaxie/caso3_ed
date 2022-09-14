#include "Node.h"

#ifndef PRIORITYQUEUE

#define PRIORITYQUEUE 1

template <class T>
class PriorityQueue{
    private:
        Node<T> *first;
        Node<T> *last;
        int quantity;
        Node<T>*searchPosition;
    public:
        PriorityQueue(){
            first = NULL;
            last = NULL;
            searchPosition = NULL;
            quantity = 0;
        }

        Node<T>* getFirst(){
            return first;
        }

        bool isEmpty(){
            return !quantity;
        }

        int getSize(){
            return quantity;
        }

        void enqueue(T* pData, int pPriority = 0){
            Node<T>* newNode = new Node<T>(pData, pPriority);
            if(this->quantity > 0){
                if(pPriority < this->first->getPriority()){
                    this->first->setNext(newNode);
                    newNode->setBehind(newNode);
                    this->first = newNode;
                }
                else if(pPriority>= this->last->getPriority()){
                    newNode->setNext(last);
                    this->last->setBehind(newNode);
                    this->last = newNode;
                }
                else{
                    searchPosition = this->first->getBehind();
                    while(searchPosition != NULL){
                        if(searchPosition->getPriority() > pPriority){
                            newNode->setNext(searchPosition->getNext());
                            newNode->setBehind(searchPosition);
                            searchPosition->getNext()->setBehind(newNode);
                            searchPosition->setNext(newNode);
                        }
                        else{
                            searchPosition = searchPosition->getBehind();
                        }

                    }

                }
            }
            else{
                this->first = newNode;
                this->last = newNode;
            }
            this->quantity += 1;
        }
        T dequeue(){
            if(!this->isEmpty()){
                T* data = this->first->getData();
                if(this->first != this->last){
                    this->first = this->first->getBehind();
                    this->first->getNext()->setNext(NULL);
                }
                else{
                    this->first = NULL;
                    this->last = NULL;
                }
                this->quantity -= 1;
                return *data;
            }

            return T();
        }
};

#endif