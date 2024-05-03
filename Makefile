CC = g++
CFLAGS = -std=c++11 -Wall
SRCDIR = src
INCLUDEDIR = include
OBJDIR = obj
BINDIR = bin

# List of source files
SRCS = $(SRCDIR)/main.cpp \
       $(SRCDIR)/packets/packet_capture_header.cpp \
       $(SRCDIR)/packets/packet.cpp \
	   $(SRCDIR)/messages/ouch_message.cpp \
	   $(SRCDIR)/messages/accepted_message.cpp \
	   $(SRCDIR)/messages/canceled_message.cpp \
	   $(SRCDIR)/messages/replaced_message.cpp \
	   $(SRCDIR)/messages/system_event_message.cpp \
	   $(SRCDIR)/messages/executed_message.cpp \
	   $(SRCDIR)/factories/message_factory.cpp \
	   $(SRCDIR)/factories/accepted_message_factory.cpp \
	   $(SRCDIR)/factories/canceled_message_factory.cpp \
	   $(SRCDIR)/factories/replaced_message_factory.cpp \
	   $(SRCDIR)/factories/system_event_message_factory.cpp

# List of object files
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Executable name
EXECUTABLE = $(BINDIR)/app

# Main target
all: $(EXECUTABLE)

# Rule to compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDEDIR) -c $< -o $@

# Rule to link object files into executable
$(EXECUTABLE): $(OBJS)
	mkdir -p $(BINDIR)
	$(CC) $(OBJS) -o $@

# Clean rule
clean:
	rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean
