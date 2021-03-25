#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		Node* nxt;
};

class list: public Node{
	
	public:
	Node *startptr, *temp;
		list(){
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
			newnode->nxt=NULL;
			if(startptr==NULL)
			{
				startptr=newnode;
				temp=newnode;
			}
			else
			{
				temp->nxt=newnode;
				temp=newnode;
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
					cout<<temp->data<<"->";
					temp = temp->nxt;
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
			newnode->nxt = NULL;
			newnode->nxt = startptr;
			startptr = newnode;
			cout<<" Data Added";
			cout<<"\n";
	

		}
		
		void insrtend(){
		cout<<"\n";

			int Element;
			Node * newnode = new Node;
			
				cout<<"\n Enter Data : ";
			    cin>>Element;
			    newnode->data = Element;
			    newnode->nxt = NULL;
			    temp = startptr;
			    while(temp->nxt != NULL){
				     temp = temp->nxt;
			    }
			    temp->nxt = newnode;
				
			
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
			    newnode->nxt = NULL;
			    temp = startptr;
			    while(i != (n-1)){
				     temp = temp->nxt;
				     i++;
			    }
			    newnode->nxt = temp->nxt;
			    temp->nxt = newnode;
			}
			cout<<" Data Added";
			cout<<"\n";
		}
		
		void delsrt(){
		cout<<"\n";

			temp = startptr;
			startptr = temp->nxt;
			delete(temp);
			cout<<" Data Deleted";
			cout<<"\n";

		}
		
		void delend(){
		cout<<"\n";

			Node *temp2;
			temp = startptr;
			while(temp->nxt->nxt != NULL){
				temp=temp->nxt;
			}
			temp2 = temp->nxt;
			temp->nxt = NULL;
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
				temp = temp->nxt;
			}
			temp3 = temp->nxt;
			temp->nxt = temp3->nxt;
			delete(temp3);
			cout<<" Data Deleted";
			cout<<"\n";

		}
		void reverse(){
		cout<<"\n";
		

			Node * forward,* curr,* back;
			curr=startptr;
			back=NULL;
			forward=NULL;
			while(curr!=NULL)
			{
				forward=curr->nxt;
				curr->nxt=back;
				back=curr;
				curr=forward;
				
				
			}
			startptr=back;
			cout<<"\n";
		}

		
		void Concat(Node *a,Node *b)
		{
			if( a != NULL && b!= NULL )
    		{
        		if (a->nxt == NULL)
            		a->nxt = b;
        		else
            		Concat(a->nxt,b);
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
	list list1,list2;
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
		cout<<"\n9. Reverse the list";
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
				case 10:cout<<"Enter number of elements: ";
				cin>>x;
				for(i=0;i<x;i++)
			    list2.create();	

					list2.display();
				list1.Concat(list1.startptr,list2.startptr);
				list1.display();
				break;
			default:
				cout<<"Invalid choice entered";
				break;
		cout<<"\n";
		}
		cout<<"\n Pess 1 to Countinue : ";
		cin>>start;
	}
}
	

	



