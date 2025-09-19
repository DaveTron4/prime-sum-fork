# Multiprocessing with Fork in C

This project demonstrates process creation and management in C using `fork()`, `wait()`, and `getpid()`.
It creates three child processes that each perform a different calculation between 1 and 1000:

* **Child 1**: Calculates the sum of all even numbers.
* **Child 2**: Calculates the sum of all odd numbers.
* **Child 3**: Finds and prints all prime numbers.
* **Parent**: Waits for all children to complete, then prints its own completion message.

---

## 🚀 Features

* Demonstrates use of `fork()` to create multiple processes.
* Uses `wait()` to ensure parent process runs after children finish.
* Implements a helper function to check for prime numbers.
* Prints process IDs (`pid`) and parent process IDs (`ppid`) for clarity.

---

## 📂 Files

* `lab14.c` → main C program source code.
* `Makefile` *(optional)* → can be added for easy compilation.

---

## 🛠️ Compilation & Usage

### Compile

```bash
gcc -std=c99 -o lab14 lab14.c
```

### Run

```bash
./lab14
```

---

## 📝 Example Output

```
Child 1 (Even sum): 250500
DONE. MY PID IS 22616. MY PARENT’S PID IS 22615.
Child 2 (Odd sum): 250000
DONE. MY PID IS 22617. MY PARENT’S PID IS 22615.
Child 3 (Primes between 1 and 1000):
2 3 5 7 11 13 17 ... 991 997
DONE. MY PID IS 22618. MY PARENT’S PID IS 22615.
Parent DONE. MY PID IS 22615. MY PARENT’S PID IS 22520.
```

---

## 📖 What I Learned

* How to create and manage processes in C with `fork()` and `wait()`.
* Understanding parent-child process relationships using process IDs.
* Practical application of loops and conditionals for sums and prime checking.
* Basics of parallel task execution with multiple processes.

---

## 🔮 Possible Extensions

* Add **timing** to compare execution performance.
* Implement **inter-process communication (IPC)** using pipes or shared memory.
* Write results to files instead of printing to stdout.

---

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
