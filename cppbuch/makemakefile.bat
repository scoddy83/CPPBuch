@echo off
rem \MinGW\msys\bin\find 
rem damit nicht Windows's find aufgerufen wird
C:\MinGW\msys\bin\find.exe . -name makefile > s538n835md8923b.txt
rem alle mit src ausklammern, weil die von uebergeordneten Verzeichnissen
rem aufgerufen werden
grep -v "/src/" s538n835md8923b.txt > s538n835md8923b1.txt
rem k15 ausklammern (Qt)
grep -v "k15/" s538n835md8923b1.txt > s538n835md8923b.txt
rem  home ausklammern 
grep -v "\./makefile" s538n835md8923b.txt  > s538n835md8923b1.txt
sed "s#\./#	\$(MAKE) -C #g" s538n835md8923b1.txt > s538n835md8923b.txt
echo all:> makefile
sed "s#/makefile##g" s538n835md8923b.txt >> makefile
echo clean:>> makefile
sed "s#/makefile# clean#g" s538n835md8923b.txt >> makefile
del s538n835md8923b.txt
del s538n835md8923b1.txt
echo makefile erzeugt! Aufruf: make oder make clean
