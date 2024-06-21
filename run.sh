#!/bin/bash

REPO_LINK="https://github.com/yadavanshu/Coding.git"
BRANCH="master"
COMMIT_MSG="Repo Update"


# git init
git add .
git commit -m "$COMMIT_MSG"
git remote add origin "$REPO_LINK"
<<<<<<< HEAD
git push
=======
git push -u origin "$BRANCH"
>>>>>>> f31bbf6 (Repo Update)

echo "Git Update Done"

