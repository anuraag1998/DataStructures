/*------------this programme is for binomial heap---------*/

#include <iostream>
#include <limits.h>

using namespace std;

struct node
{
	int key;
	struct node* parent;
	struct node* left_child;
	struct node* sibling;
	int degree;

}*head;

struct node* make_empty_heap()
{
	struct node* h = (struct node*)malloc(sizeof(struct node));
	return h;	
}

/*------linking the tree(headed x and y) of same order----------------*/
struct node* heap_link(struct node* x, struct node* y)
{
	x->parent = y;
	x->sibling = y->left_child;
	y->left_child = x;
	y->degree++;
	
return y;
}

/*--------merging the heap with headed x,y----------------*/
struct node* heap_merge(struct node* x, struct node* y)
{
	struct node*p;
	struct node* p_head;
	if(x== NULL)//---------------------case 1
		//-----------------if first is heap is empty
	{
		p = y;
		p_head = y;
		return p_head;
	}
	else if(y == NULL)//---------------case 2
		//----------------if second heap is empty
	{
		p = x;
		p_head = x;
		return p_head;
	}

	if(x != NULL && y!= NULL)//---------case 3
		//----------------if both are not empty
	{
		if(x->key < y->key)
        {
			p = x;
			x = x->sibling;
			p_head = p;
		}
        else if(y->key < x->key)
        {
        	p = y;
			y = y->sibling;
			p_head = p;
        }
	}

	//-------merge the heap according to degree of tree it has
	while(x != NULL && y != NULL)
	{
		if(x->key < y->key)
		{
			p->sibling = x;
			p = p->sibling;
			x = x->sibling;
		}
		else if(y->key < x->key)
		{
			p->sibling = y;
			p = p->sibling;
			y = y->sibling;
		}
	}
	
	if(x == NULL)
	{
		p->sibling = y;
	}
	else
	{
		p->sibling = x;
	}
	
	//--------return the head of list of result heap
	return p_head;
}

/*-----union of heap headed at a and b------------*/
//-----------returing the head of tree a and b
struct node* heap_union(struct node *a, struct node* b)
{
	struct node *head1 = heap_merge(a,b);

	//------------maintaining the three pointers
	struct node *x_prev,*x,*x_next;

	//--------if we have empty tree
	if(head1 == NULL)
		return NULL;
	x = head1;
	x_prev = NULL;
	x_next = x->sibling;

	
	while(x_next != NULL)
	{
		//---------------case 1 and 2 
		if((x->degree != x_next->degree) || (x_next->sibling != NULL && x_next->sibling->degree == x->degree))
		{
			x_prev = x;
			x = x_next;
			x_next = x_next->sibling;
		}
		//-------------case 3 and 4
		else
		{
			if(x->key <= x_next->key)
			{
				x->sibling = x_next->sibling;
				heap_link(x_next,x);
			}
			else
			{
				 if(x_prev == NULL)
	                	{
        	                	head1 = x_next;
                		}
    	       			else
        	        	{
                	        	x_prev->sibling = x_next;
                		}
				heap_link(x,x_next);
                                x = x_next;
                                head1 = x;
			}

		}
		x_next = x->sibling;
	}
		
	return head1;

}


/*-------------inserting in the heap----------*/
//----------head at t, inserting num
struct node* insert(struct node* t,int num)
{
	struct node* h;
	h = make_empty_heap();
	h->key = num;
	h->parent = NULL;
	h->left_child = NULL;
	h->sibling = NULL;
	h->degree = 0;
	t = heap_union(t,h);

	return t;
}


/*-------------function for finding the minimum element------*/
struct node* find_min(struct node* a)
{
	if(a!= NULL)
		return a;
	else
	{
		cout<<"the list is empty\n";
		return a;
	}
		
}


/*-------delesting minimum---------------------*/
//-----------------headed at t
struct node * delete_min(struct node *a)
{
	struct node* temp1,*temp2;
	temp1 = a;
	if(a == NULL)
	{
		cout<<"list is empty\n";
		return NULL;		
	}
	else
	{
		a = a->sibling;
		temp2 = temp1->left_child;			
	}

	

	struct node* current = temp2;
	struct node* prev = NULL;
	struct node* next = NULL;

	/*----------traversing the list to find minimum-------*/
	while(current != NULL)
	{
		current->parent = NULL;
		next = current->sibling;
		current->sibling = prev;
		prev = current;
		current = next;
		temp2 = prev;
	}
	/*---------------------------------------------------*/
	/*-----------unifying the heap----------*/
	a = heap_union(temp2,a);
	cout<<"minimum is deleted\n";
return a;	
}


int main()
{
	int cas,num;
	
	head = NULL;
	struct node*a;

	cout<<"cases are:\n1:insertion\n2:find_min\n3:delete min\n4:exit\n\n";
	
	do
	{
		cout<<"enter case: ";
		cin>>cas;
		switch(cas)	
		{
			case 1:
				cout<<"enter number to insert: ";
				cin>>num;
				head = insert(head,num);
				break;
			case 2:
				a = find_min(head);
				if(a != NULL)
				{
					cout<<"minimum number is: "<<a->key<<endl;
				}
				break;
			case 3:
				head = delete_min(head);
				break;
			case 4:
				exit(0);
			default:
				cout<<"you ave neter wrong choice\n";
							
		}
	
	}while(1);

	return 0;
}






