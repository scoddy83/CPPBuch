@echo off
set SRCDIR=src
echo SRCDIR := %SRCDIR%> makefile
echo cppfiles=\>>  makefile
C:\MinGW\msys\bin\find.exe  %SRCDIR% -name "*.cpp" > 5373td73g.txt
sed "s/\.cpp/.cpp\\\\/g" 5373td73g.txt >> makefile
rem Leerzeile
echo.>> makefile
echo include include.mak >> makefile
del 5373td73g.txt
echo makefile erzeugt!

