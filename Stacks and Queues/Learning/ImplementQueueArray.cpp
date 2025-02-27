// Implement Queue Using Array

#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        int arr[10], siz = 10, curSize=0, start=-1, end=-1;
        
        void push(int ele){
            if(curSize == siz){
                cout<<"Queue Overflow"<<"\n";
                return;
            }
            if(curSize == 0){
                start = 0;
                end = 0;
            }else{
                end = (end+1)%siz;
            }
            arr[end] = ele;
            curSize += 1;
        }
        
        void pop(){
           if(curSize == -1){
               cout<<"Queue Underflow"<<"\n";
               return;
           }
           int ele = arr[start];
           if(curSize == 0){
               start = -1;
               end = -1;
           }else{
               start = (start+1)%siz;
           }
           curSize -= 1;
           cout<<"Element Poped: "<<ele<<"\n";
        }
        
        void getTop(){
            if(curSize <= 0){
                cout<<"Queue is empty"<<"\n";
                return;
            }
            
            cout<<arr[start]<<"\n";
        }
        
        void size(){
            cout<<curSize<<"\n";
        }
};

int main()
{
    Queue queue;
    int n;
    int ele;

    while(true){
        cout<<"Choose the action to perform: "<<"\n"<<"1: Push"<<"\n"<<"2. Pop"<<"\n"<<"3. Top"<<"\n"<<"4. Size"<<"\n"<<"5. Quit"<<"\n";
        cout<<"Enter the action to be performed: "<<"\n";
        cin>>n;
        
        switch(n){
            case 1:
                cout<<"Enter the element to be inserted: ";
                cin>>ele;
                queue.push(ele);
                break;
            case 2:
                queue.pop();
                break;
            case 3:
                queue.getTop();
                break;
            case 4:
                queue.size();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default: 
                cout << "Invalid action. Please try again." << endl;
                
        }
    }
    return 0;
}
