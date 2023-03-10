#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	
};struct node *head;

int choice,num=1,true=1;

void insert();
void display();
void main()
{
	printf("\n***** Treasure Hunt *****\n");
	printf("\nTo find treasure number\n");
	printf("\nClue 1: The number is even prime\n");
	printf("\nGuess the number:");
	scanf("%d",&choice);
	while(true)
	{
		switch(choice)
		{
			case 1:printf("\nThe guess number is correct\n");
				   insert();break;
			case 2:printf("\nThe guess number is correct\n");
				   insert();break;
			case 123:printf("\nThe guess number is correct\n");
				   insert();break;
			case 55:display();break;
			case 999:printf("\nThe guess number is correct\n");
				   insert();break;
			case 2345:printf("\nYou won the game\n");
					  exit(0);
			default:printf("\nGuessing number is incorrect\n");
			        num=num-1;
			        choice=55;
					break;
		}
	}
}
void insert()
{
	struct node *ptr,*temp;
	int item;
	ptr = (struct node *)malloc(sizeof(struct node));
	if(ptr==NULL)
	printf("\nOverflow");
	else
	{
		item=choice;
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			choice=55;
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			ptr->next=NULL;
			temp->next=ptr;
			choice=55;
		}
	}
}
void display()
{
	if(num==0)
	{
		printf("\nClue 1: The number is even prime\n");
		printf("\nGuess the number:");
		scanf("%d",&choice);
		num++;
	}
	else if(num==1)
	{
		printf("\n\nClue-2: The number is neither prime nor composite\n");
		printf("\nGuess the number:");
		scanf("%d",&choice);
		num++;
	}
	else if(num==2)
	{
		printf("\n\nClue-3: The number is first three digits\n");
		printf("\nGuess the number:");
		scanf("%d",&choice);
		num++;
	}
	else if(num==3)
	{
		printf("\n\nClue-4: The number is the last three digit number\n");
		printf("\nGuess the number:");
		scanf("%d",&choice);
		num++;
	}
	else if(num==4)
	{
		struct node *temp;
		temp=head;
		printf("\nTreasure hunt follows as:\n\n");
		while(temp!=NULL)
		{
			printf("-->%d",temp->data);
			temp=temp->next;
		}
		choice=2345;
	}
}
/*OUTPUT:
***** Treasure Hunt *****

To find treasure number

Clue 1: The number is even prime

Guess the number:345

Guessing number is incorrect

Clue 1: The number is even prime

Guess the number:1

The guess number is correct


Clue-2: The number is neither prime nor composite

Guess the number:1

The guess number is correct


Clue-3: The number is first three digits

Guess the number:123

The guess number is correct


Clue-4: The number is the last three digit number

Guess the number:789

Guessing number is incorrect


Clue-4: The number is the last three digit number

Guess the number:890

Guessing number is incorrect


Clue-4: The number is the last three digit number

Guess the number:999

The guess number is correct

Treasure hunt follows as:

-->1-->1-->123-->999
You won the game
*/
