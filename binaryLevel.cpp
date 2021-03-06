#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <assert.h>
#include <initializer_list>
#include <utility>
#include <stack>
using namespace std;

struct node
{
	int n; // value of node 
	struct node *left; // left subtree 
	struct node *right; // right subtree 
	struct node *level; // level pointer (node “to the right”) 
};

void linkSameLevel(struct node *t) {
	if (t->right == 0 && t->left == 0) {
		cout << endl;
		cout << "for this will be end function " << t->n << endl;
		return;
	}
	if (t->level == 0) {
		cout << endl;
		cout << "level 0" << endl;
		if (t->left != 0) {
			t->left->level = t->right;
			cout << "current function argument:  " << t->n << endl;
			if (t->left->level != 0)cout << "for left node we set level " << t->left->n << ": " << t->left->level->n << endl;
			linkSameLevel(t->left);
		}
		if (t->right != 0) {
			t->right->level = 0;
			cout << endl;
			cout << "current function argument: " << t->n << endl;
			if (t->right->level != 0)cout << "for right node we set level " << t->right->n << ": " << t->right->level->n << endl;
			linkSameLevel(t->right);
		}

	}
	else {
		cout << endl;
		cout << "for the level that not 0" << endl;
		if (t->left != 0) {
			cout << "current function argument: " << t->n << endl;
			if (t->right != 0) {
				t->left->level = t->right;
			}
			else if (t->level->left != 0) {
				t->left->level = t->level->left;
			}
			else if (t->level->right != 0) {
				t->left->level = t->level->right;
			}
			else t->left->level = 0;
			if (t->left->level != 0) cout << "for the left node we set level " << t->left->n << ": " << t->left->level->n << endl;
			linkSameLevel(t->left);
		}

		if (t->right != 0) {
			cout << "current function argument: " << t->n << endl;
			if (t->level->left != 0) {
				t->right->level = t->level->left;
			}
			else if (t->level->right != 0) {
				t->right->level = t->level->right;
			}
			else t->right->level = 0;
			if (t->right->level != 0)cout << "for the right node we set level " << t->right->n << ": " << t->right->level->n << endl;
			linkSameLevel(t->right);
		}
	}
}



int main() {

	node * head = new node();
	head->n = 0;
	node * leftn = new node();
	leftn->n = 1;
	node * rightn = new node();
	rightn->n = 2;
	node * ll = new node();
	ll->n = 3;
	node * rr = new node();
	rr->n = 4;
	node * lll = new node();
	lll->n = 5;
	node * llr = new node();
	llr->n = 6;
	node * rrl = new node();
	rrl->n = 7;

	head->level = 0;
	head->left = leftn;
	head->left->level = 0;

	head->right = rightn;
	head->right->level = 0;

	leftn->level = 0;
	leftn->left = ll;
	leftn->right = 0;

	rightn->level = 0;
	rightn->left = 0;
	rightn->right = rr;

	ll->level = 0;
	ll->left = lll;
	ll->right = llr;

	rr->level = 0;
	rr->left = rrl;
	rr->right = 0;

	lll->level = 0;
	lll->left = 0;
	lll->right = 0;

	llr->level = 0;
	llr->left = 0;
	llr->right = 0;

	rrl->level = 0;
	rrl->left = 0;
	rrl->right = 0;

	linkSameLevel(head);

	system("pause");
	return 0;
}