#include<bits/stdc++.h>
using namespace std;
vector<int> pre,post;
struct Node{
    int x;
    int y;
    int index;
    Node(int x,int y,int index) : x(x),y(y),index(index) {}
};
struct Tree{
    Node n;
    Tree* left;
    Tree* right;
};
bool cmp(Node n1,Node n2){
    if(n1.y==n2.y){
        return n1.x<n2.x;
    }
    return n1.y>n2.y;
}
void insert(Tree* parent,Tree* child){
    // 왼쪽 노드 설정
    if(parent->n.x>child->n.x){
        if(parent->left==NULL){
            parent->left=child;
        }else{
            insert(parent->left,child);
        }
    }else{
        // 오르쪽 노드 설정
        if(parent->right==NULL){
            parent->right=child;
        }else{
            insert(parent->right,child);
        }
    }
}
// 전위 순회
void preorder(Tree *t){
    if(t==NULL) return;
    pre.push_back(t->n.index);
    preorder(t->left);
    preorder(t->right);
}
// 후위 순회
void postorder(Tree *t){
    if(t==NULL) return;
    postorder(t->left);
    postorder(t->right);
    post.push_back(t->n.index);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node>nodes;
    
    // 이진트리 만들기
    for(int i=0;i<nodeinfo.size();i++){
        nodes.push_back(Node(nodeinfo[i][0],nodeinfo[i][1],i+1));    
    }
    
    sort(nodes.begin(),nodes.end(),cmp);
    
    Tree *root=(Tree*)malloc(sizeof(Tree));
    root->n=nodes[0];
    root->left=NULL;
    root->right=NULL;
    // 값을 변경하고 싶을때 포인터를 사용해야 함
    for(int i=1;i<nodes.size();i++){
        Tree *tmp=(Tree*)malloc(sizeof(Tree));
        tmp->n=nodes[i];
        tmp->left=NULL;
        tmp->right=NULL;
        insert(root,tmp);
    }
    
    preorder(root);
    postorder(root);
    
    answer.push_back(pre);
    answer.push_back(post);
    
    return answer;
}