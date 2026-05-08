''' CS425: Computer Networks
    Homework-3 (Question 2) Submission
    
    Name: Ronav Puri
    Roll No: 230815
    Program: BT-CSE
    
    Note: This is the UDP Client code.
    Please run the corresponding UDP Server code (CS425_HW3_UDPServer.py)
    before executing this client code.
    
    How to run this code:
    1. Open a terminal and navigate to the directory containing this code.
    2. Type: "python3 CS425_HW3_UDPClient.py" and press Enter.''' 

from socket import *

serverName = 'localhost'
serverPort = 13000

clientSocket = socket(AF_INET, SOCK_DGRAM)

message = input('Input lowercase sentence: ')
clientSocket.sendto(message.encode(), (serverName, serverPort))

modifiedMessage, serverAddress = clientSocket.recvfrom(2048)
print (modifiedMessage.decode())

clientSocket.close()