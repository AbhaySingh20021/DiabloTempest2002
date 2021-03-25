#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* next;
		Node* prev;
};

class DL_list: public Node{
	
	public:
	Node *startptr, *temp;
		DL_list(){
			startptr = NULL;
			temp = NULL;
			
		}
		void create(){	
		cout<<"\n";

			int Element;
			cout<<"Enter value: ";
			cin>>Element;
			Node *newnode=new Node;
			newnode->data=Element;
			newnode->next=NULL;
			newnode->prev=NULL;
			if(startptr==NULL)
			{
				startptr=newnode;
				temp=newnode;
			}
			else
			{
				temp->next=newnode;
				newnode->prev=temp;
				temp=temp->next;
			}
		}
		
		void display(){
		cout<<"\n";

			cout<<"----Display----";
			if(startptr == NULL){
				cout<<"\n List is Empty";
			}else{
	            cout<<"\n List : ";
			    temp = startptr;
				while(temp != NULL ){
					cout<<"("<<temp->prev<<")  "<<temp->data<<"  ("<<temp->next<<")""  <->  ";
					temp = temp->next;
				}
				cout<<"NULL ";
			}
		}
		
		void insrtsrt(){
		cout<<"\n";

			int Element;
			Node * newnode = new Node;
			cout<<"\n Enter Data : ";
			cin>>Element;
			newnode->data = Element;
			newnode->next = NULL;
			newnode->prev=NULL;
            newnode->next = startptr;
			startptr->prev=newnode;
			startptr = newnode;
			cout<<" Data Added";
			cout<<"\n";
	

		}
		
		void insrtend(){
		cout<<"\n";

			int Element;
			Node *newnode = new Node;
			
				cout<<"\n Enter Data : ";
			    cin>>Element;
			    newnode->data = Element;
			    newnode->next = NULL;
			    temp = startptr;
			    while(temp->next != NULL){
				     temp = temp->next;
			    }
			    temp->next = newnode;
			    newnode->prev=temp;

				
			
			cout<<" Data Added";
			cout<<"\n";
		}
		
		void insrtbtwn(){
		cout<<"\n";

			int Element , n, i=1;
			Node * newnode = new Node;
			cout<<"\n Enter Data : ";
			cin>>Element;
			cout<<"\n Enter Position : ";
			cin>>n;
			if(n<1){
				cout<<"\n Error! Cannot enter data at this position ";
			}else{
				newnode->data = Element;
			    newnode->next = NULL;
			    temp = startptr;
			    while(i != (n-1)){
				     temp = temp->next;
				     i++;
			    }
			    newnode->next = temp->next;
				temp->next->prev=newnode;
			    temp->next = newnode;
			    newnode->prev=temp;

			}
			cout<<" Data Added";
			cout<<"\n";
		}
		
		void delsrt(){
		cout<<"\n";

			temp = startptr;
			startptr = temp->next;
			delete(temp);
			cout<<" Data Deleted";
			cout<<"\n";

		}
		
		void delend(){
		cout<<"\n";

			Node *temp2;
			temp = startptr;
			while(temp->next->next != NULL){
				temp=temp->next;
			}
			temp2 = temp->next;
			temp->next = NULL;
			delete(temp2);
			cout<<" Data Deleted";
			cout<<"\n";

		}
		
		void delbwt(){
		cout<<"\n";

			Node * temp3;
			int n,i;
			temp = startptr;
			cout<<"\n Enter Position : ";
			cin>>n;
			for(i=1;i<n-1;i++){
				temp = temp->next;
			}
			temp3 = temp->next;
			temp->next = temp3->next;
			temp3->next->prev=temp;
			delete(temp3);
			cout<<" Data Deleted";
			cout<<"\n";

		}
			void reverse(){
			cout<<"\n";
		

			Node * curr,* temp;
			curr=startptr;
			temp=NULL;

			while(curr!=NULL)

			{
			temp=curr->prev;
			curr->prev=curr->next;
			curr->next=temp;
			curr=curr->prev;
			}
			if(temp!=NULL)
			startptr=temp->prev;
			cout<<"\n";
		}

		
		void Concat(Node *a,Node *b)
		{
			if( a != NULL && b!= NULL )
    		{
        		if (a->next == NULL)
				{
            		a->next = b;
					b->prev=a;
				}
        		else
            		Concat(a->next,b);
    		}
    		else
    		{
        		cout<<"\nEither a or b is NULL\n";
    		}
		}
	};

int main(){
	int start =1,choice;
 
	int Element;
	DL_list list1,list2;
	int i,x;
			
	while(start==1){
		cout<<"\n1. Create";
		cout<<"\n2. Display";
		cout<<"\n3. Insert from Start";
		cout<<"\n4. Insert from Between";
		cout<<"\n5. Insert from End";
		cout<<"\n6. Delete from  Start";
		cout<<"\n7. Delete from  Between";
		cout<<"\n8. Delete from  End";
		cout<<"\n9. Reverse the DL_list";
		cout<<"\n10. Concat ";
		cout<<"\n";
		cout<<"\n Enter Choice : ";
		cin>>choice;
		cout<<"\n";

		
		switch(choice){
			case 1:
				cout<<"Enter number of elements: ";
				cin>>x;
				for(i=0;i<x;i++)
				list1.create();
				break;

			case 2:
				list1.display();
				break;

			case 3:
				list1.insrtsrt();
				list1.display();
				break;

			case 4:
				list1.insrtbtwn();
				list1.display();
				break;

			case 5:
				list1.insrtend();
				list1.display();
				break;

			case 6:
				list1.delsrt();
				list1.display();
				break;

			case 7:
				list1.delbwt();
				list1.display();
				break;

			case 8:
				list1.delend();
				list1.display();
				break;

			case 9:
				list1.reverse();
				list1.display();
				break;

			case 10:
				cout<<"Enter number of elements: ";
				cin>>x;
				for(i=0;i<x;i++)
			    list2.create();	
				list2.display();
				cout<<"\n\n";
				list1.Concat(list1.startptr,list2.startptr);
				list1.display();
				cout<<"\n\n";
				break;

			default:
				cout<<"Invalid choice entered";
				start==0;
				break;

		cout<<"\n";
		}
		cout<<"\n Pess 1 to Countinue : ";
		cin>>start;
	}
}
	

	



