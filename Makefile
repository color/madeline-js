CC           = em++
CFLAGS       = -O3 -Wall -Wextra -std=gnu++11

TARGET     = madeline
SOURCEDIR  = madeline/src/
SOURCES    = $(shell echo $(SOURCEDIR)*.cpp)
INCLUDEDIR = madeline/src/
HEADERS    = $(shell echo $(INCLUDEDIR)*.h)
OBJECTS    = $(SOURCES:.cpp=.o)


all: $(TARGET)
	$(CC) -O3 -v -s DEMANGLE_SUPPORT=1 --pre-js pre.js --post-js post.js --memory-init-file 0 --bind $(TARGET).bc libnested.cc -o $(TARGET).js

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET).bc $(OBJECTS)

clean:
	-rm -f $(OBJECTS) $(TARGET).bc

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $<


.PHONY: all clean
