// Problem statement: Implement a stack using an array.

// Note: Stack is a data structure that follows the Last In First Out (LIFO) rule.

#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
        int arr[10], top=-1;
        
        void push(int ele){
            if(top==9){
                cout<<"Stack Overflow"<<"\n";
                return;
            }
            top = top+1;
            arr[top] = ele;
        }
        
        void pop(){
            if(top==-1){
                cout<<"Stack Underflow"<<"\n";
                return;
            }
            int ele = arr[top];
            top = top-1;
            cout<<ele<<"\n";
        }
        
        void getTop(){
            if(top==-1){
                cout<<"Stack is empty"<<"\n";
                return;
            };
            cout<<arr[top]<<"\n";
        }
        
        void size(){
            cout<<top+1<<"\n";
        }
};

int main()
{
    Stack stack;
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
                stack.push(ele);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.getTop();
                break;
            case 4:
                stack.size();
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
