# Push_swap

- The idea of this project is that you have two stacks : A and B. At the beginning B is empty and A contains a certain number of positive or negative integers, without repeats.
- The goal is to sort stack A only using a certain number of defined commands :
  * sa: swap A: swap the first two elements on stack A
  * sb: sawp B: swap the first two elements on stack B
  * ss: do commands sa and sb at the same time
  * pb: push A to B: take the first element on A and move it to the beginning of B
  * pa: push B to A: take the first element on B and move it to the beginning of A
  * ra: rotate A: move all the elements on A and move them towards the beginning, moving the first element to the end
  * rb: rotate B: move all the elements on B and move them towards the beginning, moving the first element to the end
  * rr: do commands ra and rb at the same time
  * rra: reverse rotate A: move all the elements on A and move them towards the end, moving the last element to the beginning
  * rrb: reverse rotate B: move all the elements on B and move them towards the end, moving the last element to the beginning
  * rrr: do commands rra and rrb at the same time
  
  ## How to use it ?
  
  ```
  git clone https://github.com/vkannema/push_swap
  make
  ```
  This will create two executables : push_swap and checker.
  The first one is made to sort the list, the second checks if the list is sorted. You will need to give the same arguments for checker you gave to push_swap.
  We will use them like that :
  Exemple 1:
  ```
  ./push_swap 2 1 3 4 5
  sa
  ./checker 2 1 3 4 5
  KO
  ./push_swap 2 1 3 4 5 | ./checker 2 1 3 4 5
  OK  
  ```
  
