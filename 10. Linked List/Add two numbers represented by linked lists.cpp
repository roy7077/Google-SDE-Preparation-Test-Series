
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node* reverse(Node* root)
    {
        //base case
        if(root==NULL)
        return NULL;
        
        if(root->next==NULL)
        return root;
        
        //recursive calls
        Node* temp=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        return temp;
    }
    
    void print(Node* head)
    {
        while(head)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // first=reverse(first);
        // second=reverse(second);
        
        Node* i=reverse(first);
        Node* j=reverse(second);
        
        // print(i);
        // print(j);
        
        Node* head=NULL;
        Node* tail=NULL;
        int c=0;
        while(i and j)
        {
            int sum=c+(i->data)+(j->data);
            int first=sum/10;
            int last=sum%10;
            c=first;
            
            Node* newnode=new Node(last);
            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            i=i->next;
            j=j->next;
        }
        
        //print(head);
        while(i)
        {
            int sum=c+i->data;
            int first=sum/10;
            int last=sum%10;
            c=first;
            
            Node* newnode=new Node(last);
            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            i=i->next;
        }
        
        while(j)
        {
            int sum=c+j->data;
            int first=sum/10;
            int last=sum%10;
            c=first;
            
            Node* newnode=new Node(last);
            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            j=j->next;
        }
        
        if(c)
        {
            Node* newnode=new Node(c);
            tail->next=newnode;
            tail=newnode;
        }
        
        head=reverse(head);
        return head;
    }
};