
#include <iostream>
#include <cstdlib>
using namespace std;

// Definition of Node
struct Node
{
    int data;
    Node* next;
};

// Definition of SortedLinkedList
class SortedLinkedList
{
private:
    Node* head;
public:
    // Constructor
    SortedLinkedList();

    // Destructor
    ~SortedLinkedList();

    // Member functions
    void addElement(int element);
    void printElements();
    void deleteElementByIndex(int index);
    void deleteElementByValue(int value);
};

// Constructor
SortedLinkedList::SortedLinkedList()
{
    head = NULL;
}

// Destructor
SortedLinkedList::~SortedLinkedList()
{
    Node* currNode, * nextNode;
    currNode = head;

    while (currNode != NULL)
    {
        nextNode = currNode->next;
        delete currNode;
        currNode = nextNode;
    }
    head = NULL;
}

// Add a element
void SortedLinkedList::addElement(int element)
{
    Node* newNode = new Node;
    newNode->data = element;
    newNode->next = NULL;

    // If list is empty
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* currNode = head;
    Node* prevNode = NULL;

    // Find the position to insert
    while (currNode != NULL && currNode->data < element)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Insert at the beginning
    if (prevNode == NULL)
    {
        newNode->next = head;
        head = newNode;
    }
    // Insert at middle or end
    else
    {
        prevNode->next = newNode;
        newNode->next = currNode;
    }
}

// Print the elements
void SortedLinkedList::printElements()
{
    Node* currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

// Delete a element by index
void SortedLinkedList::deleteElementByIndex(int index)
{
    Node* currNode = head;
    Node* prevNode = NULL;

    if (index < 0)
    {
        return;
    }

    // Find the node to delete
    int count = 0;
    while (currNode != NULL && count != index)
    {
        prevNode = currNode;
        currNode = currNode->next;
        count++;
    }

    // If node to delete is not found
    if (currNode == NULL)
    {
        return;
    }

    // Delete the node
    if (prevNode == NULL)
    {
        head = currNode->next;
    }
    else
    {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

// Delete a element by value
void SortedLinkedList::deleteElementByValue(int value)
{
    Node* currNode = head;
    Node* prevNode = NULL;

    // Find the node to delete
    while (currNode != NULL && currNode->data != value)
    {
        prevNode = currNode;
        currNode = currNode->next;
    }

    // If node to delete is not found
    if (currNode == NULL)
    {
        return;
    }

    // Delete the node
    if (prevNode == NULL)
    {
        head = currNode->next;
    }
    else
    {
        prevNode->next = currNode->next;
    }

    delete currNode;
}

int main()
{
    SortedLinkedList list;
    list.addElement(1);
    list.addElement(20);
    list.addElement(3);
    list.printElements();  // 1 2 3
    list.deleteElementByIndex(1);
    list.printElements();  // 1 3
    list.deleteElementByValue(20);
    list.printElements();  // 1 
    return 0;
}