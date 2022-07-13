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
		cout << "\n\t2.Them node vao Tree";
		cout << "\n\t3.In danh sach";
		cout << "\n\t4.Xep loai node";
		cout << "\n\t5.Xoa node";
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
			int sl;
			do
			{
				cout << "Nhap vao so luong so nguyen muon them: ";
				cin >> sl;
			} while (sl<0);
			for (size_t i = 0; i < sl; i++)
			{
				int x;
				cout << "Nhap vao gia tri thu " << i + 1 << " ma ban muon them: ";
				cin >> x;
				tree->ThemNode(x);
			}
			cout << " Done! ";
			system("pause");
			break;
		}
		case 3: {
			if (tree->getRoot()==NULL)
			{
				cout << " Cay dang rong! ";
			}
			else
			{
				tree->XuatNODERNL(tree->getRoot());
			}
			system("pause");
			break;
		}
		case 4: {
			if (tree->getRoot() == NULL)
			{
				cout << " Cay dang rong! ";
			}
			else
			{
				tree->XepLoaiNode(tree->getRoot());
			}
			system("pause");
			break;
		}
		case 5: {
			if (tree->getRoot() == NULL)
			{
				cout << " Cay dang rong! ";
			}
			else
			{
				int data;
				cout << "Nhap vao gia tri ma ban muon xoa: ";
				cin >> data;
				tree->XoaNode(tree->getRoot(),data);
				cout << " Xong ";
			}
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

