echo all:> s538n835md8923b.txt
find . -name makefile\
  | sed "s%\./%\	\$(MAKE) -C %g" \
  | sed "s%/makefile%%g" >> s538n835md8923b.txt
echo clean:>> s538n835md8923b.txt
find . -name makefile\
  | sed "s%\./%\	\$(MAKE) -C %g" \
  | sed "s%/makefile% clean%g" >> s538n835md8923b.txt
# alle mit src ausklammern, weil die von uebergeordneten Verzeichnissen
# aufgerufen werden
grep -v "/src/" s538n835md8923b.txt > s538n835md8923b1.txt
# cppbuch home ausklammern 
grep -v "makefile" s538n835md8923b1.txt  > s538n835md8923b.txt
mv s538n835md8923b.txt makefile
rm s538n835md8923b1.txt
echo makefile erzeugt! Aufruf: make oder make clean
