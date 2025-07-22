# Page Replacement Algorithms

This repository contains implementations of various **Page Replacement Algorithms** commonly used in Operating Systems for managing memory. These algorithms help determine which memory pages to swap out when a new page needs to be loaded into memory.

## 🧠 Algorithms Implemented

- **FIFO (First-In-First-Out)**  
  Replaces the oldest page in memory.

- **LRU (Least Recently Used)**  
  Replaces the page that hasn't been used for the longest time.

- **Optimal Page Replacement**  
  Replaces the page that will not be used for the longest time in the future. (Requires future knowledge, used as a benchmark.)

- **LFU (Least Frequently Used)** _(Optional)_  
  Replaces the page with the lowest frequency of accesses.