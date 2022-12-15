/*
 * CS:2630
 * Author: Paul Johnson
 * hawkid: pjohnson16
 */

#include <stdio.h>
#include <stdlib.h>
#include "hw1b.h"

/*
 * Malloc space for a Node structure and set its element field to number
 * then return a pointer to the newly created node.
 */
Node *createNode(int number)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->element = number;
    newNode->next = NULL;

    return newNode;
}

/* Free all memory allocated for node */
void destroyNode(Node *node)
{
    if (!node)
    {
        free(&node);
    }
}

/*
 * If list is initally NULL, return node.
 * Otherwise, add node to the end of list by setting the next field of the last
 * Node structure in list to node.  Then return a pointer to the list.
 */
Node *appendList(Node *list, Node *node)
{
    // Checks if the pointer reference is null.
    if (!list)
    {
        return node;
    }
    else
    {
        Node *head = list;
        // Forces the linked list to iterate to the last element.
        Node *current = list;
        // This will terminate with current = the last item.
        while (current->next != NULL)
        {
            current = current->next;
        }

        // Will always be referencing the last node.
        current->next = node;

        return head;
    }
}

/*
 * Build and return a linked list such that each integer in array is
 * stored in the element field of a newly created node of the linked list.
 */
Node *createList(int array[], int cnt)
{
    Node *head = NULL;
    Node *current = NULL;
    /*
        Loop through the array and add a new node to the next value of the
        last item of the linked list.
    */
    for (int i = 0; i < cnt; i++)
    {
        if (current == NULL)
        {
            // Creates the current node.
            current = createNode(array[i]);
            head = current;
        }
        else
        {
            Node *newNode = createNode(array[i]);

            // Set the current.next to the new node.
            current->next = newNode;
            // Traverse to the next node.
            current = current->next;
        }
    }

    return head;
}

/* Free all memory allocated for the nodes in list */
void destroyList(Node *list)
{
    /*
        Idea is to get the next pointer before destroying the current node
        and to do this until all the nodes are destroyed.

        For loop won't work as we'd have to have the length and it doesn't
        need to be found.
    */

    Node *current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }
}

/* Return the length of list */
int listLength(Node *list)
{
    int cnt = 0;

    Node *current = list;

    while (current->next != NULL)
    {
        current = current->next;

        cnt++;
    }

    return cnt;
}

/* Return the max of the element values in list */
int maxElement(Node *list)
{
    Node *current = list;
    int max = list->element;

    while (current->next != NULL)
    {
        current = current->next;

        if (current->element > max)
        {
            max = current->element;
        }
    }

    return max;
}

/* Return the min of the element values in list */
int minElement(Node *list)
{
    Node *current = list;
    int min = list->element;

    while (current->next != NULL)
    {
        current = current->next;

        if (current->element < min)
        {
            min = current->element;
        }
    }

    return min;
}

/* Return the sum of the element values in list */
int sumElements(Node *list)
{
    Node *current = list;
    int sum = 0;

    while (current->next != NULL)
    {
        sum += current->element;
        current = current->next;
    }

    return sum;
}

/* Return a list wherein the values of list are in increasing order. */
Node *sortListIncreasingOrder(Node *list)
{
    return list;
}

/* Return a list wherein the values of list are in decreasing order. */
Node *sortListDecreasingOrder(Node *list)
{
    return list;
}

/* Return the median value of the elements in list.
 * If the lenght of the list is odd, then the median is the middle
 * element of the sorted list.
 * if the length of the list is even, then the median is the average
 * of the two middle values.
 */
int medianElement(Node *list)
{
    return 1;
}