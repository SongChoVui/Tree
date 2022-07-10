/*BTVN:
1. Trình bày kết quả RNL

2. Xây dựng chức nâng xếp loại node

3. Xây dựng chức năng, xóa node(lá, 1 con, 2 con)
*/

// Bài 1:  25 22 19 18 17 15 10 5 4 -7 -10
#include"Tree.h"
void Menu() {
	Tree* tree = new Tree();
	int luachon;
	do
	{
		system("cls");
		cout << "\n\t1.Nhap danh sach so nguyen tu file";
		cout << "\n\t2.In danh sach";
		cout << "\n\t3.Xep loai node";
		cout << "\n\t4.Xoa node";
		cout << "\n\t0.Thoat";
		cout << "\nNhap vao lua chon cua ban: "; cin >> luachon;
		switch (luachon)
		{
		case 1: {
			tree->InputFromFile();
			system("pause");
			break;
		}
		case 2: {
			tree->Xuat();
			system("pause");
			break;
		}
		case 3: {
			tree->XepLoaiNode();
			system("pause");
			break;
		}
		case 0: {
			cout << "Thoat";
			delete tree;
			break;
		}
		default:
			break;
		}
	} while (luachon!=0);
}
void main() {
	Menu();
}

