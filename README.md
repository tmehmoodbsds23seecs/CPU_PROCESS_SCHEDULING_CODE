CPU Process Scheduling Algorithm
Problem 1: Simple Process Scheduling Algorithm
This project implements a CPU Process Scheduling Algorithm using a circular linked list. The processes are represented as nodes, and a fixed CPU time is assigned to each process in cycles, simulating a round-robin scheduling algorithm.

Table of Contents
Project Description
Features
Installation
Usage
Example
Contributing
License
Project Description
The goal of this project is to simulate a simple process scheduling system using a linked list. Each process has:

process_id: A unique identifier for each process.
execution_time: The total time required by the process for execution.
remaining_time: The remaining time the process needs to complete.
The scheduling algorithm runs in cycles, where each process is assigned a fixed amount of CPU time. The algorithm reduces the remaining execution time for each process by the assigned CPU time, and if the remaining time becomes zero, the process is removed from the scheduling list. The system continues until all processes have completed their execution.

Features
Circular Linked List: Processes are represented as nodes in a circular linked list.
Round-robin Scheduling: In each cycle, CPU time is assigned to a process and its remaining_time is reduced.
Dynamic Process Management: New processes can be added, and completed processes are removed from the list.
Cycle Simulation: The state of processes is displayed after each cycle, showing which process is running and its remaining time.

Contributing
If you'd like to contribute to this project, feel free to submit a pull request. Contributions are welcome for:

Code improvements
Bug fixes
New features or enhancements
