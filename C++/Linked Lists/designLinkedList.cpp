#include <bits/stdc++.h>
using namespace std;

class Node{
public:
   int data;
   Node*next;
   Node(int val){  //constructor
    data = val;
    next = NULL;
   }
};


class MyLinkedList {
public:
      Node* head;
      Node* tail;
      int size;
    MyLinkedList() {
        
        head = tail = NULL;
        size = 0;
    }
    
    int get(int index) {
       if(index<0 || index>=size){
        return -1;
       }
       if(index == 0){
        return head->data;
       }
       if(index == size -1){
        return tail->data;
       }
        Node* temp = head;
        for(int i = 0;i<index;i++){
            temp = temp->next;
        }
        return temp->data;

        
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        if(size == 0)
        {                            //kahli hai toh aey wala case
          head = tail = newnode;
        }
        else{
        newnode->next = head;
        head = newnode;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);
         if(size == 0){    // agar khali hai toh ey wala case
            head =  tail = newnode;
        }else{
        tail->next = newnode;   //warna aey wala
        tail = newnode;
        }
       
        size++;
    }
    
    void addAtIndex(int index, int val) {
              //cases banrahe hai index ki value pe depend ho ke
    //casel:
     if(index<0 || index>size)
     {
        return;
     }
     if(index == 0) //case2: addAtHead karraha hai
     {
        addAtHead(val);
        return;
     }
     if(index == size){   //case3: addAtTail bolraha hai
        addAtTail(val);
        return;
     }
     Node* newnode = new Node(val);
     Node* temp = head;
     for(int i = 0;i<index-1;i++){
        temp = temp->next;
     }                           //index ki phele vali node pe pauch gaya 
     newnode->next =temp->next;        //newnode ko index vali node se connect kardiya
     temp->next = newnode;       //phele vali node ko newnode se connect kiya aur abb naya node add hogya apne index place pe
      size++;   
    }
    
    void deleteAtIndex(int index) {
    if(index<0 || index>=size)
     {
        return;
     }
     if(index == 0) //case2: delete at head
     {
        Node*temp = head;
        head = head->next;
        delete temp;
        if(size == 1) tail = NULL; //ek edge case;
     }
     else{  
          Node* temp = head;
          for(int i = 0;i<index-1;i++){
            temp=temp->next;
          }
        Node*remove = temp->next;        //deleting element to store kiya
          temp->next = temp->next->next; //temp->next ko deleting element ka next se connect kiya
          delete remove;                 // delete kiya
          if(index == size-1) tail = temp;   //tail ko adjust kiya
     }
        size--;
    }
    
    // Helper function to display the linked list
    void display() {
        Node* temp = head;
        cout << "List: ";
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        cout << "Size: " << size << endl;
    }
};

int main(){
    // Test Case from LeetCode Example
    MyLinkedList* obj = new MyLinkedList();
    
    cout << "Adding 1 at head:" << endl;
    obj->addAtHead(1);
    obj->display();
    
    cout << "\nAdding 3 at tail:" << endl;
    obj->addAtTail(3);
    obj->display();
    
    cout << "\nAdding 2 at index 1:" << endl;
    obj->addAtIndex(1, 2);
    obj->display();
    
    cout << "\nGetting value at index 1:" << endl;
    cout << "Value: " << obj->get(1) << endl;
    obj->display();
    
    cout << "\nDeleting at index 1:" << endl;
    obj->deleteAtIndex(1);
    obj->display();
    
    cout << "\nGetting value at index 1:" << endl;
    cout << "Value: " << obj->get(1) << endl;
    obj->display();
    
    delete obj;
    
    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */