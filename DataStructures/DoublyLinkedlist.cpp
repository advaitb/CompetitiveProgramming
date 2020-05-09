#include <iostream>

using namespace std;


class Node{
  
  public:
  Node *next;
  Node *previous;
  int data;
    
};

class Linkedlist{
    
    public:
    
    Node *head;
    Node *tail;
    int length;
    
    Linkedlist(){
        
        this->head = NULL;
        this->tail = NULL;
        this->length = 0;
    }
    
    //~Linkedlist();
    
    void addFirstNode(int data){
        
        Node *node = new Node();
        node->data = data;
        node->next  = this->head;
        node->previous = this->head;
        this->head = node;
        this->tail = node;
        this->length++;
    }
    
    void addNodeLast(int data){
        
        if(this->length == 0){
            addFirstNode(data);
        }
        
        else{
            
            Node *node = new Node();
            node->data = data;
            node->previous = this->tail;
            this->tail->next=node;
            this->tail=node;
            node->next = NULL;
            this->length++;
            
        }
    }
    
    
    void printNodes(){
        
        if(this->head == NULL){
            cout<<"Linkedlist is empty!"<<endl;
        }
        
        else{
        
        Node *temp = this->head;
        //cout<<temp->data<<endl;
        
        for(int i=0;i<this->length;i++){
            
            cout<<temp->data<<"->";
            temp = temp->next;
            
        }
        cout<<"NULL";
 
       }
    }
    

    void addNodeInter(int data, int pos){
        
        if(this->length == 0){
            cout<<"Linkedlist is empty, redirecting to addFirstNode()"<<endl;
            addFirstNode(data);
            
        }
        
        else if(pos > this->length-1){
            cout<<"Adding to the end of the list!"<<endl;
            addNodeLast(data);
        }
        
        else if(pos == 0){
            
            Node *node = new Node();
            node->previous = NULL;
            node->next = this->head;
            this->head->previous = node;
            node->data = data;
            this->head = node;
            this->length++;
        }
        
        else{
            Node *node = new Node();
            node->data = data;
            
            Node *temp = this->head;
            
            for(int i = 0;i<pos-1;i++){
                
                temp = temp->next;
            }
            
            Node *temp1 = temp->next;
            temp->next = node;
            node->previous = temp;
            node->next = temp1;
            temp1->previous = node;
            this->length++;
            
        }
        
        
        
    }
    
    int deleteNode(int pos){
        
        int delnode = 0;
        
        if(pos>this->length-1){
            
            cout<<"Postion invalid!"<<endl;
            return -100000000;
        }
        
        else if(pos == 0){
            delnode = this->head->data;
            this->head=this->head->next;
            this->head->previous=NULL;
            this->length--;
            
        }
        
        else if(pos == this->length-1){
            
            Node *temp = this->head;
            
            for(int i = 0;i<pos-1;i++){
                
                temp = temp->next;
            }
            delnode = temp->next->data;
            this->tail = temp;
            temp->next = NULL;
            this->length--;
            
        }
        
        else{
            
            Node *temp = this->head;
            
            for(int i = 0;i<pos-1;i++){
                
                temp = temp->next;
            }
            
            delnode = temp->next->data;
            
            temp->next = temp->next->next;
            temp->next->previous=temp;
            this->length--;
            
        }
        
        return delnode;
    }
   
    
};

int main()
{
    
    Linkedlist l;
    
    l.addFirstNode(3);
    l.addNodeLast(6);
    l.addNodeLast(8);
    l.addNodeInter(9,2);
    l.printNodes();
   
   return 0;
}