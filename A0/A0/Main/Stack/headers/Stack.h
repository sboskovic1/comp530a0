
#ifndef STACK_H
#define STACK_H

// this is the node class used to build up the LIFO stack
template <class Data>
class Node {

private:

	Data holdMe;
	Node *next;
	
public:

	/*****************************************/
	/** WHATEVER CODE YOU NEED TO ADD HERE!! */
	/*****************************************/

    Data val() {
        return holdMe;
    }

    Node (Data val) {
        holdMe = val;
        next = NULL;
    }

    Node *getNext() {
        return next;
    }

    void setNext(Node *nextNode) {
        next = nextNode;
    }

};

// a simple LIFO stack
template <class Data> 
class Stack {

	Node <Data> *head;

public:

	// destroys the stack
	~Stack () { 
        Node<Data>* curr = head;
        while (curr != NULL) {
            Node<Data>* temp = curr;
            curr = curr->getNext();
            delete temp;
        }
    }

	// creates an empty stack
	Stack () { 
        head = NULL;
    }

	// adds pushMe to the top of the stack
	void push (Data pushMe) { 
        Node<Data>* newNode = new Node<Data>(pushMe);
        newNode->setNext(head);
        head = newNode;
    }

	// return true if there are not any items in the stack
	bool isEmpty () { 
        return head == NULL;
    }

	// pops the item on the top of the stack off, returning it...
	// if the stack is empty, the behavior is undefined
	Data pop () { 
        Node<Data> *temp = head;
        head = head->getNext();
        Data val = temp->val();
        delete temp;
        return val;
    }
};

#endif
