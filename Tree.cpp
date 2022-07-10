#include"Tree.h"

NODE* Tree::KhoiTaoNode(int x){
	NODE* p = new NODE;
	p->x = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void Tree::ThemNode(int x)
{
	if (root == NULL)
	{
		NODE* p = KhoiTaoNode(x);
		root = p; return;
	}
	if (x > root->x)//lớn hơn qua phải
	{
		if (root->right != NULL)
		{
			ThemNode(root->right, x);
		}
		else
		{
			root->right = KhoiTaoNode(x);
		}
	}
	else
	{
		if (x < root->x) // nhỏ hơn qua trái
		{
			if (root->left != NULL)
			{
				ThemNode(root->left, x);
			}
			else
			{
				root->left = KhoiTaoNode(x);
			}
		}
	}
}

void Tree::ThemNode(NODE* p, int x)
{
	if (x > p->x)//lớn hơn qua phải
	{
		if (p->right != NULL)
		{
			ThemNode(p->right, x);
		}
		else
		{
			p->right = KhoiTaoNode(x);
		}
	}
	else
	{
		if (x < p->x) // nhỏ hơn qua trái
		{
			if (p->left != NULL)
			{
				ThemNode(p->left, x);
			}
			else
			{
				p->left = KhoiTaoNode(x);
			}
		}
	}
}

void Tree::XuatNODELNR(NODE* p)
{
	if (p != NULL)
	{
		cout << p->x << " ";
		XuatNODELNR(p->left);
		XuatNODELNR(p->right);
	}
}

void Tree::Xuat()
{
	if (root != NULL)
	{
		cout << root->x << " ";
		XuatNODELNR(root->left);
		XuatNODELNR(root->right);
	}
	else
	{
		cout << " Empty ";
	}
}

void Tree::XepLoaiNode(NODE* p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
		{
			cout << p->x << "(La) ";
		}
		else
		{
			if (p->left == NULL || p->right == NULL)
			{
				cout << p->x << "(1 Con) ";
			}
			else
			{
				cout << p->x << "(2 Con) ";
			}
		}
		XepLoaiNode(p->left);
		XepLoaiNode(p->right);
	}
}

void Tree::XepLoaiNode()
{
	if (root != NULL)
	{
		if (root->left == NULL && root->right == NULL)
		{
			cout << root->x << "(La) ";
		}
		else
		{
			if (root->left == NULL || root->right == NULL)
			{
				cout << root->x << "(1 Con) ";
			}
			else
			{
				cout << root->x << "(2 Con) ";
			}
		}
		XepLoaiNode(root->left);
		XepLoaiNode(root->right);
	}
	else
	{
		cout << " Empty ";
	}
}

void Tree::InputFromFile()
{
	ifstream filein("FileIn.txt");
	while (!filein.eof())
	{
		int x; filein >> x;
		ThemNode(x);
	}
	cout << " Xong! ";
}

NODE* Tree::XoaNode(NODE* root, int data)
{
	if (root == NULL) return NULL;
	if (data < root->x) root->left = XoaNode(root->left, data);
	else if (data > root->x) root->right = XoaNode(root->right, data);
	else {
		//case 1: no child
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//case 2: one child
		else if (root->left==NULL) // 1 child in the riht
		{
			NODE* temp = root;
			root = root->right;
			delete temp;
		}
		else if (root->right==NULL) //one child in the left
		{
			NODE* temp = root;
			root = root->left;
			delete temp;
		}
		else  //case 3: 2 child
		{

		}
		return root;
	}
}





