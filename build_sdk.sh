#! /bin/sh
# install compiler
cp private_settings.py mbed/workspace_tools
( cd mbed;  python workspace_tools/build.py -m LPC1768 -t GCC_ARM -r -U -u -f )
