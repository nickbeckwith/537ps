# CS537-P2

# C/H Files
- queue.{ch}
  - createStringQueue
  - enqueueString
  - dequeueString
  - printQueueStats
- reader.{ch}
- munch1.{ch}
- munch2.{ch}
- writer.{ch}
- main.{ch}
-- Top level contains three queues and four threads each running reader, munch1, munch2 or writer. The threads communicate to each other by passing line pointers to the queue.
# Other Files
- makefile

# Description
This project exemplifies the classic producer consumer synchronization problem. Where there are 4 different modules connected together
to be each others producers and consumers. To accomplish this, we set up communication through a FIFO that was locked during reads
and writes. All 3 communication paths were connected by a different FIFO. Finally, to signal the end of production, a NULL string
is sent by the first producer (the stdin one) and acknoweldged downstream by thread exiting.
