#include<iostream>

using namespace std;

struct node{
    string bookname;
    int quantity;
    node *left;
    node *right;
};

typedef struct node snode;

snode* create_node(string book, int quantity){
    snode* newnode=new snode;
    newnode->bookname=book;
    newnode->quantity=quantity;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

snode* insertBST(snode* root, string book, int quantity){
    if(root==NULL){
        return create_node(book, quantity);
    }
    else if(book<root->bookname){
        root->left=insertBST(root->left,book, quantity);
    }
    else if(book>root->bookname){
        root->right=insertBST(root->right,book, quantity);
    }
    else{
        root->quantity+=quantity;
    }
    return root;
}

void inorder_traverse(snode *root){
    if(root==NULL){
        return;
    }
    inorder_traverse(root->left);
    cout<<"Book Name: "<<root->bookname<< " , Quantity: "<<root->quantity<<endl;
    inorder_traverse(root->right);
}

snode* updateQuantity(snode* root, string bookname, int newQuantity){
    if(root==NULL){
        cout<<"Book not found"<<endl;
    }
    else if(root->bookname==bookname){
        root->quantity=newQuantity;
        cout<<"Quantity updated - Name: "<<root->bookname<<" , New Quantity: "<< root->quantity<<endl;
    }
    else if(bookname<root->bookname){
        root->left=updateQuantity(root->left, bookname, newQuantity);
    }
    else if(bookname>root->bookname){
        root->right=updateQuantity(root->right, bookname, newQuantity);
    }
    return root;
}

snode* searchInBST(snode* root, string name_tobe_searched, string &task){
    if(root==NULL){ 
        if(task=="returnbook"){
            cout<<"Book not found in the library, adding it now"<<endl;
            root=insertBST(root, name_tobe_searched, 1);
            cout<<"Thank you for returning the book "<<name_tobe_searched<<endl;
            cout << "Note: The return period for the book is 1.5 months" << endl;
        }
        else{
            cout<<"Book not found"<<endl;
        }
    }
    else if(root->bookname==name_tobe_searched){
        cout<<"Book found - Name: "<<root->bookname <<" ,Quantity: "<<root->quantity<<endl;
        if(task=="issue"){
            int newQuantity=root->quantity-1;
            root=updateQuantity(root, name_tobe_searched, newQuantity); 
            cout<<"Thank you for issuing the book "<< name_tobe_searched<<endl;
            cout<<"Note: The return period for the book is 1.5 months"<<endl;
        }
        else if(task=="returnbook"){
            int newQuantity=root->quantity+1;
            root=updateQuantity(root, name_tobe_searched, newQuantity); 
            cout<<"Thank you for returning the book"<<endl;
        }
    }
    else if(root->bookname>name_tobe_searched){
        root->left=searchInBST(root->left, name_tobe_searched, task);
    }
    else if(root->bookname<name_tobe_searched){
        root->right=searchInBST(root->right,name_tobe_searched, task);
    }
    return root;
}

snode* inordersucc(node* root){
    snode* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

snode* deleteInBST(snode* root, string name_tobe_deleted){
    if(root==NULL){
        return root;
    }
    if(name_tobe_deleted<root->bookname){
        root->left=deleteInBST(root->left,name_tobe_deleted);
    }
    else if(name_tobe_deleted>root->bookname){
        root->right=deleteInBST(root->right,name_tobe_deleted);
    }
    else{
        //Case 1 & 2a
        if(root->left==NULL){
            snode* temp=root->right;
            delete(root);
            return temp;
        }
        //Case 2b
        else if(root->right==NULL){
            snode* temp=root->left;
            delete(root);
            return temp;
        }
        // Case 2: Node with two children, find the in-order successor
        snode* temp=inordersucc(root->right);

        // Copy the in-order successor's content to this node
        root->bookname=temp->bookname;

        // Delete the in-order successor
        root->right=deleteInBST(root->right, temp->bookname);
    }
    return root;
}

int main() {
    snode* root = NULL;
    cout<<"*******####### WELCOME TO E-LIBRARY #######********";

    string type; 
    int pwd_set_admin=12345; 
    string university_id="pass@123";

    while(true){
        cout<<"Who are you? - Admin OR User or exit to quit: ";
        cin>>type;

        if(type == "Admin"){
            cout<<"Enter password to login: ";
            int pwd_admin_entered, quantity;
            cin>>pwd_admin_entered;

            if(pwd_set_admin == pwd_admin_entered){
                cout<<"You now have access to E-Library Database" << endl;

                while(true){
                    cout<<"Enter 1 to select options and enter any other number to exit Admin: ";
                    int user_entry;
                    cin>>user_entry;

                    if(user_entry != 1){
                        break;
                    }

                    int choice;
                    cout<<"Options:\n 1. Add Book\n 2. Delete Book\n 3. Update Book\n 4. Display Books\n 5. Exit Admin" << endl;
                    cout<<"Enter your Option Preference: ";
                    cin>>choice;

                    switch(choice){
                        case 1:{
                            cout<<"Enter book name: ";
                            string name;
                            cin >>name;
                            cout<< "Enter book quantity: ";
                            cin>>quantity;
                            root=insertBST(root, name, quantity);
                            break;
                        }

                        case 2:{
                            if(root==NULL) {
                                cout<<"No books to delete. Library is empty" << endl;
                            }
                            else{
                                cout<<"Enter book name to delete: ";
                                string name;
                                cin>>name;
                                root=deleteInBST(root, name);
                                cout<<"Book: "<<name<<" deleted from the library"<<endl;
                            }
                            break;
                        }

                        case 3:{
                            if(root==NULL){
                                cout<<"No books to update. Library is empty" << endl;
                            }
                            else{
                                cout<<"Enter book name to update quantity: ";
                                string name;
                                cin>>name;
                                int newquantity;
                                cout<<"Enter new quantity: ";
                                cin>>newquantity;
                                root=updateQuantity(root, name, newquantity);
                            }
                            break;
                        }

                        case 4:{
                            if (root==NULL){
                                cout<<"No books added in the library" << endl;
                            }
                            else{
                                cout<<"Books in sorted order:" << endl;
                                inorder_traverse(root);
                            }
                            break;
                        }

                        case 5:{
                            break;
                        }
                    }
                }
            } else{
                cout<<"Invalid Password" << endl;
            }
        } 
        
        //User
        else if (type=="User"){
            cout<<"Enter valid university ID to access E-Library: ";
            string university_id_entered;
            cin>>university_id_entered;

            if(university_id_entered==university_id){
                cout<<"You have access to the E-Library"<<endl;

                while(true){
                    cout<<"Enter 1 to get Options and enter any other number to exit: ";
                    int opt_num;
                    cin>>opt_num;

                    if(opt_num!=1){
                        break;
                    }

                    int choice;
                    cout<<"Options:\n 1. Issue Book\n 2. Return Book\n 3. Exit" << endl;
                    cout<<"Enter your option preferences: ";
                    cin>>choice;

                    switch(choice){
                        case 1:{
                            cout<<"Enter the book name you want to issue: ";
                            string bookname_to_issue;
                            cin>>bookname_to_issue;

                            string issue = "issue";
                            root=searchInBST(root, bookname_to_issue, issue);
                            break;
                        }

                        case 2:{
                            cout<<"Enter book name to return: ";
                            string bookname_to_return;
                            cin>>bookname_to_return;

                            string returnbook = "returnbook";
                            root=searchInBST(root, bookname_to_return, returnbook);
                            break;
                        }

                        case 3:{
                            break;
                        }

                        default:{
                            cout<<"Invalid option number entered" << endl;
                            break;
                        }
                    }
                }
            } else{
                cout<<"Sorry, your request for accessing the e-library has been rejected due to the wrong password" << endl;
            }
        } else if (type=="exit") {
            break;
        } else {
            cout<<"Invalid choice."<<endl;
        }
    }

    return 0;
}
