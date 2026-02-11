### General Setup (Do this before anything else)

Step 1: Run `. install_afl.sh` -- Installs AFL on your system

Step 2: Run `setenv.sh` -- This adds AFL to your path, sets target-specific environment variables, and configures the system for fuzzing.

### 1) File Command Line Tool Demo
Step 1: Run `cd file-demo` -- Navigate to the file-demo directory.

Step 2: Run `make lib_fuzz` -- Build the file tool and instrument it with `afl-clang-fast`.

Step 3: Run `./begin_fuzzing.sh` -- Start fuzzing!

### 2) LibUCL Harness Demo
Step 1: Run `cd harness-demo` -- Navigate to the harness-demo directory.

Step 2: Run `make lib_fuzz` -- Build the library and instrument it with `afl-clang-fast`.

Step 3: Run `make harness` -- Build the harness and link against the instrumented library

Step 4: Run `./begin_fuzzing.sh` -- Start fuzzing!

### 3) c-ares CVE 2016-5180

Step 1: Run `cd cve-2016-demo` -- Navigate to the cve-2016-demo directory.

Step 2: Run `make lib_fuzz` -- Build the library and instrument it with `afl-clang-fast`.

Step 3: Run `make harness` -- Build the harness and link against the instrumented library

Step 4: Run `./begin_fuzzing.sh` -- Start fuzzing! You'll quickly get some crashes

Step 5: Crashing inputs will be stored in `output/default/crashes`

Step 6: Recreate a crash by running `./harness.out output/default/crashes/id:000000*` -- You've found the bug!
