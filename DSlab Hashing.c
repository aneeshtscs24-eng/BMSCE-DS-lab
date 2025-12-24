#include<stdio.h>
#include<stdlib.h>

int key[20], m, n;
int *ht, index;
int count = 0;

void insert(int key)
{
    index = key % m;
    while (ht[index] != -1)
        index = (index + 1) % m;

    ht[index] = key;
    count++;
}

void display()
{
    int i;
    if (count != 0)
    {
        printf("\nHash table contents are:\n");
        for (i = 0; i < m; i++)
            printf("\nT[%d] -> %d", i, ht[i]);
    }
    else
        printf("\nHash table is empty");
}

int main()
{
    int i;

    printf("\nEnter the number of employee records (n): ");
    scanf("%d", &n);

    printf("\nEnter the memory locations (m) for hash table: ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));

    for (i = 0; i < m; i++)
        ht[i] = -1;

    printf("\nEnter 4 digit values (k) for N employee records:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &key[i]);

    for (i = 0; i < n; i++)
    {
        if (count == m)
        {
            printf("\nHash table is full. Cannot insert record %d", i + 1);
            break;
        }
        insert(key[i]);
    }

    display();
    return 0;
}

