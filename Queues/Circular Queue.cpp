class MyCircularQueue {
    private:
    struct Node{
        Node* next;
        int val;
        Node(int n)
        {
            val=n;
            next=NULL;
        }
    };
    Node* head;
    Node* tail;
    int size;
    int capacity;
public:
    MyCircularQueue(int k) {
        head=NULL;
        tail=NULL;
        size=0;
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(isFull()){
            return false;
        }

        Node* temp=new Node(value);
        if(!head)
        {
            head=temp;
            tail=temp;
            tail->next=head;
            size++;
            return true;
        }
        else{
            tail->next=temp;
            tail=temp;
            tail->next=head;
            size++;
            return true;
        }

    }
    
    bool deQueue() {
        if(isEmpty())
        return false;
        if(size==1)
        {
        delete head;
        head=tail=NULL;
        size--;
        return true;
        }else
        {
        Node* temp=head;
        head=head->next;
        tail->next=head;
        delete temp;    
        size--;
        return true;
        } 
        
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        return head->val;
    }
    
    int Rear() {
        if(isEmpty())
        return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        if(size==0)
        return true;
        return false;
    }
    
    bool isFull() {
        if(size==capacity)
        return true;
        return false;
        
    }
};
