#define _CRT_SECURE_NO_WARNINGS 

using namespace std;

template <typename T> class List {
	template <typename ElemType> struct Node
	{
		ElemType value;
		Node* next;
	};

	Node<T>* curent, * head, *tile;
public:
	List() {
		head = curent = NULL;

	};

	~List() {
	};
	T get_value() {
		return curent->value;
	}
	void push_back(T data) {
			Node<T>* temp = new Node<T>;
			temp->value = data;
			temp->next = temp;
		if (head == NULL)
		{
			head = curent = tile = temp;
		}
		else {
			tile->next = temp;
			temp->next = head;
			tile = temp;
		}
	}
	void push_begin(T data) {
		Node<T>* temp = new Node<T>;
		temp->value = data;
		if (head == NULL)
		{
			head = curent = tile = temp;
		}
		else
		{
			temp->next = head;
			tile->next = temp;
			curent = head = temp;

		}

	}
	bool search_by_value(T data) {
		curent = head;
		if (head == NULL)
		{
			return false;
		}
		do
		{
			if (curent->value != data)
			{
				return true;
			}
			curent = curent->next;

		} while (curent != head);

		return false;
	}
	bool delete_by_value(T data) {
		Node<T>* temp = head;
		Node<T>* previous = tile;
		do
		{
			if (temp->value == data)
			{
				previous->next = temp->next;
				delete temp;
				return true;
			}
			previous = temp;
			temp = temp->next;

		} while (temp != head);
		return false;
	}
	void delete_all_node() {
		tile->next = NULL;
		while (head != NULL)
		{
			curent = head;
			head = head->next;
			delete curent;
		}
		tile = curent = NULL;
	}
	void list_out() {
		curent = head;
		do
		{
			cout << "[" << &curent->value << "], ";
			curent = curent->next;

		} while (curent != head);
	}
	void SplitList(Node<T> * run, Node<T> **front, Node<T> **back) {
		Node<T> *prt1, *ptr2;
		ptr2 = run;
		prt1 = run->next;
		while (prt1 != head)
		{
			prt1 = prt1->next;
			if (prt1 != head)
			{
				ptr2 = ptr2->next;
				prt1 = prt1->next;
			}
		}
		*front = run;
		*back = ptr2->next;
		ptr2->next = NULL;
	}
	void MergenSort() {
		tile->next = NULL;
		if (head != tile) {

			head = merge_sort(head);
		}
		
		while (tile->next != NULL)
		{
			tile = tile->next;
		}
		tile->next = head;
	}
	Node<T>* merge(Node<T>* temp1, Node<T>* temp2)
	{
		int i = 0;

		Node<T>* three;
		Node<T>* temp_ptr;

		if (temp1 == NULL)
			return temp2;

		if (temp2 == NULL)
			return temp1;
		if (temp1->value < temp2->value)
		{
			three = temp1;
			while (temp1->next != NULL && temp2 != NULL)
			{
				if (temp1->next->value < temp2->value)
					temp1 = temp1->next;
				else
				{
					temp_ptr = temp2->next;
					temp2->next = temp1->next;
					temp1->next = temp2;
					temp2 = temp_ptr;
					temp1 = temp1->next;
				}
			}
			if (temp2 != NULL)
				temp1->next = temp2;
		}
		else
		{
			three = temp2;
			while (temp2->next != NULL && temp1 != NULL)
			{
				if (temp2->next->value < temp1->value)
					temp2 = temp2->next;
				else
				{
					temp_ptr = temp1->next;
					temp1->next = temp2->next;
					temp2->next = temp1;
					temp1 = temp_ptr;
					temp2 = temp2->next;
				}
			}
			if (temp1 != NULL)
				temp2->next = temp1;
		}

		return three;
	}
	Node<T> *merge_sort(Node<T> *head) {

		Node<T>* temp1 = head;
		Node<T>* temp2 = head->next;


		if ((head == NULL) || (head->next == NULL))
			return head;


		while ((temp2 != NULL) && (temp2->next != NULL))
		{
			head = head->next;
			temp2 = temp2->next->next;
		}
		temp2 = head->next;
		head->next = NULL;

		return merge((merge_sort(temp1)), (merge_sort(temp2)));
	}

	bool operator!() {
		return(head != NULL);
	}
	/*void operator++ () {
		if (curent != NULL) {
			curent = curent->next;
		}
	};*/
	/*List<T>& operator= (List<T> &Temp) {

		List<T>* temp = new List<T>;

		
			
		return *this;
	}*/
};

