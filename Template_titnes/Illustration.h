#pragma
#include <iostream>
#include "Node.h"
using namespace std;
template<class t>

class LinkedList
{
private:
    Node<t>* lift;
    Node<t>* right;
    int length;
public:

    LinkedList()
    {
        lift = right = NULL;
        length = 0;
    }

    Node<t>* begin()
    {
        return lift;
    }

    Node<t>* end()
    {
        return right;
    }

    Node<t>* prevece(Node<t>* current)
    {
        if (current != nullptr)
            return current->prevece;
        else
            return nullptr;
    }

    Node<t>* next(Node<t>* current)
    {
        if (current != nullptr)
            return current->next;
        else
            return nullptr;
    }

    void insertLift(t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (length == 0)
        {
            lift = right = newNode;
            newNode->next = newNode->prevece = NULL;
        }
        else
        {
            newNode->next = lift;
            newNode->prevece = NULL;
            lift->prevece = newNode;
            lift = newNode;
        }
        length++;
    }
    void insertRight(t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (length == 0)
        {
            lift = right = newNode;
            newNode->next = newNode->prevece = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prevece = right;
            right->next = newNode;
            right = newNode;
        }
        length++;
    }
    void insertAtPosition(int position, t element)
    {
        Node<t>* newNode = new Node<t>;
        newNode->item = element;
        if (position == 0)
        {
            insertLift(element);
        }
        else if (position == length)
        {
            insertRight(element);
        }
        else
        {
            Node<t>* current = lift;
            for (int i = 1; i < position; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            newNode->prevece = current;
            current->next->prevece = newNode;
            current->next = newNode;
            length++;
        }

    }
    void removeLift()
    {
        if (length == 0)
        {
            cout << "Linked List is Empty can`t remove element" << endl;
        }
        else
        {
            Node<t>* current = lift;
            lift = lift->next;
            lift->prevece = NULL;
            current->next = current->prevece = NULL;
            delete current;
            length--;
        }
    }

    void removeRight()
    {
        if (length == 0)
        {
            cout << "Linked List is Empty can`t remove element" << endl;
        }
        else
        {
            Node<t>* current = right;
            right = right->prevece;
            right->next = NULL;
            current->next = current->prevece = NULL;
            delete current;
            length--;
        }
    }

    void removeAtPosition(int position)
    {
        if (position == 0)
        {
            removeLift();
        }
        else if (position == length - 1)
        {
            removeRight();
        }
        else
        {
            Node<t>* current = lift;
            for (int i = 0; i < position; i++)
            {
                current = current->next;
            }
            current->next->prevece = current->prevece;
            current->prevece->next = current->next;
            current->next = current->prevece = NULL;
            delete current;
            length--;
        }
    }

    int search(t element)
    {
        Node<t>* current = lift;
        for (int i = 0; i < length; i++)
        {
            if (current->item == element)
            {
                return i;
            }
            current = current->next;

        }
        return -1;
    }

    void sortList()
    {
        Node<t>* prevece = lift;
        Node<t>* current = NULL;
        while (prevece != NULL)
        {
            current = prevece->next;
            while (current != NULL)
            {
                if (prevece->item > current->item)
                {
                    swap(prevece->item, current->item);
                }
                current = current->next;
            }
            prevece = prevece->next;
        }

    }

    void reverse()
    {
        if (lift == NULL)
        {
            cout << "Linked List is Empty " << endl;
        }
        else
        {
            Node<t>* prevece = lift;
            Node<t>* current = lift->next;
            Node<t>* next = current->next;
            while (current != NULL)
            {
                if (prevece->prevece == NULL)
                {
                    prevece->prevece = current;
                    prevece->next = NULL;
                    right = prevece;
                }
                current->next = prevece;
                current->prevece = next;
                prevece = current;
                current = next;
                if (next != NULL)
                {
                    next = next->next;
                }
            }
            lift = prevece;
        }
    }
    void print()
    {
        Node<t>* temp = lift;
        cout << "[";
        while (temp != NULL)
        {
            cout << temp->item << " ";
            temp = temp->next;
        }
        cout << "]" << endl;
    }
};