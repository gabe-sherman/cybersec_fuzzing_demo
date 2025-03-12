// Copyright 2016 Google Inc. All Rights Reserved.
// Licensed under the Apache License, Version 2.0 (the "License");
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/nameser.h>
#include <ares.h>

int main(int argc, char **argv){
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

  unsigned char *buf;
  int buflen;
  ares_create_query(data, ns_c_in, ns_t_a, 0x1234, 0, &buf, &buflen, 0);
  free(buf);
  return 0;
}