#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Node for our linked list
struct node
{
    int data; // data value (could be a lot more values)

    node *next; // we always need a "link" in a linked list

    node(int x)
    { // cunstructor to make adding values easy
        data = x;
        next = NULL;
    }
};

class MyVector
{
private:
    node *head;
    node *tail;
    int size;

public:
    // int &operator[](int index, const MyVector other)
    // {
    //  }

    MyVector()
    {
        head = nullptr;
    }

    MyVector(string FileName, int *&arr, int &size)
    {
        ifstream fin;        // stream reference
                             //
        fin.open(FileName);  // open the file
                             //
        fin >> size;         // get first value which contains
                             // number of remaining values in file
                             //
        arr = new int[size]; // allocate new array of correct size
                             //
        int i = 0;           // need an array index for our while loop
                             //
        // Can also use for loop since we know the exact count in file.
        // eof = end of file flag
        // `!fin.eof()` evaulates to true when we hit end of file.
        while (!fin.eof())
        {
            fin >> arr[i]; // read file value straight into array
                           // at index i
            i++;           // increment array index
        }
    }

    MyVector(int A[], int size)
    {
        head = NULL; // NULL = zeros
                     // and zeros imply empty

        for (int i = 0; i < size; i++)
        {
            pushFront(A[i]);
        }
    }

    MyVector(const MyVector &V1)
    {
    }

    void pushFront(int x)
    {
        node *tempPtr = new node(x); // create a new node and
                                     // add data to it

        if (!head)
        { // `!head` implies empty list
            // So does `head == NULL`

            head = tail = tempPtr; // `head = tempPtr` places addrress of
                                   // tempPtr in head (points head to tempPtr)
        }
        else
        {                         // list not empty
            tempPtr->next = head; // point tempPtr's next to what head points to
            head = tempPtr;       // now point head to tempPtr
        }
    }

    void pushFront(MyVector V2)
    {
        for (int i = 0; i < V2.size; i++)
        {
            pushFront(V2.tail->data);
        }
    }

    void pushRear(int x)
    {
        node *tempPtr = new node(x); // create a new node and
                                     // add data to it
        if (!head)
        { // `!head` implies empty list
            // So does `head == NULL`

            head = tail = tempPtr; // `head = tempPtr` places addrress of
                                   // tempPtr in head (points head to tempPtr)
        }
        else
        {
            tail->next = tempPtr; // point tempPtr's next to what head points to
            tail = tempPtr;       // now point head to tempPtr
        }
    }

    void pushRear(MyVector V2)
    {
        for (int i = 0; i < V2.size; i++)
        {
            pushRear(V2.head->data);
        }
    }

    int popFront()
    {
        int bruh = head->data;
        return bruh;
    }

    int popRear()
    {
        int bruh = tail->data;
        return bruh;
    }

    void print()
    {
        cout << "[";
        node *temp = head;
        while (temp)
        {
            cout << temp->data << ", ";
        }
        cout << "]" << endl;
    }
};
