class Node {
public:
	int val;
	Node* next;
	Node* prev;

	Node(int _val) {
		this->val = _val;
		this->prev = this->next = nullptr;
	}
};

class MyCircularDeque {
	Node* head;
	Node* tail;
	int capacity;
	int size;
public:
    MyCircularDeque(int k) {
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
        this->capacity = k;
        this->size = 0;
    }
    
    bool insertFront(int value) {
        if(size < capacity) {
        	Node* node = new Node(value);
	        Node* temp = head->next;
	        head->next = node;
	        node->prev = head;
	        temp->prev = node;
	        node->next = temp;
	        size++;
	        return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(size < capacity) {
        	Node* node = new Node(value);
        	Node* temp = tail->prev;
        	tail->prev = node;
        	node->next = tail;
        	temp->next = node;
        	node->prev = temp;
        	size++;
        	return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(size) {
        	Node* delNode = head->next;
        	Node* nextt = delNode->next;
        	head->next = nextt;
        	nextt->prev = head;
        	delete delNode;
        	size--;
        	return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(size) {
        	Node* delNode = tail->prev;
        	Node* prevv = delNode->prev;
        	prevv->next = tail;
        	tail->prev = prevv;
        	delete delNode;
        	size--;
        	return true;
        }
        return false;
    }
    
    int getFront() {
        if(size)
        	return head->next->val;
        return -1;
    }
    
    int getRear() {
        if(size)
        	return tail->prev->val;
        return -1;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};