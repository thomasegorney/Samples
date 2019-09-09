// tree element type is int for now
typedef int elem_t;   // elem_t is hidden from the client

// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Left;
  elem_t  Elem;
  Vertex *Right;
  int Height;  // for EC only
  int Balace;  // for EC only
};   

// this is set up to be inherited by another class
class BST
{
  
 public:
  
  BST();
  ~BST();  // destructor calls dtraverse to destroy the dynamic tree
  
  // PURPOSE: these will show the vertices in IN order 
  // TO CALL: No parameter  but provide a pointer to 
  //          the root vertex in calling INorderTraversal
  void Display();      
  void INorderTraversal(Vertex*);
  
  // PURPOSE: these will search in PRE order - same as Depth First
  // TO CALL: provide the element to search for; provide a pointer to 
  //          the root vertex in calling PREorderSearch
  bool Search(elem_t);
  bool PREorderSearch(Vertex*, elem_t);
  
  // PURPOSE: This inserts a new vertex into the BST 
  // TO CALL: provide the element to be inserted into the tree
  void InsertVertex(elem_t);
  
  // PURPOSE: This deletes a vertex with the given element 
  //- calls remove and  findMax (see below)
  // TO CALL: procide the element to be removed from the tree
  void DeleteVertex(elem_t);
  
 protected:   

  Vertex *Root; //  Root which is a pointer to the root vertex

  // utility functions follow - these are not for the clients to use
  // These were created to implement the public methods
  
  void dtraverse(Vertex*);
  // traverse and delete all vertices in post order
  
  void remove(Vertex*, Vertex*); 
  // removes the vertex knowing its parent
  
  elem_t findMax(Vertex*);  // finds the MAX element in the
  // left sub-tree of the vertex and also deletes it
  
};


