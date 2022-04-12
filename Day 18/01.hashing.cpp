// https://www.geeksforgeeks.org/hashing-set-1-introduction/

/**
    Hashing:- 
            A function that converts a given big phone number to a small practical integer value. The mapped integer value is used as an index in hash table.
            A hash function maps a big number or string to a small integer that can be used as index in hash table. 
            A good hash function should have following properties:-
            1) Efficiently computable. 
            2) Should uniformly distribute the keys (Each table position equally likely for each key)
    HashTable:- 
            An array that stores pointers to records corresponding to a given phone number. An entry in hash table is NIL if no existing phone number has hash function value equal to the index for the entry. 

    Collision Handling:-
            Since a hash function gets us a small number for a big key, there is possibility that two keys result in same value. The situation where a newly inserted key maps to an already occupied slot in hash table is called collision and must be handled using some collision handling technique. 
            Following are the ways to handle collisions:
            Chaining: The idea is to make each cell of hash table point to a linked list of records that have same hash function value. Chaining is simple, but requires additional memory outside the table.
            Open Addressing: In open addressing, all elements are stored in the hash table itself. Each table entry contains either a record or NIL. When searching for an element, we examine the table slots one by one until the desired element is found or it is clear that the element is not in the table.
 */