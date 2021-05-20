#define _CRT_SECURE_NO_WARNINGS 

using namespace std;

template <typename T> class List {
	template <typename ElemType> struct Node
	{
		ElemType value;
		Node* next;
	};

	Node<T>* current, * head, *tile;
	void push_after(Node<T> *target, T data) {
		Node<T>* temp = new Node<T>;
		temp->next = target->next;
		temp->value = data;
		target->next = temp;
	}
public:
	List() {
		head = current = tile =  NULL;

	};

	~List() {
		delete_all_node();
	};

	// -	добавление элемента после последнего
	void push_back(T data) {
			Node<T>* temp = new Node<T>;
			temp->value = data;
			temp->next = temp;
		if (head == NULL)
		{
			head = current = tile = temp;
		}
		else {
			tile->next = temp;
			temp->next = head;
			tile = temp;
		}
	}
	//==========================================
	//	-	добавление элемента перед первым;  
	void push_begin(T data) {
		Node<T>* temp = new Node<T>;
		temp->value = data;
		if (head == NULL)
		{
			head = current = tile = temp;
		}
		else
		{
			temp->next = head;
			tile->next = temp;
			current = head = temp;

		}

	}
	//==========================================
	//-	добавление элемента по пор€дку (предполагаетс€, что элемент в динамической
	//  структуре отсортированы, и необходимо, чтобы добавление нового элемента
	//  не нарушило упор€доченности);
	void add_after_sorting(T data) {

		if (head == NULL)
		{
			return;
		}
		Node<T>* run = current;
		if (current->value > data)
		{
			run = head;
			if (data < head->value)
			{
				push_begin(data);
			}
		}
		while (run->next != head)
		{
			if (data >= run->value && data <= run->next->value)
			{
				push_after(run, data);
				return;
			}
			run = run->next;
		}
		Node<T>* temp = new Node<T>;
		tile = temp;
		temp->value = data;
		run->next = temp;
		temp->next = head;
		
	}
	//==========================================
	//-	удаление элемента с указанной информационной частью; 
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
	//==========================================
	//-	поиск элемента;
	bool search_by_value(T data) {
		current = head;
		if (head == NULL)
		{
			return false;
		}
		do
		{
			if (current->value != data)
			{
				return true;
			}
			current = current->next;

		} while (current != head);

		return false;
	}
	//==========================================
	//-	удаление всех элементов;
	void delete_all_node() {
		tile->next = NULL;
		while (head != NULL)
		{
			current = head;
			head = head->next;
			delete current;
		}
		tile = current = NULL;
	}
	//==========================================
	//-	сортировка элементов;
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
	private:
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
	public:
	//==========================================
	//-	упор€дочение текущего элемента (предполагаетс€, что все остальные элементы упор€дочены);
	void sort_current_value() {
		T data = current->value;
		Node<T> *temp = current;
		if (temp == head)
		{
			head = head->next;
			tile->next = head;
			current = head;
			delete temp;
		}
		else {
			Node<T> *run = head;
			while (run->next != temp)
			{
				run = run->next;
			}
			run->next = temp->next;
			current = temp->next;
			
			delete temp;
		}
		add_after_sorting(data);
	}
	//==========================================
	//-	перегруженный оператор !, определ€ющий существование элементов в структуре данных;
	bool operator!() {
		return(head != NULL);
	}
	//==========================================
	//-	копирование структуры данных с помощью перегруженного оператора присваивани€;
	List<T> operator= ( List<T>& Val) {

		if (Val.head != NULL) {
			Val.delete_all_node();
		}
		this->SetStart(true);
		do
		{
			Val.push_back(current->value);
			++(*this);

		} while (current != head);
		
		return *this;
	}
	//==========================================
	//-	получение ссылки на информационную часть текущего элемента (возвращает удачность операции);
	bool curr_inf(T *& inf) { 
		if (current != NULL)
		{
			inf = &current->value;
			return false;
		}
		return true;
	}
	//==========================================
	//-	получение копии информационной части текущего элемента (возвращает удачность операции); 
	bool curr_inf(T & inf) { 
		if (current != NULL) {
			inf = current->value;
			return false;
		}
		return true;
	}
	//==========================================
	//-	перегруженный оператор ++ (префиксный) дл€ перехода к следующему элементу;
	List& operator ++() {
		if (current != NULL) {
			current = current->next;
		}
		return *this;
	};
	//==========================================
	//-	метод, перевод€щий указатель на текущий элемент в начало (конец, при необходимости) списка.
	void SetStart(bool Head) {
		current = Head ? head : tile;
	}
	//==========================================
	/*T get_value() {
		return curent->value;
	}*/
	void list_out() {
		current = head;
		do
		{
			cout << "[" << current->value << "], ";
			current = current->next;

		} while (current != head);
	}
	
};

