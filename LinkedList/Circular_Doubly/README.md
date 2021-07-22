# This is **circular doubly linked list** impelementation using `structs`.

## Methods and Usages :

* ```IsEmpty()``` : check if a list is empty.

* ```InsertEnd(int value)``` : insert a node in the end of the list.

* ```DeleteEnd()``` : delete a node from the end of the list.

* ```InsertFirst(int value)``` : insert a node in the begining of the list.

* ```DeleteFirst()``` : delete a node from the beginig of the list.

* ```InsertNth(int value, int position)``` : insert a node in any valid position in the list.

* ```DeleteNth(int position)``` : delete a node from any valid position in the list. 

* ```Display()``` : print all the nodes of the list.

* ```Length()``` : return the length of the list.
## Time Complexity :
*here i will give the time complexity of every function using 'O' notation*

| Function      |   Best Case     | Worst Case    |
| :---          |     :---:       |          ---: |
| IsEmpty      | O(1)            | O(1)          |
| InsertEnd    | O(1)            | O(1)          |
| DeleteEnd    | O(1)            | O(1)          |  
| InsertFirst  | O(1)            | O(1)          |
| DeleteFirst  | O(1)            | O(1)          | 
| InsertNth    | O(1) 1th node   | O(n)          |
| DeleteNth    | O(1) 1th node   | O(n)          |
| Display       | O(1)           | O(n)          |
| Length        |O(1)             |O(n)          |