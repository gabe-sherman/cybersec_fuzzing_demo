# set the compilers to AFL's compilers
CC_FUZZ       	= afl-clang-fast
CXX_FUZZ      	= afl-clang-fast++
CFLAGS 			= -fsanitize=address
CXXFLAGS 		= -fsanitize=address

LIB_NAME = lib_fuzz
LIB_REPO = https://github.com/c-ares/c-ares.git

# compilation dependencies
DEPS = -I $(PWD)/$(LIB_NAME)/include \
	   -I $(PWD)/$(LIB_NAME)/ \
	   -L $(PWD)/$(LIB_NAME)/.libs/

DEPS_DYN = -lcares

lib_fuzz: # AFL coverage; static linking.
	rm -rf $(LIB_NAME)
	git clone $(LIB_REPO) $(LIB_NAME)
	cd $(LIB_NAME) && \
	git checkout 51fbb479f7948fca2ace3ff34a15ff27e796afdd &&\
	./buildconf && \
	CC=$(CC_FUZZ) CXX=$(CXX_FUZZ) CFLAGS=$(CFLAGS) CXXFLAGS=$(CXXFLAGS) ./configure &&\
	make -j12

harness:
	$(CC_FUZZ) -o harness.out harness.c $(DEPS) $(DEPS_DYN) $(CFLAGS)