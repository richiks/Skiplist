# Skiplist

* An implementation of a set abstraction backed by a skiplist.  A skiplist
 * is a probabilistic data structure introduced by William Pugh in his paper
 * "Skip Lists: A Probabilistic Alternative to Balanced Trees."  The skiplist
 * can be thought of as a sorted linked list where each node stores pointers
 * to a collection of nodes further down in the list, not just the next node.
 * These pointers are "stacked" on top of one another, with the topmost pointer
 * pointing furthest down in the structure, the second-to-topmost pointer
 * pointing no further than that, etc.  The bottommost level points directly to
 * the next node in the skiplist.  The skiplist structure itself maintains an
 * array of pointers stored in the same fashion.  Searches can then be done by
 * starting at the top of the pointer stack, then advancing to the indicated
 * node if its value is no greater than the key to search for, and otherwise
 * dropping down a level and repeating.
 *
 * The main advantage of a skiplist over a standard self-balancing binary 
 * search tree is that the skiplist implemention is significantly easier than
 * most balanced tree implementations.  There are no tree rotations, nor
 * "colors" or "balance factors" to keep track of.  Instead, the balancing
 * comes probabalistically with the choice of the heights of each node.
 * Moreover, the constant factors on skiplist implementations of search,
 * insert, and delete operations are often much lower than the constant factors
 * on typical balanced BSTs.
 *
 * This implementation of the skiplist uses the skiplist to represent an
 * associative array structure like the STL map.  Each entry stores a constant
 * key and mutable value, as well as the forward pointers.  The structure also
 * supports forward iterators, which can read and write entries.  However, in
 * the interests of simplicity, this implementation does not comply with the
 * associative container requirements of the C++ standard; this would require
 * an enormous amount of extra code that could complicate the implementation
 * without necessarily adding anything interesting.
 *
 * This code does contain one optimization which might make it a bit harder
 * to read.  Although any two nodes in a skiplist might support different
 * numbers of pointers, once a node is constructed the number of pointers it
 * stores is fixed.  Rather than having each node store a vector of pointers or
 * a dynamically-allocated array of pointers, I instead override the new and
 * delete operators for nodes so that when a node is constructed on the heap,
 * it is overallocated with space to store the extra pointers.  This saves an
 * indirection to locate the pointer array, since they're bundled directly with
 * the object itself.  This was mostly for my own edification (I've seen this
 * technique used before, but never implemented it myself), and I apologize if
 * it complicates the implementation.
