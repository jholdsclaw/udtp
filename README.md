UDTP API for C++ Documentation
====

UDTP is a file transfer implementation to the User Datagram protocol. It uses a set amount of threads to send a file, split up in optimal size, more faster and efficiently than standard TCP. Both server and client will have a process to check the integrity of the file through an acknowledgement system. The API will include functions that allow to check the completion of the transfer and allow for direct handling of the file once it is entirely there -- it will return a fstream.

UDTP will try and remain as simple as possible. For client and servers: you initialize the UDTPSocket, connect to the server, and send a file or much like polling file descriptors -- wait until there is a file to receive. You will not have to worry about the troubling matters of splitting up a file and sending it, UDTP will handle that given a fstream. Whether you are creating a Photo sharing app or just want to transfer large files, let UDTP take care of the delivery and receipt while you focus on the design.

Supported languages
====
C++
Objective-C (With Cocoa Touch in mind)

Status
====
UDTP is currently under development.

Team
====
Kevin Trinh - Development lead, designer, and researcher of the UDTP architecture.
