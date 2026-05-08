''' CS425: Computer Networks
    Homework-3 (Question 2) Submission
    
    Name: Ronav Puri
    Roll No: 230815
    Program: BT-CSE
    
    Note: This is the UDP Server code.
    Please run this code before running the UDP Client code (CS425_HW3_UDPClient.py).
    
    How to run this code:
    1. Open a terminal and navigate to the directory containing this code.
    2. Type: "python3 CS425_HW3_UDPServer.py" and press Enter.''' 

from socket import *

serverPort = 13000

serverSocket = socket(AF_INET, SOCK_DGRAM)
serverSocket.bind(('', serverPort))
print ("The server is ready to receive!")

while True:
    message, clientAddress = serverSocket.recvfrom(2048)
    modifiedMessage = message.decode().upper()
    serverSocket.sendto(modifiedMessage.encode(), clientAddress)