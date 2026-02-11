# set the compilers to AFL's compilers
CC_FUZZ       	= afl-clang-fast
CXX_FUZZ      	= afl-clang-fast++

LIB_NAME = lib_fuzz
LIB_REPO = https://github.com/vstakhov/libucl

# compilation dependencies
DEPS = -I $(PWD)/$(LIB_NAME)/include \
	   -L $(PWD)/$(LIB_NAME)/

DEPS_DYN = -lucl
DEPS_LDD = $(PWD)/$(LIB_NAME)/

lib_fuzz: # AFL coverage; static linking.
	rm -rf $(LIB_NAME)
	git clone $(LIB_REPO) $(LIB_NAME)
	cd $(LIB_NAME) && \
	cmake . \
		-DCMAKE_C_COMPILER=$(CC_FUZZ) -DCMAKE_CXX_COMPILER=$(CXX_FUZZ) -DBUILD_SHARED_LIBS=ON && \
	make all -j12


harness:
	afl-clang-fast -o harness.out harness.c $(DEPS) $(DEPS_DYN)
