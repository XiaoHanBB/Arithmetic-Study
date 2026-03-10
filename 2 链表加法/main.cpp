#include <iostream>

using namespace std;

typedef struct LinkNode{
	int data;
	LinkNode * next;
}Node;
void creatLinkList(Node *&head){
	int n;
	cin>>n;
	head=nullptr;
	for(int i=0;i<n;i++){
		Node *p=new Node;
		int data;
		cin>>data;
		p->data=data;
		p->next=head;
		head=p;
	}
}
Node * LinkAdd(const Node *h1,const Node *h2){
	Node * ans = nullptr;
	Node *pre = nullptr, *cur=nullptr;
	for(int sum,carry=0;h1!=nullptr||h2!=nullptr||carry!=0;h1=(h1==nullptr?nullptr:h1->next),h2=(h2==nullptr?nullptr:h2->next)){
		sum=(h1==nullptr?0:h1->data)+(h2==nullptr?0:h2->data)+carry;
		carry=sum/10;
		sum%=10;
		if(ans==nullptr){
			ans=new Node;
			ans->data=sum;
			ans->next=nullptr;
			pre=ans;
		}
		else{
			cur=new Node;
			cur->data=sum;
			cur->next=nullptr;
			pre->next=cur;
			pre=cur;
		}
	}
	return ans;
}
void printLink(const Node *h){
	const Node * p=h;
	while(p!=nullptr){
		cout<<p->data<<' ';
		p=p->next;
	}
}
int main(){
	Node *h1,*h2;
	creatLinkList(h1);
	creatLinkList(h2);
	Node * ans;
	ans=LinkAdd(h1,h2);
	printLink(h1);
	cout<<endl;
	printLink(h2);	
	cout<<endl;
	cout<<"相加等于："<<endl;
	printLink(ans);
	return 0; 
}
