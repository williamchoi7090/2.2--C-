#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Tree{
  int key;
  vector<Tree*>child;
};
Tree *General(int key){
  Tree *temp= new Tree;
  temp->key= key;
  return temp;
}
void Order(Tree*root){
  if (root== NULL)
  return;
  queue<Tree*> q;
  q.push(root);
  while (!q.empty()){
    int a= q.size();
    while (a> 0){
      Tree*p= q.front();
      q.pop();
      cout<< p->key << " ";
      for (int i= 0; i<p->child.size(); i++)
      q.push(p->child[i]);
      a--;
    }
    cout<< endl;
  }
}
int main(){
  Tree*root= General(1);
  (root->child).push_back(General(2));
  (root->child).push_back(General(2));
  (root->child[0]->child).push_back(General(3));
  (root->child[0]->child).push_back(General(3));
  (root->child[1]->child).push_back(General(3));
  (root->child[1]->child).push_back(General(3));
  Order(root);
  return 0;
}