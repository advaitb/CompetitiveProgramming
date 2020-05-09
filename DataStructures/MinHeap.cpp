#include <iostream>

using namespace std;


class Heap{
  
  int *harr;
  int capacity;
  int heapsize;
  
  
  Heap(int size){
      
      harr = new int[size];
      capacity = size;
      heapsize  = 0;
  }
  
  ~Heap();
  
  int parent(int i){
      
      return (i-1)/2;
      
  }
  
  int leftchild(int i){
      
      return (2*i + 1)/2;
      
  }
  
  int rightchild(int i){
      
      return (2*i + 2)/2;
  } 
  
  void printHeap(){
      
      for(int i =0;i<capacity;i++){
          
          cout<<harr[i]<<' ';
          
      }
      
      cout<<endl;
  }
  
  void decreaseKey(int i, int new_val){ 
    
    harr[i] = new_val; 
    while (i != 0 && harr[parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[parent(i)]); 
       i = parent(i); 
    } 
 } 
  
  void swap(int *i, int *j){
      
      int temp = int *i;
      *i = *j;
      *j = temp;
     
      
  }
  
  void insert_element(int key){
      
      if(isFull()){
          
         cout<<"SORRY, HEAP IS FULL!"<<endl;
         return; 
      }
      
      heapsize++;
      int i =  heapsize-1;
      harr[i] = key;
      
      while(i !=0 && harr[parent(i)] > harr[i]){
          
          swap(&harr[parent(i)],&harr[i]);
          i = parent(i);
      }
     
  }
  
  int extractmin(){
      
      if(heapsize <= 0){
          return -1000000;
      }
      
      if(heapsize == 1){
          
          heapsize--;
          return harr[0];
           
      }
      
      harr[0] = harr[heap_size-1]; 
      heap_size--; 
      MinHeapify(0);
      
      
  }
  
  void MinHeapify(int i) { 
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l] < harr[i]) 
        smallest = l; 
    if (r < heap_size && harr[r] < harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        MinHeapify(smallest); 
    } 
 }
 
 void delete_element(int element){
     
    decreaseKey(i, -1000000); 
    extractMin(); 
} 
    
    
};




int main()
{
   //Push elemts using: insert_element
   //Decrease value of already inserted element using: decreaseKey
   //Delete element using: delete_element
   //Print Heap using: printHeap
   
   return 0;
}
