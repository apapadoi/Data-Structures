# Additional Information about the repository:

# **Useful Definitions:**
**Occupancy factor:** Given an array of size N ( For instance if the array's elements are integers then the memory   
                      allocated for this structure is sizeof(int)*N depending the architecture and the operating system of the computer ) suppose we really use k positions of the total array's N positions.Then we define the occupancy factor as the fraction k/N.Whenever we delete or insert an element in the structure which is implemented with this type of array we act as below:
                    
                    **Insert:**Whenever we insert an element if the structures is not full we just do the insertion.Otherwise we double up the positions ( N ) of the array.
                    **Delete:**If after the deletion the occupancy factor is greater ( > ) than 0.25 we just do the deletion.Otherwise we reduce the positions ( N ) of the array by 1/2 ( so the new N is equal to previous N/2 )

                    **In conclusion,**in this way we keep the occupancy factor greater than 0.25 and we achieve a more efficient way of memory usage.

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
**Note:** This structure is implemented using an array with dynamic memory allocation based on the occupancy factor
          depending the specific state of the structure. 