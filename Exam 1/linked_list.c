#include "linked_list.h"

//create a node with value v
node * create_node(int v) 
{
    node	* p = malloc(sizeof(node)); // Allocate memory
    assert(p != NULL);		// you can be nicer
    
    // Set the value in the node. 
    p->v = v;		
    p->next = NULL;  
    return p;			// return
}

//TODO:
void insert(node **head, node *newnode)
{
    if((*head) == NULL) //if there is no list already
    {
		//fill in code below
		newnode = head; //the new node becomes the head

    }
    node *p = (*head); //points to the head
	node *q = p; //points to the value at the head
	while(p->next != NULL && newnode->v > p->v) //while the value of the next node != NULL, 
												//and the value of the new node is greater than the head
	{
		//fill in code below
		node *p = malloc(sizeof(node)); //allocate the memory for the node
	}
	if(newnode->v > p->v) //if the new node is bigger than the head node
	{
		// fill in code below
		p->next = newnode->v; //put the new node after the head

	}
	//fill in code below
	//node *q = p->next; //now the "head" moves to the next node to keep inserting

	return;
}

//add newnode the last of the linked list determined by *head and *tail
//note **head, **tail
void insert_last(node **head, node **tail, node *newnode)
{
	if((*head) == NULL)
	{
		(*head) = (*tail) = newnode;
	}
	else
	{
		(*tail)->next = newnode;
		(*tail) = newnode;
	}
}

//remove the first node from the list
//note **head
//return a pointer to the removed content

node * remove_first(node **head) 
{
        node *p;

        p = (*head);
        if((*head)!=NULL) (*head) = (*head)->next;
        return p;
}

//print the list pointed by head
void print_list(node *head)
{
	node *p = head;

	while(p!=NULL)
	{
		printf("%d ", p->v);
		p = p->next;
	}
	printf("\n");
}

//TODO
//merge two sorted linked list as one
node * merge(node **p1, node **p2)
{
	node *head = NULL, *tail = NULL; //no head or tail right now
	node *q1 = (*p1), *q2 = (*p2), *p; //both point to the head of their respective linked list
									   //I'm assuming *p points to the current node?
							

	if(q1 == NULL && q2 == NULL) return NULL; //no linked lists to be merged
	if(q1 != NULL && q2 == NULL) //if there is only linked list 1...
	{
		p = q1; //the value p points to is equal to the head of the first linked list
		(*p1) = NULL; //this points to nothing
		return p; //you return the head of the linked list
	}
	if(q1 == NULL && q2 != NULL) //if there is only linked list 2...
	{
		//same ordeal as the last if statement
		p = q2;
		(*p2) = NULL;
		return p;
	}

	while(q1 != NULL && q2!= NULL) //there are 2 linked lists to merge
	{
		//fill in code below
		if(q1->v < q2->v) //compare to see which current value is smaller
						  //we want ascending order
		{
			p = q1->v; //p is assigned the current value of linked list 1
			p->next = q1->next; //p goes to the next value
		}
		else
		{
			p = q2->v; //p is assigned to the current of linked list 2
			p->next = q2->next; //p goes to the next value
		}

	}
	while(q1 != NULL) //get rid of linked list 1
	{
		//fill in code below
		node *temp = q1; //temporary value we'll get rid of later
		q1 = q1->next; //move to the next value (I feel this should be a pointer but idk what I'm doing)
	  //*q1 = q1->next; (I wanted to write that but it wouldn't compile and I CANNOT lose anymore points)
		temp->v = NULL; //get rid of the value
		free(temp->v); //free the node now that it is gone 
	}
	while(q2 != NULL) //get rid of linked list 2
	{	
		//fill in code below
		node *temp = q2; //value to get rid of later
		q2 = q2->next; //move to the next value (Again, should be a pointer, but idk)
		temp->v = NULL; //get rid of the value
		free(temp->v); //free the node now that it is gone
	
	}
	//fill in code below
	//head should point to the head of the merged linked list
	p = head;
	return 	head;
}
int main(int argc, char *argv[])
{
	assert(argc == 2);
	int n = atoi(argv[1]);
	
	int a[n];
	int b[n];
	
	for(int i = 0; i < n; i++)
	{
		a[i] = i;
		b[i] = 2*i;
	}

	node *p1 = NULL, *p2 = NULL;

	for(int i = 0; i < n; i++)
	{
		node *p = create_node(a[i]);
 		insert(&p1, p);
	}
	print_list(p1);

	for(int i = 0; i < n; i++)
    {
        node *p = create_node(b[i]);
        insert(&p2, p);
    }
	print_list(p2);
	
	node *p = merge(&p1, &p2);
	print_list(p);
	printf("%p\n", p1);
	printf("%p\n", p2);

	//TODO
	//fill in code below
	printf("I'm switching to business");
	

	return 0;
}
