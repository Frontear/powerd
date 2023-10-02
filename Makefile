BUILD_DIR=${PWD}/build
SOURCE_DIR=${PWD}/src

build: ${SOURCE_DIR}/powerd
	mkdir -p ${BUILD_DIR}
	cp ${SOURCE_DIR}/powerd ${BUILD_DIR}
	chmod 0711 ${BUILD_DIR}/powerd

install: build
	mkdir -p ${DESTDIR}/usr/local/bin
	cp ${BUILD_DIR}/powerd ${DESTDIR}/usr/local/bin
