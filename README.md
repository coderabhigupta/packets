# OUCH Protocol Packet Ingestion

## Folder Structure
```
📦include
 ┣ 📂factories
 ┃ ┣ 📜accepted_message_factory.hpp
 ┃ ┣ 📜canceled_message_factory.hpp
 ┃ ┣ 📜executed_message_factory.hpp
 ┃ ┣ 📜message_factory.hpp
 ┃ ┣ 📜replaced_message_factory.hpp
 ┃ ┗ 📜system_event_message_factory.hpp
 ┣ 📂messages
 ┃ ┣ 📜accepted_message.hpp
 ┃ ┣ 📜canceled_message.hpp
 ┃ ┣ 📜executed_message.hpp
 ┃ ┣ 📜ouch_message.hpp
 ┃ ┣ 📜replaced_message.hpp
 ┃ ┗ 📜system_event_message.hpp
 ┗ 📂packets
 ┃ ┣ 📜packet.hpp
 ┃ ┗ 📜packet_capture_header.hpp

 📦src
 ┣ 📂factories
 ┃ ┣ 📜accepted_message_factory.cpp
 ┃ ┣ 📜canceled_message_factory.cpp
 ┃ ┣ 📜executed_message_factory.cpp
 ┃ ┣ 📜message_factory.cpp
 ┃ ┣ 📜replaced_message_factory.cpp
 ┃ ┗ 📜system_event_message_factory.cpp
 ┣ 📂messages
 ┃ ┣ 📜accepted_message.cpp
 ┃ ┣ 📜canceled_message.cpp
 ┃ ┣ 📜executed_message.cpp
 ┃ ┣ 📜ouch_message.cpp
 ┃ ┣ 📜replaced_message.cpp
 ┃ ┗ 📜system_event_message.cpp
 ┣ 📂packets
 ┃ ┣ 📜packet.cpp
 ┃ ┗ 📜packet_capture_header.cpp
 ┗ 📜main.cpp
```
## Running Instructions

### Compile Program

```
make
```

### Execute Program

```
./bin/app
```

#### Expected Sample Output

```
Stream: 1 Number of packets: 1
Stream: 2 Number of packets: 3
Stream: 3 Number of packets: 5
Stream: 4 Number of packets: 2
Stream: 5 Number of packets: 1
-----Aggregated OUCH Message Summary-----
Total number of captured packets: 12
Total number of Unique streams: 5
Total number of Accepted Messages: 5
Total number of Replaced Messages: 2
Total number of Canceled Messages: 1
Total number of System Event Messages: 1
Total number of Executed Messages: 3
Total number of Executed Shares: 50
```