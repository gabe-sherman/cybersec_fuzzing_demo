### General Setup(Do this before anything else)
Step 1: Run `. install_afl.sh` -- Installs AFL on your system

Step 2: Run `setenv.sh` -- This adds AFL to your path, set the `LD_LIBRARY_PATH`, and configure the system for fuzzing.

### Fuzzing Demo
Step 1: Run `cd demo` -- Navigate to the demo directory.

Step 2: Run `make lib_fuzz`. -- Build the library and instrument it.

Step 3: Run `make harness`. -- Build the harness and link against the instrumented library

Step 4: Run `begin_fuzzing.sh` -- Start fuzzing!

### c-ares CVE 2016-5180

Step 1: Run `cd c-ares_CVE` -- Navigate to the demo directory.

Step 2: Run `make lib_fuzz`. -- Build the library and instrument it.

Step 3: Run `make harness`. -- Build the harness and link against the instrumented library

Step 4: Run `begin_fuzzing.sh` -- Start fuzzing! You'll quickly get some crashes

Step 5: Crashing inputs will be stored in `output/default/crashes`

Step 6: Recreate a crash by running `./harness.out output/default/crashes/id:000000*` -- You've found the bug!