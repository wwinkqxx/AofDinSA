#include <iostream>
#include "DoublyList.h"
#include "Node.h"

using namespace std;

void inputList(DoublyList& list, const char* name) 
{ int n;
cout << "Enter count of elements the list " << name << ": ";
cin >> n;

while (n <= 0)
{
    cout << "Count nedd be high then 0. Enter again: ";
    cin >> n;
}

cout << "Enter " << n << " elements:" << endl;

for (int i = 0; i < n; i++)
{
    int value;
    cin >> value;

    list.addTail(value);
}
}

void showList(DoublyList& list) 
{ list.print();
cout << "Length of the list: "
<< list.length()
<< endl;

cout << endl;
}

void printPointerTable( const char* task, DoublyList& list) 
{ cout << "------------------------------------------------------------" << endl;


cout << "HEAD -> ";

Node* current = list.getHead();

while (current != nullptr)
{
    cout << "[" << current->data << "]";

    if (current->next != nullptr)
        cout << " -> ";

    current = current->next;
}

cout << " -> NULL" << endl;

cout << "TAIL -> ";

current = list.getTail();

while (current != nullptr)
{
    cout << "[" << current->data << "]";

    if (current->prev != nullptr)
        cout << " -> ";

    current = current->prev;
}

cout << " -> NULL" << endl;

cout << "------------------------------------------------------------"
<< endl;
}
int main() {
    DoublyList L; DoublyList L2;
 
    cout << endl;
    cout << "Enter list L" << endl;

    inputList(L, "L");

    cout << endl;
    cout << "Start list:" << endl;
    showList(L);



    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Task 1" << endl;
    cout << "Insert element E after the first element of the list"<< endl;
 
    cout << "------------------------------------------------------------" << endl;

    int E;

    cout << "Ener value E: ";
    cin >> E;

    L.insertAfterFirst(E);

    cout << endl;
    cout << "List after task1:" << endl;

    showList(L);

    printPointerTable("1 - insert E after the first element", L);



    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Task 2" << endl;
    cout << "Find max value the list L." << endl;
    cout << "------------------------------------------------------------" << endl;

    int maximum = L.findMax();

    cout << "max value: "
        << maximum
        << endl;

    cout << endl;

    cout << "List after task 2:" << endl;

    showList(L);

    printPointerTable("Á — find the max value", L);


    cout << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Task 3" << endl;
    cout << "Conect list L2 to tail list L1." << endl;
    cout << "------------------------------------------------------------" << endl;

    cout << endl;
    cout << "Enter list L2:" << endl;

    inputList(L2, "L2");

    cout << endl;

    cout << "list L1 before conect:" << endl;
    L.print();

    cout << "list L2 before conect:" << endl;
    L2.print();

    cout << endl;

    L.append(L2);

    cout << "list L1 after conect L2:" << endl;

    showList(L);

    printPointerTable("Â — conect L2 to tail L1", L);
  

    return 0;
}