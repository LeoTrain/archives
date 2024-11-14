#!/bin/zsh

source ~/.zshrc

echo "Running clock script..."
progress_bar 1

echo "Compiling clock programm..."
gcc ~/documents/git_repos/c_proj/digital_clock/main.c -o ~/documents/git_repos/c_proj/digital_clock/prog
progress_bar 3

echo "Running digital clock.."
progress_bar 2
chmod +x ~/documents/git_repos/c_proj/digital_clock/prog
if [ $# -eq 0 ]
	then ~/documents/git_repos/c_proj/digital_clock/prog
elif [ $# -eq 1 ]
	then ~/documents/git_repos/c_proj/digital_clock/prog $1
elif [ $# -eq 2 ]
	then ~/documents/git_repos/c_proj/digital_clock/prog $1 $2
elif [ $# -eq 3 ]
	then ~/documents/git_repos/c_proj/digital_clock/prog $1 $2 $3
fi
