#include <iostream>
#include "stack.h"
#include "stack.cpp"
using std::cout;

int main()
{
	stack<int,1500000> testStack1;
	stack<float,1500000> testStack2;
	stack<int,2> testStack3;

	/*========= Test 1 ======================
		stack<int,100> testStack;
		for(int i=0;i<4000000;i++)
			if(testStack.push(i))
			cout<<"Pushed successfully "<<i<<" value"<<endl;
		else
			cout<<"Pushing error testStack1!!!!!!!!!!!!\t\t\t"<<endl;
	*/


	//================Test 2 =====================
	for(int i=0;i<1500000;i++)
	{
		int tempVariable=0;
		if(testStack1.push(i))
			cout<<"Pushed successfully "<<i<<" value"<<endl;
		else
			cout<<"Pushing error testStack1!!!!!!!!!!!!\t\t\t"<<endl;

		if(!(i%4))//we pop from testStack1 for every number n such as n=4*k where k is an integer 
			if( testStack1.pop(tempVariable) )
			{
				if( testStack3.push(tempVariable))
					cout<<"Popped and pushed successfully "<<tempVariable<<" value"<<endl;
				else
					cout<<"Pushing error testStack2!!!!!!!!!!\t\t\t"<<endl;
			}
			else
				cout<<"Popping error testStack1!!!!!!!!!!\t\t\t"<<endl;
		
		if(testStack2.push(i*0.1))
			cout<<"Pushed successfully "<<i*0.1<<" value"<<endl;
		else
			cout<<"Pushing error testStack2!!!!!!!!!!!!!\t\t\t"<<endl;

		
		cout<<"Finished round "<<i<<endl<<endl;
	}

	return 0;
}