The echo program display the thread if of the connection. The client disconnected when press the "quit".
It been testing using 'nc localhost 3000' in the client side. The default port is 3000 while 127.0.0.1 is 
being set as the local address. Has a test to check if threads ID to check for different clients. User can 
only choose port between 1024 and 65535 otherwise it won't be accepted. The only trouble it is when closing 
from the server side has to be manually from command line. In Mac to check for the process identifier (PID) 
enter 'lsof -i :(port number) and the find the PID and to forcefully close the process in which the socket is running.
I made some comments for more understanding of the code when trying to review.