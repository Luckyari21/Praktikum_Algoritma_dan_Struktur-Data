#include "double_linked_list.h"
#include <iostream>

static void delete_node(DoubleLinkedList &list, Node *node)
{
    if (list.size == 1)
    {
        list.head = list.tail = nullptr;
        delete node;
        list.size = 0;
        return;
    }
    if (node == list.head)
        list.head = node->next;
    if (node == list.tail)
        list.tail = node->prev;
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
    list.size--;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, R;
    std::cin >> N >> R;

    DoubleLinkedList list;
    list.init();

    for (int i = 0; i < N; i++)
    {
        char c;
        std::cin >> c;
        list.add_back (c);
    }

    Node *alpha = list.head;
    Node *beta = list.tail;

    for (int r = 0; r < R; r++)
    {
        long long X, Y;
        std::cin >> X >> Y;

        if (list.size == 0)
            continue;

        long long x_steps = X % (long long)list.size;
        long long y_steps = Y % (long long)list.size;

        for (long long i = 0; i < x_steps; i++)
            alpha = alpha->next;
        for (long long i = 0; i < y_steps; i++)
            beta = beta->prev;

        if (alpha == beta)
        {
            Node *next_a = alpha->next;
            Node *prev_b = alpha->prev;
            delete_node(list, alpha);

            if (list.size == 0)
            {
                alpha = beta = nullptr;
            }
            else
            {
                alpha = next_a;
                beta = prev_b;
            }
        }
        else if (alpha->next == beta || beta->next == alpha)
        {
            char tmp = alpha->data;
            alpha->data = beta->data;
            beta->data = tmp;
        }
    }

    if (list.is_empty())
    {
        std::cout << "EMPTY\n";
    }
    else
    {
        list.display();
    }

    list.clear();
    return 0;
}