1. The issue would occur immediately after the `unlock mutex.spinlock` line is executed. At this point, the current thread is still in the `runnable threads` and as such, could reclaim the mutex and execute again. This is not ideal since it does not allow other threads to claim the mutex and run.

2. The issue occurs since the two calls of `state.get()` are not guaranteed to be referencing the exact same object. Between these two lines, there is a chance that `state` was changed, which would result in an inconsistent returned value from state.get(). Establishing the `snapshot` variable solves this problem by ensuring that both lines reference the same state of `state`. 

5.  2 - Phase locking -> not possible () <br />
    "Read Committed" isolation level is used -> possible () <br />
    Snapshot Isolation -> not possible ()
   
6.
The virtual addresses of the first and last four-byte words in page 6 are 24,576 and 28,668, respectively. These addresses map to the physcial addresses 12,288 and 16,380, respectively.

7. The numbers `1047552` and `1047553` come from the index of the last page table, and the fact that each page table has 1024 frames. The bottom right nodes indicate the first two page frames of the last page table. Since the root has the range of 1024-2047, we can calculate the start index of the last page table from `1024 * 1023`. Thus it makes sense that the first and second index of the last page tabe are `1047552` and `1047553` respectively.

8. We wrote a program (in this repo `problem8.c`) to access every 4096th element of a 1000000 byte array allocated to the heap. Using the `time` library to time the access time of each element, we receieve only `0.000000` for every access. In addition, the time read for the total time for all access combined also came out to 0. Making the byte array any larger results in the program being unable to run. Since we are unable to get non-zero values for these access times, we are unable to conclude if array size has an effect on access time.

9.

| ID   | name    | time    | process      |
| ---- | ------- | ------- | ------------ |
| 1493 | ttys001 | 0:00.00 | ./problem9.o |
| 1494 | ttys001 | 0:00.00 | ./problem9.o |
| 1495 | ttys001 | 0:00.00 | ./problem9.o |
| 1496 | ttys001 | 0:00.00 | ./problem9.o |
| 1497 | ttys001 | 0:00.00 | ./problem9.o |
| 1498 | ttys001 | 0:00.00 | ./problem9.o |
| 1499 | ttys001 | 0:00.00 | ./problem9.o |
| 1500 | ttys001 | 0:00.00 | ./problem9.o |

![](./problem9.png )
