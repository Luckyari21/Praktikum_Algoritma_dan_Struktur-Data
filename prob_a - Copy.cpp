#include "single_linked_list.h"
#include <iostream>

static void delete_after(SingleLinkedList &list, Node *prev_node)
{
    Node *target = prev_node->next;

    if (target == list.head)
        list.head = target->next;
    if (target == list.tail)
        list.tail = prev_node;

    prev_node->next = target->next;
    delete target;
    list.size--;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    const int k_init = k;

    SingleLinkedList list;
    list.init();
    for (int i = 0; i < n; i++)
    {
        int val;
        std::cin >> val;
        list.add_back(val);
    }

    Node *prev = list.tail;

    while (list.size > 1)
    {
        int steps = (k - 1) % list.size;
        for (int i = 0; i < steps; i++)
            prev = prev->next;

        int val = prev->next->data;

        delete_after(list, prev);

        if (val % 2 == 0)
            k++;
        else
            k--;

        if (k <= 0)
            k = k_init;
    }

    std::cout << list.head->data << "\n";

    list.clear();
    return 0;
}