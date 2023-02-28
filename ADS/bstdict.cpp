#include<iostream>
#include<string>

using namespace std;

class node
{
	private:
		string w,m;
		node *left = NULL;
		node *right = NULL;
		friend class tree;
	public:
		void accept();
		void display();
		void swap();
};

void node::accept()
{
	cout << "Word: ";
	cin >> w;
	cout << "Meaning: ";
	cin >> m;
}

void node::display()
{
	cout << "[" << w << ", " << m << "]";
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
		void search_nr();
		void del();
};

void tree::create()
{
	char ch='y';
	int flag;
	node *temp,*curr;
	root = new node;
	cout << "Enter data of root node:\n";
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
			if(curr->w < temp->w)
			{
				if(temp->left==NULL)
				{
					temp->left=curr;
					flag=0;
				}
				else
					temp = temp->left;
			}
			else if(curr->w > temp->w)
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
		temp->w = t->w;
        temp->m = t->m;
		temp->left = copy(t->left);
		temp->right = copy(t->right);
	}
	return temp;
}

void tree::search_nr()
{
	int f=1;
    string s;
	node *temp = root;

	cout << "Enter word to be searched: ";
	cin >> s;

	while(f)
	{
		if(temp==NULL) break;
		if(s==temp->w)
		{
			f=0;
			break;
		}

		else if(s < temp->w)
			temp = temp->left;
		else
			temp = temp->right;
	}
	if(!f)
		cout << "Found!\n";
	else if(f)
		cout << "Not Found\n";
}

void tree::del()
{
	int f=1;
    string s;
	node *temp = root,*par;

	cout << "Enter data to be deleted: ";
	cin >> s;

	while(f)
	{
		if(temp==NULL) break;
		if(s==temp->w)
		{
			f=0;
			break;
		}

		else if(s < temp->w)
		{
			par = temp;
			temp = temp->left;
		}
		else
		{
			par = temp;
			temp = temp->right;
		}
	}
	if(!f)
	{
		if(temp!=root)
		{
			int d;
			node *curr;

			if(temp->left==NULL && temp->right==NULL) d=1;
			else if((temp->left==NULL && temp->right!=NULL) || (temp->left!=NULL && temp->right==NULL)) d=2;
			else if(temp->left!=NULL && temp->right!=NULL) d=3;
			else d=4;

			switch (d)
			{
			case 1:// leaf node
				if(par->left==temp)
					par->left = NULL;
				else
					par->right = NULL;

				delete temp;
				cout << "Node Successfully Deleted";
				break;
			
			case 2://node with one child
				if(par->left==temp)
				{
					if(temp->left==NULL)
						par->left = temp->right;
					else
						par->left = temp->left;
				}
				else
				{
					if(temp->left==NULL)
						par->right = temp->right;
					else
						par->right = temp->left;
				}
				delete temp;
				cout << "Node Deleted Successfully";
				break;
			case 3:
				
				break;
			default:
				break;
			}	
		}
	}
	else
		cout << "Node not found";
}

int main()
{
	tree t1,t2;

	t1.create();
	cout << "Breadth First Display of First Tree: ";
	t1.bfs();
	cout << "\n";
	t1.del();
	cout << "\nBreadth First Display: ";
	t1.bfs();
	cout << "\n";
	
	return 0;
}