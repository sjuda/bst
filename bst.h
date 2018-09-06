#pragma once
#define TEMPLATE template<typename T>

TEMPLATE struct Node
{
	Node*Parrent;
	Node*Left;
	Node*Right;
	T Value;
};

TEMPLATE class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	void Add(const T&);
	Node<T>*Find(const T&);
	void Remove(Node<T>*);
	Node<T>*GetTree() const {
		return Tree;
	}
private:
	Node<T>* Tree;
};

TEMPLATE BinarySearchTree<T>::BinarySearchTree()
{
	Tree = NULL;
}
TEMPLATE BinarySearchTree<T>::~BinarySearchTree()
{
	Remove(Tree);
}
TEMPLATE void BinarySearchTree<T>::Add(const T& Value)
{
	if (Find(Value) != NULL)
		return;
	if (Tree == NULL)
	{
		Tree = new Node<T>;
		Tree->Left = NULL;
		Tree->Right = NULL;
		Tree->Parrent = NULL;
		Tree->Value = Value;
		return;
	}
	Node<T>* Alloc = new Node<T>;
	Alloc->Left = NULL;
	Alloc->Right = NULL;
	Alloc->Value = Value;
	Node<T>* Temp = Tree;
	while (true)
	{
		if (Temp->Value > Value)
		{
			if (Temp->Left == NULL)
			{
				Temp->Left = Alloc;
				Alloc->Parrent = Temp;
				return;
			}
			Temp = Temp->Left;
			continue;
		}
		else
		{
			if (Temp->Right == NULL)
			{
				Temp->Right = Alloc;
				Alloc->Parrent = Temp;
				return;
			}
			Temp = Temp->Right;
			continue;
		}
	}
}

TEMPLATE Node<T>*BinarySearchTree<T>::Find(const T&Value)
{
	if (Tree == NULL)
		return NULL;
	Node<T>* Temp = Tree;
	while (Temp != NULL)
	{
		if (Temp->Value == Value)
			return Temp;
		if (Temp->Value > Value)
		{
			Temp = Temp->Left;
			continue;
		}
		else
		{
			Temp = Temp->Right;
			continue;
		}
	}
	return NULL;
}

TEMPLATE void BinarySearchTree<T>::Remove(Node<T>*node)
{
	if (node == NULL)
		return;
	if (node->Left != NULL)
		Remove(node->Left);
	if (node->Right != NULL)
		Remove(node->Right);
	if (node->Parrent == NULL)
	{
		delete[] Tree;
		Tree = NULL;
		return;
	}
	if (node->Parrent->Left == node)
	{
		node->Parrent->Left = NULL;
		delete[] node;
	}
	else if (node->Parrent->Right == node)
	{
		node->Parrent->Right = NULL;
		delete[] node;
	}
}

TEMPLATE bool isBST(Node<T>* root)
{
	if (root == NULL)
		return false;
	const T&Value = root->Value;
	if (root->Left == NULL && root->Right == NULL)
		return true;
	if (root->Left != NULL && root->Left->Value >= Value || root->Right!= NULL && root->Right->Value <= Value)
		return false;
	bool ILeft = true, IRigt = true;
	if (root->Left != NULL)
		ILeft = isBST(root->Left);
	if (root->Right != NULL)
		IRigt = isBST(root->Right);
	return ILeft && IRigt;
}
