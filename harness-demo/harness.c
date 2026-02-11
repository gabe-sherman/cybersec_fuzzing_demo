#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <ucl.h>

int main(int argc, char **argv) {
    // all of this code is just reading input from a file and storing it into a buffer
    FILE *f;
    char *data = NULL;
    char *fuzzDataCmp = NULL;
    long size;

    if(argc < 2)
        exit(0);

    f = fopen(argv[1], "rb");
    if(f == NULL)
        exit(0);

    fseek(f, 0, SEEK_END);

    size = ftell(f);
    rewind(f);

    if(size < 1) 
        exit(0);

    data = (char*)malloc((size_t)size+1);
    if(data == NULL)
        exit(0);
                        
    if(fread(data, (size_t)size, 1, f) != 1)
        exit(0);

	if(size==0){
		return 0;
	}

    // create a parser to use later
	struct ucl_parser *parser;
       	parser = ucl_parser_new(0);
	
    // now we start passing this random input into the library!
	ucl_parser_add_string(parser, (char *)data, size);
	
    // check if any errors occur. If they do, exit
	if (ucl_parser_get_error(parser) != NULL) {
		return 0;
	}

    // free up allocated memory
	ucl_parser_free (parser);
    return 0;
}