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
	if (TRoot == NULL)
	{
		NODE* p = KhoiTaoNode(x);
		TRoot = p; return;
	}
	ThemNode(TRoot, x);
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

void Tree::XuatNODERNL(NODE* p)
{
	if (p!=NULL)
	{
		XuatNODERNL(p->right);
		cout << p->x<<" ";
		XuatNODERNL(p->left);
	}
}


void Tree::XepLoaiNode(NODE* p)
{
	if (p != NULL)
	{
		if (p->left == NULL && p->right == NULL)
		{
			cout << "Node la: " << p->x << endl;
		}
		else
		{
			if (p->left == NULL || p->right == NULL)
			{
				cout <<"Node 1 con: " << p->x << endl;
			}
			else
			{
				cout <<"Node 2 con: " << p->x << endl;
			}
		}
		XepLoaiNode(p->left);
		XepLoaiNode(p->right);
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

NODE* TimMin(NODE* p) { //tìm giá trị nhỏ nhất bên phải
	if (p->left==NULL)
	{
		return p;
	}
	else
	{
		TimMin(p->left);
	}
}
//trái cùng cây con phải
//phải cùng cây con trái

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
			NODE* temp = TimMin(root->right);//trái cùng cây con phải
			root->x = temp->x;
			root->right = XoaNode(root->right,temp->x);// lặp lại việc xóa temp
		}
	}
	return root;
}

	



