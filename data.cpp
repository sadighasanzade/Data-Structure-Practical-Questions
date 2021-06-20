/* cixa bilecek suallar:
1) linked listde  n-ci elementden sonra x elementini elave eden funksiya yazin
    -butun caseleri nezere alin 
    -argument kimi int x, int n, *node r alin
2) Linked listde x elementinden sonra t elementini elave edin
    -butun caseleri ehate edin
    -argument kimi int x, int t,*node root alin
3)Linked listde qarisiq formada verilmis ededleri artan sira ile duzun (*advanced)
    -argument kimi *node root alin

4) (3+4)*5-12*2+(10+4)/7 ifadesini postfix ve prefixe cevirin

5)stackda n-ci elementi silen funksiya yazin 
    -butun caseler nezere alinsin 

6)stackda x elementinin olub olmadigin yoxlayan funksiya yazin
    -varsa 1 yoxdursa 0 return edin

7)Queue de n-ci elementi silin
    -butun caseler nezere alinmalidir
    
8)Queue de olan butun elementlerin ededi ortasini tapin

9)Queue'nin ilk elementini silin

10)verilmis tree nin binomial tree olub olmadigin yoxlayan funksiya tertib edin
    -eledirse 1 deyilse 0 qaytarin

11) tree-nin sag ve sol qolunun uzunluqlarini tapin print eden void funksiya yazin
*/
#include<iostream>
#include<cstdlib>
using namespace std;

//creating struct for linked list

struct Node {
    int data;
    Node *next;
};


void PrintAll(Node * r){
    Node * iter;
    iter=r;
    while(iter!=NULL){
        cout<<iter->data<<"  ";
        iter=iter->next;

    }
    cout<<endl;
}

//question 1
Node * addByIndex(int x, int n, Node * r){
    Node * iter=r;
    Node * temp;
    int counter=1;

    while(counter<n && iter->next != NULL){
        iter=iter->next;
        counter++;

    }
    if (iter->next==NULL){
        temp =(Node *) malloc(sizeof(Node));
        temp->data=x;
        iter->next=temp;
        temp->next=NULL;
        cout<<"added to end"<<endl;
        return r;

        
    }
    if(r==NULL || n==0){
        //adding to start
        temp =(Node *) malloc(sizeof(Node));
        temp->data=x;
        temp->next=r;
        if(r=NULL){
        r=temp;
        r->next=NULL;
        }
        else{
            temp->next=r;
            r=temp;
        }
        
        cout<<"added to start"<<endl;
        return r;
    }
    temp =(Node *) malloc(sizeof(Node));
    temp->data=x;
    temp->next=iter->next;
    iter->next=temp;
    
    cout<<"added to spesific index"<<endl;
    return r;
    
  }

  //question 2

Node * addAfterNum(Node * r, int x, int t){
    Node * iter=r;
    Node * temp;
    

    while(iter != NULL && iter->data!=x){
        iter=iter->next;
    }
    if(iter== NULL){
        cout<<"element could not be found"<<endl;
        return r;
    }else{
        temp =(Node *) malloc(sizeof(Node));
        temp->data=t;
        temp->next=iter->next;
        iter->next=temp;
        return r;

    }

}
//question 3

//helpful function for q3
Node * addAsc(Node * r, int x){
    if(r==NULL){
        r=(Node*)malloc(sizeof(Node));
        r->next=NULL;
        r->data=x;
        return r;
    }
    if( x < r->data){
        Node *temp = (Node*)malloc(sizeof(Node));
        temp->data=x;
        temp->next=r;
       
        return temp;
    }
     Node * iter=r;
     while(iter->next!=NULL && iter->next->data < x){
         iter=iter->next;

     }
     Node* temp= (Node*)malloc(sizeof(Node));
     temp->next=iter->next;
     iter->next=temp;
     temp->data=x;
     return r;

}
Node * sortList(Node * r){
    Node* newRoot=NULL;
    Node* iter= r;
    while(iter!=NULL){
        newRoot=addAsc(newRoot,iter->data);
        iter=iter->next;
    }
    return newRoot;
}
int main(){
    //testing all function in the main part

    Node * root ;
    //question 1 test part
    root=addByIndex(5,0,root);
    root=addByIndex(2,3,root);
    root=addByIndex(7,1,root);
    PrintAll(root);
    //question 2 test part
    root=addAfterNum(root,12,1);
    root=addAfterNum(root,7,4);
    PrintAll(root);
    root=sortList(root);
    PrintAll(root);
 
    return 0;
}