#include <iostream>
using namespace std;

struct node
{
    int value;
    struct node* next;
};

void push(node**, int);
int pop(node**);

void push(node** head, int num)
{
    if (*head == nullptr)
    {
        *head = new node();
        (*head)->value = num;
        (*head)->next = nullptr;
    }
    else
    {
        node* arr = *head;
        *head = new node();
        (*head)->value = num;
        (*head)->next = arr;
    }
}

int pop(node** head) // получить и убрать первый элемент
{
    int result = (*head)->value;
    node* arr = *head;
    *head = (*head)->next;
    delete arr;

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, num, count = 0;
    char comm;

    node* head;
    head = nullptr;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> comm;
        if (comm == '+')
        {
            cin >> num;
            push(&head, num);
        }
        else if (comm == '-')
        {
            cout << pop(&head) << "\n";

        }
    }
    return 0;
}