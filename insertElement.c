#include <stdio.h>
#include <stdlib.h>

struct entry
{
    int value;
    struct entry *next;
};
struct entry *head;

void insertElement(int data, int n)
{
    struct entry *newElement = (struct entry *)malloc(sizeof(struct entry));
    struct entry *temp = head;
    newElement->value = data;
    if (n == 1)
    {
        newElement->next = head;
        head = newElement;
        return;
    }
    int i;
    for (i = 0; i < n -2; i++)
    {
        temp = temp->next;
    }
    newElement->next = temp->next;
    temp->next = newElement;
}

void createList()
{
    struct entry *temp = (struct entry *)malloc(sizeof(struct entry));
    printf("Inserisci valore: ");
    int value;
    scanf("%i", &value);
    temp->value = value;
    temp->next = head;
    head = temp;
}

void readList()
{
    struct entry *temp = head;
    printf("La lista e' : ");
    while (temp != NULL)
    {
        printf(" %d", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

int main(void)
{
    head = NULL; //empty list
    int lengthList, i;
    char scelta;
    printf("Di quanti elementi vuoi creare la tua lista: ");
    scanf("%i", &lengthList);

    for (i = 1; i <= lengthList; i++)
    {
        createList();
    };

    printf("Vuoi inserire un'altro elemento nella lista?: (s/n)");
    scanf(" %c", &scelta);

    readList();
    if (scelta == 's')
    {
        printf("In quale posizione vuoi mettere quello nuovo?: ");
        int afterElement;
        scanf("%i", &afterElement);
        printf("Inserisci il nuovo elemento: ");
        int newValue;
        scanf("%i", &newValue);
        insertElement(newValue, afterElement);
    }

    readList();

    return 0;
}