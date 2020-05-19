#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
	Node(int x){
		data = x;
		left=right=NULL;
	}
};

class treefunc{
	public:
		void inorder(Node* temp){
			if (!temp)
				return;

			inorder(temp->left);
			cout<< temp->data << " ";
			inorder(temp->right);
		}

		void insert(Node* temp, int data){
			queue<Node*> q;
			q.push(temp);

			while(!q.empty()){
				Node* temp = q.front();
				q.pop();

				if (!temp->left){
					temp->left = new Node(data);
					break;
				} else
					q.push(temp->left);

				if (!temp->right){
					temp->right = new Node (data);
					break;
				} else
					q.push(temp->right);
			}
		}
 };
int main(){

	#ifndef ONLINE_JUDGE
  	freopen("C:/Users/Azhan/Desktop/input.txt", "r", stdin);
  	freopen("C:/Users/Azhan/Desktop/output.txt", "w", stdout);
  	#endif
 	
  	Node* root = new Node(10);
  	root->left = new Node(11);
  	root->left->left = new Node(7);
  	root->right = new Node(9);
  	root->right->left = new Node(15);
  	root->right->right = new Node(8);

  	treefunc tree;

  	cout << "Inorder before insertion : ";
  	tree.inorder (root);

  	int data = 12;
  	tree.insert(root,data);

  	cout<<endl << "Inorder after insertion : ";
  	tree.inorder(root);
   
 	return 0;   	
}
