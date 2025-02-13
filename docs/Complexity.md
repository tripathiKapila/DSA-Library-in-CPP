
---

### docs/Complexity.md
```markdown
# Complexity Analysis

Below is a brief summary of the time complexities for the implemented data structures:

- **Dynamic Array:**  
  - Access: O(1)  
  - Insertion (amortized): O(1)  
  - Removal (pop_back): O(1)

- **Linked List:**  
  - Access (front): O(1)  
  - Insertion/Deletion (front): O(1)  
  - Insertion (back): O(n) if no tail pointer, O(1) with tail pointer

- **Stack:**  
  - All operations (push, pop, top): O(1)

- **Queue:**  
  - All operations (enqueue, dequeue, front): O(1)

- **Binary Search Tree (BST):**  
  - Insertion/Search (average): O(log n), worst-case O(n)

- **Graph:**  
  - Using an adjacency list; complexity depends on the algorithm (e.g., O(V + E) for breadth-first search)

- **Hash Map:**  
  - Average-case for insertion, search, and deletion: O(1)  
  - Worst-case: O(n) if many collisions occur
