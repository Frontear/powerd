BUILD_DIR=${PWD}/build
SOURCE_DIR=${PWD}/src

build: ${SOURCE_DIR}/main.c
	mkdir -p ${BUILD_DIR}
	${CC} -o ${BUILD_DIR}/powerd ${SOURCE_DIR}/main.c
	chmod 0711 ${BUILD_DIR}/powerd

install: build
	mkdir -p ${DESTDIR}/usr/local/bin
	cp ${BUILD_DIR}/powerd ${DESTDIR}/usr/local/bin
