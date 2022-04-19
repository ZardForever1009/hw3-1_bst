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

// Search function (TRUE: exist)
bool Search(Node* root, string data){
	// prevent invalid search options
	if(invalid_data(data)){
		cout<<"Search wrong data\n";
		return false;
	}
	if(root==nullptr)return false; // impossible for data to store in the bst
	// start searching
	if(root->data==stoi(data))return true;
	else{
		if(root->left!=nullptr)Search(root->left, data);
		if(root->right!=nullptr)Search(root->right, data);
	}
	return false;
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
	else if(Search(root, data)){
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
	
}

// height of tree
int Height(Node* root){
	
}

// print out tree by level order
void Print(Node* root){
	
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
			Search(root, data);
		}
		else if(action=="Number"){
			cout<<Number(root)<<endl;
		}
		else{
			cout<<"Wrong instruction"<<endl;
		}
	}
	return;
}

int main(){
	
	bst();
	
	system("pause");
	return 0;
}
