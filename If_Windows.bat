@echo off
chcp 65001 >NUL
goto start

:start
	cls
	echo 1 - check versions, 2 - install conan, 3 - run instalation, 4-write a comand, 0 - exit
	set answ=0
	set /p answ=""
goto answ%answ%

:answ1
	python --version
	pip --version
	cmake --version
	conan --version
set /p pause="Press enter"
goto start

:answ2
	pip install -v "conan<2"
pause
goto start

:answ3
	mkdir build
	cd build && conan install .. --build=missing
	cmake ..
set /p pause=
goto start

:answ4
	set /p comand="U'r comand:"
	%comand%
pause
goto start

:answ0
exit&exit
