
#ifndef STACK_TEST_CC
#define STACK_TEST_CC

#include "QUnit.h"
#include "Stack.h"
#include <memory>
#include <iostream>
#include <string>
#include <vector>

int main () {

	QUnit::UnitTest qunit(std :: cerr, QUnit :: verbose);
	
	// UNIT TEST 1
	// just make sure we can create an empty stack, and that it is empty
	{
		
		Stack <int> myStack;
		QUNIT_IS_EQUAL (myStack.isEmpty (), true);

	}

	// UNIT TEST 2
	// make sure we can push/pop a bunch of items
	{

		Stack <int> myStack;
		for (int i = 0; i < 10; i++) {
			myStack.push (i);
		}

		// now, pop everything off
		for (int i = 0; i < 10; i++) {
			QUNIT_IS_EQUAL (myStack.pop (), 9 - i);
		}
	}

	// UNIT TEST 3
	// make sure that the destructor works correctly... unless the stack correctly deallocates
	// all of the items it contains, this test will fail
	{
		static int temp = 0;
		struct Tester {
			Tester () {temp++;}
			~Tester () {temp--;}
		};

		{
			Stack <std :: shared_ptr <Tester>> myStack;
			std :: shared_ptr <Tester> myGuy = std :: make_shared <Tester> ();
			for (int i = 0; i < 10; i++) {
				myStack.push (myGuy);
			}
		}

		QUNIT_IS_EQUAL (temp, 0);
	}

	// UNIT TEST 4
	// make sure we can push/pop a bunch of items and then do it again
	{

		Stack <int> myStack;
		for (int i = 0; i < 10; i++) {
			myStack.push (i);
		}

		for (int i = 0; i < 5; i++) {
			QUNIT_IS_EQUAL (myStack.pop (), 9 - i);
		}

		for (int i = 5; i < 20; i++) {
			myStack.push (i);
		}

		for (int i = 0; i < 20; i++) {
			QUNIT_IS_EQUAL (myStack.pop (), 19 - i);
		}
		
		QUNIT_IS_EQUAL (myStack.isEmpty (), true);
	}


    {
        Stack<std::string> stringStack;
        
        stringStack.push("Hello");
        stringStack.push("World");
        stringStack.push("Stack");
        stringStack.push("Test");
        
        QUNIT_IS_EQUAL(stringStack.pop(), "Test");
        QUNIT_IS_EQUAL(stringStack.pop(), "Stack");
        QUNIT_IS_EQUAL(stringStack.pop(), "World");
        QUNIT_IS_EQUAL(stringStack.pop(), "Hello");
        
        QUNIT_IS_EQUAL(stringStack.isEmpty(), true);
    }

    {
        Stack<std::vector<int>> vectorStack;
        
        std::vector<int> vec1 = {1, 2, 3};
        std::vector<int> vec2 = {4, 5, 6};
        std::vector<int> vec3 = {7, 8, 9};
        
        vectorStack.push(vec1);
        vectorStack.push(vec2);
        vectorStack.push(vec3);
        
        // Verify vectors are popped in reverse order
        std::vector<int> popped3 = vectorStack.pop();
        QUNIT_IS_EQUAL(popped3.size(), 3);
        QUNIT_IS_EQUAL(popped3[0], 7);
        
        std::vector<int> popped2 = vectorStack.pop();
        QUNIT_IS_EQUAL(popped2.size(), 3);
        QUNIT_IS_EQUAL(popped2[1], 5);
        
        std::vector<int> popped1 = vectorStack.pop();
        QUNIT_IS_EQUAL(popped1.size(), 3);
        QUNIT_IS_EQUAL(popped1[2], 3);
        
        QUNIT_IS_EQUAL(vectorStack.isEmpty(), true);
    }
}

#endif

