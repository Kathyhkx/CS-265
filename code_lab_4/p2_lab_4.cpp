#include <iostream> // std::cout
#include <algorithm> // std::random_shuffle
#include <vector> // std::vector
#include <ctime> // std::time
#include <cstdlib> // std::rand, std::srand
using namespace std;

/*
 * * Node Declaration
 * */
struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;

/*
 * * Class Declaration
 * */
class BST
{
public:
    void insert(node *,node *);
    void display(node *, int);
    BST()
    {
        root = NULL;
    }
};

/* random generator function:*/
int myrandom (int i) { return std::rand()%i;}

int main () {
    std::srand ( unsigned ( std::time(0) ) );
    std::vector<int> myvector;
    clock_t start, end;
    
    int n;
    BST bst;
    node *temp;
    cout<<"ENter and integer";
    cin>>n;
    
    /* set some values:*/
    for (int i=0; i<n; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9
    
    /* using built-in random generator:*/
    std::random_shuffle ( myvector.begin(), myvector.end() );
    
    /* using myrandom:
     * std::random_shuffle ( myvector.begin(), myvector.end(), myrandom);*/
    
    /* print out content:*/
    start = clock();
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    {
        temp = new node;
        temp->info = *it;
        bst.insert(root, temp);
    }
    
    
    end = clock();
    // std::cout << '\n';
    cout << "The elapsed time for inserting random permutation into BST: ";
    cout << 1000*(end-start) /CLOCKS_PER_SEC << endl;
    
    return 0;
}

void BST::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->: ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<" ";
        }
        cout<<ptr->info;
        display(ptr->left, level+1);
        
    }
}

void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);
        }
        else
        {
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            
            return;
        }
    }
}