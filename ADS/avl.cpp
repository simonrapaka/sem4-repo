#include<iostream>
#include<string.h>

#define COUNT 4

using namespace std;

class node
{
	char v[10];
	node *left = NULL, *right = NULL;

	public:
	friend class avl;
};

class avl
{
	node *rootm = NULL;

	public:
	node* ll(node*);
	node* lr(node*);
	node* rl(node*);
	node* rr(node*);
	int height(node*);
	node* insert(node*,char[],node*);
	void insert();
	void inorder();
	void inorder(node*);
	void print2d();
	void print2d(node*,int);
};

int avl::height(node *root)
{
	int t2=-1,t1=-1,h;

	if(root!=NULL)
	{
		t1 = height(root->left);
		t2 = height(root->right);
	}
	if(t1 > t2)
		h = t1;
	else
		h = t2;

	return h+1;
}

void avl::insert()
{
	char c='y';
	while(c=='y')
	{
		char d[10];
		cout << "\nEnter String(max 10): ";
		cin >> d;
		rootm = insert(rootm,d,NULL);
		cout << "Do you want to enter another node? ";
		cin >> c;
	}
}

node* avl::insert(node *root, char d[], node *p)
{
	if(root==NULL)
	{
		root = new node;
		strcpy(root->v,d);
		return root;
	}

	int bf;

	if(strcmp(d,root->v) < 0)
	{
		root->left = insert(root->left,d,rootm);
		bf = height(root->left) - height(root->right);
		cout << "Balance Factor: " << bf << "\n";

		if(bf==2 || bf==-2)
		{
			if(strcmp(d,root->left->v) < 0)
			{
				cout << "LL Rotation\n";
				if(p==NULL)
					root = ll(root);
				else
				{
					if(root==p->left) { root = ll(root); p->left = root;}
					else { root = ll(root); p->right = root;}
				}
			}

			if(strcmp(d,root->left->v) > 0)
			{
				cout << "LR Rotation\n";

				if(p==NULL)
					root = lr(root);
				else
				{
					if(root==p->left) { root = lr(root); p->left = root;}
					else { root = lr(root); p->right = root;}
				}
			}
		}
	}

	if(strcmp(d,root->v) > 0)
	{
		root->right = insert(root->right,d,rootm);
		bf = height(root->left) - height(root->right);
		cout << "Balance Factor: " << bf << "\n";

		if(bf==2 || bf==-2)
		{
			if(strcmp(d,root->right->v) < 0)
			{
				cout << "RL Rotation\n";

				if(p==NULL)
					root = rl(root);
				else
				{
					if(root==p->left) { root = rl(root); p->left = root;}
					else { root = rl(root); p->right = root;}
				}
			}

			if(strcmp(d,root->right->v) > 0)
			{
				cout << "RR Rotation\n";

				if(p==NULL)
					root = rr(root);
				else
				{
					if(root==p->left) { root = rr(root); p->left = root;}
					else { root = rr(root); p->right = root;}
				}
			}
		}
	}

	return root;
}

node* avl::ll(node* n)
{
	node *b;
	b = n->left;
	n->left = b->right;
	b->right = n;
	return b;
}

node* avl::lr(node *a)
{
	node *b,*c;
	b = a->left;
	c = b->right;
	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;
	return c;
}

node* avl::rl(node *a)
{
	node *b, *c;
	b = a->right;
	c = b->left;
	a->right = c->left;
	b->left = c->right;
	c->left = a;
	c->right = b;
	return c;
}

node* avl::rr(node *a)
{
	node *b;
	b = a->right;
	a->right = b->left;
	b->left = a;
	return b;
}

void avl::inorder()
{
	if(rootm==NULL) {cout << "ERROR: Tree Empty\n"; return;}
	else inorder(rootm);
}

void avl::inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->left);
		cout << temp->v << " ";
		inorder(temp->right);
	}
}

void avl::print2d()
{
	if(rootm==NULL) {cout << "ERROR: Tree Empty"; return;}
	print2d(rootm,0);
}

void avl::print2d(node *r, int space)
{
	if(r==NULL)
		return;

	space += COUNT;

	print2d(r->right,space);
	cout << "\n";

	for(int i=0;i < space; i++)
		cout << " ";
	cout << r->v;

	print2d(r->left,space);
}

int main()
{
	avl t1;

	t1.insert();
	cout << "Inorder: ";
	t1.inorder();
	cout << "\nTwo Dimensional Display:\n";
	t1.print2d();

	return 0;
}