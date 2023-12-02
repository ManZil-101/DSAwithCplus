
// Implementing a List using an array in C++




#include<iostream>

using namespace std;

class List {

private: //Declearing private data variable
    int data[100];
    int position;

public:
    //Constructor
    List () {
        position = -1;
    };

   void create(int val); //Add data to the list linearly
   void insert_data(int pos, int val); // Add data to the list at specified position
   void delete_data(int pos); // Delete data from the specified position of list
   void modify(int pos, int val); // Modification of data from desired position
   void transverse(); // Display all element of list
   void Merging(List l1, List L2); //merge two existing list

};


void List :: create(int val)
{
    data[position++] = val;
    cout << position;
}

void List :: insert_data (int pos, int val)
{
    for(int i = position; i > pos ; i-- )
    {
        data[i+1] = data[i];


    }
}


int main()
{

    List l1;
    l1.create(5);
    return 0;
}
