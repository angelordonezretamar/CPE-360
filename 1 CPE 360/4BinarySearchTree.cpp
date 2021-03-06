#include<iostream> 
using namespace std; 

class TreeChunk { 
public: 
  int value; 
  TreeChunk *left; 
  TreeChunk *right; 
  
  TreeChunk(){ 
    value = 0;
    left = right = NULL;
  }
};

class BST{ 
public:
  TreeChunk *root; 

  BST() { 
    root = NULL;
  }

  //1. Add values 
  void addValue(int key) {
    //check to see if the tree is empty! 
    //if it is, then make this value the root of the tree 
    if(root == NULL) { 
      root = new TreeChunk; 
      root->value = key; 
      return; 
    }

    //if you are here, your tree is not empty 
    //which means we have to go 'searching' for this value (key) 
    //if we fall off the tree in the process, we have found the right position!
    TreeChunk *fast, *slow; 
    fast = slow = root; 

    while(fast != NULL) { 
    	slow = fast; //set this to fast and let fast go ahead 
	
	if(fast->value == key) {
	       //duplicate! 
	       cout << "Sorry, not adding duplicates" << endl; 
       	       return; 	       
	} 
	else if(key < fast->value) { 
		//go left
		fast = fast->left; 
	}
	else { 
		fast = fast->right; 
	}
    }

    //now we check to see if fast is NULL 
    //that's good news: we have found a spot to add 'key' 
    //slow will have the address of the new 'parent' to be 
    if(fast == NULL) {
    	TreeChunk *temp = new TreeChunk; 
	temp->value = key; 

	if(key < slow->value) 
		slow->left = temp;
        else 
		slow->right = temp; 	
    }
  } 

  //2. Search for a value (key)
  void searchBST(int key, TreeChunk *start) { 
	if(start == NULL) {
	  cout << "Value not found in this tree" << endl; 
	}
	else {
        	if(key == start->value) { 
	   		cout << "Yes! Found it!!" << endl; 
		}
		else if(key > start->value) {
	   		 searchBST(key, start->right); 
		}
		else { 
	   		searchBST(key, start->left);
		}
	}
  }

  //3. Delete a value (key) 
  //4. Display contents: (a) in--, (b) pre--, (c) post-- order 
};


int main() 
{
  BST tree; 
  int choice, value; 
  //we'll jumpstart the tree with values (like in the slides) 
  //30, 15, 60, 7, 22, 45, 17, 27, 75 
  tree.addValue(30);
  tree.addValue(15); 
  tree.addValue(60);
  tree.addValue(7); 
  tree.addValue(22); 
  tree.addValue(45); 
  tree.addValue(17); 
  tree.addValue(27); 
  tree.addValue(75); 
 
  while(1) { 
  	cout << "Press 1 to add a new value" << endl; 
	cout << "Press 2 to search" << endl; 
	cout << "(other options coming soon)" << endl; 
	cin >> choice; 

	switch(choice) { 
	  case 1: cout << "What value did you want to add?" << endl; 
		  cin >> value;
		  tree.addValue(value); 
		  break; 

	  case 2: cout << "Search for what?" << endl; 
		  cin >> value;
		  tree.searchBST(value, tree.root);
		  break; 

	  default: cout << "Goodbye!" << endl; 
		  exit(1);  
	} 
  }
   
  

}
