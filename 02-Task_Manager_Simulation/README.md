# Task Manager Simulation  

A simple C++ task manager that manages running processes using **stacks** (LIFO) and **queues** (FIFO), simulating different scheduling mechanisms.  

## Features  
✅ Add a process (to stack or queue)  
✅ View the next process (without removing it)  
✅ Execute a process (remove from stack or queue)  
✅ List all processes in the stack and queue  

🔹 **Bonus Features:**  
- Sort processes by priority before adding them  
- Simulate execution based on priority  

---

## Project Structure  
📂 `src/` - Contains the C++ source code  
📂 `include/` - Header files  
📄 `README.md` - Project documentation  

---

## Classes  

### 1. Process  
Represents a process with:  
- `id` (unique identifier)  
- `name` (process name)  
- `priority` (1 = High, 2 = Medium, 3 = Low)  

### 2. TaskManager  
Manages processes using:  
- `std::stack<Process>` (LIFO mechanism)  
- `std::queue<Process>` (FIFO mechanism)  


