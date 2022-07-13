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
	Tree() { TRoot = NULL; }
	Tree(int x) { TRoot = KhoiTaoNode(x); }

	NODE* KhoiTaoNode(int x);

	void ThemNode(NODE* p, int x);

	void XuatNODELNR(NODE* p); // xuất theo LNR
	void XuatNODERNL(NODE* p); // xuất theo RNL

	void XepLoaiNode(NODE* p);

	void InputFromFile();

	NODE* XoaNode(NODE* parent,int data);

	NODE* getRoot() { return TRoot; };
private:
	NODE* TRoot; //node lv0
};