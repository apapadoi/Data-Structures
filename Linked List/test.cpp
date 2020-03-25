#include <iostream>
#include <cstdlib>
#include "linkedList.h"
#include "linkedList.cpp"

#define TEST_LIMIT_NUMBER 500000

int main()
{
	linkedList<int> testList1;
	
	for(int i=0;i<TEST_LIMIT_NUMBER;i++)
		if(!testList1.insertStart(i))		
		{
			cout<<"i: "<<i;
			system("pause");
		}
	
	int temp;
	cout<<"inserted"<<endl;
	for(int i=TEST_LIMIT_NUMBER/3 - 1 ;i>=0;i--)
		if(testList1.getData(i,temp))
		{
			//cout<<"temp: "<<temp<<endl;
			//system("pause");
		}

	//========= Tested methods ==========
	//isEmpty
	//insertStart 4 million elements
	//insertAfter 4 million elements
	//insertEnd 100 thousands elements
	//deleteStart(T&) 2 million elements
	//deleteStart() 2 million elements
	//deleteAfter(T&,T&) 250 thousand elements ~697 seconds
 	//deleteAfter(T&) 250 thousand elements ~697 seconds
	//_delete 250000 thousand elements ~637 seconds
	//deleteEnd(T&) 250000 thousand elements ~1160 seconds
	//deleteEnd 250000 thousand elements ~1160 seconds
	//getData 250000 thousand elements
	//print

	/*
	testList1.insertEnd(5);
	//testList1.print();
	testList1.insertStart(8);
	//testList1.print();
	testList1.insertEnd(15);
	//testList1.print();
	int temp=0;
	cout<<"Initial list: "<<endl;
	testList1.print();
	cout<<endl;
	testList1.deleteEnd(temp);
	cout<<"Temp: "<<temp<<endl;
	testList1.print();
	cout<<endl;
	testList1.deleteEnd(temp);
	cout<<"Temp: "<<temp<<endl;
	testList1.print();
	cout<<endl;
	testList1.deleteEnd(temp);
	cout<<"Temp: "<<temp<<endl;
	testList1.print();
	cout<<"."<<endl;
	testList1.deleteEnd(temp);
	cout<<"Temp: "<<temp<<endl;
	testList1.print();*/

	/*testList1.insertStart(5);
	testList1.insertAfter(5,15);
	testList1.insertEnd(8);
	int temp=0;
	testList1.getData(15000000,temp);
	cout<<temp<<endl<<endl;
	testList1.print();*/
	
	/*
	//===============================================
	int choice=3,prevnumber,element;
	
	while(choice!=0)
	{
		cout<<"1-insertStart"<<endl;
		cout<<"2-print"<<endl;
		cout<<"Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				//cout<<"Give previous number: ";
				//cin>>prevnumber;
				cout<<"Give element: ";
				cin>>element;
				testList1.insertStart(element);
				break;
			case 2:
				testList1.print();
				break;
			default:
				cout<<"Wrong choice";
		}
		cout<<endl<<endl;
	}
	testList1.print();
	*/
	return 0;
}