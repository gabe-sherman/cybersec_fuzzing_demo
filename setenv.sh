SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
export PATH=$SCRIPT_DIR/AFLplusplus:$PATH
export LD_LIBRARY_PATH=$SCRIPT_DIR/harness-demo/lib_fuzz/:$SCRIPT_DIR/cve-2016-demo/lib_fuzz/.libs/
export MAGIC=$SCRIPT_DIR/file-demo/lib_fuzz/magic/magic.mgc

# some stuff to optimize fuzzing
sudo sh -c 'echo core >/proc/sys/kernel/core_pattern'
sudo sysctl -w kernel.core_pattern="core" > /dev/null
sudo sysctl -w kernel.randomize_va_space=0 > /dev/null
sudo sh -c 'echo performance | tee /sys/devices/system/cpu/cpu*/cpufreq/scaling_governor'
