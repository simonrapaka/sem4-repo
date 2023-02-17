#include<iostream>

using namespace std;

class node
{
	private:
		int d;
		node *left=NULL;
		node *right=NULL;
		friend class tree;
	public:
		void accept();
		void display();
};

void node::accept()
{
	cout << "Enter data: ";
	cin >> d;
}

void node::display()
{
	cout << d << " ";
}

class tree
{
	node *root;
	public:
		tree()
		{
			root = NULL;
		}
		void create_nr();
		void inorder_r();
		void inorder_r(node *temp);
};

void tree::create_nr()
{
	char ch1,ch2='y';

	if(root==NULL)
		root = new node;

	node *temp = root;
	int flag;

	cout << "Enter data of root node: ";
	cin >> root->d;
	cout << "Do you want to add another node?(y/n) ";
	cin >> ch2;

	while(ch2=='y')
	{
		temp = root;
		flag = 0;
		while(flag==0)
		{
			cout << "Left or Right?(l/r): ";
			cin >> ch1;
			if(ch1=='l')
			{
				if(temp->left==NULL)
				{
					node *curr = new node;
					curr->accept();
					temp->left = curr;
					temp = temp->left;
					flag=1;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if(ch1=='r')
			{
				if(temp->right==NULL)
				{
					node *curr = new node;
					curr->accept();
					temp->right = curr;
					temp = temp->right;
					flag=1;
				}
				else
				{
					temp = temp->right;
				}
			}
			else break;
		}
		cout << "Do you want to add another node?(y/n) ";
		cin >> ch2;
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

int main()
{
	tree bt;
	bt.create_nr();
	cout << "\nInorder Traversal of the tree: ";
	bt.inorder_r();
	cout << endl;
	return 0;
}