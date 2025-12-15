struct Node{
    int data;
    Node* next;
    Node(int n){
        data = n;
        next = nullptr;
    }
};

void insertAtTail(Node*& head, Node*& tail, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
        head = tail = newNode;
        return;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtHead(Node*& head, int val){
    Node* newNode = new Node(val);
    newNode-> next = head;
    head = newNode;
}

void insertAtTailWithoutHead(Node*& head, int val){
    Node* newNode = new Node(val);
    if(!head){
        head = newNode;
    }
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* reverse(Node*& head){
    Node* cur = head;
    Node* next = nullptr;
    Node* prev = nullptr;
    while(cur != nullptr){
        next = cur->next;
        cur->next = prev;

        prev = cur;
        cur = next;
    }
}


int main(){

}