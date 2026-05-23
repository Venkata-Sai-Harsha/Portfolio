#!/usr/bin/bash

echo "currently logged user: $USER"
echo "long name of currently logged user: $(getent passwd $USER | cut -d ':' -f 5)"
echo "currently shell: $SHELL"
echo "home directory: $HOME"
echo "operating system type: $(uname -s)"
echo "current path setting: $PATH"
echo "current working directory: $(pwd)"
echo "all available shells: $(cat /etc/shells)"