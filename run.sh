#!/bin/bash

REPO_LINK="https://github.com/yadavanshu/Coding.git"
BRANCH="master"

echo "Commit Message: "

read COMMIT_MSG


# git init
git add .
git commit -m "$COMMIT_MSG"
git push -u origin "$BRANCH"

echo "Git Update Done"

