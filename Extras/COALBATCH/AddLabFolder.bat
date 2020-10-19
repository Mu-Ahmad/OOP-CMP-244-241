@echo off
color 0a
title Coal Lab Git made by Saadi
@echo Updating Git repository of Coal Lab
set /p repo="Enter repository address: "
cd %repo%
git add --all
set /p folder="Enter folder name: "
if not exist .\%folder% mkdir .\%folder%
cd %folder%
git add --all
git commit -m "Updated"
git push origin master