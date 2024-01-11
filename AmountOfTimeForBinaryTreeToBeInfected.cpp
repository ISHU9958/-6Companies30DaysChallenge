
#define Node TreeNode
class Solution {

    Node*search(Node*root,int start){
        if(root==NULL) return NULL;

        if(root->val==start) return root;

        Node*left=search(root->left,start);
        if(left!=NULL) return left;
        Node*right=search(root->right,start);

        if(right!=NULL) return right;
        return NULL;
    }

    void makeparent(Node*root,auto &parent){
        if(root==NULL) return ;

        if(root->left) parent[root->left]=root;
        if(root->right) parent[root->right]=root;

        makeparent(root->left,parent);
        makeparent(root->right,parent);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        
        // search for the starting node
        Node*begin=search(root,start);
        
        // step 2: apply bfs
        // for bfs i want to acess the parent
        // store the parent of each node

        map<Node*,Node*>parent;
        parent[root]=NULL;

        makeparent(root,parent);

        // now apply bfs
        map<Node*,bool>visited;
        queue<pair<Node*,int>>q;
        q.push({begin,0});
        
        int ans=-1;

        while(!q.empty()){

            Node*curr=q.front().first;
            int t=q.front().second;
            ans=t;
            visited[curr]=1;
            q.pop();

            if(curr->left && !visited[curr->left]){
                visited[curr->left]=1;
                q.push({curr->left,t+1});
            }
            if(curr->right && !visited[curr->right]){
                visited[curr->right]=1;
                q.push({curr->right,t+1});
            }
            if(parent[curr]!=NULL && !visited[parent[curr]]){
                visited[parent[curr]]=1;
                q.push({parent[curr],t+1});
            }

        }
        return ans;

    }
};
