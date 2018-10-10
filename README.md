# CS537-P2

# C/H Files
## monitor.{ch}
## queue.{ch}
- CreateStringQueue
- EnqueueString
- DequeueString
- PrintQueueStats
## reader.{ch}
## munch1.{ch}
## munch2.{ch}
## writer.{ch}
## main.{ch}
Top level contains three queues and four threads each running reader, munch1, munch2 or writer. The threads communicate to each other by passing line pointers to the queue.
# Other Files
## makefile
