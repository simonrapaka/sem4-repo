#include<iostream>

using namespace std;

class node
{
	private:
		int d;
		node *left;
		node *right;
		friend class tree;
	public:
		void accept();
		void display();
		void swap();
};

void node::accept()
{
	cin >> d;
}

void node::display()
{
	cout << d << " ";
}

void node::swap()
{
	node *temp;
	temp = left;
	left = right;
	right = temp;
}

class queue
{
	private:
	node *q[30];
	int f,r;
	public:
	queue()
	{
		f = r = -1;
	}
	void insert(node *e);
	node *del();
	int isnotempty();
};

void queue::insert(node *e)
{
	q[++r] = e;
}

node *queue::del()
{
	return q[++f];
}

int queue::isnotempty()
{
	if(f!=r) return 1;
	else return 0;
}

class tree
{
	node *root;
	public:
		tree()
		{
			root = NULL;
		}
		void create();
		void inorder_r();
		void inorder_r(node *temp);
		void bfs();
		void mirror();
		void copy(tree t);
		node *copy(node *t);
};

void tree::create()
{
	char ch='y';
	int flag;
	node *temp,*curr;
	root = new node;
	cout << "Enter data of root node: ";
	root->accept();
	cout << "Do you want to enter another node?(y/n) ";
	cin >> ch;
	while(ch=='y')
	{
		temp = root;
		flag=1;
		curr = new node;
		cout << "Enter data: ";
		curr->accept();
		while(flag)
		{
			if(curr->d < temp->d)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					flag=0;
				}
				else
					temp = temp->left;
			}
			else if(curr->d > temp->d)
			{
				if(temp->right==NULL)
				{
					temp->right = curr;
					flag=0;
				}
				else
					temp = temp->right;
			}
		}
		cout << "Do you want to enter another node?(y/n) ";
		cin >> ch;
	}
}

void tree::inorder_r()
{
	inorder_r(root);
}

void tree::inorder_r(node *temp)
{
	if(temp!=NULL)
	{
		inorder_r(temp->left);
		temp->display();
		inorder_r(temp->right);
	}
}

void tree::bfs()
{
	queue q1;
	node *temp;
	temp = root;

	q1.insert(temp);

	while(q1.isnotempty())
	{
		temp = q1.del();
		temp->display();
		if(temp->left!=NULL)
			q1.insert(temp->left);
		if(temp->right!=NULL)
			q1.insert(temp->right);
	}
}

void tree::mirror()
{
	queue q1;
	node *temp;
	temp = root;

	q1.insert(temp);

	while(q1.isnotempty())
	{
		temp = q1.del();
		temp->swap();
		if(temp->left!=NULL)
			q1.insert(temp->left);
		if(temp->right!=NULL)
			q1.insert(temp->right);
	}
}

void tree::copy(tree t)
{
	root = copy(t.root);
}

node *tree::copy(node *t)
{
	node *temp=NULL;

	if(t!=NULL)
	{
		temp = new node;
		temp->d = t->d;
		temp->left = copy(t->left);
		temp->right = copy(t->right);
	}
	return temp;
}

int main()
{
	tree t1,t2;

	t1.create();
	cout << "Breadth First Display of First Tree: ";
	t1.bfs();
	cout << "\n";
	t1.mirror();
	cout << "First Tree Mirrored: ";
	t1.bfs();
	cout << "\n";
	t2.copy(t1);
	cout << "Copying First Tree into Second Tree...\n";
	cout << "Breadth First Display of Second Tree: ";
	t2.bfs();
	cout << "\n";
	
	return 0;
}
