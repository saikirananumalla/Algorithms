#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	int height;
};

Node* newnode(int val){
	Node* temp=new Node;
	temp->data=val;
	temp->left=nullptr;
	temp->right=nullptr;
	temp->height=1;
	return temp;
}

class tree{
	Node* root;
public:
	tree(){root= nullptr;}
	void preorder(){
		preorder(root);
	}
	void preorder(Node* p){
		if(p){
			cout<<p->data<<" ";
			preorder(p->left);
			preorder(p->right);
		}
	}
	void insert(int val){
		if(!root)root=insert(root,val);
		else insert(root,val);
	}

	int nodeheight(Node* p){
		int hl=(p && p->left)?p->left->height:0;
		int hr=(p && p->right)?p->right->height:0;
		return max(hl,hr)+1;
	}

	int balfact(Node* p){
		int hl=(p && p->left)?p->left->height:0;
		int hr=(p && p->right)?p->right->height:0;
		return hl-hr;
	}
	Node* LLrotation(Node* p){
		Node* pl=p->left;
		Node* plr=pl->right;

		pl->right=p;
		p->left=plr;

		p->height=nodeheight(p);
		pl->height=nodeheight(pl);

		if(p==root)root=pl;
		return pl;
	}

	Node* LRrotation(Node* p){
		Node* pl = p->left;
    	Node* plr = pl->right;
 
    	pl->right = plr->left;
    	p->left = plr->right;
 
   		plr->left = pl;
    	plr->right = p;
 
    	// Update height
    	pl->height = nodeheight(pl);
    	p->height = nodeheight(p);
    	plr->height = nodeheight(plr);
 
    	// Update root
    	if (p == root){
        	root = plr;
    	}
    	return plr;
	}

	Node* RLrotation(Node* p){
	    Node* pr = p->right;
	    Node* prl = pr->left;
	 
	    pr->left = prl->right;
	    p->right = prl->left;
	 
	    prl->right = pr;
	    prl->left = p;
	 
	    // Update height
	    pr->height = nodeheight(pr);
	    p->height = nodeheight(p);
	    prl->height = nodeheight(prl);
	 
	    // Update root
	    if (root == p){
	        root = prl;
	    }
	    return prl;
	}

	Node* RRrotation(Node* p){
		Node* pr=p->right;
		Node* prl=pr->left;

		pr->left=p;
		p->right=prl;

		p->height=nodeheight(p);
		pr->height=nodeheight(pr);

		if(root==p)root=pr;
		return pr;
	}

	Node* insert(Node* p , int val){
		if(p==nullptr){
			p=newnode(val);
			return p;
		}
		else{
			if(val>=p->data)p->right=insert(p->right,val);
			else p->left=insert(p->left,val);
		}
		p->height=nodeheight(p);

		if(balfact(p)==2 && balfact(p->left)==1) return LLrotation(p);
		else if(balfact(p)==2 && balfact(p->left)==-1)return LRrotation(p);
		else if(balfact(p)==-2 && balfact(p->right)==1)return RLrotation(p);
		else if(balfact(p)==-2 && balfact(p->right)==-1)return RRrotation(p);

		return p;
	}
};

int main(){
	int a[]={50,30,20,40,45,60};
	tree t;
	for(auto i:a){
		t.insert(i);
	}
	t.preorder();
	return 0;
}