#pragma once

#include<iostream>
#include<stack>
#include<iomanip>
#include<fstream>
using namespace std;
template<typename T>
class binnode {

public:

	T data;

	binnode*left;

	binnode*right;

	int  height;

};

template<class T>

class AVL
{
public:
	AVL();
	
	~AVL();

	void init_insert();

	void remove(binnode<T>*&ptr, const T &item);

	void insert( binnode<T> *& ptr, const T &item);

	int getheight(binnode<T>*p);

	binnode<T>* LL(binnode<T>*ptr);//×óµ¥Ðý

	binnode<T>*RR(binnode<T>*ptr);
    
	binnode<T>*RL(binnode<T>*ptr);

	binnode<T>* LR(binnode<T>*ptr);
	//×óÓÒË«Ðý
	
	void graph(ostream&out)const;
	

	binnode<T>*head;

	bool search(const T&item);

private:

	void release(binnode<T>*ptr);
	
	void graphaux(ostream & out, int indent, binnode<T>*subtree)const;
};
template <typename T>
void AVL<T>::remove(binnode<T>*&ptr, const T &item) {

	if (ptr == NULL) {
		return;
	}
	else {

		if (item < ptr->data) {


			remove(ptr->left, item);

			if (getheight(ptr->right) - getheight(ptr->left) > 1) {

				if (getheight(ptr->right->left) > getheight(ptr->right->left)) {
					ptr = RL(ptr);

				}
				else {
					ptr = RR(ptr);
				}
			}
			else {

				ptr->height = getheight(ptr->left) > getheight(ptr->right) ? getheight(ptr->left) + 1 : getheight(ptr->right) + 1;
			}


		}
		else if (item > ptr->data) {
			remove(ptr->right, item);

			if (getheight(ptr->left) - getheight(ptr->right) > 1) {

				if (getheight(ptr->left->right) > getheight(ptr->left->left)) {

					ptr = LR(ptr);
				}
				else {
					ptr = LL(ptr);
				}

			}
			else
			{
				ptr->height = getheight(ptr->left) > getheight(ptr->right) ? getheight(ptr->left) + 1 : getheight(ptr->right) + 1;
			}
		}
		else {
			if (ptr->left != NULL && ptr->right != NULL) {

				if (getheight(ptr->left) > getheight(ptr->right)) {
					binnode<T>*tmp = ptr->left;
					while (tmp->right != NULL) {
						tmp = tmp->right;
					}
					ptr->data = tmp->data;
					remove(ptr->left, ptr->data);
				}
				else {

					binnode<T>*tmp = ptr->right;

					while (tmp->left != NULL) {

						tmp = tmp->left;

					}
					ptr->data = tmp->data;
					remove(ptr->right, ptr->data);

				}
			}
			else {
				binnode<T>*tmp = ptr;

				ptr = ptr->left ? ptr->left : ptr->right;
				delete  tmp;
			}
         



		}




	}






}
template <typename T>
void AVL<T>::init_insert() {
	fstream f;

	f.open("1.txt", ios::in);

	while (!f.eof()) {

		string str1, str2;

		f >> str1 >> str2;

		insert(head, str1);

	}



}
template<typename T>
bool AVL<T>::search(const T&item) {

	if (head == NULL) {
		return false;
	}
	else if (head->data==item)
	{
		return true;
	}
	else {
		binnode<T>*ptr = head, *pre=head;

		while (ptr) {
			if (ptr->data < item) {

				pre = ptr;
				ptr = ptr->right;

			}
			else if (ptr->data > item) {
				pre = ptr;

				ptr = ptr->left;
			}
			else {

				return true;
			}


		}

		return false;


	}



}
template<typename T>
void AVL<T>::release(binnode<T>*ptr) {

	if (ptr) {

		release(ptr->left);
		release(ptr->right);
		delete ptr;
		ptr = NULL;

	}

}

template<typename T>
void AVL<T>::graph(ostream&out)const {
	graphaux(cout, 0, head);

}
template<typename T>
void AVL<T>::graphaux(ostream &out, int indent, binnode<T>*subtree)const {

	if (subtree!=NULL )
	{
		graphaux(out, indent + 8, subtree->right);
		out << setw(indent) << " " << subtree->data << endl;
		graphaux(out, indent + 8, subtree->left);
	}

}
template<typename T>
binnode<T>*AVL<T>::LR(binnode<T>*ptr) {

	 ptr->left = LL(ptr->left);

	return RR(ptr);


}
template<typename T>
binnode<T>*AVL<T>::LL(binnode<T>*ptr) {

	binnode<T>*tmp = ptr->right;

	ptr->right = tmp->left;
	tmp->left = ptr;
	ptr->height = getheight(ptr->left) > getheight(ptr->right) ? getheight(ptr->left)+1 : getheight(ptr->right)+1;
	tmp->height = getheight(tmp->left) > ptr->height ? getheight(tmp->left) + 1 : ptr->height + 1;
	return tmp;

}
template<typename T>
binnode<T>*AVL<T>::RL(binnode<T>*ptr) {
   

    ptr->right= RR(ptr->right);

	return LL(ptr);
}
template<typename T>
binnode<T>* AVL<T>::RR(binnode<T>*ptr) {

	binnode<T>*tmp = ptr->left;
	ptr->left = tmp->right;
	tmp->right = ptr;
	ptr->height = getheight(ptr->left) > getheight(ptr->right) ? getheight(ptr->left)+1 : getheight(ptr->right)+1;
	tmp->height = getheight(tmp->left) > ptr->height ? getheight(tmp->left) + 1 : ptr->height + 1;
	return tmp;




}
template<typename T>
int AVL<T>::getheight(binnode<T>*p) {

	if (p == NULL) {
		int a = 0;
		return a;
	}
	else
	{
		return p->height;
	}

	
}
template<typename T>
AVL<T>::AVL()
{

	head = NULL;


	

}
template<typename T>
AVL<T>::~AVL()
{
	if (head != NULL) {
		release(head);
	}

}
template<typename T>
void AVL<T>::insert( binnode<T>* &ptr, const T &item) {

	if (ptr==NULL)
	{
		ptr = new binnode<T>();

		ptr->data = item;
		ptr->height=1;
		ptr->left = ptr->right = NULL;
		
		
	}
	else if (item<ptr->data)
	{

	     insert(ptr->left, item);

		if (getheight(ptr->left)-getheight(ptr->right)==2)
		{

			if (item<ptr->left->data)
			{
				ptr = RR(ptr);
			

			}
			else {
				ptr = LR(ptr);
		
			}

		}

	}
	else if (item > ptr->data) {

		   insert(ptr->right, item);

		if (getheight(ptr->left)-getheight(ptr->right)==-2)
		{
			if (item > ptr->right->data) {
				
				ptr = LL(ptr);

			}
			else {
				
				ptr = RL(ptr);
			}
		}

	}
	else
	{
		cerr << "Ê÷ÖÐÒÑ´æÔÚ¸ÃÏî£¬²åÈëÊ§°Ü";
		
	}
	ptr->height=getheight(ptr->left) > getheight(ptr->right) ? getheight(ptr->left) +1: getheight(ptr->right)+1;

}
