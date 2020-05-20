#ifndef STRINGALGO_SKIPLIST_H
#define STRINGALGO_SKIPLIST_H

#include <cstdlib>
#include <vector>


/*
 * Author: Advait Balaji
 *
 *implements search, add and delete methods in a Skiplist
 *Note: this is not a concurrent Skiplist! - But lightweight and header-only!
 */

/*
 * Logic:
 * search: we first start with the head and while head exists we keep a while loop. While checks for existence
 * of _next and checks if value is less than num, if it is we update current node to node->_next. Once the while loop
 * breaks we check if there is no more _next(right) node OR if the value to the right is greater, we move a step down.
 * If this is not the case, then we have surely found a node->_val == currentnode->_next->_val and we return true.
 * If we go down, then we restart the loop and go to the _next(right) at that level
 *
 * add: adding is a more complex and interesting logic. Like search we start at the head node in the topmost level.
 * We check if node exists and keep moving in the while loop  till we encounter either a node with no _next(right) or
 * a node with value greater than the target we want to insert. Remember this will be node->_next of the current node.
 * We pause here make a note of the node (add it to a vector) and go to the bottom level and continue this process.
 * This will continue till we reach the lowest level.
 * Now we need to traverse back to all the nodes from bottom-up and keep adding nodes to our checkpoints in the vector.
 * We first initialize a bottomnode to be a nullptr and flip the "add to more layer" variable (up) to be true. We then
 * extract the last node from the bottom layer, add a new node with the value to the right and set the bottom variable.
 * We then update the bottom variable to this new node. Note that when we move a layer up we automatically set the
 * bottom to be the new node we added below, this continues till either we flip the variable back to false or the vector
 * is empty. If the vector empties and the last flip was still true by contract we are supposed to a new layer with
 * that value which we do in the last if block. The last if block creates a new head above the current head  with value
 * INT_MIN and to the right has the node with the given num value and a below node pointer still pointing to the correct
 * sequence of nodes at the lower level.
 *
 *
 * erase: this is similar to search for the first loop and if block, the only change is that once we find the element in
 * a level we mark the next of the node (remember again finding the element means node->_next->_val == target) to
 * the next of next i.e node->_next = node->_next->_next. We also need to explore bottom layers so set current node to
 * node->_bottom and continue resetting the next(right) nodes for each subsequent layer
 *
 * getLevel(): just for user info to get the number of levels added so far, we increment the level in the final if
 * block of add as explained above. Level is zero indexed.
 */


class Node
{
public://each node has three attributes; its value, next (right) node and a possible bottom node
    Node(int val, Node* next, Node* bottom)
    {
        _val = val;
        _next = next;
        _bottom = bottom;
    }

    int _val;
    Node* _next;
    Node* _bottom;
};


class Skiplist
{
public:

    Skiplist()
    {   //head is always the beginning node
        _head = new Node(0, nullptr, nullptr);
        //total levels - 0 indexed;
        _level = 0;
    }

    /*
    *@function: searches skiplist
    *@params: int target to find
    *@returns: bool
    */
    bool search(int target)
    {
        //start with the head in the topmost level
        Node* searchnode = _head;
        //while we have an existing head
        while(searchnode)
        {   //keep moving right and checking for values less than target
            while(searchnode->_next && searchnode->_next->_val < target)
            {   //reset searchnode to be the one right of it
                searchnode = searchnode->_next;
            }
            if(!(searchnode->_next) || searchnode->_next->_val > target)
            {   //if there is no right node OR we have landed at a node with value greater than target go down
                searchnode = searchnode->_bottom;
            }
            else
            {   //if the above is untrue we must've have found the target
                return true;
            }
        }
        //return false if we haven't hit target!
        return false;
    }

    /*
     *@function: adds to skiplist
     *@params: int num to add
     *@returns: void
     */
    void add(int num) {
        //clear any previous nodes to track: will get more clear why we use this in the code below
        _tracenodes.clear();
        //start with the head
        Node *addnode = _head;
        //aim: we need to know where to insert our node
        //we loop from the head till we don't have a right node
        //this loop will break if we have a null head OR the bottom return null
        //bottom null means we are at the lowest level of the list
        while (addnode)
        {   //loop
            while ((addnode->_next) && (addnode->_next->_val < num))
            {  //shift  to right
                addnode = addnode->_next;
            }
            //add this last node to the vector
            _tracenodes.emplace_back(addnode);
            //go down a level
            addnode = addnode->_bottom;
        }
        //get a dummy downNode
        Node *downNode = nullptr;
        //we want to insert it at an upper level - this variable is controlled by flipping a coin
        bool up = true;
        //loop till we keep having nodes in the higher level AND flipping coins favourably
        while (up && !_tracenodes.empty())
        {
            //get most recent viable node
            Node *afternode = _tracenodes.back();
            //remove from vector
            _tracenodes.pop_back();
            //to the right of the viable node we insert our new node with value num
            //right of new node was the right of the viable node
            //downnode is null for first insertion or the new node inserted now
            afternode->_next = new Node(num, afternode->_next, downNode);
            //this is where we update the downnode to  the current inserted node
            downNode = afternode->_next;
            //flip a coin - are we done or do we have to insert it above?
            // C++11 suggests use random library for better randomization but std::rand() keeps compilation quicker
            up = ((rand() & 1) == 0);
        }
        if (up) {
            //we want a new level or we want to add our first node in the list!
            _head = new Node(INT32_MIN,new Node(num, nullptr, downNode), _head);
            //keep a track of how many levels have been added
            _level++;
        }
    }

    /*
    *@function: erases node from skiplist
    *@params: int num to erase
    *@returns: bool
    */
    bool erase(int num)
    {
        Node* erasehead = _head;
        bool erased = true;
        while(erasehead)
        {   //similar to search find node with value
            while(erasehead->_next and erasehead->_next->_val < num)
            {   //not found yet move right
                erasehead = erasehead->_next;
            }
            if(!erasehead->_next or erasehead->_next->_val > num)
            {   // move a level down
                erasehead = erasehead->_bottom;
            }
            else
            {   //found it
                //remember the node with our value is erasehead->_next NOT erasehead itself
                erased = true;
                //set next of current node to the next of the node to be erased
                erasehead->_next = erasehead->_next->_next;
                //go down and check if the node we erased in this level can be found in the lower levels
                erasehead = erasehead->_bottom;
            }
        }
        return erased;
    }

    /*
     *@function: get highest level in skiplist
     *@params: none
     * @return: _level
     */
    int getLevel()
    {
        return _level;
    }

private:
    Node* _head;
    std::vector<Node*> _tracenodes;
    int _level;
};

/*
USAGE: (TESTED)
int main()
{
    auto* sk = new Skiplist();
    sk->add(3);
    sk->add(4);
    sk->add(5);
    std::cout<<"Found 4: "<<sk->search(4)<<std::endl;
    std::cout<<"Found 6: "<<sk->search(6)<<std::endl;
    sk->add(7);
    std::cout<<"Erased 4: "<<sk->erase(4)<<std::endl;
    std::cout<<"Found 4: "<<sk->search(4)<<std::endl;
    std::cout<<"Found 7: "<<sk->search(7)<<std::endl;
    std::cout<<"Highest Level(Starts from 0): "<<sk->getLevel()<<std::endl;
}
*/

#endif //STRINGALGO_SKIPLIST_H
