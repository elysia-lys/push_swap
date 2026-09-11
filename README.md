This project has been created as part of the 42 curriculum by zetan, yeliew.

# Push_swap

## Description
```push swap``` is used to sort a stack of integers.

Depending on how complicated the numbers are and by calculating the disorder of the integers
you will use those algorithm to solve it.

The objective is to sort the numbers in ascending order based on 2 stacks (A and B), and keeping
the total operations as low as possible.

## Features
## Algorithms
### Simple Algorithm
```selection sort``` find smallest element, roate to top of stack A, push it to B,
repeat and push everything back to A.
### Medium Algorithm
```chunk-based sort``` calculate √n, divde index into chunk, find elements belong to
current chunk, push to B, process next chunk, find largest index in B and push back to A.
### Complex Algorithm
```radix sort``` normalize number into index, use binary radix sorting.
### Adaptive Algorithm
Based on the disorder calculated. 

Low disorder: if disorder < 0.2, your chosen method must run in O(n2) time.

Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in
O(n√n) time.

High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n)
time.
## Instructions
Use the flags to run which algorith you prefer:
--simple
--medium
--complex
--adaptive
and ```--bench``` to see in txt format.
### Execution
Run ```make``` to compile into executable file and then ./push_swap (any numbers and flags).

Use ./checker_linux or any other checker to test whether it is OK or KO.
## Resources
```push swap``` : www.medium.com
```sorting with chunk merge sort```: www.medium.com
### AI Usage
AI was used as a supplementary learning and debugging tool during development. 
It was used to clarify C concepts such as pointers, linked lists, size_t, void *, 
and va_list, and to explain algorithmic concepts such as radix sort, 
chunk-based sorting, inversion counting, and algorithmic complexity. 
AI was also used to help identify bugs and suggest debugging approaches, 
particularly during the implementation of the medium and adaptive algorithms.

The project code was written, tested, modified, and validated by the author. 
AI suggestions were reviewed and adapted to fit the project's existing code 
structure and constraints.
