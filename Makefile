PACKAGE=module


install:
	python setup.py sdist
	pip install dist/*

reinstall: uninstall install

uninstall:
	pip uninstall -y $(PACKAGE)

build: .PHONY
	python setup.py build

clean:
	python setup.py clean --all
	rm -rf build dist MANIFEST *.egg-info
	find . -name '*.pyc' -exec rm -f {} \;

.PHONY:
