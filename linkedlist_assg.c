/******************************************************************************
 *
 * File Name: linkedlist_assg.c
 *
 * Description: File contains all functions based on the linkledlist assginment in Standard Diploma
 * each Task has its own Functionality and description individually
 * and the user which functionality he wants to use
 *
 * Author: Yahia Hamimi
 ******************************************************************************/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linkedlist_assg.h"

struct node
{
	int data;
	struct node *next;
};
struct node *head = NULL;
struct node *current = NULL;
struct node *prev = NULL;

/**
 * prints the linked list
 *
 * start from the head and print each node's data until the last node
 * when the last node is reached, print [null]
 */
void printList(void)
{
	struct node *ptr = head;

	printf("[head] =>");

	// start looping from the head until the last node
	while (ptr != NULL)
	{
		printf(" %d =>", ptr->data);
		ptr = ptr->next;
	}

	printf(" [null]\n");
}
/**
 * Delete the entire linked list
 *
 * loops through the linked list and frees each node one at a time
 * until the entire list is deleted
 */
void deleteList()
{
	struct node *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;

		free(temp);
	}

	printf("SUCCESSFULLY DELETED ALL NODES OF LINKED LIST\n");
}

/**
 * Inserts a node at the end of the linked list
 *
 * creates a new node and assigns the given data to it
 * traverses the linked list until the last node is reached
 * assigns the new node to the last node's next pointer
 */
void Insertatlast(int data)
{
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->data = data;
	link->next = NULL;
	if (head == NULL)
	{
		head = link;
		return;
	}
	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = link;
}

/**
 * Returns the size of the linked list
 *
 * starts from the head and traverses the list by incrementing a counter
 * until the last node is reached
 * returns the counter value as the size of the linked list
 *
 * @return -1 if the list is empty, otherwise returns the size of the list
 */
int sizeOfList(void)
{
	int size = 0;

	// check if the linked list is empty
	if (head == NULL)
	{
		printf("List size : %d ", size);
		return -1;
	}

	current = head;
	size = 1;
	while (current->next != NULL)
	{
		current = current->next;
		size++;
	}
	return size;
}
/**
 * Inserts a new node at any given position in the linked list
 *
 * if the position is 0, the new node is inserted at the beginning of the list
 * if the position is greater than the size of the list, an error message is displayed
 * if the position is valid, the new node is inserted at the specified position
 * in the list
 *
 * @param data the data to be stored in the new node
 * @param position the position where the new node is to be inserted
 */
void InsertatanyPosition(int data, int position)
{
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->data = data;
	int pos = 0;
	if (head == NULL)
	{
		head = link;
		return;
	}
	if (position > sizeOfList())
	{
		printf("the given position %d exceeds the list size\n", position);
		return;
	}
	if (position == 0)
	{
		link->next = head;
		head = link;
		return;
	}
	current = head;
	prev = head;
	while (pos < position)
	{
		prev = current;
		current = current->next;
		pos++;
	}
	prev->next = link;
	link->next = current;
	prev = link;
}
/**
 * returns the middle data of the linked list
 *
 * calculates the size of the linked list
 * if the list is empty, 0 is returned
 * if the list has only one node, the data of the only node is returned
 * if the list has two nodes, the data of the first node is returned
 * if the list has an odd size, the data of the middle node is returned
 * if the list has an even size, the data of the node before the middle node is returned
 *
 * @return the data of the middle node
 */
int MiddleDataSearch(void)
{
	int size = sizeOfList();
	if (head == NULL)
	{
		return 0;
	}
	prev = head;
	current = head;
	if (head->next == NULL)
	{
		return head->data;
	}
	if (head->next->next == NULL)
	{
		return head->data;
	}
	// that's a solution using the previous size function
	if (size % 2 == 0)
	{
		while (current->next != NULL)
		{
			current = current->next->next;
			if (current->next->next == NULL)
				current = current->next;
			prev = prev->next;
		}
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next->next;
			prev = prev->next;
		}
	}
	return prev->data;
	// another solution if we don't have the size function
	/*
	int step;
	while(current->next != NULL)
		{
			current = current->next;
			step++;
			if(step == 2)
			{
				prev = prev->next;
				step = 0;
			}
		}
		return prev->data;
	}*/
}

/**
 * returns the 5th element from the end of the linked list
 *
 * starts from the head and traverses the list by incrementing a counter
 * until the last node is reached
 * returns the 5th element from the end of the linked list as the result
 *
 * @return the 5th element from the end of the linked list
 */
int fifthElmentFromEnd(void)
{
	// check if the list is empty
	struct node *ptr = head;

	if (head == NULL)
	{
		printf("Empty Linked List \n");
		return 0;
	}
	// check if the list has only one node
	if (head->next == NULL)
	{
		return head->data;
	}
	// check if the array size is greater than or equal 5
	if (sizeOfList() >= 5)
	{

		printf("%p", head);
		while (ptr->next->next->next->next->next != NULL)
		{
			// increment step by step until reached the 5th element from the end
			ptr = ptr->next;
		}
		printf("%d", ptr->data);
		return ptr->data;
	}
	else
	{
		printf("Linked List Size is smaller than 5\n");
		return 0;
	}
}
/**
 * Returns the sum of all the elements in the linked list
 *
 * starts from the head and traverses the list by adding each node's data
 * to a running sum
 * returns the sum of all the elements in the linked list
 *
 * @return the sum of all the elements in the linked list
 */
int listsum(void)
{
	if (head == NULL)
	{
		printf("Empty Linked List \n");
		return 0;
	}

	int sum = 0;
	struct node *ptr = head;

	while (ptr != NULL)
	{
		sum += ptr->data;
		ptr = ptr->next;
	}

	return sum;
}

/**
 * Returns the maximum of all the elements in the linked list
 *
 * starts from the head and traverses the list by comparing each node's data
 * with a running maximum value
 * returns the maximum of all the elements in the linked list
 *
 * @return the maximum of all the elements in the linked list
 */
int Maxlist(void)
{
	if (head == NULL)
	{
		printf("Empty Linked List \n");
		return 0;
	}
	struct node *ptr1 = head;

	int max = head->data;
	ptr1 = ptr1->next; // start check from the second node
	while (ptr1 != NULL)
	{

		if (ptr1->data > max)
			max = ptr1->data;
		ptr1 = ptr1->next;
	}

	return max;
}

int main(void)
{
	/* Set the stdout and stderr to unbuffered mode to solve printf() and scanf() problems */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int task;
	printf("Enter the specific task to operate:\n");
	scanf("%d", &task);
	/* switch case for different tasks to be operated on */
	switch (task)
	{
	case 1:
	{
		Insertatlast(11);
		Insertatlast(15);
		Insertatlast(100);
		Insertatlast(17);
		Insertatlast(20);
		Insertatlast(30);
		int data_entry, pos;
		printf("Enter the data and positon to insert:");
		scanf("%d %d", &data_entry, &pos);
		InsertatanyPosition(data_entry, pos);
		printList();
		deleteList();
		break;
	}
	case 2:
	{
		Insertatlast(11);
		Insertatlast(15);
		Insertatlast(100);
		Insertatlast(17);
		Insertatlast(20);
		Insertatlast(30);
		printList();
		int result = MiddleDataSearch();
		if (result == 0)
			printf("Empty Linked List \n");
		printf("The middle data is:%d\n", result);
		deleteList();
		break;
	}
	case 3:
	{
		Insertatlast(11);
		Insertatlast(15);
		Insertatlast(20);
		Insertatlast(100);
		Insertatlast(17);
		Insertatlast(20);
		Insertatlast(30);
		printList();
		printf("size list is %d", sizeOfList());
		printf("The fifth element from end is:%d\n", fifthElmentFromEnd());
		deleteList();
		break;
	}
	case 4:
	{
		Insertatlast(11);
		Insertatlast(15);
		Insertatlast(20);
		Insertatlast(100);
		Insertatlast(105);
		Insertatlast(17);
		Insertatlast(20);
		Insertatlast(30);
		printList();
		printf("the max is:%d", Maxlist());
		deleteList();

		// deleteList();
		break;
	}
	case 5:
	{
		// int sum=0;
		Insertatlast(11);
		Insertatlast(15);
		Insertatlast(20);
		Insertatlast(100);
		Insertatlast(105);
		Insertatlast(17);
		Insertatlast(20);
		Insertatlast(30);
		// sumList(&sum);
		printf("the maximum element is:%d", listsum());
		deleteList();
		break;
	}
	default:
		printf("You have entered an invalid task number\n");
	}
}
