#include <iostream>
#include "List/DoubleLinkedlist.h"
#include "List/Singlelinkedlist.h"
void exampleSingleList(){
    try{
        SinglyLinkedList<int> list;
        list.AddToBack(5);
        list.AddToBack(10);
        list.AddToBack(20);
        list.AddToBack(12);
        list.AddToBack(13);
        list.AddToBack(14);

        cout<<"added six elements to the emd of list" << endl;
        cout<<endl<<list << endl;

        list.AddToBeginning(7);

        cout<<"added an element to the beginning"<<endl;
        cout<<endl<<list << endl;


        list.AddAtIndex(4,123);

        cout<<"added an element by index 4"<<endl;
        cout<<list << endl;

        cout<<"Search 123 in list: "<<list.Search(123) << endl << endl;

        cout<<"Size of list: "<<list.getSize()<<endl << endl;

        cout<<"IS empty: "<<list.IsEmpty()<<endl << endl;

        list.DeleteFromBeginning();

        cout<<"deleted an object from the beginning"<<endl;
        cout<<list<<endl;

        list.DeleteFromEnd();

        cout<<"deleted an object from the end"<<endl;
        cout<<list<<endl;

        list.DeleteAtIndex(4);

        cout<<"deleted an obj by index 4"<<endl;
        cout<<list<<endl;

        cout<<"used operator[] with index 2"<<endl;
        cout<<list[2]<<endl << endl;

        cout<<"used operator[] with index 100"<<endl;
        cout<<list[100]<<endl;
    }
    catch (const out_of_range &e){
        cerr<<e.what()<<endl;
    }

}
void exampleDoubleList(){
    try {
        DoubleLinkedList<int> list;
        list.AddToBack(5);
        list.AddToBack(10);
        list.AddToBack(20);
        list.AddToBack(12);
        list.AddToBack(13);
        list.AddToBack(14);

        cout << "added six elements to the emd of list" << endl;
        cout << endl << list << endl;

        list.AddToBeginning(7);

        cout << "added an element to the beginning" << endl;
        cout << endl << list << endl;


        list.AddAtIndex(4, 123);

        cout << "added an element by index 4" << endl;
        cout << list << endl;

        cout << "Search 123 in list: " << list.Search(123) << endl << endl;

        cout << "Size of list: " << list.getSize() << endl << endl;

        cout << "IS empty: " << list.IsEmpty() << endl << endl;

        list.DeleteFromBeginning();

        cout << "deleted an object from the beginning" << endl;
        cout << list << endl;

        list.DeleteFromEnd();

        cout << "deleted an object from the end" << endl;
        cout << list << endl;

        list.DeleteAtIndex(4);

        cout << "deleted an obj by index 4" << endl;
        cout << list << endl;

        cout << "used operator[] with index 2" << endl;
        cout << list[2] << endl << endl;

        cout << "used operator[] with index 100" << endl;
        cout << list[100] << endl;
    }
    catch (const out_of_range &e){
        cerr<<e.what()<<endl;
    }
}


int main() {
    exampleSingleList();
    //exampleDoubleList();
}