#!/bin/bash

REPO_LINK="https://github.com/yadavanshu/Coding.git"
BRANCH="master"
COMMIT_MSG="Repo Update"


# git init
git add .
git commit -m "$COMMIT_MSG"
git remote add origin "$REPO_LINK"
git push

echo "Git Update Done"

