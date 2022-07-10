#pragma once
#include"Config.h"

typedef struct node {
	int x;
	struct node* right;
	struct node* left;
}NODE;

class Tree // Binary search tree
{
public:
	Tree() { root = NULL; }
	Tree(int x) { root = KhoiTaoNode(x); }

	NODE* KhoiTaoNode(int x);

	void ThemNode(int x);
	void ThemNode(NODE* p, int x);

	void XuatNODELNR(NODE* p);
	void Xuat();

	void XepLoaiNode(NODE* p);
	void XepLoaiNode(); // xếp loại cho root, còn branch, leaf ở bên trên

	void InputFromFile();

	NODE* XoaNode(NODE* parent,int data);

	NODE* getRoot() { return root; };
private:
	NODE* root; //node lv0
};