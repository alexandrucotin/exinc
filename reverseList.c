#include <stdio.h>
#include <stdlib.h>

struct list
{
    int value;
    struct list *next;
};
struct list *head;

void createList()
{
    int data;
    struct list *temp = (struct list *)malloc(sizeof(struct list));
    printf("Inserisci elemento: ");
    scanf("%i", &data);
    temp->value = data;
    temp->next = head;
    head = temp;
}

void reverseList()
{
    struct list *prev, *current, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

void printList(struct list* p)
{
    if (p == NULL)
    {
        printf("\n");
        return;
    }
    printf(" %i", p->value);
    printList(p->next);
}

void reversePrint(struct list *p)
{
    if (p == NULL)
    {
        printf("\n");
        return;
    }
    reversePrint(p->next);
    printf(" %i", p->value);
}

int main(void)
{
    head = NULL;
    int i, numE, data;
    printf("Quanti elementi vuoi mettere nella lista?: ");
    scanf("%i", &numE);
    for (i = 0; i < numE; i++)
    {
        createList();
    }
    struct list* temp;
    temp = head;
    printList(temp);
    reverseList();
    printList(head);
    temp = head;
    printList(temp);
    reversePrint(temp);

    return 0;
}