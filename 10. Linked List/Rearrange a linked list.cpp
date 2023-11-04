// Time complexity - O(N)
// Space complexity- O(1)
class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       Node* FinalHead=head;
       Node* Ehead=NULL;
       Node* Etail=NULL;
       
       Node* Ohead=NULL;
       Node* Otail=NULL;
       
       int i=1;
       while(head)
       {
           if(i&1)
           {
               if(!Ohead)
               {
                    Ohead=head;
                    Otail=head;
               }
               else
               {
                   Otail->next=head;
                   Otail=head;
               }
           }
           else
           {
               if(!Ehead)
               {
                   Ehead=head;
                   Etail=head;
               }
               else
               {
                   Etail->next=head;
                   Etail=head;
               }
           }
           head=head->next;
           i++;
       }
       
       if(i-1>=2)
       {
           Otail->next=Ehead;
           Etail->next=NULL;
       }
      
    }
};
