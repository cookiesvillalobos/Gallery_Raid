//
// Created by viviana on 03/06/19.
//

#ifndef GenericLinkedList_H
#define GenericLinkedList_H


#include <iostream>
#include "GenericNode.h"

/**
 * Class use for storing any type of object
 * @tparam T
 */
template <class T>
class GenericLinkedList{
public:
    GenericLinkedList();
    void add(T);
    void remove(int);
    GenericNode<T>* get(int);
    GenericNode<T>* getHead();
    int* getLength();
    bool includes(T);
    void deleteEndNode();
    GenericNode<T>* getLast();
private:
    GenericNode<T>* header;
    GenericNode<T>* last;
    int length;
};

/**
 * This constructor doesn't take any parameters
 * @tparam T
 */
template <class T>
GenericLinkedList<T>::GenericLinkedList() {
    this->length = 0;
    this->header = nullptr;
    this->last = nullptr;
}

/**
 * This  function creates a node with the data and sets it as a head
 * @tparam T
 * @param data
 */
template<class T>
void GenericLinkedList<T>::add(T data) {
    GenericNode<T>* temp = new GenericNode<T>(data);
    if(this->length == 0){
        this->header = temp;
    }else{
        if(this->last == nullptr){
            this->header->setNext(temp);
            this->last = temp;
        }else{
            this->last->setNext(temp);
            this->last = temp;
        }
    }
    this->length++;
    //std::cout << "Added " << data << " to the list" << std::endl;
}

/**
 * This function returns the node in index i
 * @tparam T
 * @param i
 * @return GenericNode<T>
 */
template <class T>
GenericNode<T>* GenericLinkedList<T>::get(int i) {
    if(this->length == 0){
        return nullptr;
    }
    GenericNode<T>* temp = this->header;
    for(int j = 0; j < i; j++){
        temp = temp->getNext();
    }
    return temp;
}

/**
 * This function removes the node on index i
 * @tparam T
 * @param i
 */
template <class T>
void GenericLinkedList<T>::remove(int i) {
    if(this->length == 1){
        this->header = nullptr;
    }else{
        GenericNode<T>* temp = get(i);
        if(temp == header){
            this->header = this->header->getNext();
        }else {
            if (temp->getNext() != nullptr) {
                this->get(i - 1)->setNext(temp->getNext());
            } else {
                this->get(i - 1)->setNext(nullptr);
            }
        }
    }
    this->length--;
}

/**
 * This function returns the head of the linkedlist
 * @tparam T
 * @return GenericNode<T>
 */
template<class T>
GenericNode<T> *GenericLinkedList<T>::getHead() {
    return this->header;
}

/**
 * This function returns the length of the linkedlist
 * @tparam T
 * @return
 */
template <class T>
int* GenericLinkedList<T>::getLength() {
    /*int i = 0;
    GenericNode<T>* temp = this->get(0);
    while(temp != nullptr){
        i++;
        temp = temp->getNext();
    }
    this->length = i;*/
    return &this->length;
}

template<class T>
bool GenericLinkedList<T>::includes(T data) {
    for(int i = 0; i < this->length; i++){
        if(data == get(i)->getData()){
            return true;
        }
    }return false;
}


template<class T>
void GenericLinkedList<T>::deleteEndNode(){
    GenericNode<T>*ptr;
    GenericNode<T>*prev;
    if ( header== nullptr)
        std::cout << "The list is empty, cant delete nack node.\n";
    else {
        ptr = header;
        while (ptr->getNext() != nullptr) {
            prev = ptr;
            ptr = ptr->getNext();
        }
        prev->setNext(nullptr);
        //delete(ptr);
    }
    this->length--;
}

template<class T>
GenericNode<T> *GenericLinkedList<T>::getLast() {
    return this->last;
}


#endif //GenericLinkedList_H
