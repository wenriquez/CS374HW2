CS374HW2
========

Homework 2

1. Use the makefile( make all) to compile and link the files. Three binary files will be created: Client1, Client2, and the Server.

2. The Server must be ran first in order to setup the FIFO's.

3. Client1 or Client 2 can now be ran in any order from separate terminals.

4. Messeges up to 4094 characters will be allowed, anything longer will be read up to the max and then ignored.

5. If you want to exit from a client, you must type _exit_ in order for the client to stop.

6. Once the chat session is over, Use make clean to remove the Binary files and the two FIFO's that were created.
