#include "double_linked_list.h"
#include <iostream>

void DoubleLinkedList::init()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty()
{
    return size == 0;
}

void DoubleLinkedList::add_front(char val)
{
    Node *node = new Node();
    node->data = (char)val;

    if (is_empty())
    {
        node->next = node->prev = node;
        head = tail = node;
    }
    else
    {
        node->next = head;
        node->prev = tail;
        head->prev = node;
        tail->next = node;
        head = node;
    }
    size++;
}

void DoubleLinkedList::add_back(char val)
{
    Node *node = new Node();
    node->data = (char)val;

    if (is_empty())
    {
        node->next = node->prev = node;
        head = tail = node;
    }
    else
    {
        node->next = head;
        node->prev = tail;
        tail->next = node;
        head->prev = node;
        tail = node;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx)
{
    if (idx <= 0)
    {
        add_front(val);
        return;
    }
    if (idx >= size)
    {
        add_back(val);
        return;
    }

    Node *curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;

    Node *node = new Node();
    node->data = (char)val;
    node->next = curr;
    node->prev = curr->prev;
    curr->prev->next = node;
    curr->prev = node;
    size++;
}

void DoubleLinkedList::delete_front()
{
    if (is_empty())
        return;


    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }
    size--;
}

void DoubleLinkedList::delete_back()
{
    if (is_empty())
        return;

    if (size == 1)
    {

        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        delete temp;
    }
    size--;
}

void DoubleLinkedList::delete_idx(int idx)
{
    if (is_empty())
        return;


    if (idx <= 0)
    {
        delete_front();
        return;
    }
    if (idx >= size - 1)
    {
        delete_back();
        return;
    }

    Node *curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    size--;
}

void DoubleLinkedList::display()
{
    if (is_empty())
        return;
    Node *curr = head;
    do
    {
        std::cout << curr->data;
        curr = curr->next;
    } while (curr != head);
    std::cout << "\n";
}

char DoubleLinkedList::get(int idx)
{
    if (is_empty())
        throw std::out_of_range("Index out of range");
    if (idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range");
    Node *curr = head;

    for (int i = 0; i < idx; i++)
        curr = curr->next;
    return curr->data;
}

void DoubleLinkedList::set(char val, int idx)
{
    if (is_empty() || idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range");
    Node *curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;
    curr->data = val;
}

void DoubleLinkedList::clear()
{
    if (is_empty())
        return;

    tail->next = nullptr;
    Node *curr = head;
    while (curr)
    {
        Node *next = curr->next;
        delete curr;
        curr = next;
    }
    head = tail = nullptr;
    size = 0;
}