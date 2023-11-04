class Solution{
   public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        vector<int> ans;
        for(int i=0;i<k;i++)
        {
            Node* head=arr[i];
            while(head)
            {
                ans.push_back(head->data);
                head=head->next;
            }
        }
        
        sort(ans.begin(),ans.end());
        for(auto it:ans)
        cout<<it<<" ";
        return NULL;
    }
};