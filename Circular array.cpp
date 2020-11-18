#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

	  const int MAX = 20;
	  class circularqueue
	  {
		   int a[MAX],front,rear;
		    public :
		   circularqueue()
		   {
			 front=rear=-1;
		   }
		   void insert(int);
		   int deletion();
		   void display();
	  };

	  void circularqueue :: insert(int val)
	  {
		 if((front==0 && rear==MAX-1) || (rear+1==front))
			  cout<<" Circular Queue is Full";
		 else
		 {
		   if(rear==MAX-1)
			  rear=0;
		   else
			 rear++;
		   a[rear]=val;
		 }
		 if(front==-1)
		   front=0;
	  }
	  int circularqueue :: deletion()
	  {
		 int k;
		 if(front==-1)
			cout<<"Circular Queue is Empty";
		 else
		 {
			k=a[front];
			if(front==rear)
			   front=rear=-1;
			else
			{
			   if(front==MAX-1)
				  front=0;
			   else
				  front++;
			}
		 }
		 return k;
	  }
	  void circularqueue :: display()
	  {
		  int i;
		  if(front==-1)
			 cout<<"Circular Queue is Empty";
		  else
		  {
			 if(rear < front)
			 {
				for(i=front;i<=MAX-1;i++)
				   cout<<a[i]<<"   ";
				for(i=0;i<=rear;i++)
				   cout<<a[i]<<"   ";
			 }
			 else
			 {
				for(i=front;i<=rear;i++)
				   cout<<a[i]<<"   ";
				cout<<endl;
			 }
		  }
	  }

	  int main()
	  {
		 circularqueue c1;

		 int ch,val;
		 char opt;
		 do
		 {
		   system("cls");
		   cout<<"-----------Menu-------------";
		   cout<<"\nPress 1 for Insertion:";
           cout<<"\nPress 2 for Deletion";
           cout<<"\nPress 3 for the Display";
           cout<<"\nPress 4 for Exit";
		   cout<<"\nEnter Your Choice Accordingly ?";
		   cin>>ch;
		   switch(ch)
		   {
			   case 1 : cout<<"Enter Element to Insert ?";
						cin>>val;
						c1.insert(val);
						break;
			   case 2 : val=c1.deletion();
						cout<<"Deleted Element :"<<val<<endl;
						break;
			   case 3 : c1.display();
						break;
			}
			cout<<"Do you want to continue<Y/N> ?";
			cin>>opt;
		  }while(opt=='Y' || opt=='y');
		   getch();
		}
