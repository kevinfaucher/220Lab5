#include "AVLTree.hpp"
#include "ZNode.hpp"
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int count = 0;

AVLTree::AVLTree(){
	root = NULL;
	AVLflag = false;
}
AVLTree::AVLTree(bool flag){
	root = NULL;
	AVLflag = flag;
        
}


ZNode* AVLTree::findZip(int z, ZNode *n){
    cout << "test call" << endl;
    cout << count;
    while (count < 5){
        count++;
        
        while (z != n->zip->zip){
            if(n->zip->zip > z){
                cout << "test value 1" << endl;
                return (findZip(z, n->left));
            }
            else if (n->zip->zip < z){
                cout << "test value 2" << endl;
                 return (findZip(z, n->right));
            }
            }
        cout << "end loop" << endl;
                }
    return n;
}
//          cout << "test val " << endl;
//	if(z == n->zip->zip){
//           
//           cout << "test val 1" << endl; 
//		return n;
//                
//	}
//	else if(n->zip->zip > z){
//            cout << "test val 2" << endl;
//		//return (findZip(z, n->left));
//            return n;
//	}
//	else {       cout << "test val 3" << endl;
//		//return (findZip(z, n->right));
//            return n;
//	}
//}

void AVLTree::addNode(Z_Obj *n, ZNode *r){
    if (r == NULL){
        root = new ZNode(n);
        cout << "Made new root with " << root->zip->zip << endl;
        return;
    }
    	if(n->zip < r->zip->zip){
		if(r->left != NULL){
			return addNode(n, r->left);
		}
		else{
			r->left = new ZNode(n);
                        r->left->parent = r;
		}
	}
	else if(n->zip > r->zip->zip){
		if(r->right != NULL){
			return addNode(n, r->right);
		}
		else{
			r->right = new ZNode(n);
                        r->right->parent = r;
		}
	}
}
void AVLTree::adjustBalances(ZNode *n){
    int difference = leftRightDiff(n);
    if (difference > 1)
    {
        if (leftRightDiff(n->left) > 1){
            n = rotateLeft(n);
        }
        else{
        	n = rotateRight(n);
        	n = rotateLeft(n);
        }
    }
    else if (difference < -1)
    {
        if (leftRightDiff(n->right) > 0){
        	n = rotateLeft(n);
        	n = rotateRight(n);
        }
        else{
            n = rotateRight(n);
        }
    }
}

ZNode* AVLTree::rotateRight(ZNode *n){
    ZNode *tmp;
    tmp = n->right;
    n->right = tmp->left;
    tmp->left = n;
    return tmp;
}
ZNode* AVLTree::rotateLeft(ZNode *n){
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

int AVLTree::newHeight(ZNode *n){
    int height = 0;
    if (n != NULL)
    {
        int left = height = int(n->left);
        int right = height = int(n->right);
        int total = max(left, right);
        height = total + 1;
    }
    return height;
}

int AVLTree::leftRightDiff(ZNode *n){
    return (newHeight(n->left) - newHeight(n->right));
}
