// =========================================================
//HW#: HW4 BST
//Your name: Thomas Gorney
//Complier:  g++
//File type: implementation file binstree.cpp
//================================================================

using namespace std;
#include <iostream>
#include "binstree.h"

// constructor  initializes Root
BST::BST()
{
  Root = NULL;   // This is an empty tree
}

// destructor must completely destroy the tree
BST::~BST()
{
  dtraverse(Root); // traverse to delete all vertices in post order
  Root = NULL;    
}
// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAM:   V is a pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
  if (V != NULL)
    {
      dtraverse(V->Left);         // visit left sub tree of V
      dtraverse(V->Right);       //  visit right sub tree of V
      delete V;                  //  deletes V
    }
}

// PURPOSE: Show elements in IN order traversal from the Root
void BST::Display()
{
  cout << "Elements in the IN order: " << endl;
  INorderTraversal(Root);  // start in-order traversal from the root
}
// PURPOSE: Does IN order traversal from V recursively
// PARAM: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
  if (V != NULL)
    {
      	INorderTraversal(V->Left);  	  //traverse left sub-tree of V recursively
      	cout << V->Elem << endl;  	  	  //display V's element and do endl;
      	INorderTraversal(V->Right);  	  //traverse right sub-tree of V recursively
    }
}

// PURPOSE: Searches for an element in PRE-order traversal
// This is the same as Depth First Traversal
bool BST::Search(elem_t K)
{
  PREorderSearch(Root, K);  // start pre-order traversal from the root
}
// PURPOSE: Does PRE order search from V recursively
// PARAM: V is the pointer to the vertex to be visited now
bool BST::PREorderSearch(Vertex *V, elem_t K)
{
    if (V != NULL)
      {
        if (K == V->Elem) return true;
        else if (K < V->Elem )
        	{PREorderSearch(V->Left, K);}	//Call search recursively left
	  else
	  	  {PREorderSearch(V->Right, K);}	//Call search recuyrsively right
      }
    else return false;
}

// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAM: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
// to demonstrate the algorithm that is in the notes
//    - smaller than the current -> go to the left
//    - bigger than the current  -> go to the right
//    - cannot go any further    -> add it there
void BST::InsertVertex(elem_t E)
{
  // Set up a new vertex first
   Vertex *N;         // N will point to the new vertex to be inserted
   N = new Vertex;    // a new vertex is created
   N->Left  = NULL;   // make sure it does not
   N->Right = NULL;   // point to anything
   N->Elem  = E;      // put element E in it

   cout << "Trying to insert " << E << endl;

   if (Root == NULL)  // Special case: we have a brand new empty tree
     {
       Root = N;      // the new vertex is added as the root
       cout << "...adding " << E << " as the root" << endl; 
     }

   else  // the tree is not empty
     {
        Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent

        V = Root;        // start with the root as V

	// go down the tree until you cannot go any further        
	while (V != NULL)
	  {
	    if (N->Elem == V->Elem) // the element already exists
              {	 cout << "...error: the element already exists" << endl;
		return;  }
	    else
	      if (N->Elem < V->Elem)  // what I have is smaller than V
		{  cout << "...going to the left" << endl; 
		  Parent = V;	//change Parent to be V to go down
		  V = V->Left;	//change V to be V's Left
		}
	      else // what I have is bigger than V
		{  cout << "...going to the right" << endl;
		  Parent = V;		//change Parent to be V to go down
		  V = V->Right;  	//change V to be V's Right
		}
	  }//end of while
        
        // reached NULL -- Must add N as the Parent's child
        
        if (N->Elem < Parent->Elem)  
          {  
        Parent->Left = N;		//Parent's Left should point to the same place as N
	    cout << "...adding " << E << " as the left child of " 
                  << Parent->Elem << endl;	}
        else 
           {
	     Parent->Right = N;		//Parent's Right should point to the same place as N
             cout << "...adding " << E << " as the right child of " 
                  << Parent->Elem << endl;	}

      }// end of normal case
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAM: element E to be removed
// ALGORITHM: First we must find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
  cout << "Trying to delete " << E << endl;
  
  Vertex *V;              // the current vertex
  Vertex *Parent = NULL;  // its parent


  // case 1: Lonely Root  
  if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { cout << "...deleting the lonely root" << endl;
      delete Root; 
      Root = NULL;
      return; }  // only the Root was there and deleted it
  
  // case 2:  One Substree Root
  if ((E == Root->Elem)
		  && ((Root->Left != NULL && Root->Right == NULL)
		  || (Root->Left == NULL && Root->Right != NULL)))	//if what you want to delete is the root
  {
    if(Root->Left != NULL)	//and it has only the left subtree
    {
    	Root = Root->Left;
    	return;				//change the root to the left child and return
    }
    else	//and it has only the right subtree
    {
    	Root = Root->Right;
    	return;				//change the root to the right child and return
    }
  }// end of deleting the root with one subtree
  
  // Otherwise deleting something else
  
  V = Root;  // start with the root to look for E
  
  while (V != NULL)
    { 
      if ( E == V->Elem)   // found it
	{  cout << "...removing " << V->Elem << endl;
	  remove(V, Parent);	//call remove here to remove V
	  return; }
      
      else
	if (E < V->Elem)
	  {  cout << "...going to the left" << endl;
	    Parent = V;//update Parent and V here to go down
	    V = V->Left;
	  }
	else
	  {  cout << "...going to the right" << endl;
	    Parent = V;//update Parent and V here to go down
	    V = V->Right;
	  }
      
    }// end of while
  
  // reached NULL  -- did not find it
  cout << "Did not find the key in the tree." << endl;
  
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAM: V and its parent  pointer P
// Case 1: it is a leaf, delete it
// Case 2: it has just one child, bypass it
// Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
  if(V->Left == NULL && V->Right == NULL)//if V is a leaf (case 1)
      {
	cout << "removing a leaf" << endl;
	if(V == P->Left)	//if V is a left child of P
	{
	  delete V;	//delete V and also make Parent's left NULL
	  P->Left = NULL;
	}
	else // V is a right child of the Parent
	  { 
	    delete V;	//delete V and also make Parent's right NULL
	    P->Right = NULL;
	  }
      }//end of leaf case
    
      else if(V->Left != NULL && V->Right == NULL)	//if V has just the left child (case 2)
	{
	  cout << "removing a vertex with just the left child" << endl;
	  if(V->Left->Elem < P->Elem){	//You need if then else to determine Parent's left or right
		  P->Left = V->Left;		//should point to V's left child; be sure to delete V
		  delete V;
	  }else{
		 P->Right = V->Left;
		 delete V;
	  }
	}// end of V with left child       
      else if(V->Left == NULL && V->Right != NULL)//if V has just the right child
	{
	  cout << "removing a vertex with just the right child" << endl;
	  if(V->Right->Elem < P->Elem){	//You need if then else to determine Parent's left or right
		  P->Left = V->Right;		//should point to V's right child; be sure to delete V
		  delete V;
	  }else{
		  P->Right = V->Right;
		  delete V;
	  }
        }//end of V with right child
      else // V has two children (case 3)
	{ cout << "removing an internal vertex with children" << endl;
	  cout << "..find the MAX of its left sub-tree" << endl;
	  elem_t Melem;
	  // find MAX element in the left sub-tree of V
          Melem = findMax(V); 
          cout << "..replacing " << V->Elem << " with " << Melem << endl;
          V->Elem = Melem;//Replace V's element with Melem here
        }//end of V with two children
      
}// end of remove

// PURPOSE: Finds the Maximum element in the left sub-tree of V
elem_t BST::findMax(Vertex *V)
{
  Vertex *Parent = V;
  V = V->Left;          // start with the left child of V
  
  while(V->Right != NULL)	//while the right child of V is still available
  {
    Parent = V;		//update Parent and V to go to the right
    V = V->Right;
  }
  
  // reached NULL Right  -- V now has the MAX element
  elem_t X = V->Elem;
  cout << "...Max is " << X << endl;
  remove(V, Parent);    // remove the MAX vertex 
  return X;             // return the MAX element
  
}// end of FindMax

