all:
	cd src; qmake; make
	cd test; qmake; make

clean:
	cd src; qmake; make clean
	cd test; qmake; make clean
	rm -f src/Makefile
	rm -f test/Makefile
	rm -f bin/CQImageView
