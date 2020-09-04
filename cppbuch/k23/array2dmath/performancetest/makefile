
makeall:
	$(MAKE) -C array2d
	$(MAKE) -C boost
	@echo Ausfuehrung mit make runadd  oder make runmult

runadd:makeall
	array2d/add.exe
	boost/addboost.exe

runmult:makeall
	array2d/mult.exe
	boost/multboost.exe

clean:
	$(MAKE) -C array2d clean
	$(MAKE) -C boost clean


