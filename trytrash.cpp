#include <iostream>
using namespace std;
struct node
{
	/* data */
	public:
	int data;
	struct node * left=NULL;
	struct node* right=NULL;
	node(){
		this->data=data;
		this->left=left;
		this->right=right;
	}

};
struct node* bst{

	public:
	struct node* newnode=new node();
	/*bst(int data,struct node* left,struct node* right){
		newnode->data=data;
		newnode->left=left;
		newnode->right=right;

	}*/
	static int height(struct node* Node){
		if(Node==NULL){
			return 0;
		}
		int left=height(Node->left);
		int right=height(Node->right);
		return max(left,right)+1;
	}

	

	void printlevel(struct node* Node,int level){
		if(Node==NULL){
			return;
		}
		else if(level==0){
			cout<<Node->data<<endl;

		}
		else{
			printlevel(Node->left,level-1);
			printlevel(Node->right,level-1);
		}
	}
	void printbfs(struct node* Node){
		
		int h=height(Node);
		for(int i=0;i<=h;i++){
			printlevel(Node,i);
		}
	}
  	void insert(struct node* node1){
    	if (newnode== NULL) {
      	newnode = node1;
      	cout << "Value Inserted as root node!" << endl;
    } else {
      struct node * temp = newnode;
      while (temp!= NULL) {
        if (node1->data == temp->data) {
          cout << "Value Already exist," <<
            "Insert another data!" << endl;
          return;
        } else if ((node1->data< temp ->data) && (temp -> left == NULL)) {
          temp -> left = node1;
          cout << "Value Inserted to the left!" << endl;
          break;
        } else if (node1 -> data < temp -> data) {
          temp = temp -> left;
        } else if ((node1 -> data > temp -> data) && (temp -> right == NULL)) {
          temp -> right = node1;
          cout << "Value Inserted to the right!" << endl;
          break;
        } else {
          temp = temp -> right;
        }
      }
    }
  }
  	
		


};

int main(){
	bst obj;
	struct node* newnode=new node();
	int n;
	cin>>n;
	newnode->data=n;

	obj.insert(newnode);




	return 0;
}

