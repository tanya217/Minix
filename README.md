Process Scheduling
Domain: Operating Systems
5th semester - October 2017

What?
MINIX is a small, open source UNIX clone that was first released in January 1987. 
It is now best known for its role in inspiring Linus Torvalds to develop Linux. 

Why?
MINIX was written for educational purposes. It is very small size, abundance of 
advanced features, freely available source code, excellent documentation and liberal 
licensing have made MINIX particularly well suited for educational purposes.

Task?
1) Change the round-robin process scheduling algorithm of MINIX in a way that it gives higher priority to process that frequently often block for Input/Output.
2) We split time into 5 seconds segments
3) For each segment we keep track the number of clock ticks for which the process run on the processor.
4) When the scheduler is called for picking the next process to run on the processor, it will select the process which runs the least clock ticks during the current segment
