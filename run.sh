#!/bin/bash



REPO_LINK="https://github.com/yadavanshu/Coding"
BRANCH="master"



git add .
git commit -m "new file update"
git remote add origin $REPO_LINK
git push -u origin $BRANCH
