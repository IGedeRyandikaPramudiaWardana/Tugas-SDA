#include <iostream>
using namespace std;

class Node{
	public: 
		Node *left;
		Node *right;
	
		int key;
	
	Node(){
		left = right = NULL;
	}
};

class BST{
	public:
		Node *root;
		
		BST(){
			root = NULL;
		}
		
		Node *insertRecursive(int inputKey, Node *currentRoot){
			
			if(currentRoot == NULL){
				Node *newNode = new Node();
				newNode->key = inputKey;
				return newNode;
			}
			
			if(inputKey < currentRoot->key){
				currentRoot->left = insertRecursive(inputKey, currentRoot->left);
			}
			
			else if(inputKey > currentRoot->key){
				currentRoot->right = insertRecursive(inputKey, currentRoot->right);
			}
			
			return currentRoot;
		}
		
		
		void insert(int inputKey){
			root = insertRecursive(inputKey, root);
		}
		
		void preOrderTransversal(Node *currentNode){
			if(currentNode != NULL){
				cout << currentNode->key << " ";
				preOrderTransversal(currentNode->left);
				preOrderTransversal(currentNode->right);
			}
		}
		
		void postOrderTransversal(Node *currentNode){
			if(currentNode != NULL){
				//cout << currentNode->key << " ";
				postOrderTransversal(currentNode->right);
				postOrderTransversal(currentNode->left);
				cout <<  currentNode->key << " ";
			}
		}
		
		void inOrderTransversal(Node *currentNode){
			if(currentNode != NULL){
				inOrderTransversal(currentNode->left);
				cout << currentNode->key << " ";
				//inOrderTransversal(currentNode->left);
				//inOrderTransversal(currentNode->key);
				inOrderTransversal(currentNode->right);
			}
		}
		
		void reverseInOrderTransversal(Node *currentNode){
			if(currentNode != NULL){
				reverseInOrderTransversal(currentNode->right);
				cout << currentNode->key << " ";
				reverseInOrderTransversal(currentNode->left);
			}
		}
		
		void reversePreOrderTransversal(Node *currentNode){
			if(currentNode != NULL){
				cout << currentNode->key << " ";
				reversePreOrderTransversal(currentNode->right);
				reversePreOrderTransversal(currentNode->left);
			}
		}
		
		void reversePostOrderTransversal(Node *currentNode){
			if(currentNode != NULL){
				reversePostOrderTransversal(currentNode->right);
				reversePostOrderTransversal(currentNode->left);
				cout << currentNode->key << " ";
			}
		}
		
		
		void findMin(Node *currentNode){
			if(currentNode == NULL){
				cout << "Pohon Node kosong." << endl;
			}
			
			Node *temp = currentNode;
			while(temp->left != NULL){
				temp = temp->left;
			}
			
			cout << "Nilai Minimum: " << temp->key << endl;
		}
		
		void findMax(Node *currentNode){
			if(currentNode == NULL){
				cout << "Pohone Node kosong." << endl;
			}
			
			Node *temp = currentNode;
			while(temp->right != NULL){
				temp = temp->right;
			}
			
			cout << "Nilai Minimum: " << temp->key << endl;
		}
		
		void search(int findKey, Node *currentNode){
			if(currentNode ==  NULL){
				cout << "Pohon node kosong." << endl; 
			}
			
			//if(currentNode != NULL){
			if(currentNode->key == findKey){
				cout << "Node ditemukan." << endl;
			}
			
			if(findKey < currentNode->key){
				search(findKey, currentNode->left);
			} else{
				search(findKey, currentNode->right);
			}
		}	
			
		//}
		
		 void deleteNode(Node*& currentNode, int key) {
	        if (currentNode == NULL) {
	            cout << "Node tidak ditemukan." << endl;
	            return;
	        }
	
	        if (key < currentNode->key) {
	            deleteNode(currentNode->left, key);
	        } else if (key > currentNode->key) {
	            deleteNode(currentNode->right, key);
	        } else {
	            // Node ditemukan
	            if (currentNode->left == NULL) {
	                Node* tmp = currentNode->right;
	                delete currentNode;
	                currentNode = tmp;
	            } else if (currentNode->right == NULL) {
	                Node* tmp = currentNode->left;
	                delete currentNode;
	                currentNode = tmp;
	            } else {
	                // Node memiliki dua cabang
	                Node* tmp = currentNode->right;
	                while (tmp->left != NULL) {
	                    tmp = tmp->left;
	                }
	                currentNode->key = tmp->key;
	                deleteNode(currentNode->right, tmp->key); // Hapus penerus inorder
	            }
	        }
	    }
	
		// Fungsi untuk eksekusi program
		
		void Search(){
			int findKey;
			cout << "Masukkan node yang ingin dicari: ";
			cin >> findKey;
			search(findKey, root);
		}
		
		void preOrder(){
			cout << "Pre Order Transversal: ";
			
			preOrderTransversal(root);
			
			cout << endl;
		}
		
		void  postOrder(){
			cout << "Post Order Transversal: ";
			
			postOrderTransversal(root);
			
			cout << endl;
		}
		
		void inOrder(){
			cout << "In Order Transversal: ";
			
			inOrderTransversal(root);
			
			cout << endl;
		}
		
		void reverseInOrder(){
			cout << "Reverse In-Order Transversal: ";
			
			reverseInOrderTransversal(root);
			
			cout << endl;
		}
		
		void reversePreOrder(){
			cout << "Reverse Pre-Order Transversal: ";
			
			reversePreOrderTransversal(root);
			
			cout << endl;
		}
		
		void reversePostOrder(){
			cout << "Reverse Post-Order Transversal: ";
			
			reversePostOrderTransversal(root);
			
			cout << endl;
		}
		
		void min(){
			cout << endl;
			findMin(root);
		}
		
		void max(){
			findMax(root);
		}
		
		void deleteKey(int Key){
			deleteNode(root, Key);
		}
};


int main(int argc, char** argv){
	BST *bin1 = new BST();
	
	bin1->insert(6);
	bin1->insert(7);
	bin1->insert(4);
	bin1->insert(8);
	bin1->insert(5);
	bin1->insert(3);
	
	bin1->preOrder();
	bin1->postOrder();
	bin1->inOrder();
	bin1->reverseInOrder();
	
	
	bin1->min();
	bin1->max();
	
	bin1->Search();
	
	int deleteKey = 4;
	bin1->deleteKey(deleteKey);
	cout << "Setelah Menghapus Nilai: " << deleteKey << endl;
	bin1->inOrder();
	return 0;
}
