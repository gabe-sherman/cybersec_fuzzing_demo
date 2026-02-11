CC_FUZZ       	= afl-clang-fast
CXX_FUZZ      	= afl-clang-fast++

lib_fuzz:
	git clone https://github.com/file/file.git lib_fuzz &&\
	cd lib_fuzz &&\
	autoreconf -i &&\
	./configure --disable-shared CC=$(CC_FUZZ) CXX=$(CXX_FUZZ) &&\
	make all -j12
