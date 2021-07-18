# This is **circular linked list** impelementation using `structs`.

## Methods and Usages :

* ```empty()``` : check if a list is empty.

* ```insert_end(int value)``` : insert a node in the end of the list.

* ```delete_end()``` : delete a node from the end of the list.

* ```insert_first(int value)``` : insert a node in the begining of the list.

* ```delete_first()``` : delete a node from the beginig of the list.

* ```insert_nth(int value, int index)``` : insert a node in any valid position in the list.

* ```delete_nth(int index)``` : delete a node from any valid position in the list. 

* ```display()``` : print all the nodes of the list.

* ```length()``` : return the length of the list.

## Time Complexity :
*here i will give the time complexity of every function using 'O' notation*

| Function      |   Best Case     | Worst Case    |
| :---          |     :---:       |          ---: |
| empty         | O(1)            | O(1)          |
| insert_end    | O(1)            | O(n)          |
| delete_end    | O(1)            | O(n)          |  
| insert_first  | O(1)            | O(n)          |
| delete_first  | O(1)            | O(n)          | 
| insert_nth    | O(1) 1th node   | O(n)          |
| delete_nth    | O(1) 1th node   | O(n)          |
| display       | O(1)            | O(n)          |
| length        | O(1)            | O(n)          |


## Few facts about circular single linked list : 
- The last node point to the first node.
- If there is one node in the list ,it points to itself.
- The implementation is little different than single linked list.







