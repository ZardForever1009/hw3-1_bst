// hw3-1: binary search tree implementation
// environment: Notepad++ 8.2.1(64bits X64)
// C++ type: C++ 14
// g++ type: g++ version 6.3.0
#include <iostream>
#include <string>

using namespace std;

// tree node initializtion
class Node{
public:
	int data=-1;
	Node* left=nullptr;
	Node* right=nullptr;
};

// check if data is invalid
bool invalid_data(string data){
	// check if non digit exist
	for(int i=0;i<data.size();i++){
		if(!isdigit(data[i]))return true;
		else;
	}
	// check if data overflow
	if(stoi(data)>100)return true;
	else return false;
}

// exist function (TRUE: exist)
bool node_exist(Node* root, string data){
	if(root==nullptr)return false; // impossible for data to store in the bst
	// start searching
	if(root->data==stoi(data))return true;
	if(root->data<stoi(data))return node_exist(root->right, data);
	if(root->data>stoi(data))return node_exist(root->left, data);
}

// insert function
void Insert(Node*& root, string data){
	// prevent invalid insert options
	if(invalid_data(data)){
		cout<<"Insert wrong data\n";
		return;
	}
	// root is nullptr
	if(root==nullptr){
		root=new Node();
		root->data=stoi(data);
		return;
	}
	// root is NOT nullptr && same data already exist
	if(node_exist(root, data)){
		cout<<"This data is in BST\n";
		return;
	}
	// root is NOT nullptr && No same data exist in bst
	// insert node to its position
	else{
		Node* restore_root=root;
		// go right
		if(stoi(data)>root->data){
			if(root->right==nullptr){ // create new node
				Node* new_node=new Node();
				new_node->data=stoi(data);
				root->right=new_node;
				return;
			}
			else{
				Insert(root->right, data);
			}
		}
		// go left
		else{
			if(root->left==nullptr){
				Node* new_node=new Node();
				new_node->data=stoi(data);
				root->left=new_node;
				return;
			}
			else{
				Insert(root->left, data);
			}
		}
		root=restore_root;
	}
	return;
}

// delete function
void Delete(Node*& root, string data){ 
	// prevent invalid insert options
	if(invalid_data(data)){
		cout<<"Delete wrong data\n";
		return;
	}
	// root is nullptr
	if(root==nullptr){
		cout<<"BST is empty\n";
		return;
	}
	// root is NOT nullptr && data not exist
	if(!node_exist(root, data)){
		cout<<"This data is not in BST\n";
		return;
	}
	// root is NOT nullptr && data exist in bst
	// delete node
	else{
		Node* restore_root=root;
		if(stoi(data)==root->data){
			// delete operation
			// NO CHILD
			if(root->left==nullptr&&root->right==nullptr){
				root->data=-1;
				root=nullptr;
			}
			// TWO CHILD
			// replace with right child desuccessor
			else if(root->left!=nullptr&&root->right!=nullptr){
				// find desccessor
				Node* min=root->right;
				while(min->left!=nullptr)min=min->left;
				// delete 
				int tmp=min->data;
				Delete(min, to_string(min->data));
				root->data=tmp;
			}
			// ONE CHILD
			else{
				// LEFT child not nullptr
				if(root->left!=nullptr){
					root->data=root->left->data;
					root->left=root->left->left;
					root->right=root->left->right;
					root->left=nullptr;
					delete root->left;
				}
				else{
					root->data=root->right->data;
					root->left=root->right->left;
					root->right=root->right->right;
					root->right=nullptr;
					delete root->right;
				}
			}
			root=restore_root;
			return;
		}
		// keep searching delete node
		if(stoi(data)>root->data)Delete(root->right, data); // Search right 
		if(stoi(data)<root->data)Delete(root->left, data); // Search left
	}
	return;
}

// height of tree
int Height(Node* root){
	
}

// print out tree by level order
void Print(Node* root){
	
}

// search given data
int Search(Node* root, string data){
	
}

// Number function
int Number(Node* root){
	int count=0;
	if(root==nullptr)return 0;
	count++;
	count+=Number(root->left);
	count+=Number(root->right);
	return count;
}

// combination of all instructions
void bst(){
	Node* root=nullptr;
	string action, data;
	while(cin>>action){
		if(action=="Insert"){
			cin>>data;
			Insert(root, data);
		}
		else if(action=="Delete"){
			cin>>data;
			Delete(root, data);
		}
		else if(action=="Height"){
			Height(root);
		}
		else if(action=="Print"){
			Print(root);
		}
		else if(action=="Search"){
			cin>>data;
			cout<<Search(root, data)<<endl;
		}
		else if(action=="Number"){
			cout<<Number(root)<<endl;
		}
		else{
			cout<<"Wrong instruction"<<endl;
		}
		cout<<root->data<<endl;
	}
	return;
}

int main(){
	
	/* Node* root=new Node();
	Node* tmp=new Node();
	root->data=25;
	tmp->data=50;
	root->right=tmp;
	cout<<root->right->data<<"/"<<tmp->data<<endl;
	Node* nn=tmp;
	delete tmp;
	tmp=nullptr;
	cout<<root->right->data<<"/"<<tmp->data<<endl; */
	bst();
	
	system("pause");
	return 0;
}
