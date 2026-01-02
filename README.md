# Data-Structures
# Data Structures in C++ 📚

This repository contains implementations of classic **Data Structures** in **C++**, all built from scratch without using STL containers, with a focus on learning how each structure works internally.

These data structures are commonly taught in computer science courses and are fundamental for interviews and competitive programming.

---

## 📋 Implemented Data Structures

### ✅ **Stack**
- Implemented using a linked list (`Stack.cpp`)
- Supports basic operations:
  - `push`
  - `pop`

---

### ✅ **Queue**
- Implemented using a linked list (`Queue.cpp`)
- Supports:
  - `enqueue`
  - `dequeue`

---

### ✅ **Max Heap**
- Array / vector based heap (`Max_Heap.cpp`)
- Supports:
  - Insert
  - Delete max
- Maintains the heap property after each operation

---

### ✅ **Trie (Prefix Tree)**
- String-based tree (`Trie.cpp`)
- Supports:
  - Insert
  - Search
  - Delete
- Efficient string lookup

---

### ✅ **AVL Tree**
- Self-balancing BST (`AVL.cpp`)
- Supports:
  - Insert
  - Delete
- Automatically balances tree height

---

## 🧪 How to Compile and Run

Use `g++` (or another C++ compiler) to build and run each file.

Example:
```bash
g++ Stack.cpp -o stack
./stack