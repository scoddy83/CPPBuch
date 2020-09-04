echo off
set SRCDIR=src
@echo SRCDIR := %SRCDIR%> makefile
@echo cppfiles :=\>>  makefile
C:\MinGW\msys\bin\find.exe  %SRCDIR% -name "*.cpp" > temporaeredatei123.txt
sed "s!\.cpp!.cpp\\\\!g" temporaeredatei123.txt >> makefile
rm -f temporaeredatei123.txt
rem Leerzeile
@echo.   >> makefile
@echo include libinclude.mak >> makefile
@echo makefile erzeugt!
cat makefile