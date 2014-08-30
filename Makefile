GXX=g++
FILES=color_printer.cpp main.cpp
OUTPUT_BINARY=color_printer

all:
	${GXX} ${FILES} -o ${OUTPUT_BINARY}

clean:
	rm -rf ${OUTPUT_BINARY}
