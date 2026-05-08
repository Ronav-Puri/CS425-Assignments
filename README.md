# CS425-Assignments
Assignments which were part of the course CS425: Computer Networks, during my sixth semester at IITK.

### Assignment 1: Error Detection and Data Link Layer
Focused on Cyclic Redundancy Check (CRC) generation and verification as well as theoretical problems on ARQ mechanisms.
* `CS425_ass1.pdf`: Problem statement
* `CS425_ass1_sol.pdf`: Detailed theoretical and numerical solutions
* `CS425_ass1_code.c`: C implementation for generating an $n$-bit frame from a $k$-bit data block using a CRC pattern $P$

#### How to Run (CRC Program)
1.  Open your terminal and navigate to the directory.
2.  Compile the code using `gcc`:
    ```bash
    gcc CS425_ass1_code.c -o crc_gen
    ```
3.  Run the executable:
    ```bash
    ./crc_gen
    ```
4.  Follow the on-screen prompts to enter the data block and CRC pattern.

---

### Assignment 2: IP Protocol and Packet Analysis
Centered on analyzing IPv4 packet headers and fragmentation using Wireshark captures.
* `CS425_ass2.pdf`: Problem statement containing Wireshark traffic screenshots
* `CS425_ass2_sol.pdf`: Analysis of IP fields such as TTL, Identification and Fragmentation Flags

---

### Assignment 3: Routing Algorithms and Socket Programming
Covers the implementation of Dijkstra's and Bellman-Ford algorithms along with UDP Socket Programming.
* `CS425_ass3.pdf`: Problem statement including the network graph for shortest-path calculation
* `CS425_ass3_code.cpp`: C++ implementation of Dijkstra's and Bellman-Ford shortest path algorithms
* `UDPClient.py`: Python script for the UDP client.
* `UDPServer.py`: Python script for the UDP server.

#### How to Run

**Shortest Path Algorithms (C++ Code):**
1.  Compile the routing program:
    ```bash
    g++ code.cpp -o routing
    ```
2.  Run the executable:
    ```bash
    ./routing
    ```
3.  Input the source and destination nodes as prompted to view the route and cost.

**UDP Socket Application (Python):**
1.  Open two separate terminal windows.
2.  **Start the Server first**:
    ```bash
    python UDPServer.py
    ```
3.  **Start the Client**:
    ```bash
    python UDPClient.py
    ```
4.  Exchange messages between the client and server terminals.
