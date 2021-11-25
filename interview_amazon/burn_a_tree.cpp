/*
Given a binary tree and target node. By giving the fire to the target node and fire starts to spread in a complete tree. 

The task is to print the sequence of the burning nodes of a binary tree.
Rules for burning the nodes : 

1. Fire will spread constantly to the connected nodes only.
2. Every node takes the same time to burn.
3. A node burns only once.


Input : 
                       12
                     /     \
                   13       10
                          /     \
                       14       15
                      /   \     /  \
                     21   24   22   23
target node = 14

Output :``1`
14
21, 24, 10
15, 12
22, 23, 13

*/