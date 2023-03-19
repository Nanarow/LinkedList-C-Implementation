#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char value;
    struct node *next;
} Node;

Node *head = NULL;
Node *tail = NULL;
int size = 0;

void append(char);
void insert(char);
void insertAfterHead(char);
void insertBeforeTail(char);
void insertThirdFromTail(char);
void deleteNode(char);
void deleteLinkedList();
void searchNode(char);
void display();

void input(char *);
void menu();

int main(void)
{
    menu();
    return 0;
}

void append(char c)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = c;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        tail->next = newNode;
    }

    tail = newNode;
    size++;
}

void insert(char c)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = c;

    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void insertAfterHead(char c)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = c;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    else if (head == tail)
    {
        newNode->next = NULL;
        head->next = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head->next;
        head->next = newNode;
    }
    size++;
}

void insertBeforeTail(char c)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = c;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    else if (size == 1)
    {
        newNode->next = head;
        tail = head;
        head = newNode;
    }
    else if (size == 2)
    {
        newNode->next = tail;
        head->next = newNode;
    }
    else
    {
        newNode->next = tail;
        Node *prevNode = head;
        while (1)
        {
            if (prevNode->next == tail)
            {
                prevNode->next = newNode;
                break;
            }
            prevNode = prevNode->next;
        }
    }
    size++;
}
void insertThirdFromTail(char c)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->value = c;

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        tail->next = NULL;
    }
    else if (size == 1)
    {
        newNode->next = head;
        tail = head;
        head = newNode;
    }
    else if (size == 2)
    {
        newNode->next = tail;
        head->next = newNode;
    }
    else
    {
        Node *prevNode = head;
        while (1)
        {
            if (prevNode->next->next == tail)
            {
                newNode->next = prevNode->next;
                prevNode->next = newNode;
                break;
            }
            prevNode = prevNode->next;
        }
    }
    size++;
}

void deleteNode(char c)
{
    Node *prevNode;
    Node *delNode = head;

    if (head->value == c)
    {
        head = head->next;
    }
    else
    {
        while (delNode != NULL && delNode->value != c)
        {
            prevNode = delNode;
            delNode = delNode->next;
        }
        if (delNode != NULL && delNode->value == c)
        {
            if (tail->value == c)
            {
                tail = prevNode;
            }
            prevNode->next = delNode->next;
            delNode->next = NULL;
        }
    }

    if (delNode != NULL && delNode->value == c)
    {
        size--;
        free(delNode);
    }
    else
    {
        printf("'%c' is not in linkedList\n", c);
    }
}

void deleteLinkedList()
{
    Node *delNode;
    while (size > 0)
    {
        delNode = head;
        head = head->next;
        free(delNode);
        size--;
    }
}

void searchNode(char c)
{
    Node *current = head;
    int index = 0;
    while (current != NULL && current->value != c)
    {
        current = current->next;
        index++;
    }
    if (current != NULL && current->value == c)
    {
        printf("Found %c at ", current->value);
        printf("index %d\n", index);
    }
    else
    {
        printf("'%c' is not in LinkedList\n", c);
    }
}

void display()
{
    Node *current = head;
    if (current == NULL)
    {
        printf("LinkedList : [ Null ], Size: %d \n", size);
        return;
    }
    printf("LinkedList : [ ");
    while (current != NULL)
    {
        if (current->next == NULL)
        {
            printf("%c ], Size: %d \n", current->value, size);
            break;
        }
        else
        {
            printf("%c --> ", current->value);
        }
        current = current->next;
    }
}

void input(char *arg)
{
    printf("input : ");
    scanf(" %c", arg);
    printf("\n");
}
void menu()
{
    int choice;
    char c;
    int exit = 1;
    while (exit)
    {
        printf("\n(1) append\n");
        printf("(2) insert\n");
        printf("(3) insertAfterHead\n");
        printf("(4) insertBeforeTail\n");
        printf("(5) deleteNode\n");
        printf("(6) deleteLinkedList\n");
        printf("(7) searchNode\n");
        printf("(8) display\n");
        printf("(9) exit\n");
        printf("select menu : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input(&c);
            append(c);
            printf("Append '%c' in linkedlist\n", c);
            display();
            break;
        case 2:
            input(&c);
            insert(c);
            printf("Insert '%c' in linkedlist.\n", c);
            display();
            break;
        case 3:
            input(&c);
            insertAfterHead(c);
            printf("Insert '%c' afterhead in linkedlist.\n", c);
            display();
            break;
        case 4:
            input(&c);
            insertBeforeTail(c);
            printf("Insert '%c' beforetail in linkedlist.\n", c);
            display();
            break;
        case 5:
            input(&c);
            deleteNode(c);
            printf("Delete '%c' from linkedlist.\n", c);
            display();
            break;
        case 6:
            deleteLinkedList();
            printf("Delete linkedlist.\n");
            display();
            break;
        case 7:
            input(&c);
            printf("Search '%c' in linkedlist.\n", c);
            searchNode(c);
            break;
        case 8:
            printf("Display linkedlist.\n");
            display();
            break;
        case 9:
            exit = 0;
            break;
        }
    }
}
