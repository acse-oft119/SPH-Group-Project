import os
import os.path
import glob
import subprocess
import sys

import tests.python_tests
import tests.test_post

DIR = "tests/bin/*"

files = glob.glob(DIR)
glob_fail = False
for file in files:
    if sys.platform == "win32" and file.split(".")[-1] != "exe":
         continue
    if not os.path.isdir(file) and "test" in file:  # skip directories and unwanted files such as core dumps
        output = subprocess.run([file,"--log_level=unit_scope"], stdout=subprocess.PIPE, universal_newlines=True)
        test_failed = False
        print(output.stdout)
        if output.returncode:
            test_failed = True
        if "fail" in output.stdout:
            test_failed = True
        if "test_output" in file:
            test_failed = False
        if test_failed:
            print("Test %s failed" % file)
            glob_fail = True
        else:
            print("Test %s passed" % file)
      

tests.test_post.post()

for name, attr in tests.python_tests.__dict__.items():
    if 'test' in name:
        try:
            attr()
            print("Test %s passed" %name)
        except Exception:
            print("Test %s failed" %name)
            print(attr())
            glob_fail = True
            
if glob_fail:
    sys.exit(1)
