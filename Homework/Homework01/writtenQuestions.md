Thomas Ochsner

Mike West

Kevin Peters

  

1. Middleware is software that interacts between the operating system and the applications. Applications tell the middleware what to do and the middleware tells the operating system what to do. The operating system would then tell the hardware what to do. 
2. A thread is a sequence of programmed actions. Operating systems allow multiple threads to run concurrently on the same machine. A process is a container for threads that protects them from unwanted interactions with unrelated threads. 
3. Security appears to be the most interesting topic that was mentioned in chapter 1 of the book. Understanding how potential mismanagement of threads and processes lead to security vulnerabilities could be both practically and academically intriguing. Even if we do not plan on writing low level code in the future, a fundamental understanding of how these exploits work would be useful. 
4. a) 2101ms 

    b) 1301ms. (12ms per loop [Start A, switch, do B, switch, compute]) * 100 + 100ms [finish B] + 1ms switch

    c)Method b is more efficient because it utilizes idle CPU time while thread A is doing its I/O operations. Thus, total time to run is significantly less.

5. Yes, the child thread can print it’s message while the main thread is waiting for keyboard input. Yes, the main thread can read keyboard input and subsequently kill the child thread while the child thread is in the early seconds of one of it’s 5-second sleeps. With our program, the child thread is killed immediately when the keyboard input is read.
6. Rate monotonic scheduling is the optimal fixed-priority scheduling
![Gantt Charts](https://github.com/JustusWest/CMSI-387/blob/master/Homework/Homework01/IMG_1043.JPG)

```
1->3->6 -> 10    = 10/3       shortest is first in first out
3->4->9 -> 13    = 13/3
2->5->8 -> 13    = 13/3
2->3->8 -> 11    = 11/3
3->5->9 -> 14    = 14/3
1->4->8 -> 12    = 12/3
```
