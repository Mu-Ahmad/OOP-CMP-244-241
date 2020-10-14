# OOP-CMP-244-241
This repository is in accordance with OOP course and LAB taught in Fall 20' in PUCIT.

## There's only one Rule: No one will make mean comments about anyone's code and everyone is obliged to explain there logic and code if needed.

Keep checking back "Extra" directory to check out interesting scripts shared by your peers.

Those who are using Command Prompt for commit and Push may face this
error: 
       ##! [rejected]        master -> master (fetch first)
       ##error: failed to push some refs to 'git@github.com:zapnaa/abcappp.git'

Use Following commands one by one to resolve this issue,it works for github/bitbucket both

##git fetch origin master:tmp
##git rebase tmp
##git push origin HEAD:master
##git branch -D tmp

After these commands add the new/modified files to stage again make new commit and push, your
error will be hopefully ##resolved.