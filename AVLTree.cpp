#include "AVLTree.hpp"
#include "ZNode.hpp"
#include <stdlib.h>
#include <string>
using namespace std;

AVLTree::AVLTree(){
	root = NULL;
	AVLflag = false;
}
AVLTree::AVLTree(bool flag){
	root = NULL;
	AVLflag = flag;
        
}

//Getting identifier errors
ZNode AVLTree::*findZip(int z, ZNode *n){
	if(z == n->zip->zip){
		return n;
	}
	else if(z < n->zip){
		return (findZip(z, n->left));
	}
	else{
		return (findZip(z, n->right));
	}
}
/**
void AVLTree::addNode(Z_Obj *n, ZNode *r){
	if(n->zip < r->zip){
		if(r->left != NULL){
			return addNode(n, r->left);
		}
		else{
			r->left = ZNode(n);
		}
	}
	else if(n->zip > r->zip){
		if(r->right != NULL){
			return addNode(n, r->right);
		}
		else{
			r->right = ZNode(n);
		}
	}
}
void AVLTree::adjustBalances(ZNode *n){
    int difference = heightDifference(n);
    if (difference > 1)
    {
        if (heightDifference(n->left) > 0){
            n = rotateLeft(n);
        }
        else{
        	n = rotateRight(n);
        	n = rotateLeft(n);
        }
    }
    else if (difference < -1)
    {
        if (heightDifference(n->right) > 0){
        	n = rotateLeft(n);
        	n = rotateRight(n);
        }
        else{
            n = rotateRight(n);
        }
    }
}
ZNode AVLTree::*rotateRight(ZNode *n){
    ZNode *tmp;
    tmp = n->right;
    n->right = tmp->left;
    tmp->left = n;
    return tmp;
}
ZNode AVLTree::*rotateLeft(ZNode *n){
    ZNode *tmp;
    tmp = n->left;
    n->left = tmp->right;
    tmp->right = n;
    return tmp;
}
void AVLTree::printIO(ZNode *root){
    if (root == NULL){
        return;
}
    printIO(root->left);
    cout << root->zip << "  ";
    printIO(root->right);
}
void AVLTree::PrintPre(ZNode *root){
	 if (root == NULL){
	        return;
	 }
	    cout << root->zip << "  ";
	    PrintPre(root->left);
	    PrintPre(root->right);
}
void AVLTree::PrintPost(ZNode *root){
    if (root == NULL){
        return;
    }
    PrintPost(root ->left);
    PrintPost(root ->right);
    cout << root->zip << "  ";
}
int AVLTree::updateHeight(ZNode *n){
    int height = 0;
    if (n != NULL)
    {
        int left = height(n->left);
        int right = height(n->right);
        int total = max(left, right);
        height = total + 1;
    }
    return height;
}
int AVLTree::heightDifference(ZNode *n){
    return (updateHeight(n->left) - updateHeight(n->right));
}
*/