# Data Structures Implementation:

### **This**
 repository was created during my 1st year studies in Computer Science Department of Aristotle University of Thessaloniki alongside with the course "Data Structures",but I keep trying improving and making better the implementation of these Data Structures.Also, I would want you to know that there will be another repository implementing Data Structures in which data from Gutenberg Project(https://www.gutenberg.org/) will be processed,which was an assignment/Project in "Data Structures" course in 2020.In the following section there are some useful information about each Data Structure individually.Also feel free to make any Pull Requests if you think something needs to be changed and I am also opened in any suggestions about the repository in general. 

## **Useful Definitions:**
**Occupancy factor:** Given an array of size N ( For instance if the array's elements are integers then the memory   
allocated for this structure is sizeof(int)*N depending the architecture and the operating system of the computer ) suppose we really use k positions of the total array's N positions.Then we define the occupancy factor as the fraction k/N.Whenever we delete or insert an element in the structure which is implemented with this type of array we act as below:
                    
Insert:Whenever we insert an element if the structure is not full we just do the insertion.Otherwise we double up the positions (N)   of the array.

Delete:If after the deletion the occupancy factor is greater ( > ) than 0.25 we just do the deletion.Otherwise we reduce the positions ( N ) of the array by 1/2 ( so the new N is equal to previous N/2 )

In conclusion,in this way we keep the occupancy factor greater than 0.25 and we achieve a more efficient way of memory usage.

## **Stack Data Structure:**
If you want to use the stack implementation code you should include both stack.h and stack.cpp files inside your client  .cpp file so the compiler and the linker can find the implementation of the class stack because I use a template for this class so it can be used for every element of any data type.Also the template works with every input in the STACK_SIZE parameter.If the STACK_SIZE is less or equal than zero then I construct by default a stack with size equal to ten.You can change that by changing the value of #define macro inside the stack.h file.

**Note:** This structure is implemented using an array with dynamic memory allocation based on the occupancy factor
          depending the specific state of the structure. 

## **Queue Data Structure:**
If you want to use the queue implementation code you should include both queue.h and queue.cpp files inside your client  .cpp file so the compiler and the linker can find the implementation of the class queue because I use a template for this class so it can be used for every element of any data type.Also the template works with every input in the QUEUE_SIZE parameter.If the QUEUE_SIZE is less or equal than zero then I construct by default a queue with size equal to 10.You can change that by changing the value of #define macro inside the queue.h file.

**Note:** This structure is implemented using an array with dynamic memory allocation based on the occupancy factor
          depending the specific state of the structure. 

## **Circular Queue Structure:**
If you want to use the Circular queue implementation code you should include both circularQueue.h and circularQueue.cpp files inside your client  .cpp file so the compiler and the linker can find the implementation of the class circularQueue because I use a template for this class so it can be used for every element of any data type.Also the template works with every input in the QUEUE_SIZE parameter.If the QUEUE_SIZE is less or equal than zero then I construct by default a queue with size equal to 10.You can change that by changing the value of #define macro inside the circularQueue.h file.

## **Linked List Structure:**
If you want to use the Linked List implementation code you should include both linkedList.h and linkedList.cpp files inside your client  .cpp file so the compiler and the linker can find the implementation of the class linkedList because I use a template for this class so it can be used for every element of any data type.

## **Sequential List Structure:**
If you want to use the Sequential List implementation code you should include both sequential.h and sequential.cpp files inside your client  .cpp file so the compiler and the linked can find the implementation of the class sequentialList because I use a template for this class so it can be used for every element of any data type.Also the sequential structure works with every input in the constructor of a specific object.If the size that the constructor has been called is zero or negative then the list will be constructed by default with size equal to ten.You can change that by changing the value of #define macro inside the sequentialList.h file.

**Note:** This structure is implemented using an array with dynamic memory allocation based on the occupancy factor depending the specific state of the structure. 

## **Doubly Linked List Structure:**
If you want to use the Doubly Linked List implementation code you should include both doublyLinkedList.h and doublyLinkedList.cpp files inside your client  .cpp file so the compiler and the linker can find the implementation of the class doublyLinkedList because I use a template for this class so it can be used for every element of any data type.Also you should include in your compiler's path the following: doublyNode.h,doublyNode.cpp,linkedList.h and linkedList.cpp ,specifically the versions of these files as they are in the Doubly Linked List folder because this structure is implemented using inheritance.

**Note:** The files had to be copied in the Doubly Linked List folder because when I was developing the structure I could not make the compiler find and compile them.I know that if something in linkedList class has been updated,changed or deleted these changes will not be applied in the parent class linkedList of doublyLinkedList but I will try whenever I change something in the Linked List implementation folder I will also update the parent class of this structure and continue trying to fix the error with the compiler so the doublyLinkedList can inheritance from class of another folder.