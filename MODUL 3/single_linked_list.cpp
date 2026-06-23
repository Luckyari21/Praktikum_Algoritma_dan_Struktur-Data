#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty()
{
    return size == 0;
}

void SingleLinkedList::add_front(int val)
{
    Node *node = new Node();
    node->data = val;

    if (is_empty())
    {
        node->next = node;
        head = tail = node;
    }
    else
    {
        node->next = head;
        tail->next = node;
        head = node;
    }
    size++;
}

void SingleLinkedList::add_back(int val)
{
    Node *node = new Node();
    node->data = val;

    if (is_empty())
    {
        node->next = node;
        head = tail = node;
    }
    else
    {
        node->next = head;
        tail->next = node;
        tail = node;
    }
    size++;
}

void SingleLinkedList::add_idx(int val, int idx)
{
    if (idx < 0 || idx > size)
        throw std::out_of_range("Index out of range");

    if (idx == 0)
    {
        add_front(val);
        return;
    }
    if (idx == size)
    {
        add_back(val);
        return;
    }

    Node *curr = head;
    for (int i = 0; i < idx - 1; i++)
        curr = curr->next;

    Node *node = new Node();
    node->data = val;
    node->next = curr->next;
    curr->next = node;
    size++;
}

void SingleLinkedList::delete_front()
{
    if (is_empty())
        throw std::underflow_error("List Kosong");


    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }
    size--;
}

void SingleLinkedList::delete_back()
{
    if (is_empty())
        throw std::underflow_error("List Kosong");

    if (size == 1)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node *curr = head;
        while (curr->next != tail)
            curr = curr->next;

        delete tail;
        tail = curr;
        tail->next = head;
    }
    size--;
}

void SingleLinkedList::delete_idx(int idx)
{
    if (is_empty())
        throw std::underflow_error("List Kosong");

    if (idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range");

    if (idx == 0)
    {
        delete_front();
        return;
    }
    if (idx == size - 1)
    {
        delete_back();
        return;
    }


    Node *curr = head;
    for (int i = 0; i < idx - 1; i++)
        curr = curr->next;

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    size--;
}

void SingleLinkedList::display()
{
    if (is_empty())
        return;
    Node *curr = head;
    do
    {
        std::cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    std::cout << "\n";
}

int SingleLinkedList::get(int idx)
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

void SingleLinkedList::set(int val, int idx)
{
    if (is_empty() || idx < 0 || idx >= size)
        throw std::out_of_range("Index out of range");
    Node *curr = head;
    for (int i = 0; i < idx; i++)
        curr = curr->next;
    curr->data = val;
}

void SingleLinkedList::clear()
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