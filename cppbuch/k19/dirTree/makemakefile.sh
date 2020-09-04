SRCDIR=src
echo SRCDIR := $SRCDIR> makefile
echo cppfiles=\\>>  makefile
find  $SRCDIR -name "*.cpp"\
  | sed "s%\.cpp%\.cpp\\\\%g" >> makefile
# Leerzeile
echo "" >> makefile
echo include include.mak >> makefile
echo makefile erzeugt!

