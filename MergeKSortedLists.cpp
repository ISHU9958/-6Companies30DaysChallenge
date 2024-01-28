
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;

        for(auto &it:lists){
            if(it!=NULL)
                pq.push({it->val,it});
        }

        ListNode*dummy=new ListNode(-1);
        ListNode*temp=dummy;

        while(!pq.empty()){

            auto front=pq.top();
            pq.pop();

            temp->next=front.second;
            temp=temp->next;

            if(front.second->next){
                pq.push({front.second->next->val,front.second->next});
            }

        }

        return dummy->next;
    }
};
