//
// Created by Biss on 3/09/2021.
//

#include "LinkedDouble.h"

template<class T>
T *getObject(int index);

template<class T>
LinkedDouble<T>::LinkedDouble() {
    head = NULL;
    last = NULL;
}

template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {
    Node<T>* newNode = new Node<T>(info);
    if ( isEmpty( ) ){
        head = newNode;
        last = newNode;
    }else{
        head->previous = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template<class T>
void LinkedDouble<T>::addNodeLast(T info) {
    Node<T>* newNode = new Node<T>(info);
    if ( isEmpty( ) ){
        head = newNode;
        last = newNode;
    }else{
        last->next = newNode;
        newNode->previous = last;
        last = newNode;
    }
}

template<class T>
std::vector<T> LinkedDouble<T>::getList(bool forward) {
    std::vector<T> out;
    Node<T>* aux = forward ? head : last;
    while( aux != NULL ){
        out.push_back( aux->info );
        aux = forward ? aux->next : aux->previous;
    }

    return out;
}

template<class T>
LinkedDouble<T>::~LinkedDouble() {

}

template<class T>
void LinkedDouble<T>::addNodeAfterTo(Node<T> *node, T info) {

    if (node == last)
    {
        addNodeLast(info);
    }
    else
    {
        Node<T>* newNode = new Node<T>(info);
        Node<T>* aux = last;
        while (aux->previous != node)
        {
            aux = aux->previous;
        }

        newNode->previous = aux->previous;
        newNode->next = aux;
        aux->previous = newNode;
        aux = aux->previous;
        aux = aux->previous;
        aux->next = newNode;

    }
}

template<class T>
void LinkedDouble<T>::addNodeBeforeTo(Node<T> *node, T info) {

    if (node == head)
    {
        addNodeFirst(info);
    }
    else
    {
        Node<T>* newNode = new Node<T>(info);
        Node<T>* aux = head;
        while (aux->next != node)
        {
            aux = aux->next;
        }

        newNode->next = aux->next;

        newNode->previous = aux;
        aux->next = newNode;
        aux = aux->next;
        aux = aux->next;
        aux->previous = newNode;

    }
}
template<class T>
Node<T> *LinkedDouble<T>::findNode(std::string ISBN) {
    Node<T>* aux = head;
    while (aux != NULL)
    {
        if (ISBN.compare(aux->info.getISBN())==0)
        {
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

template<class T>
T *LinkedDouble<T>::findInfo(std::string ISBN) {
    Node<T>* aux = head;
    while (aux != NULL)
    {
        if (ISBN.compare(aux->info.getISBN()) == 0)
        {
            return &aux->info;
        }
        aux = aux->next;
    }

    return NULL;
}

template<class T>
T LinkedDouble<T>::deleteNode(Node<T> *node) {
    T info = node->info;
    Node<T> *prev = NULL;


    if (node == head && node->next == NULL) {
        head = NULL;
        last = NULL;


    } else {

        if (node == head) {
            head = head->next;
            head->previous = NULL;

            //prev=head->next;
            //prev->previous=
        } else if (node == last) {
            last = last->previous;
            last->next = NULL;
        } else {
            Node<T> *aux = head;

            while (aux->next != node) {
                aux = aux->next;

            }
            aux->next = node->next;
            prev = node->next;
            prev->previous = aux;
        }
    }
    delete (node);
    return info;
}
template<class T>
void LinkedDouble<T>::addNodesorted(T info)
{
    Node<T>* newNode = new Node<T>(info);
    if (isEmpty())
    {
        head = newNode;
        last = newNode;
    }
    else
    {
        Node<T>* act = head;
        Node<T>* ant = NULL;
        while (act != NULL && info.getISBN().compare(act->info.getISBN()) > 0)
        {
            ant = act;
            act = act->next;
        }

        if (ant == NULL)
        {
            newNode->next = act;
            act->previous = newNode;
            head = newNode;
        }
        else if (ant == last)
        {
            ant->next = newNode;
            newNode->previous = ant;
            last = newNode;
        }
        else
        {
            newNode->next = act;
            ant->next = newNode;
            newNode->previous = ant;
            act->previous = newNode;
        }

    }
}
template<class T>
T * LinkedDouble <T>::getObject( int index) {

    Node<T> *aux = head;
    int i = 0;
    while (aux != NULL) {
        if (i == index) {
            return &aux->info;

        }
        aux = aux->next;
        i++;
    }

    return NULL;
}