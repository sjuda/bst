#include "stdafx.h"
#include <stdio.h>
#include "iostream"
#include "BSearchTree.h"
using namespace std;

int main()
{
	BinarySearchTree<int> a;
	//ROOT{
	a.Add(8);
	//}
	a.Add(7);
	a.Add(9);
	a.Add(4);
	a.Add(6);
	a.Add(10);
	a.Add(15);
	a.Add(11);

	cout << (a.Find(8) != NULL) << endl;
	cout << (a.Find(7) != NULL) << endl;
	cout << (a.Find(9) != NULL) << endl;
	cout << (a.Find(4) != NULL) << endl;
	cout << (a.Find(6) != NULL) << endl;
	cout << (a.Find(10) != NULL) << endl;
	cout << (a.Find(15) != NULL) << endl;
	cout << (a.Find(11) != NULL) << endl;
	cout << (a.Find(20) != NULL) << endl;
	cout << "Is BST " << isBST(a.GetTree()) << endl;
  return 0;
  }
