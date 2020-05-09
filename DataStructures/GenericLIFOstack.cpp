#include <iostream>

using namespace std;

//Generic LIFO Stack using templates
template <class T>
class Stack{
    
  public:
  
  T *arr;
  int capacity;
  int top;
  
  
  Stack(int size){
      
      arr = new T[size];
      capacity = size;
      top = -1;
  }

  bool isEmpty(){
      
      return(top==-1);
  }
  
  bool isFull(){
      
      return(top==capacity-1);
  }
  
  T peek(){
      
      return arr[top];
  }
    
  void insertelement(T element){
      
      if (isFull()){
          
          cout<<"SORRY, THE STACK IS FULL!"<<endl;
          return;
      }
      
      arr[++top] = element;
  }
  
  T popelement(){
      
      int element;
      
      if(isEmpty()){
          cout<<"SORRY, THE STACK IS EMPTY"<<endl;
    
      }
      else{
         
         element = arr[top];
         arr[top] = 0;
         top--;
         return element;
  }
    
  }
  
  void printStack(){
      
      for(int i = 0;i<capacity;i++){
          cout<<arr[i]<<' ';
      }
      cout<<endl;
  }
};




int main()
{
    
    Stack<int> s(5);
    s.insertelement(5);
    s.insertelement(6);
    s.printStack();
    int k = s.popelement();
    s.printStack();
    
   return 0;
}