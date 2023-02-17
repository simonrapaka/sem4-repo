#include<stdio.h>
#include<stdlib.h>

struct polynode
{
	int coeff,exp;
	struct polynode *next;
};

void create(struct polynode *head)
{
	struct polynode *temp = head,*curr;
	char c='y';

	while(c=='y')
	{
		curr = (struct polynode *)malloc(sizeof(struct polynode));
		printf("Enter coefficient: ");
		scanf("%d", &curr->coeff);
		printf("Enter exponent: ");
		scanf("%d", &curr->exp);

		curr->next = head;
		temp->next = curr;
		temp = curr;
		printf("Do you want to add another term(y/n): ");
		scanf(" %c", &c);
	}
}

void display(struct polynode *head)
{
	struct polynode *curr;

	curr = head->next;

	while(curr != head)
	{
		printf("%dx^%d", curr->coeff, curr->exp);
		
		curr = curr->next;

		if(curr != head)
			printf(" + ");
	}
	printf("\n");
}

void add(struct polynode *head1, struct polynode *head2, struct polynode *head3)
{
	struct polynode *curr1, *curr2, *curr3, *tempa = head3;

	curr1 = head1->next;
	curr2 = head2->next;


	while (curr1!=head1 && curr2!=head2)
	{
		if(curr1->exp==curr2->exp)
		{
			curr3 = (struct polynode *)malloc(sizeof(struct polynode));
			curr3->coeff = curr1->coeff + curr2->coeff;
			curr3->exp = curr1->exp;
			curr3->next = head3;
			tempa->next = curr3;
			tempa = curr3;
			curr1 = curr1->next;
			curr2 = curr2->next;
		}
		else if(curr1->exp < curr2->exp)
		{
			curr3 = (struct polynode *)malloc(sizeof(struct polynode));
			curr3->coeff = curr2->coeff;
			curr3->exp = curr2->exp;
			curr3->next = head3;
			tempa->next = curr3;
			tempa = curr3;
			curr2 = curr2->next;

		}
		else if(curr1->exp > curr2->exp)
		{
			curr3 = (struct polynode *)malloc(sizeof(struct polynode));
			curr3->coeff = curr1->coeff;
			curr3->exp = curr1->exp;
			curr3->next = head3;
			tempa->next = curr3;
			tempa = curr3;
			curr1 = curr1->next;
		}
	}
	
	if(curr1!=head1)
	{
		tempa = (struct polynode *)malloc(sizeof(struct polynode));
		while (curr1!=head1)
		{
			curr3->coeff = curr1->coeff;
			curr3->exp = curr1->exp;
			curr3->next = head3;
			tempa->next = curr3;
			tempa = curr3;
			curr1 = curr1->next;
		}
		
	}
	else if(curr2!=head2)
	{
		tempa = (struct polynode *)malloc(sizeof(struct polynode));
		while (curr2!=head2)
		{
			curr3->coeff = curr2->coeff;
			curr3->exp = curr2->exp;
			curr3->next = head3;
			tempa->next = curr3;
			tempa = curr3;
			curr2 = curr2->next;
		}
	}

}

int main()
{
	struct polynode *head1, *head2, *head3;

	head1 = (struct polynode *)malloc(sizeof(struct polynode));
	head1->next = head1;

	head2 = (struct polynode *)malloc(sizeof(struct polynode));
	head2->next = head2;

	printf("Enter the contents of the first polynomial\n\n");
	create(head1);
	printf("\n");
	display(head1);

	printf("\nEnter the contents of the second polynomial\n\n");
	create(head2);
	printf("\n");
	display(head2);

	head3 = (struct polynode *)malloc(sizeof(struct polynode));
	head3->next = head3;

	add(head1,head2,head3);

	printf("\n\n");
	printf("The sum of the entered polynomials is: \n");
	display(head1);
	display(head2);
	printf("---------------------------\n");
	display(head3);

	return 0;
}