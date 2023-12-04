
#include<iostream>

using namespace std;

class List {

private:
    int data[100];
    int position;

public:
    List() {
        position = 0;
    };

    int getsize() {
        return position;
    };

    void create(int val);
    void insert_data(int pos, int val);
    void delete_at_position(int pos);
    void modify(int pos, int val);
    void transverse();
    List Merging(List l1, List l2);
};

void List::create(int val) {
    data[position++] = val;
}

void List::insert_data(int pos, int val) {
    int i;
    if (pos < position) {
        for (i = position; i > pos; i--) {
            data[i] = data[i - 1];
        }
        data[i] = val;
        position++;
    }
    else if (pos == position) {
        data[position++] = val;
    }
    else {
        cout << "\nIndex out of range. Data not inserted.\n";
    }
}

void List::delete_at_position(int pos) {
    if (pos < position) {
        for (int i = pos; i < position - 1; i++) {
            data[i] = data[i + 1];
        }
        position--;
    }
    else {
        cout << "\nIndex out of range. Data not deleted.\n";
    }
}

void List::modify(int pos, int val) {
    if (pos < position) {
        data[pos] = val;
    }
    else {
        cout << "\nIndex out of range. Data not modified.\n";
    }
}

void List::transverse() {
    for (int i = 0; i < position; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}
List List::Merging(List l1, List l2) {
    List l3;
    int pos = 0;

    cout << "\nList 1 data:\n";
    l1.transverse();
    cout << "\nList 2 data:\n";
    l2.transverse();

    for (pos = 0; pos < l1.position; pos++) {
        l3.data[l3.position++] = l1.data[pos];
    }

    for (int i = 0; i < l2.position; i++) {
        l3.data[l3.position++] = l2.data[i];
    }


    return l3;
}


int main() {

    List l1, l2, l3;
    l1.create(5);
    l1.create(4);
    l1.create(3);
    l1.create(2);
    l1.insert_data(2, 7); // Inserting at a random index
    l1.insert_data(10, 9); // Inserting at an index out of range
    cout << "\nAfter Insertion:\n";
    l1.transverse();
    l1.delete_at_position(9);
    cout << "\nAfter deletion:\n";
    l1.transverse();
    l1.delete_at_position(100);
    l1.modify(4, 20);
    cout << "\nAfter modification:\n";
    l1.transverse();

    l2.create(10);
    l2.create(14);
    l2.create(13);
    l2.create(12);
    cout << "\nElements of list 2:\n";
    l2.transverse();

    l3 = l3.Merging(l1, l2);
    cout << "\nAfter merging:\n";
    l3.transverse();

    return 0;
}
