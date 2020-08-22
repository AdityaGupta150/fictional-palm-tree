BUILD_DIR="build"
PROG_NAME="calculator"

build: mkdir main.o util.o
	g++ ${BUILD_DIR}/main.o ${BUILD_DIR}/util.o -o ${PROG_NAME}

mkdir:
	mkdir -p ${BUILD_DIR}

main.o: main.cpp
	g++ -c main.cpp -o ${BUILD_DIR}/main.o

util.o: util.cpp
	g++ -c util.cpp -o ${BUILD_DIR}/util.o

clean:
	rm -r ${BUILD_DIR} ${PROG_NAME}
