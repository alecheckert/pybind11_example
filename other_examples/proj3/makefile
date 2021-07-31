TARGETS: proj3

ALL: $(TARGETS)

proj3: libproj3
	python setup.py install

libproj3:
	mkdir build; cd build; cmake ..; cmake --build .

.PHONY: clean

clean:
	rm -r ./build
	rm -r ./dist
	rm -r ./pyproj3.egg-info
