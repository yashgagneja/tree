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

		// Algorithm
		// 1. Starting at root, find the deepest and rightmost node in binary tree and node which we want to delete.
		// 2. Replace the deepest rightmost node’s data with node to be deleted.
		// 3. Then delete the deepest rightmost node.

		void deleteDeepest(Node* root, Node* d_node){
			queue<Node*> q;
			q.push(root);
			// LEVEL ORDER TRAVERSAL FOR LAST NODE
			Node* temp;
			while(!q.empty()) {
				temp=q.front();
				q.pop();

				if(temp == d_node){
					temp=NULL;
					delete (d_node);
					return ;
				}
				if(temp->right){
					if(temp->right == d_node){
						temp->right = NULL;
						delete(d_node);
						return;
					}
					else 
						q.push(temp->right);
				}
				if(temp->left){
					if(temp->left == d_node){
						temp->left = NULL;
						delete(d_node);
						return;
					}
					else 
						q.push(temp->left);
				}
			}
		}

		// FUNCTION TO DELETE ELEMENT IN BINARY TREE
		Node* deletion (Node* root, int data){
			if(root == NULL)
				return NULL;

			if (root->left == NULL && root->right == NULL){
				if(root->data == data)
					return NULL;
				else
					return root;
			}

			queue<Node*> q;
			q.push(root);

			Node* temp;
			Node* key_node  = NULL;

			/* Do level order traversal to find deepest 
			node(temp) and node to be deleted (key_node)*/
			while(!q.empty()){
				temp = q.front();
				q.pop();

				if(temp->data == data)
					key_node = temp;

				if(temp->left)
					q.push(temp->left);

				if(temp->right)
					q.push(temp->right);
			}

			if(key_node != NULL){
				int x = temp->data;
				deleteDeepest(root, temp);
				key_node->data = x;
			}
			return root;
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

	cout << "Inorder traversal before deletion : "; 
    tree.inorder(root); 
  
    int key = 11; 
    root = tree.deletion(root, key); 
  
    cout << endl; 
    cout << "Inorder traversal after deletion : "; 
    tree.inorder(root); 
  
    return 0;   	
}